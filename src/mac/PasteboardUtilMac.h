#pragma once

#include <string>

namespace hydrogen { ;

class PasteboardUtilMac
{
	PasteboardUtilMac(const PasteboardUtilMac&);
	PasteboardUtilMac& operator=(const PasteboardUtilMac&);
private:
	PasteboardUtilMac() { ; }
	~PasteboardUtilMac() { ; }
public:
	static bool HasData()
	{
		BOOL bRet = ::OpenClipboard(NULL);
		if (!bRet) return false;
		HGLOBAL hData = ::GetClipboardData(CF_UNICODETEXT);
		if (NULL != hData)
		{
			GlobalUnlock(hData);
			::CloseClipboard();
			return true;
		}
		hData = ::GetClipboardData(CF_DIB);
		if (NULL != hData)
		{
			GlobalUnlock(hData);
			::CloseClipboard();
			return true;
		}
		hData = ::GetClipboardData(QQRichEditFormat);
		if (NULL != hData)
		{
			GlobalUnlock(hData);
			::CloseClipboard();
			return true;
		}
		return false;
	}
public:
	static bool WriteString(const std::wstring& wstr,std::string& error)
	{
		return writeBuffer((const unsigned char*)(wstr.c_str()), (wstr.size() + 1) * sizeof(wchar_t), CF_UNICODETEXT,error);
	}
public:
	static bool ReadString(std::wstring& wstr,std::string& error)
	{
		BOOL bRet = ::OpenClipboard(NULL);
		if (!bRet) return false;
		HGLOBAL hData = ::GetClipboardData(CF_UNICODETEXT);
		if (NULL == hData) { ::CloseClipboard(); return false; }

		int nSize = (int)(GlobalSize(hData));
		if (nSize <= 0) { ::CloseClipboard(); return false; }

		wchar_t *pBuffer = (wchar_t *)GlobalLock(hData);
		if (NULL == pBuffer)
		{
			GlobalUnlock(hData);
			::CloseClipboard();
			return false;
		}

		wstr.clear();
		wstr = pBuffer;

		GlobalUnlock(hData);
		::CloseClipboard();
		return true;
	}
public:
	static bool ReadDib(unsigned char* pData, size_t& len,std::string& error) { return readBuffer(pData, len, CF_DIB,error); }
	static bool WriteDib(const unsigned char* pData, size_t nBytes, std::string& error) { return writeBuffer(pData, nBytes, CF_DIB,error); }
	static bool ReadBitmap(unsigned char* pData, size_t& len, std::string& error) { return readBuffer(pData, len, CF_BITMAP,error); }
	static bool WriteBitmap(const unsigned char* pData, size_t nBytes, std::string& error) { return writeBuffer(pData, nBytes, CF_BITMAP,error); }
public:
	static bool ReadFormat(std::string& str, const std::wstring& wstrFormatName,std::string& error)
	{
		UINT uFormat = registerFormat(wstrFormatName,error);
		if (0 == uFormat) return false;

		BOOL bRet = ::OpenClipboard(NULL);
		if (!bRet)
		{
			int code = ::GetLastError();
			//TRACEW("[!CU-RF!] OpenClipboard failed,code = %d", code);
			return false;
		}
		HGLOBAL hData = ::GetClipboardData(uFormat);
		if (NULL == hData)
		{
			//TRACED("[!CU-RF!] no data in clipboard ");
			::CloseClipboard();
			return false;
		}

		int nSize = (int)(GlobalSize(hData));
		if (nSize <= 0) { ::CloseClipboard(); return false; }

		char *pBuffer = (char*)GlobalLock(hData);
		if (NULL == pBuffer)
		{
			GlobalUnlock(hData);
			::CloseClipboard();
			return false;
		}
		//for(int i = 0;i < nSize;++i) TRACED("%02x ",pBuffer[i]);

		str.clear();
		str = pBuffer;

		GlobalUnlock(hData);
		::CloseClipboard();
		return true;
	}
public:
	static bool WriteFormat(const string& str, const wstring& wstrFormatName,std::string& error)
	{
		UINT uFormat = registerFormat(wstrFormatName,error);
		if (0 == uFormat) return false;
		return writeBuffer((const unsigned char*)(str.c_str()), str.size() + 1, uFormat,error);
	}
public:
	static bool ReadQQRichEditFormat(string& str)
	{
		BOOL bRet = ::OpenClipboard(NULL);
		if (!bRet) return false;
		HGLOBAL hData = ::GetClipboardData(QQRichEditFormat);
		if (NULL == hData) { ::CloseClipboard(); return false; }

		int nSize = (int)(GlobalSize(hData));
		if (nSize <= 0) { ::CloseClipboard(); return false; }

		char *pBuffer = (char*)GlobalLock(hData);
		if (NULL == pBuffer)
		{
			GlobalUnlock(hData);
			::CloseClipboard();
			return false;
		}
		//for(int i = 0;i < nSize;++i) TRACED("%02x ",pBuffer[i]);

		str.clear();
		str = pBuffer;

		GlobalUnlock(hData);
		::CloseClipboard();
		return true;
	}
private:
	static UINT registerFormat(const std::wstring& wstrFormatName,std::string& error)
	{
		// 自定义格式的值在[0xC000,0xFFFF]
		if (0 == wstrFormatName.size())
		{
			error = "format name is invalid";
			return 0;
		}
		UINT uFormat = ::RegisterClipboardFormat(wstrFormatName.c_str());
		if (0 == uFormat)
		{
			int code = ::GetLastError();
			error = "RegisterClipboardFormat failed,code:" + std::to_string(code);
			return 0;
		}
		return uFormat;
	}
private:
	static bool readBuffer(unsigned char* pData, size_t& len, unsigned int format,std::string& error)
	{
		BOOL bRet = ::OpenClipboard(NULL);
		if (!bRet)
		{
			error = "OpenClipboard failed," + ErrorUtilWin::GetLastErrorDesc();
			return false;
		}
		HGLOBAL hData = ::GetClipboardData(format);
		if (NULL == hData)
		{
			error = "no data in clipboard";
			::CloseClipboard();
			return false;
		}

		int nSize = (int)(GlobalSize(hData));
		if (nSize <= 0)
		{
			error = "no data in clipboard";
			::CloseClipboard();
			return false;
		}

		if (NULL == pData || len < nSize) { len = nSize; return false; }

		BYTE *pBuffer = (BYTE *)GlobalLock(hData);
		if (NULL == pBuffer)
		{
			GlobalUnlock(hData);
			::CloseClipboard();
			return false;
		}
		memcpy_s(pData, len, pBuffer, nSize);
		len = nSize;
		GlobalUnlock(hData);
		::CloseClipboard();
		return true;
	}
private:
	static bool writeBuffer(const unsigned char* pData, size_t nBytes, unsigned int format,std::string& error)
	{
		BOOL bRet = ::OpenClipboard(NULL);
		if (!bRet)
		{
			error = "OpenClipboard failed," + ErrorUtilWin::GetLastErrorDesc();
			return false;
		}

		HGLOBAL hData = ::GlobalAlloc(GMEM_DDESHARE | GHND, nBytes);
		if (NULL == hData)
		{
			error = "GlobalAlloc failed," + ErrorUtilWin::GetLastErrorDesc();
			CloseClipboard();
			return false;
		}

		unsigned char *pBuffer = (unsigned char*)GlobalLock(hData);
		memset(pBuffer, 0, nBytes);
		if (NULL != pBuffer) memcpy_s(pBuffer, nBytes, pData, nBytes);

		GlobalUnlock(hData);
		::EmptyClipboard();
		if (NULL == ::SetClipboardData(format, hData))
		{
			error = "SetClipboardData failed," + ErrorUtilWin::GetLastErrorDesc();
		}
		::GlobalFree(hData);
		::CloseClipboard();

		return true;
	}
};

}