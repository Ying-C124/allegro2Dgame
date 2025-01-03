#include "myheader.h"

void all_initialize(){
        //初始化
    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_init_ttf_addon();

    //menu要加這個套件
    al_init_native_dialog_addon();

    //安裝搖桿驅動程式 
    if(!al_install_joystick())  
    {
        printf("cannot joystick");
    }
}
