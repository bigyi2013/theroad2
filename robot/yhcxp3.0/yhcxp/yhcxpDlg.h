// yhcxpDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "SerialPort.h"
#include<vector>

// CyhcxpDlg �Ի���
class CyhcxpDlg : public CDialogEx
{
// ����
public:
	CyhcxpDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHCXP_DIALOG };
#endif

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
	afx_msg LRESULT OnReceiveStr(WPARAM str, LPARAM commInfo);
	DECLARE_MESSAGE_MAP()
public:
	CSerialPort m_Serialport;
	std::vector <int> BaudRate;
	std::vector <int> Databits;
	std::vector <char*> stopbits;
	std::vector <char*> parity;
	//��������
	CComboBox m_port;
	//������
	CComboBox m_baudrate;
	// �򿪹رմ���
	CButton m_openclose;
	// �������ı�
	CEdit m_sendedit;
	afx_msg void OnBnClickedOpenclose();
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedDeteccom();
	afx_msg void OnBnClickedTextclc();
	CEdit m_receive;
	afx_msg void OnBnClickedRecclc();
	// ����λ
	CComboBox m_databits;
	// ֹͣλ
	CComboBox m_stopbits;
	// ��żλ
	CComboBox m_parity;
	void CComboBoxInti();//��ʼ��combobox�ؼ�
	bool send_model;//����ģʽ��־
	bool receive_model;//����ģʽ��־
	afx_msg void OnBnClickedSendhex();
	afx_msg void OnBnClickedSendchar();
	afx_msg void OnBnClickedReceivehex();
	afx_msg void OnBnClickedReceivechar();
	UINT sendcount;
	UINT receivecount;
	// ���ʹ���
	CStatic m_SendCount;
	// ���մ���
	CStatic m_ReceiveCount;
	afx_msg void OnBnClickedClearcount();
};
