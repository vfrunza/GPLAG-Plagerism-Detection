/B2017/2018: Zadaća 3, Zadatak 3

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica
    {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };
    
template <typename TipElemenata>
    void PSSkalarom (Matrica <TipElemenata> mat, double skalar)
    {
        for(int i=0; i<mat.br_redova; i++)
        {
            for(int j=0; j<mat.br_kolona; j++)
            {
                mat.elementi[i][j] = mat.elementi[i][j] * skalar;
            }
        }
    }
    
template <typename TipElemenata>
    void UnistiMatricu(Matrica <TipElemenata> mat)
    {
        if(!mat.elementi) return;
        for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> StvoriMatricu (int br_redova, int br_kolona)
    {
        Matrica <TipElemenata> mat;
        mat.br_redova = br_redova;
        mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
        try{
            for(int i=0; i<br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica <TipElemenata> &mat)
    {
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++)
            {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu (const Matrica <TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
    {
        for(int i=0; i<mat.br_redova; i++)
        {
            for(int j=0; j<mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
                std::cout << std::endl;
        }
        if(treba_brisati == true) UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> ZbirMatrica (const Matrica <TipElemenata> &m1, const Matrica <TipElemenata> &m2)
    {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
            
            auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
            for(int i=0; i<m1.br_redova; i++)
                for(int j=0; j<m1.br_kolona; j++)
                    m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
                    
                    return m3;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> ProduktMatrica (const Matrica <TipElemenata> &m1, const Matrica <TipElemenata> &m2)
    {
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error ("Matrice nisu saglasne za mnozenje");
            
        auto m3 (StvoriMatricu <TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i<m1.br_redova; i++)
        {
            for(int j=0; j<m2.br_kolona; j++)
            {
                TipElemenata suma=0;
                for(int k=0; k<m2.br_redova; k++)
                    suma = suma + m1.elementi[i][k] * m2.elementi[k][j];
                m3.elementi[i][j] = suma;
            }
        }
        return m3;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> MatricniPolinom (Matrica <TipElemenata> mat, std::vector<double> v)
    {
        if(mat.br_kolona != mat.br_redova)
            throw std::domain_error ("Matrica mora biti kvadratna");
        auto mat_polinom (StvoriMatricu <TipElemenata> (mat.br_kolona, mat.br_kolona));
        
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++)
                mat_polinom.elementi[i][j] = 0;
        
        for(int i=0; i<v.size(); i++)
        {
            if(v[i] == 0) continue;
            
            try
            {
                auto jed_matrica (StvoriMatricu <TipElemenata> (mat.br_redova, mat.br_kolona));
                for(int i=0; i<mat.br_redova; i++)
                    for(int j=0; j<mat.br_kolona; j++)
                    {
                        if(i==j) jed_matrica.elementi[i][j] = 1;
                        else jed_matrica.elementi[i][j] = 0;
                    }
                    for(int j=0; j<i; j++)
                    {
                        auto temp(jed_matrica);
                        try
                        {
                            jed_matrica = ProduktMatrica(mat, jed_matrica);
                            UnistiMatricu(temp);
                        }
                        catch(...)
                        {
                            UnistiMatricu(jed_matrica);
                            throw;
                        }
                    }
                    PSSkalarom(jed_matrica, v[i]);
                    try
                    {
                        auto temp(mat_polinom);
                        mat_polinom = ZbirMatrica(mat_polinom, jed_matrica);
                        UnistiMatricu(jed_matrica);
                        UnistiMatricu(temp);
                    }
                    catch(...)
                    {
                        UnistiMatricu(jed_matrica);
                        throw;
                    }
            }
            catch(...)
            {
                UnistiMatricu(mat_polinom);
                throw;
            }
        }
        return mat_polinom;
    }

int main()
{
  // std::cout << "sve je ok";
  
  Matrica <double> a;
  std::vector<double> K;
  int m;
  
  std::cout << "Unesite dimenziju kvadratne matrice: ";
  std::cin >> m;
  
  try
  {
      a = StvoriMatricu <double> (m, m);
      std::cout << "Unesite elemente matrice A: " << std::endl;
      UnesiMatricu('A', a);
      std::cout << "Unesite red polinoma: ";
      int n;
      std::cin >> n;
      std::cout << "Unesite koeficijente polinoma: ";
      
      for(int i=0; i<n+1; i++)
      {
          double broj;
          std::cin >> broj;
          K.push_back(broj);
      }
      IspisiMatricu(MatricniPolinom(a, K), 10, 6, true);
      UnistiMatricu(a);
  }
  catch(...)
  {
      UnistiMatricu(a);
  }
    
    return 0;
}