
// PraticeMFCView.cpp : CPraticeMFCView Ŭ������ ����
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
	// ǥ�� �μ� ����Դϴ�.
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




// CPraticeMFCView ����/�Ҹ�

CPraticeMFCView::CPraticeMFCView()
{


}

CPraticeMFCView::~CPraticeMFCView()
{
}



BOOL CPraticeMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

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
	//Wnd ������ ���� �� ȣ��
	CView::OnSize(nType, cx, cy);

	width = cx;
	height = cy;

	if(m_edit.GetSafeHwnd())
	{
		setText();
	}



// CPraticeMFCView �׸���
}

void CPraticeMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	m_pos = point;
	Invalidate();
	if(m_drag == TRUE)
	{
		setText2(L"�巡�� ��");
	}
	else if(m_drag == FALSE)
	{
		setText2(L"���콺�� �̵���");
	}
	CView::OnMouseMove(nFlags, point);
}

void CPraticeMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_drag = TRUE;
	setText2(L"���� ���콺 Ŭ��");
	CView::OnLButtonDown(nFlags, point);
}

void CPraticeMFCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	setText2(L"������ ���콺 Ŭ��");
	CView::OnRButtonDown(nFlags, point);
}


void CPraticeMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_drag == TRUE)
	{
		m_drag = FALSE;
		setText2(L"���콺�� �̵���");
		
	}
	CView::OnLButtonUp(nFlags, point);
}

void CPraticeMFCView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString tem;
	tem.Format(L"%d Ű�ٿ�", nChar);
	setText2(tem);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CPraticeMFCView::setText()
{
	CString temp;
	temp.Format(L"������ ũ���� �ʺ�� %d, ���̴� %d, ���̴� %d�Դϴ�.", width, height, width*height);
	m_edit.SetWindowText(temp);
}

void CPraticeMFCView::setText2(CString str)
{
	CString temp;
	temp.Format(L"%s �Դϴ�.", str);
	m_edit3.SetWindowText(temp);
}

void CPraticeMFCView::OnDraw(CDC* /*pDC*/)
{
	CPraticeMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CString strPoint;
	strPoint.Format(_T("���콺 ��ǥ (%4d, %4d)"), m_pos.x, m_pos.y);
	m_edit2.SetWindowText(strPoint);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CPraticeMFCView �μ�

BOOL CPraticeMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPraticeMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPraticeMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CPraticeMFCView ����

#ifdef _DEBUG
void CPraticeMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CPraticeMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPraticeMFCDoc* CPraticeMFCView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPraticeMFCDoc)));
	return (CPraticeMFCDoc*)m_pDocument;
}


#endif //_DEBUG


// CPraticeMFCView �޽��� ó����
