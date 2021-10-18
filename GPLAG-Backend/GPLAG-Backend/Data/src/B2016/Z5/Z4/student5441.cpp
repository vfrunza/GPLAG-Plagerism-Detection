/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>

template<typename Tip>
class GMatrica{
    Tip matrica[4][4];
    int br_redova, br_kolona;
    public:
    GMatrica(): br_redova(0), br_kolona(0) {}
   
    GMatrica<Tip>(int br_r, int br_k, const Tip vrijednost=Tip());
    template<typename Tip2>
    GMatrica(const GMatrica<Tip2> m2);
    template<typename Tip3>
    GMatrica(Tip3 mat[4][4]);
    GMatrica(std::vector<std::vector<Tip>> v);
    GMatrica(const std::initializer_list<std::initializer_list<Tip>>& lista);
    int DajBrojRedova()  { return br_redova; }
    int DajBrojKolona()  { return br_kolona; }
    template<typename Tip2>
    friend GMatrica<Tip2> operator +(GMatrica<Tip2>& m, GMatrica<Tip2>& m2);
    template<typename Tip2>
    GMatrica<Tip> operator +=(GMatrica<Tip>& m, GMatrica<Tip>& m2)
    template<typename Tip2>
    friend GMatrica<Tip2> operator -(GMatrica<Tip2>& m, GMatrica<Tip2>& m2);
    template<typename Tip2>
    friend GMatrica<Tip2> operator *(GMatrica<Tip2>& m, GMatrica<Tip2>& m2);
    template<typename Tip2>
    friend std::ostream& operator <<(std::ostream& tok, const GMatrica<Tip2>& m);
    template<typename Tip2>
    friend GMatrica<Tip2> operator *(Tip2 broj, GMatrica<Tip2>& m);
    template<typename Tip2>
    friend GMatrica<Tip2> operator *(GMatrica<Tip2>& m, Tip2 broj);

    void Ispisi(){
        for(int i=0; i<br_redova; i++)
        {for(int j=0; j<br_kolona; j++)
            std::cout<<matrica[i][j]<<"  ";
            std::cout<<std::endl; }
    }
   
};
template<typename Tip>

GMatrica<Tip>::GMatrica(int br_r, int br_k, const Tip vrijednost) {
        if(br_r>4 || br_r<0 || br_k>4 || br_k<0) throw std::logic_error("Ilegalan format matrice");
        for(int i=0; i<br_r; i++)
            for(int j=0; j<br_k; j++)
                matrica[i][j]=vrijednost;
                
    }
template<typename Tip>
template<typename Tip2>
GMatrica<Tip>::GMatrica(const GMatrica<Tip2> m2){
        br_kolona=m2.DajBrojKolona(); br_redova=m2.DajBrojRedova();
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                matrica[i][j]=m2[i][j];
    }
template<typename Tip>
template<typename Tip3>
GMatrica<Tip>::GMatrica(Tip3 mat[4][4]): br_redova(4), br_kolona(4) {
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                matrica[i][j]=mat[i][j];
    }
template<typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> v){
        for(int i=0; i<v.size(); i++)
            if(v[i].size()!=v[0].size() || v[i].size()>4 || v.size()>4) throw std::logic_error("Ilegalan format matrice");
        br_redova=v.size(); br_kolona=v[0].size();
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                matrica[i][j]=v[i][j];
        
    }
template<typename Tip>   
GMatrica<Tip>::GMatrica(const std::initializer_list<std::initializer_list<Tip>>& lista){
        for(auto it=lista.begin(); it!= lista.end(); it++)
        if((*it).size()>4 || (*it).size()!=(*lista.begin()).size() || lista.size()>4) throw std::logic_error("Ilegalan format matrice");
        br_redova=lista.size(); br_kolona=(*lista.begin()).size();
        int red(0);
        for(const auto&l : lista){
            int kolona(0);
            for(const auto e : l) {
                matrica[red][kolona++]=e;
            }
            red++;
        }
    }
template<typename Tip>
GMatrica<Tip> operator +(GMatrica<Tip>& m, GMatrica<Tip>& m2){
        if(m.DajBrojKolona()!=m2.DajBrojKolona() || m.DajBrojRedova()!=m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
        GMatrica<Tip> mkopija(m);
        for(int i=0; i<m.DajBrojRedova(); i++)
            for(int j=0; j<m.DajBrojKolona(); j++)
            mkopija.matrica[i][j]+=m2.matrica[i][j];
            return mkopija;
    }
template<typename Tip>
GMatrica<Tip> operator +=(GMatrica<Tip>& m, GMatrica<Tip>& m2){
        if(m.DajBrojKolona()!=m2.DajBrojKolona() || m.DajBrojRedova()!=m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
       
        for(int i=0; i<m.DajBrojRedova(); i++)
            for(int j=0; j<m.DajBrojKolona(); j++)
            m.matrica[i][j]+=m2.matrica[i][j];
            return m;
    }
template<typename Tip>
GMatrica<Tip> operator -(GMatrica<Tip>& m, GMatrica<Tip>& m2){
        if(m.DajBrojKolona()!=m2.DajBrojKolona() || m.DajBrojRedova()!=m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
        GMatrica<Tip> mkopija(m);
        for(int i=0; i<m.DajBrojRedova(); i++)
            for(int j=0; j<m.DajBrojKolona(); j++)
            mkopija.matrica[i][j]-=m2.matrica[i][j];
            return mkopija;
    }
template<typename Tip>
GMatrica<Tip> operator *(GMatrica<Tip>& m, GMatrica<Tip>& m2){
    if(m.br_kolona!=m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> rez;
    rez.br_redova=m.br_redova; rez.br_kolona=m2.br_kolona;
    for(int i=0; i<rez.br_redova; i++)
        for(int j=0; j<rez.br_kolona; j++)
            rez.matrica[i][j]=0;
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m.br_kolona; k++)
            rez.matrica[i][j]+=m.matrica[i][k]*m2.matrica[k][j];
    return rez;
}
template<typename Tip>
GMatrica<Tip> operator *(Tip broj, GMatrica<Tip>& m){
    GMatrica<Tip>mkopija(m);
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            mkopija.matrica[i][j]*=broj;
        return mkopija;
}
template<typename Tip>
GMatrica<Tip> operator *(GMatrica<Tip>& m, Tip broj){
    GMatrica<Tip>mkopija(m);
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            mkopija.matrica[i][j]*=broj;
        return mkopija;
}
template<typename Tip>
std::ostream& operator <<(std::ostream& tok, const GMatrica<Tip>& m){
     for(int i=0; i<m.br_redova; i++)
        {
            for(int j=0; j<m.br_kolona; j++)
            tok<<std::setw(6)<<m.matrica[i][j];
            tok<<std::endl; 
        }
        return tok;
}



int main ()
{
    GMatrica<int> m1({{1, 2}, {3, 4}});
   GMatrica<int> m2 = m1 * 2;
   GMatrica<int> m3 = 2 * m1;  
   std::cout <<  m2 << std::endl;
   std::cout << m3 << std::endl;
    
   
    
	return 0;
}