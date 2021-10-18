#include<stdio.h>

void izbaci(int A[], int n)
{
    int i, j,k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;) {
            if (A[j] == A[i]) {
                for (k = j; k < n; k++) {
                    A[k] = A[k + 1];
                }
                n--;
            } else
                j++;
        }
    }
}




int dva_od_tri(int A[],int a,int B[],int b,int C[],int c)
{
    int i,j,k,br=0;
    izbaci(A,a);
    izbaci(B,b);
    izbaci(C,c);
    for(i=0; i<a; i++) {
        int br1=0;
        for(j=0; j<b; j++) {
            if(A[i]==B[j])
                br1++;

        }
        for(k=0; k<c; k++) {
            if(A[i]==C[k])
                br1++;
        }
        if(br1==1) br++;
    }


    for(i=0; i<b; i++) {
        for(j=0; j<c; j++) {
            if(B[i]==C[j]) {
                br++;
                for(k=0; k<a; k++) {
                    if(B[i]==A[k]) br--;
                }
            }
        }
    }
    return br;
}

int main()
{
    int a,b,c,i,i1,A[100000],B[100000],C[100000];
    printf("Unesi velicinu niza A: ");
    scanf("%d",&a);
    printf("Unesi clanove niza: ");
    for(i=0; i<a; i++) {
        scanf("%d",&A[i]);
    }
    printf("Unesi velicinu niza B: ");
    scanf("%d",&b);

    printf("Unesi clanove niza: ");
    for(i=0; i<b; i++) {
        scanf("%d",&B[i]);
    }

    printf("Unesi velicinu niza C: ");
    scanf("%d",&c);
    printf("Unesi clanove niza: ");
    for(i=0; i<c; i++) {
        scanf("%d",&C[i]);
    }


    dva_od_tri(A,a,B,b,C,c);
}
