#define GBOARD_WIDTH 200
#define GBOARD_HEIGHT 150

extern char car[4][5][9];

void initScreen() {
    /* 게임 이름 start 버튼 생성 */
    int x = 10;
    int y = 3;
    SetCurrentCursorPos(x, y);
    printf("*");
    for (int i = 0; i < 80; i++) {
        printf("*");
        Sleep(5);
    }
    printf("*");
    SetCurrentCursorPos(x, y+10);
    printf("*");
    for (int i = 0; i < 80; i++) {
        printf("*");
        Sleep(5);
    }
    printf("*");
    SetCurrentCursorPos(x, y + 20);
    printf("*");
    for (int i = 0; i < 80; i++) {
        printf("*");
        Sleep(5);
    }
    printf("*");
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
    int curPosX = 23;
    int curPosY = 17;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[0][y][x]);
        }
    }
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[1][y][x]);
        }
    }
    curPosX += 15;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 8; x++) {
            SetCurrentCursorPos(curPosX + x, curPosY + y);
            printf("%c", car[2][y][x]);
        }
    }
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
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 70; j++) {
            printf(" ");
        }
    }
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
