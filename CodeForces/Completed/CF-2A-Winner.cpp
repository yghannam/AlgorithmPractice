/* 	Author: 		Yazen Ghannam
	Date:			May 15, 2012
	Problem Set:	CodeForces Set 2
	Problem:		A "Winner"
*/

#include <iostream>
#include <map>
#include <string>
#include <climits>

using namespace std;

class Score{
	public:
		int max, score, round;
		multimap<int, int> history;
		Score (){
			max = 0;
			score = 0;
			round = 0;
		}
		Score (int a, int b){
			max = a;
			score = a;
			round = b;
			history.insert(pair<int, int>(score, b));
		}
		void set_values(int a,int b){
			score += a;
			if ( score > max)
			{
				max = score;
				round = b;
			}
			history.insert(pair<int, int>(score, b));
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
	
	pair<string,Score> winner = make_pair(players.begin()->first, players.begin()->second);
	
	// Look for player with max score
	for (map<string,Score>::iterator it = players.begin(); it != players.end(); it++)
	{
		if(it->second.score > winner.second.score)
			winner = make_pair(it->first, it->second);
	}
		
	// Make sure player was first
	for (map<string,Score>::iterator it = players.begin(); it != players.end(); it++)
	{
		if(it->second.score == winner.second.score)
		{
			// Look for first round that the score was equalled or surpassed 
			int itRound = INT_MAX;
			int winRound = INT_MAX;
			
			for(multimap<int,int>::iterator rndit = it->second.history.find(it->second.score); rndit != it->second.history.end(); rndit++)
			{
				if(rndit->second < itRound)
					itRound = rndit->second;
			}
			
			for(multimap<int,int>::iterator rndit = winner.second.history.find(winner.second.score); rndit != winner.second.history.end(); rndit++)
			{
				if(rndit->second < winRound)
					winRound = rndit->second;
			}
			if(itRound < winRound)
			{
				winner = make_pair(it->first, it->second);
			}
		}
	}
	
	cout << winner.first << endl;	
}
