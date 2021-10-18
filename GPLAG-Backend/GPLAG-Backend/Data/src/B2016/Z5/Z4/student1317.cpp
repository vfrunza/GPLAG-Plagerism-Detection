/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

using namespace std;

template <typename NekiTip>
class GMatrica
{
    NekiTip matrica[4][4];
    int broj_redova, broj_kolona;
    
    public:
        GMatrica() : broj_redova(0), broj_kolona(0) { }
        GMatrica(int br_redova, int br_kolona, NekiTip elementi=NekiTip());
        template <typename Tip>
        GMatrica(const GMatrica<Tip> &m);
};

template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(int br_redova, int br_kolona, NekiTip elementi) : broj_redova(br_redova), broj_kolona(br_kolona)
{
    if(!(broj_redova>0 && broj_redova<=4) || !(broj_kolona>0 && broj_kolona<=4)) throw logic_error("Ilegalan format matrice");
    for(int i=0; i<broj_redova; i++)
    {
        for(int j=0; j<broj_kolona; i++)
        {
            matrica[i][j]=elementi;
        }
    }
}

template <typename Tip>
GMatrica<Tip>::GMatrica(const GMatrica<Tip> &m) : broj_redova(m.broj_redova), broj_kolona(m.broj_kolona)
{
    if(!(broj_redova>0 && broj_redova<=4) || !(broj_kolona>0 && broj_kolona<=4)) throw logic_error("Ilegalan format matrice");
    for(int i=0; i<broj_redova; i++)
    {
        for(int j=0; j<broj_kolona; i++)
        {
            matrica[i][j]=m[i][j];
        }
    }
}

int main ()
{
	GMatrica<int> g(3, 2, 4);
	return 0;
}



