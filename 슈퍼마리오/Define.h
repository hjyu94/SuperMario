#pragma once

#define WINCX 800
#define WINCY 600

#define OBJ_ALIVE 0 
#define OBJ_DEAD 1
#define OBJ_COLLISION 2

#define PI 3.1415926874
#define GRAVITY 10

#define ToRadian(degree) degree*PI/180.f
#define ToDegree(rad) rad*180.f/PI

#define PLAYER_FCX 30
#define PLAYER_FCY 30


/// /// == 이창열추가
#define ITEM_MOVE_SIZE 50.f
#define TILE_BLOCK_FCX 50
#define TILE_BLOCK_FCY 50

#define PLANT_BLOCK_FCX 100
#define PLANT_BLOCK_FCY 160
#define FLOWER_MON_FCX 50
#define FLOWER_MON_FCY 50

#define BULLET_FCX 10
#define BULLET_FCY 10