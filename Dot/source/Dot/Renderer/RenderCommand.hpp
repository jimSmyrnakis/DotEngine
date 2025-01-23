#pragma once
#include "RenderApi/RendererApi.hpp"

namespace dot{

    class RenderCommand{

        public:
            static void DrawIndexed(VertexArray& va);
            static void ClearColor(const glm::vec4& color);
            static void Clear(void);

        public:
            static RendererApi* s_RendererApi;
    };

}