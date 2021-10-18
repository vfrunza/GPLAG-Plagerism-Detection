/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <vector>
#include <initializer_list>

template <typename Tipic>
class GMatrica{
    
    int br_redova;
    int br_kolona;
    Tipic elementi[4][4];
    char ime_matrice;
    
    public:  
        
        GMatrica(): br_redova(0), br_kolona(0) {}
        GMatrica(int br_redova, int br_kolona, Tipic Vrijednost=Tipic());
        
        template<typename Tipic1>
        GMatrica(const GMatrica<Tipic1> &m);
        
        template<typename Tipic1>
        GMatrica(const std::initializer_list<std::initializer_list<Tipic1>> &listica);
        
        template<typename Tipic1>
        GMatrica(std::vector<std::vector<Tipic1>> vektorcic);
        
        GMatrica (Tipic dvaDniz[4][4]);
        
        int DajBrojRedova() {return br_redova;}
        int DajBrojKolona() {return br_kolona;}
        
        template <typename Tip>
        friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip> &mat);  
        
        template <typename Tip>
        friend std::istream &operator >>(std::istream &tok, GMatrica<Tip> &mat);        
        
        template <typename Tip>
        friend GMatrica<Tip> operator +(const GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
        
        template <typename Tip>
        friend GMatrica<Tip> operator -(const GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
        
        template <typename Tip>
        friend GMatrica<Tip> operator *(const GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
        
        template <typename Tip>
        friend GMatrica<Tip> operator +=(GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
        
        template <typename Tip>
        friend GMatrica<Tip> operator *=(GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
        
        template <typename Tip,typename Tip1>
        friend GMatrica<Tip> operator -=(GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
        
        template <typename Tip,typename Tip1>
        friend GMatrica<Tip> operator *(const GMatrica<Tip> &mat1, Tip1 n);
        
        template <typename Tip,typename Tip1>
        friend GMatrica<Tip> operator *=(const GMatrica<Tip> &mat1, Tip1 n);
        
        template <typename Tip1,typename Tip>
        friend GMatrica<Tip> operator *(Tip1 n, const GMatrica<Tip> &mat2);
        
        template <typename Tip1,typename Tip>
        friend GMatrica<Tip> operator *=(Tip1 n, const GMatrica<Tip> &mat2);
        
        template <typename Tip>
        friend bool operator ==(const GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
        
        template <typename Tip>
        friend bool operator !=(const GMatrica<Tip> &mat1, const GMatrica<Tip> &mat2);
       
        
        
        
        
    const Tipic operator [](int indeks) const{

        return elementi[indeks];
    }
    const Tipic operator () (int i,int j) const{
      if(i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
        if(j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    
    
    auto operator [](int indeks) ->decltype(*elementi){
        return elementi[indeks];
    }
    auto operator () (int i,int j) ->decltype(**elementi){
        if(i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
        if(j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    
    
};

//2D VEKTOR

template <typename Tipic>
template<typename Tipic1>
GMatrica<Tipic>::GMatrica(std::vector<std::vector<Tipic1>> vektorcic){
    for(int i=0; i<vektorcic.size();i++){
        for(int j=0; j<vektorcic[i].size(); j++){
            elementi[i][j]=vektorcic[i][j];
        }
    }
}

template <typename Tipic>
template<typename Tipic1>
GMatrica<Tipic>::GMatrica(const std::initializer_list<std::initializer_list<Tipic1>> &listica) {
    br_redova = listica.size();
    br_kolona = (*listica.begin()).size();
    int i(0), j(0);
    for(auto red : listica) {
        for (auto el: red) {
            elementi[i][j] = el;
            j++;
        }
        j=0;
        i++;
    }
}

template <typename Tipic>
GMatrica<Tipic>::GMatrica (Tipic dvaDniz[4][4]) : br_redova(4), br_kolona(4) {

        for(int i(0);i<4;i++){
            for(int j(0);j<4;j++){
                elementi[i][j]=dvaDniz[i][j];
            }
        }
}

template<typename Tipic>
template<typename Tipic1>//,typename Tip2>
GMatrica<Tipic>::GMatrica (const GMatrica<Tipic1> &m) : br_kolona(m.br_kolona),br_redova(m.br_redova), ime_matrice(m.ime_matrice), elementi(m.elementi){
    if(m.br_kolona<0 || m.br_kolona>4 || m.br_redova<0 || m.br_redova>4)
        throw std::logic_error("Ilegalan format matrice");
         for(int i(0);i<m.br_redova;i++){
            for(int j(0);j<m.br_kolona;j++){
                elementi[i][j]=m.elementi[i][j];
            }
        }
}

//INICIJALIZACIJA ZADAVANJEM PARAMETARA
template<typename Tipic>
 GMatrica<Tipic>::GMatrica(int br_redova, int br_kolona, Tipic Vrijednost) : br_redova(br_redova), br_kolona(br_kolona){
     if (br_kolona>4 || br_kolona<0 || br_redova>4 || br_redova<0)
        throw std::logic_error("Ilegalan format matrice");
         for(int i(0);i<br_redova;i++){
            for(int j(0);j<br_kolona;j++){
                elementi[i][j]=Vrijednost;
            }
        }
    }
 
 
 
template<typename Tipic>
std::ostream &operator <<(std::ostream &tok, const GMatrica<Tipic> &mat){
      int sirina_ispisa(tok.width());
      if (tok.width() < 6)
        sirina_ispisa = 6;
      for(int i(0);i<mat.br_redova;i++){
            for(int j(0);j<mat.br_kolona;j++){
                tok<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
            }
        std::cout<<std::endl;
      }
      return tok;
  }
    
template<typename Tipic>
std::istream &operator >>(std::istream &tok, GMatrica<Tipic> &mat){
    //  int sirina_ispisa(tok.width());
    char znak(0);
      tok >> znak;
      mat = GMatrica<Tipic>(4,4, Tipic());
      int i(0), j(0);
      while(i < 4) {
          while(j < 4) {
              tok >> mat.elementi[i][j];
              j++;
              tok >> znak;
              if (znak == ';' || znak == ']') {
                  mat.br_kolona = j;
                  j = 0;
                  break;
              }
              
          }
          
          i++;
          if (znak == ']') {
              mat.br_redova = i;
            break;
          }
      }
      return tok;
  }
template<typename Tipic>
GMatrica<Tipic> operator -(const GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    
    if((mat1.br_kolona!=mat2.br_kolona) || (mat1.br_redova!=mat2.br_redova))
        throw std::domain_error("Nedozvoljena operacija");
        
        GMatrica<Tipic> mat3(mat1.br_redova,mat1.br_kolona, Tipic());
        for(int i(0);i<mat1.br_redova;i++){
            for(int j(0);j<mat1.br_kolona;j++){
                mat3.elementi[i][j]=mat1.elementi[i][j]-mat2.elementi[i][j];
            }
        }
    return mat3;
}

template<typename Tipic>
GMatrica<Tipic> operator +(const GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    
    if((mat1.br_kolona!=mat2.br_kolona) || (mat1.br_redova!=mat2.br_redova))
        throw std::domain_error("Nedozvoljena operacija");
        
        GMatrica<Tipic> mat3(mat1.br_redova,mat1.br_kolona);
        for(int i(0);i<mat1.br_redova;i++){
            for(int j(0);j<mat1.br_kolona;j++){
                mat3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
            }
        }
    return mat3;
}

template<typename Tipic>
GMatrica<Tipic> operator -=(GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    return mat1=mat1-mat2;
}

template<typename Tipic>
GMatrica<Tipic> operator +=(GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    return mat1=mat1+mat2;
}

template<typename Tipic>
GMatrica<Tipic> operator *=(GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    return mat1=mat1*mat2;
}
       

template<typename Tipic>
GMatrica<Tipic> operator *(const GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    
    if(mat1.br_kolona!=mat2.br_redova)
        throw std::domain_error("Nedozvoljena operacija");
        
        GMatrica<Tipic> mat3(mat1.br_redova,mat1.br_kolona);
        for(int i(0);i<mat1.br_redova;i++){
            for(int j(0);j<mat1.br_kolona;j++){
                mat3.elementi[i][j]={};
            }
        }
         for(int i(0);i<mat1.br_redova;i++){
            for(int k(0);k<mat2.br_kolona;k++){
                 for(int j(0);j<mat1.br_kolona;j++){
                    mat3.elementi[i][k]+=(mat1.elementi[i][j]*mat2.elementi[j][k]);
                 }}}
    return mat3;
}

template<typename Tip,typename Tip1>
GMatrica<Tip> operator *(const GMatrica<Tip> &mat1, Tip1 n){
    GMatrica<Tip> mat3(mat1);
        for(int i(0);i<mat3.br_redova;i++){
            for(int j(0);j<mat3.br_kolona;j++){
                mat3.elementi[i][j]*=n;
            }
        }
    return mat3;
}

template<typename Tip,typename Tip1>
GMatrica<Tip> operator *=(GMatrica<Tip> &mat1, Tip1 n){
    return mat1=mat1*n;
}

template<typename Tip,typename Tip1>
GMatrica<Tip1> operator *(Tip n,const GMatrica<Tip1> &mat1){
    GMatrica<Tip> mat3(mat1);
        for(int i(0);i<mat3.br_redova;i++){
            for(int j(0);j<mat3.br_kolona;j++){
                mat3.elementi[i][j]*=n;
            }
        }
    return mat3;
}

template<typename Tip,typename Tip1>
GMatrica<Tip1> operator *=(Tip n,GMatrica<Tip1> &mat1){
    return mat1=n*mat1;
}


template<typename Tipic>
bool operator ==(const GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    if(mat1.br_redova != mat2.br_redova || mat1.br_kolona != mat2.br_kolona)
        return false;
    
    for(int i(0);i<mat1.br_redova;i++){
        for(int j(0);j<mat1.br_kolona;j++){
            if(mat1.elementi[i][j]!=mat2.elementi[i][j])
                return false;
        }
    }
    return true;
}

template<typename Tipic>
bool operator !=(const GMatrica<Tipic> &mat1, const GMatrica<Tipic> &mat2){
    if(!(mat1==mat2)) return true;
return false;
}

 
int main ()
{
   GMatrica<int> m1,m2;
   std::cin >> m1>>m2;
   std::cout << m1 << std::endl;
   std::cout<< m1*m2 << " "<<m1+m2;
	return 0;
}