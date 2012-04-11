#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int rounds;
	string N, P;
	int n = 0, p = 0;
	
	cin >> rounds;
	cin >> N;
	cin >> P;
	
	
	int nLen = N.length();
	int pLen = P.length();
	
	int totLen = nLen*pLen;
	string nNew, pNew;
	for (int i = 0; i < nLen; i++)
		pNew.append(P);
		
	for (int i = 0; i < pLen; i++)
		nNew.append(N);
		
	int remainder = rounds%totLen;
	rounds/=totLen;
		
	if (N.compare(P) == 0){
		rounds = 0;
		remainder = 0;
	}
	for (int i = 0; i < totLen; i++){
		char nPick = nNew.at(i%nLen);
		char pPick = pNew.at(i%pLen);
		if (nPick != pPick){
			if (nPick == 'R' && pPick == 'S')
				n++;
			else if (nPick == 'S' && pPick == 'P')
				n++;
			else if (nPick == 'P' && pPick == 'R')
				n++;
			else
				p++;		
		}
	}
	
	n*=rounds;
	p*=rounds;
	
	
	
	for (int i = 0; i < remainder; i++){
		char nPick = nNew.at(i%nLen);
		char pPick = pNew.at(i%pLen);
		if (nPick != pPick){
			if (nPick == 'R' && pPick == 'S')
				n++;
			else if (nPick == 'S' && pPick == 'P')
				n++;
			else if (nPick == 'P' && pPick == 'R')
				n++;
			else
				p++;		
		}
	}
	
	
	cout << p << " " << n << endl;
	
//	system("PAUSE");
}
