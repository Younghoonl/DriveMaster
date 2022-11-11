
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
