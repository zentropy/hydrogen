#pragma once

#include <functional>
#include <vector>
#include <map>
#include <string>
#include <comdef.h>
#include <Wbemidl.h>
#include "StringUtil.h"

#pragma comment(lib,"Wbemuuid.lib")

using namespace hydrogen;

namespace hydrogen_impl {;

/*
AddressWidth:在32位操作系统，该值是32，在64位操作系统是64。
Architecture:所使用的平台的处理器架构。
AssetTag:代表该处理器的资产标签。
Availability:设备的状态。
Caption:设备的简短描述
Characteristics:处理器支持定义的功能
ConfigManagerErrorCode:Windows API的配置管理器错误代码
ConfigManagerUserConfig:如果为TRUE，该装置是使用用户定义的配置
CpuStatus:处理器的当前状态
CreationClassName:出现在用来创建一个实例继承链的第一个具体类的名称
CurrentClockSpeed:处理器的当前速度，以MHz为单位
CurrentVoltage:处理器的电压。如果第八位被设置，位0-6包含电压乘以10，如果第八位没有置位，则位在VoltageCaps设定表示的电压值。 CurrentVoltage时SMBIOS指定的电压值只设置
DataWidth:在32位处理器，该值是32，在64位处理器是64
Description:描述
DeviceID:在系统上的处理器的唯一标识符
ErrorCleared:如果为真，报上一个错误代码的被清除
ErrorDescription:错误的代码描述
ExtClock:外部时钟频率，以MHz为单位
Family:处理器系列类型
InstallDate:安装日期
L2CacheSize:二级缓存大小
L2CacheSpeed:二级缓存处理器的时钟速度
L3CacheSize:三级缓存的大小
L3CacheSpeed:三级缓存处理器的时钟速度
LastErrorCode:报告的逻辑设备上一个错误代码
Level:处理器类型的定义。该值取决于处理器的体系结构
LoadPercentage:每个处理器的负载能力，平均到最后一秒
Manufacturer:处理器的制造商
MaxClockSpeed:处理器的最大速度，以MHz为单位
Name:处理器的名称
NumberOfCores:芯为处理器的当前实例的数目。核心是在集成电路上的物理处理器
NumberOfEnabledCore:每个处理器插槽启用的内核数
NumberOfLogicalProcessors:用于处理器的当前实例逻辑处理器的数量
OtherFamilyDescription:处理器系列类型
PartNumber:这款处理器的产品编号制造商所设置
PNPDeviceID:即插即用逻辑设备的播放设备标识符
PowerManagementCapabilities:逻辑设备的特定功率相关的能力阵列
PowerManagementSupported:如果为TRUE，该装置的功率可以被管理，这意味着它可以被放入挂起模式
ProcessorId:描述处理器功能的处理器的信息
ProcessorType:处理器的主要功能
Revision:系统修订级别取决于体系结构
Role:所述处理器的作用
SecondLevelAddressTranslationExtensions:如果为True，该处理器支持用于虚拟地址转换扩展
SerialNumber:处理器的序列号
SocketDesignation:芯片插座的线路上使用的类型
Status:对象的当前状态
StatusInfo:对象的当前状态信息
Stepping:在处理器家族处理器的版本
SystemCreationClassName:创建类名属性的作用域计算机的价值
SystemName:系统的名称
ThreadCount:每个处理器插槽的线程数
UniqueId:全局唯一标识符的处理器
UpgradeMethod:CPU插槽的信息
Version:依赖于架构处理器的版本号
VirtualizationFirmwareEnabled:如果真，固件可以虚拟化扩展
VMMonitorModeExtensions:如果为True，该处理器支持Intel或AMD虚拟机监控器扩展。
VoltageCaps:该处理器的电压的能力
*/


/*
Win32_baseboard
Caption  --简短说明
ConfigOptions   --数组，表示位于在底板上跳线和开关的配置。
CreationClassName  --表示类的名称(就是Win32_baseboard类)
Depth   --以英寸为单位的物理封装。
Description  --对象的描述（底板）
Height  --用英寸表示的物理包的高度
HostingBoard  --如果为TRUE，该卡是一个主板，或在一个机箱中的基板。
HotSwappable  --如果为TRUE，就是支持热插拔（判断是否支持热插拔）
InstallDate  --日期和时间对象安装。此属性不需要的值以表示已安装的对象。
Manufacturer  --表示制造商的名称
Model  --物理元素的名称是已知。
Name   --对象的名称标签
OtherIdentifyingInfo  --捕获附加数据，超出资产标签的信息，可以用来标识物理元件
PartNumber  --由负责生产或制造的物理元素的组织分配部件编号。
PoweredOn  --如果为真，物理元素处于开机状态。
Product  --产品的型号
Removable  --判断是否可拆卸的
Replaceable  --判断是否可更换的
RequirementsDescription  --自由格式字符串描述方式，这张卡是身体不同于其他卡。该属性才有意义时，相对应的布尔值属性特殊要求是集真的
RequiresDaughterBoard  --如果是TRUE，至少一个子板或辅助卡才能正常工作。
SerialNumber  --制造商分配的用于识别所述物理元件数目。
SKU  --库存的物理单元号。
SlotLayout  --描述插槽位置
SpecialRequirements  --如果为真，此卡是同类型的其他卡物理上唯一的，因此需要一个专门的插槽
Status  --对象的当前状态。
Tag  --符系统的基板唯一标识
Version  --物理元素的版本
Weight  --物理元素的重量英镑表示
Width  --用英寸表示的物理元素的宽度
*/

/*
Win32_VideoController
AcceleratorCapabilities:图形和视频控制器的三维阵列的能力
AdapterCompatibility  --用于此控制器与系统比较兼容性一般芯片组
AdapterDACType  --姓名或数字 - 模拟转换器（DAC）芯片的标识符
AdapterRAM  --视频适配器的内存大小
Availability  --可用性和设备的状态
CapabilityDescriptions  --自由形式字符串提供更详细的解释中的任何加速器能力阵列所指示的视频加速器功能
Caption  --对象的简短描述
ColorTableEntries  --尺寸系统的色表
ConfigManagerErrorCode  --Win32的配置管理器错误代码
ConfigManagerUserConfig  --如果为TRUE，该装置是使用用户定义的配置
CreationClassName  --第一个具体类的名称出现在创建实例所使用的继承链
CurrentBitsPerPixel  --使用的比特数以显示每个像素
CurrentHorizontalResolution  --水平像素的当前数量
CurrentNumberOfColors  --在当前的分辨率支持的色彩数目
CurrentNumberOfColumns  --此视频控制器列（如果在字符模式下）编号
CurrentNumberOfRows  --此视频控制器行（如果在字符模式下）编号
CurrentRefreshRate  --频率在该视频控制器刷新监视器的图像
CurrentScanMode  --当前扫描模式
CurrentVerticalResolution  --当前垂直像素数量
Description  --描述
DeviceID  --该视频控制器标识符（唯一的计算机系统）
DeviceSpecificPens  --目前许多设备专用笔。值0xFFFF表示设备不支持笔。
DitherType  --抖动型视频控制器
DriverDate  --当前已安装的视频驱动程序的最后修改日期和时间
DriverVersion  --视频驱动程序的版本号
ErrorCleared  --如果为真，报上一个错误代码属性中的错误现已清除
ErrorDescription  --可能采取的纠正措施字符串提供有关记录在一个错误代码属性错误的详细信息
ICMIntent  --应使用默认三种可能的配色方法或意图中的一个特定值
ICMMethod  --处理ICM方法。对于非ICM的应用程序，这个属性决定了ICM是否已启用对于ICM的应用程序，系统将检查此属性来确定如何处理ICM支持
InfFilename  --视频适配器的路径.inf文件
InfSection  --Windows的视频信息所在的.inf文件
InstallDate  --安装的日期
InstalledDisplayDrivers  --已安装的显示设备驱动程序的名称
LastErrorCode  --报告的逻辑设备上一个错误代码
MaxMemorySupported  --以字节为单位支持的内存最高限额
MaxNumberControlled  --可支持通过该控制器可直接寻址的实体的最大数量
MaxRefreshRate  --在赫兹视频控制器的最大刷新率
MinRefreshRate   --在赫兹视频控制器的最小刷新率
Monochrome  --如果是TRUE，灰阶用于显示图像。
Name  --标签由该对象是已知的。当子类，该属性可以被覆盖是一个关键属性。
NumberOfColorPlanes  --当前一些颜色平面。如果该值不适用于当前视频的配置，输入0（零）
NumberOfVideoPages  --当前的分辨率和可用内存支持视频页数
PNPDeviceID  --即插即用逻辑设备的播放装置识别符
PowerManagementCapabilities  --逻辑设备的特定功率相关的能力阵列
PowerManagementSupported  --如果为TRUE，该装置可以是电源管理（可以投入挂起模式，等等）
ProtocolSupported  --由控制器使用协议访问“控制”的设备
ReservedSystemPaletteEntries  --系统调色板保留的条目数
SpecificationVersion  --初始化数据规范的版本号（在其上的结构的基础）
Status  --对象的当前状态
StatusInfo  --对象的当前状态详细信息
SystemCreationClassName  --该作用域计算机的创建类别名称属性的值
SystemName  --系统的名称
SystemPaletteEntries  --当前一些系统调色板颜色索引条目
TimeOfLastReset  --该控制器是最后一次复位日期和时间，这可能意味着该控制器被断电或重新初始化
VideoArchitecture  --视频体系结构的类型
VideoMemoryType  --显存类型
VideoMode  --当前视频模式
VideoModeDescription  --当前的分辨率，颜色和视频控制器的扫描模式设置
VideoProcessor  --无格式的字符串描述视频处理器
*/

class WMIUtil
{
	WMIUtil(const WMIUtil&);
	WMIUtil& operator=(const WMIUtil&);
private:
	WMIUtil() { ; }
	~WMIUtil() { ; }
private:
	typedef std::pair<std::string,std::string>	propertyKey;
public:
	static std::vector<std::string> GetCpuName() { return GetPropertyValue("Win32_Processor", "Name"); }
	static std::vector<std::string> GetBaseboardName() { return GetPropertyValue("Win32_baseboard","Name"); }
public:
	static std::vector<std::string> GetPropertyValue(const std::string& className,const std::string& propertyName)
	{
		static std::map<propertyKey, std::vector<std::string> > mapPropertyValue;
		static std::map<propertyKey, unsigned int> mapPropertyDefines;
		if(0 == mapPropertyDefines.size())
		{
			mapPropertyDefines[std::make_pair("Win32_Processor", "Description")] = VT_BSTR;
			mapPropertyDefines[std::make_pair("Win32_Processor","Name")] = VT_BSTR;


			mapPropertyDefines[std::make_pair("Win32_baseboard", "Name")] = VT_BSTR;
			mapPropertyDefines[std::make_pair("Win32_baseboard","Description")] = VT_BSTR;
			mapPropertyDefines[std::make_pair("Win32_baseboard", "Product")] = VT_BSTR;
			mapPropertyDefines[std::make_pair("Win32_baseboard", "Manufacturer")] = VT_BSTR;
			mapPropertyDefines[std::make_pair("Win32_baseboard", "SerialNumber")] = VT_BSTR;

			mapPropertyDefines[std::make_pair("Win32_VideoController", "AdapterRAM")] = VT_I4;
			mapPropertyDefines[std::make_pair("Win32_VideoController", "Description")] = VT_BSTR;
			mapPropertyDefines[std::make_pair("Win32_VideoController","VideoProcessor")] = VT_BSTR;

			mapPropertyDefines[std::make_pair("Win32_PhysicalMedia", "SerialNumber")] = VT_BSTR;

			mapPropertyDefines[std::make_pair("Win32_DiskDrive", "Caption")] = VT_BSTR;

			getHardwareInfo(mapPropertyDefines, mapPropertyValue);
		}
		return mapPropertyValue[std::make_pair(className,propertyName)];
	}
private:
	static bool getHardwareInfo(const std::map<propertyKey, unsigned int>& mapPropertyDefines,std::map< propertyKey, std::vector<std::string> >& mapPropertyValue)
	{
		HRESULT hr = CoInitializeEx(0, COINIT_APARTMENTTHREADED);
		//if (FAILED(hr)) return false;

		//// Initialize 
		//hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
		//if (FAILED(hr)) { CoUninitialize(); return false; }

		// Obtain the initial locator to Windows Management
		// on a particular host computer.
		IWbemLocator *pLoc = 0;
		hr = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&pLoc);
		if (FAILED(hr)) { return false; }

