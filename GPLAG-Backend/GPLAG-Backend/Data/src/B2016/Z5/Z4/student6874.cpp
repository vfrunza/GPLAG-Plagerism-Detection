/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>

template <typename TipEl>
class GMatrica{
    TipEl matrica[4][4];
    int br_redova, br_kolona;
    public:
     GMatrica() : br_redova(0), br_kolona(0){}
     GMatrica(int br_redova, int br_kolona, TipEl inicijalna_vrijednost = TipEl());
     GMatrica(TipEl klasicni_niz[4][4]);
     GMatrica(const std::vector<std::vector<TipEl>> &v);
     GMatrica(std::initializer_list<std::initializer_list<TipEl>> lista);
     template <typename tip2>
      GMatrica<TipEl>(const GMatrica<tip2> &gm);
    int DajBrojRedova() const {return br_redova;}
    int DajBrojKolona() const {return br_kolona;}
    template <typename tip1, typename tip2>
     friend GMatrica<decltype(tip1() + tip2())> operator+ (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2);
    template <typename tip1, typename tip2>
      friend GMatrica<decltype(tip1() + tip2())> operator- (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2);
    template <typename tip1, typename tip2>
     friend GMatrica<decltype(tip1() * tip2())> operator* (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2);
    template <typename tip1, typename tip2>
      friend GMatrica<decltype(tip1() + tip2())> operator* (tip1 broj, const GMatrica<tip2> &m);
    template <typename tip1e, typename tip2e>
      friend GMatrica<decltype(tip1e() + tip2e())> operator* (const GMatrica<tip1e> &m, tip2e broj);
    
    template <typename tip2>
      GMatrica<decltype(TipEl() + tip2())> &operator+=(const GMatrica<tip2> &m);
    template <typename tip2>
      GMatrica<decltype(TipEl() - tip2())> &operator-=(const GMatrica<tip2> &m);
    template <typename tip1, typename tip2>
      friend GMatrica<decltype(tip1() + tip2())> &operator*= (GMatrica<tip1> &m, tip2 broj); 
    template <typename tip1, typename tip2>
      friend GMatrica<decltype(tip1() + tip2())> &operator*= (tip1 broj, GMatrica<tip2> &m);
  
    template <typename tip2>
      GMatrica<decltype(TipEl() + tip2())> &operator*=(const GMatrica<tip2> &m);
    template <typename tip2>
    friend bool operator == (const GMatrica<tip2> &m1, const GMatrica<tip2> &m2);
    template <typename tip2>
    friend bool operator!= (const GMatrica<tip2> &m1, const GMatrica<tip2> &m2);
    TipEl operator() (int red, int kolona) const;
    TipEl &operator() (int red, int kolona);
    TipEl *operator[] (int red) const;
    TipEl *operator[] (int red);
    template <typename tip2>
    friend std::ostream &operator<< (std::ostream &tok, const GMatrica<tip2> &m);
    template <typename tip2>
    friend std::istream &operator>> (std::istream &tok, GMatrica<tip2> &m);
};

template <typename TipEl>
GMatrica<TipEl>::GMatrica(int br_redova, int br_kolona, TipEl inicijalna_vrijednost){
    if(br_redova>4 || br_redova<0 || br_kolona>4 || br_kolona<0)
      throw std::logic_error("Ilegalan format matrice");
    GMatrica<TipEl>::br_redova = br_redova;
    GMatrica<TipEl>::br_kolona = br_kolona;
    for(int i=0; i<br_redova; i++)
     for(int j=0; j<br_kolona; j++)
       matrica[i][j] = inicijalna_vrijednost;
}



/*template <typename TipEl>
template <typename tip2>
GMatrica<TipEl>::GMatrica(const GMatrica<tip2> &gm){
    br_redova = gm.br_redova;
    br_kolona = gm.br_kolona;
    for(int i=0; i<br_redova; i++)
     for(int j=0; j<br_kolona; j++)
       matrica[i][j] = gm.matrica[i][j];
}*/

