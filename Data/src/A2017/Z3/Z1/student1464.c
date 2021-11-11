#include <stdio.h>


int dva_od_tri(int na[], int a, int nb[], int b, int nc[], int c)
{
    int temp[3000][3];
    int i, j, broj=0;

    for(i=0; i<a; i++) {
        for(j=0; j<broj && temp[j][0]!=na[i]; j++);
        if(j==broj) {
            temp[j][0]=na[i];
            temp[j][1]=1;
            temp[j][2]=0;
            broj++;
        }
    }
    // 1 1 2 3 4 4
    // 1 2 2 
    // 3 3 1
    
    // 1 2 3 4 elementi
    // 3 2 2 1 u koliko niyova se ponavlja
    // 2 1 2 0 u u kojem niyu se ponovilo
    for(i=0; i<b; i++) {
        for(j=0; j<broj; j++)
            if(temp[j][0]==nb[i]) {
                if(temp[j][2]!=1)temp[j][1]++;
                temp[j][2]=1;
                break;
        }
        if(j==broj) {
            temp[j][0]=nb[i];
            temp[j][1]=1;
            temp[j][2]=1;
            broj ++;
        }
    }
    for(i=0; i<c; i++) {
        for(j=0; j<broj; j++)
            if(temp[j][0]==nc[i]) {
                if(temp[j][2]!=2)temp[j][1]++;
                temp[j][2]=2;
                break;
        }
        if(j==broj) {
            temp[j][0]=nc[i];
            temp[j][1]=1;
            temp[j][2]=2;
            broj++;
        }
    }

    j=0;
    // prolayoi kroz tabelu i broji koliko se puta clan ponovio
    for(i=0; i<broj; i++) if(temp[i][1]==2) j++;
    return j;
}
            int main() {

                return 0;
            }
