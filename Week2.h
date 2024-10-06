#pragma once

class CWeek2 : public CView
{
protected:
	CWeek2();
	DECLARE_DYNCREATE(CWeek2);

//특성입니다.
public:
	

//작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	int			 OnCreate(LPCREATESTRUCT lpCreateStruct);
	void		 OnDestroy();


// 구현입니다.
public:
	virtual ~CWeek2();


protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};