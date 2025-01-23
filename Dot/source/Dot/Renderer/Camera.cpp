#include "Camera.hpp"

namespace dot{

    Camera::CameraType Camera::GetType(void)                const { return Camera::CameraType::NONE; }
    Camera::CameraType PerspectiveCamera::GetType(void)     const { return Camera::CameraType::PERSPECTIVE; }
    Camera::CameraType OrthographicCamera::GetType(void)    const { return Camera::CameraType::ORTHOGRAPHIC; }
    
    // Perspective Camera
    PerspectiveCamera::PerspectiveCamera(void) 
    :   m_Position(0.0f , 0.0f , 1.0f) , m_Rotation(0.0f) , m_Fov(65.0f) , m_AspectRatio(1.0f) , m_Zfar(10.0f) , m_Znear(0.1f) { }
    PerspectiveCamera::~PerspectiveCamera(void) {}
    
    glm::mat4 PerspectiveCamera::GetProjectionMatrix(void)        const{
        //return glm::mat4(1.0f);
        return glm::perspective(glm::radians(m_Fov) , m_AspectRatio , m_Znear , m_Zfar);
    }
    
    glm::mat4 PerspectiveCamera::GetViewMatrix(void)              const{
        glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), -m_Position);
        //return glm::mat4(1.0f);
        return  rotationX * rotationY * translation;
    }
    
    glm::mat4 PerspectiveCamera::GetProjectionViewMatrix(void)    const{
        return GetProjectionMatrix() * GetViewMatrix();
    }
    glm::mat4 PerspectiveCamera::GetViewProjectionMatrix(void)    const {
        return GetViewMatrix()* GetProjectionMatrix();
    }
    

    // Orthographic Camera
    OrthographicCamera::OrthographicCamera(void)
    :   m_Position(0.0f) ,
        m_Rotation(0.0f) , 
        m_Top(100.0f)     ,
        m_Bottom(0.0f)  ,
        m_Left(100.0f)    ,
        m_Right(0.0f)          {}
    OrthographicCamera::~OrthographicCamera(void){}

    glm::mat4 OrthographicCamera::GetProjectionMatrix(void) 	const{
        return glm::ortho(m_Left , m_Right , m_Bottom , m_Top);
    }
    glm::mat4 OrthographicCamera::GetViewMatrix(void) 		    const{
        // Δημιουργία ενός αρχικού πίνακα ταυτότητας
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(-m_Position, 0.0f));

        // Περιστροφή της κάμερας γύρω από τον άξονα Z
        transform = glm::rotate(transform, glm::radians(-m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));

        return transform;//glm::inverse(transform);
    }

    glm::mat4 OrthographicCamera::GetProjectionViewMatrix(void)    const{
        return GetProjectionMatrix() * GetViewMatrix();
    }
    glm::mat4 OrthographicCamera::GetViewProjectionMatrix(void)    const {
        return GetViewMatrix()* GetProjectionMatrix();
    }
    

}
