#include "myheader.h"
#include "structure.h"


int main() {
    int resolutionWidth = 1600; 
    int resolutionHeigth = 900;

    all_initialize();
    Camera camera; 
    MKBitmap Bitmaps;   //The Structure For Bitmaps.
    MKSample Sounds;    //The Structure For Sound, Samples.
    MKMenu Menus;       //The Structure For Menus, Options.
    ALLEGRO_DISPLAY *display = al_create_display(resolutionWidth, resolutionHeigth);
    ALLEGRO_TIMER *timer = al_create_timer(0.016);
    ALLEGRO_FONT *font_16 = al_load_ttf_font("./score.TTC", 16, 0);
    ALLEGRO_KEYBOARD_STATE keyState;
    ALLEGRO_JOYSTICK_STATE joyState;
    ALLEGRO_JOYSTICK* joy1 = al_get_joystick(0);
    bool joyStickPluged = false;    //The bool for Check did jotstick install?
    bool Active = true;
    int score = 0;
    int i,Level;
    int CD = 40;
    ying_loadingBitmap(&Bitmaps);                           //inital and Load Bitmaps.
    leng_playerImgInit(Bitmaps.player_images,playerImages); //inital and Load the Animation for Player.
    ying_loadingSound(&Sounds);                             //inital and Load Sound,Samples.
    al_start_timer(timer); 
    al_set_window_title(display,"A New World!");
    //sample1 = al_load_sample("./pickup01.mp3");
    

    printf("level:");
    scanf("%d",&Level);

    mkworld world[NUM_WORLDS];  //The World Data Will Save As a array and Structure.
    createWorld(world,NUM_WORLDS,&Bitmaps,&Sounds);  //Make the main.c more clear. We move it to "world_generate.c" file.

    Player player = create_player(100, 100, 100, 100, 40, 40, 6.0, 0, 1.0, 0, 0 ,false, Bitmaps.player_images[0],20,1,1,0,0,0);
    
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

    int numTexts1 = sizeof(texts1) / sizeof(texts1[0]);
    int numTexts2 = sizeof(texts2) / sizeof(texts2[0]);
    int numTexts3 = sizeof(texts3) / sizeof(texts3[0]);
    

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_EVENT ev;
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_default_menu_event_source());
    al_register_event_source(event_queue, al_get_joystick_event_source());

    // ying_ Menu Setting
    ying_InitMenu(&Menus,display);

    //Detect Joystick
    joyStickPluged = load_joystick_info(joy1);


    //在這邊插入程式碼，主選單

    //

    //Inital Camera
    ying_setCamera(&camera,(double)resolutionWidth,(double)resolutionHeigth);

    while (Active) {
        al_wait_for_event(event_queue, &ev);
        ying_hotplug_detection(&ev,joy1,&joyStickPluged);
        if (ev.type == ALLEGRO_EVENT_TIMER){
            al_get_keyboard_state(&keyState);

            //Joystick Signal, If No Joystick plugin, Fill zero to Output;
            if(joyStickPluged){
                al_get_joystick_state(joy1,&joyState);
            }
            else{
                ying_joystickFillZero(&joyState);
            }
    
                al_clear_to_color(al_map_rgb(0, 0, 0));  
                move_player(&player, world[Level-1].groundAddress, world[Level-1].groundNum, &keyState , &joyState, Bitmaps.player_images);
                check_object_collision(world[Level-1].objectAddress, &player, &score,world[Level-1].objectNum);
                moveMonster(world[Level-1].monsterAddress);
                ying_attacking(&player,&world[Level-1] ,&keyState,&joyState,&CD,Bitmaps.player_images);
                ying_updateCamera(&player,&camera);
                ying_renderWorld(&camera,world[Level-1].groundAddress,world[Level-1].objectAddress,world[Level-1].monsterAddress,
                texts1,&player,score,
                world[Level-1].groundNum,world[Level-1].objectNum,world[Level-1].monsterNum,numTexts1);
                //al_draw_text(font_24, al_map_rgb(255, 0, 0), 100, 400, 0, "TEST");
                al_flip_display();
           
            // al_rest(0.016);  
        }

        //These are for Menu
        else if(ev.type == ALLEGRO_EVENT_MENU_CLICK){
            i = ying_MenuDecoder(&ev);
            if(i == 0){
                ying_Resoultion(&resolutionWidth,&resolutionHeigth,ev.user.data1,&camera,display);
            }
            else if(i == 1){
                ying_GameMenu(&ev,&player,&Active,&Level);
            }
            /*Reserve for External Function in Future*/
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
    }
    //Release the data in memory.
    al_destroy_display(display);

    releaseMemory(world,&Menus);

    al_destroy_bitmap(Bitmaps.checkpoint_image);
    al_destroy_bitmap(Bitmaps.chest_image);
    //al_destroy_bitmap(player_image);
    al_destroy_bitmap(Bitmaps.monster_image1);
    al_destroy_bitmap(Bitmaps.reward_image);
    al_destroy_event_queue(event_queue);
    al_destroy_sample_instance(Sounds.coin);
    al_destroy_sample_instance(Sounds.check);
    al_destroy_sample(Sounds.sample1);
    al_destroy_sample(Sounds.sample2);
    al_destroy_mixer(Sounds.mixer);
    al_destroy_voice(Sounds.voice);
    al_destroy_font(font_16);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_uninstall_joystick();
    for (i = 0; i < playerImages; i++)
    {
        al_destroy_bitmap(Bitmaps.player_images[i]);
    }
    return 0;
}