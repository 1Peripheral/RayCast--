#pragma once
#include <raylib.h>
#include <Vec2.h>
#include <Settings.h>
class Player
{
public:
   Player() = default;
   Player(Vec2<float> pos, const bool* _map);

   void moveAndCollide();
   void draw();
   Vector2 lookingAt();

   void castRays(int nbrRays);

public:
   Vec2<float> position;
   Vec2<float> velocity;
   float angle = PI;
   int fov = FOV;
   Color color;
   bool showRay = false;
   const bool* map;
};