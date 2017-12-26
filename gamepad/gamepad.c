#include <stdio.h>
#include <signal.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>

void sig_int(int sig)
{
    exit(0);
}

void printButtonVals(SDL_Joystick *joy)
{
#define TRIANGLE 12
#define O 13
#define X 14
#define SQUARE 15

    printf("/\\: %d\t", SDL_JoystickGetButton(joy, TRIANGLE));
    printf("O: %d\t", SDL_JoystickGetButton(joy, O));
    printf("X: %d\t", SDL_JoystickGetButton(joy, X));
    printf("[]: %d\t", SDL_JoystickGetButton(joy, SQUARE));
}

void printAxelVals(SDL_Joystick *joy)
{
#define X1 0
#define Y1 1
#define X2 2
#define Y2 3
    
    printf("X1: %4d\t", SDL_JoystickGetAxis(joy, X1)/256);
    printf("Y1: %4d\t", SDL_JoystickGetAxis(joy, Y1)/256);
    printf("X2: %4d\t", SDL_JoystickGetAxis(joy, X2)/256);
    printf("Y2: %4d\t", SDL_JoystickGetAxis(joy, Y2)/256);
}

int main(int argc, char **argv)
{
    signal(SIGINT, sig_int);
    SDL_Joystick *joy;

    SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    int joyIndex = -1, numJoys = 0;
    
    numJoys = SDL_NumJoysticks();
    printf("Joystick connected: %d\n",numJoys); 
    if (numJoys > 0) {
        if (numJoys > 1) {
            printf("Which one to open[0-%d]?: ", numJoys-1);
            scanf("%d", &joyIndex);
        } else {
            joyIndex = 0;
        }
        joy = SDL_JoystickOpen(joyIndex);

        if (joy) {
            printf("Opened Joystick %d\n", joyIndex);
            printf("Name: %s\n", SDL_JoystickNameForIndex(joyIndex));
            printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
            printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
            printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
            while(1) {
                int i;
                SDL_JoystickUpdate();
                //for (i = 0; i < 4; i++)
                //    printf("Axis %d: %d\t", i, SDL_JoystickGetAxis(joy, i));
                //for (i = 0; i < 19; i++)
                //    printf("b%d: %d\t", i, SDL_JoystickGetButton(joy, i));
                printAxelVals(joy);
                printButtonVals(joy);
                printf("\n");
                usleep(20000);
            }
        } else {
            printf("Couldn't open Joystick %d\n", joyIndex);
        }

        if (SDL_JoystickGetAttached(joy)) {
            SDL_JoystickClose(joy);
        }
    }
    return 0;
}
