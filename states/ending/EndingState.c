/**
 * @description
 * @fileName EndingState.cpp.
 * @author komatsu
 * @date 8/4/16.
 * @version 0.0
 */

#include "EndingState.h"

static char *state_id = "ending";


static void print_id(void) {
    printf("%s", state_id);
}

/**
 *
 */
static void onEnter(State *state) {

    state->superOnEnter(state);

    printf("ENDING START");

}


/**
 *
 */
static void onExit(State *state) {

    printf("\n\n\n");
    print_id();
    printf("\n\n\n");

    state->superOnExit(state);

    printf("ENDING END");

}


State *new_ending_state(void) {
    State *self = state_new();
    self->id = state_id;
    self->onEnter = onEnter;
    self->onExit = onExit;
    return self;
}
