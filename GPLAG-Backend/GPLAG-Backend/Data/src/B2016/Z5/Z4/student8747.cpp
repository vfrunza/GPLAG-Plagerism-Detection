/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>

    template<typename Tip>
class GMatrica{
    int broj_redova, broj_kolona;
    Tip mat[4][4];
    public:
    GMatrica(){ broj_kolona=0; broj_redova=0; }
    GMatrica(int red, int kolona, Tip el=Tip());
    template<typename Tip1,typename Tip2>
    GMatrica<Tip1>(const GMatrica<Tip2> &m);
    template<typename Tip1,typename Tip2>
    GMatrica<Tip1>(Tip2 m[4][4]);
    GMatrica(const std::vector<std::vector<Tip>> &v);
    GMatrica(std::initializer_list<Tip> lista);
    int DajBrojRedova()const{ return broj_redova;}
    int DajBrojKolona()const{ return broj_kolona;}
    template<typename Tip1,typename Tip2>
    GMatrica<Tip1> &operator +=(const GMatrica<Tip2> &a);
    template <typename Tip1,typename Tip2, typename Tip3>
    friend GMatrica<Tip1> operator +(const GMatrica<Tip2> &a, const GMatrica<Tip3> &b);
};

    template<typename Tip1>
GMatrica<auto> &GMatrica::operator +=(const GMatrica<Tip1> &a)->decltype(a[0][0]+this[0][0]){
    
}

    template <typename Tip1,typename Tip2, typename Tip3>
GMatrica<Tip1> operator +(const GMatrica<Tip2> &a, const GMatrica<Tip3> &b){
    
}
  template <typename Tip1>
GMatrica<Tip1>::GMatrica(int red, int kolona, Tip1 el ){
    if(red>4 || red<0 || kolona>4 || kolona<0) throw std::logic_error("Ilegalan format matrice");
    broj_redova=red; broj_kolona=kolona;
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++){
            mat[i][j]=el;
        }
    }
}
   /* template <typename Tip1,typename Tip2>
GMatrica<Tip1>::GMatrica(const GMatrica<Tip2> &m){
    broj_redova=m.broj_redova; broj_kolona=m.broj_kolona;
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++) mat[i][j]=m.mat[i][j];
    }
}
   template <typename Tip1,typename Tip2>
GMatrica<Tip1>::GMatrica(Tip2 m[4][4]){
    broj_redova=4; broj_kolona=4;
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++) mat[i][j]=m[i][j];
    }
}*/
    template<typename Tip>
GMatrica<Tip>::GMatrica(const std::vector<std::vector<Tip>> &v){
    if(v.size()<0 || v.size()>4) throw std::logic_error("Ilegalan format matrice");
    if(v.size()>0){
        int c=v[0].size();
        if(c>4 || c<0)  throw std::logic_error("Ilegalan format matrice");
        for(int i=1;i<v.size();i++){
            if(v[i].size()!=c) throw std::logic_error("Ilegalan format matrice");
        }
    }
    broj_redova=v.size();
    if(v.size()>0) broj_kolona=v[0].size();
    else broj_kolona=0;
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++){
            mat[i][j]=v[i][j];
        }
    }
}
    template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<Tip>lista){
    if(lista.size()<0 || lista.size()>4) throw std::logic_error("Ilegalan format matrice");
    if(lista.size()>0){
        auto it=lista.begin();
        int c= it->size();
        if(c<0 || c>4)  throw std::logic_error("Ilegalan format matrice");
        for(auto i=lista.begin();i!=lista.end();i++){
            if(c!=i->size())  throw std::logic_error("Ilegalan format matrice");
        }
    }
    broj_redova=lista.size();
    if(broj_redova>0) broj_kolona=lista.begin()->size();
    else broj_kolona=0;
    for(int i=0;i<broj_redova;i++){
        auto s=lista.begin();
        for(int j=0;j<broj_kolona;j++){
            auto si=s.begin();
            mat[i][j]=*si;
            si++;
        }
        s++;
    }
}

int main (){
    
	return 0;
}