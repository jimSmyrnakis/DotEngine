#pragma once 

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace dot{

    inline float GetTime(void) { return (float)glfwGetTime();}

    class TimeStep{
        public:
        TimeStep(float time = 0.0f) : m_Time(time) {}
        ~TimeStep(void) = default;

        operator float() const { return m_Time;}

        inline float GetSeconds(void)   const { return m_Time; }
        inline float GetMills(void)     const { return m_Time * 1000.0f; } 

        private:
            float m_Time; // in second's
    };

}