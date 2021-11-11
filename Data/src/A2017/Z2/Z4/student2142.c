#include <stdio.h>

int main() {
	int mata[100][100],matb[100][100],matc[100][100],a[1000],b[1000],c[1000],i,j,m,n,k,mia;
	
	do{
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d",&m,&n);
	}while(m<0 || n<0 || m>100 || n>100);
	k=0;
	printf("Unesite clanove matrice A: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mata[i][j]);
            a[k]=mata[i][j];
            k++;
        }
    }
    k=0;
    printf("Unesite clanove matrice B: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matb[i][j]);
            b[k]=matb[i][j];
            k++;
        }
    }
    k=0;
    printf("Unesite clanove matrice C: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matc[i][j]);
            c[k]=matc[i][j];
            k++;
        }
    }
    for(i=0;i<(m*n)-1;i++){
        for(j=i+1;j<m*n;j++){
            if(a[j]<a[i]){
                mia=a[i];
                a[i]=a[j];
                a[j]=mia;
            }
            if(b[j]<b[i]){
                mia=b[i];
                b[i]=b[j];
                b[j]=mia;
            }
            if(c[j]<c[i]){
                mia=c[i];
                c[i]=c[j];
                c[j]=mia;
            }
        }
    }
    for(i=0;i<m*n;i++){
        if(a[i]!=b[i] || a[i]!=c[i]){
            printf("NE");
            return 0;
        }
    }
    printf("DA");
	return 0;
}
