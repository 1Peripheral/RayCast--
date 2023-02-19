#include "Player.h"

Player::Player(Vec2<float> pos, const bool* _map)
{
   this->position = pos;
   this->color    = GREEN;
   this->map      = _map;
   this->velocity = Vec2<float>{cosf(angle) , sinf(angle) };
}

void Player::moveAndCollide()
{
   int xOff = 0;
   int yOff = 0; 

   // Add x and y offset depending on the direction of the player
   if (velocity.x < 0)  xOff = -15;
   else                 xOff = 15;

   if (velocity.y < 0)  yOff = -15;
   else                 yOff = 15;

   // Position of the player relative to the nubmer of cells;
   int iX = (position.x) / CELLSIZE;
   int iY = (position.y) / CELLSIZE;

   // Add the offset to the player's position
   int iXOffAdd = (position.x + xOff) / CELLSIZE;
   int iYOffAdd = (position.y + yOff) / CELLSIZE;

   int iXOffSub = (position.x - xOff) / CELLSIZE;
   int iYOffSub = (position.y - yOff) / CELLSIZE;


   if(IsKeyDown(KEY_W)) 
   {  
      if(map[iY * MAPY + iXOffAdd] == 0) 
         position.x += velocity.x * SPEED * GetFrameTime();
      if(map[iYOffAdd * MAPY + iX] == 0) 
         position.y += velocity.y * SPEED * GetFrameTime();
   }
   if(IsKeyDown(KEY_S)) 
   {
      if(map[iY * MAPY + iXOffSub] == 0)
         position.x -= velocity.x * SPEED * GetFrameTime();
         
      if(map[iYOffSub * MAPY + iX] == 0) 
         position.y -= velocity.y * SPEED * GetFrameTime();   
   }
   if(IsKeyDown(KEY_A))
   {
      if(angle < 0)  angle += 2 * PI;

      angle -= ANGLE_VEL * GetFrameTime();
      velocity.x = cosf(angle) ;
      velocity.y = sinf(angle) ;
   }
   if(IsKeyDown(KEY_D))
   {
      if(angle > 0)  angle -= 2 * PI;

      angle += ANGLE_VEL * GetFrameTime();
      velocity.x = cosf(angle) ;
      velocity.y = sinf(angle) ;
   }
}

void Player::draw() 
{
   DrawCircleV({position.x / 2, position.y / 2} , 10, color);
}

Vector2 Player::lookingAt()
{
   return  {position.x+velocity.x*20, position.y+velocity.y*20};
}

void Player::castRays(int nbrRays)
{
   int rayLength = RAY_LENGTH;
   float fovRad = fov * PI / 180;
   float scale = (float)RENDER_SCREEN_WIDTH / nbrRays;  // size of the projection of the rays (rectangles)

   float rayIncrement = fovRad / nbrRays;
   float rayAngle = angle - fovRad / 2;

   float x = 0; 
   float y = 0;

   Vector2 endPos = {x , y};

   for(int ray = 0 ; ray < nbrRays ; ++ray)
   {
      x = position.x + cosf(rayAngle) * rayLength;
      y = position.y + sinf(rayAngle) * rayLength;
      endPos = {x, y};

      // Checking if the ray touches a block
      for(int j = 0 ; j < rayLength ; ++j)
      {
         int dx = (int)(position.x + j  * cosf(rayAngle));
         int dy = (int)(position.y + j  * sinf(rayAngle));

         if(map[dy/CELLSIZE * MAPY + dx/CELLSIZE] == 1)
         {
            endPos.x = dx;
            endPos.y = dy;  
            break;
         }
      }
      float distance = sqrtf((position.x - endPos.x) * (position.x - endPos.x) + (position.y - endPos.y) * (position.y - endPos.y));
      // End Collision

      // Calculating line height in order to draw them as walls
      int shading       = 255 / (1 + distance * SHADING_STRENGTH);
      Color rayColor    = {shading, shading, shading, 255}; 

      // Fisheye  fix
      distance  *= cosf(angle - rayAngle);
      float lineHeight  = (CELLSIZE * SCREEN_HEIGHT / 2 ) / (distance);

      Vector2 startRec  = {ray * scale, (SCREEN_HEIGHT / 2) - lineHeight / 2};
      Vector2 endRec    = {scale, lineHeight};

      DrawRectangleV(startRec, endRec, rayColor);

      // Drawing the ray on the map
      if(showRay)    DrawLineV({position.x/2, position.y/2}, {endPos.x/2, endPos.y/2}, {150, 0, 0, 150});
      rayAngle += rayIncrement;
   }
}

