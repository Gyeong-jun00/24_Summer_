#pragma once
class TimeMgr {
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER	curCount;	// 현재 시간
	LARGE_INTEGER	prevCount;	// 이전 시간
	LARGE_INTEGER	preQuency;	// 성능 카운터가 초당 몇 번 진행되었는가 저장

	double			dDT;		// 두 프레임 사이의 시간 값 - 현재 시간과 이전 시간의 차이를 구해 시스템 성능 카운터의 주파수로 나눠서 계산
	double			dAcc;		// 누적 경과 시간 : 1초를 초과하면 FPS 계산하고 초기화
	UINT			iCallCount;	// UPDATE 함수 호출 횟수
	UINT			iFPS;		// 프레임 속도 : 1초당 UPDATE 호출 횟수

public:
	void			Init();
	void			Update();
	void			Render();
	double			getDT() { return dDT; }
	float			getfDT() { return (float)dDT; }
};

