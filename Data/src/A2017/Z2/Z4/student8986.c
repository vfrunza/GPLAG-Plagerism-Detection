#include <stdio.h>

int main() {

int m,n,a[100][100],b[100][100],c[100][100],e[1000],f[1000],g[1000],i,j,k=0,l=0,o=0,min1,min2,min3,temp1,temp2,temp3,br=0;

do{	

printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	
}while(n<0 || n>100 || m<0 || m>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++){
	    for(j=0;j<m;j++){
	        scanf("%d",&a[i][j]);
	    }
	}
	
	printf("Unesite clanove matrice B: ");
    for(i=0;i<n;i++){
	    for(j=0;j<m;j++){
	        scanf("%d",&b[i][j]);
	    }
	}

    printf("Unesite clanove matrice C: ");
    for(i=0;i<n;i++){
	    for(j=0;j<m;j++){
	        scanf("%d",&c[i][j]);
	    }
	}



k=0;




for(i=0;i<n;i++)
{for(j=0;j<m;j++)
 e[k++]=a[i][j];

 }


for(i=0;i<n;i++)
{for(j=0;j<m;j++)
 f[l++]=b[i][j];

 }
 


for(i=0;i<n;i++)
{for(j=0;j<m;j++)
 g[o++]=c[i][j];
}


	
for (i=0; i<m*n; i++) {
min1=i;
for (j=i+1; j<m*n; j++) {
if (e[j] < e[min1])
min1 = j;
}
temp1 = e[i];
e[i] = e[min1];
e[min1] = temp1;
}i=0;	

for (i=0; i<m*n; i++) {
min2=i;
for (j=i+1; j<m*n; j++) {
if (f[j] < f[min2])
min2 = j;
}
temp2 = f[i];
f[i] = f[min2];
f[min2] = temp2;
}i=0;
	
for (i=0; i<m*n; i++) {
min3=i;
for (j=i+1; j<m*n; j++) {
if (g[j] < g[min3])
min3 = j;
}
temp3 = g[i];
g[i] = g[min3];
g[min3] = temp3;
}i=0;	

	
for(i=0;i<m*n;i++){
		if(e[i]!=f[i] || e[i]!=g[i] || f[i]!=g[i]){
			printf("NE");return 0;
		}
	}
	
	printf("DA");

	return 0;
}
