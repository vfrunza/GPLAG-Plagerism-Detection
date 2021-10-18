/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

template <typename TipElemenata>
struct Matrica{
  int br_redova, br_kolona;
  TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}


template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu (int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata* [br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
    try{
        for(int i=0; i<br_redova; i++)
          mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
        
    }
    return mat;
}


template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++)
      for(int j=0; j<mat.br_kolona; j++){
          std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
          std::cin>>mat.elementi[i][j];
      }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
          std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati)
      UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
      throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m1.br_kolona; j++)
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova)
      throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m2.br_kolona; j++){
          TipElemenata suma = TipElemenata();
          for(int k=0; k<m2.br_redova; k++)
            suma+=m1.elementi[i][k] * m2.elementi[k][j];
        m3.elementi[i][j] = suma;
      }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &a, const std::vector<double> &v){
  if(a.br_redova!=a.br_kolona)
    throw std::domain_error ("Matrica mora biti kvadratna");
  auto b(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
  for(int i=0; i<b.br_redova; i++)
    for (int j=0; j<b.br_kolona; j++)
      b.elementi[i][j] = TipElemenata();
  if(v.size()==0)
    return b;
  
  for(int k=0; k<v.size(); k++){
    try{
      auto m(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
      int l(0);
      for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++){
          if(i==j)
            m.elementi[i][j] = 1;
          else
            m.elementi[i][j] = 0;
        }
        while (l<k) {
          Matrica<TipElemenata> n = m;
          m = ProduktMatrica(a, m);
          UnistiMatricu(n);
          l++;
        }
        for(int i=0; i<m.br_redova; i++){
          for(int j=0; j<m.br_kolona; j++)
            m.elementi[i][j]*=v[k];
        }
       Matrica<TipElemenata> s = b;
        b = ZbirMatrica(b, m);
       UnistiMatricu(s);
        UnistiMatricu(m);
    }
    catch(...){
      UnistiMatricu(b);
      throw;
    }
  }
  return b;
}


int main ()
{
    Matrica<double> a, b;
    int n;
	std::cout<<"Unesite dimenziju kvadratne matrice: ";
	std::cin>>n;
	try{
	    a = StvoriMatricu<double>(n, n);
	    std::cout<<"Unesite elemente matrice A:\n";
	    UnesiMatricu('A', a);
	    std::cout<<"Unesite red polinoma: ";
	    int p;
	    std::cin>>p;
	    std::vector<double> v(p + 1);
	    std::cout<<"Unesite koeficijente polinoma: ";
	    for(int i=0; i<=p; i++)
	      std::cin>>v[i];
	   b = MatricniPolinom(a, v);
	   IspisiMatricu(b, 10);
	}
	catch(std::bad_alloc){
	    std::cout<<"Nema dovoljno memorije!\n";
	}
	UnistiMatricu(a); UnistiMatricu(b); 
	return 0;
}