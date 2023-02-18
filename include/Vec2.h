#pragma once
#include <raylib.h>
#include <cmath>

template <typename T>
class Vec2 
{
public:
   Vec2() = default;
   constexpr Vec2(T x, T y) : x(x), y(y)
   {}
   
   constexpr T GetX() const { return x; }
   constexpr T GetY() const { return y; }

   constexpr T SetX(T x_in) { x = x_in; }  
   constexpr T SetY(T y_in) { y = y_in; }   
   
   // Operator Overloading
   constexpr Vec2 operator+(const Vec2& right) const 
   {
      return {x + right.x, y + right.y};
   }
   constexpr Vec2 operator+(const int right) const 
   {
      return {x + right, y + right};
   }
   constexpr Vec2& operator+=(const Vec2& right) 
   {
      return *this = *this + right;
   }

   constexpr Vec2 operator-(const Vec2& right) const 
   {
      return {x - right.x, y - right.y};
   }
   constexpr Vec2 operator-(const int right) const 
   {
      return {x - right, y - right};
   }
   constexpr Vec2& operator-=(const Vec2& right) 
   {
      return *this = *this - right;
   }

   constexpr Vec2 operator*(const Vec2& right) const 
   {
      return {x * right.x, y * right.y};
   }
   constexpr Vec2 operator*(const int right) const 
   {
      return {x * right, y * right};
   }
   constexpr Vec2& operator*=(const Vec2& right) 
   {
      return *this = *this * right;
   }
 constexpr bool operator==(const Vec2& right) const 
   {
      return (x == right. x && y = right.y);
   }
   constexpr bool operator!=(const Vec2& right) const
   {
      return !(*this == right);
   }
   constexpr Vector2 toRlVec()
   {
      return (Vector2){(float)x, (float)y};
   }
   constexpr Vec2 normalized()
   {
      T dist = sqrtf(x*x + y*y);
      if(dist == 0 ) dist = 1;

      return  Vec2{x/dist, y/dist}; 
   }

public:
   T x;
   T y;
};