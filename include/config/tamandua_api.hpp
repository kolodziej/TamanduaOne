#ifndef CONFIG_TAMANDUA_API_HPP
#define CONFIG_TAMANDUA_API_HPP

#undef TAMANDUA_API
#ifdef WIN32

// TAMANDUA_DLL_BUILD must be defined when you are compiling TamanduaOne library on Win32
#ifdef TAMANDUA_DLL_BUILD
#define TAMANDUA_API __declspec(dllexport)
#endif

// TAMANDUA_DLL must be defined when you are linking TamanduaOne library on Win32
#ifdef TAMANDUA_DLL
#define TAMANDUA_API __declspec(dllimport)
#endif

#endif

#ifndef TAMANDUA_API
#define TAMANDUA_API
#endif

#endif
