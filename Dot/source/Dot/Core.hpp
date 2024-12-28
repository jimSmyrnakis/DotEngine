#pragma once

#include <stddef.h>
#include <stdint.h>
#include "Logger/Logger.hpp"

#define DEBUG_MODE

// This Game Engine is targeted for linux like O.S. only 
#define DOT_STATIC_LINK 
#if  defined(DOT_STATIC_LINK) 
    #define DOT_API 
#elif  defined(DOT_DYNAMIC_LINK)
    #error "No dynamic linking support yet "
#else 
    #error "Must define DOT_STATIC_LINK or DOT_DYNAMIC_LINK before include this file "
#endif


#define DOT_BIT_SET(x) (1 << (x))

#ifdef DEBUG_MODE

#define DOT_ENGINE_ASSERT(x , ...) if (!(x)) {DOT_ENGINE_ERROR(__VA_ARGS__); exit(1);} 
#define DOT_ASSERT(x , ...) if (!(x)) {DOT_ERROR(__VA_ARGS__); exit(1);}
#else

#define DOT_ENGINE_ASSERT(x , ...) x
#define DOT_ASSERT(x , ...) x

#endif

 
