
// PraticeMFCDoc.cpp : CPraticeMFCDoc 클래스의 구현
//

#include "stdafx.h"
#include "PraticeMFC.h"

#include "PraticeMFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPraticeMFCDoc

IMPLEMENT_DYNCREATE(CPraticeMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CPraticeMFCDoc, CDocument)
END_MESSAGE_MAP()


// CPraticeMFCDoc 생성/소멸

CPraticeMFCDoc::CPraticeMFCDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPraticeMFCDoc::~CPraticeMFCDoc()
{
}

BOOL CPraticeMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CPraticeMFCDoc serialization

void CPraticeMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CPraticeMFCDoc 진단

#ifdef _DEBUG
void CPraticeMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPraticeMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPraticeMFCDoc 명령
