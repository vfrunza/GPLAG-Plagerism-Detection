/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <algorithm>

template<typename Tip>
class GMatrica{
    
    Tip niz[4][4];
    int broj_redova, broj_kolona;
    void popuniMatricu(Tip n){
        for(int i = 0; i < broj_redova; i++){
            for(int j = 0; j < broj_kolona; j++){
                niz[i][j]= n;
            }
        }
    }
    Tip vrati_defaultnu(){
        return Tip();
    }
public:
    GMatrica();
    GMatrica(int br_r, int br_k, const Tip inic_vrijednost= {});
    template<typename Tip2>
    GMatrica(const GMatrica<Tip2> &g);
    GMatrica(std::vector<std::vector<Tip>> vektor);
    GMatrica(Tip **niz);
    GMatrica(std::initializer_list<Tip> lista);
    int DajBrojRedova(){
        return broj_redova;
    }
    int DajBrojKolona(){
        return broj_kolona;
    }
    template<typename Tip2>
    friend auto operator +(const GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) ->GMatrica<decltype(g1.niz[0][0]+g2.niz[0][0])>;
    
    template<typename Tip2>
    friend auto operator -(const GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) ->GMatrica<decltype(g1.niz[0][0]+g2.niz[0][0])>;
    
    template<typename Tip2>
    friend auto operator *(const GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) ->GMatrica<decltype(g1.niz[0][0]*g2.niz[0][0])>;
    
    template<typename Tip2>
    friend auto operator *(const GMatrica<Tip> &g1, const Tip2 broj)->GMatrica<decltype(g1.niz[0][0]*broj)>;
    
    template<typename Tip2>
    friend auto operator *(const Tip2 broj, const GMatrica<Tip> &g1)->GMatrica<decltype(g1.niz[0][0]*broj)>;
    
    template<typename Tip2>
    friend GMatrica<Tip> &operator +=(GMatrica<Tip> &g1, const GMatrica<Tip2> &g2);
    
    template<typename Tip2>
    friend GMatrica<Tip> &operator -=(GMatrica<Tip> &g1, const GMatrica<Tip2> &g2);
    
    template<typename Tip2>
    friend GMatrica<Tip> &operator *=(GMatrica<Tip> &g1, const GMatrica<Tip2> &g2);
    
    template<typename Tip2>
    friend bool operator ==(GMatrica<Tip> &g1, const GMatrica<Tip2> &g2){
        if(g1.broj_kolona != g2.broj_kolona || g1.broj_redova != g2. broj_redova) return false;
        for(int i = 0; i < g1.broj_redova; i++)
            for(int j = 0; j < g2.broj_kolona; j++)
                if(g1.niz[i][j] != g2.niz[i][j]) return false;
        return true;
    }
    
    template<typename Tip2>
    friend bool operator !=(GMatrica<Tip> &g1, const GMatrica<Tip2> &g2){
        return !(g1==g2);
    }
    
    /*friend &operator ()(const GMatrica<Tip> &g1, int m, int n){
        if(m>g1.broj_redova+1 || n>g1.broj_kolona+1) throw std::range_error("Nedozvoljen indeks");
        
        return g1.niz[m-1][n-1];
    }*/
    
};


template<typename Tip>
GMatrica<Tip>::GMatrica(){
         broj_kolona = 0;
        broj_redova = 0;
}

template<typename Tip>
GMatrica<Tip>::GMatrica(int br_r, int br_k,const Tip inic_vrijednost){
        if(br_r > 4 || br_r < 0 || br_k < 0 || br_k >4) throw std::logic_error("Ilegalan fromat matrice");
        broj_kolona = br_k;
        broj_redova = br_r;
        popuniMatricu(inic_vrijednost);
    
}

template<typename Tip>
template<typename Tip2>
GMatrica<Tip>::GMatrica(const GMatrica<Tip2> &g){
    broj_kolona = g.broj_kolona;
    broj_redova = g.broj_redova;
    for(int i=0;i<broj_redova; i++){
        for(int j =0; j < broj_kolona; j++)
            niz[i][j] = g.niz[i][j];
            
    }
}

template<typename Tip>
GMatrica<Tip>::GMatrica(Tip** nizp){
    broj_kolona = 4;
    broj_redova = 4;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            niz[i][j] = nizp[i][j];
}

