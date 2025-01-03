#include "myheader.h"

void ying_setCamera(Camera* cameraInput,double windowWidth,double windowHeight){
    //camera左上角位置
    cameraInput->x = 0;
    cameraInput->y = 0;
    cameraInput->directionHorizonal = 1;    //初始向右 
    cameraInput->directionVertical = 0; //初始向下
    cameraInput->MoveHorizonal = -cameraMoveRange;  //初始化相機拉回的長度
    cameraInput->MoveVertical = 0;
    //待接入玩家初始位置
    cameraInput->cameraWidth = windowWidth;
    cameraInput->cameraHeight = windowHeight;
    cameraInput->needHoriTrans = false;
    cameraInput->needVertTrans = false;
    cameraInput->VerticalSpeed = 0;
}

void ying_updateCamera(Player *playerInput,Camera* cameraInput){
    //將鏡頭的位置以玩家的絕對位置做位移後為左上角

    if(playerInput->verticalSpeed > 0 ){
        if(playerInput->jumpingStatus == 1){
            if(cameraInput->needVertTrans == true){
                cameraInput->MoveVertical -= 8*cameraMoveMulti;
                if(cameraInput->MoveHorizonal <= 0) cameraInput->needVertTrans = false;
            }
            else{cameraInput->MoveVertical -=4*cameraMoveMulti;
            if((cameraInput->MoveVertical >=0)&& cameraInput->needVertTrans == false ) cameraInput->MoveVertical =0;
            }
        }
        if(playerInput->jumpingStatus == 0){
            cameraInput->MoveVertical -= 4*cameraMoveMulti;
            cameraInput->needVertTrans = true;
            if(cameraInput->MoveVertical <=-cameraMoveRange )cameraInput->MoveVertical =-cameraMoveRange;
        }   
    }
    else if(playerInput->verticalSpeed < 0){
        if(playerInput->jumpingStatus == 1){
            if(cameraInput->needVertTrans ==true ){
                cameraInput->MoveVertical += 8*cameraMoveMulti;
                if(cameraInput->MoveVertical >= 0) cameraInput->needVertTrans = false;
            }
            else cameraInput->MoveVertical += 4*cameraMoveMulti;
            if((cameraInput->MoveVertical <=0 ) && cameraInput->needVertTrans == false ) cameraInput->MoveVertical =0;
        }
        if(playerInput->jumpingStatus == 0){
            cameraInput->MoveVertical += 4*cameraMoveMulti;
            cameraInput->needVertTrans = true;
            if(cameraInput->MoveVertical >=cameraMoveRange ) cameraInput->MoveVertical =cameraMoveRange;
        }   
    }    


    if(cameraInput->MoveVertical !=0 ) cameraInput->MoveVertical = cameraInput->MoveVertical + cameraInput->VerticalSpeed;
    // printf("%lf",playerInput->verticalSpeed);
    // printf("    %lf",cameraInput->MoveVertical);

    if(playerInput->directionStatus == 1){
        if(playerInput->walkingStatus == 1){
            if(cameraInput->needHoriTrans == true){
                cameraInput->MoveHorizonal -= 4*cameraMoveMulti;
                if(cameraInput->MoveHorizonal <= 0) cameraInput->needHoriTrans = false;
            }
            else{cameraInput->MoveHorizonal +=2*cameraMoveMulti;
            if((cameraInput->MoveHorizonal >=0)&& cameraInput->needHoriTrans == false ) cameraInput->MoveHorizonal =0;
            }
        }
        if(playerInput->walkingStatus == 0){
            cameraInput->MoveHorizonal -= 2*cameraMoveMulti;
            cameraInput->needHoriTrans = true;
            if(cameraInput->MoveHorizonal <=-cameraMoveRange )cameraInput->MoveHorizonal =-cameraMoveRange;
        }   
    }
    else if(playerInput->directionStatus == 0){
        if(playerInput->walkingStatus == 1){
            if(cameraInput->needHoriTrans ==true ){
                cameraInput->MoveHorizonal += 4*cameraMoveMulti;
                if(cameraInput->MoveHorizonal >= 0) cameraInput->needHoriTrans = false;
            }
            else cameraInput->MoveHorizonal -= 2*cameraMoveMulti;
            if((cameraInput->MoveHorizonal <=0 ) && cameraInput->needHoriTrans == false ) cameraInput->MoveHorizonal =0;
        }
        if(playerInput->walkingStatus == 0){
            cameraInput->MoveHorizonal += 2*cameraMoveMulti;
            cameraInput->needHoriTrans = true;
            if(cameraInput->MoveHorizonal >=cameraMoveRange ) cameraInput->MoveHorizonal =cameraMoveRange;
        }   
    }

    cameraInput->x = playerInput->x - cameraInput->cameraWidth/2 + cameraInput->MoveHorizonal;
    
    cameraInput->y = playerInput->y - cameraInput->cameraHeight*4/8 - cameraInput->MoveVertical;

    //檢測是否遇到邊緣
    if(cameraInput->x < 0){
        cameraInput->x = 0;
    }
    else if(cameraInput->x > WORLD_WIDTH-cameraInput->cameraWidth){
        cameraInput->x = WORLD_WIDTH-cameraInput->cameraWidth;
    }

    if (cameraInput->y < WORLD_HEIGHT){
        cameraInput->y = WORLD_HEIGHT;
    }
    else if(cameraInput->y > WORLD_LOWEST - cameraInput->cameraHeight){
        cameraInput->y = WORLD_LOWEST - cameraInput->cameraHeight;
    }
}

