


#include<iostream>

using namespace std;

#include"GalaxyIncludes.h"
#include <opencv2/opencv.hpp>


int main() {
IGXFactory::GetInstance().Init();
GxIAPICPP::gxdeviceinfo_vector vectorDeviceInfo;

IGXFactory::GetInstance().UpdateDeviceList(1000, vectorDeviceInfo);

for (uint32_t i = 0; i < vectorDeviceInfo.size(); i++)

{

	cout << vectorDeviceInfo[i].GetVendorName() << endl;

	cout << vectorDeviceInfo[i].GetModelName() << endl;


	//�����豸��Ϣ���IGXDeviceInfo�ӿ�
}

if (vectorDeviceInfo.size()> 0)

{

	//�������еĵ�һ���豸

	CGXDevicePointer objDevicePtr;

	GxIAPICPP::gxstring strSN = vectorDeviceInfo[0].GetSN();

	GxIAPICPP::gxstring strUserID = vectorDeviceInfo[0].GetUserID();

	GxIAPICPP::gxstring strMAC = vectorDeviceInfo[0].GetMAC();

	GxIAPICPP::gxstring strIP = vectorDeviceInfo[0].GetIP();
	cv::Mat img;
	cv::VideoCapture cap(CV_CAP_DSHOW + 1);
	cap >> img;
	cv::imshow("img", img);
	cv::waitKey(0);

	//�û�Ҳ����ֱ��ָ���򿪵��豸��Ϣ�����������ʹ�õ���ϢΪα����Ϣ���û���ʵ���豸Ϊ׼

	//GxIAPICPP::gxstring strSN     = "GA0140100002";

	//GxIAPICPP::gxstring strUserID = "MyUserName";

	//GxIAPICPP::gxstring strMAC    = "A1-0B-32-7C-6F-81";

	//GxIAPICPP::gxstring strIP     = "192.168.0.100";

	objDevicePtr = IGXFactory::GetInstance().OpenDeviceBySN(strSN, GX_ACCESS_EXCLUSIVE);

	//objDevicePtr = IGXFactory::GetInstance().OpenDeviceByUserID(strUserID, GX_ACCESS_EXCLUSIVE);

	//objDevicePtr = IGXFactory::GetInstance().OpenDeviceByMAC(strMAC, GX_ACCESS_EXCLUSIVE);

	//objDevicePtr = IGXFactory::GetInstance().OpenDeviceByIP(strIP, GX_ACCESS_EXCLUSIVE);
	CGXStreamPointer objStreamPtr = objDevicePtr->OpenStream(0);



	//������ͨ���ɼ�

	objStreamPtr->StartGrab();



	//���豸���Ϳ�������

	CGXFeatureControlPointer objFeatureControlPtr = objDevicePtr->GetRemoteFeatureControl();

	objFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();



	//�ɵ�֡

	CImageDataPointer objImageDataPtr;

	objImageDataPtr = objStreamPtr->GetImage(500);//��ʱʱ��ʹ��500ms���û����������趨

	if (objImageDataPtr->GetStatus() == GX_FRAME_STATUS_SUCCESS)

	{

	}



	//ͣ��

	objFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();

	objStreamPtr->StopGrab();



	//�ر���ͨ��

	objStreamPtr->Close();

	//�ر��豸֮�������ٵ���IDevice�Լ��豸��IFeatureControl��IStream�����нӿ�

	objDevicePtr->Close();

}

//�ر��豸֮�󣬲����ٵ��������κο�ӿ�

IGXFactory::GetInstance().Uninit();

system("pause");
}