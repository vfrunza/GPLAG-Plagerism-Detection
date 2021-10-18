/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

template<typename Tip>
class Gmatrica
{
  Tip elementi[4][4];
  int br_redova, br_kolona;
public:
    Gmatrica();
    Gmatrica(int m, int n);
    Gmatrica(int m, int n, Tip v);
    Gmatrica(const Gmatrica<Tip> &mat);
    Gmatrica(Tip mat[]);
    Gmatrica(const std::vector<std::vector<Tip>> &mat);
    Gmatrica(const std::initializer_list<std::initializer_list<Tip>> &lista);
    
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; }
    
    /*friend std::istream &operator >> (std::istream &tok, Gmatrica &mat);*/
    template <typename Tip1>
    friend std::ostream &operator << (std::ostream &tok, const Gmatrica<Tip1> &mat);
    
    Tip &operator () (int i, int j);
    Tip *operator [] (int i);
    Tip const *operator [] (int i) const; 
    
    template <typename Tip1>
    friend bool operator == (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip1> &mat2); 
    template <typename Tip1>
    friend bool operator != (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip1> &mat2); 
    
    template <typename Tip1, typename Tip2>
    friend Gmatrica operator + (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip2> &mat2);
    template <typename Tip1, typename Tip2>
    friend Gmatrica operator - (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip2> &mat2);
    template <typename Tip1, typename Tip2>
    friend Gmatrica operator * (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip2> &mat2);

    
    Gmatrica &operator += (const Gmatrica &x);
    Gmatrica &operator -= (const Gmatrica &x);
    Gmatrica &operator *= (const Gmatrica &x);
};

//Konstruktori
template <typename Tip>
Gmatrica<Tip>::Gmatrica() : br_redova(0), br_kolona(0) {}

template<typename Tip>
Gmatrica<Tip>::Gmatrica(int m, int n) : br_redova(m), br_kolona(n)
{
    if(m < 0 || m > 4 || n < 0 || n > 4)
      throw std::logic_error("Ilegalan format matrice");
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
          elementi[i][j] = 0;
    }
}

template<typename Tip>
Gmatrica<Tip>::Gmatrica(int m, int n, Tip v) : br_redova(m), br_kolona(n)
{
    if(m < 0 || m > 4 || n < 0 || n > 4)
      throw std::logic_error("Ilegalan format matrice");
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
          elementi[i][j] = v;
    }
}

template <typename Tip>
Gmatrica<Tip>::Gmatrica(const Gmatrica<Tip> &mat) : br_redova(mat.br_redova), br_kolona(mat.br_kolona)
{
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
          elementi[i][j] = mat[i][j];
    }
}

template <typename Tip>
Gmatrica<Tip>::Gmatrica(Tip mat[]) : br_redova(4), br_kolona(4)
{
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
          elementi[i][j] = mat[i][j];
    }
}

template <typename Tip>
Gmatrica<Tip>::Gmatrica(const std::vector<std::vector<Tip>> &mat) : br_redova(mat.size()), br_kolona(mat[0].size())
{
    if(mat.size() < 0 || mat.size() > 4 || mat[0].size() < 0 || mat[0].size() > 4)
      throw std::logic_error("Ilegalan format matrice");
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
          elementi[i][j] = mat[i][j];
    }
}

template <typename Tip>
Gmatrica<Tip>::Gmatrica(const std::initializer_list<std::initializer_list<Tip>> &lista) : br_redova(lista.size()), br_kolona(lista.begin()->size())
{
    if(lista.size() < 0 || lista.size() > 4)
      throw std::logic_error("Ilegalan format matice");
    
    int i(0), j(0);
    for (const auto& l : lista)
    {
        for (const auto& v : l)
        {
           elementi[i][j] = v;
           ++j;
        }
        j = 0;
        ++i;
    }
}

//Operatori
template <typename Tip1>
std::ostream &operator << (std::ostream &tok, const Gmatrica<Tip1> &mat)
{
    int wide(tok.width());
    if(wide < 6) wide = 6;
    for(int i(0); i < mat.br_redova(); i++)
    {
        for(int j(0); j < mat.br_kolona(); j++)
        {
            tok << std::setw(wide) << mat.elementi[i][j]; 
        }
        tok << std::endl;
    }
    return tok;
}

template <typename Tip>
Tip &Gmatrica<Tip>::operator () (int i, int j)
{
    if(i <= 0 || i > br_redova || j <= 0 || j > br_kolona)
      throw std::range_error("Nedozvoljen indeks");
    
    return elementi[i - 1][j - 1];
}

