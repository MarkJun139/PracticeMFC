#pragma once


// DIalog2 ��ȭ �����Դϴ�.

class DIalog2 : public CDialog
{
	DECLARE_DYNAMIC(DIalog2)

public:
	DIalog2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DIalog2();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
