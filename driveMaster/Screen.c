#define GBOARD_WIDTH 150
#define GBOARD_HEIGHT 40

extern char car[4][5][9];

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