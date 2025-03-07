#pragma once

#include <glm/ext.hpp>
#include <glm/glm.hpp> // vec3, vec4, ivec4, mat4
#include <glm/gtc/matrix_transform.hpp> // translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp> // value_ptr

namespace dot{



    struct Camera {
        enum class CameraType{
            NONE , ORTHOGRAPHIC , PERSPECTIVE , FIRST_PERSON
        };
        public:
            virtual CameraType GetType(void) 			    const;
            virtual glm::mat4 GetProjectionMatrix(void) 	const = 0;
            virtual glm::mat4 GetViewMatrix(void) 		    const = 0;
            virtual glm::mat4 GetProjectionViewMatrix(void) const = 0;
            virtual glm::mat4 GetViewProjectionMatrix(void) const = 0;

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

           /* void SetPosition(const glm::vec3& position) ;
            void SetRotation(float ThetaX , float ThetaY);
            void SetFov(float fov);
            void SetPlanes(float zNear , float zFar);
            void SetAspectRatio(float ratio);
            void SetAspectRatio(unsigned int width , unsigned int height);
            //void Set(const glm::vec3& position , )*/
        public:
            glm::vec3 m_Position	;
            glm::vec2 m_Rotation	; // (ThetaX , ThetaY )
            float     m_Fov     	; // (FovX , FovY)
            float     m_Znear   	; // from what depth i start see the 3D word
            float     m_Zfar    	; // from what depth i stop see the 3D word
            float     m_AspectRatio	; // NDC space represented as a cube , so i need to retain a cube like form
            glm::mat4 m_View        ; // The camera view matrix 
            glm::mat4 m_Projection  ; // The Projection Matrix
            glm::mat4 m_ProjView    ; // View
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

    class FirstPersonCamera : public Camera{
        public:
            FirstPersonCamera(
                const glm::vec3& up = glm::vec3(0.0f,1.0f,0.0f)     , 
                const glm::vec3& eye = glm::vec3(0.0f,0.0f,0.0f)    , 
                const glm::vec3& targetPosition = glm::vec3(0.0f, 0.0f, -1.0f));
            ~FirstPersonCamera(void);

            virtual CameraType  GetType(void) 			        const override;
            virtual glm::mat4   GetProjectionMatrix(void) 	    const override;
            virtual glm::mat4   GetViewMatrix(void) 		    const override;
            virtual glm::mat4   GetProjectionViewMatrix(void)   const override;
            virtual glm::mat4   GetViewProjectionMatrix(void)   const override;

            void SetProjection(float znear , float zfar , float aspectRatio , float fovDegrees );
            void SetPosition(const glm::vec3& eyePosition);

            float GetZFar(void) const;
            float GetZNear(void) const;
            float GetAspectRation(void) const;
            float GetFov(void) const; 

            void MoveFront(float step);
            void MoveBack (float step);
            void MoveUp   (float step);
            void MoveDown (float step);
            void MoveLeft (float step);
            void MoveRight(float step);

            void RotateRight(float stepDegrees);
            void RotateLeft (float stepDegrees);
            void RotateUp   (float stepDegrees);
            void RotateDown (float stepDegrees);

            void  CaculateViewMatrix(void) const ;
            void CaculateProjMatrix(void);

            //void SetZoomLevel(float zoomLevel); TODO in the future
        private:
            glm::vec3           m_Position;         // the position of the camera
            glm::vec3           m_Up;               // the up direction or axis ? 
            glm::vec3           m_View;             // view direction 
            mutable glm::mat4   m_ViewMatrix;       // the camera matrix 
            mutable glm::mat4   m_ProjectionMatrix; // the projection matrix
            float               m_Fov;              // fov of the furstom
            float               m_Aspect;           // Aspect Ratio
            float               m_Near;             // near plane
            float               m_Far;              // far  plane
            mutable bool        m_Update;           // is used to update the matrixe's as needed and when needed to avoid overdoing
            // the same caculation's over and over again
    };
}
