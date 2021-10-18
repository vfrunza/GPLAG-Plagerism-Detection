#include <stdio.h>
int dva_od_tri(int niz1[],int a,int niz2[],int b,int niz3[],int c)
{

    int i,j,k,istina=1;
    int brojac=0;
    for(i=0; i<a; i++) {
        for(j=i+1; j<a; j++)
            if(niz1[i]==niz1[j]) {
                for(k=j; k<a-1; k++) {
                    niz1[k]=niz1[k+1];
                }
                a--;
                j--;
            }

    }

    for(i=0; i<b; i++) {
        for(j=i+1; j<b; j++)
            if(niz2[i]==niz2[j]) {
                for(k=j; k<b-1; k++) {
                    niz2[k]=niz2[k+1];
                }
                b--;
                j--;
            }

    }
    for(i=0; i<c; i++) {
        for(j=i+1; j<c; j++)
            if(niz3[i]==niz3[j]) {
                for(k=j; k<c-1; k++) {
                    niz3[k]=niz3[k+1];
                }
                c--;
                j--;
            }

    }


    for(i=0; i<a; i++)
        for(j=0; j<b; j++) {
            if(niz1[i]==niz2[j]) {
                for(k=0; k<c; k++)
                    if(niz1[i] == niz3[k]) {
                        istina=0;
                        break;
                    } else istina=1;
                    
                if(istina==1) {
                    brojac++;

                }

            } else continue;
        }





    for(i=0; i<b; i++)
        for(j=0; j<c; j++) {
            if(niz2[i]==niz3[j]) {
                for(k=0; k<a; k++)
                    if(niz2[i] == niz1[k]) {
                        istina=0;
                        break;
                    } else istina=1;
                if(istina==1) {
                    brojac++;

                }


            } else continue;
        }



    for(i=0; i<c; i++)
        for(j=0; j<a; j++) {
            if(niz3[i]==niz1[j]) {
                for(k=0; k<b; k++)
                    if(niz3[i] == niz2[k]) {
                        istina=0;
                        break;
                    } else istina=1;
                if(istina==1)
                    brojac++;

            } else continue;
        }

    return brojac;

}



int main()
{
    int a,b,c,i,rez;
    int niz1[100];
    int niz2[100];
    int niz3[100];

    printf("Unesite velicinu niza: ");
    scanf("%d",&a);

    for(i=0; i<a; i++) {
        scanf("%d",&niz1[i]);
    }
    printf("Unesite velicinu niza: ");
    scanf("%d",&b);

    for(i=0; i<b; i++) {
        scanf("%d",&niz2[i]);
    }
    printf("Unesite velicinu niza: ");
    scanf("%d",&c);
    for(i=0; i<c; i++) {
        scanf("%d",&niz3[i]);
    }
    rez= dva_od_tri(niz1,a,niz2,b,niz3,c);
    printf("%d",rez);

    return 0;
}
