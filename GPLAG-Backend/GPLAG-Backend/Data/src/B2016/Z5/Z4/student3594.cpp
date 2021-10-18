/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

template <typename NekiTip>
class GMatrica{
  int broj_redova;
  int broj_kolona;
  NekiTip mat[4][4];
  static bool Uporedi(const GMatrica<NekiTip> &mat1, const GMatrica<NekiTip> &mat2);
  public:
  
  GMatrica();
  GMatrica(int br_r, int br_k, NekiTip pocetna = NekiTip {} );
  template <typename Tip1> 
  GMatrica(const GMatrica<Tip1> &mat2){
  broj_redova = mat2.broj_redova;
  broj_kolona = mat2.broj_kolona;
  for(int i=0; i<mat2.broj_redova; i++){
    for(int j=0; j<mat2.broj_kolona; j++){
      mat[i][j] = mat2.mat[i][j];    
    }
  }
  
}
  //template <typename Tip1> GMatrica(Tip1 niz);
  GMatrica(std::vector<std::vector<NekiTip>> vek);
  GMatrica(std::initializer_list<std::initializer_list<NekiTip>> lista);
  int DajBrojRedova() const {return broj_redova;}
  int DajBrojKolona() const {return broj_kolona;}
  template <typename T1, typename T2> 
  friend auto operator +(GMatrica<T1> mat1, GMatrica<T2> mat2)-> GMatrica<decltype(mat1.mat[0][0] + mat2.mat[0][0])>;
  template <typename T1, typename T2> 
  friend auto operator -(GMatrica<T1> mat1, GMatrica<T2> mat2) -> GMatrica<decltype(mat1.mat[0][0] - mat2.mat[0][0])>;
  template <typename T1, typename T2> 
  friend auto operator *(GMatrica<T1> mat1, GMatrica<T2> mat2) -> GMatrica<decltype(mat1.mat[0][0] * mat2.mat[0][0])>;
  template <typename T2>
  friend GMatrica<NekiTip> operator*(GMatrica<NekiTip> mat1, T2 x){
  for(int i=0; i<mat1.broj_redova; i++){
    for(int j=0; j<mat1.broj_kolona; j++){
      mat1.mat[i][j] *= x;
    }
  }
  return mat1;
  }
  template <typename Tip1> 
  friend GMatrica<NekiTip> operator*(Tip1 x, GMatrica<NekiTip> mat1){
   return mat1*x;
 }
  template<typename T1>
  GMatrica<NekiTip> &operator +=(T1 x){
  for(int i=0; i<broj_redova; i++){
    for(int j=0; j<broj_kolona; j++){
      this -> mat[i][j] += x;
    }
  }
  return *this;
  }
  template<typename T1>
  GMatrica<NekiTip> &operator -=(T1 x){
  for(int i=0; i<broj_redova; i++){
    for(int j=0; j<broj_kolona; j++){
      this -> mat[i][j] -= x;
    }
  }
  return *this;
  }
  template<typename T1>
  GMatrica<NekiTip> &operator *=(T1 x){
  for(int i=0; i<broj_redova; i++){
    for(int j=0; j<broj_kolona; j++){
      this -> mat[i][j] *= x;
    }
  }
  return *this;
  }
  template<typename T1>
  GMatrica<NekiTip> &operator +=(GMatrica<T1> mat){
    *this = *this + mat;
    return *this;
  }
   template<typename T1>
  GMatrica<NekiTip> &operator -=(GMatrica<T1> mat){
    *this = *this - mat;
    return *this;
  }
   template<typename T1>
  GMatrica<NekiTip> &operator *=(GMatrica<T1> mat){
    *this = *this * mat;
    return *this;
  }
  friend bool operator==(const GMatrica<NekiTip> &mat1, const GMatrica<NekiTip> &mat2){if(Uporedi(mat1, mat2)) return true; else return false; }
  friend bool operator!=(const GMatrica<NekiTip> &mat1, const GMatrica<NekiTip> &mat2){if(Uporedi(mat1, mat2)) return false; else return true; }
  NekiTip* operator[](int x);
  NekiTip operator()(int x, int y);
  template <typename T>
  friend std::ostream &operator <<(std::ostream &tok, const GMatrica<T> &mat);
  template <typename T>
  friend std::istream &operator >>(std::istream &tok, GMatrica<T> &x);
};

template <typename NekiTip>
bool GMatrica<NekiTip>::Uporedi(const GMatrica<NekiTip> &mat1, const GMatrica<NekiTip> &mat2){
  if(mat1.broj_redova != mat2.broj_redova || mat1.broj_kolona != mat2.broj_kolona) return false;
  bool isti(true);
  for(int i=0; i<mat1.broj_redova; i++){
    for(int j=0; j<mat1.broj_kolona; j++){
      if(mat1.mat[i][j] != mat2.mat[i][j]){
        isti = false;
        break;
      }
    }
}
return isti;
}

template <typename NekiTip>
NekiTip* GMatrica<NekiTip>::operator[](int x){
  NekiTip* pok = mat[x];
  return pok;
}

