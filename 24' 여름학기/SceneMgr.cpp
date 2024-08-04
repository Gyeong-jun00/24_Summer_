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
	// scene 생성
	arrScene[(UINT)SCENE_TYPE::START] = new Start_Scene;
	arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start_Scene");
	// 현재 씬 지정
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