#include "pch.h"
#include "SceneMgr.h"

#include "Start_Scene.h"

SceneMgr::SceneMgr()
	: arrScene{}
	, currScene(nullptr)
{

}

SceneMgr::~SceneMgr()
{

}

void SceneMgr::Init()
{
	// scene ����
	arrScene[(UINT)SCENE_TYPE::START] = new Start_Scene;
	arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start_Scene");
	// ���� �� ����
	currScene = arrScene[(UINT)SCENE_TYPE::START];
	currScene->Enter();

}

void SceneMgr::Update()
{
	currScene->Update();
}

void SceneMgr::Render(HDC hdc)
{
	currScene->Render(hdc);
}