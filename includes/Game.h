#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include "Actor.h"

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

  // Pending actors stores actors which can't be added yet because actors are
  // updating
  std::vector<class Actor*> mPendingActors;
  std::vector<class Actor*> mActors;

  // Stores where actors are updating
  bool mUpdatingActors;
};

