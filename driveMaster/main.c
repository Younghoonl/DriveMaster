#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define GBOARD_WIDTH 100
#define GBOARD_HEIGHT 80

char userName[30];
int score = 0;
int speed = 0;
int carNumber;
int item; // 현재 아이템
int heart = 5; // 초기 목숨
int gameTime = 0;

void SetCurrentCursorPos(int x, int y){
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

COORD GetCurrentCursorPos(void){
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

void initScreen() { 
	/* 게임 이름 start 버튼 생성 */
    SetCurrentCursorPos(9, 1);
    printf("*");
    for (int i = 0; i < 60; i++) {
        printf("*");
        Sleep(5);
    }
    printf("*");
    SetCurrentCursorPos(9, 11);
    printf("*");
    for (int i = 0; i < 60; i++) {
        printf("*");
        Sleep(5);
    }
    printf("*");
    SetCurrentCursorPos(9, 20);
    printf("*");
    for (int i = 0; i < 60; i++) {
        printf("*");
        Sleep(5);
    }
    printf("*");
    SetCurrentCursorPos(12, 3);
    printf("* *       * * *       * * *   *           *  * * * * *");
    SetCurrentCursorPos(12, 4);
    printf("*   *     *     *       *      *         *   *");
    SetCurrentCursorPos(12, 5);
    printf("*     *   *     *       *       *       *    * ");
    SetCurrentCursorPos(12, 6);
    printf("*     *   * * *         *        *     *     * * * * *   ");
    SetCurrentCursorPos(12, 7);
    printf("*     *   *     *       *         *   *      *");
    SetCurrentCursorPos(12, 8);
    printf("*   *     *       *     *          * *       * ");
    SetCurrentCursorPos(12, 9);
    printf("* *       *        *  * * *         *        * * * * *");
    Sleep(100);
    SetCurrentCursorPos(30, 14);
    //Sleep(1000);
    printf("**운 전 의 달 인**");
    SetCurrentCursorPos(36, 16);
    printf(" G O!");
    
    
}

void eraseScreen() {
    SetCurrentCursorPos(9, 1);
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 70; j++) {
            printf(" ");
        }
    }
}

void gameInfoSelect() {
	/* 유저 이름, 자동차 선택 */
    SetCurrentCursorPos(9, 1);
    for (int i = 0; i < 60; i++) {
        printf("*");
    }
    SetCurrentCursorPos(9, 20);
    for (int i = 0; i < 60; i++) {
        printf("*");
    }

    SetCurrentCursorPos(12, 3);
    printf("이름 : ");
    scanf("%s", &userName);
    SetCurrentCursorPos(12, 5);
    printf("자동차 : ");
    scanf("%d", &carNumber);
}

void countMotion() {
	/* 게임 시작 전 3 - 2 - 1 재생 */

    SetCurrentCursorPos(12, 4);
    printf("* * *   * * *      *     * *     *     *");
    SetCurrentCursorPos(12, 5);
    printf("*    *  *         * *    *   *    *   *");
    SetCurrentCursorPos(12, 6);
    printf("* * *   * * *    * * *   *    *     *");
    SetCurrentCursorPos(12, 7);
    printf("* *     *       *     *  *   *      *");
    SetCurrentCursorPos(12, 8);
    printf("*    *  * * *  *       * * *        *");
    Sleep(2000);
    eraseScreen();
    SetCurrentCursorPos(12, 4);
    printf("* * * * * * ");
    SetCurrentCursorPos(12, 5);
    printf("* * * * * * * ");
    SetCurrentCursorPos(12, 6);
    printf("          * *");
    SetCurrentCursorPos(12, 7);
    printf("          * *");
    SetCurrentCursorPos(12, 8);
    printf("* * * * * * ");
    SetCurrentCursorPos(12, 9);
    printf("* * * * * * * ");
    SetCurrentCursorPos(12, 10);
    printf("          * *");
    SetCurrentCursorPos(12, 11);
    printf("          * *");
    SetCurrentCursorPos(12, 12);
    printf("* * * * * * *");
    SetCurrentCursorPos(12, 13);
    printf("* * * * * *  ");
    SetCurrentCursorPos(12, 15);
    Sleep(1000);
    eraseScreen();
    SetCurrentCursorPos(12, 4);
    printf("* * * * * * ");
    SetCurrentCursorPos(12, 5);
    printf("* * * * * * * ");
    SetCurrentCursorPos(12, 6);
    printf("          * *");
    SetCurrentCursorPos(12, 7);
    printf("         * *");
    SetCurrentCursorPos(12, 8);
    printf("        * *");
    SetCurrentCursorPos(12, 9);
    printf("      * *");
    SetCurrentCursorPos(12, 10);
    printf("    * *");
    SetCurrentCursorPos(12, 11);
    printf(" * *");
    SetCurrentCursorPos(12, 12);
    printf("* * * * * * *");
    SetCurrentCursorPos(12, 13);
    printf("* * * * * *  ");
    SetCurrentCursorPos(12, 14);
    Sleep(1000);
    eraseScreen();
    SetCurrentCursorPos(14, 4);
    printf("* *");
    SetCurrentCursorPos(14, 5);
    printf("* *");
    SetCurrentCursorPos(14, 6);
    printf("* *");
    SetCurrentCursorPos(14, 7);
    printf("* *");
    SetCurrentCursorPos(14, 8);
    printf("* *");
    SetCurrentCursorPos(14, 9);
    printf("* *");
    SetCurrentCursorPos(14, 10);
    printf("* *");
    SetCurrentCursorPos(14, 11);
    printf("* *");
    SetCurrentCursorPos(14, 12);
    printf("* *");
    SetCurrentCursorPos(14, 13);
    printf("* *");
    SetCurrentCursorPos(14, 14);
    Sleep(1000);
    

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
void gameOver() {
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
    key = _getch();
    eraseScreen();
    gameOver();
    key = _getch();
}