#include "Map.h"

Map::Map(const bool* _map, int _cellSize, int _mapX, int _mapY)
   : map(_map), cellSize(_cellSize / 2), mapX(_mapX), mapY(_mapY)
{
   // Deviding the cell size from the settings by two to rescale it for the minimap
   this->width = cellSize/2 * mapX ; 
   this->height= cellSize/2 * mapY ;
}

void Map::draw() const
{
   Color cellColor;
   // Drawing Mini Map

   for(int y = 0 ; y < mapY ; ++y)
      for(int x = 0 ; x < mapX ; ++x)
      {
         if(map[y * mapY + x]) cellColor = Color{255, 255, 255, 150};
         else                      cellColor = Color{40, 40, 40, 150};

         DrawRectangle(
            cellSize * x ,
            cellSize * y ,
            cellSize ,
            cellSize ,
            cellColor
         );
      }

}
