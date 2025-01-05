#include "myheader.h"

//These program is wrote by ** 和 **, 我只負責把其整合成一結構方便整理
void ying_loadingBitmap(MKBitmap *inputBitmaps){
    int monsterClassNum=1;
    inputBitmaps->chest_image = al_load_bitmap("chest.png");
    inputBitmaps->chest_image2 = al_load_bitmap("chest2.png");
    inputBitmaps->reward_image = al_load_bitmap("reward.png");
    inputBitmaps->checkpoint_image = al_load_bitmap("checkpoint.png");
    inputBitmaps->checkpoint_image2 = al_load_bitmap("checkpoint2.png");
    inputBitmaps->end_image = al_load_bitmap("end.png");
    inputBitmaps->monster_image1 = al_load_bitmap("monster1.png");
    inputBitmaps->monster_image2 = al_load_bitmap("monster2.png");
    inputBitmaps->world_map_mediumRes = al_load_bitmap("./Map/med.png");
    inputBitmaps->world_map_highRes = al_load_bitmap("./Map/high.jpg");
    inputBitmaps->world_map_lowRes = al_load_bitmap("./Map/earth.jpg");
}

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
    player_images[22] = al_load_bitmap("./Attack/1.png");
    player_images[23] = al_load_bitmap("./Attack/2.png");
    player_images[24] = al_load_bitmap("./Attack/3.png");
    player_images[25] = al_load_bitmap("./Attack/4.png");
    player_images[26] = al_load_bitmap("./Attack/5.png");
    player_images[27] = al_load_bitmap("./Attack/6.png");
    player_images[28] = al_load_bitmap("./Attack/7.png");
    player_images[29] = al_load_bitmap("./Attack/8.png");
    player_images[30] = al_load_bitmap("./Attack/9.png");
    player_images[31] = al_load_bitmap("./Attack/10.png");
    player_images[32] = al_load_bitmap("./Attack/11.png");
    player_images[33] = al_load_bitmap("./Attack/12.png");
    player_images[34] = al_load_bitmap("./Attack/13.png");
    player_images[35] = NULL;

    // for(i = 0; i<=playerImagesNum; i++){
    //     if(player_images[i] != NULL)
    //         player_images[i] = al_create_sub_bitmap(player_images[i], 40, 64, 48, 64);
    //     else 
    //         player_images[i] = NULL;
    // }

    for(i = 0; i<=playerImagesNum-15; i++){
        if(player_images[i] != NULL)
            player_images[i] = al_create_sub_bitmap(player_images[i], 40, 64, 48, 64);
        else 
            player_images[i] = NULL;
    }
    for(i = playerImagesNum-14; i<=playerImagesNum; i++){
        if(player_images[i] != NULL)
            player_images[i] = al_create_sub_bitmap(player_images[i], 5, 64, 125, 64);
        else 
            player_images[i] = NULL;
    }
}

// ying_MENU
void ying_InitMenu(MKMenu *inputMenu,ALLEGRO_DISPLAY *inputDisplay){
    inputMenu->mainMenu = al_create_menu();
    inputMenu->Game = al_create_menu();
    inputMenu->Setting = al_create_menu();
    inputMenu->Resolution = al_create_menu();
    inputMenu->LevelOption = al_create_menu();


    al_append_menu_item(inputMenu->mainMenu, "Game" , 0 , 0 , NULL ,inputMenu->Game);
    al_append_menu_item(inputMenu->mainMenu, "Setting", 0 , 0 , NULL, inputMenu->Setting);
    al_append_menu_item(inputMenu->Setting ,"Resoultion", 0 , 0 , NULL ,inputMenu->Resolution);
    al_append_menu_item(inputMenu->Resolution, "640x320",VGA,0,NULL,NULL);
    al_append_menu_item(inputMenu->Resolution, "800x600",SVGA,0,NULL,NULL);
    al_append_menu_item(inputMenu->Resolution, "1024x768",XGA,0,NULL,NULL);
    al_append_menu_item(inputMenu->Resolution, "1280x720",HD,0,NULL,NULL);
    al_append_menu_item(inputMenu->Resolution, "1920x1080",FHD,0,NULL,NULL);
    al_append_menu_item(inputMenu->Resolution, "2560x1440",DUAL,0,NULL,NULL);
    al_append_menu_item(inputMenu->Resolution, "3840x2160",QUAD,0,NULL,NULL);

    al_append_menu_item(inputMenu->Game,"Save" ,SAVE_SCORE , 0 , NULL , NULL);
    al_append_menu_item(inputMenu->Game,"Read" ,READ_SCORE_BOARD , 0 , NULL , NULL);
    al_append_menu_item(inputMenu->Game,"Respawn" ,SPAWN , 0 , NULL , NULL);
    al_append_menu_item(inputMenu->Game,"Back to Menu" ,BACK_TO_MENU , 0 , NULL , NULL);
    al_append_menu_item(inputMenu->Game,"Quit" ,EXIT_ID ,0 , NULL ,NULL);

    al_append_menu_item(inputMenu->Game, "Level",0 ,0,NULL,inputMenu->LevelOption);
    al_append_menu_item(inputMenu->LevelOption, "Level 1",LEVEL1,0,NULL,NULL);
    al_append_menu_item(inputMenu->LevelOption, "Level 2",LEVEL2,0,NULL,NULL);
    al_append_menu_item(inputMenu->LevelOption, "Level 3",LEVEL3,0,NULL,NULL);



    al_set_display_menu(inputDisplay, inputMenu->mainMenu);

    }


void all_initialize(){
    //initialize the part of allegro 
    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_init_ttf_addon();
    al_install_mouse();

    //REMIND: This is for Meun fnction
    al_init_native_dialog_addon();

    //random seed
    srand(time(NULL));

    //Install joystick driver
    if(!al_install_joystick())  
    {
        printf("cannot joystick");
    }
}