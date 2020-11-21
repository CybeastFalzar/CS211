#include <iostream>
using namespace std;


typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b) {
  double delta = .0001;
  double x = a;
  double s = 0;
  while (x < b) {
    
    s += f(x) * delta;
    x += delta;
  }

  return s;
}

double line(double x){
    return x;
}

double square(double x){
    return x*x;
}
double cube(double x){
    return x*x*x;
}

int main() {
  cout << integrate(line, 1, 5) << endl;
  cout << integrate(square, 1, 5) << endl;
  cout << integrate(cube, 1, 5) << endl;
}



