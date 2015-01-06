/*
 * Renderer Class
 *
 */

#ifndef VSGE_RENDERER_H
#define VSGE_RENDERER_H

#include <vector>

#include <SDL2/SDL.h>

#include "defines.h"
#include "colors.h"

/*
  TODO(naum):
  - Use SDL_Image
  - Texture holding (?)
  - Texture blitting (RenderCopy/RenderCopyEx)
  - Texture updating
*/

namespace vsge
{

class Renderer
{
public:
  explicit Renderer(SDL_Window*);
  virtual ~Renderer();

  bool isInit();

  /**
   * Set the screen's clear color
   */
  void setClearColor(uint8 r, uint8 g, uint8 b);

  // IDEA(naum): Rename function (like updateScreen)
  /**
   * Swap buffers
   * Present the backbuffer and clear the backbuffer
   */
  void swapBuffers();

private:
  SDL_Renderer* renderer_ = nullptr; /**< Window renderer */

  SDL_Color clearColor = Color::WHITE; /**< Screen's clean color */

  // NOTE(naum): SDL_Renderer holds a linked list of all
  // SDL_Textures that it handles, but we want instant
  // access to all textures
  // XXX(naum): Decide if we want external classes to modify and hold
  // textures or not.
  //std::vector<SDL_Texture*> textures_; /**< Renderer textures */
};

} // namespace vsge

#endif // VSGE_RENDERER_H
