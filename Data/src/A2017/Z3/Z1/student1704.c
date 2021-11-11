#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
    int i, j, temp1, temp2, temp3;
    int a=0, b=0, c=0;
    int niz12[1000], niz23[1000], niz13[1000];
    int logicko=0, k=0; 
    
    
    /*Poredjenje prvog i drugog niza*/
    
    for(i=0; i<vel1; i++) {
        for(j=0; j<vel2; j++) {
            if(niz1[i]==niz2[j])
            {
                niz12[a]=niz1[i];
                a++;
            }
        }
    }
    
    /*Poredjenje drugog i treceg niza*/
    
    for(i=0; i<vel2; i++) {
        for(j=0; j<vel3; j++) {
            if(niz2[i]==niz3[j])
            {
                niz23[b]=niz2[i];
                b++;
            }
        }
    }
    
    /*Poredjenje prvog i treceg niza*/
    
    for(i=0; i<vel3; i++) {
        for(j=0; j<vel1; j++) {
            if(niz3[i]==niz1[j])
            {
                niz13[c]=niz3[i];
                c++;
            }
        }
    }
    
    /*Sortiranje niz12 po velicini*/
    
    for(i=0; i<a; i++) {
        for(j=0; j<a; j++) {
            if(niz12[i]<niz12[j])
            {
                temp1=niz12[i];
                niz12[i]=niz12[j];
                niz12[j]=temp1;
            }
        }
    }
    
    /*Sortiranje niz23 po velicini*/
    
    for(i=0; i<b; i++) {
        for(j=0; j<b; j++) {
            if(niz23[i]<niz23[j])
            {
                temp2=niz23[i];
                niz23[i]=niz23[j];
                niz23[j]=temp2;
            }
        }
    }
    
    /*Sortiranje niz13 po velicini*/
    
    for(i=0; i<c; i++) {
        for(j=0; j<c; j++) {
            if(niz13[i]<niz13[j])
            {
                temp3=niz13[i];
                niz13[i]=niz13[j];
                niz13[j]=temp3;
            }
        }
    }
    
    
    /*Uklanjanje duplikata iz niz12*/
    
    for(i=0; i<a; i++) {
        for(j=i+1; j<a; j++) {
            if(niz12[i]==niz12[j])
            {
                niz12[j]=niz12[a-1];
                a--;
                j--;
            }
        }
    }
    
    
    /*Uklanjanje duplikata iz niz23*/
    
    for(i=0; i<b; i++) {
        for(j=i+1; j<b; j++) {
            if(niz23[i]==niz23[j])
            {
                niz23[j]=niz23[b-1];
                b--;
                j--;
            }
            
        }
    }
    
    /*Uklanjanje duplikata iz niz13*/
    
    for(i=0; i<c; i++) {
        for(j=i+1; j<c; j++) {
            if(niz13[i]==niz13[j])
            {
                niz13[j]=niz13[c-1];
                c--;
                j--;
            }
            
        }
    }
    
    
    for(i=0; i<a; i++) {
        for(j=0; j<b; j++) {
            if(niz12[i]==niz23[j])
            logicko=1;
        }
        if(logicko==0)
        k++;
        logicko=0;
    }
    
    for(i=0; i<b; i++) {
        for(j=0; j<c; j++) {
            if(niz23[i]==niz13[j])
            logicko=1;
        }
        if(logicko==0)
        k++;
        logicko=0;
    }
    
    for(i=0; i<c; i++) {
        for(j=0; j<a; j++) {
            if(niz13[i]==niz12[j])
            logicko=1;
        }
        if(logicko==0)
        k++;
        logicko=0;
    }
    
    return k;
}

int main()
{
    int niz1[1000], niz2[1000], niz3[1000], vel1, vel2, vel3, i;
    
    printf("Unesite velicinu prvog niza: ");
    scanf("%d", &vel1);
    printf("Unesite elemente prvog niza: ");
    for(i=0; i<vel1; i++)
    scanf("%d", &niz1[i]);
    
    printf("Unesite velicinu drugog niza: ");
    scanf("%d", &vel2);
    printf("Unesite elemente drugog niza: ");
    for(i=0; i<vel2; i++)
    scanf("%d", &niz2[i]);
    
    printf("Unesite velicinu treceg niza: ");
    scanf("%d", &vel3);
    printf("Unesite elemente treceg niza: ");
    for(i=0; i<vel3; i++)
    scanf("%d", &niz3[i]);
    
    printf("%d", dva_od_tri(niz1, vel1, niz2, vel2, niz3, vel3));
    
    return 0;
}