#pragma once
namespace connected
{
#if defined(_WIN32) || defined(_WIN64)
    #define WINDOWS 1
#elif defined(__linux__)
    #define LINUX 1
#endif

#if defined(WINDOWS)
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")
#endif
}
