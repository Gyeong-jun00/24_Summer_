#pragma once
class Res {
private:
	wstring		key;
	wstring		strRelativePath; 
	// 상대경로 - 폴더 내에서 변하지 않는 경로

public:
	Res();
	~Res();

	void SetKey(const wstring& _key) { key = _key; }
	void SetRelativePath(const wstring& _str) { strRelativePath = _str; }
	
	const wstring& GetKey() { return key; }
	const wstring& GetRelativePath() { return strRelativePath; }
};

