#include "myheader.h"

Object create_object(double x, double y, double width, double height, ALLEGRO_BITMAP *image, int typeID, bool isHit, bool isVisible, bool audioTrigger, Object* bond, ALLEGRO_SAMPLE_INSTANCE *audio) {
    Object object = {x, y, width, height, image, typeID, isHit, isVisible, audioTrigger, bond, audio};
    return object;
}


void check_object_collision(Object object[], Player *player, int *score,int objectNum,MKBitmap *inputBitmaps,int* level,bool* level_2_unlock,bool* level_3_unlock,Node *Scoreheadptr,char name[16],bool* menu_active,int* button_state) {
    int i,j;
    for(i = 0; i<=objectNum; i++)
    {
        switch(object[i].typeID)
        {
            //checkpoint
            case 1:
                if (player->x < object[i].x + object[i].width && player->x + 32 > object[i].x &&
                    player->y < object[i].y + object[i].height && player->y + player->height > object[i].y) {
                    player->checkpoint_x = object[i].x;
                    player->checkpoint_y = object[i].y;
                    if(object[i].audioTrigger == true){
                        al_set_sample_instance_playing(object[i].audio, false);
                        al_set_sample_instance_playing(object[i].audio, true);
                        object[i].image = inputBitmaps->checkpoint_image2;
                        object[i].audioTrigger = false;
                    }
                    for(j = 0; j<=objectNum; j++){
                        if((object[j].typeID == 1) && (i != j)){
                            object[j].image = inputBitmaps->checkpoint_image;
                            object[j].audioTrigger = true;
                        }
                    }
                    //checkpoint->isHit = true;
                }
                break;
            //box
            case 2:
                if (object[i].isHit == true && object[i].audioTrigger == true) {
                    //object[i].isHit = true;
                    object[i].image = inputBitmaps->chest_image2;
                    object[i].audioTrigger = false;
                    object[i].bond->isVisible = true;
                    al_set_sample_instance_playing(object[i].audio, false);
                    al_set_sample_instance_playing(object[i].audio, true);
                }
                break;
            //money
            case 3:
                if (!object[i].isHit && player->x < object[i].x + object[i].width && player->x + 40 > object[i].x &&
                    player->y < object[i].y + object[i].height && player->y + player->height > object[i].y && object[i].isVisible == true) {
                    object[i].isHit = true;
                    object[i].isVisible = false;
                    if(object[i].audioTrigger == true){
                        al_set_sample_instance_playing(object[i].audio, false);
                        al_set_sample_instance_playing(object[i].audio, true);
                        object[i].audioTrigger = false;
                        *score +=1;
                    }
                }
                break;
            //end    
            case 4:
                if (!object[i].isHit && player->x < object[i].x + object[i].width && player->x + 32 > object[i].x &&
                    player->y < object[i].y + object[i].height && player->y + player->height > object[i].y && object[i].isVisible == true) {
                    object[i].isHit = true;
                    object[i].isVisible = false;
                    *level +=1;
                    player->x = 100;
                    player->y = 100;
                    player->checkpoint_x = 100;
                    player->checkpoint_y = 100;
                    player->HP = 20;
                    if(*level ==2){
                        *level_2_unlock = true;
                    }
                    else if(*level == 3){
                        *level_3_unlock = true;
                        ///
                        player->x = 4500;
                        player->y = 800;
                        player->checkpoint_x = 4500;
                        player->checkpoint_y = 800;
                        ///
                    }
                    else{
                        *button_state = 0;
                        *level = 1;
                        insert(Scoreheadptr,name,*score);
                        *menu_active = true;
                    }
                }
                break;
        }        
    }
}

