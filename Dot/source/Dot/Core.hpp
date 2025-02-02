#pragma once
#include "Logger/Logger.hpp"

#define HARD_DEBUG_MODE
#define OS_LINUX_ELF64 
#define PROCESSOR_X86_64 
#define GNU_COMPILER 

#define DOT_API 

#ifdef GNU_COMPILER
    #define DOT_FILE        __FILE__ 
    #define DOT_LINE        __LINE__
    #define DOT_TIME        __TIME__  
#endif 

#if defined(GNU_COMPILER) && defined(PROCESSOR_X86_64)
    #if   defined(HARD_DEBUG_MODE)
        #define DOT_BREAKPOINT asm("int3")
    #elif defined(SOFT_DEBUG_MODE) || defined(SOFT_RELEASE_MODE)
        #define DOT_BREAKPOINT 
    #elif defined(HARD_RELEASE_MODE)
        #define DOT_BREAKPOINT exit(1)
    #elif defined(SOFT_RELEASE_MODE) || defined(DISTRIBUTION_MODE)
        #define DOT_BREAKPOINT 
    #endif 
#endif 


#if defined(HARD_DEBUG_MODE) || defined(SOFT_DEBUG_MODE) || defined(HARD_RELEASE_MODE) || defined(SOFT_RELEASE_MODE)
    #define DOT_ENGINE_ASSERT(x , ...)  if (!(x)) {DOT_ENGINE_ERROR("{ " __VA_ARGS__); DOT_BREAKPOINT;} 
    #define DOT_ASSERT(x , ...)         if (!(x)) {DOT_ERROR(__VA_ARGS__); DOT_BREAKPOINT;}
#else
    #define DOT_ENGINE_ASSERT(x , ...) (x)
    #define DOT_ASSERT(x , ...) (x)
#endif




#define DOT_BIT_SET(x) (1 << (x))

#define DOT_ENGINE_BIND_FN(T , x) std::bind(&T::x , this , std::placeholders::_1)

#define dotSize uint32_t

 
