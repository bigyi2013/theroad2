// surf1.8Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "surf1.8.h"
#include "surf1.8Dlg.h"
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "windef.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "CvvImage.h"
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <iostream>
#include <vector>

using namespace std;  //ʹ�����ֿռ�std

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Csurf18Dlg �Ի���




Csurf18Dlg::Csurf18Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Csurf18Dlg::IDD, pParent)
		
	, ptr1(0)
	, ptr2(0)
	, tt(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Csurf18Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ptr1);
	DDX_Text(pDX, IDC_EDIT2, ptr2);
	DDX_Text(pDX, IDC_EDIT3, tt);
}

BEGIN_MESSAGE_MAP(Csurf18Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Csurf18Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Csurf18Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Csurf18Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Csurf18Dlg ��Ϣ�������

BOOL Csurf18Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	cv::initModule_nonfree();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Csurf18Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

//0xFFF0 ��Ӧ�����ƣ�1111 1111 1111 0000
//nID & 0xFFF0 ���ǰ�nID�����4λ��Ϊ0,Ȼ���жϵõ��������Ƿ��IDM_ABOUTBOX���
//�����Ի��������С����ť������Ҫ����Ĵ���
//�����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//�⽫�ɿ���Զ���ɡ�

void Csurf18Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);  
		int cyIcon = GetSystemMetrics(SM_CYICON);
        //����cxIcon����ʼ��GetSystemMetrics(SM_CXICON);
		CRect rect;//ָ��һ�����Σ��ÿͻ�����Ĵ�С���루������Ϊ��λ��
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR Csurf18Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Csurf18Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T("*.bmp"), NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		NULL);
	if( dlg.DoModal() != IDOK )                    // �ж��Ƿ���ͼƬ
		return;
    CString mPath = dlg.GetPathName();            // ��ȡͼƬ·��
	src = cvLoadImage( mPath, CV_LOAD_IMAGE_GRAYSCALE );    // ��ȡͼƬ�����浽һ���ֲ����� ipl �У��ԻҶȵ�ģʽ����ͼ��
	
	showimage(src,IDC_STATIC_PIC1);

	}



void Csurf18Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	CFileDialog dlg(TRUE, _T("*.bmp"), NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		NULL);
	if( dlg.DoModal() != IDOK )                    // �ж��Ƿ���ͼƬ
		return;
	CString mPath = dlg.GetPathName();            // ��ȡͼƬ·��
	obj = cvLoadImage( mPath, CV_LOAD_IMAGE_GRAYSCALE);    // ��ȡͼƬ�����浽һ���ֲ����� ipl �У��ԻҶȵ�ģʽ����ͼ��
   showimage(obj,IDC_STATIC_PIC2);
	
}
void Csurf18Dlg::showimage(IplImage *img,UINT ID)
{
	CDC* pDC = GetDlgItem( ID) ->GetDC();        // �����ʾ�ؼ��� DC
	HDC hDC = pDC ->GetSafeHdc();                // ��ȡ HDC(�豸���) �����л�ͼ����
	CRect rect;
	GetDlgItem(ID) ->GetClientRect( &rect );       // ��ȡ�ؼ������귶Χ
	CvvImage cimg;
	cimg.CopyOf( img );                            // ����ͼƬ
	cimg.DrawToHDC( hDC, &rect );                // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC( pDC );
}



