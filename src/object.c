#include "myheader.h"

Object create_object(double x, double y, double width, double height, ALLEGRO_BITMAP *image, int typeID, bool isHit, bool isVisible, bool audioTrigger, Object* bond, ALLEGRO_SAMPLE_INSTANCE *audio) {
    Object object = {x, y, width, height, image, typeID, isHit, isVisible, audioTrigger, bond, audio};
    return object;
}


void check_object_collision(Object object[], Player *player, int *score) {
    int i;
    for(i = 0; i<=NUM_OBJECTS; i++)
    {
        switch(object[i].typeID)
        {
            case 1:
                if (player->x < object[i].x + object[i].width && player->x + player->width > object[i].x &&
                    player->y < object[i].y + object[i].height && player->y + player->height > object[i].y) {
                    player->checkpoint_x = object[i].x;
                    player->checkpoint_y = object[i].y;
                    if(object[i].audioTrigger == true){
                        al_set_sample_instance_playing(object[i].audio, false);
                        al_set_sample_instance_playing(object[i].audio, true);
                        object[i].audioTrigger = false;
                    }
                    //checkpoint->isHit = true;
                }
                break;
            case 2:
                if (!object->isHit && player->x < object[i].x + object[i].width && player->x + player->width > object[i].x &&
                    player->y < object[i].y + object[i].height && player->y + player->height > object[i].y) {
                    object[i].isHit = true;
                    object[i].bond->isVisible = true;
                }
                break;

            case 3:
                if (!object->isHit && player->x < object[i].x + object[i].width && player->x + player->width > object[i].x &&
                    player->y < object[i].y + object[i].height && player->y + player->height > object[i].y) {
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
        }        
    }
}

