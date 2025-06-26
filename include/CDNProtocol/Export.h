#pragma once

#ifdef _WIN32
#ifdef CDNPROTOCOL_LIBRARY
#define CDNPROTOCOL_EXPORT __declspec(dllexport)
#else
#define CDNPROTOCOL_EXPORT __declspec(dllimport)
#endif
#else
#define CDNPROTOCOL_EXPORT
#endif