void Csurf18Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
    CvMemStorage* storage = cvCreateMemStorage(0);        //����һ���ڴ�洢����ͳһ������ֶ�̬������ڴ�
	CvSeq *objectKeypoints = 0, *objectDescriptors = 0;// ��ʾָ�������㼰���������Ľṹ���ָ��
	CvSeq *imageKeypoints = 0, *imageDescriptors = 0;//����(object)�ͳ���(scene)��ͼ���������
	int i;
	if( !obj || !src )
	{
	  exit(-1);
	}
    double tt1 = (double)cvGetTickCount();     //��ȷ����������ִ��ʱ��
	
	CvSURFParams params = cvSURFParams(500, 1);//SURF�������ã���ֵ500������128ά������,�趨SURF�㷨�ĳ�ʼ����
	cvExtractSURF( obj, 0, &objectKeypoints, &objectDescriptors, storage, params );//��ȡͼ���е������㣬
	cvExtractSURF( src, 0, &imageKeypoints, &imageDescriptors, storage, params );
    
	CvPoint src_corners[4] = {{0,0}, {obj->width,0}, {obj->width, obj->height}, {0, obj->height}};//ԭͼ
	CvPoint dst_corners[4];          //Ŀ��ͼ

	IplImage* match = cvCreateImage(cvGetSize(src), 8, 3);
	
	cvCvtColor( src, match, CV_GRAY2BGR );           //��ɫ�ռ�ת��,CV_GRAY2BGR��gray��BGR
	
	
	int  locatePlanarObject(const CvSeq* , const CvSeq* ,
		const CvSeq* , const CvSeq* ,
		const CvPoint [4], CvPoint [4] );


#ifdef USE_FLANN     //�����Ƿ����� "USE_FLANN" ���ò�ͬ��ƥ�䷽����flann �� ��flann
	printf("Using approximate nearest neighbor search\n");
#endif
	// �ҵ�����ĵ㣬�ڴ�����ͼ���б��
	if( locatePlanarObject( objectKeypoints, objectDescriptors, imageKeypoints,
		imageDescriptors, src_corners, dst_corners ))//����ƥ��ĵ㣬locateplanarobject��������1������Ϊ0
	//�ҵ�����ͼ����Ŀ����ĸ������λ��
	{
		
		for( i = 0; i < 4; i++ )
		{
			CvPoint r1 = dst_corners[i%4];
			CvPoint r2 = dst_corners[(i+1)%4];
			cvLine( match, cvPoint(r1.x, r1.y ),
				cvPoint(r2.x, r2.y),CV_RGB(255,0,0) ,3);
			
		}
	}
	//����������
	CvPoint z1;
	z1.x=dst_corners[0].x+dst_corners[2].x;
	z1.x=z1.x/2;
	z1.y=dst_corners[0].y+dst_corners[2].y;
	z1.y=z1.y/2;
	CvPoint z2;
	z2.x=dst_corners[1].x+dst_corners[3].x;
	z2.x=z2.x/2;
	z2.y=dst_corners[1].y+dst_corners[3].y;
	z2.y=z2.y/2;
	CvPoint z0;
	z0.x=z1.x+z2.x;
	z0.x=z0.x/2;
	z0.y=z1.y+z2.y;
	z0.y=z0.y/2;

	cvLine( match, cvPoint(z0.x, z0.y ),
		cvPoint(dst_corners[0].x, dst_corners[0].y), CV_RGB(255,0,0),3 ); //��Խ���
   cvCircle(match, cvPoint(z0.x, z0.y ),1,CV_RGB(255,0,0),2,8,0);

	tt1 = (double)cvGetTickCount() - tt1;
	tt1= tt1/(cvGetTickFrequency()*1000.);
	//tt1 = (cvGetTickCount()-tt1)/1000000;
	tt=(int)tt1;

   
	//���ĵ���ʾ��ptrΪedit�ؼ��Ĺ���������
	ptr1=z0.x;
	ptr2=z0.y;
	UpdateData(FALSE);
   showimage(match,IDC_STATIC_PIC3);

}



#define USE_FLANN
double   compareSURFDescriptors( const float* d1, const float* d2, double best, int length )
//Ϊ��ȡ�ļ�ֵ�㸽�������������ӴӶ��γ�������Ϣ

