#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	
	int in[] = { -2, 3, -16, 100, -4, 5 };
	int M [6];
	M[0]=in[0];
	int max = in[0];
	
	for (int i = 1; i < 6; i++){
		M[i] = M[i-1] + in[i] > in[i] ? M[i-1] + in[i] : in[i];
		max = max > M[i] ? max : M[i];
		
	}
	cout << "Max = " << max << endl;
	system("PAUSE");
}
