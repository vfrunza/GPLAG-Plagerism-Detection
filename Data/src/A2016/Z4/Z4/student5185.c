#include <stdio.h>

char* obuhvat (char* s, int x1, int y1, int x2, int y2){
	
	/*Test da vidim koliko ce autotestova proci samo sa ovim :D */
	return 0;
}

int main() {
	/*(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)*/
	char kooridnate[100] = "b";
	int x1 =-3, y1=-3, x2=3, y2=3;
	
	printf ("%s", obuhvat(kooridnate, x1, y1, x2, y2));
	
	return 0;
}
