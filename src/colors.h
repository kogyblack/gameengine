#ifndef VSGE_COLORS_H
#define VSGE_COLORS_H

#include <SDL2/SDL_video.h>

namespace vsge
{

namespace Color
{
const SDL_Color WHITE {0xff, 0xff, 0xff, 0xff};
const SDL_Color BLACK {0x00, 0x00, 0x00, 0xff};
const SDL_Color RED   {0xff, 0x00, 0x00, 0xff};
const SDL_Color GREEN {0x00, 0xff, 0x00, 0xff};
const SDL_Color BLUE  {0x00, 0x00, 0xff, 0xff};

} // namespace Color

} // namespace vsge

#endif
