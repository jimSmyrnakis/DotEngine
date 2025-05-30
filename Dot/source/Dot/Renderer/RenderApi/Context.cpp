
#include "Context.hpp"

dot::Context::Context(WindowApiImpl impl ) : m_WinImpl(impl) {
    DOT_ENGINE_ASSERT(m_WinImpl != dot::WindowApiImpl::NONE , "Error : Window implementation is defined as dot::WindowApiImpl::NONE" );
}