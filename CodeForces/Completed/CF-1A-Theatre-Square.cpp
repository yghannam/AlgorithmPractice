#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	
	double n, m, a;
	
	scanf("%Lf %Lf %Lf", &n, &m, &a);
	
	printf("%.0Lf", (ceil(n/a)*ceil(m/a)));
	
	//system("PAUSE");
}
