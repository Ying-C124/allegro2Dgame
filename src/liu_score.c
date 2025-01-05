#include "myheader.h"

/* Insert a new value into the list in sorted order */
void insert( Node *sPtr, char newName[16] ,int score)
{
   Node  *newPtr; /* pointer to new node */
   Node  *previousPtr; /* pointer to previous node in list */
   Node  *currentPtr; /* pointer to current node in list */

   newPtr = malloc( sizeof( Node ) ); /* create node */

   if (newPtr == NULL) {
    fprintf(stderr, "Error: Memory allocation failed for new node.\n");
    return;
   }
    strncpy(newPtr->name, newName, sizeof(newPtr->name) - 1);
    newPtr->name[sizeof(newPtr->name) - 1] = '\0'; // Ensure null-terminated
    newPtr->score = score;
    newPtr->nextPtr = NULL;

    previousPtr = NULL;
    currentPtr = sPtr;

    // Find the correct location
    while (currentPtr != NULL && score > currentPtr->score) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr == NULL) { // Insert at the beginning
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    } else { // Insert in the middle or end
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
}


//原code:liu    改Link List:ying
void save_score(Node *inputNode) { 
    FILE *file = fopen(SCORE_FILE, "w");
    
    if (file != NULL) {
        while(inputNode != NULL){
            fprintf(file, "%-16s\t%d\n",inputNode->name,inputNode->score);
            inputNode = inputNode->nextPtr;  // Move to the next node
        }
        fclose(file);
        printf("Save file: '%s'!\n", SCORE_FILE);
    } else {
        printf("Can't Open file to save\n");
    }
}


/* Load scores from a file into a linked list */
void load_score(Node *sPtr) {
    FILE *file = fopen(SCORE_FILE, "r");
    char name[16];  // 暫存名稱
    int score;      // 暫存分數
    int line = 0;

    if (file != NULL) {
        while (fscanf(file, "%16s\t%d", name, &score) == 2) {
            // 將讀取的名稱與分數插入鏈結串列
            insert(sPtr, name, score);
            line++;
        }
        if (line == 0) {
        printf("Warning: No valid data found in file.\n");
        insert(sPtr,"tailed",0);
        printf("%s\t,%d\n",sPtr->name,sPtr->score);
        }
        else{
            printf("Read form '%s'!\n", SCORE_FILE);
        }
        fclose(file);  // 關閉檔案
    } else {
        printf("Can't Open and Create!\n");
    }
}

void free_list(NodePtr *sPtr) {
    NodePtr tempPtr;
    while (*sPtr != NULL) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
    }
}

void EnterName(char inputName[16] , ALLEGRO_KEYBOARD_STATE *keyState , ALLEGRO_EVENT *ev, ALLEGRO_EVENT_QUEUE *event_queue,Camera *cameraInput,ALLEGRO_FONT *font_16){
    bool Active = true;
    char name[16]={0};

    char title[]={"Please Enter Name, you are allow close windows only after enter name."};
    while(Active){
        al_wait_for_event(event_queue, ev);
        if (ev->type == ALLEGRO_EVENT_KEY_CHAR) {
            if (strlen(name) < 16) {
                if (ev->keyboard.unichar >= 32 && ev->keyboard.unichar <= 126) {
                    // Add valid character to the name
                    int len = strlen(name);
                    name[len] = (char)ev->keyboard.unichar;
                    name[len + 1] = '\0';
                }
            }
        if (ev->keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(name) > 0) {
                // Remove the last character
                name[strlen(name) - 1] = '\0';
            }

            if (ev->keyboard.keycode == ALLEGRO_KEY_ENTER) {
                // User pressed Enter, finalize input
                Active = false;
            }
        }
        al_clear_to_color(al_map_rgb(0, 0, 0)); // 清空畫面
        al_draw_text(font_16, al_map_rgb(255, 255, 255),cameraInput->x + cameraInput->cameraWidth/2-15, cameraInput->y +cameraInput->cameraHeight/2, ALLEGRO_ALIGN_LEFT, name);
        al_draw_text(font_16, al_map_rgb(255, 255, 255),cameraInput->x + cameraInput->cameraWidth/2-180, cameraInput->y +cameraInput->cameraHeight/2-20, ALLEGRO_ALIGN_LEFT, title);
        al_flip_display(); // 更新畫面
    }
    strncpy(inputName, name, 16); 
    inputName[15] = '\0'; 
}


