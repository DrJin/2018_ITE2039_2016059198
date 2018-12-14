#include <iostream>
#include <string>
using namespace std;

enum WAY { UP, LEFT, DIAG, NONE };

typedef struct {
	int length;
	WAY way;
}Node;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int x, y;
	x = s1.length() + 1;
	y = s2.length() + 1;
	Node** table = new Node*[y]();
	for (int i = 0; i < y; i++)
		table[i] = new Node[x]();
	int i, j;
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			if (i == 0 || j == 0)
				table[i][j] = { 0, NONE };
			else {
				if (s1[j - 1] == s2[i - 1])
					table[i][j] = { table[i - 1][j - 1].length + 1, DIAG };
				else {
					if (table[i - 1][j].length >= table[i][j - 1].length)
						table[i][j] = { table[i - 1][j].length, UP };
					else
						table[i][j] = { table[i][j - 1].length, LEFT };
				}
			}
		}
	}
	/*
	for (int i = 0; i < y; i++) {
	for (int j = 0; j < x; j++) {
	cout << table[i][j].length << " ";
	}
	cout << endl;
	}
	*/
	string subs = "";
	--i;
	--j;
	while (table[i][j].length != 0) {
		if (table[i][j].way == NONE)
			break;
		switch (table[i][j].way) {
		case DIAG:
			subs = s1[j - 1] + subs;
			--i;
			--j;
			break;
		case UP:
			--i;
			break;
		case LEFT:
			--j;
			break;
		case NONE:
			break;
		}
	}

	cout << subs;

	for (int i = 0; i < y; i++)
		delete[] table[i];
	delete[] table;
	return 0;
}
