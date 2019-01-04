#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

class snake {
public:
	int ntail;
	int x;
	int y;
	int score;
	int tailX[200];
	int tailY[200];
	bool visit;
};

class fruits {
public:
	int x;
	int y;
};
snake snk1;
snake snk2;
fruits fruit;
fruits wrong;
fruits GameO;

bool gameOver;
int width;
int height;
enum  eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum  eDirection2 { STOP2 = 0, LEFT2, RIGHT2, UP2, DOWN2 };
eDirection dir;
eDirection2 dir2;


void Setup() {
	gameOver = false;
	dir = STOP;
	dir2 = STOP2;
	snk1.x = width / 2 - 2 ;
	snk1.y = height / 2 ;
	snk2.x = width / 2 + 2;
	snk2.y = height / 2 ;
	fruit.x = rand() % width;
	fruit.y = rand() % height;
	wrong.x = rand() % width;
	wrong.y = rand() % height;
	GameO.x = rand() % width;
	GameO.y = rand() % height;
	snk1.score = 0;
	snk2.score = 0;
}

void Draw() {

	COORD position;
	position.X = 0;
	position.Y = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < width; i++) {
		cout << "*";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width - 1; j++) {
			if (j == 0 || j == width - 2) {
				cout << "*";
			}
			if (i == snk1.y && j == snk1.x) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
				cout << "1";
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
			}
			else if (i == snk2.y && j == snk2.x) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
				cout << "2";
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
			}
			else if (i == fruit.y && j == fruit.x) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
				cout << "F";
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
			}
			else if (i == wrong.y && j == wrong.x) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 6));
				cout << "W";
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
			}
			else if (i == GameO.y && j == GameO.x) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 3));
				cout << "G";
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
			}
			else {
				bool print = false;
				for (int k = 0; k < snk1.ntail; k++) {
					if (snk1.tailX[k] == j && snk1.tailY[k] == i) {
						print = true;
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
						cout << "o";
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
					}
				}
				for (int k1 = 0; k1 < snk2.ntail; k1++) {
					if (snk2.tailX[k1] == j && snk2.tailY[k1] == i) {
						print = true;
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
						cout << "o";
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
					}
				}
				if (!print) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width; i++) {
		cout << "*";
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
	cout << "Score 1 : " << snk1.score << endl;
	cout << "Score 2 : " << snk2.score << endl;
	cout << "ntail :" << snk1.ntail << endl;
	cout << "ntail2 :" << snk2.ntail << endl;

}

