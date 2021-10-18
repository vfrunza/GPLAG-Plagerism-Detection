#include <stdio.h>

/* prototipi */
int max(int [100][100], int, int);
int izbaci_kolone(int [100][100], int, int, int);
void delete_column(int [100][100], int, int, int);

int main() {
	int matrix[100][100];
	int height, width;
	int turn; // broj prolaza
	int i, j;
	
	/* UNOS */
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &width, &height);
	
	for (i = 0; i < height; i++) {
		printf("Unesite elemente %d. reda: ", i + 1);
		
		for (j = 0; j < width; j++)
			scanf("%d", &matrix[i][j]);
	}
	
	printf("\n");
	
	turn = 1;
	while (width) {
		/* dobivamo novu sirinu matrice iz funkcije */
		width = izbaci_kolone(matrix, height, width, max(matrix, height, width));
		
		/* ako je ona nula, onda je matrica prazna, gotovi sa radom */
		if (!width) {
			printf("Nakon %d. prolaza matrica je prazna!\n", turn);
			break;
		}
		
		/* ako nije prazna, ispisati je */
		printf("Nakon %d. prolaza matrica glasi:\n", turn);
		for (i = 0; i < height; i++) {
			for (j = 0; j < width; j++)
				printf("%5d", matrix[i][j]);
			printf("\n");
		}
		printf("\n");
		
		/* sljedeci prolaz */
		turn++;
	}
	
	return 0;
}

/* max - IMPLEMENTACIJA */
int max(int matrix[100][100], int height, int width) {
	int maxOccurances = -1, maxNumber = -1;
	int tmpCount, len = height * width;
	int i, j;
	
	for (i = 0; i < len; i++) {
		tmpCount = 1;
		
		for (j = i + 1; j < len; j++)
			if (matrix[i / width][i % width] == matrix[j / width][j % width])
				tmpCount++;
				
		if (maxOccurances < tmpCount ||
		   (maxOccurances == tmpCount && maxNumber > matrix[i / width][i % width])) {
			maxOccurances = tmpCount;
			maxNumber = matrix[i / width][i % width];
		}
	}
	
	return maxNumber;
}
// end max

/* delete_column - IMPLEMENTACIJA */
/* Ova funkcija izbaca kolonu iz matrice po njenom indeksu*/
void delete_column(int matrix[100][100], int height, int width, int column) {
	int i, j;
	
	for (i = 0; i < height; i++)
		for (j = column; j < width - 1; j++)
			matrix[i][j] = matrix[i][j + 1];
}
// end delete_column

/* izbaci_kolone - IMPLEMENTACIJA */
/* Ova funkcija izbaca svaku kolonu koja sadrzi element toBeDeleted */
int izbaci_kolone(int matrix[100][100], int height, int width, int toBeDeleted) {
	int i, j;
	
	for (j = 0; j < width; j++) 
		for (i = 0; i < height; i++)
			if (matrix[i][j] == toBeDeleted) {
				// Izbrisi je
				delete_column(matrix, height, width, j);
				
				// Posto je izbrisana smanji sirinu za jedan
				width--;
				
				// Vrati se i pregledaj ovu kolonu sto je sada zamijenila izbrisanu
				j--;
				
				// ne treba provjeravati dalje ovu kolonu
				break;
			}
	
	// Vrati novu sirinu
	return width;
}