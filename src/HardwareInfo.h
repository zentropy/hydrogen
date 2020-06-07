#pragma once

#include <string>

namespace hydrogen { ;

#pragma pack(push,1)

struct Hardware_CpuInfo
{
	std::string name;
};

struct Hardware_BaseboardInfo
{
	std::string manufacturer;
	std::string product;
	std::string serialNumber;
};

struct Hardware_DiskInfo
{
	std::string name;
	std::string serialNumber;
};

struct Hardware_VideoCardInfo
{
	std::string name;
	unsigned int memSize;
};

#pragma pack(pop)

}