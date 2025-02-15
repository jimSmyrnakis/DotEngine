#include "vec.hpp"

//==============================================================================================
//======================================Vector2f================================================
//==============================================================================================

dot::Vector2f::Vector2f(float xy){
    x = y = xy;
}
            
dot::Vector2f dot::Vector2f::operator+(const dot::Vector2f& vec) const{
    dot::Vector2f vecRes;
    vecRes.x = x + vec.x;
    vecRes.y = y + vec.y;
    return vecRes;
}

dot::Vector2f dot::Vector2f::operator-(const dot::Vector2f& vec) const{
    dot::Vector2f vecRes;
    vecRes.x = x - vec.x;
    vecRes.y = y - vec.y;
    return vecRes;
}

dot::Vector2f dot::Vector2f::operator*(const dot::Vector2f& vec) const{
    dot::Vector2f vecRes;
    vecRes.x = x * vec.x;
    vecRes.y = y * vec.y;
    return vecRes;
}

dot::Vector2f dot::Vector2f::operator/(const dot::Vector2f& vec) const{
    dot::Vector2f vecRes;
    vecRes.x = x / vec.x;
    vecRes.y = y / vec.y;
    return vecRes;
}

dot::Vector2f& dot::Vector2f::operator+=(const dot::Vector2f& vec){
    return (*this) = (*this) + vec;
}

dot::Vector2f& dot::Vector2f::operator-=(const dot::Vector2f& vec){
    return (*this) = (*this) - vec;
}

dot::Vector2f& dot::Vector2f::operator*=(const dot::Vector2f& vec){
    return (*this) = (*this) * vec;
}

dot::Vector2f& dot::Vector2f::operator/=(const dot::Vector2f& vec){
    return (*this) = (*this) / vec;
}

bool dot::Vector2f::operator==(const dot::Vector2f& vec) const{
    return (x == vec.x) && (y == vec.y);
}

bool dot::Vector2f::operator!=(const dot::Vector2f& vec) const{
    return !((*this) == vec);
}


//==============================================================================================
//======================================Vector3f================================================
//==============================================================================================



dot::Vector3f::Vector3f(float xyz ){
    x = y = z = xyz;
}

dot::Vector3f::Vector3f(const Vector2f& vec , float z ){
    x = vec.x; y = vec.y; this->z = z;
}
            
dot::Vector3f dot::Vector3f::operator+(const dot::Vector3f& vec) const{
    dot::Vector3f v = vec;
    v.x += x;
    v.y += y;
    v.z += z;
    return v;
}

dot::Vector3f dot::Vector3f::operator-(const dot::Vector3f& vec) const{
    dot::Vector3f v = vec;
    v.x -= x;
    v.y -= y;
    v.z -= z;
    return v;
}

dot::Vector3f dot::Vector3f::operator*(const dot::Vector3f& vec) const{
    dot::Vector3f v = vec;
    v.x *= x;
    v.y *= y;
    v.z *= z;
    return v;
}

dot::Vector3f dot::Vector3f::operator/(const dot::Vector3f& vec) const{
    dot::Vector3f v = vec;
    v.x /= x;
    v.y /= y;
    v.z /= z;
    return v;
}

dot::Vector3f& dot::Vector3f::operator= (const dot::Vector2f& vec){
    x = vec.x;
    y = vec.y;
    z = 0.0f;
    return (*this);
}

dot::Vector3f& dot::Vector3f::operator+=(const dot::Vector3f& vec){
    return (*this) = (*this) + vec;
}

dot::Vector3f& dot::Vector3f::operator-=(const dot::Vector3f& vec){
    return (*this) = (*this) - vec;
}

dot::Vector3f& dot::Vector3f::operator*=(const dot::Vector3f& vec){
    return (*this) = (*this) * vec;
}

dot::Vector3f& dot::Vector3f::operator/=(const dot::Vector3f& vec){
    return (*this) = (*this) / vec;
}

