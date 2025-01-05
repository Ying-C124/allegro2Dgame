#include "myheader.h"
#include "structure.h"

int openMenu(Player *playerInput,Camera* cameraInput,bool* menu_active,ALLEGRO_MOUSE_STATE* mouseState,ALLEGRO_FONT *font_48,int *score){
    double button_width = 500;
    double button_height = 50;

    al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8-button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-5*button_height/2,
                             cameraInput->x+cameraInput->cameraWidth*4/8+button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-3*button_height/2,al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8-button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-button_height/2,
                             cameraInput->x+cameraInput->cameraWidth*4/8+button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+button_height/2,al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8-button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+3*button_height/2,
                             cameraInput->x+cameraInput->cameraWidth*4/8+button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+5*button_height/2,al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8-button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+7*button_height/2,
                             cameraInput->x+cameraInput->cameraWidth*4/8+button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+9*button_height/2,al_map_rgb(255, 255, 255));
    al_draw_text(font_48, al_map_rgb(0, 255, 0),cameraInput->x+cameraInput->cameraWidth*4/8-100,cameraInput->y+cameraInput->cameraHeight*4/8-9*button_height/2, ALLEGRO_ALIGN_LEFT,"2D GAME!");
    al_draw_text(font_48, al_map_rgb(190, 190, 0),cameraInput->x+cameraInput->cameraWidth*4/8-50,cameraInput->y+cameraInput->cameraHeight*4/8-5*button_height/2, ALLEGRO_ALIGN_LEFT,"Play");
    al_draw_text(font_48, al_map_rgb(0, 190, 190),cameraInput->x+cameraInput->cameraWidth*4/8-168,cameraInput->y+cameraInput->cameraHeight*4/8-button_height/2, ALLEGRO_ALIGN_LEFT,"Continue level");
    al_draw_text(font_48, al_map_rgb(190, 0, 190),cameraInput->x+cameraInput->cameraWidth*4/8-120,cameraInput->y+cameraInput->cameraHeight*4/8+3*button_height/2, ALLEGRO_ALIGN_LEFT,"Player rank");
    al_draw_text(font_48, al_map_rgb(190, 190, 190),cameraInput->x+cameraInput->cameraWidth*4/8-50,cameraInput->y+cameraInput->cameraHeight*4/8+7*button_height/2, ALLEGRO_ALIGN_LEFT,"Quit");
    if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->cameraWidth*4/8-button_width/2 && mouseState->x<=cameraInput->cameraWidth*4/8+button_width/2
                                            && mouseState->y>=cameraInput->cameraHeight*4/8-5*button_height/2 && mouseState->y<=cameraInput->cameraHeight*4/8-3*button_height/2) {
        playerInput->HP = 20;
        playerInput->x = 100;
        playerInput->y = 100;
        playerInput->checkpoint_x = 100;
        playerInput->checkpoint_y = 100;
        return 1;
    }
    else if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->cameraWidth*4/8-button_width/2 && mouseState->x<=cameraInput->cameraWidth*4/8+button_width/2
                                                 && mouseState->y>=cameraInput->cameraHeight*4/8-button_height/2 && mouseState->y<=cameraInput->cameraHeight*4/8+button_height/2) {
        return 2;
    }
    else if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->cameraWidth*4/8-button_width/2 && mouseState->x<=cameraInput->cameraWidth*4/8+button_width/2
                                                 && mouseState->y>=cameraInput->cameraHeight*4/8+3*button_height/2 && mouseState->y<=cameraInput->cameraHeight*4/8+5*button_height/2) {
        return 3;
    }
    else if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->cameraWidth*4/8-button_width/2 && mouseState->x<=cameraInput->cameraWidth*4/8+button_width/2
                                                 && mouseState->y>=cameraInput->cameraHeight*4/8+7*button_height/2 && mouseState->y<=cameraInput->cameraHeight*4/8+9*button_height/2) {
        return 4;
    }
    else{
        return 0;
    }
    return 0;
}
int openMenu2(Player *playerInput,Camera* cameraInput,bool* menu_active,ALLEGRO_MOUSE_STATE* mouseState,ALLEGRO_FONT* font_48,bool* level_2_unlock,bool* level_3_unlock,int *score){
    double button_width = 100;
    double button_height = 100;
    al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8-5*button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-button_height/2,
                             cameraInput->x+cameraInput->cameraWidth*4/8-3*button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+button_height/2,al_map_rgb(255, 255, 255));
    al_draw_text(font_48, al_map_rgb(255, 0, 0),cameraInput->x+cameraInput->cameraWidth*4/8-4*button_width/2-10,cameraInput->y+cameraInput->cameraHeight*4/8-20, ALLEGRO_ALIGN_LEFT,"1");
    if(*level_2_unlock == true){
        al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8-button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-button_height/2,
                                cameraInput->x+cameraInput->cameraWidth*4/8+button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+button_height/2,al_map_rgb(255, 255, 255));
        al_draw_text(font_48, al_map_rgb(0, 255, 0),cameraInput->x+cameraInput->cameraWidth*4/8-10,cameraInput->y+cameraInput->cameraHeight*4/8-20, ALLEGRO_ALIGN_LEFT,"2");
    }
    else{
        al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8-button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-button_height/2,
                                cameraInput->x+cameraInput->cameraWidth*4/8+button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+button_height/2,al_map_rgb(128, 128, 128));
        al_draw_text(font_48, al_map_rgb(0, 0, 0),cameraInput->x+cameraInput->cameraWidth*4/8-10,cameraInput->y+cameraInput->cameraHeight*4/8-20, ALLEGRO_ALIGN_LEFT,"?");
    }
    if(*level_3_unlock == true){
        al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8+3*button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-button_height/2,
                                cameraInput->x+cameraInput->cameraWidth*4/8+5*button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+button_height/2,al_map_rgb(255, 255, 255));
        al_draw_text(font_48, al_map_rgb(0, 0, 255),cameraInput->x+cameraInput->cameraWidth*4/8+4*button_width/2-10,cameraInput->y+cameraInput->cameraHeight*4/8-20, ALLEGRO_ALIGN_LEFT,"3");
    }
    else{
        al_draw_filled_rectangle(cameraInput->x+cameraInput->cameraWidth*4/8+3*button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8-button_height/2,
                                cameraInput->x+cameraInput->cameraWidth*4/8+5*button_width/2,cameraInput->y+cameraInput->cameraHeight*4/8+button_height/2,al_map_rgb(128, 128, 128));
        al_draw_text(font_48, al_map_rgb(0, 0, 0),cameraInput->x+cameraInput->cameraWidth*4/8+4*button_width/2-10,cameraInput->y+cameraInput->cameraHeight*4/8-20, ALLEGRO_ALIGN_LEFT,"?");
    }
    al_draw_filled_rectangle(cameraInput->x,cameraInput->y,
                             cameraInput->x+50,cameraInput->y+50,al_map_rgb(255, 255, 255));
    al_draw_text(font_48, al_map_rgb(128, 128, 128),cameraInput->x+cameraInput->cameraWidth*4/8-150,cameraInput->y+cameraInput->cameraHeight*4/8-150, ALLEGRO_ALIGN_LEFT,"Choose level");
    al_draw_text(font_48, al_map_rgb(0, 0, 0),cameraInput->x+13,cameraInput->y, ALLEGRO_ALIGN_LEFT,"X");
    if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->cameraWidth*4/8-5*button_width/2 && mouseState->x<=cameraInput->cameraWidth*4/8-3*button_width/2
                                            && mouseState->y>=cameraInput->cameraHeight*4/8-button_height/2 && mouseState->y<=cameraInput->cameraHeight*4/8+button_height/2) {
        playerInput->HP = 20;
        playerInput->x = 100;
        playerInput->y = 100;
        playerInput->checkpoint_x = 100;
        playerInput->checkpoint_y = 100;
        return 5;
    }
    else if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->cameraWidth*4/8-button_width/2 && mouseState->x<=cameraInput->cameraWidth*4/8+button_width/2
                                                 && mouseState->y>=cameraInput->cameraHeight*4/8-button_height/2 && mouseState->y<=cameraInput->cameraHeight*4/8+button_height/2 && *level_2_unlock == true) {
        playerInput->HP = 20;
        playerInput->x = 100;
        playerInput->y = 100;
        playerInput->checkpoint_x = 100;
        playerInput->checkpoint_y = 100;
        return 6;
    }
    else if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->cameraWidth*4/8+3*button_width/2 && mouseState->x<=cameraInput->cameraWidth*4/8+5*button_width/2
                                                 && mouseState->y>=cameraInput->cameraHeight*4/8-button_height/2 && mouseState->y<=cameraInput->cameraHeight*4/8+button_height/2 && *level_3_unlock == true) {
        playerInput->HP = 20;
        playerInput->x = 100;
        playerInput->y = 100;
        playerInput->checkpoint_x = 100;
        playerInput->checkpoint_y = 100;
        return 7;
    }
    else if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->x && mouseState->x<=cameraInput->x+50
                                                 && mouseState->y>=cameraInput->y && mouseState->y<=cameraInput->y+50) {
        return 0;
    }
    return 2;
}

