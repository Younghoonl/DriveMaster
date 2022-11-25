#pragma once
#include <Windows.h>
#include <stdbool.h>
#include <time.h>


#define LEFT 75
#define RIGHT 77
#define SPACE 32

extern int curPosX;
extern int curPosY;
extern int carNumber;
extern char car[4][5][9];

extern clock_t itemTimeStart;
extern clock_t itemTimeEnd;

extern void useItem();

static COORD curPos;

bool LeftRightChange = false;

static void SetCurrentCursorPos(int x, int y) {
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

static COORD GetCurrentCursorPos(void) {
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X = curInfo.dwCursorPosition.X;
    curPoint.Y = curInfo.dwCursorPosition.Y;

    return curPoint;
}

void showCar(char carBlock[5][9]) {
    int x, y;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            textcolor(15, 0);
            printf("%c", carBlock[y][x]);
        }

    }
}
void DeleteCar(char carBlock[5][9]) {
    int y, x;
    COORD curPos = GetCurrentCursorPos();
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 9; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf(" ");
        }
    }
}


void ShiftLeft() {
    DeleteCar(car[carNumber]);
    curPosX -= 2;
    SetCurrentCursorPos(curPosX, curPosY);
    showCar(car[carNumber]);
}
void ShiftRight() {
    DeleteCar(car[carNumber]);
    curPosX += 2;
    SetCurrentCursorPos(curPosX, curPosY);
    showCar(car[carNumber]);
}

void ProcessKeyInPut() {
    int key;
    if (_kbhit() != 0) {
        key = _getch();
        switch (key) {
        case LEFT:
            
            if (LeftRightChange == false) {
                ShiftLeft();
            }
            else {
                ShiftRight();
            }
            break;
        case RIGHT:
            
            if (LeftRightChange == false) {
                ShiftRight();               
            }
            else {
                ShiftLeft();
            }
            break;
        case SPACE:
            useItem();
            itemTimeStart = clock();
            break;
        default:
            break;
        }
       
    }
}