#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <utility>
#include <iomanip>




template <typename tip> class GMatrica{
  
    
  
    int realrou,realkol;
    tip elementi[4][4];
    public:
    GMatrica();
    GMatrica(int br_redova,int br_kolona,tip vrednost=0);
     /*    GMatrica(const GMatrica <int> &matrica);*/
     GMatrica(const std::vector<std::vector<tip>> &v);
     GMatrica (const std::initializer_list<std::initializer_list<tip>>  &lista);
     void Ispisi () const; 
     tip DajBrojRedova () const { return realrou;}
     tip DajBrojKolona () const { return realkol;}
    /* template <typename tip>  friend auto  operator + (const GMatrica<tip> &m1,const GMatrica<tip> &m2)->decltype(m1.elementi[0][0]+m2.elementi[0][0]) ;*/
     /*template <typename tip> friend GMatrica<tip> operator -(const GMatrica<tip> &m1,const GMatrica<tip> &m2);*/
     
template<typename T1, typename T2> friend auto operator+(const GMatrica<T1>  &a, const GMatrica <T2> &b) -> GMatrica <decltype(T1{} + T2{})> ;
template<typename T1, typename T2> friend auto operator-(const GMatrica<T1>  &a, const GMatrica <T2> &b) -> GMatrica <decltype(T1{} + T2{})> ;
template<typename T1, typename T2> friend auto operator*(const GMatrica<T1>  &a, const GMatrica <T2> &b) -> GMatrica <decltype(T1{} + T2{})> ;
template<typename T1, typename T2> friend auto operator*(const GMatrica<T1>  &a,  T2 b) -> GMatrica <decltype(T1{} + T2{})> ;
template<typename T1, typename T2> friend auto operator*(T2 b,const GMatrica<T1>  &a  ) -> GMatrica <decltype(T1{} + T2{})> ;
template <typename T1>  friend std::ostream &operator <<  (std::ostream &tok, const GMatrica<T1> &a); 
template <typename T1>  friend std::istream &operator >>  (std::istream &tok,  GMatrica<T1> &a); 
 GMatrica &operator +=(const GMatrica<tip>  &a);
 GMatrica &operator -=(const GMatrica<tip>  &a);
 GMatrica &operator *=(tip b);
 GMatrica &operator *=(const GMatrica<tip>  &a);
 tip &operator () (int indeks1,int indeks2){
    if(indeks1<1 || indeks2<1 ) throw std::range_error("Nedozvoljen indeks");
    return elementi[indeks1-1][indeks2-1];
}


tip operator () (int indeks1,int indeks2) const {
    if(indeks1<1 || indeks2<1 ) throw std::range_error("Neispravan indeks");
    return elementi[indeks1-1][indeks2-1];
}


tip* operator [] (int indeks1)   {/*ovaj ne diraj emire */
    if(indeks1<1 ) throw std::range_error("Neispravan indeks");
    return elementi[indeks1];
}

/*tip &operator [](int kolona,int red){ /*ovaj popravi 
     if(indeks1<1 || indeks2<1 ) throw std::range_error("Nedozvoljen indeks");
     return elementi[red][kolona];
    
}*/


 template <typename z> friend bool operator ==(const GMatrica<z>  &a, const GMatrica <z> &b);
 template <typename z> friend bool operator !=(const GMatrica<z>  &a, const GMatrica <z> &b);
 
 




     


     


    
};



