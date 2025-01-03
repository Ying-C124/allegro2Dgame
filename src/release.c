#include "myheader.h"

void releaseMemory(mkworld inputworld[],MKMenu *inputMenu){
    int i;
    
    for(i=0 ; i<NUM_WORLDS;i++){
        if (inputworld[i].groundAddress != NULL) {
            free(inputworld[i].groundAddress);
            inputworld[i].groundAddress = NULL;
        }
        if (inputworld[i].objectAddress != NULL) {
            free(inputworld[i].objectAddress);
            inputworld[i].objectAddress = NULL;
        }
        if (inputworld[i].monsterAddress != NULL) {
            free(inputworld[i].monsterAddress);
            inputworld[i].monsterAddress = NULL;
        }
    }
    al_destroy_menu(inputMenu->Game);
    al_destroy_menu(inputMenu->Resolution);
    al_destroy_menu(inputMenu->Setting);
    al_destroy_menu(inputMenu->LevelOption);
}