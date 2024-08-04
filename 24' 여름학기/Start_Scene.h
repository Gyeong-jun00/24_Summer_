#pragma once
#include "CScene.h"

class Start_Scene : public CScene
{
public:
	Start_Scene();
	~Start_Scene();

	void Enter();
	void Exit();
	void Update();
	void Render(HDC hdc);
};

