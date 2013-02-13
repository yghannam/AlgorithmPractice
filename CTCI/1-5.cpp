#include <cstdio>

using namespace std;

char* compress(char* str){
	

	int blocks = 0;
	int len1 = 0;
	for (int i = 1; str[i] != NULL; i++){
		if(str[i] != str[i-1]){
			blocks++;
		}
		len1++;
	}
	blocks++;
	if(blocks*2 < len1){
		char* compStr = new char[blocks*2];
		int count = 1, block = 0;
		for (int i = 1; i < len1; i++){
			if(str[i] == str[i-1]){
				count++;
			}
			else{
				compStr[block*2] = str[i-1];
				compStr[block*2+1] = count+48;
				block++;
				count = 1;				
			}
		}
		
		compStr[block*2] = str[len1-1];
		compStr[block*2+1] = count + 1 + 48;
		compStr[blocks*2] = NULL;

		return compStr;
	}
	
	return str;
}

int main(){
	
	char str[] = "aab  c!!!$###ccccaaa";
	//char str[] = "aabcda";
	
	printf("%s\n%s\n", str, compress(str));
	
	
	return 0;
}
