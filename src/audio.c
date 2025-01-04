#include "myheader.h"

ALLEGRO_SAMPLE_INSTANCE *createSound(ALLEGRO_SAMPLE *sample,ALLEGRO_MIXER *mixer,ALLEGRO_VOICE *voice)
{
    ALLEGRO_SAMPLE_INSTANCE *instance = NULL;
    instance = al_create_sample_instance(sample);
    mixer = al_create_mixer(al_get_sample_instance_frequency(instance), al_get_sample_instance_depth(instance), al_get_sample_instance_channels(instance));
    voice = al_create_voice(al_get_sample_instance_frequency(instance), al_get_sample_instance_depth(instance), al_get_sample_instance_channels(instance));
    al_attach_mixer_to_voice(mixer, voice);
    al_attach_sample_instance_to_mixer(instance, mixer);
    al_set_sample_instance_gain(instance, 0.5);
    al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
    return instance;
}

//These program is wrote by leng, 我只負責把其整合成一結構方便整理
void ying_loadingSound(MKSample *inputSounds){
    inputSounds->sample1 = al_load_sample("./pickup01.mp3");
    inputSounds->sample2 = al_load_sample("./coin02.mp3");
    inputSounds->sample3 = al_load_sample("./laser2.mp3");
    inputSounds->sample4 = al_load_sample("./button01a.mp3");
    inputSounds->check = createSound(inputSounds->sample1,inputSounds->mixer,inputSounds->voice);
    inputSounds->coin = createSound(inputSounds->sample2,inputSounds->mixer,inputSounds->voice);
    inputSounds->laser = createSound(inputSounds->sample3,inputSounds->mixer,inputSounds->voice);
    inputSounds->chest = createSound(inputSounds->sample4,inputSounds->mixer,inputSounds->voice);
    inputSounds->mixer = NULL;
    inputSounds->voice = NULL;
}