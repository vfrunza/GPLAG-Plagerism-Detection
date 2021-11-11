#include <stdio.h>

	void zaokruzi1(double *pok, int vel){
		int i;
		for(i=0;i<vel;i++){
			*(pok+i)=(int)(*(pok+i)*10+0.5)/10.;
		}
	}
	
	void preslozi(double niz[], int k){
		zaokruzi1(niz,vel);
		
	}


int main() {
	printf("Zadaća 3, Zadatak 2");
	return 0;
}
{
	int mat[3][4]={{1,2,3,4}, {4,5,6,7}, {8,9,4,1}},i,j,niz[12],t;
	int element, count=1;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			niz[i*4+j]=mat[i][j];
		}
	}
	for(i=1;i<12;i++){
    for(j=0;j<i;j++){
        if(niz[i]>niz[j]){
            t=niz[i];
            niz[i]=niz[j];
            niz[j]=t;
        }
    }
}
 for(i=1;i<=12;i++){
    if(i==4 || niz[i]!=niz[i-1]){
        
            element=niz[i-1];
        
        count=1;
    } else{
        ++count;
    }
 }
 printf("najvise se ponavlja %d element i to puta", element);
	return 0;
}