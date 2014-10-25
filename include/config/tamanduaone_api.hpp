#ifndef CONFIG_TAMANDUAONE_API_HPP
#define CONFIG_TAMANDUAONE_API_HPP

#undef TAMANDUAONE_API
#ifdef WIN32

// TAMANDUA_DLL_BUILD must be defined when you are compiling TamanduaOne library on Win32
#ifdef TAMANDUAONE_DLL_BUILD
#define TAMANDUAONE_API __declspec(dllexport)
#endif

// TAMANDUAONE_DLL must be defined when you are linking TamanduaOne library on Win32
#ifdef TAMANDUAONE_DLL
#define TAMANDUAONE_API __declspec(dllimport)
#endif

#endif

#endif
