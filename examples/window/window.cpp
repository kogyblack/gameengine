#include <iostream>
#include <SDL.h>

#include <VSGE/window.h>

int main(int, char**)
{
  vsge::Window window("Test", 640, 480);

  SDL_Delay(1000);

  return 0;
}
