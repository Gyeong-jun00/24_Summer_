#include "pch.h"
#include "Start_Scene.h"

#include "CObject.h"
#include "Player.h"

Start_Scene::Start_Scene()
{

}

Start_Scene::~Start_Scene()
{

}


void Start_Scene::Enter()
{
	// Object Ãß°¡
	CObject* obj = new Player;
	obj->SetPos(Vec2(640.f, 348.f));
	obj->SetScale(Vec2(100.f, 100.f));
	AddObject(obj, GROUP_TYPE::DEFAULT);

	obj = new CObject;
	obj->SetPos(Vec2(640.f, 348.f));
	obj->SetScale(Vec2(100.f, 100.f));
	AddObject(obj, GROUP_TYPE::DEFAULT);
}

void Start_Scene::Exit()
{

}