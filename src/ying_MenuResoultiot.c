#include "myheader.h"


int ying_MenuDecoder(ALLEGRO_EVENT *ev){
    if(ev->user.data1 ==VGA||
    ev->user.data1 ==SVGA||
    ev->user.data1 ==XGA||
    ev->user.data1 ==HD||
    ev->user.data1 ==FHD||
    ev->user.data1 ==DUAL||
    ev->user.data1 ==QUAD) return 0;
    else {
        return 1;
    }
}

void ying_Resoultion(int *nativeWidth, int *nativeHeigth, int inputMenuID,Camera *inputCamera, ALLEGRO_DISPLAY* inputDisplay){
    int settingWidth;
    int settingHeigth;
    switch (inputMenuID)
    {
    case VGA:
        settingWidth = 640;
        settingHeigth = 480;
        break;
    case SVGA:
        settingWidth = 800;
        settingHeigth = 600;
        break;
    case XGA:
        settingWidth = 1024;
        settingHeigth = 768;
        break;
    case HD:
        settingWidth = 1280;
        settingHeigth = 720;
        break;
    case FHD:
        settingWidth = 1920;
        settingHeigth = 1080;
        break;
    case DUAL:
        settingWidth = 2560;
        settingHeigth = 1440;
        break;
    case QUAD:
        settingWidth = 3840;
        settingHeigth = 2160;
        break;
    default:
        break;
    }
    al_resize_display(inputDisplay,settingWidth,settingHeigth);
    *nativeWidth = settingWidth;
    *nativeHeigth = settingHeigth;
    inputCamera->cameraWidth = settingWidth;
    inputCamera->cameraHeight = settingHeigth;
}

void ying_GameMenu(){

}