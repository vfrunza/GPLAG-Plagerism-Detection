#include <iostream>
#include <stdexcept>
#include <string>

template <typename Tip>
class GMatrica {
    Tip mat[4][4];
    int broj_redova;
    int broj_kolona;
    static void ProvjeraIndeksa(int x, int y){
        if(x < 0 || y < 0 || x > 4 || y > 4)throw std::logic_error("Ilegalan format matrice");
    }
public:
    GMatrica(){ broj_redova = 0; broj_kolona = 0; }
    GMatrica(int broj_r, int broj_k, Tip vrijednost = {}){
        ProvjeraIndeksa(broj_r, broj_k);
        broj_redova = broj_r; broj_kolona = broj_k;
        for(int i(0); i < broj_redova; i++) std::fill(mat[i], mat[i]+ broj_kolona, vrijednost);
    }
    
};
int main ()
{
    try {
        GMatrica<int> m(-1,0);
        
    }catch(std::logic_error iz){
        std::cout << iz.what();
    }
	return 0;
}