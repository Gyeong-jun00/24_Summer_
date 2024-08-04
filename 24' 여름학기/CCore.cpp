#include "pch.h"
#include "CCore.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "CScene.h"
#include"SceneMgr.h"
#include "CObject.h"
#include "struct.h"

CObject obj;

CCore::CCore()
	: handle(0)
	, ptResolution{}
	, hdc(0)
	, mdc(0)
	,hBit(0)
{

}

CCore::~CCore()
{
	ReleaseDC(handle, hdc);

	DeleteDC(mdc);
	DeleteObject(hBit);
}

void CCore::Update() // 움직이는거
{
	TimeMgr::Instance()->Update();
	KeyMgr::Instance()->update();
	SceneMgr::Instance()->Update();

	Vec2 vPos = obj.getPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		vPos.x -= 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		vPos.x += 200.f * fDT;
	}
	
	obj.SetPos(vPos);

}

void CCore::Render() // 사각형 생성
{
	

	Rectangle(mdc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);
	TimeMgr::Instance()->Render();
	SceneMgr::Instance()->Render(mdc);
	BitBlt(hdc, 0, 0, ptResolution.x, ptResolution.y,
		mdc, 0, 0, SRCCOPY);
}

int CCore::init(HWND _handle, POINT _pt)
{
	handle = _handle;
	ptResolution = _pt;

	RECT rt = { 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);	
	SetWindowPos(handle, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	hdc = GetDC(handle);

	// 이중 버퍼링 용도의 비트맵과 DC를 만든다.
	hBit = CreateCompatibleBitmap(hdc, ptResolution.x, ptResolution.y);
	mdc = CreateCompatibleDC(hdc);

	HBITMAP oldBit = (HBITMAP)SelectObject(mdc, hBit);
	DeleteObject(oldBit);

	obj.SetPos(Vec2((float)(ptResolution.x / 2), (float)(ptResolution.y / 2)));
	obj.SetScale(Vec2( 100, 100 ));

	// Manager Init
	TimeMgr::Instance()->Init();
	KeyMgr::Instance()->Init();
	SceneMgr::Instance()->Init();

	return S_OK;
}

void CCore::Progress()
{
	TimeMgr::Instance()->Update();
	TimeMgr::Instance()->Render();
	Update();
	Render();
}
