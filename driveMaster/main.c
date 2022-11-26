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

#define OB1 33
#define OB2 73
#define OB3 141
#define OB4 59
#define OB5 41
#define OB6 131
#define OB7 71
#define OB8 111
#define OB9 151

#define ITEM 171


double road[360][3];

char command[COMMAND_SIZE] = { '\0', };

int curPosX = 38;
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
int item = 0; // 현재 아이템
int heart = 5; // 초기 목숨
int gameTime = 0;
int tmpCarNumber;

clock_t itemTimeStart;
clock_t itemTimeEnd;

int tmpCycle[8] = { 0,315,270,225,180,135,90,45};
int tmpC = 0;

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
    int obNum;

    for (int i = 0; i < 360; i++) {
        if (i % ITEM == 0 && i!=0)     road[i][1] = 10;    //item 
        else if (i % OB1 == 0) road[i][1] = 1;
        else if (i % OB2 == 0) road[i][1] = 2;
        else if (i % OB3 == 0) road[i][1] = 3;
        else if (i % OB4 == 0) road[i][1] = 4;
        else if (i % OB5 == 0) road[i][1] = 5;
        else if (i % OB6 == 0) road[i][1] = 6;
        else if (i % OB7 == 0) road[i][1] = 7;
        else if (i % OB8 == 0) road[i][1] = 8;
        else if (i % OB9 == 0) road[i][1] = 9;
        else  road[i][1] = 0;
    }
    

    for (int i = 0; i < 90; i++)
    {
        road[i][0] = 25;
        road[i][2] = 70;
    }

    for (int i = 0, j = 90; i < 1440; j++, i += 8) {
        y = sin(i * 3.14 / 180);

        ly = y * 20 + 25.0;
        ry = y * 20 + 70.0;

        road[j][0] = ly; 
        road[j][2] = ry;
    }

    for (int i = 270, k = 0; i < 360; i++)
    {
        road[i][0] = 25 + k;
        road[i][2] = 70 + k;
        if (i < 292) k++;
        else if (i >= 293 && i < 315) k--;
        else if (i >= 315 && i < 337) k++;
        else if (i >= 338 && i < 360)  k--;
    }
}