template <typename tip1>
template <typename tip2>
GMatrica<tip1>::GMatrica(const GMatrica<tip2> &gm){
    br_kolona = gm.DajBrojKolona();
    br_redova = gm.DajBrojRedova();
    for(int i=0; i<br_redova; i++)
      for(int j=0; j<br_kolona; j++)
       matrica[i][j] = gm(i+1, j+1);
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(TipEl klasicni_niz[4][4]){
    br_redova = 4;
    br_kolona = 4;
    for(int i=0; i<4; i++)
     for(int j=0; j<4; j++)
      matrica[i][j] = klasicni_niz[i][j];
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(const std::vector<std::vector<TipEl>> &v){
    if(v.size()>4)
      throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<v.size(); i++)
      if(v[i].size()!=v[0].size() || v[i].size()>4)
        throw std::logic_error("Ilegalan format matrice");
   br_redova = v.size();
   br_kolona = v[0].size();
   for(int i=0; i<br_redova; i++)
     for(int j=0; j<br_kolona; j++)
       matrica[i][j] = v[i][j];
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(std::initializer_list<std::initializer_list<TipEl>> lista){
    if(lista.size()>4)
      throw std::logic_error("Ilegalan format matrice");
     int kol(0);
    for(auto it=lista.begin(); it!=lista.end(); it++){
        if(it->size()!=lista.begin()->size() || it->size()>4)
          throw std::logic_error("Ilegalan format matrice");
          kol = it->size();
    }
    br_redova = lista.size();
    br_kolona = kol;
    int i(0);
   for(auto it=lista.begin(); it!=lista.end(); it++){
       int j(0);
       for(auto it1=it->begin(); it1!=it->end(); it1++){
         matrica[i][j] = *it1;
         j++;
       }
       i++;
   }   
}
template <typename tip1, typename tip2>
GMatrica<decltype(tip1() + tip2())>  operator+ (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
      throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(tip1() + tip2())> m3(m1.br_redova, m1.br_kolona);
    for(int i=0; i<m3.br_redova; i++)
      for(int j=0; j<m3.br_kolona; j++)
        m3.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
    return m3;
}

template <typename tip1, typename tip2>
GMatrica<decltype(tip1() + tip2())> operator- (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
      throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(tip1() + tip2())> m3(m1.br_redova, m1.br_kolona);
    for(int i=0; i<m3.br_redova; i++)
      for(int j=0; j<m3.br_kolona; j++)
        m3.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
    return m3;
}

template <typename tip1, typename tip2>
GMatrica<decltype(tip1()*tip2())> operator* (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2){
    if(m1.br_kolona!=m2.br_redova)
      throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(tip1() * tip2())> m3(m1.br_redova, m2.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m2.br_kolona; j++){
          decltype(tip1() * tip2()) suma(m1.matrica[0][0] - m1.matrica[0][0]);
          for(int k=0; k<m2.br_redova; k++) 
            suma+= m1.matrica[i][k] * m2.matrica[k][j];
          m3.matrica[i][j] = suma;
      }
      return m3;
}

template <typename TipEl>
template <typename tip2>
GMatrica<decltype(TipEl() + tip2())> &GMatrica<TipEl>::operator+=(const GMatrica<tip2> &m){
    if(br_redova!=m.DajBrojRedova() || br_kolona!=m.DajBrojKolona())
      throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<br_redova; i++)
      for(int j=0; j<br_kolona; j++)
        matrica[i][j] += m(i+1, j+1);
    return *this;
}

template <typename TipEl>
template <typename tip2>
GMatrica<decltype(TipEl() - tip2())> &GMatrica<TipEl>::operator-=(const GMatrica<tip2> &m){
    if(br_redova!=m.DajBrojRedova() || br_kolona!=m.DajBrojKolona())
      throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<br_redova; i++){
     for(int j=0; j<br_kolona; j++){
       matrica[i][j] -= m(i+1, j+1);
     }
    }
    return *this;
}

