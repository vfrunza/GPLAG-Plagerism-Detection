/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename Tip>
class GMatrica
{
    Tip mat[4][4];
    int br_redova, br_kolona;
public:
    {
       GMatrica() : br_redova(0), br_redova(0) {}
       template <typename Tip2>
       GMatrica(int red, int kolona, Tip2 vrijednost=0);
       template <typename Tip2>
       GMatrica(GMatrica<Tip2> m): br_redova(m.br_redova), br_kolona(m.br_kolona) {}
       template <typename Tip2>
       GMatrica(Tip2 vrijednost): br_redova(4), br_kolona(4) { std::fill(& mat[0][0], &mat[3][3]+1, vrijednost); }
       template <typename Tip2>
       GMatrica(std::vector<std::vector<Tip2>> v)
       
   
};

template <typename Tip>
GMatrica<Tip>::GMatrica(int red, int kolona, Tip vrijednost)
{
    if(red < 0 || red > 4 || kolona < 0 || kolona >4) std::logic_error("Ilegalan format matrice");
    br_redova=red;
    br_kolona=kolona;
    for(int i=0; i<br_redova; i++)
    {
        for(int j=0; j<br_kolona; j++)
        {
            mat[i][j]=vrijednost;
        }
    }
}

int main ()
{
	return 0;
}