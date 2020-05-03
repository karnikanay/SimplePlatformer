#pragma once
#include <SDL2/SDL.h>

class Game
{
public:

  bool Init();
  void Loop();
  void Quit();

private:

  const int SCREEN_WIDTH = 1024;
  const int SCREEN_HEIGHT = 768;

  SDL_Window* mWindow;
  SDL_Renderer* mRenderer;

  bool mIsRunning;
  Uint32 mTicksCount;

  void ProcessEvents();
  void Update();
  void GenOutput();
};

