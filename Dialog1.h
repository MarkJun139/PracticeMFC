#pragma once
#include "afxwin.h"


// Dialog1 대화 상자입니다.

class Dialog1 : public CDialog
{
	DECLARE_DYNAMIC(Dialog1)

public:
	Dialog1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Dialog1();

	CString m_sList;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedButton1();

	void UpdateListBox(CString str);
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();

	BOOL		 OnInitDialog();

	CComboBox m_sCombo;
	CString m_sComboT;
//	BOOL m_bLSel;
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnLbnSetfocusList1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
