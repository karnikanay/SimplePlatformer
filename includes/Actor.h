#pragma once
#include "Game.h"
#include "Component.h"
#include "Math.h"
#include <vector>

class Actor
{
public:

  // Enum for state of actor
  enum State
  {
    Active,
    Dead
  };

  Actor(class Game* parentGame);
  virtual ~Actor();

  // Update function called from game (not overridable)
  void Update(float deltaTime);

  // Updates all the actor components (not overridable)
  void UpdateComponents(float deltaTime);

  // Actor specific update code
  virtual void UpdateActor(float deltaTime);

  // Add/Remove components
  void AddComponent(class Component* component);
  void RemoveComponent(class Component* component);

  // Getters and Setters
  State GetState();
  void SetState(State newState);

private:

  // Components list
  std::vector<class Component*> mComponents;

  // Parent game pointer
  class Game* mParentGame;

  // Position in game
  Vector2 mPosition;

  // State of the actor
  State mState;
};

