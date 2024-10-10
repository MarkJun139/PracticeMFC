// DIalog2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PraticeMFC.h"
#include "DIalog2.h"


// DIalog2 대화 상자입니다.

IMPLEMENT_DYNAMIC(DIalog2, CDialog)

DIalog2::DIalog2(CWnd* pParent /*=NULL*/)
	: CDialog(DIalog2::IDD, pParent)
{

}

DIalog2::~DIalog2()
{
}

void DIalog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DIalog2, CDialog)
END_MESSAGE_MAP()


// DIalog2 메시지 처리기입니다.
