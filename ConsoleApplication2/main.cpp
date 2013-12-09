#include <iostream>
using namespace std;
#include "uppertrimatrix.h"

int main()
{
	UpperTriMatrix m = UpperTriMatrix(3);
	m.setv(0,0,	1.5f);
	m.setv(0,1,	2.5f);
	m.setv(0,2,	3.0f);
	m.setv(1,1,	4.0f);
	m.setv(1,2,	0.5f);
	m.setv(2,2,	-1.0f);

	printf("Source matrix M:\n");
	cout << m.getv(0, 0) << " " << m.getv(0, 1) << " " << m.getv(0, 2) << "\n";
	cout << m.getv(1, 0) << " " << m.getv(1, 1) << " " << m.getv(1, 2) << "\n";
	cout << m.getv(2, 0) << " " << m.getv(2, 1) << " " << m.getv(2, 2) << "\n\n";

	UpperTriMatrix mm = (* mul(&m, -2.0f));
	cout << "M*(-2):\n";
	cout << mm.getv(0, 0) << " " << mm.getv(0, 1) << " " << mm.getv(0, 2) << "\n";
	cout << mm.getv(1, 0) << " " << mm.getv(1, 1) << " " << mm.getv(1, 2) << "\n";
	cout << mm.getv(2, 0) << " " << mm.getv(2, 1) << " " << mm.getv(2, 2) << "\n\n";
	
	cout << "|M| = " << m.det() << "\n";
	cout << "press enter to exit";
	getchar();
	return 0;
}