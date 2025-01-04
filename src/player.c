#include "myheader.h"

Player create_player(double x, double y, double checkpoint_x,double checkpoint_y, double width, double height,  double horizonSpeed,
 double verticalSpeed, double g,int collisionHorizon,int collisionVert, bool onGround ,ALLEGRO_BITMAP *image,
 int HP, int LV ,int direction,int img_num,int frame_count,int prev_key) {
    int maxHP;
    maxHP = HP;
    Player player = {x, y, checkpoint_x, checkpoint_y, width, height, horizonSpeed,
     verticalSpeed, g, collisionHorizon, collisionVert, onGround, 0 , 0 , 1, image,
     20 , 1,1 ,direction,img_num ,frame_count,prev_key , maxHP};
    return player;
}

void move_player(Player *player, Ground grounds[], int num_grounds,Object objects[], int num_objects, ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState,ALLEGRO_BITMAP *player_image_tmp[]) {
    double new_x = player->x;
    double new_y = player->y;
    double new_verticalSpeed = player->verticalSpeed;
    int i,j,num,m,n;
    new_verticalSpeed = player->verticalSpeed - player->g; 
    new_y = player->y - player->verticalSpeed;
    player->frame_count+=1;
    printf("%f   %f\n",player->x,player->y);
    //printf("%d  ",player->img_num);
    if (player->prev_key == 0 && (player->img_num > 12 && player->img_num <22)){
        player->img_num = 0;
    }
    player->prev_key = 0;
    if(player->frame_count == 5){
        player->frame_count = 0;
        player->img_num += 1;
        //num = player->img_num;
        // printf("%d",num);
    }   
    if(player->img_num == 12){
        player->img_num = 0;
    }
    else if(player->img_num == 21){
        player->img_num = 13;
    }
    else if(player->img_num >= 22 && player->img_num < 33){
        player->width = 115;
        player->image = player_image_tmp[player->img_num];
        player->img_num += 1;
        if(player->img_num == 34||player->img_num == 35){
            player->img_num = 0;
            player->width = 40;
        }
        return;
    }
    if(player->img_num == 34||player->img_num == 35){
        player->img_num = 0;
        player->width = 40;
    }
    
    // if(player->img_num == 11){
    //     player->img_num = 0;
    // }
    player->image = player_image_tmp[player->img_num];
    
    
    //player->onGround = true;
    // Check collision with ground
    if ((al_key_down(keyState, ALLEGRO_KEY_UP))||(JoyState->button[0])) {
        if(player->onGround){
            new_verticalSpeed = 20;
            player->onGround = false;
        }
    }
    for (j = 0; j < num_grounds; j++) {
        // Check TOP
        if (new_x < grounds[j].x + grounds[j].width && new_x + player->width > grounds[j].x &&
            new_y < grounds[j].y && new_y + player->height > grounds[j].y) {
            player->collisionVert = 1;
            break;
        }
        // Check Bottom
        if (new_x < grounds[j].x + grounds[j].width && new_x + player->width > grounds[j].x &&
            new_y < grounds[j].y + grounds[j].height && new_y + player->height > grounds[j].y + grounds[j].height) {
            player->collisionVert = 2;
            break;
        }
        player->collisionVert = 0;
    }
    if (player->collisionVert == 1) {
        new_verticalSpeed = 0;;
        //player->x = new_x;
        new_y = grounds[j].y - player->height;
        player->onGround = true;
    }
    if (player->collisionVert == 2) {
        new_verticalSpeed = 0;
        //player->x = new_x;
        new_y = grounds[j].y + grounds[j].height;
    }
    for (n = 0; n < num_objects; n++) {
        if(objects[n].typeID == 2){
            // Check TOP
            if (new_x < objects[n].x + objects[n].width && new_x + player->width > objects[n].x &&
                new_y < objects[n].y && new_y + player->height > objects[n].y) {
                player->collisionVert = 5;
                break;
            }
            // Check Bottom
            if (new_x < objects[n].x + objects[n].width && new_x + player->width > objects[n].x &&
                new_y < objects[n].y + objects[n].height && new_y + player->height > objects[n].y + objects[n].height) {
                player->collisionVert = 6;
                break;
            }
            player->collisionVert = 0;
        }
    }                
    
    if (player->collisionVert == 5) {
        new_verticalSpeed = 0;
        //player->x = new_x;
        player->onGround = true;
        new_y = objects[n].y - player->height;
        
        
    }
    if (player->collisionVert == 6) {
        new_verticalSpeed = 0;
        //player->x = new_x;
        new_y = objects[n].y + objects[n].height;
        
        objects[n].isHit =true;
    }


    if (al_key_down(keyState, ALLEGRO_KEY_LEFT)||(JoyState->stick[0].axis[0]<-0.5)) {
        player->width = 40;
        new_x -= player->horizonSpeed;
        player->walkingStatus = true;
        player->directionStatus = 1;
        player->direction = 0;
        player->prev_key = 1;
        if(player->img_num <= 12 || player->img_num >20)
            player->img_num = 13;
    }
    else if (al_key_down(keyState, ALLEGRO_KEY_RIGHT)||(JoyState->stick[0].axis[0]>0.5)) {
        player->width = 40;
        new_x += player->horizonSpeed;
        player->walkingStatus = true;
        player->directionStatus = 0;
        player->direction = 1;
        player->prev_key = 1;
        if(player->img_num <= 12 || player->img_num >20)
            player->img_num = 13;
    }
    else {
        player->walkingStatus = false;
    }
    for (i = 0; i < num_grounds; i++) {
        // Check LEFT
        if (new_x < grounds[i].x && new_x + player->width > grounds[i].x &&
            new_y < grounds[i].y + grounds[i].height && new_y + player->height > grounds[i].y) {
            player->collisionHorizon = 3;
            break;
        }
        // Check RIGHT
        if (new_x < grounds[i].x + grounds[i].width && new_x + player->width > grounds[i].x + grounds[i].width &&
            new_y < grounds[i].y + grounds[i].height && new_y + player->height > grounds[i].y) {
            player->collisionHorizon = 4;
            break;
        }
        player->collisionHorizon = 0;
    }
    if (player->collisionHorizon == 3) {
        //new_verticalSpeed = player->verticalSpeed - player->g;
        new_x = grounds[i].x - player->width;
        player->walkingStatus = false;
        //player->y = new_y;
    }

    if (player->collisionHorizon == 4) {
        //new_verticalSpeed = player->verticalSpeed - player->g;
        new_x = grounds[i].x + grounds[i].width;
        player->walkingStatus = false;
        //player->y = new_y;
    }
    for (m = 0; m < num_objects; m++) {
        if(objects[m].typeID == 2){
            // Check LEFT
            if (new_x < objects[m].x && new_x + player->width > objects[m].x &&
                new_y < objects[m].y + objects[m].height && new_y + player->height > objects[m].y) {
                player->collisionHorizon = 7;
                break;
            }
            // Check RIGHT
            if (new_x < objects[m].x + objects[m].width && new_x + player->width > objects[m].x + objects[m].width &&
                new_y < objects[m].y + objects[m].height && new_y + player->height > objects[m].y) {
                player->collisionHorizon = 8;
                break;
            }
            player->collisionHorizon = 0;
        }
    }
    
    if (player->collisionHorizon == 7) {
        //new_verticalSpeed = player->verticalSpeed - player->g;
        new_x = objects[m].x - player->width;
        player->walkingStatus = false;
        //player->y = new_y;
    }

    if (player->collisionHorizon == 8) {
        //new_verticalSpeed = player->verticalSpeed - player->g;
        new_x = objects[m].x + objects[m].width;
        player->walkingStatus = false;
        //player->y = new_y;
    }

    if(new_y > (-WORLD_HEIGHT))
    {
        new_x = player->checkpoint_x;
        new_y = player->checkpoint_y;
        new_verticalSpeed = 0;
        player->walkingStatus = false;
    }
    player->verticalSpeed = new_verticalSpeed;
    player->x = new_x;
    player->y = new_y;
    // printf("playerX:%f  playerY:%f\n",player->x,player->y);
    if(player->verticalSpeed != 0)
        player->onGround = false;
}

