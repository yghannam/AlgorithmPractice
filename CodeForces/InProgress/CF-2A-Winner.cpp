/* 	Author: 		Yazen Ghannam
	Date:			May 15, 2012
	Problem Set:	CodeForces Set 2
	Problem:		A "Winner"
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Score{
	public:
		int max, round;
		Score (){
			max = 0;
			round = 0;
		}
		Score (int a, int b){
			max = a;
			round = b;
		}
		void set_values(int a,int b){
			max += a;
			round = b;
		}			
};

class Player{
	public:
		int round;
		string player;
		Player(){
			round = 0;
			player = "";
		}
		Player (int a, string b){
			round = a;
			player = b;
		}
};

int main(){
	int rounds;
	cin >> rounds;
	
	map<string,Score> players;
	
	for (int i = 1; i <= rounds; i++){
		string player;
		int score;
		cin >> player >> score;
		
		if(players.count(player)){
			players[player].set_values(score, i);
		}
		else{
			Score tmp (score, i);
			players[player] = tmp;
		}
	}	
	
	multimap<int,Player> sorted;
	for ( map<string,Score>::iterator it = players.begin(); it != players.end(); it++){
		Player tmp ((*it).second.round, (*it).first);
		sorted.insert( pair<int,Player> ((*it).second.max, tmp) );
	}
	Player winner = (*sorted.rbegin()).second;	
	for (multimap<int,Player>::iterator it = sorted.lower_bound( (*sorted.rbegin()).first); it != sorted.end(); it++){
		if ( (*it).second.round < winner.round )
			winner = (*it).second;
	}
		cout << winner.player << endl;
	
	
}
