#include <stdio.h>
int dva_od_tri(int *niz1,int a, int *niz2, int b, int *niz3, int c)
{
    int br1=0,br2=0,br3=0,j,i,k,br,l,m,n,br4=0;
    for(i=0;i<a;i++) {
        for(l=i+1;l<a;l++) {
            if(niz1[i]==niz1[l]) {
                niz1[i]=niz1[a-1];
                a--;
                l--;
            }
        }
    }
    for(j=0;j<b;j++) {
        for(m=j+1;m<b;m++) {
            if(niz2[j]==niz2[m]) {
                niz2[j]=niz2[b-1];
                b--;
                m--;
            }
        }
    }
    for(k=0;k<c;k++) {
        for(n=k+1;n<c;n++) {
            if(niz3[k]==niz3[n]) {
                niz3[k]=niz3[c-1];
                c--;
                n--;
            }
        }
    }
  
    
    for(i=0; i<a; i++) {
        for(j=0; j<b; j++) {
            if(niz1[i]==niz2[j]) {
                br1++; 
                break;
             
            }
        }

    }
    for(i=0; i<a; i++) {
        for(k=0; k<c; k++) {
            if(niz1[i]==niz3[k]) {
                br2++;
                break;
             
            }
            
        }
    }
    
    for(j=0; j<b; j++) {
        for(k=0; k<c; k++) {
            if(niz2[j]==niz3[k]) {
                br3++;
                break;
              
            }
        }
    }
    for(i=0;i<a;i++) {
        for(j=0;j<b;j++) {
            for(k=0;k<c;k++) {
                if(niz1[i]==niz2[j] && niz1[i]==niz3[k]) br4++;
            }
        }
    } 
    
br=br1+br2+br3-3*br4;
    return br;
}

int main()
{
    int niz1[100], niz2[100],niz3[100], a,b,c,i,BR;
    printf("Unesite velicinu prvog niza: ");
    scanf("%d", &a);
    printf("Unesite elemente prvog niza: ");
    for(i=0; i<a; i++) {
        scanf("%d", &niz1[i]);
    }
    printf("Unesite velicinu drugog niza: ");
    scanf("%d", &b);
    printf("Unesite elemente drugog niza: ");
    for(i=0; i<b; i++) {
        scanf("%d", &niz2[i]);
    }

    printf("Unesite velicinu treceg niza: ");
    scanf("%d", &c);
    printf("Unesite elemente treceg niza: ");
    for(i=0; i<c; i++) {
        scanf("%d", &niz3[i]);
    }

    BR=dva_od_tri(niz1,a,niz2,b,niz3,c);
    printf("%d",BR);
    return 0;
}
