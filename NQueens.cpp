#include <iostream>
#include <cmath>
using namespace std;

bool testOutput(int q[], int c) {
  
  for (int i = 0; i < c; i++) {
    if(q[i] == q[c] || abs(q[c] - q[i]) == c - i) return false;
  }
  return true;
}

void backtrack(int &col) {
    col--;
}

void finished(int &counter, int n) {   
cout << "  " << n << ". "<<"There are " << counter << " solutions to the "<< n <<" queens problem." << endl;

       
}// Print function ends here

int main() {

  int n;
  cout << "Enter a number, n to see the number of solutions for the n queens problem: ";
  cin >> n;
  while (n <= 0) {
    cout << "INVALID INPUT: USE POSITIVE INTEGER" << endl;
    cout << "Enter a number, n to see the number of solutions for the n queens problem: ";
    cin >> n;
  }


for (int i = 1; i <= n; i++) {
  int counter = -1;
  int *q = new int[i], col = 0;
  q[0] = 1;
  bool keepRow = false;

  while (true) { 
      while (col < i) {
    
        if(keepRow == 0) 
          q[col]=-1;   
          keepRow=true;
      
        while(q[col] < i) {
          q[col]++;
        if (q[col] == i) {
            keepRow=true;
            backtrack(col);
            break;
          }
          if (testOutput(q, col)) {
            keepRow = false;
            col++;
            break;
          }
          
        }
          if (col == -1) break;
        // col++;  
      }
      counter++;
      backtrack(col);
      keepRow = true;
      if (col <= -1) break;
    }

    delete []q;
    finished(counter,i);
   }
}
