#pragma once

#ifdef _WIN32
#include "win/HardwareInfoUtilWin.h"
#endif

namespace hydrogen { ;

class HardwareInfoUtil
{
	HardwareInfoUtil(const HardwareInfoUtil&);
	HardwareInfoUtil& operator=(const HardwareInfoUtil&);
private:
	HardwareInfoUtil() { ; }
	~HardwareInfoUtil() { ; }
private:
	enum
	{
		HARDWARE_INFO_VIDEOCARDNAME = 0,
		HARDWARE_INFO_VIDEOCARDSIZE,
		HARDWARE_INFO_DISKSN,
		HARDWARE_INFO_DISKNAME,
		HARDWARE_INFO_COUNT,
	};
private:
#ifdef _WIN32
	typedef hydrogen_impl::HardwareInfoUtilWin HardwareInfoUtilPaltform;
#endif
public:
	static bool GetVideoCardInfo(std::vector<hydrogen::Hardware_VideoCardInfo>& infos,std::string& error)
	{
		return HardwareInfoUtilPaltform::GetVideoCardInfo(infos);
	}
public:
	static bool GetDiskInfo(std::vector<hydrogen::Hardware_DiskInfo>& infos,std::string& error)
	{
		return HardwareInfoUtilPaltform::GetDiskInfo(infos);
	}
public:
	static bool GetCpuInfo(std::vector<hydrogen::Hardware_CpuInfo>& infos, std::string& error)
	{
		return HardwareInfoUtilPaltform::GetCpuInfo(infos);
	}
private:
	static bool getHardwareInfoFromCache(unsigned int key,std::string& value)
	{
		if (key >= HARDWARE_INFO_COUNT) return false;
		static std::string hardwareData[HARDWARE_INFO_COUNT];
		if (0 != hardwareData[key].size())
		{
			value = hardwareData[key];
			return true;
		}
		switch (key)
		{
		default:
			break;
		}
		return true;
	}
};

}