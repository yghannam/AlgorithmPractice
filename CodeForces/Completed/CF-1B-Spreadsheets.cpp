/* 	Author: 		Yazen Ghannam
	Date:			May 13, 2012
	Problem Set:	CodeForces Set 1
	Problem:		B "Spreadsheets"
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;

int main(){
	int num;
	cin >> num;
	
	vector<string> ins;
	string in;
	
	for(int i = 0; i < num; i++){
		cin >> in;
		ins.push_back(in);
	}
	
	for(int i = 0; i < num; i++){
		string in = ins.at(i);
		int col=0;
		string out = "";
		
		if (in.find_first_of("0123456789") == 1 && in.find_first_of("C", 2) != string::npos){
			int pos = in.find_first_of("C");
			
			out.insert(0,in.substr(1,pos-1));
			col = atoi(in.substr(pos+1, in.length()-pos-1).c_str());
			
			while (col > 0){
				int rem = col%26;
				if (rem == 0){
					out.insert(0, string(1, 26+64));
					col -= 26;
				}
				else{
					out.insert(0,string(1, rem+64));
				}
				col /= 26;
			}
			cout << out << endl;
		}
		else{
			int pos = in.find_first_of("0123456789");
			col += in.at(pos-1)-64;			
			int pow26 = 26;
			
			for(int j = pos-2; j >= 0; j--){
				col += (in.at(j)-64)*pow26;
				pow26 *= 26;
			}
			
			cout << "R" << in.substr(pos, in.length()-pos+1) << "C" << col << endl;
		}
		
	}
}
