// Dialog1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PraticeMFC.h"
#include "Dialog1.h"


// Dialog1 대화 상자입니다.

IMPLEMENT_DYNAMIC(Dialog1, CDialog)

Dialog1::Dialog1(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog1::IDD, pParent)
{

}

Dialog1::~Dialog1()
{
}

void Dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sList);
	DDX_Control(pDX, IDC_COMBO1, m_sCombo);
	DDX_Text(pDX, IDC_COMBO1, m_sComboT);
}


BEGIN_MESSAGE_MAP(Dialog1, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &Dialog1::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO2, &Dialog1::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK1, &Dialog1::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &Dialog1::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON2, &Dialog1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Dialog1::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Dialog1::OnBnClickedButton5)
END_MESSAGE_MAP()


// Dialog1 메시지 처리기입니다.


BOOL Dialog1::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_sCombo.AddString(L"한국");
	m_sCombo.AddString(L"북한");
	m_sCombo.AddString(L"일본");

	return TRUE;
}

void Dialog1::UpdateListBox(CString str)
{
	CListBox* pLB = (CListBox*)GetDlgItem(IDC_LIST1);

	pLB->AddString(str);
}


void Dialog1::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString te;
	te.Format(L"%s 내용 추가", m_sList);
	UpdateListBox(te);
	UpdateData(FALSE);
}


void Dialog1::OnBnClickedRadio1()
{
	UpdateListBox(L"1번 라디오 버튼 선택");
}

void Dialog1::OnBnClickedRadio2()
{
	UpdateListBox(L"2번 라디오 버튼 선택");
}

void Dialog1::OnBnClickedCheck1()
{
	UpdateListBox(L"1번 체크 박스 선택");
}

void Dialog1::OnBnClickedCheck2()
{
	UpdateListBox(L"2번 체크 박스 선택");
}

void Dialog1::OnBnClickedButton2()
{
	UpdateData(TRUE);
	CString te;
	te.Format(L"%s 콤보 추가", m_sComboT);
	UpdateListBox(te);
	UpdateData(FALSE);	
}

void Dialog1::OnBnClickedButton4()
{
	CListBox* pLB = (CListBox*)GetDlgItem(IDC_LIST1);
	int nSel = pLB->GetCurSel();
	if(nSel != LB_ERR)
	{
		CString str;
		pLB->GetText(nSel, str); // 선택된 항목의 텍스트 가져오기
	
		if (OpenClipboard())
		{
			EmptyClipboard();
			
			HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, (str.GetLength() + 1) * sizeof(TCHAR));
			
			if (hGlob) {
				LPTSTR pData = (LPTSTR)GlobalLock(hGlob); // 메모리 잠금
				if (pData) {
					memcpy(pData, str.GetBuffer(), (str.GetLength() + 1) * sizeof(TCHAR)); //메모리 복사
					GlobalUnlock(hGlob); // 잠금 해제
					if(SetClipboardData(CF_TEXT, hGlob) == NULL)
					{
						AfxMessageBox(L"클립보드 설정 실패");
					}
				} else {
					GlobalFree(hGlob); // 잠금 실패 시 할당 해제
				}
			}
			CloseClipboard(); // 클립보드 닫기
		}
		
	}
}

void Dialog1::OnBnClickedButton5()
{
	CListBox* pLB = (CListBox*)GetDlgItem(IDC_LIST1);
	int nSel = pLB->GetCurSel();
	if(nSel != -1)
	{
		pLB->DeleteString(nSel);
	}
	else
	{
		AfxMessageBox(L"삭제할 셀을 선택해주세요!");
	}
	
}
