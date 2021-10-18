/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>


template <typename TipElemenata>


class GMatrica
{
    int broj_redova;
    int broj_kolona;
    TipElemenata Matrica[4][4];
    
    public:
    GMatrica() { Matrica[0][0]; }
    
    GMatrica(int br_redova, int br_kolona, TipElemenata Matrica =  TipElemenata())
    {
        if (br_redova < 0 || broj_kolona < 0 || br_redova > 4 || br_kolona > 4)
        {
            throw std::logic_error ("Ilegalan format matrice");
        }
        
        this -> broj_redova = br_redova;
        this -> broj_kolona = br_kolona;
    }
    
  
   template <typename TipElemenata1>
   
   GMatrica(const GMatrica &mat)
   {
       (GMatrica)mat;
   }
   
   template <typename TipElemenata2>
   
   GMatrica(const TipElemenata mat[4][4])
   {
       GMatrica mat1[4][4] = mat;
   }
   
 
   GMatrica(std::vector<std::vector<TipElemenata>> &v)
   {
       if (v.broj_redova < 0 || v.broj_redova > 4 || v.broj_kolona < 0 || v.broj_kolona > 4)
       {
           throw std::logic_error ("Ilegalan format matrice");
       }
   }
   

  
    
    int DajBrojRedova() const { return broj_redova; }
    int DajBrojKolona() const { return broj_kolona; }
    
};
int main ()
{
    GMatrica<int> mat(2,13);
    std::cout << mat.DajBrojRedova() << " " << mat.DajBrojKolona();
    
	return 0;
}