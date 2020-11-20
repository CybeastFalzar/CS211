#include <iostream>
using namespace std;

bool ok(int q[], int c) {
  int a[8][5] = {
  /*0*/  {-1}, 
  /*1*/  {0, -1},
  /*2*/  {0, -1},
  /*3*/  {0, 1, 2, -1},
  /*4*/  {0, 1, 3, -1},
  /*5*/  {1, 4, -1},
  /*6*/  {2, 3, 4, -1},
  /*7*/  {3, 4, 5, 6, -1},
  };

  
  // q[8] = {1, 3, 3}
  for (int i = 0; i < c; i++) {
    if (q[c] == q[i]) return false;
  }
  int i = 0;
  
  while (a[c][i] != -1) {
    if ( (abs(q[c] - q[a[c][i]]) == 1) ) return false;
    i++;
  }


  
  
  return true;
}

void backtrack(int &col) {
   
    col--;
    if (col == -1) exit(1);
    
}

void finished(int q[], int &counter) {   
  //cout << 123;
    // for (int b = 0; b < 8; b++) {
    //   cout << q[b];
    // }
    // cout << endl;
  
  cout << "Cross " << counter << ":"<< endl;
  cout << "  " << q[0] << " " << q[1] << endl;    
  cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
  cout << "  " << q[6] << " " << q[7] << endl << endl;
  
  counter++;
       
}

int main() {
  int counter = 1;
  int q[8] = {}, col = 1;
  int s[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  q[0] = 1;
  bool keepRow = false;

  while (true) { 
    while (col < 8) {
      if(keepRow == 0) q[col] = 0;   
      keepRow=false;
      while ( q[col] < 9) {
        q[col]++;
        while (q[col] == 9) {
          backtrack(col);
          q[col]++;
        }
        if (ok(q, col)) {
          s[q[col] - 1] = -1;
          break;
        }
      } 
      col++;  
      }    
    finished(q,counter);
    backtrack(col);
    keepRow = true;
  } 
}
