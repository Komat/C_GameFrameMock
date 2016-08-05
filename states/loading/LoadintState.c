/**
 * @description
 * @fileName LoadintState.c.
 * @author komatsu
 * @date 8/4/16.
 * @version 0.0
 */

#include "LoadintState.h"


static char *state_id = "loading";

static void print_zero() {
    printf("██████╗\n");
    printf("██╔═████╗\n");
    printf("██║██╔██║\n");
    printf("████╔╝██║\n");
    printf("╚██████╔╝\n");
    printf("╚═════╝\n");
}

static void print_one() {
    printf("██╗\n");
    printf("███║\n");
    printf(" ╚██║\n");
    printf("  ██║\n");
    printf("  ██║\n");
    printf("  ╚═╝\n");
}

static void print_two() {
    printf("██████╗\n");
    printf("╚════██╗\n");
    printf("█████╔╝\n");
    printf("██╔═══╝\n");
    printf("███████╗\n");
    printf("╚══════╝\n");
}

static void print_three() {
    printf("██████╗\n");
    printf("╚════██╗\n");
    printf("█████╔╝\n");
    printf("╚═══██╗\n");
    printf("██████╔╝\n");
    printf("╚═════╝\n");
}

static void print_four() {
    printf("██╗  ██╗\n");
    printf("██║  ██║\n");
    printf("███████║\n");
    printf("╚════██║\n");
    printf("     ██║\n");
    printf("     ╚═╝\n");
}

static void print_five() {
    printf("███████╗\n");
    printf("██╔════╝\n");
    printf("███████╗\n");
    printf("╚════██║\n");
    printf("███████║\n");
    printf("╚══════╝\n");
}

static void print_six() {
    printf("██████╗\n");
    printf("██╔════╝\n");
    printf("███████╗\n");
    printf("██╔═══██╗\n");
    printf("╚██████╔╝\n");
    printf("╚═════╝\n");
}

static void print_seven() {
    printf("███████╗\n");
    printf("╚════██║\n");
    printf("   ██╔╝\n");
    printf("   ██╔╝\n");
    printf("   ██║\n");
    printf("   ╚═╝\n");
}

static void print_eight() {
    printf("█████╗\n");
    printf("██╔══██╗\n");
    printf("╚█████╔╝\n");
    printf("██╔══██╗\n");
    printf("╚█████╔╝\n");
    printf("╚════╝\n");
}

static void print_nine() {
    printf("█████╗\n");
    printf("██╔══██╗\n");
    printf("╚██████║\n");
    printf("╚═══██║\n");
    printf("█████╔╝\n");
    printf("╚════╝\n");
}


static void print_id(void) {
    printf("%s", state_id);
}


static void print_num(char *num) {
    switch(*num) {
        case '0':
            print_zero();
            break;

        case '1':
            print_one();
            break;

        case '2':
            print_two();
            break;

        case '3':
            print_three();
            break;

        case '4':
            print_four();
            break;

        case '5':
            print_five();
            break;

        case '6':
            print_six();
            break;

        case '7':
            print_seven();
            break;

        case '8':
            print_eight();
            break;

        case '9':
            print_nine();
            break;

        default:
            break;

    }
}

static void print_number(int num) {
    char str[3];
    sprintf(str, "%d", num);

    switch(strlen(str)) {
        case 3:
            break;

        case 2:
            break;

        case 1:
        default:
            print_num(str);
            break;

    }
}


void count_up(int *num) {

    *num += 1;


    printf("\n\n\n\n\n\n");
    printf("    ███╗   ██╗ ██████╗ ██╗    ██╗    ██╗      ██████╗  █████╗ ██████╗ ██╗███╗   ██╗ ██████╗\n");
    printf("    ████╗  ██║██╔═══██╗██║    ██║    ██║     ██╔═══██╗██╔══██╗██╔══██╗██║████╗  ██║██╔════╝\n");
    printf("    ██╔██╗ ██║██║   ██║██║ █╗ ██║    ██║     ██║   ██║███████║██║  ██║██║██╔██╗ ██║██║  ███╗\n");
    printf("    ██║╚██╗██║██║   ██║██║███╗██║    ██║     ██║   ██║██╔══██║██║  ██║██║██║╚██╗██║██║   ██║\n");
    printf("    ██║ ╚████║╚██████╔╝╚███╔███╔╝    ███████╗╚██████╔╝██║  ██║██████╔╝██║██║ ╚████║╚██████╔╝██╗██╗██╗\n");
    printf("    ╚═╝  ╚═══╝ ╚═════╝  ╚══╝╚══╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝╚═╝\n\n\n");
    printf("                            %2d / 100\n\n\n\n\n\n\n\n\n\n", *num);

//     二桁の場合に面倒なのでやめ
//    print_number(*num);

    mod_delay(30);

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

