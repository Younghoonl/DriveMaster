#pragma once
#include <Windows.h>

#define LEFT 75
#define RIGHT 77

extern int curPosX;
extern int curPosY;
extern int carNumber;
extern char car[4][5][9];

static COORD curPos;

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
            ShiftLeft();
            break;
        case RIGHT:
            ShiftRight();
            break;
        default:
            break;
        }
       
    }
}