bool dot::Vector3f::operator==(const dot::Vector3f& vec) const{
    return (x == vec.x) && (y == vec.y) && (z == vec.z);
}

bool dot::Vector3f::operator!=(const dot::Vector3f& vec) const{
    return !((*this) == vec);
}


//==============================================================================================
//======================================Vector4f================================================
//==============================================================================================



dot::Vector4f::Vector4f(float xyzw ){
    x = y = z = w = xyzw;
}

dot::Vector4f::Vector4f(const dot::Vector3f& vec , float w ){
    x = vec.x;
    y = vec.y;
    z = vec.z;
    this->w = w;
}
            
dot::Vector4f dot::Vector4f::operator+(const dot::Vector4f& vec) const{
    dot::Vector4f v = vec;
    v.x += x;
    v.y += y;
    v.z += z;
    v.w += w;
    return v;
}

dot::Vector4f dot::Vector4f::operator-(const dot::Vector4f& vec) const{
    dot::Vector4f v = vec;
    v.x -= x;
    v.y -= y;
    v.z -= z;
    v.w -= w;
    return v;
}

dot::Vector4f dot::Vector4f::operator*(const dot::Vector4f& vec) const{
    dot::Vector4f v = vec;
    v.x *= x;
    v.y *= y;
    v.z *= z;
    v.w *= w;
    return v;
}

dot::Vector4f dot::Vector4f::operator/(const dot::Vector4f& vec) const{
    dot::Vector4f v = vec;
    v.x /= x;
    v.y /= y;
    v.z /= z;
    v.w /= w;
    return v;
}


dot::Vector4f& dot::Vector4f::operator= (const dot::Vector3f& vec){
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = 0.0f;
    return (*this);
}

dot::Vector4f& dot::Vector4f::operator= (const dot::Vector2f& vec){
    x = vec.x;
    y = vec.y;
    z = 0.0f;
    w = 0.0f;
    return (*this);
}

dot::Vector4f& dot::Vector4f::operator+=(const dot::Vector4f& vec){
    return (*this) = (*this) + vec;
}

dot::Vector4f& dot::Vector4f::operator-=(const dot::Vector4f& vec){
    return (*this) = (*this) - vec;
}

dot::Vector4f& dot::Vector4f::operator*=(const dot::Vector4f& vec){
    return (*this) = (*this) * vec;
}

dot::Vector4f& dot::Vector4f::operator/=(const dot::Vector4f& vec){
    return (*this) = (*this) / vec;
}

bool dot::Vector4f::operator==(const dot::Vector4f& vec) const{
    return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
}
bool dot::Vector4f::operator!=(const dot::Vector4f& vec) const{
    return !((*this) == vec);
}



//==============================================================================================
//======================================Constant Operators======================================
//==============================================================================================

dot::Vector2f dot::operator*( float a , const dot::Vector2f& vec ){
    Vector2f Res = vec;
    Res.x *= a;
    Res.y *= a;
    return Res;
}

dot::Vector3f dot::operator*( float a , const dot::Vector3f& vec ){
    Vector3f Res = vec;
    Res.x *= a;
    Res.y *= a;
    Res.z *= a;
    return Res;
}

dot::Vector4f dot::operator*( float a , const dot::Vector4f& vec ){
    Vector4f Res = vec;
    Res.x *= a;
    Res.y *= a;
    Res.z *= a;
    Res.w *= a;
    return Res;
}

dot::Vector2f dot::operator*( const dot::Vector2f& vec , float a ){
    Vector2f Res = vec;
    Res.x *= a;
    Res.y *= a;
    return Res;
}

dot::Vector3f dot::operator*( const dot::Vector3f& vec , float a ){
    Vector3f Res = vec;
    Res.x *= a;
    Res.y *= a;
    Res.z *= a;
    return Res;
}

dot::Vector4f dot::operator*( const dot::Vector4f& vec , float a){
    Vector4f Res = vec;
    Res.x *= a;
    Res.y *= a;
    Res.z *= a;
    Res.w *= a;
    return Res;
}