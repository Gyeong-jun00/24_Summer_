#pragma once
#include "CObject.h"

class Player : public CObject 
{
public: 
	virtual void Update();

private:
	void CreateMissile();
};

