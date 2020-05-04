#include "Actor.h"

Actor::Actor(Game* parentGame)
:mParentGame(parentGame)
,mState(State::Active)
,mPosition(Vector2::Zero)
{
  parentGame->AddActor(this);
}

Actor::State Actor::GetState()
{
  return this->mState;
}

void Actor::Update(float deltaTime)
{

}

void Actor::UpdateComponents(float deltaTime)
{

}

void Actor::UpdateActor(float deltaTime)
{

}

void Actor::AddComponent(Component* component)
{

}

void Actor::RemoveComponent(Component* component)
{

}

void Actor::SetState(Actor::State newState)
{
  this->mState = newState;
}

Actor::~Actor()
{
  
}

