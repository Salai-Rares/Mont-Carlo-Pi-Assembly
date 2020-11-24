#include <iostream>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

#define INTERVAL 10000
using namespace std;

extern "C" double TrimiteArray(double *tablou,int dimensiune);
double tablou[INTERVAL];
void populateArray() {
	srand((int)time(NULL));
	double rand_x;
	for (int i = 0; i < INTERVAL; i++) {
		rand_x = (double)(rand() % (INTERVAL + 1)) / (INTERVAL);
		tablou[i] = rand_x;
	}
}

void afisareArray() {
	for (int i = 0; i < INTERVAL; i++)
		cout << tablou[i] << " ";
}

int main() {
	populateArray();
	afisareArray();
	double* ptr = tablou;
	double pi=TrimiteArray(ptr,INTERVAL);
	cout <<"Valoarea lui pi aproximata este:"<< pi;
	return 0; 
}