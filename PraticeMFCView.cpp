
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
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()




// CPraticeMFCView 생성/소멸

CPraticeMFCView::CPraticeMFCView()
{
	//AfxMessageBox(L"윈도우 생성");
}

CPraticeMFCView::~CPraticeMFCView()
{
	//AfxMessageBox(L"윈도우 소멸");
	//delete m_week2;
}


int CPraticeMFCView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if(CView::OnCreate(lpCreateStruct) == -1)
	{	
		return -1;
	}
	AfxMessageBox(L"윈도우가 생성되었습니다.");
	return 0;

}

void CPraticeMFCView::OnDestroy()
{
	AfxMessageBox(L"윈도우가 종료되었습니다.");
	CView::OnDestroy();

	KillTimer(m_timer);
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
	m_edit3.Create(WS_CHILD | WS_VISIBLE, CRect(10, 150, 300, 180), this, 3);
	SetText();

	m_timer = NULL;

}

void CPraticeMFCView::OnSize(UINT nType, int cx, int cy)
{
	//Wnd 사이즈 변경 시 호출
	CView::OnSize(nType, cx, cy);

	width = cx;
	height = cy;

	if(m_edit.GetSafeHwnd())
	{
		SetText();
	}

}

void CPraticeMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
// 	m_pos = point;
// 	Invalidate();
// 	if(m_drag == TRUE)
// 	{
// 		SetText2(L"드래그 중");
// 	}
// 	else if(m_drag == FALSE)
// 	{	
// 		SetText2(L"마우스를 이동중");
// 	}
// 	CView::OnMouseMove(nFlags, point);
}	


void CPraticeMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
// 	m_drag = TRUE;
// 	SetText2(L"왼쪽 마우스 클릭");
// 	CView::OnLButtonDown(nFlags, point);
	m_timer = SetTimer(1, 1000, NULL);
	DrawTimer();
}

void CPraticeMFCView::OnRButtonDown(UINT nFlags, CPoint point)
{
// 	SetText2(L"오른쪽 마우스 클릭");
// 	CView::OnRButtonDown(nFlags, point);
	KillTimer(m_timer);
	SetText2(L"");
}


void CPraticeMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_drag == TRUE)
	{
		m_drag = FALSE;
		SetText2(L"마우스를 이동중");
		
	}
	CView::OnLButtonUp(nFlags, point);
}

void CPraticeMFCView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString tem;
	//tem.Format(L"%d 키다운", nChar);
	//SetText2(tem);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);

	if(nChar == 37 || nChar == 38 || nChar == 39 || nChar == 40)
	{
		CRect rect;
		m_edit3.GetWindowRect(&rect);
		ScreenToClient(&rect);

		CRect clientRect;
		GetClientRect(&clientRect);

		int x, y, x2, y2;

		if(m_timer != NULL)
		{

			if(nChar == 37)
			{
				rect.OffsetRect(-5, 0);

				x = rect.left;
				y = rect.top;

				if(x < 10)
				{
					AfxMessageBox(L"더이상 왼쪽으로 이동할 수 없습니다!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}
				
		
			}
			if(nChar == 38)
			{
				rect.OffsetRect(0, -10);

				x = rect.left;
				y = rect.top;

				if(y < 0)
				{
					AfxMessageBox(L"더이상 위쪽으로 이동할 수 없습니다!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}


			}
			if(nChar == 39)
			{

				rect.OffsetRect(5, 0);

				x2 = clientRect.right;
				y2 = clientRect.bottom;

				x = rect.right;
				y = rect.top;

				if(x > x2)
				{
					AfxMessageBox(L"더이상 오른쪽으로 이동할 수 없습니다!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}

			
			}
			if(nChar == 40)
			{
				rect.OffsetRect(0, 5);

				x2 = clientRect.right;
				y2 = clientRect.bottom;

				x = rect.right;
				y = rect.bottom;

				if(y > y2)
				{
					AfxMessageBox(L"더이상 아래쪽으로 이동할 수 없습니다!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}

			
			}	
		}
	}
}

void CPraticeMFCView::SetText()
{	
	CString temp;
	temp.Format(L"윈도우 크기의 너비는 %d, 높이는 %d, 넓이는 %d입니다.", width, height, width*height);
	m_edit.SetWindowText(temp);
}

void CPraticeMFCView::SetText2(CString str)
{
	CString temp;
	temp.Format(L"%s", str);
	m_edit3.SetWindowText(temp);
}

void CPraticeMFCView::DrawTimer()
{
	if(m_timer != NULL)
	{
		CTime cTime = CTime::GetCurrentTime();

		CString strTime;
		strTime.Format(_T("현재는 %04d년 %02d월 %02d일 %02d시 %02d분 %02d초"),
			cTime.GetYear(),
			cTime.GetMonth(),
			cTime.GetDay(),
			cTime.GetHour(),
			cTime.GetMinute(),
			cTime.GetSecond());

		SetText2(strTime);
	}
}

void CPraticeMFCView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == m_timer)
	{
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
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

	DrawTimer();

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
