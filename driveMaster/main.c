#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "Car.h"
#include <math.h>
#include <conio.h>

#define COMMAND_SIZE 256

double road[44][2];

char command[COMMAND_SIZE] = { '\0', };

int curPosX = 25;
int curPosY = 25;

char userName[30];
int score = 0;
int speed = 100;
int carNumber=0;
int item; // 현재 아이템
int heart = 5; // 초기 목숨
int gameTime = 0;

int lines = 45;
int cols = 150;

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
    x = 15;
    y = 5;
    SetCurrentCursorPos(x, y);
    printf("이름 : ");
    scanf("%s", &userName);
    SetCurrentCursorPos(x, y + 2);
    printf("자동차를 골라보세요!");
    SetCurrentCursorPos(x, y+4);
    printf("자동차 : ");
    scanf("%d", &carNumber);
    if (carNumber > 5) {
        carNumber = 1;
    }
    carNumber--;
}

void gameBoardInfo() {
    int x, y;
    x = 80;
    y = 3;
    for (int i = 0; i < 28; i++) {
        SetCurrentCursorPos(x-3, 2 + i);
        printf("|");
    }
    SetCurrentCursorPos(x, y);
    printf("<%s's GAME>", userName);
    SetCurrentCursorPos(x, y+2);
    printf("---CAR---");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            SetCurrentCursorPos(j + x - 0.5, i + y+3);
            printf("%c", car[carNumber][i][j]);
        }
    }
    y += 8;
    SetCurrentCursorPos(x, y);
    printf("---------");
    SetCurrentCursorPos(x, y+2);
    printf("---ITEM---");
    SetCurrentCursorPos(x, y+7);
    printf("----------");
    SetCurrentCursorPos(x, y+9);
    printf("SPEED : %d", speed);
    SetCurrentCursorPos(x, y + 11);
    printf("SCORE : %d", score);
    SetCurrentCursorPos(x, y + 13);
    printf("HEART ");
    for (int i = 0; i < heart; i++) {
        printf("♥");
    }
    for (int i = 5; i > heart; i--) {
        printf("♡");
    }
    SetCurrentCursorPos(x, y + 15);
    printf("TIME : %d", gameTime);
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

    for (int i = 0, j = 0; i < 360; j++, i += 8) {
        y = sin(i * 3.14 / 180);

        ly = y * 20 + 20.0;
        ry = y * 20 + 55.0;

        road[j][0] = ly;
        road[j][1] = ry;
    }
}

void show_road() {
    int road_idx = 0;
    int j;
    int i, k;
    
    for (j = 0, i = road_idx; j < lines; i++, j++) {
        i = i % lines;
        gotoxy((int)road[i][0], j);
        printf("*");
        gotoxy((int)road[i][1], j);
        printf("*");
    }
    Sleep(100);
    for (j = 0, i = road_idx; j < lines; i++, j++) {
        i = i % lines;
        gotoxy((int)road[i][0], j);
        printf(" ");
        gotoxy((int)road[i][1], j);
        printf(" ");
    }
    

    road_idx++;
    Sleep(speed);

    while (1) {
        
        for (k = lines - road_idx, j = 0; j < lines; j++, k++) {
            k = k % lines;
            gotoxy(road[k][0], j);
            printf("*");
            gotoxy(road[k][1], j);
            printf("*");
        }
        Sleep(speed);
        for (k = lines - road_idx, j = 0; j < lines; j++, k++) {
            k = k % lines;
            gotoxy(road[k][0], j);
            printf(" ");
            gotoxy(road[k][1], j);
            printf(" ");
        }
        road_idx++;
       
        if (road_idx > lines) {
            road_idx = 1;
            setRoad();
        }
        for (int i = 0; i < 20; i++) {
            ProcessKeyInPut();
           
        }
    }
}





int main() {    
    sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
    system(command);

    
    RemoveCursor();
    
   // initScreen();
    int key;
    key = _getch();
   // eraseScreen();
   // gameInfoSelect();

    //eraseScreen();
    countMotion();
    eraseScreen();
    
    gameBoardInfo();
    
    SetCurrentCursorPos(curPosX, curPosY);
    showCar(car[carNumber]);
    while (1) {
        setRoad();
        show_road();
        
    }
    

    gameOver(score);
    //key = _getch();
    

}