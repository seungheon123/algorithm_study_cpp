#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;

int map[20][20];


int dice[6] = { 0 };

void rollEast(int x, int y) {
	int d1 = dice[0]; int d2 = dice[2]; int d3 = dice[4]; int d4 = dice[5];
	dice[2] = d1;
	dice[0] = d3;
	dice[4] = d4;
	dice[5] = d2;
	if (map[x][y] == 0) {
		map[x][y] = dice[5];
	}
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
}

void rollWest(int x, int y) {
	int d1 = dice[0]; int d2 = dice[2]; int d3 = dice[4]; int d4 = dice[5];
	dice[4] = d1;
	dice[0] = d2;
	dice[2] = d4;
	dice[5] = d3;
	if (map[x][y] == 0) {
		map[x][y] = dice[5];
	}
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}

}

void rollNorth(int x, int y) {
	int d1 = dice[0]; int d2 = dice[1]; int d3 = dice[3]; int d4 = dice[5];
	dice[3] = d1;
	dice[0] = d2;
	dice[1] = d4;
	dice[5] = d3;
	if (map[x][y] == 0) {
		map[x][y] = dice[5];
	}
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
}

void rollSouth(int x, int y) {
	int d1 = dice[0]; int d2 = dice[1]; int d3 = dice[3]; int d4 = dice[5];
	dice[1] = d1;
	dice[0] = d3;
	dice[3] = d4;
	dice[5] = d2;
	if (map[x][y] == 0) {
		map[x][y] = dice[5];
	}
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
}

int main() {
	cin >> n >> m >> x >> y >> k;
	int a, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}

	}

	int move;
	for (int i = 0; i < k; i++) {
		cin >> move;
		if (move == 1) {
			if (y + 1 < m) {
				y++;
				rollEast(x, y);
				cout << dice[0] << endl;
			}
		}
		else if (move == 2) {
			if (y - 1 >= 0) {
				y--;
				rollWest(x, y);
				cout << dice[0] << endl;
			}
		}
		else if (move == 3) {
			if (x - 1 >= 0) {
				x--;
				rollNorth(x, y);
				cout << dice[0] << endl;
			}
		}
		else if (move == 4) {
			if (x + 1 < n) {
				x++;
				rollSouth(x, y);
				cout << dice[0] << endl;
			}
		}
		else continue;
	}

}