#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main (){
	int number;
	printf("Number: ");
	scanf("%d", &number);

	int x = 1;
	vector <int> primes;
	primes.push_back(x);
	x++;

	while ( x <= number ){
		bool prime = true;

		if ( x > 2 && x%2 == 0 )
			prime = false;

		else{
			double root = sqrt((double)x);
			for ( int i = 1; i < primes.size(); i++)
				if ( primes.at(i) > root )
					break;
				else if ( x%primes.at(i) == 0 ){
					prime = false;
					break;
				}
		}

		if(prime)
			primes.push_back(x);
		x++;
	}

	//for (int i = 0; i < primes.size(); i++)
		printf("Number of primes from 1 to %d: %d \n", number, primes.size());
	//printf("\n");
	system("PAUSE");
}
