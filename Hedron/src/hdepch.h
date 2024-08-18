
// Precompile header.

#pragma once

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

// Preprocessor check for Windows platforms.
#ifdef HDE_PLATFORM_WINDOWS
	#include <WaaSApi.h>
#endif
