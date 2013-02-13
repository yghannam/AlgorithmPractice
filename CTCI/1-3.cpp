#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

bool isPermutations(char* str1, char* str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	if(len1 != len2)
		return false;
	
	map<char, int> one;
	map<char, int> two;
	
	map<char, int>::iterator it;
	for(int i = 0; i < len1; i++){
		//cout << str1[i];
		it = one.find(str1[i]);
		if(it == one.end())
			one[str1[i]] = 0;
		one[str1[i]]++;
		
		it = two.find(str2[i]);
		if(it == two.end())
			two[str2[i]] = 0;
		two[str2[i]]++;
	}

	return one == two;
}

int main(){
	
	//cout << "Hello!" << endl;
	
	char* str1 = "Hello";
	char* str2 = "elloH ";
	
	//cout << str1 << str2 << endl;
	
	cout << isPermutations(str1, str2) << endl;
	
	return 0;
}
