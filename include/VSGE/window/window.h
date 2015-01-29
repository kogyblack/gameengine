/*
 * Very Simple Game Engine
 *
 * Window class
 *
 * Manages window and inputs
 *
 */

#ifndef VSGE_WINDOW_H
#define VSGE_WINDOW_H

#include <string>

#include <SDL_video.h>

namespace vsge
{

class Window final
{
public:
  /**
   * \brief Default constructor
   *
   * \param title Window title
   * \param width Window width
   * \param height Window height
   */
  Window(const std::string& title,
         int width, int height);

  /**
   * \brief Destructor
   */
  ~Window();

  /*
   * Disable copy and move
   */
  Window(const Window&) = delete;
  Window(const Window&&) = delete;
  Window& operator=(const Window&) & = delete;
  Window& operator=(Window&&) & = delete;
protected:
private:
  std::string title_; /**< Title */
  SDL_Window* window_; /**< Window handler */

  //SDL_Renderer* renderer_; /**< Window renderer */

  bool isFullscreen_; /**< Fullscreen mode */
};

}

#endif //VSGE_WINDOW_H
