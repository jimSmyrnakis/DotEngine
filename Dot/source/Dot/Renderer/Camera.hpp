#pragma once

#include <glm/ext.hpp>
#include <glm/glm.hpp> // vec3, vec4, ivec4, mat4
#include <glm/gtc/matrix_transform.hpp> // translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp> // value_ptr

namespace dot{



    struct Camera {
        enum class CameraType{
            NONE , ORTHOGRAPHIC , PERSPECTIVE 
        };
        public:
            virtual CameraType GetType(void) 			const;
            virtual glm::mat4 GetProjectionMatrix(void) 	const = 0;
            virtual glm::mat4 GetViewMatrix(void) 		const = 0;
            virtual glm::mat4 GetProjectionViewMatrix(void) 	const = 0;
            virtual glm::mat4 GetViewProjectionMatrix(void)     const = 0;

    };

    struct PerspectiveCamera : public Camera {
        public:
            PerspectiveCamera(void);
            ~PerspectiveCamera(void);

            virtual CameraType GetType(void)                   const override;
            virtual glm::mat4 GetProjectionMatrix(void)        const override;
            virtual glm::mat4 GetViewMatrix(void)              const override;
            virtual glm::mat4 GetProjectionViewMatrix(void)    const override;
            virtual glm::mat4 GetViewProjectionMatrix(void)    const override;
        public:
            glm::vec3 m_Position	;
            glm::vec2 m_Rotation	; // (ThetaX , ThetaY )
            float     m_Fov     	; // (FovX , FovY)
            float     m_Znear   	; // from what depth i start see the 3D word
            float     m_Zfar    	; // from what depth i stop see the 3D word
            float     m_AspectRatio	; // NDC space represented as a cube , so i need to retain a cube like form

    };

    struct OrthographicCamera : public Camera {
        public:
            OrthographicCamera(void);
            ~OrthographicCamera(void);

            virtual CameraType GetType(void) 			    const override;
            virtual glm::mat4 GetProjectionMatrix(void) 	const override;
            virtual glm::mat4 GetViewMatrix(void) 		    const override;
            virtual glm::mat4 GetProjectionViewMatrix(void) const override;
            virtual glm::mat4 GetViewProjectionMatrix(void) const override;
        public:
            glm::vec2 m_Position; // (x,y) coordinates
            float     m_Rotation; // (ThetaZ)
            float     m_Top     ;
            float     m_Bottom  ;
            float     m_Left    ;
            float     m_Right   ;
            float     m_Znear   ;
            float     m_Zfar    ;
            
            
    };
}
