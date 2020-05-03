#include "Actor.h"

class Component
{
private:

  Actor* mOwner;

  int mUpdateOrder;

public:

  // Component with lower updateOrder order updates earlier
  Component(Actor* owner, int updateOrder = 50);

  virtual ~Component();

  virtual void Update(float deltaTime);
  
  int GetUpdateOrder();
};

