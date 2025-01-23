#include "RendererApi.hpp"

dot::RendererApi::Api dot::RendererApi::s_RendererApi = dot::RendererApi::Api::OPENGL;

dot::RendererApi::Api dot::RendererApi::GetCurrentApi(void) { return s_RendererApi; }
void dot::RendererApi::SetCurrentApi(const dot::RendererApi::Api graphicsApi) { s_RendererApi = graphicsApi; }