/**
 * @description
 * @fileName MainState.c.
 * @author komatsu
 * @date 8/4/16.
 * @version 0.0
 */

#include "MainState.h"



static char *state_id = "main";


static void print_id(void) {
    printf("%s", state_id);
}

/**
 *
 */
static void onEnter(State *state) {

    int key_type;

    state->superOnEnter(state);

    printf("\n\n*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n\n");

    while ((key_type = getchar()) != EOF) {
        if (key_type == '\n') {
            break;
        }
    }

}


/**
 *
 */
static void onExit(State *state) {

    printf("\n\n\n");
    printf("GAME END... .. . ");
    printf("\n\n\n");

    state->superOnExit(state);

}



/**
 *
 * @return
 */
State *new_main_state(void) {
    State *self = state_new();
    self->id = state_id;
    self->onEnter = onEnter;
    self->onExit = onExit;
    return self;
}
