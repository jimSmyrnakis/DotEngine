#pragma once
#include "RenderApi/RendererApi.hpp"
#include "Mesh.hpp"
#include "MeshSettings.hpp"

namespace dot{

    class RenderCommand{

        public:
            static void DrawIndexed(VertexArray& va , MeshSettings mesh);
            static void DrawMesh(Mesh& mesh );
            static void ClearColor(const glm::vec4& color);
            static void Clear(void);

        public:
            static RendererApi* s_RendererApi;
    };

}