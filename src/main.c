#include "myheader.h"
#include "structure.h"


int main() {
    int resolutionWidth = 1600; 
    int resolutionHeigth = 900;

    //MultiPlayer
    int localPlayerIndex = 0;

    if (!init_enet()) return -1;

    ENetHost* networkHost = NULL;
    ENetPeer* peer = NULL;

// First try as client
    networkHost = create_client();
    if (!networkHost) {
        fprintf(stderr, "Failed to create client.\n");
        return -1;
    }
    ENetAddress address;
    enet_address_set_host(&address, "127.0.0.1");
    address.port = 1234;
    peer = enet_host_connect(networkHost, &address, 2, 0);

    bool isServer = false;
    bool isSinglePlayer = false;
    if (!peer) {
        isServer = true;
    } else {
        // Wait briefly to see if the connection succeeds
        ENetEvent event;
        if (enet_host_service(networkHost, &event, 5000) > 0) { //5s timeout
            if (event.type == ENET_EVENT_TYPE_CONNECT) {
                printf("Connected to server!\n");
                localPlayerIndex = 1; // Client player index
            } else {
                // Failed to connect; become server instead
                enet_peer_reset(peer);
                enet_host_destroy(networkHost);
                isServer = true;
            }
        } else {
            // Timed out
            enet_peer_reset(peer);
            enet_host_destroy(networkHost);
            isServer = true;
        }
    }

    if (isServer) {
        networkHost = create_server(1234);
        if (!networkHost) {
            fprintf(stderr, "Failed to create server.\n");
            return -1;
        }
        peer = NULL;
        printf("Server started.\n");

        // Wait for a client to connect with a timeout
        ENetEvent event;
        if (enet_host_service(networkHost, &event, 20000) > 0) { // 20 seconds timeout
            if (event.type == ENET_EVENT_TYPE_CONNECT) {
                printf("Client connected!\n");
                peer = event.peer;
            } else {
                printf("No client connected. Starting single-player game.\n");
                isSinglePlayer = true;
            }
        } else {
            printf("No client connected. Starting single-player game.\n");
            isSinglePlayer = true;
        }
    }

    all_initialize();
    Camera camera; 
    MKBitmap Bitmaps;   //The Structure For Bitmaps.
    MKSample Sounds;    //The Structure For Sound, Samples.
    MKMenu Menus;       //The Structure For Menus, Options.
    ALLEGRO_DISPLAY *display = al_create_display(resolutionWidth, resolutionHeigth);
    ALLEGRO_TIMER *timer = al_create_timer(0.016);
    ALLEGRO_FONT *font_16 = al_load_ttf_font("./score.TTC", 16, 0);
    ALLEGRO_FONT *font_48 = al_load_ttf_font("./score.TTC", 48, 0);
    ALLEGRO_KEYBOARD_STATE keyState;
    ALLEGRO_JOYSTICK_STATE joyState;
    ALLEGRO_MOUSE_STATE mouseState;
    ALLEGRO_JOYSTICK* joy1 = al_get_joystick(0);
    bool joyStickPluged = false;    //The bool for Check did jotstick install?
    bool Active = true;
    int score = 0;
    int i,Level;
    int CD = 40;
    int monsterCD = 40;
    int MapCD = 1;
    int ScoreBoardMaxNum;
    char name[16]={"TAILED"};
    bool menu_active = true,level_2_unlock = false,level_3_unlock = false,create = false;
    int button_state = 0;

// Initialize your game state
    GameState gameState;
    memset(&gameState, 0, sizeof(gameState));

    // For demonstration: first player is local
    gameState.players[0] = create_player(100, 100, 100, 100, 40, 40, 6.0, 0, 1.0, 0, 0, false,
                                         NULL, 20, 1, 1, 0, 0, 0);
    // Second player starts at different coords
    gameState.players[1] = create_player(300, 100, 300, 100, 40, 40, 6.0, 0, 1.0, 0, 0, false,
                                         NULL, 20, 1, 1, 0, 0, 0);

    ying_loadingBitmap(&Bitmaps);                           //inital and Load Bitmaps.
    leng_playerImgInit(Bitmaps.player_images,playerImages); //inital and Load the Animation for Player.
    ying_loadingSound(&Sounds);                             //inital and Load Sound,Samples.
    al_start_timer(timer); 
    al_set_window_title(display,"A New World!");
    //sample1 = al_load_sample("./pickup01.mp3");

    MkScoreBoard scoreboard[MaxOfScoreBoard];
    Node Scorehead ;
    strncpy(Scorehead.name,name,sizeof(name)-1);
    Scorehead.score = 0;
    Scorehead.nextPtr = NULL;

    load_score(&Scorehead);
    ScoreBoard(&Scorehead,&scoreboard,&ScoreBoardMaxNum);
    printf("%s\t%d\n",Scorehead.name,Scorehead.score);

    // Assign images to players
    gameState.players[0].image = Bitmaps.player_images[0];
    gameState.players[1].image = Bitmaps.player_images[0];

    printf("level:\n");
    // scanf("%d",&Level);
    Level = 1;

    mkworld world[NUM_WORLDS];  //The World Data Will Save As a array and Structure.
    createWorld(world,NUM_WORLDS,&Bitmaps,&Sounds,font_16);  //Make the main.c more clear. We move it to "world_generate.c" file.

    Player player = create_player(100, 100, 100, 100, 40, 40, 6.0, 0, 1.0, 0, 0 ,false, Bitmaps.player_images[0],20,1,1,0,0,0);
    
    

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

    //Inital Camera
    ying_setCamera(&camera,(double)resolutionWidth,(double)resolutionHeigth);

    //EnterName Must after than setCamera;
    EnterName(name,&keyState,&ev,event_queue,&camera,font_16);

    while (Active) {
        al_wait_for_event(event_queue, &ev);
        ying_hotplug_detection(&ev,joy1,&joyStickPluged);
        if (menu_active == true){
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_get_mouse_state(&mouseState);
            //////
            // if(button_state == 0)
            //     button_state = openMenu(&camera,&menu_active,&mouseState,font_48);
            // else if(button_state == 1){
            //     button_state = openMenu2(&camera,&menu_active,&mouseState,font_48,&level_2_unlock,&level_3_unlock);
            //     if(button_state == 5){
            //         menu_active = false;
            //         Level = 1;
            //     }
            //     else if(button_state == 6){
            //         menu_active = false;
            //         Level = 2;
            //     }
            //     else if(button_state == 7){
            //         menu_active = false;
            //         Level = 3;
            //     }    
            // }
            //////
            create = menuLogic(&player,&button_state,&Level,&camera,&menu_active,&mouseState,font_48,&level_2_unlock,&level_3_unlock,&score,&ScoreBoardMaxNum,scoreboard,&Active);
            if (create == true){
                createWorld(world,NUM_WORLDS,&Bitmaps,&Sounds,font_16);
                create == false;
            }
            //////
            al_flip_display();
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
                break;
            else if(ev.type == ALLEGRO_EVENT_MENU_CLICK){
                i = ying_MenuDecoder(&ev);
                if(i == 0){
                    ying_Resoultion(&resolutionWidth,&resolutionHeigth,ev.user.data1,&camera,display);
                }
                else if(i == 1){
                    ying_GameMenu(&ev,&player,&Active,&Level,&menu_active,&button_state,score,scoreboard,&Scorehead,name);
                }
                /*Reserve for External Function in Future*/
            }
        }    
        else if (ev.type == ALLEGRO_EVENT_TIMER){
            al_get_keyboard_state(&keyState);

            //Joystick Signal, If No Joystick plugin, Fill zero to Output;
            if(joyStickPluged){
                al_get_joystick_state(joy1,&joyState);
            }
            else{
                ying_joystickFillZero(&joyState);
            }
                
                al_clear_to_color(al_map_rgb(0, 0, 0));  
                move_player(&player, world[Level-1].groundAddress, world[Level-1].groundNum, world[Level-1].objectAddress, world[Level-1].objectNum, &keyState , &joyState, Bitmaps.player_images);
                check_object_collision(world[Level-1].objectAddress, &player, &score,world[Level-1].objectNum,&Bitmaps,&Level,&level_2_unlock,&level_3_unlock,&Scorehead,name,&menu_active,&button_state);
                moveMonster(world[Level-1].monsterAddress,world[Level-1].monsterNum);
                monsterCollision(world[Level-1].monsterAddress,&player,&monsterCD,world[Level-1].monsterNum,&score);
                ying_attacking(&player,&world[Level-1] ,&keyState,&joyState,&CD,Bitmaps.player_images,&score,&Sounds);
                ying_updateCamera(&player,&camera);
                ying_renderWorld(&camera,world[Level-1].groundAddress,world[Level-1].objectAddress,world[Level-1].monsterAddress,
                world[Level-1].textAddress,&player,score,
                world[Level-1].groundNum,world[Level-1].objectNum,world[Level-1].monsterNum,world[Level-1].textNum);
                //al_draw_text(font_24, al_map_rgb(255, 0, 0), 100, 400, 0, "TEST");
                
                printf("%d\n",&gameState.players[localPlayerIndex].HP);
                
                if (!isSinglePlayer) {
                 // Send local player info
                send_player_state(networkHost, peer, &gameState.players[localPlayerIndex], localPlayerIndex);

                // Receive remote updates
                receive_updates(networkHost, &gameState);

                // Draw the remote player if the image is not NULL
                int remotePlayerIndex = (localPlayerIndex == 0) ? 1 : 0;
                if (gameState.players[remotePlayerIndex].image != NULL) {
                    draw_player(gameState.players[remotePlayerIndex]);
                }


            }


                
                Map(&camera,&player,&world[Level-1],&keyState,&joyState,&MapCD,&Bitmaps);

                printf("%d\n",player.HP);
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
                ying_GameMenu(&ev,&player,&Active,&Level,&menu_active,&button_state,score,scoreboard,&Scorehead,name);
            }
            /*Reserve for External Function in Future*/
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
    }
    
    //Release the data in memory.
    al_destroy_display(display);
    printf("%s\t%d\n",Scorehead.name,Scorehead.score);
    save_score(&Scorehead);

    releaseMemory(world,&Menus,&scoreboard);

    al_destroy_bitmap(Bitmaps.checkpoint_image);
    al_destroy_bitmap(Bitmaps.chest_image);
    //al_destroy_bitmap(player_image);
    al_destroy_bitmap(Bitmaps.monster_image1);
    al_destroy_bitmap(Bitmaps.reward_image);
    al_destroy_bitmap(Bitmaps.world_map_lowRes);
    al_destroy_bitmap(Bitmaps.world_map_mediumRes);
    al_destroy_bitmap(Bitmaps.world_map_highRes);
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