void ScoreBoard(Node *inputNode,MkScoreBoard inputScoreBoard[],int *ScoreBoardMaxNum){
    int max=1;
    int i;
    int nowRank;
    int printNum;
    Node tempNode = *inputNode;

    while(tempNode.nextPtr != NULL){
        max++;
        tempNode = *tempNode.nextPtr;
    }
    
    if(max < MaxOfScoreBoard)    printNum = max;
    else    printNum = MaxOfScoreBoard;
    
    inputScoreBoard->Num = printNum;

    tempNode = *inputNode;
    *ScoreBoardMaxNum = printNum;

    for(i=0;i<max;i++){
        if((max-i)<=printNum){
            strncpy(inputScoreBoard[max-i-1].NameAddress,tempNode.name,(sizeof(inputScoreBoard[0].NameAddress)-1));
            inputScoreBoard[max-i-1].ScoreAddress = tempNode.score;
        }
        if(tempNode.nextPtr != NULL) tempNode = *tempNode.nextPtr;
    }
}

#define RANGE 54
#define StartPoint 120
void printScoreBoard(int printNum,MkScoreBoard inputScoreBoard[],Camera *inputCamera,ALLEGRO_FONT* font_48){
    char inputText[50];
    int i;
    al_draw_text(font_48,al_map_rgb(255,255,255),0,StartPoint-RANGE,0,"Rank:\tName:\tScore:");

    for(i=0;i<printNum;i++){
        sprintf(inputText,"%2d\t\t%s\t\t%d",i+1,inputScoreBoard[i].NameAddress,inputScoreBoard[i].ScoreAddress);
        al_draw_text(font_48,al_map_rgb(255,255,255),0,StartPoint+i*RANGE,0,inputText);
    }
}


    //     al_draw_text(font_48,al_map_rgb(255,255,255),0,100-(double)Range,0,RankTitleText);
    // for(i=0;i<printNum;i++){
    //     strcpy(tempStr,Name[i]);
    //     sprintf(RankText,"%d\t,%s\t,%d\n",i+1,tempStr,Score[i]);
    //     al_draw_text(font_48,al_map_rgb(255,255,255),0,100+i*(double)Range,0,RankText);
    // }



//這不能用
// 顯示前 N 名高分
// void display_top_scores(ALLEGRO_FONT* font) {
//     int scores[MAX_SCORES];
//     int count = 0;

//     FILE *file = fopen(SCORE_FILE, "r");
    
//     if (file != NULL) {
//         while (fscanf(file, "%d", &scores[count]) != EOF && count < MAX_SCORES) {
//             count++;
//         }
//         fclose(file);
        
//         // 簡單的排序算法（冒泡排序）
//         for (int i = 0; i < count - 1; i++) {
//             for (int j = 0; j < count - i - 1; j++) {
//                 if (scores[j] < scores[j + 1]) { // 降序排列
//                     int temp = scores[j];
//                     scores[j] = scores[j + 1];
//                     scores[j + 1] = temp;
//                 }
//             }
//         }

//         // 顯示前 N 名的高分
//         printf("前 %d 高分:\n", TOP_N);
//         for (int i = 0; i < TOP_N && i < count; i++) {
//             printf("%d. %d\n", i + 1, scores[i]);
//         }
        
//         printf("\n");
        
//         // 在畫面上顯示高分（可選）
//         for (int i = 0; i < TOP_N && i < count; i++) {
//             char high_score_text[20];
//             snprintf(high_score_text, sizeof(high_score_text), "%d. %d", i + 1, scores[i]);
//             al_draw_text(font, al_map_rgb(0, 0, 0), 10, 50 + i * 30, 0, high_score_text); // 在畫面上繪製高分
//         }
        
//         al_flip_display(); 
        
//         // 暫停一下以便查看高分（可選）
//         al_rest(3.0); 
        
//         // 清除畫面以準備開始遊戲
//         al_clear_to_color(al_map_rgb(255, 255, 255)); 
//         al_flip_display(); 
//    } else {
//        printf("無法打開檔案以讀取得分！\n");
//    }
// }