template <typename TipEl>
template <typename tip2>
GMatrica<decltype(TipEl() + tip2())> &GMatrica<TipEl>::operator*=(const GMatrica<tip2> &m2){
    if(br_kolona!=m2.DajBrojRedova())
      throw std::domain_error("Nedozvoljena operacija");
    GMatrica<TipEl> m1(*this);
    br_redova = m1.DajBrojRedova();
    br_kolona = m2.DajBrojKolona();
    for(int i=0; i<m1.DajBrojRedova(); i++){
    for(int j=0; j<m2.DajBrojKolona(); j++){
        decltype(TipEl() * tip2()) suma(m1.matrica[0][0] - m1.matrica[0][0]);
        
        for(int k=0; k<m2.DajBrojRedova(); k++){suma+=(m1(i+1, k+1) * m2(k+1, j+1)); }
        
        matrica[i][j] = suma;
    }
    }
    return *this;
    
}

template <typename TipEl>
bool operator == (const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
     return false;
    for(int i=0; i<m1.br_redova; i++)
     for(int j=0; j<m1.br_kolona; j++)
       if(m1.matrica[i][j]!=m2.matrica[i][j])
         return false;
    return true;
}

template <typename TipEl>
bool operator!= (const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2){
    return !(m1==m2);
}

template <typename TipEl>
TipEl GMatrica<TipEl>::operator() (int red, int kolona) const{
    if(red<1 || red>br_redova || kolona<1 || kolona>br_kolona){
      //std::cout<<red<<" "<<kolona<<std::endl;
      throw std::range_error("Nedozvoljen indeks");
    }
    return matrica[red - 1][kolona - 1];
}

template <typename TipEl>
TipEl &GMatrica<TipEl>::operator() (int red, int kolona){
    if(red<1 || red>br_redova || kolona<1 || kolona>br_kolona)
      throw std::range_error("Nedozvoljen indeks");
    return matrica[red - 1][kolona - 1];
}

template <typename TipEl>
TipEl *GMatrica<TipEl>::operator[] (int red) const{
    return matrica[red];
}
template <typename TipEl>
TipEl *GMatrica<TipEl>::operator[] (int red){
    return matrica[red];
}

template <typename TipEl>
std::ostream &operator<< (std::ostream &tok, const GMatrica<TipEl> &m){
    int sirina(tok.width());
    if(sirina<6)
      sirina = 6;
    for(int i=0; i<m.br_redova; i++){
      for(int j=0; j<m.br_kolona; j++)
        tok<<std::setw(sirina)<<m.matrica[i][j];
    
    tok<<std::endl;    
    }
    return tok;
}

template <typename TipEl>
std::istream &operator>> (std::istream &tok, GMatrica<TipEl> &m){
    char znak;
    tok>>znak;
    if(znak!='[')
      tok.setstate(std::ios::failbit);
    
    m.br_redova = 4; 
    m.br_kolona = 4;
    
    int i(0);
    bool kraj(false);
    while(true){
        char znak1;
        int k = 0;
    
        while(true){
            //std::cout<<"\n i = "<<i<<"\n k = "<<k<<"\n";
            TipEl broj;
            tok>>broj;
            if(!tok){
              //tok.setstate(std::ios::failbit);
              //kraj = true;
              break;
                
            }
           
            m.matrica[i][k] = broj;
           
            k++;
            tok>>znak1;
            
            
            
            if(znak1 != ',' && znak1!=';' && znak1!=']'){
             tok.setstate(std::ios::failbit);
             kraj = true;
             break;
            }
            if((znak1==';') && i==0){
                m.br_kolona = k ;
                break;
            }
            if(znak1==']' && i==0){
                m.br_kolona = k;
                kraj = true;
                break;
            }
            /*if(i!=0 && (znak1==';' || znak1==']')  && k!=m.br_kolona - 1){
                tok.setstate(std::ios::failbit);
            }*/
            if(znak1==';')
              break;
            if(znak1==']'){
             kraj = true;
             break;
            }
            if(k>=4){
                tok.setstate(std::ios::failbit);
                kraj = true;
                break;
                
            }
        }
        i++;
        if(kraj){
            m.br_redova = i ;
            break;
        }
        
        if(i>=4){
            tok.setstate(std::ios::failbit);
            break;
        }
    }
   //std::cout<<"\nbr_redova = "<<m.br_redova<<"\nbr_kolona = "<<m.br_kolona<<"\n";

    
  return tok;    
}

