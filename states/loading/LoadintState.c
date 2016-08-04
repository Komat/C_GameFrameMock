/**
 * @description
 * @fileName LoadintState.c.
 * @author komatsu
 * @date 8/4/16.
 * @version 0.0
 */

#include "LoadintState.h"


static char *state_id = "loading";


static void print_id(void) {
    printf("%s", state_id);
}


void count_up(int *num) {

    *num += 1;

    printf("%2d / 100\n", *num);

    delay(30);

    if (*num < 100) {
        count_up(num);
    }
}


/**
 *
 */
static void onEnter(State *state) {


    int count = 0;

    state->superOnEnter(state);

    count_up(&count);

    printf("LOAD COMPLETE");

}


/**
 *
 */
static void onExit(State *state) {

    printf("\n\n\n");
    print_id();
    printf("\n\n\n");

    state->superOnExit(state);


}


/**
 *
 * @return
 */
State *new_loading_state(void) {
    State *self = state_new();
    self->id = state_id;
    self->onEnter = onEnter;
    self->onExit = onExit;
    return self;
}

