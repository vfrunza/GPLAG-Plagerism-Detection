#include <stdio.h>

int duplikat (int* niz,int k, int* niz1, int vel) {
    int j;
    for(j=k+1;j<vel;j++) {
        if(niz[k]==niz1[j]) return j;
    }
    return 0;
}

void sortiraj (int* niz,int vel) {
    int* p=niz;
    int* q=niz;
    int temp;
    while(p<niz+vel-1) {
        q=p+1;
        while(q<niz+vel) {
            if(*p>*q) {
                temp=*p;
                *p=*q;
                *q=temp;
            }
            q++;    
        }
        p++;
    }
}

int izbaci_visak (int* niz, int  vel) {
    int*p=niz;
    int temp,i,j;
    for(i=0;i<vel;i++) {
        for(j=i+1;j<vel;j++) {
            if(*(p+i)==*(p+j)) {
                temp=*(p+vel-1);
                *(p+vel-1)=*(p+j);
                *(p+j)=temp;
                vel--;
                j--;
            }
        }
    }
    return vel;
}

int check (int* niz, int broj, int vel) {
    int i;
    for(i=0;i<vel;i++) {
        if(niz[i]==broj) return 1;
    }
    return 0;
}

int main() {
    int mat[200][200],i,j,m,n,z=0,p=0,r,k=0,d=0,indeksi1[200],l=0,indeksi2[200],br=0,niz[200],a;	
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d%d", &m,&n);
        if(m>0 && m<=200 && n>0 && n<=200) break;
        else printf("Brojevi nisu u trazenom opsegu.\n");
    } while(2);
    
    if (m==1 && n!=1) {
        printf("Unesite elemente matrice: ");
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                scanf("%d", &mat[i][j]);
                niz[p]=mat[i][j];
                p++;
            }
        }
        for(i=0;i<p;i++) {
            r=duplikat(niz,i,niz,p); 
                if(r!=0) {
                    for(j=r;j<p-1;j++) {
                        niz[j]=niz[j+1];
                    }
                p--;
                i--;
            }
        
        }
        
        for(i=0;i<m;i++) {
            for(j=0;j<p;j++) {
                mat[i][j]=niz[j];
            }
        }
        printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
        for(i=0;i<m;i++) {
            for(j=0;j<p;j++) {
                printf("%5d", mat[i][j]);
            }
            printf("\n");
        }
    }
    
    else if (n==1 && m!=1) {
        printf("Unesite elemente matrice: ");
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                scanf("%d", &mat[i][j]);
                niz[z]=mat[i][j];
                z++;
            }
        }
        for(i=0;i<z;i++) {
            a=duplikat(niz,i,niz,z);
            if(a!=0) {
                for(j=a;j<z-1;j++) {
                    niz[j]=niz[j+1];
                }
                z--;
                i--;
            }
        }
        for(i=0;i<z;i++) {
            for(j=0;j<n;j++) {
                mat[i][j]=niz[i];
            }
        }
        printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
        for(i=0;i<z;i++) {
            for(j=0;j<n;j++) {
                printf("%5d", mat[i][j]);
            }
            printf("\n");
        }
    }
    
    else {
        printf("Unesite elemente matrice: ");
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        for(i=0;i<m;i++) {
            for(j=i+1;j<m;j++) {
                for(k=0;k<n;k++) {
                    if(mat[i][k]!=mat[j][k]) break;
                    if(mat[i][k]==mat[j][k] && k==n-1) {
                        indeksi1[d]=j;
                        d++;
                    }
                }
            }
        }
        d=izbaci_visak(indeksi1,d);
        sortiraj(indeksi1,d);
        k=0;
        l=0;
        for(i=0;i<m;i++) {
            if(check(indeksi1,l,d)==1) {
                for(j=i;j<m-1;j++) {
                    while(k<n) {
                        mat[j][k]=mat[j+1][k];
                        k++;
                        if(k==n) {
                            k=0;
                            break;
                        }
                    }
                }
                m--;
                i--;
            }
            l++;
        }
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {
                for(k=0;k<m;k++) {
                    if(mat[k][i]!=mat[k][j]) {
                        break;
                    }
                    if(mat[k][i]==mat[k][j] && k==m-1) {
                        indeksi2[br]=j;
                        br++;
                    }
                }
            }
        }

        br=izbaci_visak(indeksi2,br);
        sortiraj(indeksi2,br);
        k=0;
        l=0;
        for(i=0;i<n;i++) {
            if(check(indeksi2,l,br)==1) {
                for(j=i;j<n-1;j++) {
                    while(k<m) {
                        mat[k][j]=mat[k][j+1];
                        k++;
                        if(k==m) {
                            k=0;
                            break;
                        }
                    }
                }
                n--;
                i--;
            }
            l++;
        }
    
        printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                printf("%5d", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
