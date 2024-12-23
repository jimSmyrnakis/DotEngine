#pragma once

#include "Core.hpp"
#include <memory>

namespace dot{


    namespace Logger{

        void Init(void);
        void setEngineFatalToLogger(const char*);
        void setEngineErrorToLogger(const char*);
        void setEngineWarnToLogger(const char*);
        void setEngineInfoToLogger(const char*);
        void setEngineTraceToLogger(const char*);

        void setClientFatalToLogger(const char*);
        void setClientErrorToLogger(const char*);
        void setClientWarnToLogger(const char*);
        void setClientInfoToLogger(const char*);
        void setClientTraceToLogger(const char*);

    };
};

#define DOT_ENGINE_FATAL(x)     dot::Logger::setEngineFatalToLogger(x)
#define DOT_ENGINE_ERROR(x)     dot::Logger::setEngineErrorToLogger(x)
#define DOT_ENGINE_WARN(x)      dot::Logger::setEngineWarnToLogger(x)
#define DOT_ENGINE_INFO(x)      dot::Logger::setEngineInfoToLogger(x)
#define DOT_ENGINE_TRACE(x)     dot::Logger::setEngineTraceToLogger(x)

#define DOT_FATAL(x)            dot::Logger::setClientFatalToLogger(x)
#define DOT_ERROR(x)            dot::Logger::setClientErrorToLogger(x)
#define DOT_WARN(x)             dot::Logger::setClientWarnToLogger(x)
#define DOT_INFO(x)             dot::Logger::setClientInfoToLogger(x)
#define DOT_TRACE(x)            dot::Logger::setClientTraceToLogger(x)
