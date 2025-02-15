#pragma once 
#include "mat.hpp"


namespace dot{

    

    float Radians(float degrees);

    Matrix4f PerspectiveProjection(float fovx , float fovy , float aspect , float znear , float zfar);

    Matrix4f RotationX(float xTheta);
    Matrix4f RotationY(float yTheta);
    Matrix4f RotationZ(float zTheta);

    Matrix4f Translation(const Vector3f& vec);
    Matrix4f Scale(const Vector3f& scales);
    
    

}