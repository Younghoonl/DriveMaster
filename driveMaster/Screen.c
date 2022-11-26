#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>


#define GBOARD_WIDTH 150
#define GBOARD_HEIGHT 40

extern char userName[30];
extern int carNumber;
extern char car[4][5][9];
extern int score;
extern int speed;
extern int item; // 현재 아이템
extern int heart; // 초기 목숨
extern int gameTime;
extern int tmpCarNumber;
extern char Itemshape[3][3][15];

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

void gameBoardInfo() {
    int x, y;
    x = 122;
    y = 8;
    for (int i = 0; i < 32; i++) {
        SetCurrentCursorPos(x - 5, 4 + i);
        printf("|");
    }
    SetCurrentCursorPos(x, y);
    printf("<%s's GAME>", userName);
    SetCurrentCursorPos(x, y + 2);
    printf("---CAR---");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            SetCurrentCursorPos(j + x, i + y + 3);
            printf("  ");
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            SetCurrentCursorPos(j + x, i + y + 3);
            printf("%c", car[carNumber][i][j]);
        }
    }
    y += 8;
    SetCurrentCursorPos(x, y);
    printf("---------");
    SetCurrentCursorPos(x, y + 2);
    printf("---ITEM---");
    SetCurrentCursorPos(x, y + 3);
    //printf("%d", item);
    for (int i = 0; i < 3; i++) {
        SetCurrentCursorPos(x, y + 3 + i);
        printf("%s ", Itemshape[item][i]);
    }

    SetCurrentCursorPos(x, y + 7);
    printf("----------");
    SetCurrentCursorPos(x, y + 9);
    printf("SPEED : %d    ", speed);
    SetCurrentCursorPos(x, y + 11);
    printf("SCORE : %d     ", score);
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

int gameInfoSelect() {
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
    SetCurrentCursorPos(curPosX + x - 4, curPosY + y + 0.5);
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
    SetCurrentCursorPos(x, y + 3);
    printf("자동차 (1~4 중 선택) : ");
    SetCurrentCursorPos(x + 7, y);
    scanf("%s", &userName);
    SetCurrentCursorPos(x + 25, y + 3);
    scanf("%d", &carNumber);
    if (carNumber > 5) {
        carNumber = 1;
    }
    carNumber--;
    tmpCarNumber = carNumber;
    return carNumber;
}


void RemoveCursor() {
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}


void initScreen() {
    int ScreenX, ScreenY;
    ScreenX = 4;
    ScreenY = 1;
    
    SetCurrentCursorPos(ScreenX, ScreenY);
    for (int i = 0; i < 142; i++) {
        printf("*");
        Sleep(1);
    }
    for (int i = ScreenY + 1; i < 38; i++) {
        SetCurrentCursorPos(ScreenX + 141, i);
        printf("*");
        Sleep(1);
    }
    for (int i = 143; i > 4; i--) {
        SetCurrentCursorPos(i, 37);
        printf("*");
        Sleep(1);
    }
    for (int i = 37; i > ScreenY; i--) {
        SetCurrentCursorPos(ScreenX, i);
        printf("*");
        Sleep(1);
    }
    

    SetCurrentCursorPos(41, 6);
    for (int i = 0; i < 30; i++) {
        printf("〓");
    }
    SetCurrentCursorPos(41, 16);
    for (int i = 0; i < 30; i++) {
        printf("〓");
    }
    

    /* 게임 이름 start 버튼 생성  */
    
    int x = 32;
    int y = 6;
    x += 14;
    y -= 1;
    SetCurrentCursorPos(x, y + 3);
    printf("* *       * * *       * * *   *           *  * * * * *");
    SetCurrentCursorPos(x, y + 4);
    printf("*   *     *     *       *      *         *   *");
    SetCurrentCursorPos(x, y + 5);
    printf("*     *   *     *       *       *       *    * ");
    SetCurrentCursorPos(x, y + 6);
    printf("*     *   * * *         *        *     *     * * * * *   ");
    SetCurrentCursorPos(x, y + 7);
    printf("*     *   *     *       *         *   *      *");
    SetCurrentCursorPos(x, y + 8);
    printf("*   *     *       *     *          * *       * ");
    SetCurrentCursorPos(x, y + 9);
    printf("* *       *        *  * * *         *        * * * * *");
    Sleep(100);
    SetCurrentCursorPos(x+16, y + 13);
    //Sleep(1000);
    printf("**운 전 의 달 인**");
    SetCurrentCursorPos(x+30, 16);
    int curPosX = 43;
    int curPosY = 24;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[0][y][x]);
        }
    }
    Sleep(100);
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[1][y][x]);
        }
    }
    Sleep(100);
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[2][y][x]);
        }
    }
    Sleep(100);
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[3][y][x]);
        }
    }
}

void eraseScreen() {
    SetCurrentCursorPos(9, 1);
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 150; j++) {
            printf(" ");
        }
    }
}


void countMotion() {
    /* 게임 시작 전 READY 3 - 2 - 1 재생 */
    int x, y;
    x = 52;
    y = 15;
    int tmp = y;
    SetCurrentCursorPos(x, y++);
    printf("* * *   * * *      *     * *     *     *");
    SetCurrentCursorPos(x, y++);
    printf("*    *  *         * *    *   *    *   *");
    SetCurrentCursorPos(x, y++);
    printf("* * *   * * *    * * *   *    *     *");
    SetCurrentCursorPos(x, y++);
    printf("* *     *       *     *  *   *      *");
    SetCurrentCursorPos(x, y++);
    printf("*    *  * * *  *       * * *        *");
    Sleep(1500);
    eraseScreen();
    x = 64;
    y = 7;
    y = tmp;
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * ");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * * ");
    SetCurrentCursorPos(x, y++);
    printf("          * *");
    SetCurrentCursorPos(x, y++);
    printf("          * *");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * ");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * * ");
    SetCurrentCursorPos(x, y++);
    printf("          * *");
    SetCurrentCursorPos(x, y++);
    printf("          * *");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * *");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * ");
    SetCurrentCursorPos(x, y++);
    Sleep(1000);
    eraseScreen();
    y = tmp;
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * ");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * * ");
    SetCurrentCursorPos(x, y++);
    printf("          * *");
    SetCurrentCursorPos(x, y++);
    printf("         * *");
    SetCurrentCursorPos(x, y++);
    printf("        * *");
    SetCurrentCursorPos(x, y++);
    printf("      * *");
    SetCurrentCursorPos(x, y++);
    printf("    * *");
    SetCurrentCursorPos(x, y++);
    printf(" * *");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * *");
    SetCurrentCursorPos(x, y++);
    printf("* * * * * * * ");
    SetCurrentCursorPos(x, y++);
    Sleep(1000);
    eraseScreen();
    x += 2;
    y = tmp;
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    printf("* *");
    SetCurrentCursorPos(x, y++);
    Sleep(1000);


}


void gameOver(int score) {
    int x = 58;
    int y = 15;
    SetCurrentCursorPos(x, y);
    for (int i = 0; i < 28; i++) {
        printf("*");
        Sleep(5);
    }

    SetCurrentCursorPos(x, y+8);
    for (int i = 0; i < 28; i++) {
        printf("*");
        Sleep(5);
    }

    SetCurrentCursorPos(x+8, y+2);
    printf("game over!");
    SetCurrentCursorPos(x+6, y+4);
    printf("다시 도전하세요!");
    SetCurrentCursorPos(x+2, y+6);
    printf("당신의 점수 : ", score);

    SetCurrentCursorPos(x, y+10);

}