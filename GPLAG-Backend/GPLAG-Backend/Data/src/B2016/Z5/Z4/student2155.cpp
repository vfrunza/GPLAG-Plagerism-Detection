#include <iostream>
#include <stdexcept>
template<typename TipEl>
class GMatrica{
    TipEl mat[4][4];
    int br_redova,br_kolona;
    public:
    GMatrica():br_kolona(0),br_redova(0){}
    template <typename Tip2>
        GMatrica(int br_redova,int br_kolona,Tip2 pocetna_vrijednost);
};

int main ()
{
	return 0;
}