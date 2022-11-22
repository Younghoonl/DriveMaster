#include "Items.h"
#include <Windows.h>


#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

extern double road[44][2];

typedef struct ObstacleStruct {
    int rN; // randomNumber
    int x, y, k;
}obstacle;

typedef struct ItemStruct {
    int x, y;
}itemStruct;

void textcolor(int foreground, int background)
{
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showObstacles(obstacle ob[5]) {
    for (int i = 0; i < 5; i++) {
        if (ob[i].y > 40) {
            continue;
        }
        int obX = ob[i].x + road[ob[i].k][0] + 5;
        int obY = ob[i].y % 45;
        gotoxy(obX, obY);
        textcolor(YELLOW, BLACK);
        printf("%s", Obstacles[ob[i].rN]);
    }

}





void deleteObstacles(obstacle ob[5]) {
    for (int i = 0; i < 5; i++) {
        if (ob[i].y > 40) {
            continue;
        }
        int obX = ob[i].x + road[ob[i].k][0] + 5;
        int obY = ob[i].y % 45;
        gotoxy(obX, obY);
        printf("%s", Obstacles[3]);
    }
}


void showItem(itemStruct it) {
    if (it.y > 40) {
        return;
    }
    gotoxy(it.x + 5, it.y);
    for (int i = 1; i <= 3; i++) {
        gotoxy(it.x + 15 * i, it.y);
        printf("%s", itemIcon);
    }
}

void deleteItem(itemStruct it) {

    if (it.y > 40) {
        return;
    }
    gotoxy(it.x + 5, it.y);
    for (int i = 1; i <= 3; i++) {
        gotoxy(it.x + 15 * i, it.y);
        printf("   ", itemIcon);
    }
}