template <typename tip1, typename tip2>
GMatrica<decltype(tip1() + tip2())> operator* (tip1 broj, const GMatrica<tip2> &m){
    GMatrica<decltype(tip1() * tip2())> m2(m.br_redova, m.br_kolona);
    for(int i=0; i<m2.br_redova; i++)
     for(int j=0; j<m2.br_kolona; j++)
       m2.matrica[i][j]= m.matrica[i][j] * broj;
    return m2;
}

template <typename tip1e, typename tip2e>
inline GMatrica<decltype(tip1e() + tip2e())> operator* (const GMatrica<tip1e> &m, tip2e broj){
   GMatrica<decltype(tip1e() + tip2e())> m2(m.br_redova, m.br_kolona);
    for(int i=0; i<m2.br_redova; i++)
      for(int j=0; j<m2.br_kolona; j++)
        m2.matrica[i][j]= m.matrica[i][j] * broj;
    return broj * m;
}

template <typename tip1, typename tip2>
GMatrica<decltype(tip1() + tip2())> &operator*= (GMatrica<tip1> &m, tip2 broj){
    for(int i=0; i<m.br_redova; i++)
    for(int j=0; j<m.br_kolona; j++)
      m.matrica[i][j]*=broj;
    return m;
}

template <typename tip1, typename tip2>
inline GMatrica<decltype(tip1() + tip2())> &operator*= (tip1 broj, GMatrica<tip2> &m){
    return m*=broj;
}


int main ()
{
  try{
   GMatrica<int> m1, m2;
   std::cout<<"Unesi matrice m1 i m2: \n";
   std::cin >> m1>>m2;
   std::cout << m1 << std::endl;
   std::cout<<"\n"<<m2<<std::endl;
   std::cout<<"\n"<<m1 + m2<<std::endl;
   std::cout<< (3*m1)<<std::endl;
   GMatrica<double> m3({{1,2},{3,4}}),m4({{1, 2}, {3, 4}});
   auto m5 = m3-m4;
   std::cout << m5 << std::endl;
   if(m1==m2)
     std::cout<<"Matrice m1 i m2 su jednake."<<std::endl;
   std::cout<<m4[1][1]<<std::endl;
   std::cout<<m3(1,1)<<std::endl;
   m5+=m3;
   m5*=10;
   std::cout<<m5<<std::endl;
   GMatrica<double> m6(2,2, 0.8);
   std::cout<<m6<<std::endl;
   GMatrica<double> m7(m1);
   std::cout<<m7<<std::endl;
   m7+=m1;
   std::cout<<m7<<std::endl;
   m7-=m1;
   std::cout<<m7<<std::endl;
   std::cout<<m1[0][0] + m2[0][0]<<std::endl;
   GMatrica<int> m8(2,3,1), m9(3,2,2);
   m8*=m9;
   std::cout<<m8<<std::endl;
   GMatrica<int> m10({{1, 2}, {3, 4}});
   std::cout<<m10<<std::endl;
   GMatrica<int> m11{{1,2}, {3,4}};
   std::cout<<m11<<std::endl;
  }
  catch(std::range_error e){
      std::cout<<"Izuzetak: "<<e.what();
  }
  catch(std::logic_error e){
      std::cout<<"Izuzetak: "<<e.what();
  }
   return 0;
}