template<typename tip>GMatrica<tip>::GMatrica(const std::initializer_list<std::initializer_list<tip>> &lista){
         std::vector<std::vector<tip>> vrednosti;
        vrednosti.reserve(lista.size());
        for (auto const& red : lista)
        {
            vrednosti.emplace_back(std::begin(red), std::end(red));
        }
        int brojredova=lista.size();
         int granica(0);
        for(int i=0;i<brojredova-1;i++){
            if(vrednosti[i].size()==vrednosti[i+1].size()){granica++;}
        }
        if((brojredova<0 || brojredova>4 ) && granica>4) throw std::logic_error("Ilegalan format matrice");
           realrou=vrednosti.size();
           realkol=vrednosti[0].size();
        for(int i=0;i<vrednosti.size();i++){
            for(int j=0;j<vrednosti[i].size();j++){
                elementi[i][j]=vrednosti[i][j];
            }
        }
}
     
      
   template<typename tip> void GMatrica<tip>::Ispisi() const {
        for(int i=0;i<realrou;i++){
            for(int j=0;j<realkol;j++){
                std::cout<<elementi[i][j]<<"   ";
            }
            std::cout<<std::endl;
        }
    }

 /*template<typename tip> GMatrica<tip>::GMatrica ( const GMatrica <int> &matrica) {
     realkol=matrica.realkol; realrou=matrica.realrou;
        for(int i=0;i<matrica.realrou;i++){
            for(int j=0;j<matrica.realkol;j++){
                elementi[i][j]=(int)matrica.elementi[i][j];
            }
        }
    }*/
    
template<typename tip>GMatrica<tip>::GMatrica(const std::vector<std::vector<tip>> &v){
        int brojredova=v.size();
        int granica(0);
        for(int i=0;i<brojredova-1;i++){
            if(v[i].size()==v[i+1].size()){granica++;}
        }
        if((brojredova<0 || brojredova>4 ) && granica>4) throw std::logic_error("Ilegalan format matrice");
        else{
        realkol=v[0].size();
        realrou=v.size();
        for(int i=0;i<realrou;i++){
            for(int j=0;j<realkol;j++){
                elementi[i][j]=v[i][j];
            }
        }
        }
}


 template<typename tip>GMatrica<tip>::GMatrica(int br_redova,int br_kolona,tip  vrednost){
  if(br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4) throw std::logic_error("Ilegalan format matrice");
  else{
    realkol=br_kolona;
    realrou=br_redova;
  }
    for(int i=0;i<realrou;i++){
        for(int j=0;j<realkol;j++){
            elementi[i][j]=vrednost;
        }
    }
    
   
}

template<typename tip> GMatrica<tip>::GMatrica(){
    realkol=0; realrou=0;
    elementi[0][0]={};
}
 

template<typename T1, typename T2> auto operator+(const GMatrica<T1>  &a, const GMatrica <T2> &b) -> GMatrica <decltype(T1{} + T2{})>{
    if(a.realrou != b.realrou || a.realkol != b.realkol) throw std::domain_error("Nedozvoljena operacija"); 
    using value_type = decltype(T1{} + T2{});
    GMatrica <decltype(T1{} * T2{})> result(a.realrou,a.realkol);
    for (int i = 0; i< a.realrou; i++){
        for (int j = 0; j< a.realkol; j++){
          result.elementi[i][j] = a.elementi[i][j] + b.elementi[i][j]; 
        }
    }
    return result;
}

    
template<typename T1, typename T2> auto operator-(const GMatrica<T1>  &a, const GMatrica <T2> &b) -> GMatrica <decltype(T1{} + T2{})>{
    if(a.realrou != b.realrou || a.realkol != b.realkol) throw std::domain_error("Nedozvoljena operacija"); 
    using value_type = decltype(T1{} + T2{});
    GMatrica <decltype(T1{} * T2{})> result(a.realrou,a.realkol);
    for (int i = 0; i< a.realrou; i++){
        for (int j = 0; j< a.realkol; j++){
          result.elementi[i][j] = a.elementi[i][j] - b.elementi[i][j]; 
        }
    }
    return result;
}

template<typename T1, typename T2> auto operator*(const GMatrica<T1>  &a, const GMatrica <T2> &b) -> GMatrica <decltype(T1{} + T2{})>{
     if (a.realrou != b.realkol) throw std::domain_error("Nedozvoljena operacija"); 
    using value_type = decltype(T1{} + T2{});
    GMatrica<decltype(T1{} * T2{})> nova(a.realrou, b.realkol);
    for (int i = 0; i< a.realrou; i++)
        for (int j = 0; j< b.realkol; j++)
        {
            value_type sum = 0;
            for (int k = 0; k< b.realkol; k++)    sum += a.elementi[i][k] * b.elementi[k][j];
            nova.elementi[i][j] = sum;
        }
    return nova;
}

