#include "renderer.h"

namespace vsge
{


Renderer::
Renderer(SDL_Window* window)
{
  renderer_ = SDL_CreateRenderer(
      window,
      -1,
      SDL_RENDERER_ACCELERATED);
}

Renderer::
~Renderer()
{
  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;

  /*
  // TODO(naum): Handle this when time comes!
  for(auto& texture : textures_)
    SDL_DestroyTexture(texture);

  textures_.clear();
  */
}

bool Renderer::
isInit()
{
  return (renderer_ != nullptr);
}

void Renderer::
setClearColor(uint8 r, uint8 g, uint8 b)
{
  clearColor = {r, g, b, 0xff};
}

void Renderer::
swapBuffers()
{
  SDL_RenderPresent(renderer_);
  SDL_RenderClear(renderer_);
}


} // namespace vsge
