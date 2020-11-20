#include <iostream>
using namespace std;

/* 
1. So mp[i][j] gives man i's ranking of woman j and likewise for the women’s ranking of the men in
wp.
2. 0 = highest, 1 second highest and 2 lowest.

We need to do 2 tests:
1. If the new woman has already been assigned to some man then return false
2. Check the new pair (new man, new woman) against each existing pair consisting of
(current man, current woman) to see if the new pair would make the match unstable. So
  a. if the current man prefers the new woman to his partner and
  b. if the new woman prefers the current man to her partner
    i. this is unstable, so return false
  c. if the new man prefers the current woman to his partner and
  d. if the current woman prefers the new man to her partner
    i. This is unstable, so return false
  e. if there are no instabilities introduced with any of the existing (i.e. “current”)
couples, so we return true

*/
bool ok(int q[], int c) {
  int mp[3][3]={
    0,2,1,    // Man 1
    0,2,1,    // Man 2
    1,2,0     // Man 3
  };
  
  int wp[3][3]={
    2,1,0,    // Woman 1
    0,1,2,    // Woman 2
    2,0,1     // Woman 3
  };



  for (int i = 0; i < c; i ++) {
    if (q[c] == q[i]) return false;  
    
  }
  for (int i = 0; i < c; i ++) {  
      if ( mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c] ) return false;
      if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false;
    }
  
  
 return true; 
}

void backtrack(int &col) {
   
    col--;
    if (col == -1) exit(1);
    
}

void finished(int q[], int &counter) {   cout << "Man" << "   " << "Woman" << endl;
  cout << "0" << "     " << q[0] << endl;
  cout << "1" << "     " << q[1] << endl;
  cout << "2" << "     " << q[2] << endl;
       
}

int main() {
  int counter = 1;
  int q[8] = {}, col = 1;
  q[0] = 0;
  bool keepRow = false;

  while (true) { 
    while (col < 3) {
      if(keepRow == 0) q[col] = -1;   
      keepRow=false;
      while ( q[col] < 3) {
        q[col]++;
        while (q[col] == 3) {
          backtrack(col);
          q[col]++;
        }
        if (ok(q, col)) {
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
