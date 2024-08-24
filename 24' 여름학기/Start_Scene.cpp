#include "pch.h"
#include "Start_Scene.h"

#include "CObject.h"
#include "CCore.h"

#include "Player.h"
#include "Monster.h"

Start_Scene::Start_Scene()
{

}

Start_Scene::~Start_Scene()
{

}


void Start_Scene::Enter()
{
	// Object 추가
	CObject* obj = new Player;
	obj->SetPos(Vec2(640.f, 348.f));
	obj->SetScale(Vec2(100.f, 100.f));
	AddObject(obj, GROUP_TYPE::DEFAULT);

	// Monster Object 추가
	int iMonCount = 16;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;

	Vec2 vResolution = CCore::Instance()->GetResolution();
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale / 2.f) * 2)) / (float)(iMonCount - 1);

	Monster* Monsterobj = nullptr;

	for (int i = 0; i < iMonCount; ++i)
	{
		Monsterobj = new Monster;
		Monsterobj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 50.f));
		Monsterobj->SetCenterPos(Monsterobj->GetPos());
		Monsterobj->SetMoveDistance(fMoveDist);
		Monsterobj->SetScale(Vec2(fObjScale, fObjScale));
		AddObject(Monsterobj, GROUP_TYPE::DEFAULT);
	}

}

void Start_Scene::Exit()
{

}