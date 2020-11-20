#include <iostream>
using namespace std;



bool testOutput(int q[], int c) {
  
  for (int i = 0; i < c; i++) {
    if(q[i] == q[c] || abs(q[c] - q[i]) == c - i) return false;
  }
  return true;
}

void backtrack(int &col) {
   
    col--;
    if (col == -1) exit(1);
    
}

void finished(int q[], int &counter) {   
    ++counter;
    int temp = 0;
    int EightByEight[8][8] = {0};
    
    for (int i = 0; i < 8; i++) {
        temp = q[i];
        EightByEight[temp][i] = 1;
    }
    cout << "Solution " << counter << ": " << endl;
    cout << endl;
      for(int r = 0; r <= 7; r++){
       for(int c = 0; c <= 7; c++){
          cout<<EightByEight[r][c];   
          cout << " ";
                     
      }                   
       cout<<endl;
    }
    cout << endl;
       
}// Print function ends here

int main() {
  int counter = 0;
  int q[8] = {0}, col = 1;
  q[0] = 0;
  bool keepRow = false;
// 2.
while (true) { // Only a limited amount of solutions for the problem
    while (col < 8) {
    // For loop 
      if(keepRow == 0) 
        q[col]=-1;   
        keepRow=false;
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
    finished(q,counter);
    backtrack(col);
    keepRow = true;

  }
}
