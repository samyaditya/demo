#include <stdio.h>
#include <signal.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>

void sig_int(int sig)
{
    exit(0);
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
                for (i = 0; i < 4; i++)
                    printf("Axis %d: %d\t", i, SDL_JoystickGetAxis(joy, i));
                for (i = 0; i < 11; i++)
                    printf("b%d: %d\t", i, SDL_JoystickGetButton(joy, i));
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
