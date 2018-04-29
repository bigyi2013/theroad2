// surf1.8Dlg.cpp : 实现文件
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

using namespace std;  //使用名字空间std

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Csurf18Dlg 对话框




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


// Csurf18Dlg 消息处理程序

BOOL Csurf18Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	cv::initModule_nonfree();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

//0xFFF0 对应二进制：1111 1111 1111 0000
//nID & 0xFFF0 就是把nID的最后4位置为0,然后判断得到的数据是否和IDM_ABOUTBOX相等
//如果向对话框添加最小化按钮，则需要下面的代码
//来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//这将由框架自动完成。

void Csurf18Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);  
		int cyIcon = GetSystemMetrics(SM_CYICON);
        //声明cxIcon，初始化GetSystemMetrics(SM_CXICON);
		CRect rect;//指定一个矩形，用客户区域的大小载入（以像素为单位）
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
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
	if( dlg.DoModal() != IDOK )                    // 判断是否获得图片
		return;
    CString mPath = dlg.GetPathName();            // 获取图片路径
	src = cvLoadImage( mPath, CV_LOAD_IMAGE_GRAYSCALE );    // 读取图片、缓存到一个局部变量 ipl 中，以灰度的模式载入图像
	
	showimage(src,IDC_STATIC_PIC1);

	}



void Csurf18Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	CFileDialog dlg(TRUE, _T("*.bmp"), NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		NULL);
	if( dlg.DoModal() != IDOK )                    // 判断是否获得图片
		return;
	CString mPath = dlg.GetPathName();            // 获取图片路径
	obj = cvLoadImage( mPath, CV_LOAD_IMAGE_GRAYSCALE);    // 读取图片、缓存到一个局部变量 ipl 中，以灰度的模式载入图像
   showimage(obj,IDC_STATIC_PIC2);
	
}
void Csurf18Dlg::showimage(IplImage *img,UINT ID)
{
	CDC* pDC = GetDlgItem( ID) ->GetDC();        // 获得显示控件的 DC
	HDC hDC = pDC ->GetSafeHdc();                // 获取 HDC(设备句柄) 来进行绘图操作
	CRect rect;
	GetDlgItem(ID) ->GetClientRect( &rect );       // 获取控件的坐标范围
	CvvImage cimg;
	cimg.CopyOf( img );                            // 复制图片
	cimg.DrawToHDC( hDC, &rect );                // 将图片绘制到显示控件的指定区域内
	ReleaseDC( pDC );
}



void Csurf18Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
    CvMemStorage* storage = cvCreateMemStorage(0);        //创建一个内存存储器，统一管理各种动态对象的内存
	CvSeq *objectKeypoints = 0, *objectDescriptors = 0;// 表示指向特征点及其描述符的结构体的指针
	CvSeq *imageKeypoints = 0, *imageDescriptors = 0;//物体(object)和场景(scene)的图像的特征点
	int i;
	if( !obj || !src )
	{
	  exit(-1);
	}
    double tt1 = (double)cvGetTickCount();     //精确测量函数的执行时间
	
	CvSURFParams params = cvSURFParams(500, 1);//SURF参数设置：阈值500，生成128维描述符,设定SURF算法的初始参数
	cvExtractSURF( obj, 0, &objectKeypoints, &objectDescriptors, storage, params );//提取图像中的特征点，
	cvExtractSURF( src, 0, &imageKeypoints, &imageDescriptors, storage, params );
    
	CvPoint src_corners[4] = {{0,0}, {obj->width,0}, {obj->width, obj->height}, {0, obj->height}};//原图
	CvPoint dst_corners[4];          //目标图

	IplImage* match = cvCreateImage(cvGetSize(src), 8, 3);
	
	cvCvtColor( src, match, CV_GRAY2BGR );           //颜色空间转换,CV_GRAY2BGR是gray到BGR
	
	
	int  locatePlanarObject(const CvSeq* , const CvSeq* ,
		const CvSeq* , const CvSeq* ,
		const CvPoint [4], CvPoint [4] );


#ifdef USE_FLANN     //根据是否定义了 "USE_FLANN" 采用不同的匹配方法，flann 和 非flann
	printf("Using approximate nearest neighbor search\n");
