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

double road[360][2];

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
int item = 3; // ���� ������
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

    for (int i = 0; i < 90; i++)
    {
        road[i][0] = 25;
        road[i][1] = 70;
    }

    for (int i = 0, j = 90; i < 1440; j++, i += 8) {
        y = sin(i * 3.14 / 180);

        ly = y * 20 + 25.0;
        ry = y * 20 + 70.0;

        road[j][0] = ly; // ���ʺ��� 5 ������
        road[j][1] = ry;
    }

    for (int i = 270,  k= 0 ; i < 360; i++)
    {
        road[i][0] = 25 + k;
        road[i][1] = 70 + k;
        if (i < 292) k++;
        else if (i >= 293 && i < 315) k--;
        else if (i >= 315 && i < 337) k++;
        else if(i >= 338 && i < 360)  k--;
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
    int degree = 360;
    while (1) {
        showCar(car[carNumber]);
        showItem(it);
        showObstacles(ob);
        textcolor(WHITE, BLACK);
        for (k = degree - road_idx, j = 0; j < 45; j++, k++) {
            k = k % degree;
            gotoxy(road[k][0], j);
            printf("*");
            gotoxy(road[k][1], j);
            printf("*");
        }

        Sleep(speed);
        deleteItem(it);
        deleteObstacles(ob);
        for (k = degree - road_idx, j = 0; j < 45; j++, k++) {
            k = k % degree;
            gotoxy(road[k][0], j);
            printf(" ");
            gotoxy(road[k][1], j);
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


        if (road_idx > degree) {
            road_idx = 0;
            for (int i = 0; i < 5; i++) {
                ob[i].rN = rand() % 3;
                ob[i].x = rand() % 25;
                ob[i].y = rand() % 37;
                ob[i].k = ob[i].y;
            }
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