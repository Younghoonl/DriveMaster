#define GBOARD_WIDTH 200
#define GBOARD_HEIGHT 150

extern char car[4][5][9];

void initScreen() {
    /* ���� �̸� start ��ư ���� */
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
    printf("**�� �� �� �� ��**");
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
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 70; j++) {
            printf(" ");
        }
    }
}



void countMotion() {
    /* ���� ���� �� READY 3 - 2 - 1 ��� */
    int x, y;
    x = 30;
    y = 10;
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
    x = 40;
    y = 6;
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
    printf("* * * * * *  ");
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
    printf("* * * * * *  ");
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
    printf("�ٽ� �����ϼ���!");
    SetCurrentCursorPos(29, 14);
    printf("����� ���� : ", score);

}