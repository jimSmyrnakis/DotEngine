#include "mat.hpp"
#include "defs.hpp"


dot::Matrix4f::Matrix4f(float d ){
    for(int i = 0 ; i < 4 ; i++)
        for (int j = 0 ;j < 4 ; j++)
            if (i != j)
                m_mat[i][j] = 0.0f;
            else 
                m_mat[i][i] = d;
    
}

dot::Matrix4f::Matrix4f(float matrix[4][4]){
    for(int i = 0 ; i < 4 ; i++)
        for (int j = 0 ;j < 4 ; j++)
            m_mat[i][j] = matrix[i][j];
}

dot::Matrix4f::Matrix4f(dot::Vector4f vec[4]){
    for(int i = 0 ; i < 4 ; i++){
        m_mat[i][0] = vec[i].x;
        m_mat[i][1] = vec[i].y;
        m_mat[i][2] = vec[i].z;
        m_mat[i][3] = vec[i].w; 
    }
}

dot::Matrix4f& dot::Matrix4f::operator= (float d ){
    for(int i = 0 ; i < 4 ; i++)
        for (int j = 0 ;j < 4 ; j++)
            if (i != j)
                m_mat[i][j] = 0.0f;
            else 
                m_mat[i][i] = d;
    return (*this);
}

dot::Matrix4f& dot::Matrix4f::operator= (float matrix[4][4]){
    for(int i = 0 ; i < 4 ; i++)
        for (int j = 0 ;j < 4 ; j++)
            m_mat[i][j] = matrix[i][j];
    return (*this);
}

dot::Matrix4f& dot::Matrix4f::operator= (dot::Vector4f vec[4]){
    for(int i = 0 ; i < 4 ; i++){
        m_mat[i][0] = vec[i].x;
        m_mat[i][1] = vec[i].y;
        m_mat[i][2] = vec[i].z;
        m_mat[i][3] = vec[i].w; 
    }
    return (*this);
}

dot::Matrix4f dot::Matrix4f::operator*(const dot::Matrix4f& mat) const{
    Matrix4f Res(0.0f);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4 ; j++)
            for (int k = 0;k < 4 ; k++)
                Res.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
    return Res;
}

dot::Matrix4f dot::Matrix4f::operator*(const dot::Vector4f& vec) const{
    Matrix4f Res(0.0f);
    for (int i = 0; i < 4; i++){
        Res.m_mat[i][0] += m_mat[i][0] * vec.x;
        Res.m_mat[i][1] += m_mat[i][1] * vec.y;
        Res.m_mat[i][2] += m_mat[i][2] * vec.z;
        Res.m_mat[i][3] += m_mat[i][3] * vec.w;
    }

    return Res;
}

dot::Matrix4f& dot::Matrix4f::operator*=(const dot::Matrix4f& mat){
    return (*this) = (*this) * mat;
}

dot::Matrix4f& dot::Matrix4f::operator*=(const dot::Vector4f& vec){
    return (*this) = (*this) * vec;
}

float* dot::Matrix4f::operator[](uint32_t index) const{
    DOT_MATH_ASSERT(index < 4 , "Error: Matrix4f matrix index is Out Of Bounds !");

    return (float*)m_mat[index];
}

dot::Matrix4f dot::operator*(float a , const dot::Matrix4f& mat){
    dot::Matrix4f Res(mat);
    for (int i = 0; i < 4 ; i++)
        for(int j = 0; j < 4 ; j++)
            Res[i][j] *= a;
    return Res;
}


