/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
using namespace std; 
template <typename Tip>
class GMatrica{
    Tip matrica[4][4];
    int broj_redova, broj_kolona; 
public:
    GMatrica(){
       broj_kolona=0, broj_redova=0; 
    }
    GMatrica(int broj_redova, int broj_kolona, Tip broj){
        if(broj_redova>4 || broj_kolona>4 || broj_redova<0 || broj_kolona<0) throw logic_error ("Ilegalan format matrice"); 
        GMatrica::broj_redova=broj_redova; 
        GMatrica::broj_kolona=broj_kolona; 
        for(int i=0; i<broj_redova; i++)
            for(int j=0; j<broj_kolona; j++)
                matrica[i][j]=broj; 
    }
    int DajBrojRedova(){
        return broj_redova; 
    }
    int DajBrojKolona(){
        return broj_kolona;
    }
    
    
}; 
int main ()
{
	return 0;
}