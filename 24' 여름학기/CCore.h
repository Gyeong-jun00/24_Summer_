#pragma once
#include "pch.h"

class CCore {
	SINGLE(CCore);
private:
	HWND handle;		// �簢��
	POINT ptResolution; // ��
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

// �̱��� : �ϳ��� �ν��Ͻ��� ����� ���� ���
// �ϳ��� ��ü�� ����� ���� ���.

// Ŭ���� - ������, �Ҹ���, private ���� �ϸ� ���� �ʳ�?
// ��ü�� ���� �� ����.
// ����Լ�, ��������� ������ ������? -> ��ü�� ����
// ��� ȣ���� �� �־�? -> static �̸� �����ϴ�. ���� ��� �Լ��� ���� ��� �����θ� �����Ѵ�.

// static ����

// DATA : ���α׷� ���۵� �� ����, ���� �� �״� �ֵ� --> static
// STACK : ��������/�Լ� (�Ű�����)
// HEAP : ���� �Ҵ�
// CODE : �Լ� (�Ű�x)

// �ػ� : â�� �ִ� �ȼ��� ��