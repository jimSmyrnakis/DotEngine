#pragma once
#include "RenderApi/RendererApi.hpp"
#include "Camera.hpp"
#include "Model.hpp"
#include "MeshSettings.hpp"

namespace dot{

    class Renderer{

        public:

            

        public:
            inline static RendererApi::Api GetApi(void) { return RendererApi::GetCurrentApi(); }

        public:
            static void BeginScene(const Camera* camera); // TODO
            static void EndScene(void);   // TODO
            static void Submit(VertexArray& va , MeshSettings settings = MeshSettings());
        private:
            static Camera* s_Camera;

    };

}