
// PraticeMFCView.cpp : CPraticeMFCView 클래스의 구현
//

#include "stdafx.h"
#include "PraticeMFC.h"

#include "PraticeMFCDoc.h"
#include "PraticeMFCView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPraticeMFCView

IMPLEMENT_DYNCREATE(CPraticeMFCView, CView)

BEGIN_MESSAGE_MAP(CPraticeMFCView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()




// CPraticeMFCView 생성/소멸

CPraticeMFCView::CPraticeMFCView()
{


}

CPraticeMFCView::~CPraticeMFCView()
{
}



BOOL CPraticeMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}


void CPraticeMFCView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_drag = FALSE;
	m_edit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(10, 10, 500, 40), this, 1);
	m_edit2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(10, 90, 500, 120), this, 2);
	m_edit3.Create(WS_CHILD | WS_VISIBLE, CRect(10, 200, 500, 300), this, 3);
	setText();
}

void CPraticeMFCView::OnSize(UINT nType, int cx, int cy)
{
	//Wnd 사이즈 변경 시 호출
	CView::OnSize(nType, cx, cy);

	width = cx;
	height = cy;

	if(m_edit.GetSafeHwnd())
	{
		setText();
	}



// CPraticeMFCView 그리기
}

void CPraticeMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	m_pos = point;
	Invalidate();
	if(m_drag == TRUE)
	{
		setText2(L"드래그 중");
	}
	else if(m_drag == FALSE)
	{
		setText2(L"마우스를 이동중");
	}
	CView::OnMouseMove(nFlags, point);
}

void CPraticeMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_drag = TRUE;
	setText2(L"왼쪽 마우스 클릭");
	CView::OnLButtonDown(nFlags, point);
}

void CPraticeMFCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	setText2(L"오른쪽 마우스 클릭");
	CView::OnRButtonDown(nFlags, point);
}


void CPraticeMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_drag == TRUE)
	{
		m_drag = FALSE;
		setText2(L"마우스를 이동중");
		
	}
	CView::OnLButtonUp(nFlags, point);
}

void CPraticeMFCView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString tem;
	tem.Format(L"%d 키다운", nChar);
	setText2(tem);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CPraticeMFCView::setText()
{
	CString temp;
	temp.Format(L"윈도우 크기의 너비는 %d, 높이는 %d, 넓이는 %d입니다.", width, height, width*height);
	m_edit.SetWindowText(temp);
}

void CPraticeMFCView::setText2(CString str)
{
	CString temp;
	temp.Format(L"%s 입니다.", str);
	m_edit3.SetWindowText(temp);
}

void CPraticeMFCView::OnDraw(CDC* /*pDC*/)
{
	CPraticeMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CString strPoint;
	strPoint.Format(_T("마우스 좌표 (%4d, %4d)"), m_pos.x, m_pos.y);
	m_edit2.SetWindowText(strPoint);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPraticeMFCView 인쇄

BOOL CPraticeMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPraticeMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPraticeMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPraticeMFCView 진단

#ifdef _DEBUG
void CPraticeMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CPraticeMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPraticeMFCDoc* CPraticeMFCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPraticeMFCDoc)));
	return (CPraticeMFCDoc*)m_pDocument;
}


#endif //_DEBUG


// CPraticeMFCView 메시지 처리기