template <typename NekiTip>
NekiTip GMatrica<NekiTip>::operator()(int x, int y){
  if(x < 0 || y < 0 || x > broj_redova || y > broj_kolona)throw std::range_error("Nedozvoljen indeks");
  return mat[x-1][y-1];
}

template <typename T>
std::ostream &operator <<(std::ostream &tok, const GMatrica<T> &mat){
  
  int sirina = std::cout.width();
  if(sirina <= 6) sirina = 6;
  
  for(int i=0; i<mat.broj_redova; i++){
    for(int j=0; j<mat.broj_kolona; j++){
      tok <<std::setw(sirina) << mat.mat[i][j];
    }
    tok<< std::endl;
  }
  return tok;
}

template <typename T>
std::istream &operator >>(std::istream &tok, GMatrica<T> &x){
  //		[1,2;3,4]
  tok >> std::ws;
  char znak('b');
  T element;
  int i(0), j(0);
  while(true){
    
    tok >> znak;
    tok >> element;
    x.mat[i][j] = element;
    j++;
    
    if(tok.peek() == ';'){
      j=0;
      i++; 
    }
    if( tok.peek() == ']' || znak == ']'){
      break;
    }
  }
  x.broj_kolona = j;
  x.broj_redova = i+1;
  return tok;
}

template <typename NekiTip>
GMatrica<NekiTip>::GMatrica() {
  broj_kolona = 0;
  broj_redova = 0;
}

template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(int br_r, int br_k, NekiTip pocetna ) {
  broj_kolona = br_r;
  broj_redova = br_k;
  
  for(int i(0); i < br_r; i++){
    for(int j(0); j < br_k; j++){
        mat[i][j] = pocetna;    
    }
  }
  
}

template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(std::vector<std::vector<NekiTip>> vek){
  
 
  int temp = vek[0].size();
  
  if(vek.size() < 0 || vek.size() > 4) throw std::logic_error("Ilegalan format matrice");
  for(int i=0; i< vek.size(); i++)
      if(vek[i].size() != temp) throw std::logic_error("Ilegalan format matrice");
      
  broj_redova = vek.size();
  broj_kolona = vek[0].size();
  
  for(int i=0; i<broj_redova; i++){
    for(int j=0; j<broj_kolona; j++){
        mat[i][j] = vek[i][j];
    }
  }
  
}

template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(std::initializer_list<std::initializer_list<NekiTip>> lista){
  if(lista.size() < 0 || lista.size() > 4) throw std::logic_error("Ilegalan format matrice");
  
  auto it1 = lista.begin();
  broj_redova = lista.size();
  broj_kolona = it1->size();
  
  int i(0), j(0);
  for(auto it1 = lista.begin(); it1 != lista.end(); it1++){
    for(auto it2 = it1 -> begin(); it2 != it1 -> end(); it2++){
      mat[i][j] = *it2;
      j++;
    }
    j=0; i++;
  }
  
}


template <typename T1, typename T2>
auto operator +(GMatrica<T1> mat1, GMatrica<T2> mat2) -> GMatrica<decltype(mat1.mat[0][0] + mat2.mat[0][0])>{
  if(mat1.broj_redova != mat2.broj_redova || mat1.broj_kolona != mat2.broj_kolona) throw std::domain_error("Nedozvoljena operacija");
  
  auto mat3 = GMatrica<decltype(mat1.mat[0][0] + mat2.mat[0][0])>(mat1.broj_redova, mat1.broj_kolona);
  
  for(int i=0; i<mat1.broj_redova; i++){
    for(int j=0; j<mat1.broj_kolona; j++){
      mat3.mat[i][j] = mat1.mat[i][j] + mat2.mat[i][j];
    }
  }
  return mat3;
} 

template <typename T1, typename T2>
auto operator -(GMatrica<T1> mat1, GMatrica<T2> mat2) -> GMatrica<decltype(mat1.mat[0][0] - mat2.mat[0][0])>{
  if(mat1.broj_redova != mat2.broj_redova || mat1.broj_kolona != mat2.broj_kolona) throw std::domain_error("Nedozvoljena operacija");
  
  auto mat3 = GMatrica<decltype(mat1.mat[0][0] - mat2.mat[0][0])>(mat1.broj_redova, mat1.broj_kolona);
  
  for(int i=0; i<mat1.broj_redova; i++){
    for(int j=0; j<mat1.broj_kolona; j++){
      mat3.mat[i][j] = mat1.mat[i][j] - mat2.mat[i][j];
    }
  }
  return mat3;
}

template <typename T1, typename T2> 
auto operator *(GMatrica<T1> mat1, GMatrica<T2> mat2) -> GMatrica<decltype(mat1.mat[0][0] * mat2.mat[0][0])>{
  if(mat1.broj_kolona != mat2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
  
  auto mat3 = GMatrica<decltype(mat1.mat[0][0] * mat2.mat[0][0])>(mat1.broj_redova, mat2.broj_kolona, 0);
  
  for(int i=0; i<mat1.broj_kolona; i++){
    for(int j=0; j<mat2.broj_redova; j++){
      for(int k=0; k<mat2.broj_kolona; k++){
        mat3.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j]; 
      }
    }
  }
  return mat3;
}


int main (){

	return 0;
}