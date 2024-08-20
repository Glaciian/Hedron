	// Ensure header files are included only once
#pragma once

	// Include all necessary header files into procompiled header: 
	// [iostream] [memory] [utility] [algorithm] [functional] [string] [vector] [unordered_map] [unordered_set] and [Hedron/Log.h]
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Hedron/Log.h"


	// Preprocessor check for Windows platforms.
#ifdef HDE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
