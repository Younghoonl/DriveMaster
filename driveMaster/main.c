#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "Car.h"
#include<math.h>
#include<conio.h>

double road[36][2];
int road_idx = 0;
int next_idx = 0;

int curPosX = 25;
int curPosY = 20;

char userName[30];
int score = 0;
int speed = 0;
int carNumber=0;
int item; // 현재 아이템
int heart = 5; // 초기 목숨
int gameTime = 0;


void SetCurrentCursorPos(int x, int y) {
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

COORD GetCurrentCursorPos(void) {
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X = curInfo.dwCursorPosition.X;
    curPoint.Y = curInfo.dwCursorPosition.Y;

    return curPoint;
}

void RemoveCursor() {
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

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

    for (int i = 0, j = 0; i < 360; j++, i += 10) {
        y = sin(i * 3.14 / 180);

        ly = y * 12 + 20.0;
        ry = y * 12 + 45.0;

        road[j][0] = ly;
        road[j][1] = ry;
    }
}

void show_road() {

    gotoxy((int)road[(road_idx + 1) % 36][0], 1);
    printf("  ");
    gotoxy((int)road[(road_idx + 1) % 36][1], 1);
    printf("  ");

    if (road_idx == 0)
        next_idx = 35;
    else
        next_idx = road_idx - 1;

    for (int j = 1, i = road_idx; j < 37; i++, j++) {
        i = i % 36;
        gotoxy((int)road[i][0], j);
        printf("*");
        gotoxy((int)road[i][1], j);
        printf("*");
        Sleep(100);
    }
    road_idx = next_idx;
}



void gameInfoSelect() {
    /* 유저 이름, 자동차 선택 */
    int x = 10;
    int y = 3;
    SetCurrentCursorPos(x, y);
    printf("*");
    for (int i = 0; i < 80; i++) {
        printf("*");
    }
    SetCurrentCursorPos(x, y + 20);
    for (int i = 0; i < 80; i++) {
        printf("*");
    }
    int curPosX = 23;
    int curPosY = 16;
 
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[0][y][x]);
        }
    }
    SetCurrentCursorPos(curPosX + x-4, curPosY + y+0.5);
    printf("[1]");
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[1][y][x]);
        }
    }
    SetCurrentCursorPos(curPosX + x - 4, curPosY + y + 0.5);
    printf("[2]");
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[2][y][x]);
        }
    }
    SetCurrentCursorPos(curPosX + x - 4, curPosY + y + 0.5);
    printf("[3]");
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[3][y][x]);
        }
    }
    SetCurrentCursorPos(curPosX + x - 4, curPosY + y + 0.5);
    printf("[4]");
    x = 10;
    y = 3;
    SetCurrentCursorPos(x+2, y+2);
    printf("이름 : ");
    scanf("%s", &userName);
    SetCurrentCursorPos(x+2, y+4);
    printf("자동차 : ");
    scanf("%d", &carNumber);
    carNumber--;
}

void gameBoardInfo() {
    for (int i = 0; i < 23; i++) {
        SetCurrentCursorPos(60, 2 + i);
        printf("|");
    }
    SetCurrentCursorPos(62, 3);
    printf("<%s's GAME>", userName);
    SetCurrentCursorPos(62, 5);
    printf("---CAR---");
    SetCurrentCursorPos(62, 10);
    printf("---------");
    SetCurrentCursorPos(62, 11);
    printf("---ITEM---");
    SetCurrentCursorPos(62, 15);
    printf("----------");
    SetCurrentCursorPos(62, 17);
    printf("SPEED : %d", speed);
    SetCurrentCursorPos(62, 19);
    printf("SCORE : %d", score);
    SetCurrentCursorPos(62, 21);
    printf("HEART ");
    for (int i = 0; i < heart; i++) {
        printf("♥");
    }
    for (int i = 5; i > heart; i--) {
        printf("♡");
    }
    SetCurrentCursorPos(62, 23);
    printf("TIME : %d", gameTime);

}

void gameOver(int score) {
    SetCurrentCursorPos(25, 8);
    for (int i = 0; i < 28; i++) {
        printf("*");
        Sleep(5);
    }

    SetCurrentCursorPos(25, 16);
    for (int i = 0; i < 28; i++) {
        printf("*");
        Sleep(5);
    }

    SetCurrentCursorPos(33, 10);
    printf("game over!");
    SetCurrentCursorPos(30, 12);
    printf("다시 도전하세요!");
    SetCurrentCursorPos(29, 14);
    printf("당신의 점수 : ", score);

}


int main() {
    
    RemoveCursor();
    initScreen();
    int key;
    key = _getch();
    eraseScreen();
    gameInfoSelect();
    
    eraseScreen();
    countMotion();
    eraseScreen();
    
    gameBoardInfo();
    SetCurrentCursorPos(curPosX, curPosY);
    showCar(car[carNumber]);
    setRoad();
    show_road();
    
    while (1) {
        ProcessKeyInPut();
    }
    gameOver(score);
    key = _getch();
    
    
}