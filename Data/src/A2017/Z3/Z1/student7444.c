#include <stdio.h>

int dva_od_tri(int niz1[], int velicina1, int niz2[], int velicina2, int niz3[2], int velicina3) {
	int rezultat = 0, i, j, k, l, sviNizovi[4][100] = {{niz1},{niz2[velicina2]},{niz3[velicina3]}}, sveVelicine[4] = {velicina1, velicina2, velicina3}, counter[100] = {0}, n = 0;

	for(i=0; i<sveVelicine[0]; i++) //populating niz1
		sviNizovi[0][i] = *niz1++;

	for(i=0; i<sveVelicine[1]; i++) //populating niz2
		sviNizovi[1][i] = *niz2++;

	for(i=0; i<sveVelicine[2]; i++) //populating niz3
		sviNizovi[2][i] = *niz3++;

	for(i=0; i<2; i++) { //how many times needed to check the rows (default: 2, in case there are 3 rows)
		for(j=0; j<sveVelicine[i]; j++) { //getting the row to check the others with
			for(k=0; k<=n; k=k+2) { //checking if the element from the selected row already exists in the row for analysis (if it does then there is no point having it again = duplicate)
				if(sviNizovi[i][j] == counter[k]) {
					break; //if yes, break the loop and select another element
				}
				if(k==n) { //if no then compare if that element exists in the other two rows
					counter[n] = sviNizovi[i][j]; //write the element in the row for analysis 
					n++; //change the position in the analysis row 
					for(l=0; l<sveVelicine[i+1]; l++) {
						if(sviNizovi[i][j] == sviNizovi[i+1][l]) {
							counter[n]++; //if the same element exists in the first row (for comparing) then +1 for how many times it has showed up
							break;
						}
					} 

					if(i+2 == 3) //when "i" changes then the loop can search in an area outside of bounds of the third row, hence the IF
						for(l=0; l<sveVelicine[0]; l++)
							if(sviNizovi[i][j] == sviNizovi[0][l]) {
								counter[n]++; //same stuff but comparing the element to the third row
								break;
							}

					for(l=0; l<sveVelicine[i+2]; l++) { // same stuff only if the i didn't change
						if(sviNizovi[i][j] == sviNizovi[i+2][l]) {
							counter[n]++;
							break;
						}
					}
					n++; // change the position of the analysis row to add another element from the first row that you compare with
					break;
				}
			}
		}
	}

	for(i=1; i<=n+1; i+=2)
		if(counter[i] == 1) rezultat++; // check if the repeating of a certain element is 1, if it is 1 then it means it showed up in two rows, if 2 then it is present in all rows
// if 0 then it simply means it exists only in one element 
	return rezultat;
}

int main() {
	return 0;
}
