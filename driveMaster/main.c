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

int curPosX = 25;
int curPosY = 31;

clock_t start;
clock_t end;

char userName[30];
int score = 0;
int speed = 100;
int carNumber=0;
int item; // 현재 아이템
int heart = 5; // 초기 목숨
int gameTime = 0;

int lines = 40;
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
    SetCurrentCursorPos(x, y);
    for (int i = 0; i < 80; i++) {
        printf("*");
    }
    SetCurrentCursorPos(x, y + 25);
    for (int i = 0; i < 80; i++) {
        printf("*");
    }
    SetCurrentCursorPos(x, y + 12);
    for (int i = 0; i < 80; i++) {
        printf("*");
    }
    int curPosX = 43;
    int curPosY = 26;
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
    SetCurrentCursorPos(60, 10);
    printf("[정보를 입력하세요!]");
    SetCurrentCursorPos(63, 22);
    printf("[자동차 종류]");
    x = 38;
    y = 12;
    SetCurrentCursorPos(x, y);
    printf("이름 : ");
    SetCurrentCursorPos(x, y+3);
    printf("자동차 : ");
    SetCurrentCursorPos(x+7, y);
    scanf("%s", &userName);
    SetCurrentCursorPos(x + 10, y+3);
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
        ry = y * 20 + 55.0;

        road[j][0] = ly+5; // 왼쪽부터 5 떨어짐
        road[j][1] = ry +10;
    }
}

showObstacle(int Obstacle[]) {
    printf("%s", Obstacle);
}
deleteObstacle(int Obstacle[]) {
    printf("%s", Obstacle);
}

void show_road() {
    int road_idx = 0;
    int j=0;
    int i, k=0;
    //Sleep(speed);
    srand(time(NULL)); // 매번 다른 시드값 생성
    int randomObstacle1 = rand() % 3; // 난수 생성
    //int randomObstacle = 0;
    int obstacleX1;
    int obstacleY1=0;
    int randomLocationX1 = rand() % 8;

    int randomObstacle2 = rand() % 3; // 난수 생성
    int obstacleX2;
    int obstacleY2 = 15;
    int randomLocationX2 = rand() % 8;

    int itemX;
    int itemY = 25;


    while (1) {
        for (k = 45 - road_idx, j = 0; j < 45; j++, k++) {
            k = k % 45;

            if (k == 3) {
                obstacleX1 = road[k][0] + randomLocationX1;
                gotoxy(obstacleX1, obstacleY1);
                showObstacle(Obstacles[randomObstacle1]);
            }

            if (k == 10) {
                obstacleX2 = road[k][0] + randomLocationX2;
                gotoxy(obstacleX2, obstacleY2);
                showObstacle(Obstacles[randomObstacle2]);
            }

            if (k == 20) {
                int itemX = road[k][0]+1;
                gotoxy(itemX, itemY);
                printf("%s       %s       %s", itemIcon, itemIcon, itemIcon);
            }
            gotoxy(road[k][0], j);
            printf("*");
            
            gotoxy(road[k][1], j);
            printf("*");
        }

        Sleep(speed);

        //deleteObstacle(Obstacles[randomObstacle]);
        for (k = 45 - road_idx, j = 0; j < 45; j++, k++) {
            k = k % 45;
            if (k == 3) {
                obstacleX1 = road[k][0] + randomLocationX1;
                gotoxy(obstacleX1, obstacleY1);
                deleteObstacle(Obstacles[7]);
            }
            if (k == 10) {
                obstacleX2 = road[k][0] + randomLocationX2;
                gotoxy(obstacleX2, obstacleY2);
                deleteObstacle(Obstacles[7]);
            }
            if (k == 20) {
                int itemX = road[k][0] + 1;
                gotoxy(itemX, itemY);
                printf("                       ");
                 
            }
            gotoxy(road[k][0], j);
            printf(" ");
            
            gotoxy(road[k][1], j);
            printf(" ");
        }
        
        obstacleY1++;
        obstacleY2++;
        itemY++;
        for (int i = 0; i < 30; i++) {
            ProcessKeyInPut();
        }
        end = clock();
        gameTime = (double)(end - start) / CLOCKS_PER_SEC; //초단위 변환
        gameBoardInfo();
        road_idx++;
        if (road_idx > 45) {
            road_idx = 1;
            setRoad();
            randomObstacle1 = rand() % 3;
            obstacleY1 = 0;
            randomLocationX1 = rand() % 8;

            randomObstacle2 = rand() % 3;
            obstacleY2 = 15;
            randomLocationX2 = rand() % 8;

            itemY = 25;
        }
        if (gameTime > 60) {
            break;
        }
    }
}





int main() {    
    sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
    system(command);
    
    initScreen();
    int key;
    key = _getch();
    eraseScreen();
    gameInfoSelect();
    RemoveCursor();
    eraseScreen();
    countMotion();
    eraseScreen();
    
    gameBoardInfo();
   
    SetCurrentCursorPos(curPosX, curPosY);
    start = clock();
    
    showCar(car[carNumber]);
    setRoad();
    show_road();
    
    gameOver(score);

}