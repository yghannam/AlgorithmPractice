#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	
	int numBlocks = 0;
	
	ifstream in ("aztec.in");
	ofstream out ("aztec.out");
	while (in.good()){
		string line;
		getline(in, line);
		numBlocks = atoi(line.c_str());
		if (numBlocks > 0){
			int numLevels = 0;
			int neededCurrent = 1;
			numBlocks--;
	
			while (numBlocks >= 0){
				numLevels++;
				neededCurrent += 4*numLevels;	
				numBlocks -= neededCurrent;
			}
	
			out << numLevels << endl;
		}
		
	}
	
}
