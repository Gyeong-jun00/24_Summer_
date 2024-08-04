#pragma once
class TimeMgr {
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER	curCount;	// ���� �ð�
	LARGE_INTEGER	prevCount;	// ���� �ð�
	LARGE_INTEGER	preQuency;	// ���� ī���Ͱ� �ʴ� �� �� ����Ǿ��°� ����

	double			dDT;		// �� ������ ������ �ð� �� - ���� �ð��� ���� �ð��� ���̸� ���� �ý��� ���� ī������ ���ļ��� ������ ���
	double			dAcc;		// ���� ��� �ð� : 1�ʸ� �ʰ��ϸ� FPS ����ϰ� �ʱ�ȭ
	UINT			iCallCount;	// UPDATE �Լ� ȣ�� Ƚ��
	UINT			iFPS;		// ������ �ӵ� : 1�ʴ� UPDATE ȣ�� Ƚ��

public:
	void			Init();
	void			Update();
	void			Render();
	double			getDT() { return dDT; }
	float			getfDT() { return (float)dDT; }
};

