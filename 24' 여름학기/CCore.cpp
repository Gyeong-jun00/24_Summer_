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
	KeyMgr::Instance()->Update();
	SceneMgr::Instance()->Update();

	// 화면 CLEAR
	Rectangle(mdc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	TimeMgr::Instance()->Render();
	SceneMgr::Instance()->Render(mdc);

	BitBlt(hdc, 0, 0, ptResolution.x, ptResolution.y,
		mdc, 0, 0, SRCCOPY);
}
