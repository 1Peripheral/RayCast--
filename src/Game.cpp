#include <assert.h>
#include "Game.h"

Game::Game(int width, int height, int fps, const char* title) 
   :  map(MAP, CELLSIZE, MAPX, MAPY),
      player(Vec2<float>{MAPX * CELLSIZE / 2, MAPY * CELLSIZE / 2}, MAP)
{
   assert(!GetWindowHandle());  //If assertion triggers ->  window is already opened;
   InitWindow(width, height, title);
   SetTargetFPS(fps);
   SetExitKey(0); 
   this->overlay = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
}

Game::~Game() noexcept
{
   assert(GetWindowHandle()); // If assertion triggers -> window is already closed;
   UnloadRenderTexture(overlay);
   CloseWindow();
}

bool Game::GameShouldClose() const
{
   return WindowShouldClose();
}

void Game::pauseFilter()
{
   BeginTextureMode(overlay);
      ClearBackground({10, 10, 10, 200});
   EndTextureMode();
}

void Game::Tick() 
{
   frameCount++;

   if(IsKeyPressed(KEY_ESCAPE))
      isPaused = !isPaused;

   if(IsKeyPressed(KEY_M))
   {
      showMap = !showMap;
      player.showRay = showMap;
   }
   if(!isPaused) 
   {
      this->Update();
   }
   
   BeginDrawing();
      this->Draw();
   EndDrawing();
}

void Game::Update()
{
   player.moveAndCollide();
}

void Game::Draw()
{ 
   ClearBackground({20, 20, 20, 150});

   DrawRectangleV({0, 0}, {SCREEN_WIDTH, SCREEN_HEIGHT/2}, Color{83, 127, 231, 255});
   DrawRectangleV({0, SCREEN_HEIGHT / 2}, {SCREEN_WIDTH, SCREEN_HEIGHT/2}, Color{24, 24, 35, 255});

   player.castRays(RAYS_CASTED);

   if(showMap) 
   {
      map.draw();
      player.draw();
   }

   // Printing Informations:
   DrawFPS(10, SCREEN_HEIGHT-30);
   DrawText(TextFormat("Angle    : %.2f   ", player.angle * 180 / PI), 10, SCREEN_HEIGHT-60, 20, COLOR_GREEN);
   DrawText(TextFormat("Position : (%.2f, %.2f)   ", player.position.x, player.position.y), 10, SCREEN_HEIGHT-80, 20, COLOR_GREEN);
   DrawText(TextFormat("Fov      : %d   ", FOV), 10, SCREEN_HEIGHT-100, 20, COLOR_GREEN);

   if(isPaused){
      DrawTexture(overlay.texture, 0, 0, RAYWHITE);
      this->pauseFilter();
      DrawText( "Game Paused !", 
               SCREEN_WIDTH / 2 - MeasureText("Game Paused !", 40) / 2,
               SCREEN_HEIGHT / 10, 40, {200, 200, 200, 255});
   }
}
