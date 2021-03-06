#include <iostream>
using namespace std;



bool testOutput(int q[], int c) {

	for (int i = 0; i < c; i++) {
		if (q[i] == q[c] || abs(q[c] - q[i]) == c - i) return false;
	}
	return true;
}

void backtrack(int& col) {

	col--;
	if (col == -1) exit(1);

}

void finished(int q[], int& counter) {
	++counter;
	int i, j, k, l;
	typedef char box[5][7];
	box bb, wb, * board[8][8];

	box wq = {
	  {' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  {' ', char(219), ' ', char(219), ' ', char(219), ' '},
	  {' ', char(219), ' ', char(219), ' ', char(219), ' '},
	  {' ', char(219), char(219), char(219), char(219), char(219), ' '},
	  {' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};

	box bq = {
	  {char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
	  {char(219), ' ', char(219), ' ', char(219), ' ', char(219)},
	  {char(219), ' ', char(219), ' ', char(219), ' ', char(219)},
	  {char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
	  {char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
	};

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++) {
			wb[i][j] = ' ';
			bb[i][j] = char(219);
		}
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0)
				board[i][j] = &bb;
			else
				board[i][j] = &wb;
		}
	}
	for (i = 0; i < 8; i++) {
		if ((q[i] + i) % 2 == 0)
			board[q[i]][i] = &bq;
		else
			board[q[i]][i] = &wq;
	}

	//print the board via the pointers in array board
	// first print upper board
	cout << " ";
	for (i = 0; i < 7 * 8; i++)
		cout << '_';
	cout << endl;

	// now print the board 
	cout << "Solution " << counter << ": " << endl;
	cout << endl;
	for (i = 0; i < 8; i++)
		for (k = 0; k < 5; k++)
		{
			cout << " " << char(179); //print left border
			for (j = 0; j < 8; j++)
				for (l = 0; l < 7; l++)
					cout << (*board[i][j])[k][l];
			cout << char(179) << endl;
		}

	//before exiting print lower border
	cout << " ";
	for (i = 0; i < 7 * 8; i++)
		cout << char(196);
	cout << endl;

}// Print function ends here

int main() {
	int counter = 0;
	int q[8] = { 0 }, col = 1;
	q[0] = 0;
	bool keepRow = false;
	// 2.
	while (true) { // Only a limited amount of solutions for the problem
		while (col < 8) {
			// For loop 
			if (keepRow == 0)
				q[col] = -1;
			keepRow = false;
			//for (int r = 0; r < 8; r++) {
			for (int r = 0; q[col] < 8; r++) {
				q[col]++;
				while (q[col] == 8) {
					backtrack(col);
					q[col]++;
				}
				if (testOutput(q, col)) {
					break;
				}
			}
			col++;
		}
		finished(q, counter);
		backtrack(col);
		keepRow = true;

	}
}
