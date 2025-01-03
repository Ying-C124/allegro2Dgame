#include "myheader.h"

ALLEGRO_SAMPLE_INSTANCE *createSound(ALLEGRO_SAMPLE *sample,ALLEGRO_MIXER *mixer,ALLEGRO_VOICE *voice)
{
    ALLEGRO_SAMPLE_INSTANCE *instance = NULL;
    instance = al_create_sample_instance(sample);
    mixer = al_create_mixer(al_get_sample_instance_frequency(instance), al_get_sample_instance_depth(instance), al_get_sample_instance_channels(instance));
    voice = al_create_voice(al_get_sample_instance_frequency(instance), al_get_sample_instance_depth(instance), al_get_sample_instance_channels(instance));
    al_attach_mixer_to_voice(mixer, voice);
    al_attach_sample_instance_to_mixer(instance, mixer);
    al_set_sample_instance_gain(instance, 1.0);
    al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
    return instance;
}