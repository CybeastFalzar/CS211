#include <iostream>
#include<bits/stdc++.h>
#include <cstring>
using namespace std;

string add(string a, string b) {

	string sum = "";
	string in1= "";
	string in2 = "";
	cout << "Please Enter a number for a" << endl;
	cin >> in1;
	if (in1 == "done") {
		return sum;
	}
	cout << "Please Enter a number for b" << endl;
	cin >> in2;
	a = in1;
	b = in2;
	int remainder = 0;
	int temp = 0;
   
	//char sum[10]; 
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a.length() > b.length()) {
		swap(a, b);
	}

	

	//sum[0] = (((input1[0] - '0') + (input2[0] - '0')) % 10) + '0';
//	cout << ((((input1[0] - '0') + (input2[0] - '0')) % 10) + remainder );
	for (int i = 0; i < a.length(); i ++) {

		//cout << ((input1[i] - '0') + (input2[i] - '0')) / 10 << endl;
		//cout << i;
			
		

		//if ( i >= b.length() ) {
		//	//int tempSum = ((((a[i] - '0') + (b[i] - '0')) % 10) + remainder);

		//	//	cout << i;
		//	//sum[i] = tempSum = '0';
		//	//cout << remainder;
		//		temp = (a[i] - '0') + remainder;
		//		//cout <<temp;
		//		sum.push_back(temp + '0');
		//		remainder = 0;
		//	}
			
				int tempSum = ((((a[i] - '0') + (b[i] - '0')) % 10) + remainder);
				sum.push_back(tempSum + '0');
				//remainder = (tempSum / 10);
				remainder = ((a[i] - '0') + (b[i] - '0')) / 10;
				//	cout << i << ":" << sum[i] << endl;
			
	}
	//cout << remainder;
	for (int i = a.length(); i < b.length(); i++) {
		//cout << i;
		int tempSum = (b[i] - '0') + remainder;
		//cout << i << ":"<< tempSum << endl;
		sum.push_back((tempSum % 10) + '0');
		remainder = tempSum / 10;
	}
// Checks to see if after the final number is added if a remainder was left and adding it to the front.
	if (remainder > 0) {
		sum.push_back(remainder + '0');
  }
	reverse(sum.begin(), sum.end());
	
	//cout << remainder;
	return sum;
}


int main()
{

	//cout << a;
  cout << add("a", "b");


}
