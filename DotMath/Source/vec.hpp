#pragma once 

namespace dot{

    struct Vector2f{
        public:
            float x;
            float y;
        public:
            Vector2f(float xy=0.0f);
            
            Vector2f operator+(const Vector2f& vec) const;
            Vector2f operator-(const Vector2f& vec) const;
            Vector2f operator*(const Vector2f& vec) const;
            Vector2f operator/(const Vector2f& vec) const;

            Vector2f& operator+=(const Vector2f& vec);
            Vector2f& operator-=(const Vector2f& vec);
            Vector2f& operator*=(const Vector2f& vec);
            Vector2f& operator/=(const Vector2f& vec);

            bool operator==(const Vector2f& vec) const;
            bool operator!=(const Vector2f& vec) const;
    };

    struct Vector3f{
        public:
            float x;
            float y;
            float z;
        public:
            Vector3f(float xyz = 0.0f);
            Vector3f(const Vector2f& vec , float z = 0.0f);
            
            Vector3f operator+(const Vector3f& vec) const;
            Vector3f operator-(const Vector3f& vec) const;
            Vector3f operator*(const Vector3f& vec) const;
            Vector3f operator/(const Vector3f& vec) const;

            Vector3f& operator= (const Vector2f& vec);

            Vector3f& operator+=(const Vector3f& vec);
            Vector3f& operator-=(const Vector3f& vec);
            Vector3f& operator*=(const Vector3f& vec);
            Vector3f& operator/=(const Vector3f& vec);

            bool operator==(const Vector3f& vec) const;
            bool operator!=(const Vector3f& vec) const;
    };

    struct Vector4f{
        public:
            float x;
            float y;
            float z;
            float w;
        public:
            Vector4f(float xyzw = 0.0f);
            Vector4f(const Vector3f& vec , float w = 0.0f);
            
            Vector4f operator+(const Vector4f& vec) const;
            Vector4f operator-(const Vector4f& vec) const;
            Vector4f operator*(const Vector4f& vec) const;
            Vector4f operator/(const Vector4f& vec) const;

            Vector4f& operator= (const Vector3f& vec);
            Vector4f& operator= (const Vector2f& vec);

            Vector4f& operator+=(const Vector4f& vec);
            Vector4f& operator-=(const Vector4f& vec);
            Vector4f& operator*=(const Vector4f& vec);
            Vector4f& operator/=(const Vector4f& vec);

            bool operator==(const Vector4f& vec) const;
            bool operator!=(const Vector4f& vec) const;
    };

    
    Vector2f operator*( float a , const Vector2f& vec );
    Vector3f operator*( float a , const Vector3f& vec );
    Vector4f operator*( float a , const Vector4f& vec );

    Vector2f operator*( const Vector2f& vec  , float a );
    Vector3f operator*( const Vector3f& vec  , float a );
    Vector4f operator*( const Vector4f& vec  , float a );
}