/*
 * Very Simple Game Engine
 *
 * Display Mode class
 *
 * Holds Window display mode (width, height, refresh rate)
 *
 */

/*
 * TODO(naum):
 * - Add support for multiple monitor or swap to a different monitor
 */

#include <algorithm>
#include <functional>

#include <VSGE/window/displayMode.h>

namespace vsge
{

DisplayMode::
DisplayMode()
{
}

DisplayMode DisplayMode::
getCurrentMode()
{
  SDL_DisplayMode mode;

  bool isError;
  isError = SDL_GetCurrentDisplayMode(0, &mode);

  if (isError)
  {
    // TODO(naum): Log error!
  }

  return DisplayMode {mode};
}

const std::vector<DisplayMode>& DisplayMode::
getFullscreenModes()
{
  static std::vector<DisplayMode> modes;

  // Populate on first call
  if (modes.empty())
  {
    int displayModeCount;
    displayModeCount = SDL_GetNumDisplayModes(0);

    if (displayModeCount < 1)
    {
      // TODO(naum): Log error!
    }

    for (int i = 0;
         i < displayModeCount;
         ++i)
    {
      SDL_DisplayMode mode;

      bool isError;
      isError = SDL_GetDisplayMode(0, i, &mode);
      if (isError)
      {
        // TODO(naum): Log error!
      }

      modes.emplace_back(mode);
    }

    std::sort(modes.begin(), modes.end(), std::greater<DisplayMode>());
  }

  return modes;
}

bool DisplayMode::
isValid() const
{
  auto modes = getFullscreenModes();
  return std::find(modes.begin(), modes.end(), *this) != modes.end();
}

int DisplayMode::
getWidth() const
{
  return mode_.w;
}

int DisplayMode::
getHeight() const
{
  return mode_.h;
}

int DisplayMode::
getRefreshRate() const
{
  return mode_.refresh_rate;
}

int DisplayMode::
getBPP() const
{
  return SDL_BITSPERPIXEL(mode_.format);
}

uint32 DisplayMode::
getFormat() const
{
  return mode_.format;
}

DisplayMode::
DisplayMode(SDL_DisplayMode mode)
{
  mode_ = mode;
}

bool operator ==(const DisplayMode& lhs, const DisplayMode& rhs)
{
  return (lhs.getWidth() == rhs.getWidth() &&
          lhs.getHeight() == rhs.getHeight() &&
          lhs.getRefreshRate() == rhs.getRefreshRate() &&
          lhs.getFormat() == rhs.getFormat());
}

bool operator !=(const DisplayMode& lhs, const DisplayMode& rhs)
{
  return !(lhs == rhs);
}

bool operator <(const DisplayMode& lhs, const DisplayMode& rhs)
{
  if (lhs.getBPP() == rhs.getBPP())
  {
    if (lhs.getWidth() == rhs.getWidth())
      return lhs.getHeight() < rhs.getHeight();
    else
      return lhs.getWidth() < rhs.getWidth();
  }
  else
  {
    return lhs.getBPP() < rhs.getBPP();
  }
}

bool operator >(const DisplayMode& lhs, const DisplayMode& rhs)
{
  return rhs < lhs;
}

bool operator <=(const DisplayMode& lhs, const DisplayMode& rhs)
{
  return !(lhs > rhs);
}

bool operator >=(const DisplayMode& lhs, const DisplayMode& rhs)
{
  return !(lhs < rhs);
}

}
