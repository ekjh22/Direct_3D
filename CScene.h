#pragma once

// CSceneManager가 관리하는 씬를 만들기 위해서 만들어진 부모 클래스
class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	// 기본적으로 처음에 실행되는 함수
	virtual void Init() PURE;
	
	// 매 프레임마다 실행되는 함수
	virtual void Update() PURE;

	// 매 프레임마다 실행되는 함수
	virtual void Render() PURE;

	// 파괴될 때 실행되는 함수
	virtual void Release() PURE;
};

