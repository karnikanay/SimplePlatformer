#pragma once
#include "Game.h"
#include <SDL2/SDL_image.h>

bool Game::Init()
{
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
  {
    SDL_Log("Unable to initialize SDL. Error: %s", SDL_GetError());
    return false;
  }

  mWindow = SDL_CreateWindow("SimplePlatformer",
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             SCREEN_WIDTH,
                             SCREEN_HEIGHT,
                             0);

  if(!mWindow)
  {
    SDL_Log("Unable to create SDL window. Error: %s", SDL_GetError());
    return false;
  }

  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(!mRenderer)
  {
    SDL_Log("Failed to create renderer. Error: %s", SDL_GetError());
    return false;
  }

  if(IMG_Init(IMG_INIT_PNG) == 0)
  {
    SDL_Log("Unable to initialize SDL_Image. Error: %s", SDL_GetError());
    return false;
  }

  mIsRunning = true;
  
  mTicksCount = SDL_GetTicks();

  return true;
}

void Game::Loop()
{
  while(mIsRunning)
  {
    ProcessEvents();
    Update();
    GenOutput();
  }
}

void Game::Quit()
{
  SDL_DestroyRenderer(mRenderer);

  SDL_DestroyWindow(mWindow);

  SDL_Quit();
}

void Game::GenOutput()
{
  // Clear the screen
  SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
  SDL_RenderClear(mRenderer);

  SDL_RenderPresent(mRenderer);
}

void Game::ProcessEvents()
{
  SDL_Event e;
  while(SDL_PollEvent(&e))
  {
    switch(e.type)
    {
    case SDL_QUIT:
      mIsRunning = false;
      break;
    }
  }
}

void Game::Update()
{

  // Limit framerate
  while(!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + IDEAL_DELTA_TIME);

  // Compute deltaTime
  float deltaTime = (SDL_GetTicks() - mTicksCount)/1000.f;

  // Update mTicksCount
  mTicksCount = SDL_GetTicks();

  // Update all actors
  mUpdatingActors = true;
  for(Actor* updateActor : mActors)
  {
    updateActor->Update(deltaTime);
  }
  mUpdatingActors = false;

  // Process the pending actors
  for(Actor* pendingActor : mPendingActors)
  {
    mActors.emplace_back(pendingActor);
  }
  mPendingActors.clear();

  // Add dead actors to temp vector
  std::vector<Actor*> deadActors;
  for(Actor* checkDead : mActors)
  {
    if(checkDead->GetState() == Actor::State::Dead)
    {
      deadActors.emplace_back(checkDead);
    }
  }

  // Delete actors from deadActors
  for(Actor* toKill : deadActors)
  {
    delete toKill;
  }
}

