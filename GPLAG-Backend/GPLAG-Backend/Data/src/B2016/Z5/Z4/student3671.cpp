/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>


template <typename Tip>

class GMatrica {
    Tip matrica[4][4];
    int redovi, kolone;
    public:
    GMatrica(){ redovi = 0; kolone = 0; };
    GMatrica(int i, int j, Tip p = 0){
        if(i < 0 || i > 4 || j < 0 || j > 4) throw std::logic_error ("Ilegalan format matrice");
        for(int k = 0; k < i; k++){
            for(int z = 0; z < j; z++){
                matrica[k][z] = p;
            }
        }
        redovi = i;
        kolone = j;
    }
    
    GMatrica(const Tip **niz1){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                matrica[i][j] = niz1[i][j];
            }
        }
        redovi = 2;
        kolone = 2;
    }
    
    GMatrica(std::vector<std::vector<Tip>> M){
        for(int i = 0; i < M.size(); i++){
            for( int j = 0; j<M[0].size(); j++){
                matrica[i][j] = M[i][j];
            }
        }
        redovi = M.size();
        kolone = M[0].size();
    }
    
    GMatrica(std::initializer_list<Tip> lista){
        
        std::initializer_list<Tip>::iterator k(lista.begin());
        auto b(lista.end());
        int brojac = 0;
        while(k!=b)
            brojac++;
        int d;
        if(brojac % 4 == 0)
            d = 4;
        else if(brojac % 3 == 0)
            d = 3;
        else if(brojac % 2 == 0)
            d = 2;
        else d = 1;
        for(int i = 0; i < d; i++){
            for(int j = 0; j < d; j++){
                matrica[i][j] = *k++;
            }
        }
    }
    int DajBrojRedova() const { return redovi; }
    int DajBrojKolona() const { return kolone; }
};

int main ()
{
   GMatrica<int> m1;
   std::cout << m1.DajBrojKolona() <<"," <<m1.DajBrojRedova() << std::endl;
   
   GMatrica<int> m4(4,4,5);
   std::cout<< m4.DajBrojKolona()<<","<<m4.DajBrojRedova()<<std::endl;
   
   GMatrica<int> m2({{1, 2}, {3, 4}});
   std::cout << m2.DajBrojKolona() <<"," <<m2.DajBrojRedova() << std::endl;
   
   GMatrica<int> m3{{1, 2}, {3, 4}};
   std::cout << m3.DajBrojKolona() <<"," <<m3.DajBrojRedova() << std::endl;
	return 0;
}