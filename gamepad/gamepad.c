#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include "Interface.pb-c.h"

#define TRIANGLE 12
#define O 13
#define X 14
#define SQUARE 15

#define X1 0
#define Y1 1
#define X2 2
#define Y2 3

#define AXIS_DIVISOR(X) (X / 256)

void sig_int(int sig)
{
    exit(0);
}

void printButtonVals(SDL_Joystick *joy)
{
    printf("/\\: %d\t", SDL_JoystickGetButton(joy, TRIANGLE));
    printf("O: %d\t",   SDL_JoystickGetButton(joy, O));
    printf("X: %d\t",   SDL_JoystickGetButton(joy, X));
    printf("[]: %d\t",  SDL_JoystickGetButton(joy, SQUARE));
}

void printAxelVals(SDL_Joystick *joy)
{
    printf("X1: %4d\t", AXIS_DIVISOR(SDL_JoystickGetAxis(joy, X1)));
    printf("Y1: %4d\t", AXIS_DIVISOR(SDL_JoystickGetAxis(joy, Y1)));
    printf("X2: %4d\t", AXIS_DIVISOR(SDL_JoystickGetAxis(joy, X2)));
    printf("Y2: %4d\t", AXIS_DIVISOR(SDL_JoystickGetAxis(joy, Y2)));
}

GamePad * newGamepadPacket(void)
{
    GamePad *gp = (GamePad *)malloc(sizeof(GamePad));
    game_pad__init(gp);

    gp->stick1 =     (Axis *)malloc(sizeof(Axis));
    axis__init(gp->stick1);

    gp->stick2 =     (Axis *)malloc(sizeof(Axis));
    axis__init(gp->stick2);

    gp->triangle =   (Button *)malloc(sizeof(Button));
    button__init(gp->triangle);

    gp->o =          (Button *)malloc(sizeof(Button));
    button__init(gp->o);

    gp->x =          (Button *)malloc(sizeof(Button));
    button__init(gp->x);

    gp->square =     (Button *)malloc(sizeof(Button));
    button__init(gp->square);

    return gp;
}

void fillStickData(GamePad *gp, SDL_Joystick *joy)
{
    gp->stick1->x = AXIS_DIVISOR(SDL_JoystickGetAxis(joy, X1));
    gp->stick1->y = AXIS_DIVISOR(SDL_JoystickGetAxis(joy, Y1));
    gp->stick2->x = AXIS_DIVISOR(SDL_JoystickGetAxis(joy, X2));
    gp->stick2->y = AXIS_DIVISOR(SDL_JoystickGetAxis(joy, Y2));
}

void fillButtonData(GamePad *gp, SDL_Joystick *joy)
{
    gp->triangle->state = SDL_JoystickGetButton(joy, TRIANGLE);
    gp->o->state = SDL_JoystickGetButton(joy, O);
    gp->x->state = SDL_JoystickGetButton(joy, X);
    gp->square->state = SDL_JoystickGetButton(joy, SQUARE);
}

void fillGamepadData(GamePad *gp, SDL_Joystick *joy)
{
    fillStickData(gp, joy);
    fillButtonData(gp, joy);
}

void freeGamePadPacket(GamePad *gp)
{
    if (gp) {
        if (gp->stick1)
            free(gp->stick1);
        if (gp->stick2)
            free(gp->stick2);
        if (gp->triangle)
            free(gp->triangle);
        if (gp->o)
            free(gp->o);
        if (gp->x)
            free(gp->x);
        if (gp->square)
            free(gp->square);
        free(gp);
    }
}

void sendOverSocket(uint8_t *buf, int len, char *ip, uint16_t port)
{
    static int sfd = -1;
    static struct sockaddr_in sockAddr;
    if (sfd < 0 ) {
        sfd = socket(AF_INET,SOCK_DGRAM,0);
        if (sfd < 0) {
            perror("socket");
            return;
        }
        sockAddr.sin_family = AF_INET;
        sockAddr.sin_port = htons(port);
        sockAddr.sin_addr.s_addr = inet_addr(ip);
    }
    sendto(sfd, buf, len, MSG_DONTWAIT, (struct sockaddr *)&sockAddr, sizeof (sockAddr));
}

void sendProtobufData(SDL_Joystick *joy, char *ip, uint16_t port)
{
    int len = 0;
    uint8_t *buf = NULL;
    GamePad *gp = newGamepadPacket();
    fillGamepadData(gp, joy);
    len = game_pad__get_packed_size(gp);
    buf = (uint8_t *)malloc(len);
    len = game_pad__pack(gp, buf);
    sendOverSocket(buf, len, ip, port);
    free(buf);
    freeGamePadPacket(gp);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <server-ip> <server-port>\n", argv[0]);
        return -1;
    }

    signal(SIGINT, sig_int);
    SDL_Joystick *joy;
    char *serverIp = argv[1];
    uint16_t serverPort = atoi(argv[2]);

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
                SDL_JoystickUpdate();
#if 0
                int i;
                for (i = 0; i < 4; i++)
                    printf("Axis %d: %d\t", i, SDL_JoystickGetAxis(joy, i));
                for (i = 0; i < 19; i++)
                    printf("b%d: %d\t", i, SDL_JoystickGetButton(joy, i));
#endif
                printAxelVals(joy);
                printButtonVals(joy);
                printf("\n");
                sendProtobufData(joy, serverIp, serverPort);
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
