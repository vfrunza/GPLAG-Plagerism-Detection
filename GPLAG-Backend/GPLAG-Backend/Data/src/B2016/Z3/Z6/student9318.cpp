/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
int main (){
     
    for(int i=0; i<jedinicna.br_redova; i++){
            for(int j=0; j<jedinicna.br_kolona; j++){
                if(i==j) jedinicna.elementi[i][j]=1;
                else jedinicna.elementi[i][j]=0;
            }
        }
        return jedinicna;
	return 0;
}