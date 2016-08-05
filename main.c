/**
 * @description
 * @fileName main.c.
 * @author komatsu
 * @date 8/4/16.
 * @version 0.0
 */

#include <stdio.h>
#include "classes/states/StateMachine/StateMachine.h"
#include "classes/modules/Modules.h"
#include "states/loading/LoadintState.h"
#include "states/intro/IntroState.h"
#include "states/main/MainState.h"
#include "states/ending/EndingState.h"
#include "states/game_over/GameOverState.h"

void state_enter_handler(State *state);
void state_stay_handler(State *state);
void state_exit_handler(State *state);

void ending_enter_handler(State *state);

int main(void) {

    state_machine_init();

    state_machine_subscribe(ENTER_STATE, state_enter_handler);
    state_machine_subscribe(STAY_STATE, state_stay_handler);
    state_machine_subscribe(EXIT_STATE, state_exit_handler);


    printf("\n\nRANDOM TEST %d\n\n", mod_random());


    hash *state_machine = state_machine_new();

    State *Loading = new_loading_state();
    State *Intro = new_intro_state();
    State *Main = new_main_state();
    State *Ending = new_ending_state();
    State *GameOver = new_game_over_state();

    state_machine_add(state_machine, Loading);
    state_machine_add(state_machine, Intro);
    state_machine_add(state_machine, Main);
    state_machine_add(state_machine, Ending);
    state_machine_add(state_machine, GameOver);

    dictionary *state_machine_list = state_machine_ready(state_machine);

    state_machine_goto(state_machine, Loading);
    state_machine_goto(state_machine, Intro);
    mod_delay(1000);
    state_machine_goto(state_machine, Main);
    mod_delay(1000);
    state_machine_subscribe(ENTER_STATE, ending_enter_handler);
    state_machine_goto(state_machine, GameOver);

    state_machine_destroy(state_machine, state_machine_list);

    return 0;
}

void state_exit_handler(State *state) {
    printf("%s::EXIT\n", state->id);
}

void state_stay_handler(State *state) {
    printf("%s::STAY\n", state->id);
}

void state_enter_handler(State *state) {
    printf("%s::ENTER\n", state->id);
}

void ending_enter_handler(State *state) {

    printf("    ██████╗ ██████╗ ███████╗\n");
    printf("    ██╔═══██╗██╔══██╗╚══███╔╝\n");
    printf("    ██║   ██║██████╔╝  ███╔╝\n");
    printf("    ██║   ██║██╔══██╗ ███╔╝\n");
    printf("    ╚██████╔╝██║  ██║███████╗\n");
    printf("    ╚═════╝ ╚═╝  ╚═╝╚══════╝\n\n\n\n\n\n\n\n\n");

    state_machine_unsubscribe(ENTER_STATE, ending_enter_handler);
}