		IWbemServices *pSvc = 0;

		// Connect to the root\cimv2 namespace with the current user and obtain pointer pSvc to make IWbemServices calls.
		hr = pLoc->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &pSvc);
		if (FAILED(hr)) { pLoc->Release(); return false; }

		// Set the IWbemServices proxy so that impersonation of the user (client) occurs.
		hr = CoSetProxyBlanket(
			pSvc,                         // the proxy to set
			RPC_C_AUTHN_WINNT,            // authentication service
			RPC_C_AUTHZ_NONE,             // authorization service
			NULL,                         // Server principal name
			RPC_C_AUTHN_LEVEL_CALL,       // authentication level
			RPC_C_IMP_LEVEL_IMPERSONATE,  // impersonation level
			NULL,                         // client identity 
			EOAC_NONE                     // proxy capabilities     
		);

		if (FAILED(hr)) { pSvc->Release(); pLoc->Release(); return false; }


		// Use the IWbemServices pointer to make requests of WMI. Make requests here:

		// For example, query for all the running processes
		for (std::map<propertyKey, unsigned int>::const_iterator it = mapPropertyDefines.begin(); it != mapPropertyDefines.end();)
		{
			std::string className = it->first.first;

			std::map<std::string,unsigned int> propertys;
			std::map<std::string, std::vector<std::string> > values;
			for(;it != mapPropertyDefines.end() && it->first.first == className;++it)
			{
				propertys[it->first.second] = it->second;
				values[it->first.second] = std::vector<std::string>();
			}
			
			findHardwareInfo(pSvc, className, [&](IWbemClassObject* pclsObj) {
				findPropertyValue(pclsObj, propertys, values);
			});
			for(std::map<std::string,std::vector<std::string> >::const_iterator iter = values.begin();iter != values.end();++iter)
			{
				mapPropertyValue[std::make_pair(className,iter->first)] = iter->second;
			}
		}