{
	double total_cost = 0;
	assert( length % 4 == 0 );
	for( int i = 0; i < length; i += 4 )
	{
		double t0 = d1[i] - d2[i];
		double t1 = d1[i+1] - d2[i+1];
		double t2 = d1[i+2] - d2[i+2];
		double t3 = d1[i+3] - d2[i+3];
		total_cost += t0*t0 + t1*t1 + t2*t2 + t3*t3;
		if( total_cost > best )
			break;
	}
	return total_cost;
}

int naiveNearestNeighbor( const float* vec, int laplacian,
					 const CvSeq* model_keypoints,
					 const CvSeq* model_descriptors )   //���������������ľ���
 //vec:��ƥ�����������laplacian�����������laplacianֵ��ͬ���ݶȲ�ͬ��ʱ��ƥ��Ҳ���������
{
	int length = (int)(model_descriptors->elem_size/sizeof(float));
	int i, neighbor = -1;
	double d, dist1 = 1e6, dist2 = 1e6;
	CvSeqReader reader, kreader;
	cvStartReadSeq( model_keypoints, &kreader, 0 );  //��������seq��ʼ��reader��0��ʾ��ǰ����
	cvStartReadSeq( model_descriptors, &reader, 0 );

	for( i = 0; i < model_descriptors->total; i++ )
	{
		const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
		const float* mvec = (const float*)reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );   //��ȡ��һ��������
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		if( laplacian != kp->laplacian )
			continue;
		d = compareSURFDescriptors( vec, mvec, dist2, length );
        //Ϊ��ȡ�ļ�ֵ�㸽�������������ӴӶ��γ�������Ϣ

		if( d < dist1 )
		{
			dist2 = dist1;
			dist1 = d;
			neighbor = i;
		}
		else if ( d < dist2 )
			dist2 = d;
	}
	if ( dist1 < 0.6*dist2 )
		return neighbor;
	return -1;
}

void  findPairs( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors,
		  const CvSeq* imageKeypoints, const CvSeq* imageDescriptors, vector<int>& ptpairs )
{
	int i;
	CvSeqReader reader, kreader;
	cvStartReadSeq( objectKeypoints, &kreader );  //������seq�е�Ԫ�ش�ǰ�����������
	cvStartReadSeq( objectDescriptors, &reader );
	ptpairs.clear();

	for( i = 0; i < objectDescriptors->total; i++ )
	{
		const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
		const float* descriptor = (const float*)reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		int nearest_neighbor = naiveNearestNeighbor( descriptor, kp->laplacian, imageKeypoints, imageDescriptors );
		//���������������ľ���
		
		if( nearest_neighbor >= 0 )
		{
			ptpairs.push_back(i);
			ptpairs.push_back(nearest_neighbor);
		}
	}
}
//�����ҵ�����ͼ��֮��ƥ��ĵ�ԣ�����ƥ��ĵ�Դ洢�� ptpairs �����У���������(object)ͼ���������
//������Ӧ�����������ֲ��������ֱ�洢�� objectKeypoints �� objectDescriptors������(image)ͼ�����
//���㼰����Ӧ�����������ֲ��������ֱ�洢�� imageKeypoints�� imageDescriptors


void
flannFindPairs( const CvSeq*, const CvSeq* objectDescriptors,
			   const CvSeq*, const CvSeq* imageDescriptors, vector<int>& ptpairs )
                //�ҵ��������ƥ��� 

