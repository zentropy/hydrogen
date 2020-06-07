#pragma once

#include "PasteboardUtil.h"

class PasteboardUtilTest
{
public:
	static void RunTest()
	{
		{
			std::wstring content = L"write paste from test";
			hydrogen::PasteboardUtil::WriteString(content);
			std::wstring ret = L"";
			hydrogen::PasteboardUtil::ReadString(ret);
			assert(ret == content);
		}
	}
};