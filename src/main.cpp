/*
 * Very Simple Game Engine
 */

#include <iostream>

#include <SDL2/SDL.h>

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
