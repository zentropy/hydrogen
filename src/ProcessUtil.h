#pragma once

#ifdef _WIN32
#include <win/ProcessUtilWin.h>
#endif

namespace hydrogen { ;

class ProcessUtil
{
	ProcessUtil(const ProcessUtil&);
	ProcessUtil& operator=(const ProcessUtil&);
private:
	ProcessUtil() { ; }
	~ProcessUtil() { ; }
public:
	static bool SetProcessTitle()
	{

	}
};

}