void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
		case 'j':
			dir2 = LEFT2;
			break;
		case 'l':
			dir2 = RIGHT2;
			break;
		case 'i':
			dir2 = UP2;
			break;
		case 'k':
			dir2 = DOWN2;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() {
	int prevX = snk1.tailX[0];
	int prevY = snk1.tailY[0];
	int prev2X, prev2Y;
	snk1.tailX[0] = snk1.x;
	snk1.tailY[0] = snk1.y;
	for (int i = 1; i <snk1.ntail; i++) {
		prev2X = snk1.tailX[i];
		prev2Y = snk1.tailY[i];
		snk1.tailX[i] = prevX;
		snk1.tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}
		int prevX2 = snk2.tailX[0];
		int prevY2 = snk2.tailY[0];
		int prev2X2, prev2Y2;
		snk2.tailX[0] = snk2.x;
		snk2.tailY[0] = snk2.y;
		for (int i = 1; i < snk2.ntail; i++) {
			prev2X2 = snk2.tailX[i];
			prev2Y2 = snk2.tailY[i];
			snk2.tailX[i] = prevX2;
			snk2.tailY[i] = prevY2;
			prevX2 = prev2X2;
			prevY2 = prev2Y2;

	}
	switch (dir)
	{
	case LEFT:
		snk1.x--;
		break;
	case RIGHT:
		snk1.x++;
		break;
	case UP:
		snk1.y--;
		break;
	case DOWN:
		snk1.y++;
		break;
	}
	switch (dir2)
	{
	case LEFT2:
		snk2.x--;
		break;
	case RIGHT2:
		snk2.x++;
		break;
	case UP2:
		snk2.y--;
		break;
	case DOWN2:
		snk2.y++;
		break;
	}
	for (int d = 0; d < snk2.ntail; d++) {
		if (snk1.x == snk2.tailX[d] && snk1.y == snk2.tailY[d]) {
			snk2.visit = true;
		}
	}

	for (int d = 0; d < snk1.ntail; d++) {
		if (snk2.x == snk1.tailX[d] && snk2.y == snk1.tailY[d]) {
			snk1.visit = true;
		}
	}


	if (snk1.x > width || snk1.x < 0 || snk1.y > height || snk1.y < 0)
		gameOver = true;


	if (snk2.x > width || snk2.x < 0 || snk2.y > height || snk2.y < 0)
		gameOver = true;

	for (int i = 0; i < snk1.ntail; i++) {
		if (snk1.tailX[i] == snk1.x && snk1.tailY[i] == snk1.y)
			gameOver = true;
	}


	if (snk1.x == fruit.x && snk1.y == fruit.y) {
		fruit.x = rand() % width;
		fruit.y = rand() % height;
		snk1.ntail++;
		snk1.score += 10;
	}
	if (snk1.x == wrong.x && snk1.y == wrong.y) {
		if (snk1.ntail >= 3) {
			wrong.x = rand() % width;
			wrong.y = rand() % height;
			snk1.ntail -= 3;
			snk1.score -= 30;
		}
		else {
			wrong.x = rand() % width;
			wrong.y = rand() % height;
			gameOver = true;
		}
	}
	if (snk1.x == GameO.x && snk1.y == GameO.y) {
		GameO.x = rand() % width;
		GameO.y = rand() % height;
		gameOver = true;
	}
	for (int i = 0; i < snk2.ntail; i++) {
		if (snk2.tailX[i] == snk2.x && snk2.tailY[i] == snk2.y)
			gameOver = true;
	}

	if (snk2.x == fruit.x && snk2.y == fruit.y) {
		fruit.x = rand() % width;
		fruit.y = rand() % height;
		snk2.ntail++;
		snk2.score += 10;
	}
	if (snk2.x == wrong.x && snk2.y == wrong.y) {
		if (snk2.ntail >= 3) {
			wrong.x = rand() % width;
			wrong.y = rand() % height;
			snk2.ntail -= 3;
			snk2.score -= 30;
		}
		else {
			wrong.x = rand() % width;
			wrong.y = rand() % height;
			gameOver = true;
		}
	}
	if (snk2.x == GameO.x && snk2.y == GameO.y) {
		GameO.x = rand() % width;
		GameO.y = rand() % height;
		gameOver = true;
	}
	if (snk2.visit) {
		snk2.ntail = 0;
		snk2.visit = false;
	}
	if (snk1.visit) {
		snk1.ntail = 0;
		snk1.visit = false;
	}
}


void selectLevel() {
	cout << "Select difficulty level :" << endl;
	cout << "1. low" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Hight" << endl;
	int o;
	cin >> o;
	switch (o)
	{
	case 1:
		width = 60;
		height = 30;
		break;
	case 2:
		width = 40;
		height = 20;
		break;
	case 3:
		width = 30;
		height = 20;
		break;
	}

}



void play() {
	selectLevel();
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}
}


void resGame() {
	int	res = 1 ;
	while (res == 1) {
		cout << endl << "game over :( " << endl << " Score 1 :" << snk1.score << endl << "Score 2 :" << snk2.score << endl;
		cout << " Do You Want To Retry? :) " << endl;
		cout << "1. Yes " << endl;
		cout << "2. No " << endl;
		cin >> res;
		system("cls");
		if ( res == 1 ) play();
	}

	
}

int main() {
	play();
	resGame();
	return 0;
}