// test2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>
#include <conio.h>
#include<iostream>
double squ(double x)
{
	return x*x;
}
void print_squ(double x)
{
	std::cout<< "squ:" << x << " is " << squ(x) << "\n";
}
int main()
{
	print_squ(1.23451);
	printf("press any key to exit\n");
	_getch();//等待终端输入任意字符
	exit(0);//退出程序。
}