{
	int length = (int)(objectDescriptors->elem_size/sizeof(float));

	cv::Mat m_object(objectDescriptors->total, length, CV_32F);
	cv::Mat m_image(imageDescriptors->total, length, CV_32F);


	// copy descriptors
	CvSeqReader obj_reader;
	float* obj_ptr = m_object.ptr<float>(0);
	cvStartReadSeq( objectDescriptors, &obj_reader );    //������seq�е�Ԫ�ش�ǰ�����������
	for(int i = 0; i < objectDescriptors->total; i++ )
	{
		const float* descriptor = (const float*)obj_reader.ptr;
		CV_NEXT_SEQ_ELEM( obj_reader.seq->elem_size, obj_reader ); //��ȡ��һ��������
		memcpy(obj_ptr, descriptor, length*sizeof(float));
//��Դsrc��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n���ֽڵ�Ŀ��dest��ָ���ڴ��ַ����ʼλ����
		obj_ptr += length;
	}
	CvSeqReader img_reader;
	float* img_ptr = m_image.ptr<float>(0);
	cvStartReadSeq( imageDescriptors, &img_reader );
	for(int i = 0; i < imageDescriptors->total; i++ )
	{
		const float* descriptor = (const float*)img_reader.ptr;
		CV_NEXT_SEQ_ELEM( img_reader.seq->elem_size, img_reader );
		memcpy(img_ptr, descriptor, length*sizeof(float));
		img_ptr += length;
	}

	// find nearest neighbors using FLANN
	cv::Mat m_indices(objectDescriptors->total, 2, CV_32S);
	cv::Mat m_dists(objectDescriptors->total, 2, CV_32F);
	cv::flann::Index flann_index(m_image, cv::flann::KDTreeIndexParams(4));  // using 4 randomized kdtrees
	flann_index.knnSearch(m_object, m_indices, m_dists, 2, cv::flann::SearchParams(64) ); // maximum number of leafs checked
    //flannѰ��������ٽ�Keypoints

	int* indices_ptr = m_indices.ptr<int>(0);
	float* dists_ptr = m_dists.ptr<float>(0);
	for (int i=0;i<m_indices.rows;++i) {
		if (dists_ptr[2*i]<0.6*dists_ptr[2*i+1]) {
			ptpairs.push_back(i);
			ptpairs.push_back(indices_ptr[2*i]);
		}
	}
}


/* a rough implementation for object location */
int
locatePlanarObject( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors,
				   const CvSeq* imageKeypoints, const CvSeq* imageDescriptors,
				   const CvPoint src_corners[4], CvPoint dst_corners[4] )
                //����ͼ����Ŀ����ĸ�����λ��
{
	double h[9];
	CvMat _h = cvMat(3, 3, CV_64F, h);
	vector<int> ptpairs;
	vector<CvPoint2D32f> pt1, pt2;
	CvMat _pt1, _pt2;
	int i, n;

#ifdef USE_FLANN
	flannFindPairs( objectKeypoints, objectDescriptors, imageKeypoints, imageDescriptors, ptpairs );
#else
	findPairs( objectKeypoints, objectDescriptors, imageKeypoints, imageDescriptors, ptpairs );
#endif

	n = ptpairs.size()/2;
	if( n < 4 )
		return 0;

	pt1.resize(n);
	pt2.resize(n);
	for( i = 0; i < n; i++ )
	{
		pt1[i] = ((CvSURFPoint*)cvGetSeqElem(objectKeypoints,ptpairs[i*2]))->pt;
		pt2[i] = ((CvSURFPoint*)cvGetSeqElem(imageKeypoints,ptpairs[i*2+1]))->pt;
	}

	_pt1 = cvMat(1, n, CV_32FC2, &pt1[0] );
	_pt2 = cvMat(1, n, CV_32FC2, &pt2[0] );
	if( !cvFindHomography( &_pt1, &_pt2, &_h, CV_RANSAC, 5 ))
		return 0;

	for( i = 0; i < 4; i++ )
	{
		double x = src_corners[i].x, y = src_corners[i].y;
		double Z = 1./(h[6]*x + h[7]*y + h[8]);
		double X = (h[0]*x + h[1]*y + h[2])*Z;
		double Y = (h[3]*x + h[4]*y + h[5])*Z;
		dst_corners[i] = cvPoint(cvRound(X), cvRound(Y));
	}

	return 1;
}
//����Ѱ������(object)�ڳ���(image)�е�λ��,λ����Ϣ�����ڲ���dst_corners�У�����src_corners����
//��(object��width��height�Ⱦ������������ֲ�������findPairs


