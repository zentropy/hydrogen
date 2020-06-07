#pragma once

#include "HardwareInfoUtil.h"
#include <iostream>

class HardwareInfoTest
{
public:
	static void RunTest()
	{
		{
			std::vector<hydrogen::Hardware_VideoCardInfo> infos;
			std::string error;
			hydrogen::HardwareInfoUtil::GetVideoCardInfo(infos, error);
			assert(infos.size() == 1);
			assert(infos[0].name == "Intel(R) UHD Graphics 620");
			assert(infos[0].memSize == 1073741824);
			for(size_t i = 0;i < infos.size();++i)
			{
				std::cout << "video card:" << infos[0].name << "(" << infos[0].memSize << ")" << std::endl;
			}

		}
		{
			std::vector<hydrogen::Hardware_DiskInfo> infos;
			std::string error = "";
			hydrogen::HardwareInfoUtil::GetDiskInfo(infos, error);
			assert(2 == infos.size());
			//assert(infos[0].name == "LENSE20256GMSP34MEAT2TA;Generic- SD/MMC USB Device");
			//assert(infos[0].serialNumber == "A032_9928_5D08_E000.;2012090114345300");
			for(size_t i = 0;i < infos.size();++i)
			{
				std::cout << "disk:" << infos[i].name << "(" << infos[i].serialNumber << ")" << std::endl;
			}
		}
		{

			std::vector<hydrogen::Hardware_CpuInfo> infos;
			std::string error = "";
			hydrogen::HardwareInfoUtil::GetCpuInfo(infos,error);
			for (size_t i = 0; i < infos.size(); ++i)
			{
				std::cout << "cpu:" << infos[i].name << std::endl;
			}
		}
	}
};