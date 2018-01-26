


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


	//更多设备信息详见IGXDeviceInfo接口
}

if (vectorDeviceInfo.size()> 0)

{

	//打开链表中的第一个设备

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

	//用户也可以直接指定打开的设备信息，下面代码中使用的信息为伪造信息，用户以实际设备为准

	//GxIAPICPP::gxstring strSN     = "GA0140100002";

	//GxIAPICPP::gxstring strUserID = "MyUserName";

	//GxIAPICPP::gxstring strMAC    = "A1-0B-32-7C-6F-81";

	//GxIAPICPP::gxstring strIP     = "192.168.0.100";

	objDevicePtr = IGXFactory::GetInstance().OpenDeviceBySN(strSN, GX_ACCESS_EXCLUSIVE);

	//objDevicePtr = IGXFactory::GetInstance().OpenDeviceByUserID(strUserID, GX_ACCESS_EXCLUSIVE);

	//objDevicePtr = IGXFactory::GetInstance().OpenDeviceByMAC(strMAC, GX_ACCESS_EXCLUSIVE);

	//objDevicePtr = IGXFactory::GetInstance().OpenDeviceByIP(strIP, GX_ACCESS_EXCLUSIVE);
	CGXStreamPointer objStreamPtr = objDevicePtr->OpenStream(0);



	//开启流通道采集

	objStreamPtr->StartGrab();



	//给设备发送开采命令

	CGXFeatureControlPointer objFeatureControlPtr = objDevicePtr->GetRemoteFeatureControl();

	objFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();



	//采单帧

	CImageDataPointer objImageDataPtr;

	objImageDataPtr = objStreamPtr->GetImage(500);//超时时间使用500ms，用户可以自行设定

	if (objImageDataPtr->GetStatus() == GX_FRAME_STATUS_SUCCESS)

	{

	}



	//停采

	objFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();

	objStreamPtr->StopGrab();



	//关闭流通道

	objStreamPtr->Close();

	//关闭设备之后不允许再调用IDevice以及设备的IFeatureControl、IStream的所有接口

	objDevicePtr->Close();

}

//关闭设备之后，不能再调用其他任何库接口

IGXFactory::GetInstance().Uninit();

system("pause");
}