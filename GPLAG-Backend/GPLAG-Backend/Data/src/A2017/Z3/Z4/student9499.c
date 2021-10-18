#include <stdio.h>
#define UPLIMIT 100

/* create histogram for matrix occurrences */
struct histogram {
	int num;
	int times;
};

/* check if num exists (USED FOR MAX FUNCTION) */
int num_exists(struct histogram data[], int length, int value) {
	int id;
	for(id = 0; id < length; id++)
		if(data[id].num == value)
			return id;
	return -1;
}

/* MAX FUNCTION */
int max(int matrica[100][100], int visina, int sirina) {
	struct histogram _data[2*UPLIMIT];
	int arr_length = 0, maxID = -1, maxValue = 0;
	int i, j, id;
	
	/* find the max number */
	for(i = 0; i < visina; i++) {
		for(j = 0; j < sirina; j++) {
			id = num_exists(_data, arr_length, matrica[i][j]);
			if(id == -1) {
				_data[arr_length].num = matrica[i][j];
				_data[arr_length].times = 1;
				
				if(maxID == -1) {
					maxID = arr_length;
					maxValue = 1;
				}
				
				arr_length++;
			}
			else {
				_data[id].times++;
				if(_data[id].times > maxValue) {
					maxValue = _data[id].times;
					maxID = id;
				}
			}
		}
	}
	
	/* give me the minimum element of the most repeating ones */
	for(i = 0; i < arr_length; i++) 
		if(_data[i].times == maxValue && _data[maxID].num > _data[i].num) 
			maxID = i;
			
	return _data[maxID].num;
}



/* check if number exists in certain array (USED FOR izbaci_kolone FUNCTION) */
int valueExists(int matrica[], int length, int value) {
	int i;
	for(i = 0; i < length; i++) 
		if(matrica[i] == value)
			return 1;
	return 0;
}

/* IZBACI_KOLONE FUNCTION */
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
	/* inictial */
	int i, j, _nWidth = sirina;
	int id = -1, _toChange = -1;
	int _remove[UPLIMIT], rLength = 0;
	
	/* add elements to remove array */
	for(i = 0; i < sirina; i++) {
		for(j = 0; j < visina; j++) {
			if(matrica[j][i] == n) {
				_remove[rLength++]=i;
				_nWidth--;
				break;
			}
		}
	}
	
	/* start removing columns (saved in _remove array) from matrica array */
	for(j = 0; j < sirina; j++) {
		if(valueExists(_remove, rLength, j)) {
			id = j;
			_toChange = j;
			while(valueExists(_remove, rLength, ++id)) {
				if(id == sirina) {
					id = -1;
					break;
				}
			}
		}
		/* swap column from toChange to id */
		if(id != -1) {
			for(i = 0; i < visina; i++) 
				matrica[i][_toChange] = matrica[i][id];
			
			/* add also this swapped column so I don't go over it again */
			_remove[rLength++] = id; 
		}
	}
	
	return _nWidth;
}


int main() {
	/* initial */
	int i, j, _remove, _prolaz = 0;
	int matrica[UPLIMIT][UPLIMIT];
	int height, width;
	
	/* input */
	do {
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d %d", &width, &height); 
	}
	while(height < 0 || width < 0 || height > UPLIMIT || width > UPLIMIT);
	for(i = 0; i < height; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j = 0; j < width; j++)
			scanf("%d", &matrica[i][j]);
	}
	
	/* create the loop for removal */
	while(width != 0) {
		
		_prolaz++;
		_remove = max(matrica, height, width);
		width = izbaci_kolone(matrica, height, width, _remove);
		
		if(width == 0) {
			printf("\nNakon %d. prolaza matrica je prazna!", _prolaz);
		}
		else {
			printf("\nNakon %d. prolaza matrica glasi: \n", _prolaz);
			for(i = 0; i < height; i++) {
				for(j = 0; j < width; j++) 
					printf("%5d", matrica[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}