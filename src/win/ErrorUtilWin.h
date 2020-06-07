#pragma once

#include <windows.h>

namespace hydrogen { ;

class ErrorUtilWin
{
	ErrorUtilWin(const ErrorUtilWin&);
	ErrorUtilWin& operator=(const ErrorUtilWin&);
private:
	ErrorUtilWin() { ; }
	~ErrorUtilWin() { ; }
public:
	static std::string GetLastErrorDesc()
	{
		int code = ::GetLastError();
		return std::string("code = ") + std::to_string(code);
	}
};

}