void ying_applyTransform(Camera* cameraInput){
    ALLEGRO_TRANSFORM viewTransform;
    //標註目標轉移矩陣
    al_identity_transform(&viewTransform);

    //寫入移動量至矩陣
    al_translate_transform(&viewTransform,-cameraInput->x,-cameraInput->y);

    //套用變換矩陣
    al_use_transform(&viewTransform);
}

void ying_renderWorld(Camera* cameraInput,Ground groundInputs[],Object objectInputs[] ,Monster monsterInputs[], Text textInputs[],Player *playerInput,int score,
                      int numGrounds,int numObjects,int numMonsters,int numTexts){
    int i,j,k,m;
    Ground tempGround;
    Player tempPlayer;
    Object tempObject;
    Monster tempMonster;
    Text tempText;
    char scoreText[20];
    
    ying_applyTransform(cameraInput);
    for(i=0 ; i<numGrounds ; i++){
        if((groundInputs[i].x + groundInputs[i].width > cameraInput->x )&&
        (groundInputs[i].x < cameraInput->x+cameraInput->cameraWidth)&&
        (groundInputs[i].y + groundInputs[i].height > cameraInput->y)&&
        (groundInputs[i].y < cameraInput->y+cameraInput->cameraHeight))
        {
        tempGround = groundInputs[i];
        al_draw_filled_rectangle(tempGround.x, tempGround.y, tempGround.x + tempGround.width, tempGround.y + tempGround.height, tempGround.color);
        }
    }
    for(j=0 ; j<numObjects ; j++){
        if((objectInputs[j].x + objectInputs[j].width > cameraInput->x )&&
        (objectInputs[j].x < cameraInput->x+cameraInput->cameraWidth)&&
        (objectInputs[j].y + objectInputs[j].height > cameraInput->y)&&
        (objectInputs[j].y < cameraInput->y+cameraInput->cameraHeight))
        {
        tempObject = objectInputs[j];
        if(tempObject.isVisible == true)
            al_draw_scaled_bitmap(tempObject.image,
                                  0, 0,                                  // Source origin
                                  al_get_bitmap_width(tempObject.image),      // Source width
                                  al_get_bitmap_height(tempObject.image),     // Source height
                                  tempObject.x, tempObject.y,                     // Destination origin
                                  tempObject.width, tempObject.height,            // Destination width and height
                                  0);
        }
    }
    for(k=0 ; k<numMonsters ; k++){
        tempMonster = monsterInputs[k];
        if(tempMonster.isVisible == true)
            drawMonster(tempMonster);
    }
    for(m=0 ; m<numTexts ; m++){
        tempText = textInputs[m];
        al_draw_text(tempText.font, al_map_rgb(255, 255, 255), tempText.x, tempText.y, 0, tempText.displayText);
    }
    
    
    tempPlayer = *playerInput;
    /////////
    if(tempPlayer.direction == 1){
        al_draw_scaled_bitmap(tempPlayer.image,
                            0, 0,                                  // Source origin
                            al_get_bitmap_width(tempPlayer.image),      // Source width
                            al_get_bitmap_height(tempPlayer.image),     // Source height
                            tempPlayer.x, tempPlayer.y,                     // Destination origin
                            tempPlayer.width, tempPlayer.height,            // Destination width and height
                            0); 
    }
    if(tempPlayer.direction == 0){
        al_draw_scaled_bitmap(tempPlayer.image,
                            0, 0,                                  // Source origin
                            al_get_bitmap_width(tempPlayer.image),      // Source width
                            al_get_bitmap_height(tempPlayer.image),     // Source height
                            tempPlayer.x+tempPlayer.width, tempPlayer.y,                     // Destination origin
                            -tempPlayer.width, tempPlayer.height,            // Destination width and height
                            0); 
    }

    //////////
    sprintf(scoreText, "Score: %d", score);
    al_draw_text(textInputs[0].font, al_map_rgb(255, 255, 255),cameraInput->x + 10, cameraInput->y + 10, ALLEGRO_ALIGN_LEFT, scoreText);
}