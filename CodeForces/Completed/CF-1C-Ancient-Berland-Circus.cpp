/* 	Author: 		Yazen Ghannam
	Date:			May 13, 2012
	Problem Set:	CodeForces Set 1
	Problem:		C "Ancient Berland Circus"
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>

#define PI 3.14159265
#define ERROR 0.00001

using namespace std;

int main(){
	double ax, ay, bx, by, cx, cy;
	//ax = 0; ay = 0; bx = 1; by = 1; cx = 0; cy = 1;
	//ax = 17.288379; ay = 68.223317; bx = 48.776683; by = 71.688379; cx = 23.170559; cy = 106.572762; //1505.27997374

	
	scanf("%lf %lf", &ax, &ay);
	scanf("%lf %lf", &bx, &by);
	scanf("%lf %lf", &cx, &cy);
	
	// Find Circumcenter
	double d = 2.0*(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
	double ux = ( ((ax*ax)+(ay*ay))*(by-cy) + ((bx*bx)+(by*by))*(cy-ay) + ((cx*cx)+(cy*cy))*(ay-by) ) / d; 
	double uy = ( ((ax*ax)+(ay*ay))*(cx-bx) + ((bx*bx)+(by*by))*(ax-cx) + ((cx*cx)+(cy*cy))*(bx-ax) ) / d; 
	
	ax -= ux;
	ay -= uy;
	bx -= ux;
	by -= uy;
	cx -= ux;
	cy -= uy;
	
	double px = ax;
	double py = ay;
	
	bool bFound = false;
	bool cFound = false;
	
	int n = 3;
	// Try all possible polygons
	for(; n <= 100; n++)
	{
		px = ax;
		py = ay;
		double angle = 2.0 * PI / n;
		double pxp, pyp;
		bFound = false;
		cFound = false;
		
		// Create vectors and match
		for(int i = 1; i < n; i++)
		{
			pxp = px*cos(angle) - py*sin(angle);
			pyp = px*sin(angle) + py*cos(angle);
			
			px = pxp;
			py = pyp;
			
			if (!bFound)
			{
				bFound = ( abs(px-bx) < ERROR ) && ( abs(py-by) < ERROR );
			}
			if (!cFound)
			{
				cFound = ( abs(px-cx) < ERROR ) && ( abs(py-cy) < ERROR );
			}
		}
		
		if(bFound && cFound)
		{
			break;
		}
	}
	
	double R = sqrt( ax*ax + ay*ay );
	double area = 0.5 * (n * R*R) * sin(2.0*PI/n);
	printf("%f", area);

}
