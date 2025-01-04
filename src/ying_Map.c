#include "myheader.h"
#define MAPCD 20

void Map(Camera *camera,Player *player, mkworld *world, ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState, int *CD,MKBitmap *bitmaps){
    double max;
    double min;
    double ZoomRate;
    int i;
    Ground tempGround;
    Object tempObject;
    Player tempPlayer;
    
    //limit the time range between switch map
    if (((al_key_down(keyState, ALLEGRO_KEY_M))||(JoyState->button[3]))&&(*CD==MAPCD)){
        if(player->MapEnable==0){
            if(rand()%20==9)player->MapEnable=2;
            else player->MapEnable=1;
        }
        else player->MapEnable=0;
        *CD-=1;
    }
    else if(*CD==0){
        *CD = MAPCD;
    }
    else if(*CD!=MAPCD){
        *CD =*CD-1;
    } 

    //Enable Map
    if(player->MapEnable==2){
        al_draw_filled_rectangle(camera->x, camera->y+camera->cameraHeight/4 , camera->x+camera->cameraWidth, camera->y+camera->cameraHeight*3/4 , al_map_rgb(150,150,150));
        // al_draw_scaled_bitmap(bitmaps->world_map_high,0,0,1880,952,camera->x,camera->y,1880,952,0);
        if(camera->cameraWidth>1920-1){
            al_draw_bitmap(bitmaps->world_map_highRes,camera->x+camera->cameraWidth/2-940,camera->y+camera->cameraHeight/2-476,0);
        }
        else if(camera->cameraWidth>1280-1){
            al_draw_bitmap(bitmaps->world_map_mediumRes,camera->x+camera->cameraWidth/2-620,camera->y+camera->cameraHeight/2-313.5,0);
        }
        else{
            al_draw_scaled_bitmap(bitmaps->world_map_mediumRes,0,0,camera->cameraWidth,camera->cameraHeight/2,camera->x,camera->y+camera->cameraHeight/4,camera->cameraWidth,camera->cameraWidth/2,0);
        }
    }

    else if(player->MapEnable==1){
        min = world->groundAddress[0].x;
        max = min;
        for(i=0;i<world->groundNum;i++){
            if(min>world->groundAddress[i].x) min=world->groundAddress[i].x;
            if(world->groundAddress[i].x+world->groundAddress[i].width>max) max = world->groundAddress[i].x+world->groundAddress[i].width;
        }
        ZoomRate = (camera->cameraWidth - 40)/(max-min);
        al_draw_filled_rectangle(camera->x, camera->y+camera->cameraHeight/4 , camera->x+camera->cameraWidth, camera->y+camera->cameraHeight*3/4 , al_map_rgb(150,150,150));
        
        //Resize Ground to fit the map
        for(i=0;i<world->groundNum;i++){
            tempGround=world->groundAddress[i];
            tempGround.x*=ZoomRate;
            tempGround.y*=ZoomRate;
            tempGround.width*=ZoomRate;
            tempGround.height*=ZoomRate;

            //If too low,then just generate to the edge of map.
            if(camera->y + camera->cameraHeight*3/8 + tempGround.y + tempGround.height > camera->y+camera->cameraHeight*3/4){
                al_draw_filled_rectangle(camera->x+20+tempGround.x, camera->y + camera->cameraHeight*3/8 + tempGround.y,
                                     camera->x+20+tempGround.x+tempGround.width , camera->y+camera->cameraHeight*3/4-20,
                                     tempGround.color   );
            }
            else{
                al_draw_filled_rectangle(camera->x+20+tempGround.x, camera->y + camera->cameraHeight*3/8 + tempGround.y,
                                     camera->x+20+tempGround.x+tempGround.width , camera->y + camera->cameraHeight*3/8 + tempGround.y + tempGround.height,
                                     tempGround.color   );
            }

            //Draw the map
            

        }
        for(i=0;i<world->objectNum;i++){
            if(world->objectAddress[i].isVisible==1){
                tempObject=world->objectAddress[i];
                tempObject.x*=ZoomRate;
                tempObject.y*=ZoomRate;
                tempObject.width*=ZoomRate;
                tempObject.height*=ZoomRate;

            //Draw the checkpoint;
            if(world->objectAddress[i].typeID==1){
                al_draw_filled_rectangle(camera->x+20+tempObject.x, camera->y + camera->cameraHeight*3/8 + tempObject.y,
                                        camera->x+20+tempObject.x+tempObject.width , camera->y + camera->cameraHeight*3/8 + tempObject.y + tempObject.height,
                                        al_map_rgb(0,255,0)   );
                }
            //Draw the chest or other objects;
            else al_draw_filled_rectangle(camera->x+20+tempObject.x, camera->y + camera->cameraHeight*3/8 + tempObject.y,
                                        camera->x+20+tempObject.x+tempObject.width , camera->y + camera->cameraHeight*3/8 + tempObject.y + tempObject.height,
                                        al_map_rgb(255,255,0)   );
            }
        }

        tempPlayer = *player;
        tempPlayer.x*=ZoomRate;
        tempPlayer.y*=ZoomRate;
        tempPlayer.width*=ZoomRate;
        tempPlayer.height*=ZoomRate;
        al_draw_filled_rectangle(camera->x+20+tempPlayer.x, camera->y + camera->cameraHeight*3/8 + tempPlayer.y,
                                     camera->x+20+tempPlayer.x+tempPlayer.width , camera->y + camera->cameraHeight*3/8 + tempPlayer.y + tempPlayer.height,
                                     al_map_rgb(255,0,0)   );

    }
}