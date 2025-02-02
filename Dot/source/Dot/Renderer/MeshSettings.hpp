#pragma once 

namespace dot {
    struct Binding{
        enum class Face{
            COUNTER_CLOCK_WISE , CLOCK_WISE 
        };
        bool Enable;
        Face FrontFace;
        
    };

    struct Primitive{
        
        enum class Primitives{
            TRIANGLES , LINES , POINTS
        };

        enum class Drawing{
            FILL , LINES , POINTS 
        };

        Primitives Type;
        Drawing    Draw;

    };

    struct Blending{
        enum class Func{
            CLASSIC 
        };

        bool Enable;
        Func Function;
    };

    struct MeshSettings{
        Binding   binding;
        Primitive primitive;
        Blending  blending;

        MeshSettings(void) {
            binding.Enable = true;
            binding.FrontFace = Binding::Face::COUNTER_CLOCK_WISE;
            primitive.Type = Primitive::Primitives::TRIANGLES;
            primitive.Draw = Primitive::Drawing::FILL;
        }
        
    };
}