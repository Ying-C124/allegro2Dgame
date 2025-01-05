#ifndef _DEFINE_H_
#define _DEFINE_H_

//This Header file is for DEFINE ALL GLOBAL VALUE

//menu用ID
#define EXIT_ID 1223
#define CHANGE_RESOLUTION 1224
#define SPAWN 1225
#define BACK_TO_MENU 1226
#define SAVE_SCORE 1227
#define READ_SCORE_BOARD 1228

//menu用特殊解析度選項
#define VGA 1001
#define SVGA 1002
#define XGA 1003
#define HD 1004
#define FHD 1005
#define DUAL 1006
#define QUAD 1007

//menu LEVEL
#define LEVEL1 2331
#define LEVEL2 2332
#define LEVEL3 2333

// Define constants
// #define NUM_GROUNDS 20
// #define NUM_OBJECTS 9
// #define NUM_MONSTERS 20
// #define NUM_TEXTS 8
#define NUM_WORLDS 3
//世界的邊緣，可能需要程式嫁接
#define WORLD_WIDTH 100500
#define WORLD_HEIGHT -3000
#define WORLD_LOWEST 1500
#define cameraMoveMulti 1    //(double)
#define cameraMoveRange 30
#define ATTACK_RANGE 150
#define ATTACK_ANIME_TIME 5
#define ATTACK_PER_LV 5
// #define ALLOW_STEP_RANGE 2

#define SCORE_FILE "scores.txt"
#define TOP_N 5

#endif 