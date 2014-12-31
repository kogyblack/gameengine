/*
 * Very Simple Game Engine
 */

#include <iostream>

#include <SDL2/SDL.h>

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Texture* backbuffer = nullptr;

uint32* backbufferPixels = nullptr;

int main(int argc, char** argv)
{
  // SDL initialization
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Window instantiation
  window = SDL_CreateWindow(
      "Window",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);

  if (window == nullptr)
  {
    std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    return 2;
  }

  // Renderer instantiation
  renderer = SDL_CreateRenderer(
      window,
      -1,
      SDL_RENDERER_ACCELERATED);

  if (renderer == nullptr)
  {
    std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
    return 3;
  }

  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

  // Create Backbuffer
  backbuffer = SDL_CreateTexture(
      renderer,
      SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STREAMING,
      SCREEN_WIDTH, SCREEN_HEIGHT);

  backbufferPixels = new uint32[SCREEN_WIDTH * SCREEN_HEIGHT] {};
  for (int x = 0; x < SCREEN_WIDTH; ++x)
    for (int y = 0; y < SCREEN_HEIGHT; ++y)
      backbufferPixels[y * SCREEN_WIDTH + x] = ((x % 256) << 8) + (y % 256);

  // Main loop
  bool running = true;
  while (running)
  {
    // Handle Inputs
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN)
      {
        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
          running = false;
          break;
        }
      }
    }

    // Game Update

    // Render Video
    // Drawing
    SDL_RenderClear(renderer);

    SDL_UpdateTexture(backbuffer, 0, backbufferPixels, SCREEN_WIDTH * sizeof(uint32));
    SDL_RenderCopy(renderer, backbuffer, 0, 0);

    SDL_RenderPresent(renderer);
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_DestroyTexture(backbuffer);
  delete backbufferPixels;

  SDL_Quit();

  return 0;
}
