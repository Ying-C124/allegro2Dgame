#ifndef _MYHEADER_H_
#define _MYHEADER_H_

#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h> 
#include <string.h>
#include <stdint.h> //for utf
#include <inttypes.h> /* strtoimax */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//menu用ID
#define EXIT_ID 1223
#define CHANGE_RESOLUTION 1224
#define SPAWN 1225
#define BACK_TO_MENU 1226
#define SAVE_SCORE 1227
#define READ_SCORE_BOARD 1228

//menu用特殊解析度選項
#define VGA 1001
#define SVGA 1002
#define XGA 1003
#define HD 1004
#define FHD 1005
#define DUAL 1006
#define QUAD 1007


// Define constants
#define NUM_GROUNDS 20
#define NUM_OBJECTS 9
#define NUM_MONSTERS 20
#define NUM_TEXTS 8
//世界的邊緣，可能需要程式嫁接
#define WORLD_WIDTH 100500
#define WORLD_HEIGHT -3000
#define WORLD_LOWEST 1500
#define cameraMoveMulti 1    //(double)
#define cameraMoveRange 30
#define ATTACK_RANGE 150
#define ATTACK_ANIME_TIME 5
#define ATTACK_PER_LV 5

// Define structures for the ground, chest, and rewards
typedef struct {
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

// Function prototypes
Player create_player(double x, double y, double checkpoint_x,double checkpoint_y, double width, double height,
 double horizonSpeed, double verticalSpeed, double g, int collisionHorizon, int collisionVert,
  bool onGround ,ALLEGRO_BITMAP *image,int HP, int LV ,int direction,int img_num,int frame_count,int prev_key);
Ground create_ground(double x, double y, double width, double height, ALLEGRO_COLOR color);
// Chest create_chest(double x, double y, double width, double height, ALLEGRO_BITMAP *image);
// Reward create_reward(double x, double y, double width, double height, ALLEGRO_BITMAP *image);
// Checkpoint create_checkpoint(double x, double y, double width, double height, ALLEGRO_BITMAP *image);
Monster create_monster(double x, double y, double width, double height, double speed, ALLEGRO_BITMAP *image,
 int typeID, int direction, int moveCount, bool isHit, bool isVisible, int HP);
Object create_object(double x, double y, double width, double height, ALLEGRO_BITMAP *image, int typeID, bool isHit, bool isVisible,bool audioTrigger, Object* bond, ALLEGRO_SAMPLE_INSTANCE *audio);
Text create_text(double x, double y,char displayText[],ALLEGRO_FONT* font);
void draw_player(Player player);
void draw_ground(Ground ground);
void drawMonster(Monster monster);

// void draw_chest(Chest chest);
// void draw_reward(Reward reward);
// void draw_checkpoint(Checkpoint checkpoint);
// void draw_object(Checkpoint object);
void move_player(Player *player, Ground grounds[], int num_grounds, ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState,ALLEGRO_BITMAP *player_image_tmp[]);
void moveMonster(Monster monsters[]);
// void check_chest_collision(Chest *chest, Reward *reward, double player_x, double player_y);
// void check_checkpoint_collision(Checkpoint *checkpoint, Player *player);
void check_object_collision(Object object[], Player *player, int *score);
//all_
void all_initialize();

//leng
void leng_playerImgInit(ALLEGRO_BITMAP *player_images[],int playerImagesNum);

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

void ying_setCamera(Camera* cameraInput,double windowWidth,double windowHeight);
void ying_updateCamera(Player *playerInput,Camera* cameraInput);
void ying_applyTransform(Camera* cameraInput);
void ying_renderWorld(Camera* cameraInput,Ground groundInputs[], Object objectInputs[], Monster monsterInputs[], Text textInputs[], Player *playerInput, int score,int numGrounds,int numObjects,int numMonsters,int numTexts);

//ying_MenuResolution

int ying_MenuDecoder(ALLEGRO_EVENT *ev);
void ying_Resoultion(int *nativeWidth, int *nativeHeigth, int inputMenuID ,Camera *inputCamera, ALLEGRO_DISPLAY* inputDisplay);
//===

//ying_joystick
void print_joystick_log(ALLEGRO_EVENT *events);
bool load_joystick_info(ALLEGRO_JOYSTICK *joystick);
void ying_joystickFillZero(ALLEGRO_JOYSTICK_STATE *joyState);
void ying_hotplug_detection(ALLEGRO_EVENT *events,ALLEGRO_JOYSTICK *joystick,bool *joystickBool);

//ying_attack
void ying_attacking(Player *playerInput, Monster monsterInput[] , ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState);


ALLEGRO_SAMPLE_INSTANCE *createSound(ALLEGRO_SAMPLE *sample,ALLEGRO_MIXER *mixer,ALLEGRO_VOICE *voice);
#endif // _MYHEADER_H_