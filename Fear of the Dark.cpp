#include<iostream>
#include<math.h>
using namespace std;

double px, py,xa,ya,xb,yb;
long int n,i;

double sar, sbr, ear, ebr,abr,mer,msr,ans,amr,bmr;


int main() {

	cin >> n;
	for ( i = 0; i < n; i++) {
		cin >> px >> py >> xa >> ya >> xb >> yb;

		sar = sqrt(pow(xa, 2) + pow(ya, 2));
		sbr = sqrt(pow(xb, 2) + pow(yb, 2));
		ear = sqrt(pow(px - xa, 2) + pow(py - ya, 2));
		ebr = sqrt(pow(px - xb, 2) + pow(py - yb, 2));
		abr = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2))/2;

		mer = min(ear, ebr);
		msr = min(sar, sbr);
		ans = max(mer, max(msr, abr));
		amr = max(sar, ear);
		bmr = max(sbr, ebr);
		printf("%.10lf\n", min(amr, min(bmr, ans)));


	}

	
	return 0;
}
