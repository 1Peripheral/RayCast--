#pragma once
#include <raylib.h>
#include <Settings.h>
#include <Map.h>
#include <Player.h>
#include <Vec2.h>

class Game 
{
public:
    Game(int width, int height, int fps, const char* title);
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    ~Game() noexcept;

    bool GameShouldClose() const;

    void pauseFilter();

    void Tick();

private:
    void Draw();
    void Update();

private:
    RenderTexture2D overlay;
    int frameCount = 0;
    bool isPaused = false;
    bool showMap  = false;
    Map map;
    Player player;
}; 


