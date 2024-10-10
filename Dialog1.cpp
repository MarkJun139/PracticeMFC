// Dialog1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PraticeMFC.h"
#include "Dialog1.h"


// Dialog1 ��ȭ �����Դϴ�.

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


// Dialog1 �޽��� ó�����Դϴ�.


BOOL Dialog1::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_sCombo.AddString(L"�ѱ�");
	m_sCombo.AddString(L"����");
	m_sCombo.AddString(L"�Ϻ�");

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
	te.Format(L"%s ���� �߰�", m_sList);
	UpdateListBox(te);
	UpdateData(FALSE);
}


void Dialog1::OnBnClickedRadio1()
{
	UpdateListBox(L"1�� ���� ��ư ����");
}

void Dialog1::OnBnClickedRadio2()
{
	UpdateListBox(L"2�� ���� ��ư ����");
}

void Dialog1::OnBnClickedCheck1()
{
	UpdateListBox(L"1�� üũ �ڽ� ����");
}

void Dialog1::OnBnClickedCheck2()
{
	UpdateListBox(L"2�� üũ �ڽ� ����");
}

void Dialog1::OnBnClickedButton2()
{
	UpdateData(TRUE);
	CString te;
	te.Format(L"%s �޺� �߰�", m_sComboT);
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
		pLB->GetText(nSel, str); // ���õ� �׸��� �ؽ�Ʈ ��������
	
		if (OpenClipboard())
		{
			EmptyClipboard();
			
			HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, (str.GetLength() + 1) * sizeof(TCHAR));
			
			if (hGlob) {
				LPTSTR pData = (LPTSTR)GlobalLock(hGlob); // �޸� ���
				if (pData) {
					memcpy(pData, str.GetBuffer(), (str.GetLength() + 1) * sizeof(TCHAR)); //�޸� ����
					GlobalUnlock(hGlob); // ��� ����
					if(SetClipboardData(CF_TEXT, hGlob) == NULL)
					{
						AfxMessageBox(L"Ŭ������ ���� ����");
					}
				} else {
					GlobalFree(hGlob); // ��� ���� �� �Ҵ� ����
				}
			}
			CloseClipboard(); // Ŭ������ �ݱ�
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
		AfxMessageBox(L"������ ���� �������ּ���!");
	}
	
}
