#include <myheader.h>

Monster create_monster(double x, double y, double width, double height, double speed,
 ALLEGRO_BITMAP *image, int direction, int typeID,int movecount, bool isHit, bool isVisible,
 int HP){
    int MaxHP;
    MaxHP = HP;
    Monster monster = {x, y, width, height, speed, image, direction, typeID, movecount, isHit, isVisible , HP, MaxHP};
    return monster;
}

void drawMonster(Monster monster) {
    double rate;
    rate = (double)monster.HP/(double)monster.MaxHP;
    al_draw_filled_rectangle((monster.x+monster.width/2)-45,(monster.y-45),(monster.x+monster.width/2)+45,(monster.y-25),al_map_rgb(100,100,100));    //畫血條背景
    al_draw_filled_rectangle((monster.x+monster.width/2)-40,(monster.y-40),(monster.x+monster.width/2)-40+80*rate,(monster.y-30),al_map_rgb(200,100,100));
    if (monster.direction == 1 && monster.typeID == 1) {
         al_draw_scaled_bitmap(monster.image,
                               0, 0,                                  // Source origin
                               al_get_bitmap_width(monster.image),      // Source width
                               al_get_bitmap_height(monster.image),     // Source height
                               monster.x, monster.y,                     // Destination origin
                               monster.width, monster.height,            // Destination width and height
                               0); // 向右繪製小怪物
    } 
    else if ((monster.direction == 1 || monster.direction == -1) && monster.typeID == 2) {
         al_draw_scaled_bitmap(monster.image,
                               0, 0,                                  // Source origin
                               al_get_bitmap_width(monster.image),      // Source width
                               al_get_bitmap_height(monster.image),     // Source height
                               monster.x, monster.y,                     // Destination origin
                               monster.width, monster.height,            // Destination width and height
                               0); // 向右繪製小怪物
    } 
    else{
        al_draw_scaled_bitmap(monster.image,
                              0, 0,
                              al_get_bitmap_width(monster.image),
                              al_get_bitmap_height(monster.image),
                              monster.x + monster.width, 
                              monster.y,
                              -monster.width, 
                              monster.height,
                              0); // 向左繪製小怪物（翻轉）
        
        monster.x -= al_get_bitmap_width(monster.image); // 調整x坐標以防止重疊
    }
}

void moveMonster(Monster monsters[],int numMonsters){
    int i;
    for(i = 0; i<=numMonsters; i++)
    {
        switch(monsters[i].typeID)
        {
            case 1:
                monsters[i].moveCount += 1; 

                // 更新小怪物的位置
                monsters[i].x += monsters[i].speed * monsters[i].direction;

                // 檢查是否達到轉向間隔，如果達到則改變方向
                if (monsters[i].moveCount >= 60) {
                    monsters[i].direction *= -1; // 改變方向
                    monsters[i].moveCount = 0;   // 重置轉向時間
                }
                break;
            case 2:
                monsters[i].moveCount += 1; 

                // 更新小怪物的位置
                monsters[i].y += monsters[i].speed * monsters[i].direction;

                // 檢查是否達到轉向間隔，如果達到則改變方向
                if (monsters[i].moveCount >= 60) {
                    monsters[i].direction *= -1; // 改變方向
                    monsters[i].moveCount = 0;   // 重置轉向時間
                }
                break;
        }
    }
}

void monsterCollision(Monster monsters[],Player *player,int *monsterCD,int numMonsters){
    int i;
    *monsterCD -= 1;
    if(*monsterCD < 0){
        *monsterCD = 0;
    }   
    for(i = 0; i<=numMonsters;i++)
    {
        if (player->x < monsters[i].x + monsters[i].width && player->x + 30 > monsters[i].x &&
            player->y < monsters[i].y + monsters[i].height && player->y + player->height > monsters[i].y && monsters[i].HP>0 && *monsterCD == 0){
            player->HP -= 5;
            *monsterCD = 40;   
        }         
    }
    if(player->HP<= 0){

    }
}







