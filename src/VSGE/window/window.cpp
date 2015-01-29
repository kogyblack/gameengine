/*
 * Very Simple Game Engine
 *
 * Window class
 *
 * Manages window and inputs
 *
 */

#include <SDL.h>

#include <VSGE/window/window.h>

namespace vsge
{

Window::
Window(const std::string& title, int width, int height)
{
  int isError;

  // TODO(naum): Maybe change SDL_Init and SDL_Quit to somewhere else?
  isError = SDL_Init(SDL_INIT_VIDEO);
  if (isError != 0)
  {
    // TODO(naum): Log error!
  }

  title_ = title;

  window_ = SDL_CreateWindow(title_.c_str(),
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            width, height,
                            SDL_WINDOW_OPENGL);

  if (window_ == nullptr)
  {
    // TODO(naum): Log error!
    return;
  }
}

Window::
~Window()
{
  if (window_ != nullptr)
    SDL_DestroyWindow(window_);

  // TODO(naum): Maybe change SDL_Init and SDL_Quit to somewhere else?
  SDL_Quit();
}

}
