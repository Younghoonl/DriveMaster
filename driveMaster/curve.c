/*
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<math.h>

double road[36][2];
int road_idx =0;
int next_idx = 0;

void show_road();
void setRoad();
int gotoxy(int x, int y);

void main() 
{
	/*double y = 0;
	int x, b, lblk, rblk;

	while (1) {

		for (x = 0; x <= 360; x += 10) {
			y = sin(x * 3.14 / 180);

			lblk = y * 12 + 20;

			for (b = 0; b <= lblk; b++)
				printf(" ");
			printf("*                                *\n");
			Sleep(100);
			
		}
	}*/
/*
	setRoad();

	
	show_road();

}

int gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void setRoad() {

	double ly, ry;
	double y;

	for (int i = 0, j = 0; i < 360; j++, i += 10) {
		y = sin(i * 3.14 / 180);

		ly = y * 12 + 20.0;
		ry = y * 12 + 45.0;
		
		road[j][0] = ly;
		road[j][1] = ry;
	}
}

void show_road() {

	gotoxy((int)road[(road_idx + 1) % 36][0], 1);
	printf("  ");
	gotoxy((int)road[(road_idx + 1) % 36][1], 1);
	printf("  ");
	
	if (road_idx == 0)
		next_idx = 35;
	else
		next_idx = road_idx - 1;

	for (int j = 1, i = road_idx; j < 37; i++, j++) {
		i = i % 36;
		gotoxy((int)road[i][0], j);
		printf("*");
		gotoxy((int)road[i][1], j);
		printf("*");
		Sleep(100);
	}
	road_idx = next_idx;
	
}

*/