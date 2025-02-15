#pragma once
#include <stdio.h>

#define DEBUG_MODE
#define PROC_X86

#ifdef PROC_X86
    #define __dot_break asm("int3")
#else 
    #define __dot_break exit(1)
#endif 

#ifdef DEBUG_MODE
    #define DOT_MATH_ASSERT(x , ...) if (!(x)) { fprintf(stderr , __VA_ARGS__); __dot_break; }
#else 
    #define DOT_MATH_ASSERT(x , ...) (x)
#endif 


