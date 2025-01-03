#include "myheader.h"

//熱插拔，非自行撰寫
void ying_hotplug_detection(ALLEGRO_EVENT *events,ALLEGRO_JOYSTICK *joystick,bool *joystickBool)
{
    if (events->type == ALLEGRO_EVENT_JOYSTICK_CONFIGURATION)   //查詢event中與joystick配置有關的種類
    {
        al_reconfigure_joysticks();                             //重新給予配置
        printf("after reconfiguration num joysticks = %d\n",
                al_get_num_joysticks());
        printf("current joystick is: %s\n",
                al_get_joystick_active(joystick) ? "active" : "inactive");  //確認是否啟用?
        if(al_get_joystick_active(joystick)==true) *joystickBool = true;
        else *joystickBool = false;
    }
   
}

//測試用
void print_joystick_log(ALLEGRO_EVENT *events)   //搖桿紀錄的總function
{
    if(events->type == ALLEGRO_EVENT_JOYSTICK_AXIS)
    {
        printf("stick[%d] axis[%d] position:%f\n"
                ,events->joystick.stick
                ,events->joystick.axis
                ,events->joystick.pos);
        }
    if(events->type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN)
        printf("button[%d] has been pressed down \n",events->joystick.button);
    if(events->type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP)
        printf("button[%d] has been released \n",events->joystick.button);
}

void ying_joystickFillZero(ALLEGRO_JOYSTICK_STATE *joyState){
    int i;
    joyState->stick[0].axis[0] = 0;
    joyState->stick[0].axis[1] = 0;
    joyState->stick[1].axis[0] = 0;
    joyState->stick[1].axis[1] = 0;
    for(i=0;i<8;i++){
        joyState->button[i] = 0;
    }
}


bool load_joystick_info(ALLEGRO_JOYSTICK *joystick)
{
    if(!al_is_joystick_installed())
    {
        printf("cannot import joystick module");
        return 0;
    }


    if(al_get_num_joysticks()==0)
    {
        printf("don't have joystick??");
        return 0;
    }

    else
    {
        int i=0;int j=0;

        printf("1st player Joystick: '%s'\n\n", al_get_joystick_name(joystick));
        printf("number of joystick %d\n",al_get_num_joysticks());
        printf("number of buttons %d \n",al_get_joystick_num_buttons(joystick));    //how many buttons
        printf("number of sticks %d \n\n",al_get_joystick_num_sticks(joystick));      //how many sticks

        for(i=0;i<al_get_joystick_num_sticks(joystick);i++)
        {
            printf("stick [%d]\tnumber of axes %d \n",
                   i,al_get_joystick_num_axes(joystick,i));
        }

        printf("\n");

        for(i=0;i<al_get_joystick_num_sticks(joystick)+1;i++)
        {
            printf("stick [%d]\tflag:%d\n",
                   i,al_get_joystick_stick_flags(joystick,i));
        }

        printf("\n");

        for(i=0;i<al_get_joystick_num_sticks(joystick);i++)
        {
            printf("stick[%d] name: %s \n",
                   i,al_get_joystick_stick_name(joystick,i));
        }

        printf("\n");

        for(i=0;i<al_get_joystick_num_sticks(joystick);i++)
        {
            for(j=0;j<al_get_joystick_num_axes(joystick,i);j++)
            {
                printf("axes name: %s \tstick[%d]\taxis[%d]\n",
                       al_get_joystick_axis_name(joystick, i, j),i,j);
            }
        }


        printf("\njoystick button name:\n");

        for(i=0;i<al_get_joystick_num_buttons(joystick);i++)
            printf("%s\tbutton[%d]\n",al_get_joystick_button_name(joystick,i),i);

        printf("\n");
    }
    return 1;
}