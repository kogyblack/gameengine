// TODO(naum): Remove transcendental functions and reimplement them
#include <cmath>

#include "audio.h"

namespace vsge
{

Audio::
Audio()
{
  if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0)
  {
    SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
                    "Could not init audio system: %s\n",
                    SDL_GetError());

    isInitialized_ = false;
  }
  else
  {
    isInitialized_ = true;
  }
}

Audio::
~Audio()
{
  if (device_ != 0)
    SDL_CloseAudioDevice(device_);

  if (isInitialized_)
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

bool Audio::
openDevice(int samplesPerSecond)
{
  specDesired_.freq = samplesPerSecond;
  specDesired_.format = AUDIO_S16LSB;
  specDesired_.channels = 2;
  specDesired_.samples = 4096;
  specDesired_.callback = [] (void* userdata, uint8* stream, int audioLength)
  {
    static uint32 runningSampleIndex = 0;

    SDL_AudioSpec* spec = reinterpret_cast<SDL_AudioSpec*>(userdata);

    int samplesPerSecond = spec->freq;
    int toneHz = 256;
    int16 toneVolume = 50;
    int wavePeriod = samplesPerSecond / toneHz;
    int bytesPerSample = sizeof(int16) * spec->channels;
    int sampleCount = audioLength / bytesPerSample;

    //int16* audioStream = reinterpret_cast<int16*>(stream);
    for (int i = 0; i < sampleCount; ++i)
    {
      int16 sampleValue = 0;

      // NOTE(naum): Sine wave
      float angle = 2 * M_PI * runningSampleIndex++ / wavePeriod;
      while (angle >= 2 * M_PI)
        angle -= 2 * M_PI;
      float sineValue = std::sin(angle);
      sampleValue = static_cast<int16>(sineValue * toneVolume);

      // NOTE(naum): Square wave
      /*
      int halfWavePeriod = wavePeriod / 2;
      sampleValue = ((runningSampleIndex++ / halfWavePeriod) % 2)
      ? toneVolume : -toneVolume;
      */

      //*audioStream++ = sampleValue;
      //*audioStream++ = sampleValue;

      // TODO(naum): Make this work with uint8,
      // int8, s16msb, s32 and float32
      // This only works in S16LSB.
      *stream++ = (sampleValue & 0xFF00) >> 16;
      *stream++ = (sampleValue & 0x00FF);

      *stream++ = (sampleValue & 0xFF00) >> 16;
      *stream++ = (sampleValue & 0x00FF);
    }
  };
  specDesired_.userdata = &specDesired_;

  device_ = SDL_OpenAudioDevice(
      NULL, 0,
      &specDesired_, &specObtained_,
      SDL_AUDIO_ALLOW_FORMAT_CHANGE);

  if (device_ == 0)
  {
    SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
                    "Failed to open audio: %s\n",
                    SDL_GetError());
    return false;
  }

  if (specObtained_.format != specDesired_.format)
  {
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "Could not get desired audio format!");
  }

  return true;
}

void Audio::
play()
{
  SDL_assert(device_ != 0);
  SDL_PauseAudioDevice(device_, 0);
}

void Audio::
pause()
{
  SDL_assert(device_ != 0);
  SDL_PauseAudioDevice(device_, 1);
}

} // namespace vsge

#
