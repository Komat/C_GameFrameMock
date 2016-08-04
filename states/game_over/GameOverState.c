/**
 * @description
 * @fileName GameOverState.c.
 * @author komatsu
 * @date 8/4/16.
 * @version 0.0
 */

#include "GameOverState.h"

static char *state_id = "game_over";


static void print_id(void) {
    printf("%s", state_id);
}

/**
 *
 */
static void onEnter(State *state) {

    state->superOnEnter(state);

    printf("GAME OVER START");

}


/**
 *
 */
static void onExit(State *state) {

    printf("\n\n\n");
    print_id();
    printf("\n\n\n");

    state->superOnExit(state);

    printf("GAME OVER END");

}


State *new_game_over_state(void) {
    State *self = state_new();
    self->id = state_id;
    self->onEnter = onEnter;
    self->onExit = onExit;
    return self;
}