void ying_attacking(Player *playerInput, mkworld* inputWorld , ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState, int *CD,ALLEGRO_BITMAP *inputplayerImage[], int* score,MKSample *inputSamples){
    Monster *MonsterPtr;
    MonsterPtr = inputWorld->monsterAddress;
        *CD -=1;
        if (*CD<0)
            *CD = 0;
        //printf("%d\n",*CD);
        if((al_key_down(keyState,ALLEGRO_KEY_D)||JoyState->button[1])&&*CD == 0){
            int k;
            *CD = 40;
            playerInput->width = 115;
            playerInput->img_num = 22;
            playerInput->image = inputplayerImage[22];
            al_set_sample_instance_playing(inputSamples->laser, true);
            for(k=0;k<inputWorld[0].monsterNum;k++){
                if(playerInput->directionStatus == 0){ //玩家向右
                    if((MonsterPtr[k].x+MonsterPtr[k].width>playerInput->x+54) && (MonsterPtr[k].x < playerInput->x+playerInput->width)
                    && (MonsterPtr[k].y + MonsterPtr[k].height >= playerInput->y+2) &&(MonsterPtr[k].y <= playerInput->y+19)){
                        if(playerInput->attackingStatus == 0){
                            MonsterPtr[k].HP -= ATTACK_PER_LV * playerInput->LV;
                            if(MonsterPtr[k].HP<=0 && MonsterPtr[k].isVisible == true){
                                MonsterPtr[k].isVisible = false;
                                *score += 2;
                            }
                        } 
                    }
                }
                else{
                    if((MonsterPtr[k].x+MonsterPtr[k].width>playerInput->x-75) && (MonsterPtr[k].x < playerInput->x+playerInput->width-129)
                    && (MonsterPtr[k].y + MonsterPtr[k].height >= playerInput->y+2)&&(MonsterPtr[k].y <= playerInput->y+19)){
                        if(playerInput->attackingStatus == 0){
                            MonsterPtr[k].HP -= ATTACK_PER_LV * playerInput->LV;
                            if(MonsterPtr[k].HP<=0&& MonsterPtr[k].isVisible == true){
                                MonsterPtr[k].isVisible = false;
                                *score += 2;
                            }
                        }
                    }
                }
            }
            if(playerInput->attackingStatus == 0) playerInput ->attackingStatus = 1;
        }
        if(playerInput->attackingStatus > 0){
            if(playerInput->attackingStatus == 30){ //攻擊動畫間隔
                playerInput->attackingStatus =0;
            }
            else playerInput->attackingStatus +=1;
        }
}