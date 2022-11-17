z
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