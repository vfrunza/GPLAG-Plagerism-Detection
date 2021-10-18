#include <stdio.h>


char* ubaci_broj (char *tekst, int broj)
{

    int duzina = 0, i=1, j, k, m;
    int d_broja=1, temp=broj;
    char* p=tekst;
    while (temp!=0) {
        temp/=10;
        d_broja++;
    }
    while(p[duzina]!=0)duzina++;
    while(p[i]!=0) {

        if(p[i-1] != ' ' && p[i] == ' ' ) {
            if (broj<0)d_broja++;
            temp=i;

            while(p[temp]== ' ')temp++;
            if (p[temp]==0)return p;

            for( j=duzina; j>i; j--) {
                p[j+d_broja]=p[j];
            }
            duzina+=d_broja;
            k=broj;
            if(broj<0) {
                i++;
                p[i]='-';
                d_broja--;
                k+=-2*broj;

            }

            j=d_broja;
            if(p[i+j+1]!=' ')p[i+j]=' ';
            else {
                for(m=i+j; m<duzina; m++)
                    p[m]=p[m+1];

            }
            while(k!=0) {
                p[i+j-1]='0'+ k%10;
                k/=10;
                j--;

            }
            i=temp+d_broja;
        }
        ++i;
    }
    
    return p;
}

int main ()
{

   char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
printf("\"%s\"", ubaci_broj(s, 320));
    return 0;

}