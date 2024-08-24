#pragma once
#include "pch.h"

class CCore {
	SINGLE(CCore);
private:
	HWND handle;		// 사각형
	POINT ptResolution; // 점
	HDC hdc;

	HBITMAP hBit;
	HDC mdc;
	
	void Update();
	void Render();

public:
	int init(HWND _handle, POINT _pt);
	void Progress();

	HWND GetMainHandle() { return handle; }
	POINT GetResolution() { return ptResolution; }
};



//public:
//	static CCore* Instance() { // static 
//		static CCore core;
//		return &core;
//	}
//};

// 싱글톤 : 하나의 인스턴스를 만들기 위해 사용
// 하나의 객체를 만들기 위해 사용.

// 클래스 - 생성자, 소멸자, private 으로 하면 되지 않나?
// 객체를 만들 수 없다.
// 멤버함수, 멤버변수에 접근이 가능해? -> 객체가 없어
// 멤버 호출할 수 있어? -> static 이면 가능하다. 정적 멤버 함수는 정적 멤버 변수로만 접근한다.

// static 정적

// DATA : 프로그램 시작될 때 생성, 끝날 때 죽는 애들 --> static
// STACK : 지역변수/함수 (매개변수)
// HEAP : 동적 할당
// CODE : 함수 (신경x)

// 해상도 : 창에 있는 픽셀의 수