#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "Car.h"
#include <math.h>
#include <conio.h>
#include <stdbool.h>


#define COMMAND_SIZE 256

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

#define OB1 17
#define OB2 31
#define OB3 11

double road[360][3];

char command[COMMAND_SIZE] = { '\0', };

int curPosX = 28;
int curPosY = 36;

extern bool LeftRightChange;
extern bool BoostChange;
extern bool CarChange;

clock_t start;
clock_t end;

char userName[30];
int score = 0;
int speed = 100;
int carNumber = 0;
int item = 3; // 현재 아이템
int heart = 5; // 초기 목숨
int gameTime = 0;
int tmpCarNumber;

clock_t itemTimeStart;
clock_t itemTimeEnd;


int lines = 43;
int cols = 150;

typedef struct ObstacleStruct {
    int rN; 
    int x;
}obstacle;

typedef struct ItemStruct {
    int x, y;
}itemStruct;


int gotoxy(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.Y = y;
    pos.X = x;
    SetConsoleCursorPosition(hConsole, pos);
    return 0;
}



void setRoad() {

    double ly, ry;
    double y;

    for (int i = 0; i < 90; i++)
    {
        road[i][0] = 25;
        if (i % OB1 == 0) road[i][1] = 1;
        else if (i % OB2 == 0) road[i][1] = 2;
        else if (i % OB3 == 0) road[i][1] = 3;
        else road[i][1] = 0;

        road[i][2] = 70;
    }

    for (int i = 0, j = 90; i < 1440; j++, i += 8) {
        y = sin(i * 3.14 / 180);

        ly = y * 20 + 25.0;
        ry = y * 20 + 70.0;

        road[j][0] = ly; 
        road[j][2] = ry;

        if (j % OB1 == 0) road[j][1] = 1;
        else if (j % OB2 == 0) road[j][1] = 2;
        else if (j % OB3 == 0) road[j][1] = 3;
        else road[j][1] = 0;
    }

    for (int i = 270, k = 0; i < 360; i++)
    {
        road[i][0] = 25 + k;
        road[i][2] = 70 + k;
        if (i < 292) k++;
        else if (i >= 293 && i < 315) k--;
        else if (i >= 315 && i < 337) k++;
        else if (i >= 338 && i < 360)  k--;

        if (i % OB1 == 0) road[i][1] = 1;
        else if (i % OB2 == 0) road[i][1] = 2;
        else if (i % OB3 == 0) road[i][1] = 3;
        else road[i][1] = 0;
    }
}


void show_road() {
    int road_idx = 0;
    int j = 0;
    int i, k = 0;
    srand(time(NULL)); 
    obstacle ob1;
    ob1.rN = 0;
    ob1.x = 5;

    obstacle ob2;
    ob2.rN = 1;
    ob2.x = 15;

    obstacle ob3;
    ob3.rN = 2;
    ob3.x = 25;


    itemStruct it;
    it.x = road[1][0];
    it.y = j;
    int degree = 360;
    while (1) {
        showCar(car[carNumber]);
        showItem(it);
        textcolor(WHITE, BLACK);
        for (k = degree - road_idx, j = 0; j < 45; j++, k++) {
            k = k % degree;
            gotoxy(road[k][0], j);
            printf("*");
            if (road[k][1] == 1) {
                gotoxy(road[k][0] + ob1.x, j);
                showObstacles1(ob1);
            }
            else if (road[k][1] == 2) {
                gotoxy(road[k][0] + ob2.x, j);
                showObstacles1(ob2);
            }
            else if (road[k][1] == 3) {
                gotoxy(road[k][0] + ob3.x, j);
                showObstacles1(ob3);
            }
            gotoxy(road[k][2], j);
            printf("*");
        }

        Sleep(speed);
        deleteItem(it);
        for (k = degree - road_idx, j = 0; j < 45; j++, k++) {
            k = k % degree;
            gotoxy(road[k][0], j);
            printf(" ");
            if (road[k][1] == 1) {
                gotoxy(road[k][0] + ob1.x, j);
                deleteObstacles1(ob1);
            }
            else if (road[k][1] == 2) {
                gotoxy(road[k][0] + ob2.x, j);
                deleteObstacles1(ob2);
            }
            else if (road[k][1] == 3) {
                gotoxy(road[k][0] + ob3.x, j);
                deleteObstacles1(ob3);
            }
            gotoxy(road[k][2], j);
            printf(" ");
        }


        for (int i = 0; i < 100; i++) {
            ProcessKeyInPut();
        }
        itemTimeEnd = clock();
        if ((double)(itemTimeEnd - itemTimeStart) / CLOCKS_PER_SEC >= 10.0) {
            LeftRightChange = false;
            BoostChange = false;
            CarChange = false;
            speed = 100;
            carNumber = tmpCarNumber;
        }
        end = clock();
        gameTime = (double)(end - start) / CLOCKS_PER_SEC; //초단위 변환
        gameBoardInfo();

        road_idx++;
       


        if (road_idx > degree) {
            road_idx = 0;
            it.x = road[1][0];
            it.y = 1;
        }


    }
}

int main() {
    sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
    system(command);
    RemoveCursor();

    //initScreen();
    int key;
    //key = _getch();
    //eraseScreen();
    //carNumber = gameInfoSelect();

    eraseScreen();
    //countMotion();
    eraseScreen();

    gameBoardInfo();

    SetCurrentCursorPos(curPosX, curPosY);
    start = clock();

    showCar(car[carNumber]);
    setRoad();
    show_road();

    eraseScreen();
    gameOver(score);
    key = _getch();


}