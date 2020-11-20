#include <iostream>
#include <cmath>

using namespace std;
int main() {
  int q[8], c = 0;
  q[0] = 0;
  int counter = 0;
  int temp = 0;
  NC: 
      c++;
      if (c == 8) goto finished;
      q[c] = -1;
  NR: 
      
      q[c]++;
      if(q[c]==8) goto backtrack;
      // // row test
      // for (int i = 0; i < c; i++) {
      //   if(q[i] == q[c]) goto NR; 
      // }

      // //Diagonal test

      // for (int i = 0; i < c; i++) {
      //   if(abs(q[c] - q[i]) == c - i) goto NR;
      // }

      //Combined
      for (int i = 0; i < c; i++) {
         if ( (q[i] == q[c]) || (abs(q[c] - q[i]) == c - i) ) goto NR;
      }

  goto NC;

  backtrack: c--;
    if (c == -1) return 0;
    goto NR;


  finished: 
    ++counter;
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
    goto backtrack;
}
