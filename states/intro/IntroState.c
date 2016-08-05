/**
 * @description
 * @fileName IntroState.c.
 * @author komatsu
 * @date 8/4/16.
 * @version 0.0
 */

#include "IntroState.h"

static char *state_id = "intro";


static void print_id(void) {
    printf("%s", state_id);
}

/**
 *
 */
static void onEnter(State *state) {

    int key_type;

    state->superOnEnter(state);

    printf("\n\n\n\n************************************************************************************************************\n\n");
    printf("    ██████╗  █████╗ ███╗   ███╗███████╗    ███████╗████████╗ █████╗ ██████╗ ████████╗\n");
    printf("    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝\n");
    printf("    ██║  ███╗███████║██╔████╔██║█████╗      ███████╗   ██║   ███████║██████╔╝   ██║\n");
    printf("    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ╚════██║   ██║   ██╔══██║██╔══██╗   ██║\n");
    printf("    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ███████║   ██║   ██║  ██║██║  ██║   ██║\n");
    printf("    ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝    ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝\n\n");
    printf("************************************************************************************************************\n\n");
    printf("                            press [ENTER] start game...\n\n\n\n");

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
    print_id();
    printf("\n\n\n");

    state->superOnExit(state);

}


/**
 *
 * @return
 */
State *new_intro_state(void) {
    State *self = state_new();
    self->id = state_id;
    self->onEnter = onEnter;
    self->onExit = onExit;
    return self;
}
