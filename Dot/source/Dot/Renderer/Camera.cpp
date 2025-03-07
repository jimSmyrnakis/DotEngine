#include "Camera.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
namespace dot{

    Camera::CameraType Camera::GetType(void)                const { return Camera::CameraType::NONE; }
    Camera::CameraType PerspectiveCamera::GetType(void)     const { return Camera::CameraType::PERSPECTIVE; }
    Camera::CameraType OrthographicCamera::GetType(void)    const { return Camera::CameraType::ORTHOGRAPHIC; }
    
    // Perspective Camera
    PerspectiveCamera::PerspectiveCamera(void) 
    :   m_Position(0.0f , 0.0f , 1.0f) , m_Rotation(0.0f , 0.0f) , m_Fov(65.0f) , m_AspectRatio(1.0f) , m_Zfar(10.0f) , m_Znear(0.1f) { }
    PerspectiveCamera::~PerspectiveCamera(void) {}
    
    glm::mat4 PerspectiveCamera::GetProjectionMatrix(void)        const{
        return glm::perspective(glm::radians(m_Fov) , m_AspectRatio , m_Znear , m_Zfar);
    }
    
    glm::mat4 PerspectiveCamera::GetViewMatrix(void)              const{
        glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), - glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), - glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::vec3 pos = m_Position;
        pos.z *= (-1);
        pos.x *= (-1);
        pos.y *= (-1);
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), pos);
        //return glm::mat4(1.0f);
        return    rotationX * rotationY * translation;
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
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(m_Position, 0.0f));

        // Περιστροφή της κάμερας γύρω από τον άξονα Z
        transform = glm::rotate(transform, glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));

        return glm::inverse(transform);
    }

    glm::mat4 OrthographicCamera::GetProjectionViewMatrix(void)    const{
        return GetProjectionMatrix() * GetViewMatrix();
    }
    glm::mat4 OrthographicCamera::GetViewProjectionMatrix(void)    const {
        return GetViewMatrix()* GetProjectionMatrix();
    }
    

















    

    FirstPersonCamera::FirstPersonCamera(const glm::vec3& up , const glm::vec3& eye , const glm::vec3& targetPosition  ){
        m_Up = up;
        m_Position = eye;
        m_View = (1.0f/ targetPosition.length()) * targetPosition;//
        SetProjection(0.1f,100.0f,1.0f,60.0f);
        m_Update = true;
    }
    FirstPersonCamera::~FirstPersonCamera(void) {}

    FirstPersonCamera::CameraType  FirstPersonCamera::GetType(void) const { return FirstPersonCamera::CameraType::FIRST_PERSON; }
    glm::mat4   FirstPersonCamera::GetProjectionMatrix(void) 	    const { return m_ProjectionMatrix; }
    glm::mat4   FirstPersonCamera::GetViewMatrix(void) 		        const { 
        if (m_Update){
            m_Update = false;
            CaculateViewMatrix();
        }
        return m_ViewMatrix;       
    }
    glm::mat4   FirstPersonCamera::GetProjectionViewMatrix(void)    const { return GetProjectionMatrix() * GetViewMatrix();}
    glm::mat4   FirstPersonCamera::GetViewProjectionMatrix(void)    const { return GetViewMatrix() * GetProjectionMatrix();}

    void FirstPersonCamera::SetProjection(float znear , float zfar , float aspectRatio , float fovDegrees ){
        m_Far = zfar;
        m_Near = znear;
        m_Fov = fovDegrees;
        m_Aspect = aspectRatio;
        CaculateProjMatrix();
    }
            
    float FirstPersonCamera::GetZFar(void) const { return m_Far; }
    float FirstPersonCamera::GetZNear(void) const{ return m_Near; }
    float FirstPersonCamera::GetAspectRation(void) const { return m_Aspect; }
    float FirstPersonCamera::GetFov(void) const { return m_Fov; }

    void FirstPersonCamera::SetPosition(const glm::vec3& eyePosition){
        m_Position = eyePosition;
        m_Update = true;
    }
    
    void FirstPersonCamera::MoveFront(float step) {
        m_Position +=  m_View*step;
        m_Update = true;
    }
    void FirstPersonCamera::MoveBack (float step){
        m_Position -=  m_View*step;
        m_Update = true;
    }
    void FirstPersonCamera::MoveUp   (float step){
        m_Position += m_Up*step;
        m_Update = true;
    }
    void FirstPersonCamera::MoveDown (float step){
        m_Position -= m_Up*step;
        m_Update = true;
    }
    void FirstPersonCamera::MoveLeft (float step){
        m_Position += step*glm::cross(m_Up , m_View);
        m_Update = true;
    }
    void FirstPersonCamera::MoveRight(float step){
        m_Position += step*glm::cross( m_View , m_Up);
        m_Update = true;
    }

    void FirstPersonCamera::RotateRight(float stepDegrees){
        m_View = glm::rotate(m_View , -glm::radians(stepDegrees) , m_Up);
        m_Update = true;
    }
    void FirstPersonCamera::RotateLeft (float stepDegrees){
        m_View = glm::rotate(m_View , glm::radians(stepDegrees) , m_Up);
        m_Update = true;
    }
    void FirstPersonCamera::RotateUp   (float stepDegrees){
        glm::vec3 right = glm::cross(m_View , m_Up);
        m_Up = glm::rotate(m_Up , glm::radians(stepDegrees) , right );
        m_View = glm::cross(m_Up , right);
        m_Update = true;
    }
    void FirstPersonCamera::RotateDown (float stepDegrees){
        glm::vec3 right = glm::cross(m_View , m_Up);
        m_Up = glm::rotate(m_Up , glm::radians(-stepDegrees) , right );
        m_View = glm::cross(m_Up , right);
        m_Update = true;
    }

    void FirstPersonCamera::CaculateViewMatrix(void) const {
        m_ViewMatrix = glm::lookAt(m_Position , m_Position + m_View, m_Up);
    }
    void FirstPersonCamera::CaculateProjMatrix(void){
        m_ProjectionMatrix = glm::perspective(glm::radians( m_Fov ) , m_Aspect , m_Near , m_Far );
    }

}