template <typename Tip>
Tip *Gmatrica<Tip>::operator [] (int i)
{
    return elementi[i];
}

template <typename Tip>
Tip const *Gmatrica<Tip>::operator [] (int i) const
{
    return elementi[i];
}

template <typename Tip1>
bool operator == (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip1> &mat2)
{
    if(mat1.br_redova != mat2.br_redova || mat1.br_kolona != mat2.br_kolona)
      return false;
    for(int i(0); i < mat1.br_redova; i++)
    {
        for(int j(0); j < mat1.br_kolona; j++)
        {
            if(mat1.elementi[i][j] != mat2.elementi[i][j])
              return false;
        }
    }
    return true;
}

template <typename Tip1>
bool operator != (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip1> &mat2)
{
    return !(mat1 == mat2);
}

template <typename Tip1, typename Tip2>
auto operator + (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip2> &mat2) -> Gmatrica<decltype(mat1[0][0] + mat2[0][0])>
{
    if(mat1.br_redova != mat2.br_redova || mat1.br_kolona != mat2.br_kolona)
      throw std::domain_error("Nedozvoljena operacija");
   Gmatrica<decltype(mat1[0][0] + mat2[0][0])> mat3(mat1.br_redova, mat2.br_kolona);
   
   for(int i(0); i < mat1.br_redova(); i++)
   {
       for(int j(0); j < mat1.br_kolona(); j++)
       {
           mat1[i][j] = mat1[i][j] + mat2[i][j];
       }
   }
   return mat3;
}

template <typename Tip1, typename Tip2>
auto operator - (const Gmatrica<Tip1> &mat1, const Gmatrica<Tip2> &mat2) -> Gmatrica<decltype(mat1[0][0] - mat2[0][0])>
{
    if(mat1.br_redova != mat2.br_redova || mat1.br_kolona != mat2.br_kolona)
      throw std::domain_error("Nedozvoljena operacija");
    Gmatrica<decltype(mat1[0][0] - mat2[0][0])> mat3(mat1.br_redova, mat2.br_kolona);
    
    for(int i(0); i < mat1.br_redova(); i++)
    {
       for(int j(0); j < mat1.br_kolona(); j++)
       {
           mat1[i][j] = mat1[i][j] - mat2[i][j];
       }
    }
   return mat3;
}

template <typename Tip1, typename Tip2>
auto operator * (const Gmatrica<Tip1> &x, const Gmatrica<Tip2> &y) -> Gmatrica<decltype(x[0][0] * y[0][0])>
{
    if(x.br_kolona != y.br_redova)
      throw std::domain_error("Nedozvoljena operacija");
}

template <typename Tip>
Gmatrica<Tip> &Gmatrica<Tip>::operator += (const Gmatrica<Tip> &x)
{
    if(br_redova != x.br_redova || br_kolona != x.br_kolona)
      throw std::domain_error("Nedozvoljena operacija");
    
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
        {
            elementi[i][j] += x.elementi[i][j];
        }
    }
    return *this;
}

template <typename Tip>
Gmatrica<Tip> &Gmatrica<Tip>::operator -= (const Gmatrica<Tip> &x)
{
    if(br_redova != x.br_redova || br_kolona != x.br_kolona)
      throw std::domain_error("Nedozvoljena operacija");
    
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
        {
            elementi[i][j] -= x.elementi[i][j];
        }
    }
    return *this;
}

template <typename Tip>
Gmatrica<Tip> &Gmatrica<Tip>::operator *= (const Gmatrica<Tip> &x)
{
    if(br_kolona != x.br_redova)
      throw std::domain_error("Nedozvoljena operacija");
    
    Gmatrica<Tip> m3(br_redova, x.br_kolona);
    
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < x.br_kolona; j++)
        {
            for(int k(0); k < br_kolona; k++)
            {
                m3.elementi[i][j] += (elementi[i][k] * x.elementi[k][j]);
            }
        }
    }
    *this = m3;
    return *this;
}

int main ()
{
    /*std::vector<std::vector<int>> a{{1,2}, {3,4}};
    std::vector<std::vector<double>> b{{2,4}, {6,8}};*/
    Gmatrica<int> x({{1, 2}, {3, 4}});
    
    for(int i(0); i < x.DajBrojRedova(); i++)
    {
        for(int j(0); j < x.DajBrojKolona(); j++)
        {
            std::cout << x[i][j] << " ";            
        }
        std::cout << std::endl;
    }
  
    return 0;
}