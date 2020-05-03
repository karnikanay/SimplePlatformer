#include "Game.h"

int main(int argc, char** argv)
{
  Game game;

  if(game.Init())
  {
    game.Loop();
  }

  game.Quit();

  return 0;
}

