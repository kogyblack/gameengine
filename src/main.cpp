/*
 * Very Simple Game Engine
 */

// IDEA(naum): Rename SDL elements into VSGE elements
// e.g.: SDL_Event -> vsge::Event

#include "game.h"

int main(int argc, char** argv)
{
  vsge::Game game;

  if (!game.start("Game",
                  vsge::SCREEN_WIDTH, vsge::SCREEN_HEIGHT,
                  argc, argv))
    return 1;

  game.run();

  return 0;
}
