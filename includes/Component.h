#pragma once
#include "Actor.h"

class Component
{
private:

  class Actor* mOwner;

  int mUpdateOrder;

public:

  // Component with lower updateOrder order updates earlier
  Component(class Actor* owner, int updateOrder = 50);

  virtual ~Component();

  virtual void Update(float deltaTime);
  
  int GetUpdateOrder();
};

