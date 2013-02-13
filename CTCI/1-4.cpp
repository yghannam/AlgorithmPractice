#include <cstdio>

using namespace std;

void replaceSpaces(char* str, int len){
	
	int empty = 0;
	int i = len-1;
	while(str[i--] == ' '){
		empty++;
	}
	
	for(i = len-1; i >=0; i--){
		if(str[i-empty] != ' ')
			str[i] = str[i-empty];
		else{
			str[i] = '0';
			str[i-1] = '2';
			str[i-2] = '%';
			empty -= 2;
			i -= 2;
		}
	}		
	
}

int main(){
	
	char str[] = "I am a friend!      ";
	int length = 0;
	for(length = 0; str[length] != NULL; ++length);
	
	printf("%s\n", str);
	replaceSpaces(str, length);
	printf("%s\n", str);
	
	return 0;
}
