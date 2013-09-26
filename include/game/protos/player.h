#ifndef _PLAYER_H
#define _PLAYER_H

#include "audio/sound_state.h"

typedef struct object_t object;
typedef struct sd_stringparser_t sd_stringparser;

typedef struct player_sprite_state_t {
    int blendmode;
    int flipmode;
} player_sprite_state;

typedef struct player_animation_state_t {
    unsigned int finished;
    unsigned int ticks;
    unsigned int repeat;
    unsigned int reverse;
    unsigned int end_frame;
    sound_state *sound_state;
    sd_stringparser *parser;
    int enemy_x, enemy_y;

    void (*del_player)(object *obj, int id);
    void (*add_player)(object *obj, int id, int mx, int my, int mg);
} player_animation_state;

void player_create(object *obj);
void player_free(object *obj);
void player_reload(object *obj);
void player_reset(object *obj);
void player_run(object *obj);
void player_set_repeat(object *obj, int repeat);
int player_get_repeat(object *obj);
void player_set_end_frame(object *obj, int end_frame);
void player_next_frame(object *obj);
void player_goto_frame(object *obj, int frame_id);
int player_get_frame(object *obj);
char player_get_frame_letter(object *obj);

#endif // _PLAYER_H