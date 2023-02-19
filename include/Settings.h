#pragma once

#define SCREEN_WIDTH          900
#define SCREEN_HEIGHT         600
#define FPS                   60
#define NBR_CELLS             8
#define CELL_GAP              1


#define MAPX                  15//8
#define MAPY                  15//8
#define CELLSIZE              60


inline constexpr int  MAP_SCREEN_WIDTH     = MAPX * CELLSIZE;
inline constexpr int  MAP_SCREEN_HEIGHT    = MAPY * CELLSIZE;

inline constexpr int  RENDER_SCREEN_WIDTH  = SCREEN_WIDTH ;//- MAP_SCREEN_WIDTH;
inline constexpr int  RENDER_SCREEN_HEIGHT = SCREEN_HEIGHT ;//- MAP_SCREEN_HEIGHT;

inline constexpr Color COLOR_GREEN = {50, 150, 69, 255};

// Player Settings
#define ANGLE_VEL          3
#define SPEED              100

// Rays
#define RAY_LENGTH         600
#define SHADING_STRENGTH   0.02
#define FOV                80
#define RAYS_CASTED        900  


inline constexpr bool MAP[] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
