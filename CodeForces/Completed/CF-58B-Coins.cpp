#include <cstdlib>
#include <iostream>

using namespace std;


int main(){
	int in;
	cin >> in;
	int last = in;
	
	while (in > 0){
		
		if (last % in == 0){			
			last = in;			
			cout << last << " ";
		}	
		in--;
	}
	
	cout << endl;	
	system("PAUSE");
}
