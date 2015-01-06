/*
 * Audio Class
 *
 */

#ifndef VSGE_AUDIO_H
#define VSGE_AUDIO_H

#include <functional>

#include <SDL2/SDL.h>

#include "defines.h"

/*
  TODO(naum):
  - Use SDL_Mixer
*/

namespace vsge
{

class Audio
{
public:
  Audio();
  virtual ~Audio();

  /**
   * Open audio device
   */
  bool openDevice(int samplesPerSecond);

  void play();
  void pause();

private:
  bool isInitialized_ = false;
  SDL_AudioSpec specDesired_, specObtained_;
  SDL_AudioDeviceID device_ = 0;

  //std::function<void(void*, uint8*, int)> callback_;
};

} // namespace vsge

#endif // VSGE_AUDIO_H
