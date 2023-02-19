#pragma once
#include <raylib.h>
#include <Settings.h>


class Map
{
public:
   Map(const bool* map, int cellSize, int mapX, int mapY);

   void draw() const;
   
public:
   const bool* map;
   int width;
   int height;
   int cellSize;
   int mapX;
   int mapY;
};