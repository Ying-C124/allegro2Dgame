#ifndef _STRUCTURE_H
#define _STRUCTURE_H

//This Header file is for DEFINE ALL THE STRUCTURE

// Define structures for the ground, chest, and rewards
typedef struct Ground{
    double x, y;
    double width, height;
    ALLEGRO_COLOR color;
} Ground;

typedef struct {
    double x, y;
    double checkpoint_x,checkpoint_y;
    double width, height;
    double horizonSpeed, verticalSpeed,g;
    int collisionHorizon,collisionVert;
    bool onGround;    
    bool walkingStatus;  //0無移動、1移動
    bool jumpingStatus; //1垂直移動中、0無移動
    bool directionStatus;    //方向 0是左 1是右
    ALLEGRO_BITMAP *image;
    int HP;
    int LV;
    int attackingStatus;
    int direction;
    int img_num;
    int frame_count;
    int prev_key;
    int MaxHP;
    bool MapEnable;
} Player;


typedef struct Object{
    double x, y;
    double width, height;
    ALLEGRO_BITMAP *image;
    int typeID;
    bool isHit;
    bool isVisible;
    bool audioTrigger;
    struct Object *bond;
    ALLEGRO_SAMPLE_INSTANCE *audio;
} Object;

typedef struct {
    double x, y;
    double width, height;
    double speed;
    //double HP;
    ALLEGRO_BITMAP *image;
    int typeID;
    int direction;
    int moveCount;
    bool isHit;
    bool isVisible;
    int HP;
    int MaxHP;
} Monster;

typedef struct {
    double x, y;
    char *displayText;
    ALLEGRO_FONT *font;
} Text;

#define playerImages 35
typedef struct BITMAPS
{
    ALLEGRO_BITMAP *chest_image;
    ALLEGRO_BITMAP *chest_image2;
    ALLEGRO_BITMAP *reward_image;
    ALLEGRO_BITMAP *checkpoint_image;
    ALLEGRO_BITMAP *checkpoint_image2;
    ALLEGRO_BITMAP *monster_image1; //if have another class of monster, please rename as monster_image2,etc...
    ALLEGRO_BITMAP *monster_image2;
    ALLEGRO_BITMAP *end_image;

    ALLEGRO_BITMAP *player_images[playerImages];
}MKBitmap;

//world structure define
typedef struct world
{
    int groundNum;  //Number of Ground in world
    Ground *groundAddress;  //The memory address of ground 

    int monsterNum; //Number of Monster in world
    Monster *monsterAddress;    //The memory address of monster

    int objectNum;  //Number of Object in world
    Object *objectAddress;  //The memory address of object

    int textNum;    //Number of Text in world
    Text *textAddress;    //The memory address of text
    
    MKBitmap *inputBitmaps;
} mkworld;



//ying_
typedef struct CameraView
{
    double x,y;
    double cameraWidth,cameraHeight;
    bool directionVertical; //1上2下
    bool directionHorizonal;    //1右2左
    double MoveVertical;
    double MoveHorizonal;
    double VerticalSpeed;
    bool needHoriTrans;
    bool needVertTrans;
}Camera;

typedef struct sound{
    ALLEGRO_SAMPLE *sample1;
    ALLEGRO_SAMPLE *sample2;
    ALLEGRO_SAMPLE *sample3;
    ALLEGRO_SAMPLE *sample4;
    ALLEGRO_SAMPLE_INSTANCE *check;
    ALLEGRO_SAMPLE_INSTANCE *coin;
    ALLEGRO_SAMPLE_INSTANCE *laser;
    ALLEGRO_SAMPLE_INSTANCE *chest;
    ALLEGRO_MIXER *mixer;
    ALLEGRO_VOICE *voice;
}MKSample;

typedef struct menu{
    ALLEGRO_MENU *mainMenu;
    ALLEGRO_MENU *Game;
    ALLEGRO_MENU *Setting;
    ALLEGRO_MENU *Resolution;

    ALLEGRO_MENU *LevelOption;

}MKMenu;


#endif 