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

//typedef struct ObstacleStruct {
//    int rN; // randomNumber
//    int x, y, k;
//}obstacle;

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

//void showObstacles(obstacle ob[5]) {
//    for (int i = 0; i < 5; i++) {
//        if (ob[i].y > 40) {
//            continue;
//        }
//        int obX = ob[i].x + road[ob[i].k][0] + 5;
//        int obY = ob[i].y % 45;
//        gotoxy(obX, obY);
//        textcolor(YELLOW, BLACK);
//        printf("%s", Obstacles[ob[i].rN]);
//    }
//
//}

void showObstacles1(obstacle ob) {
   /* for (int i = 0; i < 5; i++) {
        if (ob > 40) {
            continue;
        }
        int obX = ob[i].x + road[ob[i].k][0] + 5;
        int obY = ob[i].y % 45;
        gotoxy(obX, obY);
        textcolor(YELLOW, BLACK);*/
        printf("%s", Obstacles[ob.rN]);

}


//void deleteObstacles1(obstacle ob) {
//    for (int i = 0; i < 5; i++) {
//        if (ob[i].y > 40) {
//            continue;
//        }
//        int obX = ob[i].x + road[ob[i].k][0] + 5;
//        int obY = ob[i].y % 45;
//        gotoxy(obX, obY);
//        printf("%s", Obstacles[3]);
//    }
//    
//}

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


// 아이템 사용 함수
void useItem() {
    /*
    * 초기 item = 0 , item과 collision 후에 item 1~3중에 하나 지정 -> space 키 누르면, 사용
    * item 0 : 아이템이 존재하지 않음
    * item 1 : 키 좌우 변환
    * item 2 : 부스터
    * item 3 : 자동차 변환
    */
    if (item == 0) {
        return; // 아무 일도 일어나지 않음
    }
    else if (item == 1) {
        // key 변환
        LeftRightChange = true;
    }
    else if (item == 2) {
        // 부스터
        BoostChange = true;
        speed = 5;
    }
    else if (item == 3) {
        CarChange = true;
        carNumber = 4;
    }
    item = 0;



}