#include "myheader.h"

void leng_playerImgInit(ALLEGRO_BITMAP *player_images[],int playerImagesNum){
    int i;


    player_images[0] = al_load_bitmap("./Idle/1.png");
    player_images[1] = al_load_bitmap("./Idle/2.png");
    player_images[2] = al_load_bitmap("./Idle/3.png");
    player_images[3] = al_load_bitmap("./Idle/4.png");
    player_images[4] = al_load_bitmap("./Idle/5.png");
    player_images[5] = al_load_bitmap("./Idle/6.png");
    player_images[6] = al_load_bitmap("./Idle/7.png");
    player_images[7] = al_load_bitmap("./Idle/6.png");
    player_images[8] = al_load_bitmap("./Idle/5.png");
    player_images[9] = al_load_bitmap("./Idle/4.png");
    player_images[10] = al_load_bitmap("./Idle/3.png");
    player_images[11] = al_load_bitmap("./Idle/2.png");
    player_images[12] = NULL;
    player_images[13] = al_load_bitmap("./Run/1.png");
    player_images[14] = al_load_bitmap("./Run/2.png");
    player_images[15] = al_load_bitmap("./Run/3.png");
    player_images[16] = al_load_bitmap("./Run/4.png");
    player_images[17] = al_load_bitmap("./Run/5.png");
    player_images[18] = al_load_bitmap("./Run/6.png");
    player_images[19] = al_load_bitmap("./Run/7.png");
    player_images[20] = al_load_bitmap("./Run/8.png");
    player_images[21] = NULL;

    for(i = 0; i<=playerImagesNum; i++){
        if(player_images[i] != NULL)
            player_images[i] = al_create_sub_bitmap(player_images[i], 40, 64, 48, 64);
        else 
            player_images[i] = NULL;
    }
}