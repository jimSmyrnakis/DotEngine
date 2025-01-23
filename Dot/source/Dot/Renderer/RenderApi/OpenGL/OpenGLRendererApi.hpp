#pragma once
#include "../RendererApi.hpp"

namespace dot{
    class OpenGLRendererApi : public RendererApi{

        public:
            virtual void SetClearColor(const glm::vec4& color) override;
            virtual void Clear(void) override;
            virtual void DrawIndexed(const VertexArray& va) override;

    };
}