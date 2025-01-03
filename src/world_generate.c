#include "myheader.h"

//Setting World right there.

//Initialize the game objects 
Ground create_ground(double x, double y, double width, double height, ALLEGRO_COLOR color) {
    Ground ground = {x, y, width, height, color};
    return ground;
}

void createWorld(mkworld world[],int worldNum,MKBitmap *inputBitmaps,MKSample *inputSamples){
    int i=0;
    world->inputBitmaps = inputBitmaps;
    //world_1
    i=0;
    world[i].groundNum = 10;
    world[i].groundAddress = malloc(sizeof(Ground)*world[i].groundNum);
    createGround1(world[i].groundAddress);
    world[i].objectNum = 9;
    world[i].objectAddress = malloc(sizeof(Object)*world[i].objectNum);
    createObject1(world[i].objectAddress,inputBitmaps,inputSamples);
    world[i].monsterNum = 2;
    world[i].monsterAddress = malloc(sizeof(Monster)*world[i].monsterNum);
    createMonster1(world[i].monsterAddress,inputBitmaps);
   
    //world_2
    i=1;
    world[i].groundNum = 1;
    world[i].groundAddress = malloc(sizeof(Ground)*world[i].groundNum);
    createGround2(world[i].groundAddress);
    world[i].objectNum = 2;
    world[i].objectAddress = malloc(sizeof(Object)*world[i].objectNum);
    createObject2(world[i].objectAddress,inputBitmaps,inputSamples);
    world[i].monsterNum = 2;
    world[i].monsterAddress = malloc(sizeof(Monster)*world[i].monsterNum);
    createMonster2(world[i].monsterAddress,inputBitmaps);

    //world_3
    i=2;
    world[i].groundNum = 1;
    world[i].groundAddress = malloc(sizeof(Ground)*world[i].groundNum);
    createGround3(world[i].groundAddress);
    world[i].objectNum = 2;
    world[i].objectAddress = malloc(sizeof(Object)*world[i].objectNum);
    createObject3(world[i].objectAddress,inputBitmaps,inputSamples);
    world[i].monsterNum = 2;
    world[i].monsterAddress = malloc(sizeof(Monster)*world[i].monsterNum);
    createMonster3(world[i].monsterAddress,inputBitmaps);


}

void createGround1(Ground *inputGroundAddress){
    inputGroundAddress[0]=create_ground(0, 500, 900, 300, al_map_rgb(139, 69, 19));
    inputGroundAddress[1]=create_ground(900, 600, 200, 200, al_map_rgb(139, 69, 19));
    inputGroundAddress[2]=create_ground(1100, 500, 500, 300, al_map_rgb(139, 69, 19));
    inputGroundAddress[3]=create_ground(1800, 500, 500, 300, al_map_rgb(139, 69, 19));
    inputGroundAddress[4]=create_ground(2550, 500, 1500, 300, al_map_rgb(139, 69, 19));
    inputGroundAddress[5]=create_ground(4150, 350, 100, 100, al_map_rgb(139, 69, 19));
    inputGroundAddress[6]=create_ground(4350, 350, 100, 100, al_map_rgb(139, 69, 19));
    inputGroundAddress[7]=create_ground(4550, 350, 100, 100, al_map_rgb(139, 69, 19));
    inputGroundAddress[8]=create_ground(4750, 500, 300, 300, al_map_rgb(139, 69, 19));
    inputGroundAddress[9]=create_ground(5150, 430, 400, 400, al_map_rgb(139, 69, 19));
}
void createObject1(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples){
    inputObjectAddress[0]=create_object(1400, 450, 35, 50, inputBitmaps->checkpoint_image, 1, false, true, true, NULL,inputSamples->check);
    inputObjectAddress[1]=create_object(2900, 450, 35, 50, inputBitmaps->checkpoint_image, 1, false, true, true, NULL,inputSamples->check);
    inputObjectAddress[2]=create_object(4850, 450, 35, 50, inputBitmaps->checkpoint_image, 1, false, true, true, NULL,inputSamples->check);
    inputObjectAddress[3]=create_object(750, 450, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[4]=create_object(987, 550, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[5]=create_object(2400, 300, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[6]=create_object(4187, 300, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[7]=create_object(4387, 300, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[8]=create_object(4587, 300, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
}
void createMonster1(Monster *inputMonsterAddress,MKBitmap *inputBitmaps){
    inputMonsterAddress[0] = create_monster(3100, 450, 35, 50, 2, inputBitmaps->monster_image1, 1, 1, 0, false, true, 20);
    inputMonsterAddress[1] = create_monster(5200, 380, 35, 50, 10, inputBitmaps->monster_image1, 1, 1, 0, false, true, 20);
}

void createGround2(Ground *inputGroundAddress){
    inputGroundAddress[0]=create_ground(0, 500, 900, 300, al_map_rgb(139, 69, 19));
}
void createObject2(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples){
    inputObjectAddress[0]=create_object(1400, 450, 35, 50, inputBitmaps->checkpoint_image, 1, false, true, true, NULL,inputSamples->check);
}
void createMonster2(Monster *inputMonsterAddress,MKBitmap *inputBitmaps){
    inputMonsterAddress[0] = create_monster(3100, 450, 35, 50, 2, inputBitmaps->monster_image1, 1, 1, 0, false, true, 20);
}

void createGround3(Ground *inputGroundAddress){
    inputGroundAddress[0]=create_ground(0, 500, 900, 300, al_map_rgb(139, 69, 19));
}
void createObject3(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples){
    inputObjectAddress[0]=create_object(1400, 450, 35, 50, inputBitmaps->checkpoint_image, 1, false, true, true, NULL,inputSamples->check);
}
void createMonster3(Monster *inputMonsterAddress,MKBitmap *inputBitmaps){
    inputMonsterAddress[0] = create_monster(3100, 450, 35, 50, 2, inputBitmaps->monster_image1, 1, 1, 0, false, true, 20);
}