#pragma once

#include <string>
#include "HardwareInfo.h"
#include "WMIUtil.h"

using namespace hydrogen;

namespace hydrogen_impl {;

class HardwareInfoUtilWin
{
	HardwareInfoUtilWin(const HardwareInfoUtilWin&);
	HardwareInfoUtilWin& operator=(const HardwareInfoUtilWin&);
private:
	HardwareInfoUtilWin() { ; }
	~HardwareInfoUtilWin() { ; }
public:
	static bool GetVideoCardInfo(std::vector<hydrogen::Hardware_VideoCardInfo>& infos)
	{
		infos.clear();
		std::vector<std::string> names = WMIUtil::GetPropertyValue("Win32_VideoController","Description");
		std::vector<std::string> sizes = WMIUtil::GetPropertyValue("Win32_VideoController", "AdapterRAM");
		for(size_t i = 0;i < names.size();++i)
		{
			Hardware_VideoCardInfo u;
			u.name = names[i];
			u.memSize = StringUtil::ConvertToUInt(sizes[i]);
			infos.push_back(u);
		}
		return true;
	}
public:
	static bool GetDiskInfo(std::vector<hydrogen::Hardware_DiskInfo>& infos)
	{
		infos.clear();
		std::vector<std::string> sns = WMIUtil::GetPropertyValue("Win32_PhysicalMedia", "SerialNumber");
		std::vector<std::string> names = WMIUtil::GetPropertyValue("Win32_DiskDrive", "Caption");
		for (size_t i = 0; i < names.size(); ++i)
		{
			Hardware_DiskInfo u;
			u.name = names[i];
			u.serialNumber = sns[i];
			infos.push_back(u);
		}
		return true;
	}
public:
	static bool GetCpuInfo(std::vector<hydrogen::Hardware_CpuInfo>& infos)
	{
		infos.clear();
		//WMIUtil::GetPropertyValue("Win32_PhysicalMedia", "SerialNumber", sns);
		std::vector<std::string> names = WMIUtil::GetCpuName();
		for (size_t i = 0; i < names.size(); ++i)
		{
			Hardware_CpuInfo u;
			u.name = names[i];
			//u.serialNumber = sns[i];
			infos.push_back(u);
		}
		return true;
	}
private:
	static bool getAllHardwareInfoFromWMI()
	{
	}
};

}