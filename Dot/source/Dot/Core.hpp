#pragma once

// This Game Engine is targeted for linux like O.S. only 
#define DOT_STATIC_LINK 
#if  defined(DOT_STATIC_LINK) 
    #define DOT_API 
#elif  defined(DOT_DYNAMIC_LINK)
    #error "No dynamic linking support yet "
#else 
    #error "Must define DOT_STATIC_LINK or DOT_DYNAMIC_LINK before include this file "
#endif

