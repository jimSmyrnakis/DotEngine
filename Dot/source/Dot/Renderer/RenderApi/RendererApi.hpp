#pragma once
#include "../../Core.hpp"
#include "Buffer.hpp"
#include "../MeshSettings.hpp"
#include <glm/glm.hpp>

namespace dot{
    

    class RendererApi{
        public:
            enum class Api{
                NONE = 0 , OPENGL = 1
            };
        public:
            static Api         GetCurrentApi(void);
            static void        SetCurrentApi(const Api graphicsApi);
        public:
            virtual void SetClearColor(const glm::vec4& color) = 0;
            virtual void Clear(void) = 0;
            virtual void DrawIndexed(const VertexArray& va , MeshSettings settings) = 0;
        private:
            static RendererApi::Api s_RendererApi;
    };
}