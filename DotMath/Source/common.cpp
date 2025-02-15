#include "common.hpp"
#include <cmath>

float dot::Radians(float degrees){
    return M_PIf32x * degrees / 180.0f;
}

dot::Matrix4f dot::PerspectiveProjection(float fovx , float fovy , float aspect , float znear , float zfar){
    Matrix4f Res(1.0f);

    return Res;
}

dot::Matrix4f dot::RotationX(float xTheta){
    Matrix4f Res(1.0f);

    return Res;
}

dot::Matrix4f dot::RotationY(float yTheta){
    Matrix4f Res(1.0f);

    return Res;
}

dot::Matrix4f dot::RotationZ(float zTheta){
    Matrix4f Res(1.0f);

    return Res;
}


dot::Matrix4f dot::Translation(const dot::Vector3f& vec){
    float transl[4][4] = {
        {1.0f , 0.0f , 0.0f , vec.x} ,
        {0.0f , 1.0f , 0.0f , vec.y} ,
        {0.0f , 0.0f , 1.0f , vec.z} ,
        {0.0f , 0.0f , 0.0f , 1.0f}
    };

    return Matrix4f(transl);
}

dot::Matrix4f dot::Scale(const dot::Vector3f& scales){
    float scale[4][4] = {
        {scales.x , 0.0f , 0.0f , 0.0f} ,
        {0.0f , scales.y , 0.0f , 0.0f} ,
        {0.0f , 0.0f , scales.z , 0.0f} ,
        {0.0f , 0.0f , 0.0f , 1.0f}
    };

    return Matrix4f(scale);
}