
// PraticeMFCView.h : CPraticeMFCView 클래스의 인터페이스
//


#pragma once



class CPraticeMFCView : public CView
{
protected: // serialization에서만 만들어집니다.
	CPraticeMFCView();
	DECLARE_DYNCREATE(CPraticeMFCView)

// 특성입니다.
public:
	CPraticeMFCDoc* GetDocument() const;
	//void DoDataExchange(CDataExchange* pDX);

// 작업입니다.
public:
	int height;
	int width;
	int x;
	int y;
	CEdit	m_edit;
	CEdit	m_edit2;
	CEdit	m_edit3;
	CPoint	m_pos;
	BOOL	m_drag;

	//CWeek2 m_week2;
	

	void	OnInitialUpdate();
	void	OnSize(UINT nType, int cx, int cy);
	void	OnMouseMove(UINT nFlags, CPoint point);
	void	OnLButtonDown(UINT nFlags, CPoint point);
	void	OnRButtonDown(UINT nFlags, CPoint point);
	void	OnLButtonUp(UINT nFlags, CPoint point);
	void	OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	void	SetText();
	void	SetText2(CString str);
	void	DrawTimer();

	void	OnTimer(UINT_PTR nIDEvent);


	UINT_PTR m_timer;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	afx_msg int			 OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void		 OnDestroy();

// 구현입니다.
public:
	virtual ~CPraticeMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PraticeMFCView.cpp의 디버그 버전
inline CPraticeMFCDoc* CPraticeMFCView::GetDocument() const
   { return reinterpret_cast<CPraticeMFCDoc*>(m_pDocument); }
#endif

