#pragma once

#ifdef AA_PLATFORM_WINDOWS
	#ifdef AA_BUILD_DLL
		#define ANGA_API __declspec(dllexport)
	#else	
		#define ANGA_API __declspec(dllimport)
	#endif
#else
	#error AngA only support Windows!
#endif

#define BIT(x) (1 << x)