template<typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> vektor){
     if(vektor.size() >4 || vektor[0].size() > 4 || vektor.size() <0 || vektor[0].size() <0)
        throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < vektor.size() ; i++ ) if(vektor[i].size()!= vektor[0].size()) throw std::logic_error("Ilegalan format matrice");
    
    broj_redova = vektor.size();
    broj_kolona = vektor[0].size();
    for(int i = 0; i< vektor.size(); i++){
        for(int j = 0; i < vektor[i].size(); j++){
            niz[i][j] = vektor[i][j];
        }
    }
}

template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<Tip> lista){
    std::copy(lista.begin(), lista.end(), niz);
}

template<typename Tip2, typename Tip>
auto operator +(const GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) ->GMatrica<decltype(g1.niz[0][0]+g2.niz[0][0])>{
    if(g1.broj_kolona != g2.broj_kolona || g1.broj_redova != g2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(g1.niz[0][0]+g2.niz[0][0])> g(g1.broj_redova, g1.broj_kolona);
    for(int i = 0; i < g1.broj_redova; i++)
        for(int j = 0; j < g1.broj_kolona; j++)
            g.niz[i][j] = g1.niz[i][j] + g2.niz[i][j];
    
    return g;
}
    
template<typename Tip2, typename Tip>
auto operator -(const GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) ->GMatrica<decltype(g1.niz[0][0]+g2.niz[0][0])>{
    if(g1.broj_kolona != g2.broj_kolona || g1.broj_redova != g2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(g1.niz[0][0]+g2.niz[0][0])> g(g1.broj_redova, g1.broj_kolona);
    for(int i = 0; i < g1.broj_redova; i++)
        for(int j = 0; j < g1.broj_kolona; j++)
            g.niz[i][j] = g1.niz[i][j] - g2.niz[i][j];
    
    return g;
}
    
template<typename Tip2, typename Tip>
auto operator *(const GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) ->GMatrica<decltype(g1.niz[0][0]*g2.niz[0][0])>{
    if(g1.broj_kolona  != g2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(g1.niz[0][0]+g2.niz[0][0])> g(g1.broj_redova, g1.broj_kolona);
    for(int i = 0; i < g1.broj_redova; i++)
        for(int j = 0; j < g2.broj_kolona; j++)
            for (int k = 0; k < g1.broj_kolona; k++){
                g.niz[i][j] += g1.niz[i][k]*g2.niz[k][j];
            }
            
    
    return g;
}
    
template<typename Tip2, typename Tip>
auto operator *(const GMatrica<Tip> &g1, const Tip2 broj)->GMatrica<decltype(g1.niz[0][0]*broj)>{
    GMatrica<decltype(g1.niz[0][0]*broj)> g(g1);
    for(int i = 0; i < g.broj_redova; i++)
        for(int j=0; j < g.broj_kolona; j++)
            g.niz[i][j] = g1.niz[i][j]*broj;
            
    return g;
}
    
template<typename Tip2, typename Tip>
auto operator *(const Tip2 broj, const GMatrica<Tip> &g1)->GMatrica<decltype(g1.niz[0][0]*broj)>{
     GMatrica<decltype(g1.niz[0][0]*broj)> g(g1);
    for(int i = 0; i < g.broj_redova; i++)
        for(int j=0; j < g.broj_kolona; j++)
            g.niz[i][j] = g1.niz[i][j]*broj;
            
    return g;
}

template<typename Tip, typename Tip2>
GMatrica<Tip> &operator +=(GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) {
    if(g1.broj_kolona != g2.broj_kolona || g1.broj_redova != g2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    
    for(int i = 0; i < g1.broj_redova; i++)
        for(int j = 0; j < g1.broj_kolona; j++)
            g1.niz[i][j] +=g2.niz[i][j];
    return g1;
}

template<typename Tip, typename Tip2>
GMatrica<Tip> &operator -=(GMatrica<Tip> &g1, const GMatrica<Tip2> &g2) {
    if(g1.broj_kolona != g2.broj_kolona || g1.broj_redova != g2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    
    for(int i = 0; i< g1.broj_redova; i++)
        for(int j = 0; j < g1.broj_kolona; j++)
            g1.niz[i][j] -=g2.niz[i][j];
}


int main ()
{
    GMatrica<double> m1({{1, 2}, {3, 4}});
   GMatrica<double> m2({{1, 2}, {3, 4}});
   auto m3 = m1 + m2;
   std::cout << m3 << std::endl;
   GMatrica<double> m4({{1, 2}, {3, 4}});
   auto m5 = m3-m4;
   std::cout << m5 << std::endl;
	return 0;
}