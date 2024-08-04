#pragma once

class CScene;
class SceneMgr
{
	SINGLE(SceneMgr);
public:
	void Init();
	void Update();
	void Render(HDC hdc);
private:
	CScene* arrScene[(UINT)(SCENE_TYPE::END)];
	CScene* currScene = nullptr;
};

