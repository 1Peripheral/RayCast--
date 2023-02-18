#include "Game.h"
#include "Settings.h"

int main(void)
{
   Game game{SCREEN_WIDTH, SCREEN_HEIGHT, FPS, "Testing hehe"};

   while(!game.GameShouldClose())
   {
      game.Tick();
   }

   return 1;
}