// surf1.8Dlg.h : 头文件
//
#include <cv.h>
#pragma once


// Csurf18Dlg 对话框
class Csurf18Dlg : public CDialog
{
// 构造
public:
	Csurf18Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SURF18_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
