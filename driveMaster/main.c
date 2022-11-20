#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "Car.h"
#include "Items.h"
#include <math.h>
#include <conio.h>

#define COMMAND_SIZE 256

double road[44][2];

char command[COMMAND_SIZE] = { '\0', };

int curPosX = 28;
int curPosY = 33;

clock_t start;
clock_t end;

char userName[30];
int score = 0;
int speed = 100;
int carNumber=0;
int item; // 현재 아이템
int heart = 5; // 초기 목숨
int gameTime = 0;

int lines = 43;
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
    int x = 32;
    int y = 8;
    int ScreenX, ScreenY;
    ScreenX = 4;
    ScreenY = 1;

    SetCurrentCursorPos(ScreenX, ScreenY);
    for (int i = 0; i < 142; i++) {
        printf("*");
    }
    for (int i = ScreenY + 1; i < 38; i++) {
        SetCurrentCursorPos(ScreenX + 141, i);
        printf("*");
    }
    for (int i = 143; i > 4; i--) {
        SetCurrentCursorPos(i, 37);
        printf("*");
    }
    for (int i = 37; i > ScreenY; i--) {
        SetCurrentCursorPos(ScreenX, i);
        printf("*");
    }
    SetCurrentCursorPos(41, 20);
    for (int i = 0; i < 30; i++) {
        printf("〓");
    }

    SetCurrentCursorPos(38, 7);
    for (int i = 0; i < 34; i++) {
        printf("〓");
    }

    int curPosX = 43;
    int curPosY = 24;
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
    SetCurrentCursorPos(60, 7);
    printf("[정보를 입력하세요!]");
    SetCurrentCursorPos(63, 20);
    printf("[자동차 종류]");
    x = 38;
    y = 11;
    SetCurrentCursorPos(x, y);
    printf("이름 : ");
    SetCurrentCursorPos(x, y+3);
    printf("자동차 (1~4 중 선택) : ");
    SetCurrentCursorPos(x+7, y);
    scanf("%s", &userName);
    SetCurrentCursorPos(x + 25, y+3);
    scanf("%d", &carNumber);
    if (carNumber > 5) {
        carNumber = 1;
    }
    carNumber--;
}

void gameBoardInfo() {
    int x, y;
    x = 122;
    y = 8;
    for (int i = 0; i < 32; i++) {
        SetCurrentCursorPos(x-5, 4+ i);
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
        ry = y * 20 + 60.0;

        road[j][0] = ly+5; // 왼쪽부터 5 떨어짐
        road[j][1] = ry +10;
    }
}


typedef struct ObstacleStruct {
    int rN; // randomNumber
    int x, y, k;
}obstacle;

typedef struct ItemStruct {
    int x, y;
}itemStruct;

void showObstacles(obstacle ob[5]) {
    for (int i = 0; i < 5; i++) {
        if (ob[i].y > 40) {
            continue;
        }
        int obX = ob[i].x + road[ob[i].k][0] +5;
        int obY = ob[i].y % 45;
        gotoxy(obX,obY);
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
    gotoxy(it.x, it.y);
    if (it.y > 40) {
        return;
    }
    printf("      %s           %s          %s", itemIcon, itemIcon, itemIcon); 

}

void deleteItem(itemStruct it) {
    gotoxy(it.x, it.y);
    if (it.y > 40) {
        return;
    } 
    printf("                                 ");
}


void show_road() {
    int road_idx = 0;
    int j=0;
    int i, k=0;
    srand(time(NULL)); // 매번 다른 시드값 생성

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
        for (k = 45 - road_idx, j = 0; j < 45; j++, k++) {
            k = k % 45;
            gotoxy(road[k][0], j);
            printf("*");
            gotoxy(road[k][1], j);
            printf("*");
        }

        Sleep(speed);
        deleteItem(it);
        deleteObstacles(ob);
        for (k = 45 - road_idx, j = 0; j < 45; j++, k++) {
            k = k % 45;
            gotoxy(road[k][0], j);
            printf(" ");
            gotoxy(road[k][1], j);
            printf(" ");
        }
        
       
        for (int i = 0; i < 50; i++) {
            ProcessKeyInPut();
        }

        end = clock();
        gameTime = (double)(end - start) / CLOCKS_PER_SEC; //초단위 변환
        gameBoardInfo();

        road_idx++;
        for (int i = 0; i < 5; i++) {
            ob[i].y++;
            if (ob[i].y > 45) {
                ob[i].y = 1;
            }
        }
        it.y++;


        if (road_idx > 45) {
            road_idx = 1;
            for (int i = 0; i < 5; i++) {
                ob[i].rN = rand() % 3;
                ob[i].x = rand() % 25;
                ob[i].y = rand() % 37;
                ob[i].k = ob[i].y;
            }
            it.x = road[1][0];
            it.y = 1;
            
        }
        if (gameTime > 50) {
            break;
        }
    }
}





int main() {    
    sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
    system(command);
    RemoveCursor();
    
    //initScreen();
    int key;
   // key = _getch();
    //eraseScreen();
    //gameInfoSelect();
    
    //eraseScreen();
    //countMotion();
    //eraseScreen();
    
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