template<typename T1, typename T2> auto operator*(const GMatrica<T1>  &a, T2  b) -> GMatrica <decltype(T1{} + T2{})>{
    using value_type = decltype(T1{} + T2{});
    GMatrica<decltype(T1{} * T2{})> nova(a.realrou, a.realkol);
    for (int i = 0; i< a.realrou; i++){
        for (int j = 0; j< a.realkol; j++){
            nova.elementi[i][j]=b*a.elementi[i][j];
        }
    }
    return nova;
}

template<typename T1, typename T2> auto operator*(T2  b,const GMatrica<T1>  &a ) -> GMatrica <decltype(T1{} + T2{})>{
    using value_type = decltype(T1{} + T2{});
    GMatrica<decltype(T1{} * T2{})> nova(a.realrou, a.realkol);
    for (int i = 0; i< a.realrou; i++){
        for (int j = 0; j< a.realkol; j++){
            nova.elementi[i][j]=b*a.elementi[i][j];
        }
    }
    return nova;
}

template <typename TipEl>    std::ostream  &operator  << (std::ostream &tok,const GMatrica<TipEl> &m){
     int sirina=tok.width();
     if(sirina<6) sirina=6;
      for(int i = 0; i < m.realrou; i++) {   
          for(int j = 0; j < m.realkol; j++)  
            tok  <<std::setw(sirina)<< m.elementi[i][j];  
          tok<<std::endl;
      }
          return tok;
 }

  template<typename t>GMatrica<t>  &GMatrica<t>::operator +=(const GMatrica<t> &m){
      for(int i=0;i<m.realrou;i++){
          for(int j=0;j<m.realkol;j++){
              elementi[i][j]+=m.elementi[i][j];
          }
      }
      return *this;
  }
  
  template<typename t>GMatrica<t>  &GMatrica<t>::operator -=(const GMatrica<t> &m){
      for(int i=0;i<m.realrou;i++){
          for(int j=0;j<m.realkol;j++){
              elementi[i][j]-=m.elementi[i][j];
          }
      }
      return *this;
  }
  
  template<typename t>GMatrica<t> &GMatrica<t>::operator*=(t b){
    for (int i = 0; i< realrou; i++){
        for (int j = 0; j< realkol; j++){
            elementi[i][j]*=b;
        }
    }
    return *this;
}

template<typename t>GMatrica<t>  &GMatrica<t>::operator *=(const GMatrica<t> &m){
    GMatrica nova=(*this)*m;
    (*this)=nova;
      return *this;
  }
  
 
/*template<typename T> T& GMatrica<T>::operator()(int row, int col) {
  return [row-1][col-1];
}*/
template<typename pit> bool operator ==(const GMatrica<pit> &a,const GMatrica<pit> &b){
    int br(0);
    for(int i=0;i<a.realrou;i++){
        for(int j=0;j<a.realkol;j++){
            if(a.elementi[i][j]==b.elementi[i][j]) br++;
        }
    }
    if(br==(a.realrou*a.realkol)) return true;
    return false;
}

template<typename pita> bool operator !=(const GMatrica<pita> &a,const GMatrica<pita> &b){
    int br(0);
    for(int i=0;i<a.realrou;i++){
        for(int j=0;j<a.realkol;j++){
            if(a.elementi[i][j]==b.elementi[i][j]) br++;
        }
    }
    if(br!=(a.realrou*a.realkol)) return true;
    return false;
}

template <typename TipEl>    std::istream  &operator  >> (std::istream &tok, GMatrica<TipEl> &m){
    char znak;
int i=0;
    tok>>std::ws;
int broj(0),g(0);
   tok>>znak;
    if(znak!='[') tok.setstate(std::ios::failbit);
   for(int j=0;j<1000;j++){
       a:
    tok>>m.elementi[i][j]>>znak;
    if(znak==','){g++;}
    if(znak==';'){ i++; broj++;  j=0; goto a; }
     if(znak==']') break;
   }
    
   int t=g/(broj+1)+1;
   m.realkol=t; m.realrou=broj+1;
   return tok;
 }



int main (){
    try{
 GMatrica<int>a;
 std::cin>>a;
 std::cout<<a;
    }
    catch(std::logic_error e){
        std::cout<<e.what();
    }
	return 0;
}