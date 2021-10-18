/* BACKUP ZADACE SA ZAMGERA */
#include <stdio.h>
#define upLIMIT		20000

/* create structure for histogram */
struct histogram {
	int num;
	int checked;
	int type;
};

/* function to check if number exists in histogram */
int num_exists(struct histogram arrData[], int arr_length, int value, int type) {
	int id;
	for(id = 0; id < arr_length; id++)
		if(arrData[id].num == value && arrData[id].type == type)
			return id;
	return -1;
}

/* function to calculate */
int dva_od_tri(int* A, int lenA, int* B, int lenB, int* C, int lenC) {
	
	/* variables */
	struct histogram arrData[upLIMIT];
	int arr_length = 0;
	int i, _id, _id2, _test, _timesShown = 0;
	
	/* calculate for array A */
	for(i = 0; i < lenA; i++) {
		_test = num_exists(arrData, arr_length, A[i], 1);
		if(_test == -1) {
			arrData[arr_length].num = A[i];
			arrData[arr_length].checked = 1;
			arrData[arr_length].type = 1;
			arr_length++;
		}
	}
	
	/* calculate for array B */
	for(i = 0; i < lenB; i++) {
		_id = num_exists(arrData, arr_length, B[i], 1);
		_test = num_exists(arrData, arr_length, B[i], 2);
		
		/* nemoj dodavati u niz brojeve koji se ponavljaju vec */
		if(_test == -1) {
			arrData[arr_length].num = B[i];
		
			if(_id == -1)
				arrData[arr_length].checked = 1;
			else {
				arrData[arr_length].checked = 2;
				arrData[_id].checked = 2;
			}
			
			arrData[arr_length].type = 2;
			arr_length++;
		}
	}
	
	/* calculate for array C */
	for(i = 0; i < lenC; i++) {
		_id = num_exists(arrData, arr_length, C[i], 1);
		_id2 = num_exists(arrData, arr_length, C[i], 2);
		
		if(_id != -1 && _id2 != -1) {
			arrData[_id].type = -1;
			arrData[_id2].type = -1;
			arrData[_id].checked = 3;
			arrData[_id2].checked = 3;
		}
		else {
			if(_id != -1 && arrData[_id].checked == 1) {
				arrData[_id].checked = 2;
				arrData[_id].type = -1;
				arrData[arr_length].num = C[i];
				arrData[arr_length].checked = 2;
				arrData[arr_length++].type = -1;
			}
			else if(_id2 != -1 && arrData[_id2].checked == 1) {
				arrData[_id2].checked = 2;
				arrData[_id2].type = -1;
				arrData[arr_length].num = C[i];
				arrData[arr_length].checked = 2;
				arrData[arr_length++].type = -1;
			}
		}
	}
	
	/* calculate numbers that are in two arrays */
	for(i = 0; i < arr_length; i++) 
		if(arrData[i].checked == 2)
			_timesShown++;
	
	_timesShown /= 2;
	
	return _timesShown;
}



int main() {
	
	return 0;
}