#include <stdio.h>
#define PI 3.1415926

int main() {
    int  j,i,st,n, m,s, ST[500],MIN[500],SEC[500];
    double niz[500],temp;
    printf ("Unesite broj uglova: ");
    do{
        scanf("%d",&n);
        if(n<0 || n>500)printf("Ponovite unos");
    }while(n<0 || n>500);
    for(i=0;i<n;i++){
        scanf("%lf",&niz[i]);
    }
    for(i=0;i<n;i++){
        if(niz[i]>=0){
            temp=niz[i];
            st=temp*(180/PI);
            m=((temp*(180/PI))-st)*60;
            s=((((temp*(180/PI))-st)*60-m)*60)+.5;
            if(s>=60){s=s-60;m++;}
            if(m>=60){m=m-60;st++;}
            if( s>=31){
                for(j=i;j<n-1;j++)
                niz[j]=niz[j+1];
                n--;i--;
            }
            else{ST[i]=st;MIN[i]=m;SEC[i]=s;}
        }
        else {
            temp=-niz[i];
            st=temp*(180/PI);
            m=((temp*(180/PI))-st)*60;
            s=((((temp*(180/PI))-st)*60-m)*60)+.5;
            if(s>=60){s=s-60;m++;}
            if(m>=60){m=m-60;st++;}
            if(s>=31){
                for(j=i;j<n;j++)
                niz[j]=niz[j+1];
                n--;i--;
            }
            else{ST[i]=-st;MIN[i]=m;SEC[i]=s;}
        }
    }
    printf("Uglovi su:\n");
    for(i=0;i<n;i++)
    printf ("%d stepeni %d minuta %d sekundi\n", ST[i],MIN[i], SEC[i]);

	return 0;
}
