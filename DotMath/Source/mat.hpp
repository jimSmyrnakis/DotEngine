#pragma once
#include "vec.hpp"
#include <stdint.h>
#include <stddef.h>

namespace dot{
    
    class Matrix4f{

        public:

            Matrix4f(float d = 1.0f);
            Matrix4f(float matrix[4][4]);
            Matrix4f(Vector4f vec[4]);

            Matrix4f& operator= (float d );
            Matrix4f& operator= (float matrix[4][4]);
            Matrix4f& operator= (Vector4f vec[4]);

            Matrix4f operator*(const Matrix4f& mat) const;
            Matrix4f operator*(const Vector4f& vec) const;

            Matrix4f& operator*=(const Matrix4f& mat);
            Matrix4f& operator*=(const Vector4f& vec);

            float* operator[](uint32_t index) const;

            inline uint16_t rows(void) const { return 4; }
            inline uint16_t cols(void) const { return 4; }

        private:
            float m_mat[4][4];
    };

    Matrix4f operator*(float a , const Matrix4f& mat);

}