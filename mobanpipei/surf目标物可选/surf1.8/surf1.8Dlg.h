// surf1.8Dlg.h : ͷ�ļ�
//
#include <cv.h>
#pragma once


// Csurf18Dlg �Ի���
class Csurf18Dlg : public CDialog
{
// ����
public:
	Csurf18Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SURF18_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnStnClickedStaticPic1();
public:
//	afx_msg void OnBnClickedButton1();


public:
	afx_msg void OnBnClickedButton1();
	IplImage*  src;
	IplImage*  obj;
     IplImage*  src1;


public:
	afx_msg void OnBnClickedButton2();
public:
   void  showimage(IplImage * img,UINT ID);

public:
	afx_msg void OnBnClickedButton3();
public:
	int ptr1;
  
public:
	int ptr2;
public:
	int tt;
};
