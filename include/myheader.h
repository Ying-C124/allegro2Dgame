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

#include "define.h"
#include "structure.h"

// Function prototypes
Player create_player(double x, double y, double checkpoint_x,double checkpoint_y, double width, double height,
 double horizonSpeed, double verticalSpeed, double g, int collisionHorizon, int collisionVert,
  bool onGround ,ALLEGRO_BITMAP *image,int HP, int LV ,int direction,int img_num,int frame_count,int prev_key);
Ground create_ground(double x, double y, double width, double height, ALLEGRO_COLOR color);
Monster create_monster(double x, double y, double width, double height, double speed, ALLEGRO_BITMAP *image,
 int typeID, int direction, int moveCount, bool isHit, bool isVisible, int HP);
Object create_object(double x, double y, double width, double height, ALLEGRO_BITMAP *image, int typeID, bool isHit, bool isVisible,bool audioTrigger, Object* bond, ALLEGRO_SAMPLE_INSTANCE *audio);
Text create_text(double x, double y,char displayText[],ALLEGRO_FONT* font);
void draw_player(Player player);
void draw_ground(Ground ground);
void drawMonster(Monster monster);
void monsterCollision(Monster monsters[],Player *player,int *monsterCD,int numMonsters);
void move_player(Player *player, Ground grounds[], int num_grounds,Object objects[], int num_objects, ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState,ALLEGRO_BITMAP *player_image_tmp[]);
void moveMonster(Monster monsters[],int numMonsters);
void check_object_collision(Object object[], Player *player, int *score,int objectNum,MKBitmap *inputBitmaps);

//all_
void all_initialize();

//leng
void leng_playerImgInit(ALLEGRO_BITMAP *player_images[],int playerImagesNum);

//ying_camera
void ying_setCamera(Camera* cameraInput,double windowWidth,double windowHeight);
void ying_updateCamera(Player *playerInput,Camera* cameraInput);
void ying_applyTransform(Camera* cameraInput);
void ying_renderWorld(Camera* cameraInput,Ground groundInputs[], Object objectInputs[], Monster monsterInputs[], Text textInputs[], Player *playerInput, int score,int numGrounds,int numObjects,int numMonsters,int numTexts);

//ying_MenuResolution
int ying_MenuDecoder(ALLEGRO_EVENT *ev);
void ying_Resoultion(int *nativeWidth, int *nativeHeigth, int inputMenuID ,Camera *inputCamera, ALLEGRO_DISPLAY* inputDisplay);
void ying_GameMenu(ALLEGRO_EVENT *ev,Player *inputPlayer,bool *inputActive,int *inputLevel);
void ying_ResetPlayerLocal(Player *inputPlayer);

//ying_joystick
void print_joystick_log(ALLEGRO_EVENT *events);
bool load_joystick_info(ALLEGRO_JOYSTICK *joystick);
void ying_joystickFillZero(ALLEGRO_JOYSTICK_STATE *joyState);
void ying_hotplug_detection(ALLEGRO_EVENT *events,ALLEGRO_JOYSTICK *joystick,bool *joystickBool);

//ying_attack
void ying_attacking(Player *playerInput, mkworld* inputWorld , ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState, int *CD,ALLEGRO_BITMAP *inputplayerImage[], int* score,MKSample *inputSamples);

//ying_Map
void Map(Camera *camera,Player *player, mkworld *world, ALLEGRO_KEYBOARD_STATE *keyState,ALLEGRO_JOYSTICK_STATE *JoyState,int *CD,MKBitmap *bitmaps);

ALLEGRO_SAMPLE_INSTANCE *createSound(ALLEGRO_SAMPLE *sample,ALLEGRO_MIXER *mixer,ALLEGRO_VOICE *voice);

void ying_loadingBitmap(MKBitmap *inputBitmaps);
void ying_loadingSound(MKSample *inputSounds);
void ying_InitMenu(MKMenu *inputMenu,ALLEGRO_DISPLAY *inputDisplay);

void createWorld(mkworld world[],int worldNum,MKBitmap *inputBitmaps,MKSample *inputSamples, ALLEGRO_FONT *font_16);

void createGround1(Ground *inputGroundAddress);
void createObject1(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples);
void createMonster1(Monster *inputMonsterAddress,MKBitmap *inputBitmaps);
void createText1(Text *inputTextAddress ,ALLEGRO_FONT *font_16);
void createGround2(Ground *inputGroundAddress);
void createObject2(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples);
void createMonster2(Monster *inputMonsterAddress,MKBitmap *inputBitmaps);
void createText2(Text *inputTextAddress ,ALLEGRO_FONT *font_16);
void createGround3(Ground *inputGroundAddress);
void createObject3(Object *inputObjectAddress,MKBitmap *inputBitmaps,MKSample *inputSamples);
void createMonster3(Monster *inputMonsterAddress,MKBitmap *inputBitmaps);
void createText3(Text *inputTextAddress ,ALLEGRO_FONT *font_16);

void releaseMemory(mkworld inputworld[],MKMenu *inputMenu);

#endif /* _MYHEADER_H_ */