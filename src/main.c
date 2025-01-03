#include "myheader.h"


int main() {
    Camera camera;

    all_initialize();

    int resolutionWidth = 1600; 
    int resolutionHeigth = 900;
   

    ALLEGRO_DISPLAY *display = al_create_display(resolutionWidth, resolutionHeigth);
    ALLEGRO_BITMAP *chest_image = al_load_bitmap("chest.png");
    ALLEGRO_BITMAP *reward_image = al_load_bitmap("reward.png");
    ALLEGRO_BITMAP *checkpoint_image = al_load_bitmap("checkpoint.png");
    ALLEGRO_BITMAP *monster_image = al_load_bitmap("monster1.png");
    ALLEGRO_TIMER *timer = al_create_timer(0.016);
    ALLEGRO_SAMPLE *sample1 = al_load_sample("./pickup01.mp3");
    ALLEGRO_SAMPLE *sample2 = al_load_sample("./coin02.mp3");
    ALLEGRO_SAMPLE_INSTANCE *check = NULL, *coin = NULL;
    ALLEGRO_MIXER *mixer = NULL;
    ALLEGRO_VOICE *voice = NULL;
    ALLEGRO_FONT *font_16 = al_load_ttf_font("./score.TTC", 16, 0);
    ALLEGRO_KEYBOARD_STATE keyState;
    ALLEGRO_JOYSTICK_STATE joyState;
    ALLEGRO_JOYSTICK* joy1 = al_get_joystick(0);
    bool joyStickPluged = false;
    int score = 0;
    int i,L,playerImages = 21;
    ALLEGRO_BITMAP *player_images[playerImages];
    al_start_timer(timer);
    al_set_window_title(display,"A New World!");
    //sample1 = al_load_sample("./pickup01.mp3");
    check = createSound(sample1,mixer,voice);
    coin = createSound(sample2,mixer,voice);
    leng_playerImgInit(player_images,playerImages);

    printf("level:");
    scanf("%d",&L);
    Ground grounds1[] = {
        create_ground(0, 500, 900, 300, al_map_rgb(139, 69, 19)),
        create_ground(900, 600, 200, 200, al_map_rgb(139, 69, 19)),
        create_ground(1100, 500, 500, 300, al_map_rgb(139, 69, 19)),
        create_ground(1800, 500, 500, 300, al_map_rgb(139, 69, 19)),
        create_ground(2550, 500, 1500, 300, al_map_rgb(139, 69, 19)),
        create_ground(4150, 350, 100, 100, al_map_rgb(139, 69, 19)),
        create_ground(4350, 350, 100, 100, al_map_rgb(139, 69, 19)),
        create_ground(4550, 350, 100, 100, al_map_rgb(139, 69, 19)),
        create_ground(4750, 500, 300, 300, al_map_rgb(139, 69, 19)),
        create_ground(5150, 430, 400, 400, al_map_rgb(139, 69, 19)),
    };
    Ground grounds2[] = {
        create_ground(0, 500, 900, 300, al_map_rgb(139, 69, 19))
    };
    Ground grounds3[] = {
        create_ground(0, 500, 900, 300, al_map_rgb(139, 69, 19))
    };
    Player player = create_player(100, 100, 100, 100, 40, 40, 6.0, 0, 1.0, 0, 0 ,false, player_images[0],20,1,1,0,0,0);
    Object objects1[] = {
        create_object(1400, 450, 35, 50, checkpoint_image, 1, false, true, true, NULL,check),
        create_object(2900, 450, 35, 50, checkpoint_image, 1, false, true, true, NULL,check),
        create_object(4850, 450, 35, 50, checkpoint_image, 1, false, true, true, NULL,check),
        create_object(750, 450, 35, 35, reward_image, 3, false, true, true, NULL,coin),
        create_object(987, 550, 35, 35, reward_image, 3, false, true, true, NULL,coin),
        create_object(2400, 300, 35, 35, reward_image, 3, false, true, true, NULL,coin),
        create_object(4187, 300, 35, 35, reward_image, 3, false, true, true, NULL,coin),
        create_object(4387, 300, 35, 35, reward_image, 3, false, true, true, NULL,coin),
        create_object(4587, 300, 35, 35, reward_image, 3, false, true, true, NULL,coin)
        //create_object(200, 400, 30, 30, reward_image, 3, false, false, NULL),
        //create_object(200, 450, 50, 50, chest_image, 2, false, true, &objects[1]),
    };
    Object objects2[] = {
        create_object(1400, 450, 35, 50, checkpoint_image, 1, false, true, true, NULL,check)
    };
    Object objects3[] = {
        create_object(1400, 450, 35, 35, reward_image, 2, false, true, true, NULL,check)
    };
    Monster monsters1[]={
        create_monster(3100, 450, 35, 50, 2, monster_image, 1, 1, 0, false, true, 20),
        create_monster(5200, 380, 35, 50, 10, monster_image, 1, 1, 0, false, true, 20)
    };
    Monster monsters2[]={
        create_monster(3100, 450, 35, 50, 2, monster_image, 1, 1, 0, false, true, 20)
    };
    Monster monsters3[]={
        create_monster(3100, 450, 35, 50, 2, monster_image, 1, 1, 0, false, true, 20)
    };
    
    Text texts1[]={
        create_text(100,400,"Use arrow keys to move and jump",font_16),
        create_text(700,400,"Pick up coin to get score",font_16),
        create_text(1300,400,"Touch the flag to save checkpoint",font_16),
        create_text(1640,570,"If you drop off",font_16),
        create_text(1650,600,"the platform",font_16),
        create_text(1640,630,"you will respawn",font_16),
        create_text(1650,660,"at checkpoint",font_16),
        create_text(2250,400,"Try to jump at the corner of the platform",font_16)
    };
    Text texts2[]={
        create_text(100,400,"2",font_16)
    };
    Text texts3[]={
        create_text(100,400,"3",font_16)
    };

    int numGrounds1 = sizeof(grounds1) / sizeof(grounds1[0]);
    int numObjects1 = sizeof(objects1) / sizeof(objects1[0]);
    int numMonsters1 = sizeof(monsters1) / sizeof(monsters1[0]);
    int numTexts1 = sizeof(texts1) / sizeof(texts1[0]);
    int numGrounds2 = sizeof(grounds2) / sizeof(grounds2[0]);
    int numObjects2 = sizeof(objects2) / sizeof(objects2[0]);
    int numMonsters2 = sizeof(monsters2) / sizeof(monsters2[0]);
    int numTexts2 = sizeof(texts2) / sizeof(texts2[0]);
    int numGrounds3 = sizeof(grounds3) / sizeof(grounds3[0]);
    int numObjects3 = sizeof(objects3) / sizeof(objects3[0]);
    int numMonsters3 = sizeof(monsters3) / sizeof(monsters3[0]);
    int numTexts3 = sizeof(texts3) / sizeof(texts3[0]);
    
    // ying_MENU
    ALLEGRO_MENU *mainMenu = NULL;
    ALLEGRO_MENU *Game = NULL;
    ALLEGRO_MENU *Setting = NULL;
    ALLEGRO_MENU *Resolution = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_EVENT ev;
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_default_menu_event_source());
    al_register_event_source(event_queue, al_get_joystick_event_source());

    // ying_ Menu Setting

    mainMenu = al_create_menu();
    Game = al_create_menu();
    Setting = al_create_menu();
    Resolution = al_create_menu();

    al_append_menu_item(mainMenu, "Game" , 0 , 0 , NULL ,Game);
    al_append_menu_item(mainMenu, "Setting", 0 , 0 , NULL, Setting);
    al_append_menu_item(Setting ,"Resoultion", 0 , 0 , NULL ,Resolution);
    al_append_menu_item(Resolution, "640x320",VGA,0,NULL,NULL);
    al_append_menu_item(Resolution, "800x600",SVGA,0,NULL,NULL);
    al_append_menu_item(Resolution, "1024x768",XGA,0,NULL,NULL);
    al_append_menu_item(Resolution, "1280x720",HD,0,NULL,NULL);
    al_append_menu_item(Resolution, "1920x1080",FHD,0,NULL,NULL);
    al_append_menu_item(Resolution, "2560x1440",DUAL,0,NULL,NULL);
    al_append_menu_item(Resolution, "3840x2160",QUAD,0,NULL,NULL);
    


    al_set_display_menu(display, mainMenu);
    //

    joyStickPluged = load_joystick_info(joy1);

    ying_setCamera(&camera,(double)resolutionWidth,(double)resolutionHeigth);

    while (true) {
        al_wait_for_event(event_queue, &ev);
        ying_hotplug_detection(&ev,joy1,&joyStickPluged);
        if (ev.type == ALLEGRO_EVENT_TIMER){
            al_get_keyboard_state(&keyState);

            if(joyStickPluged)  al_get_joystick_state(joy1,&joyState); 
            else    ying_joystickFillZero(&joyState);
    
            switch (L)
            {
            case 1 :
                al_clear_to_color(al_map_rgb(0, 0, 0));  
                move_player(&player, grounds1, NUM_GROUNDS, &keyState , &joyState, &player_images);
                check_object_collision(objects1, &player, &score);
                moveMonster(monsters1);
                // ying_attacking(&player,monsters1,&keyState,&joyState);
                ying_updateCamera(&player,&camera);
                ying_renderWorld(&camera,grounds1,objects1,monsters1,texts1,&player,score,numGrounds1,numObjects1,numMonsters1,numTexts1);
                //al_draw_text(font_24, al_map_rgb(255, 0, 0), 100, 400, 0, "TEST");
                al_flip_display();
                break;
            case 2 :
                al_clear_to_color(al_map_rgb(0, 0, 0));  
                move_player(&player, grounds2, NUM_GROUNDS, &keyState , &joyState, &player_images);
                check_object_collision(objects2, &player, &score);
                moveMonster(monsters2);
                ying_attacking(&player,monsters2,&keyState,&joyState);
                
                ying_updateCamera(&player,&camera);
                ying_renderWorld(&camera,grounds2,objects2,monsters2,texts2,&player,score,numGrounds2,numObjects2,numMonsters2,numTexts2);
                //al_draw_text(font_24, al_map_rgb(255, 0, 0), 100, 400, 0, "TEST");
                al_flip_display();
                break;
            case 3 :
                al_clear_to_color(al_map_rgb(0, 0, 0));  
                move_player(&player, grounds3, NUM_GROUNDS, &keyState , &joyState, &player_images);
                check_object_collision(objects3, &player, &score);
                moveMonster(monsters3);
                ying_attacking(&player,monsters3,&keyState,&joyState);

                ying_updateCamera(&player,&camera);
                ying_renderWorld(&camera,grounds3,objects3,monsters3,texts3,&player,score,numGrounds3,numObjects3,numMonsters3,numTexts3);
                //al_draw_text(font_24, al_map_rgb(255, 0, 0), 100, 400, 0, "TEST");
                al_flip_display();
                break;

            }
           
            // al_rest(0.016);  
        }
        //menu的程式
        else if(ev.type == ALLEGRO_EVENT_MENU_CLICK){
            printf("TSET");
            i = ying_MenuDecoder(&ev);
            if(i == 0){
                ying_Resoultion(&resolutionWidth,&resolutionHeigth,ev.user.data1,&camera,display);
            }
            else if(i == 1){

            }
            /*Reserve for External Function in Future*/
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
    }

    //資源釋放
    al_destroy_display(display);
    al_destroy_bitmap(chest_image);
    al_destroy_bitmap(reward_image);
    //al_destroy_bitmap(player_image);
    al_destroy_bitmap(monster_image);
    al_destroy_bitmap(checkpoint_image);
    al_destroy_event_queue(event_queue);
    al_destroy_sample_instance(coin);
    al_destroy_sample_instance(check);
    al_destroy_sample(sample1);
    al_destroy_sample(sample2);
    al_destroy_mixer(mixer);
    al_destroy_voice(voice);
    al_destroy_font(font_16);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_menu(Setting);
    al_destroy_menu(Game);
    al_uninstall_joystick();
    for (i = 0; i < playerImages; i++)
    {
        al_destroy_bitmap(player_images[i]);
    }
    return 0;
}

//Initialize the game objects 
Ground create_ground(double x, double y, double width, double height, ALLEGRO_COLOR color) {
    Ground ground = {x, y, width, height, color};
    return ground;
}



void draw_ground(Ground ground) {
    al_draw_filled_rectangle(ground.x, ground.y, ground.x + ground.width, ground.y + ground.height, ground.color);
}

void draw_player(Player player) {
    al_draw_scaled_bitmap(player.image,
                          0, 0,                                  // Source origin
                          al_get_bitmap_width(player.image),      // Source width
                          al_get_bitmap_height(player.image),     // Source height
                          player.x, player.y,                     // Destination origin
                          player.width, player.height,            // Destination width and height
                          0); 
}

