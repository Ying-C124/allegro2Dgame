#include "myheader.h"

//Setting World right there.

//Initialize the game objects 
Ground create_ground(double x, double y, double width, double height, ALLEGRO_COLOR color) {
    Ground ground = {x, y, width, height, color};
    return ground;
}

void createWorld(mkworld world[],int worldNum,MKBitmap *inputBitmaps,MKSample *inputSamples, ALLEGRO_FONT *font_16){
    int i=0;
    world->inputBitmaps = inputBitmaps;
    //world_1
    i=0;
    world[i].groundNum = 15;
    world[i].groundAddress = malloc(sizeof(Ground)*world[i].groundNum);
    createGround1(world[i].groundAddress);
    world[i].objectNum = 16;
    world[i].objectAddress = malloc(sizeof(Object)*world[i].objectNum);
    createObject1(world[i].objectAddress,inputBitmaps,inputSamples);
    world[i].monsterNum = 8;
    world[i].monsterAddress = malloc(sizeof(Monster)*world[i].monsterNum);
    createMonster1(world[i].monsterAddress,inputBitmaps);
    world[i].textNum = 13;
    world[i].textAddress = malloc(sizeof(Text)*world[i].textNum);
    createText1(world[i].textAddress,font_16);
   
    //world_2
    i=1;
    world[i].groundNum = 2;
    world[i].groundAddress = malloc(sizeof(Ground)*world[i].groundNum);
    createGround2(world[i].groundAddress);
    world[i].objectNum = 30;
    world[i].objectAddress = malloc(sizeof(Object)*world[i].objectNum);
    createObject2(world[i].objectAddress,inputBitmaps,inputSamples);
    world[i].monsterNum = 1;
    world[i].monsterAddress = malloc(sizeof(Monster)*world[i].monsterNum);
    createMonster2(world[i].monsterAddress,inputBitmaps);
    world[i].textNum = 1;
    world[i].textAddress = malloc(sizeof(Text)*world[i].textNum);
    createText2(world[i].textAddress,font_16);
    //world_3
    i=2;
    world[i].groundNum = 19;
    world[i].groundAddress = malloc(sizeof(Ground)*world[i].groundNum);
    createGround3(world[i].groundAddress);
    world[i].objectNum = 8;
    world[i].objectAddress = malloc(sizeof(Object)*world[i].objectNum);
    createObject3(world[i].objectAddress,inputBitmaps,inputSamples);
    world[i].monsterNum = 5;
    world[i].monsterAddress = malloc(sizeof(Monster)*world[i].monsterNum);
    createMonster3(world[i].monsterAddress,inputBitmaps);
    world[i].textNum = 4;
    world[i].textAddress = malloc(sizeof(Text)*world[i].textNum);
    createText3(world[i].textAddress,font_16);
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
    inputGroundAddress[10]=create_ground(5750, 430, 400, 400, al_map_rgb(139, 69, 19));
    inputGroundAddress[11]=create_ground(6300, 530, 400, 400, al_map_rgb(139, 69, 19));
    inputGroundAddress[12]=create_ground(6900, 400, 200, 400, al_map_rgb(139, 69, 19));
    inputGroundAddress[13]=create_ground(7300, 400, 200, 400, al_map_rgb(139, 69, 19));
    inputGroundAddress[14]=create_ground(7650, 550, 600, 400, al_map_rgb(139, 69, 19));
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
    inputObjectAddress[9]=create_object(6400, 300, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[10]=create_object(6500, 300, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[11]=create_object(6600, 300, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[12]=create_object(6400, 350, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[9],inputSamples->chest);
    inputObjectAddress[13]=create_object(6500, 350, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[10],inputSamples->chest);
    inputObjectAddress[14]=create_object(6600, 350, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[11],inputSamples->chest);
    inputObjectAddress[15]=create_object(8050, 450, 100, 100, inputBitmaps->end_image, 4, false, true, true, NULL,NULL);
}
void createMonster1(Monster *inputMonsterAddress,MKBitmap *inputBitmaps){
    inputMonsterAddress[0] = create_monster(3100, 450, 35, 50, 0, inputBitmaps->monster_image1, 1, 1, 0, false, true, 30);
    inputMonsterAddress[1] = create_monster(5200, 380, 35, 50, 4, inputBitmaps->monster_image1, 1, 1, 0, false, true, 20);
    inputMonsterAddress[2] = create_monster(3600, 450, 35, 50, 2, inputBitmaps->monster_image1, 1, 1, 0, false, true, 30);
    inputMonsterAddress[3] = create_monster(5607, 300, 85, 40, 2, inputBitmaps->monster_image2, 2, 1, 0, false, true, 30);
    inputMonsterAddress[4] = create_monster(6080, 380, 35, 50, 4, inputBitmaps->monster_image1, 1, -1, 0, false, true, 30);
    inputMonsterAddress[5] = create_monster(7157, 250, 85, 40, 2, inputBitmaps->monster_image2, 2, 1, 0, false, true, 30);
    inputMonsterAddress[6] = create_monster(3600, 450, 35, 50, 2, inputBitmaps->monster_image1, 1, 1, 0, false, true, 30);
    inputMonsterAddress[7] = create_monster(3600, 450, 35, 50, 2, inputBitmaps->monster_image1, 1, 1, 0, false, true, 30);
}
void createText1(Text *inputTextAddress ,ALLEGRO_FONT *font_16){
    inputTextAddress[0] = create_text(100,400,"Use arrow keys to move and jump",font_16);
    inputTextAddress[1] = create_text(700,400,"Pick up coin to get score",font_16);
    inputTextAddress[2] = create_text(1300,400,"Touch the flag to save checkpoint",font_16);
    inputTextAddress[3] = create_text(1640,570,"If you drop off",font_16);
    inputTextAddress[4] = create_text(1650,600,"the platform",font_16);
    inputTextAddress[5] = create_text(1640,630,"you will respawn",font_16);
    inputTextAddress[6] = create_text(1650,660,"at checkpoint",font_16);
    inputTextAddress[7] = create_text(2250,400,"Try to jump at the corner of the platform",font_16);
    inputTextAddress[8] = create_text(2850,300,"Attack by pressing D",font_16);
    inputTextAddress[9] =  create_text(2950,350,"The red bar is the monster's HP",font_16);
    inputTextAddress[10] = create_text(4750,250,"Tips:You can just ignore the monsters",font_16);
    inputTextAddress[11] = create_text(4750,300,"but you will get lower score in the end",font_16);
    inputTextAddress[12] = create_text(6370,250,"Hit the buttom of the chest to open it",font_16);
}


void createGround2(Ground *inputGroundAddress){
    inputGroundAddress[0]=create_ground(0, 500, 1500, 300, al_map_rgb(139, 69, 19));
    inputGroundAddress[1]=create_ground(1600, 500, 1500, 300, al_map_rgb(139, 69, 19));
}
void createObject2(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples){
    inputObjectAddress[0]=create_object(1100, 450, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[1]=create_object(1200, 450, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[2]=create_object(1300, 450, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[3]=create_object(1400, 450, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[4]=create_object(1150, 400, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[5]=create_object(1250, 400, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[6]=create_object(1350, 400, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[7]=create_object(1200, 350, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[8]=create_object(1300, 350, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[9]=create_object(1250, 300, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[10]=create_object(2100, 350, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[11]=create_object(2300, 350, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[12]=create_object(2500, 350, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[13]=create_object(2700, 350, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[14]=create_object(2200, 250, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[15]=create_object(2400, 250, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[16]=create_object(2600, 250, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[17]=create_object(2300, 150, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[18]=create_object(2500, 150, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[19]=create_object(2400, 50, 35, 35, inputBitmaps->reward_image, 3, false, false, true, NULL,inputSamples->coin);
    inputObjectAddress[20]=create_object(2100, 400, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[10],inputSamples->chest);
    inputObjectAddress[21]=create_object(2300, 400, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[11],inputSamples->chest);
    inputObjectAddress[22]=create_object(2500, 400, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[12],inputSamples->chest);
    inputObjectAddress[23]=create_object(2700, 400, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[13],inputSamples->chest);
    inputObjectAddress[24]=create_object(2200, 300, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[14],inputSamples->chest);
    inputObjectAddress[25]=create_object(2400, 300, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[15],inputSamples->chest);
    inputObjectAddress[26]=create_object(2600, 300, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[16],inputSamples->chest);
    inputObjectAddress[27]=create_object(2300, 200, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[17],inputSamples->chest);
    inputObjectAddress[28]=create_object(2500, 200, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[18],inputSamples->chest);
    inputObjectAddress[29]=create_object(2400, 100, 35, 35, inputBitmaps->chest_image, 2, false, true, true, &inputObjectAddress[19],inputSamples->chest);

}
void createMonster2(Monster *inputMonsterAddress,MKBitmap *inputBitmaps){
    inputMonsterAddress[0] = create_monster(3100, 450, 35, 50, 2, inputBitmaps->monster_image1, 1, 1, 0, false, true, 20);
}
void createText2(Text *inputTextAddress ,ALLEGRO_FONT *font_16){
    inputTextAddress[0] = create_text(100,400,"What happens if there are a lot of coins?",font_16);
}

void createGround3(Ground *inputGroundAddress){
    inputGroundAddress[0]=create_ground(0, 800, 900, 300, al_map_rgb(139, 69, 19));
    inputGroundAddress[1]=create_ground(1000, 700, 100, 30, al_map_rgb(139, 69, 19));
    inputGroundAddress[2]=create_ground(1000, 500, 100, 30, al_map_rgb(139, 69, 19));
    inputGroundAddress[3]=create_ground(1000, 300, 100, 30, al_map_rgb(139, 69, 19));
    inputGroundAddress[4]=create_ground(1200, 300, 6, 1000, al_map_rgb(139, 69, 19));
    inputGroundAddress[5]=create_ground(1400, 300, 6, 1000, al_map_rgb(139, 69, 19));
    inputGroundAddress[6]=create_ground(1500, 300, 6, 1000, al_map_rgb(139, 69, 19));
    inputGroundAddress[7]=create_ground(1700, 300, 6, 1000, al_map_rgb(139, 69, 19));
    inputGroundAddress[8]=create_ground(2000, 500, 10, 10, al_map_rgb(139, 69, 19));
    inputGroundAddress[9]=create_ground(2200, 600, 10, 10, al_map_rgb(139, 69, 19));
    inputGroundAddress[10]=create_ground(2400, 700, 10, 10, al_map_rgb(139, 69, 19));
    inputGroundAddress[11]=create_ground(2600, 800, 10, 10, al_map_rgb(139, 69, 19));
    inputGroundAddress[12]=create_ground(2800, 900, 200, 100, al_map_rgb(139, 69, 19));
    inputGroundAddress[13]=create_ground(3290, 900, 6, 6, al_map_rgb(139, 69, 19));
    inputGroundAddress[14]=create_ground(3536, 900, 6, 6, al_map_rgb(139, 69, 19));
    inputGroundAddress[15]=create_ground(3782, 900, 6, 6, al_map_rgb(139, 69, 19));
    inputGroundAddress[16]=create_ground(4028, 900, 6, 6, al_map_rgb(139, 69, 19));
    inputGroundAddress[17]=create_ground(4274, 900, 6, 6, al_map_rgb(139, 69, 19));
    inputGroundAddress[18]=create_ground(4500, 900, 300, 600, al_map_rgb(139, 69, 19));
}
void createObject3(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples){
    inputObjectAddress[0] = create_object(2900, 850, 35, 50, inputBitmaps->checkpoint_image, 1, false, true, true, NULL,inputSamples->check);
    inputObjectAddress[1] = create_object(1110, 500, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[2] = create_object(955, 300, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[3] = create_object(2100, 380, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[4] = create_object(2300, 480, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[5] = create_object(2500, 580, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[6] = create_object(2700, 680, 35, 35, inputBitmaps->reward_image, 3, false, true, true, NULL,inputSamples->coin);
    inputObjectAddress[7] = create_object(4600, 800, 100, 100, inputBitmaps->end_image, 4, false, true, true, NULL,NULL);
}
void createMonster3(Monster *inputMonsterAddress,MKBitmap *inputBitmaps){
    inputMonsterAddress[0] = create_monster(1400, 250, 85, 40, 7, inputBitmaps->monster_image2, 1, 1, 0, false, true, 20);
    inputMonsterAddress[1] = create_monster(1400, 250, 85, 40, 7, inputBitmaps->monster_image2, 1, 1, 0, false, true, 20);
    inputMonsterAddress[2] = create_monster(1400, 250, 85, 40, 7, inputBitmaps->monster_image2, 1, 1, 0, false, true, 20);
    inputMonsterAddress[3] = create_monster(1400, 250, 85, 40, 7, inputBitmaps->monster_image2, 1, 1, 0, false, true, 20);
    inputMonsterAddress[4] = create_monster(1400, 250, 85, 40, 7, inputBitmaps->monster_image2, 1, 1, 0, false, true, 20);
}
void createText3(Text *inputTextAddress ,ALLEGRO_FONT *font_16){
    inputTextAddress[0] = create_text(100,400,"This is the level with strange platforms",font_16);
    inputTextAddress[1] = create_text(100,450,"for players who wants to try some challenge",font_16);
    inputTextAddress[2] = create_text(3090,950,"you need to jump with",font_16);
    inputTextAddress[3] = create_text(3050,1000,"the greatest distance in this game",font_16);
}