int openMenu3(Camera* cameraInput,bool* menu_active,ALLEGRO_MOUSE_STATE* mouseState,ALLEGRO_FONT* font_48,int *ScoreBoardNum,MkScoreBoard *inputScoreBoard){
    double button_width = 100;
    double button_height = 100;
    al_draw_filled_rectangle(cameraInput->x,cameraInput->y,
                             cameraInput->x+50,cameraInput->y+50,al_map_rgb(255, 255, 255));
    al_draw_text(font_48, al_map_rgb(0, 0, 0),cameraInput->x+13,cameraInput->y, ALLEGRO_ALIGN_LEFT,"X");
    printScoreBoard(*ScoreBoardNum,inputScoreBoard,cameraInput,font_48);
    if (al_mouse_button_down(mouseState, 1) && mouseState->x>=cameraInput->x && mouseState->x<=cameraInput->x+50
                                                 && mouseState->y>=cameraInput->y && mouseState->y<=cameraInput->y+50) {
        return 0;
    }
    return 3;
}


bool menuLogic(Player *playerInput,int* button_state,int* Level,Camera* camera,bool* menu_active,ALLEGRO_MOUSE_STATE* mouseState,ALLEGRO_FONT* font_48,bool* level_2_unlock,bool* level_3_unlock,int *score,int *ScoreBoardNum,MkScoreBoard *inputScoreBoard,bool *ProgramActive){
    if(*button_state == 0)
        *button_state = openMenu(playerInput,camera,menu_active,mouseState,font_48,score);
    else if(*button_state == 1){
        *menu_active = false;
        *Level = 1;
        *score = 0;
        return true;
    }
    else if(*button_state == 2){
        *button_state = openMenu2(playerInput,camera,menu_active,mouseState,font_48,level_2_unlock,level_3_unlock,score);
        if(*button_state == 5){
            *menu_active = false;
            *Level = 1;
            *score = 0;
            return true;
        }
        else if(*button_state == 6){
            *menu_active = false;
            *Level = 2;
            *score = 0;
            return true;
        }
        else if(*button_state == 7){
            *menu_active = false;
            *Level = 3;
            *score = 0;
            return true;
        }    
    }
    else if(*button_state == 3){
        *button_state = openMenu3(camera,menu_active,mouseState,font_48,ScoreBoardNum,inputScoreBoard);
        return true;
    }
    else if(*button_state == 4){
        *ProgramActive = false;
        return true;
    }
    return false;
}