void show_road() {
    int road_idx = 0;
    int j = 0;
    int i, k = 0;
    int tmp;
    srand(time(NULL)); 

    obstacle ob1[3];
    ob1[0].rN = 0;
    ob1[1].rN = 0;
    ob1[2].rN = 0;
    ob1[0].x = 5;
    ob1[1].x = 25;
    ob1[2].x = 40;

    obstacle ob2[3];
    ob2[0].rN = 1;
    ob2[1].rN = 1;
    ob2[2].rN = 1;
    ob2[0].x = 8;
    ob2[1].x = 28;
    ob2[2].x = 38;

    obstacle ob3[3];
    ob3[0].rN = 2;
    ob3[1].rN = 2;
    ob3[2].rN = 2;
    ob3[0].x = 10;
    ob3[1].x = 30;
    ob3[2].x = 38;

    itemStruct it;
    it.x = 10;
    

    int roadPos = tmpCycle[tmpC] + curPosY;

    it.x = 7;
    
    int degree = 360;
    while (1) {
        showCar(car[carNumber]);
       
        textcolor(WHITE, BLACK);
        for (k = degree - road_idx, j = 0; j < 45; j++, k++) {
            k = k % degree;
            gotoxy(road[k][0], j);
            printf("*");
            int obstacleX = 0;
            int itemX = 0;
            tmp = road[k][1];

            switch (tmp) {
            case 0:  break;
            case 1:  gotoxy(road[k][0] + ob1[0].x, j);
                     showObstacles1(ob1[0]);
                     obstacleX = road[k][0] + ob1[0].x;
                     break;
            case 2:  gotoxy(road[k][0] + ob1[1].x, j);
                     showObstacles1(ob1[1]);
                     obstacleX = road[k][0] + ob1[1].x;
                     break;
            case 3:  gotoxy(road[k][0] + ob1[2].x, j);
                     showObstacles1(ob1[2]);
                     obstacleX = road[k][0] + ob1[2].x;
                     break;
            case 4:  gotoxy(road[k][0] + ob2[0].x, j);
                     showObstacles1(ob2[0]);
                     obstacleX = road[k][0] + ob2[0].x;
                     break;
            case 5:  gotoxy(road[k][0] + ob2[1].x, j);
                     showObstacles1(ob2[1]);
                     obstacleX = road[k][0] + ob2[1].x;
                     break;
            case 6:  gotoxy(road[k][0] + ob2[2].x, j);
                     showObstacles1(ob2[2]); 
                     obstacleX = road[k][0] + ob2[2].x;
                     break;
            case 7:  gotoxy(road[k][0] + ob3[0].x, j);
                     showObstacles1(ob3[0]);
                     obstacleX = road[k][0] + ob3[0].x;
                     break;
            case 8:  gotoxy(road[k][0] + ob3[1].x, j);
                     showObstacles1(ob3[1]);
                     obstacleX = road[k][0] + ob3[1].x;
                     break;
            case 9:  gotoxy(road[k][0] + ob3[2].x, j);
                     showObstacles1(ob3[2]);
                     obstacleX = road[k][0] + ob3[2].x;
                     break;
            case 10: gotoxy(road[k][0] + it.x, j);
                     showItem(it);
                     itemX = road[k][0] + it.x;
                     break;
            default:
                break;
            }

            if ((tmp>=1&&tmp<=9) && k==roadPos) {
                int p = (obstacleX - curPosX);
                p = p > 0 ? p : -p;
                if (p<7) {
                    heart--;
                    if (heart == 0) {
                        return;
                    }
                }
            }
            if (tmp == 10 && k == roadPos) {
                item = rand() % 3 + 1;
                if (item == 1) {
                    // key 변환
                    LeftRightChange = true;
                    itemTimeStart = clock();
                    item = 0;
                }
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
            tmp = road[k][1];
            switch (tmp) {
            case 0:  break;
            case 1:  gotoxy(road[k][0] + ob1[0].x, j);
                     deleteObstacles1();
                     break;
            case 2:  gotoxy(road[k][0] + ob1[1].x, j);
                     deleteObstacles1();
                     break;
            case 3:  gotoxy(road[k][0] + ob1[2].x, j);
                     deleteObstacles1();
                     break;
            case 4:  gotoxy(road[k][0] + ob2[0].x, j);
                     deleteObstacles1();
                     break;
            case 5:  gotoxy(road[k][0] + ob2[1].x, j);
                     deleteObstacles1();
                     break;
            case 6:  gotoxy(road[k][0] + ob2[2].x, j);
                     deleteObstacles1();
                     break;
            case 7:  gotoxy(road[k][0] + ob3[0].x, j);
                     deleteObstacles1();
                     break;
            case 8:  gotoxy(road[k][0] + ob3[1].x, j);
                     deleteObstacles1();
                     break;
            case 9:  gotoxy(road[k][0] + ob3[2].x, j);
                     deleteObstacles1();
                     break;
            case 10: gotoxy(road[k][0] + it.x, j);
                     deleteItem();
                     break;
            default:
                break;
            }

            gotoxy(road[k][2], j);
            printf(" ");
        }
        detectcollisionRoad(roadPos);

        for (int i = 0; i < 100; i++) {
            ProcessKeyInPut(roadPos);
        }

        roadPos--;
        if (roadPos <= 0) {
            roadPos = 360;
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
       
        if (road_idx % 45 == 0) {
            tmpC++;
            tmpC = tmpC % 8;
            roadPos = tmpCycle[tmpC] + curPosY;
        }
        if (road_idx > degree) {
            road_idx = 0;
            it.x = road[1][0];
            it.y = 1;
        }

        if (gameTime == 120) {
            return;
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