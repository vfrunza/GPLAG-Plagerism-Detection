#include <stdio.h>

/* uporedjivanje clanova dva niza */
int find_array(int trazeni, int niz[], int size)
{
	int i;
	for(i=0; i<size; i++) {
		if(niz[i]==trazeni)
			return 1;
	}
	return 0;
}

int dva_od_tri(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3)
{
	int i;
	int tr1, tr2, tr3, br=0;
	for(i=0; i<size1; i++) {
		/* funkcija koja uporedjuje clanove se poziva, zatim se pronadju clanovi koji se ponavljaju u dva niza */
		tr1=find_array(arr1[i], arr1, i);
		tr2=find_array(arr1[i], arr2, size2);
		tr3=find_array(arr1[i], arr3, size3);
		if(tr2+tr3==1 && tr1==0)
			br++;
	}
	for(i=0; i<size2; i++) {
		tr1=find_array(arr2[i], arr1, size1);
		tr2=find_array(arr2[i], arr2, i);
		tr3=find_array(arr2[i], arr3, size3);
		if (tr3==1 && tr1==0 && tr2==0)
			br++;
	}
	return br;
}

int main()
{
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
 /*#include <stdio.h>

int dva_od_tri(int *niz1,int vel1,int *niz2,int vel2,int *niz3,int vel3){
    int i=0,j=0,k=0,l=0,x=0,s=0;
    
    for(i=0;i<vel1;i++){
        for(k=0;k<i;k++){
            if(niz1[i]==niz1[k]){
                x=1;
                break;
            }
        }
        if(x){
            x=0;
            continue;
        }
        for(j=0;j<vel2;j++){
            if(niz1[i]==niz2[j]){
                for(l=0;l<vel3;l++){
                    if(niz1[i]==niz3[l])break;
                }
                if(l==vel3){
                s++;
                break;
                }
            }
        }
    }
    x=0;
    for(i=0;i<vel1;i++){
        for(k=0;k<i;k++){
            if(niz1[i]==niz1[k]){
                x=1;
                break;
            }
        }
        if(x){
            x=0;
            continue;
        }
        for(j=0;j<vel3;j++){
            if(niz1[i]==niz3[j]){
                for(l=0;l<vel2;l++){
                    if(niz1[i]==niz2[l])break;
                }
                if(l==vel2){
                    s++;
                    break;
                }
            }
        }
    }
    x=0;
    for(i=0;i<vel2;i++){
        for(k=0;k<i;k++){
            if(niz2[i]==niz2[k]){
                x=1;
                break;
            }
        }
        if(x){
            x=0;
            continue;
        }
        for(j=0;j<vel3;j++){
            if(niz2[i]==niz3[j]){
                for(l=0;l<vel1;l++){
                    if(niz2[i]==niz1[l])break;
                }
                if(l==vel1){
                    s++;
                    break;
                }
            }
        }
    }
    return s;
    
}

int main() {
	
	return 0;
}*/