#include "Items.h"
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

#define BLACK 0 
#define YELLOW 14 
#define WHITE 15 

extern double road[360][3];
extern int item;
extern bool LeftRightChange;
bool BoostChange = false;
bool CarChange = false;
extern int speed;
extern int carNumber;

extern clock_t itemTimeStart;
extern clock_t itemTimeEnd;


typedef struct ObstacleStruct {
    int rN; // randomNumber
    int x;
}obstacle;

typedef struct ItemStruct {
    int x, y;
}itemStruct;

void textcolor(int foreground, int background)
{
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



void showObstacles1(obstacle ob) {
    
    printf("%s", Obstacles[ob.rN]);

}



void deleteObstacles1(obstacle ob) {

    printf("%s", Obstacles[3]);

}


void showItem(itemStruct it) {
    if (it.y > 44) {
        return;
    }

    for (int i = 0; i <= 2; i++) {
        gotoxy(it.x + 15 * i, it.y);
        printf("%s", itemIcon);
    }
}

void deleteItem(itemStruct it) {

    if (it.y > 40) {
        return;
    }

    for (int i = 1; i <= 3; i++) {
        gotoxy(it.x + 15 * i, it.y);
        printf("   ", itemIcon);
    }
}


// ������ ��� �Լ�
void useItem() {
    /*
    * �ʱ� item = 0 , item�� collision �Ŀ� item 1~3�߿� �ϳ� ���� -> space Ű ������, ���
    * item 0 : �������� �������� ����
    * item 1 : Ű �¿� ��ȯ
    * item 2 : �ν���
    * item 3 : �ڵ��� ��ȯ
    */
    if (item == 0) {
        return; // �ƹ� �ϵ� �Ͼ�� ����
    }
    else if (item == 1) {
        // key ��ȯ
        LeftRightChange = true;
    }
    else if (item == 2) {
        // �ν���
        BoostChange = true;
        speed = 5;
    }
    else if (item == 3) {
        CarChange = true;
        carNumber = 4;
    }
    item = 0;



}