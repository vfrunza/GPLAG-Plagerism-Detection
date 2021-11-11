#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 4");*/
    int A[100][100], B[100][100], C[100][100],m,n,i,j,a[10000],b[10000],c[10000],v,u,temp,min;
   do{
    printf("Unesite brojeve M i N: ");
    scanf("%d %d",&m,&n);
   } while(m>100 ||  n>100);
   printf("Unesite clanove matrice A: ");
   for(i=0; i<m; i++)
       for(j=0; j<n; j++) scanf("%d",&A[i][j]);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++) scanf("%d",&B[i][j]);
    printf("Unesite clanove matrice C: ");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++) scanf("%d",&C[i][j]);
    v=0;
    u=m*n;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            a[v]=A[i][j];
            v++;
        }
    }
    v=0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            b[v]=B[i][j];
            v++;
        }
    }
    v=0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
           c[v]=C[i][j];
           v++;
       }
    }
    /*sortiranje*/
    for(i=0; i<u; i++){
        min=i;
        for(j=i+1; j<u; j++){
            if(a[j]<a[min])
            min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    for(i=0; i<u; i++){
        min=i;
        for(j=i+1; j<u; j++){
            if(b[j]<b[min])
            min=j;
        }
        temp=b[i];
        b[i]=b[min];
        b[min]=temp;
    }
    for(i=0; i<u; i++){
        min=i;
        for(j=i+1; j<u; j++){
            if(c[j]<c[min])
            min=j;
        }
        temp=c[i];
        c[i]=c[min];
        c[min]=temp;
    }
    for(i=0; i<u; i++) 
    if(a[i]!=b[i] || a[i]!=c[i]){
        printf("NE\n");
        return 0;
    }
    printf("DA\n");
	return 0;
}
