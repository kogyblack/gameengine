/*
 * Game Class
 *
 * Singleton class
 * Initializes SDL and SDL_Window and manages memory, handle inputs
 */

#ifndef VSGE_GAME_H
#define VSGE_GAME_H

#include <memory>
#include <string>

#include <SDL2/SDL.h>

#include "defines.h"

namespace vsge
{

// Forward declarations
class Renderer;

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

/*

  TODO(naum): Todo-list of Game class
  - Fix framerate (Create Timer class)
  - Window: Change resolution
  - Window: Enable fullscreen
  - Renderer: Enable vsync
  - Network
  - Physics

 */

/**
 *  Game class.
 *  \brief Initializes and create a window and manages inputs.
 */
class Game
{
public:
  Game();
  virtual ~Game();

  /**
   * Create window and setup the game
   */
  bool start(std::string name,
             int window_width, int window_height,
             int argc, char** argv);

  /**
   * Game main loop
   */
  void run();

protected:
  /**
   * Virtual method for the game logic
   */
  virtual void gameUpdate();

private:
  /**
   * The input handling method
   * \return false if the program should quit. True otherwise
   */
  // TODO(naum): Change this to TranslateInput and handle
  // inside a virtual method (?). Also create a structure
  // for the controllers (keyboard, joystick and mouse)
  void handleInputs();
  void handleKeyboard(SDL_Event event);
  void handleMouse(SDL_Event event);
  void handleJoysticks(SDL_Event event);
  void handleControllers(SDL_Event event);

  /**
   * Render method
   * Clears screen, render and swap buffers
   */
  void render();

  bool isRunning_ = true; /**< game running flag */

  std::string name_; /**< Game name */
  SDL_Window* window_; /**< Window handler */

  Renderer* renderer_; /**< Window renderer */


  // TODO(naum): Remove this backbuffer texture
  SDL_Texture* backbuffer_;
  uint32* backbufferPixels_;
};

}

#endif //VSGE_GAME_H