		// Cleanup
		// ========

		pSvc->Release();
		pLoc->Release();
		return true;
	}
	static bool findHardwareInfo(IWbemServices *pSvc, const std::string& hardwareName, const std::function<void(IWbemClassObject* pclsObj)>& funcObj)
	{
		if (NULL == pSvc || 0 == hardwareName.size()) return false;
		std::string sqlCode = "SELECT * FROM " + hardwareName;
		IEnumWbemClassObject* pEnumerator = NULL;
		HRESULT hr = pSvc->ExecQuery(bstr_t("WQL"), bstr_t(sqlCode.c_str()), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator);

		if (FAILED(hr))	return false;
		while (pEnumerator)
		{
			IWbemClassObject *pclsObj = NULL;
			ULONG uReturn = 0;
			hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if (0 == uReturn) break;
			if (NULL == pclsObj) continue;
			if (nullptr != funcObj)
			{
				funcObj(pclsObj);
			}
		}
		return true;
	}
private:
	static bool findPropertyValue(IWbemClassObject* pclsObj, const std::map<std::string,unsigned int> & propertys,std::map<std::string, std::vector<std::string> >& values)
	{
		if(NULL == pclsObj) return false;
		for(std::map<std::string, unsigned int>::const_iterator it = propertys.begin();it != propertys.end();++it)
		{
			VARIANT vtProp; VariantInit(&vtProp);
			HRESULT hr = pclsObj->Get(StringUtil::Utf8ToUnicode(it->first).c_str(), 0, &vtProp, 0, 0);
			std::string value = "";
			if (FAILED(hr))
			{
				assert(0);
				//TRACEW("get property %s failed,%08x", propertyName[i].c_str(),hr);
			}
			else
			{
				//TRACED("get property %s success,type = %d", propertyName[i].c_str(),vtProp.vt);
				switch(it->second)
				{
				case VT_I4:value = StringUtil::ConvertFromUInt(vtProp.uintVal);break;
				case VT_BSTR:value = StringUtil::UnicodeToUtf8(vtProp.bstrVal);break;
				default:assert(0);break;
				}
			}
			VariantClear(&vtProp);
			std::vector<std::string>& r = values[it->first];
			r.push_back(value);
		}
		return true;
	}
};

}