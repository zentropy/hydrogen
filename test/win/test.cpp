// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HardwareInfoTest.h"
#include "PasteboardUtilTest.h"

int main()
{
	HardwareInfoTest::RunTest();
	PasteboardUtilTest::RunTest();
	return 0;
}