#include <stdio.h>

int  UkloniDuple(int *niz,int size){
    int i,j,k;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;){
            if(niz[j]==niz[i]){
                for(k=j;k<size-1;k++){
                    niz[k]=niz[k+1];
                }
                size--;
            }else
            j++;
        }
    }
 return  size;
}


int bacaj(int *pro,int n,int sta){
	int i,j;
		for(i=0;i<n;i++){
		if(pro[i]==sta){
			for(j=i;j<n-1;j++){
				pro[j]=pro[j+1];
			}n--;
			i--;}
		}
		return n;
}

int ragazi(int *arr,int size){

    int  freq[100],temp[100]={0},k=0;
    int  i, j, count,vel=size;
    for(i=0; i<size; i++)
    {
        freq[i] = -1;
    }
    for(i=0; i<size; i++)
    {
        count = 1;
        for(j=i+1; j<size; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    for(i=0; i<size; i++)
    {
        if(freq[i] >1)
        {
            temp[k++]=arr[i];
        }
    }
    for(i=0;i<k;i++){
    	vel=bacaj(arr,vel,temp[i]);
	}
	return vel;
}

int jednaki(int *a,int m,int *b,int n){
    int i,j,br=0;
    for(i=0,j=0;i<m,j<n;i++,j++){
      if(a[i]==b[j]) br++;
    }
    if(br==m) return 1;
    else return 0;
}


 int presjek(int *a,int m, int *b,int n){
    if(!jednaki(a,m,b,n)){
    int i,j,novi[100]={0},k=0;
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		if(a[i]==b[j]){
    			novi[k++]=a[i];
    		}
    	}
    }
    for(i=0;i<k;i++){
    	a[i]=novi[i];
    }
    m=UkloniDuple(novi,k);
    return m;
    }
    else{
        return UkloniDuple(a,m);
    }
    }

int dva_od_tri(int *niz1, int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	int i,staria[100]={0},stari1=vel1,temp[1000]={0},k=0,nvel1,nvel2,nvel3,starib[100]={0},staric[100]={0},ab[100]={0},stari2=vel2,stari3=vel3,jk=vel1;
	for(i=0;i<vel1;i++){
		staria[i]=niz1[i];
	}
	for(i=0;i<vel1;i++){
		ab[i]=niz1[i];
	}
	for(i=0;i<vel2;i++){
		starib[i]=niz2[i];
	}
	for(i=0;i<vel3;i++){
		staric[i]=niz3[i];
	}
	nvel1=presjek(staria,stari1,starib,stari2);
	nvel2=presjek(starib,stari2,staric,stari3);
	nvel3=presjek(ab,jk,niz3,vel3);
	for(i=0;i<nvel1;i++){
		temp[i]=staria[i];
	}
	for(i=nvel1;i<nvel1+nvel2;i++){
		temp[i]=starib[k++];
	}
	k=0;
	for(i=nvel2+nvel1;i<nvel2+nvel3+nvel1;i++){
		temp[i]=ab[k++];
	}
	return ragazi(temp,nvel2+nvel3+nvel1);
}

int main() {
    int niz1[] = {1, 2, 3}, n1 = sizeof niz1 / sizeof *niz1;
    int niz2[] = {3, 2, 3}, n2 = sizeof niz2 / sizeof *niz2;
    int niz3[] = {2, 2}, n3 = sizeof niz3 / sizeof *niz3;
    printf ("%d ", dva_od_tri(niz1, n1, niz2, n2, niz3, n3));
    printf ("%d ", dva_od_tri(niz2, n2, niz3, n3, niz1, n1));
    printf ("%d ", dva_od_tri(niz2, n2, niz1, n1, niz3, n3));
    printf ("%d ", dva_od_tri(niz3, n3, niz2, n2, niz1, n1));
    printf ("%d\n", dva_od_tri(niz2, n2, niz2, n2, niz3, n3));
    int i;
    for (i = 0; i < n1; ++i)
        printf ("%d ", niz1[i]);
    printf ("\n");
    for (i = 0; i < n2; ++i)
        printf ("%d ", niz2[i]);
    printf ("\n");
    for (i = 0; i < n3; ++i)
        printf ("%d ", niz3[i]);
	return 0;
}