#endif
	// 找到最近的点，在待检测的图像中标出
	if( locatePlanarObject( objectKeypoints, objectDescriptors, imageKeypoints,
		imageDescriptors, src_corners, dst_corners ))//若有匹配的点，locateplanarobject函数返回1，否者为0
	//找到搜索图像中目标的四个顶点的位置
	{
		
		for( i = 0; i < 4; i++ )
		{
			CvPoint r1 = dst_corners[i%4];
			CvPoint r2 = dst_corners[(i+1)%4];
			cvLine( match, cvPoint(r1.x, r1.y ),
				cvPoint(r2.x, r2.y),CV_RGB(255,0,0) ,3);
			
		}
	}
	//求中心坐标
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
		cvPoint(dst_corners[0].x, dst_corners[0].y), CV_RGB(255,0,0),3 ); //半对角线
   cvCircle(match, cvPoint(z0.x, z0.y ),1,CV_RGB(255,0,0),2,8,0);

	tt1 = (double)cvGetTickCount() - tt1;
	tt1= tt1/(cvGetTickFrequency()*1000.);
	//tt1 = (cvGetTickCount()-tt1)/1000000;
	tt=(int)tt1;

   
	//中心点显示，ptr为edit控件的关联变量；
	ptr1=z0.x;
	ptr2=z0.y;
	UpdateData(FALSE);
   showimage(match,IDC_STATIC_PIC3);

}



#define USE_FLANN
double   compareSURFDescriptors( const float* d1, const float* d2, double best, int length )
//为求取的极值点附加主方向描述子从而形成特征信息

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
					 const CvSeq* model_descriptors )   //计算描述符向量的距离
 //vec:待匹配的描述符，laplacian：当两个点的laplacian值不同（梯度不同）时不匹配也不计算距离
{
	int length = (int)(model_descriptors->elem_size/sizeof(float));
	int i, neighbor = -1;
	double d, dist1 = 1e6, dist2 = 1e6;
	CvSeqReader reader, kreader;
	cvStartReadSeq( model_keypoints, &kreader, 0 );  //根据序列seq初始化reader，0表示从前向后读
	cvStartReadSeq( model_descriptors, &reader, 0 );

	for( i = 0; i < model_descriptors->total; i++ )
	{
		const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
		const float* mvec = (const float*)reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );   //读取下一个特征点
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		if( laplacian != kp->laplacian )
			continue;
		d = compareSURFDescriptors( vec, mvec, dist2, length );
        //为求取的极值点附加主方向描述子从而形成特征信息

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
	cvStartReadSeq( objectKeypoints, &kreader );  //将序列seq中的元素从前到后依次输出
	cvStartReadSeq( objectDescriptors, &reader );
	ptpairs.clear();

	for( i = 0; i < objectDescriptors->total; i++ )
	{
		const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
		const float* descriptor = (const float*)reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		int nearest_neighbor = naiveNearestNeighbor( descriptor, kp->laplacian, imageKeypoints, imageDescriptors );
		//计算描述符向量的距离
		
		if( nearest_neighbor >= 0 )
		{
			ptpairs.push_back(i);
			ptpairs.push_back(nearest_neighbor);
		}
	}
}
//用于找到两幅图像之间匹配的点对，并把匹配的点对存储在 ptpairs 向量中，其中物体(object)图像的特征点
//及其相应的描述器（局部特征）分别存储在 objectKeypoints 和 objectDescriptors，场景(image)图像的特
//征点及其相应的描述器（局部特征）分别存储在 imageKeypoints和 imageDescriptors


void
flannFindPairs( const CvSeq*, const CvSeq* objectDescriptors,
			   const CvSeq*, const CvSeq* imageDescriptors, vector<int>& ptpairs )
                //找到特征点的匹配对 

{
	int length = (int)(objectDescriptors->elem_size/sizeof(float));

	cv::Mat m_object(objectDescriptors->total, length, CV_32F);
	cv::Mat m_image(imageDescriptors->total, length, CV_32F);


	// copy descriptors
	CvSeqReader obj_reader;
	float* obj_ptr = m_object.ptr<float>(0);
	cvStartReadSeq( objectDescriptors, &obj_reader );    //将序列seq中的元素从前到后依次输出
	for(int i = 0; i < objectDescriptors->total; i++ )
	{
		const float* descriptor = (const float*)obj_reader.ptr;
		CV_NEXT_SEQ_ELEM( obj_reader.seq->elem_size, obj_reader ); //读取下一个特征点
		memcpy(obj_ptr, descriptor, length*sizeof(float));
//从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
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
    //flann寻找最近的临近Keypoints

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
                //搜索图像中目标的四个顶点位置
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
//用于寻找物体(object)在场景(image)中的位置,位置信息保存在参数dst_corners中，参数src_corners由物
//体(object的width及height等决定，其他部分参数如上findPairs


