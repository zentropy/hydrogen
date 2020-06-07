#pragma once

#include <string>

#ifdef WIN32
#include "win/PasteboardUtilWin.h"
#endif

namespace hydrogen { ;

#ifdef WIN32
typedef PasteboardUtilWin PasteboardUtilPlatform;
#endif

class PasteboardUtil
{
	PasteboardUtil(const PasteboardUtil&);
	PasteboardUtil& operator=(const PasteboardUtil&);
private:
	enum { QQRichEditFormat = 0xc0bd, QQUnicodeRichEditFormat = 0xc2f2, };
private:
	PasteboardUtil() { ; }
	~PasteboardUtil() { ; }
public:
	static bool HasData()
	{
		return PasteboardUtilPlatform::HasData();
	}
public:
	static bool WriteString(const std::wstring& wstr)
	{
		std::string error = "";
		return PasteboardUtilPlatform::WriteString(wstr,error);
	}
public:
	static bool ReadString(std::wstring& wstr)
	{
		std::string error = "";
		return PasteboardUtilPlatform::ReadString(wstr,error);
	}
public:
	static bool ReadDib(unsigned char* pData, size_t& len)
	{
		std::string error = "";
		return PasteboardUtilPlatform::ReadDib(pData, len,error);
	}
	static bool WriteDib(const unsigned char* pData, size_t size)
	{
		std::string error = "";
		return PasteboardUtilPlatform::WriteDib(pData, size,error);
	}
	static bool ReadBitmap(unsigned char* pData, size_t& len)
	{
		std::string error = "";
		return  PasteboardUtilPlatform::ReadBitmap(pData, len,error);
	}
	static bool WriteBitmap(const unsigned char* pData, size_t size)
	{
		std::string error = "";
		return PasteboardUtilPlatform::WriteBitmap(pData, size,error);
	}
public:
	static bool ReadFormat(string& str, const wstring& wstrFormatName)
	{
		std::string error = "";
		return PasteboardUtilPlatform::ReadFormat(str, wstrFormatName,error);
	}
public:
	static bool WriteFormat(const string& str, const wstring& wstrFormatName)
	{
		std::string error = "";
		return PasteboardUtilPlatform::WriteFormat(str, wstrFormatName,error);
	}
public:
	static bool ReadQQRichEditFormat(string& str)
	{
		return PasteboardUtilPlatform::ReadQQRichEditFormat(str);
	}
};

}
