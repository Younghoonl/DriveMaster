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

double road[88][2];

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
int carNumber=0;
int item = 0; // ���� ������
int heart = 5; // �ʱ� ���
int gameTime = 0;
int tmpCarNumber;

clock_t itemTimeStart;
clock_t itemTimeEnd;


int lines = 43;
int cols = 150;

typedef struct ObstacleStruct {
    int rN; // randomNumber
    int x, y, k;
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

    for (int i = 0; i < 44; i++)
    {
        road[i][0] = 20;
        road[i][1] = 60;
    }

    for (int i = 0, j = 44; i < 360; j++, i += 8) {
        y = sin(i * 3.14 / 180);

        ly = y * 20 + 20.0;
        ry = y * 20 + 60.0;

        road[j][0] = ly + 5; // ���ʺ��� 5 ������
        road[j][1] = ry + 10;
    }
}


void show_road() {
    int road_idx = 0;
    int j = 0;
    int i, k = 0;
    srand(time(NULL)); // �Ź� �ٸ� �õ尪 ����

    obstacle ob[5];
    for (int i = 0; i < 5; i++) {
        ob[i].rN = rand() % 3;
        ob[i].x = rand() % 25;
        ob[i].y = rand() % 40;
        if (ob[i].y == 1) {
            ob[i].y++;
        }
        ob[i].k = ob[i].y;
    }

    itemStruct it;
    it.x = road[1][0];
    it.y = j;

    while (1) {
        showItem(it);
        showObstacles(ob);
        for (k = 87 - road_idx, j = 0; j < 44; j++, k++) {
            k = k % 87;
            gotoxy(road[k][0], j);
            printf("*");
            gotoxy(road[k][1], j);
            printf("*");
        }

        Sleep(speed);
        deleteItem(it);
        deleteObstacles(ob);
        for (k = 87 - road_idx, j = 0; j < 44; j++, k++) {
            k = k % 87;
            gotoxy(road[k][0], j);
            printf(" ");
            gotoxy(road[k][1], j);
            printf(" ");
        }


        for (int i = 0; i < 50; i++) {
            ProcessKeyInPut();
        }

        end = clock();
        gameTime = (double)(end - start) / CLOCKS_PER_SEC; //�ʴ��� ��ȯ
        gameBoardInfo();

        road_idx++;
        for (int i = 0; i < 5; i++) {
            ob[i].y++;
            if (ob[i].y > 44) {
                ob[i].y = 1;
            }
        }
        it.y++;


        if (road_idx > 87) {
            road_idx = 1;
            for (int i = 0; i < 5; i++) {
                ob[i].rN = rand() % 3;
                ob[i].x = rand() % 25;
                ob[i].y = rand() % 37;
                ob[i].k = ob[i].y;
            }
            it.x = road[1][0];
            it.y = 1;

        }/*
        if (gameTime > 50) {
            break;
        }*/
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
    countMotion();
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