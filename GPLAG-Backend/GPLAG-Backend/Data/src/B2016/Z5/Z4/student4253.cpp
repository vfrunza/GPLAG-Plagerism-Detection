/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <type_traits>

template<typename Tip>
    class GMatrica{
        Tip mat[4][4];
        int br_redova, br_kolona;
        
        public:
        GMatrica(): br_redova(0), br_kolona(0){};
        GMatrica(int br_redova, int br_kolona, Tip vrijednost=Tip {});
        template <typename Tip1, template Tip2>
        GMatrica<Tip1> (Gmatrica<Tip2> *g);
        GMatrica(Tip **cniz);
        GMatrica(std::vector<std::vector<Tip>> v);
        GMatrica(std::initializer_list<std::initalizer_list<Tip>> lista);
        
        int DajBrojRedova(){return br_redova;}
        int DajBrojKolona(){return br_kolona;}
        
        template <typename Tip1, typename Tip2>
        friend auto operator +(const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2) std::remove_reference<decltype(GMatrcia(1,1,g1[0][0]+g2[0][0]))>::type;
        
        template <typename Tip1, typename Tip2>
        friend auto operator -(const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2) std::remove_reference<decltype(GMatrica(1,1,g1[0][0]-g2[0][0]))>::type;
        
        template <typename Tip1, typename Tip2>
        friend auto operator *(const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2) std::remove_reference<decltype(GMatrica(1,1,g1[0][0]*g2[0][0]))>::type;
        
        template <typename Tip1, typename Tip2>
        friend auto operator *(Tip1 varijabla, const GMatrica<Tip2> &g) std::remove_reference<decltype(GMatrica(1,1,g1[0][0]*varijabla))>::type;
        
        template <typename Tip1, typename Tip2>
        friend auto operator *(const GMatrica<Tip2> &g, Tip1 varijabla) std::remove_reference<decltype(GMatrica(1,1,g[0][0]*varijavla))>type;
        
        
        
        GMatrica<Tip> &(int i, int j);
        
        
    };
    
    
template<typename Tip>
    GMatrica<Tip>::GMatrica(int br_redova, int br_kolona, Tip vrijednost=Tip{}): br_redova(br_redova), br_kolona(br_kolona){
        if(br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4) throw std::logic_error("Ilegalan format matrice");
        for(int i(0); i<br_redova; i++){
            for(int j(0); j<br_redova; j++){
                niz[i][j]=vrijednost;
            }
        }
    }
    
template<typename Tip>
    GMatrica<Tip>::GMatrica(Tip **cniz){
        for(int i(0); i<4; i++){
            for(int j(0); j<4; j++){
                niz[i][j]=cniz[i][j];
            }
        }
        br_redova=4; br_kolona=4;
    }
    
template<typename Tip>
     GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip> v){
         if(int(v.size())>4) throw std::logic_error("Ilegalan format matrice");
         if(int(v.size())!=0){
             int vk(int(v.at(0).size()));
             if(vk>4) throw std::logic_error("Ilegalan format matrice");
             for(int i(1); i<int(v.size()); i++){
                 if(int(v.at(i).size())!=vk) throw std::logic_error("Ilegalan format matrice");
             }
             br_kolona=vk;
         }
         for(int i(0); i<int(v.size(0)); i++){
             for(int j(0); j<int(v..at(i).size()); j++ ){
                 niz[i][j]=v.at(i).at(j);
             }
         }
         br_redova=int(v.size()); 
         if(br_redova==0) br_kolona=0;
     }

template<typename Tip>
    GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista){
        if(int(lista.size())>4) throw std::domain_error("Ilegalan format matrice");
        if(int(lista.size())!=0){
            auto kolona(lista.begin());
            int lk(int((*kolona).size()));
            if(lk>4) throw std::domain_error("Ilegalan format matrice");
            while(kolona!=lista.end()){
                if(int((*kolona).size())!=lk) throw std::domain_error("Ilegalan format matrice");
                kolona++;
            }
            br_kolona=lk;
        }
        auto trenutnir(lista.begin());
        int i(0);
        while(trenutnir!=lista.end()){
            auto trenutnak(trenutnir->begin());
            int j(0);
            while(trenutnak!=trenutnir->end()){
                niz[i][j]=*trenutnak;
                j++; trenutnak++;
            }
            i++;
        }
        br_redova=int(lista.size());
        if(br_redova=0) br_kolona=0;
    }
    
    

template<typename Tip1, typename Tip2>
    auto operator +(const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2) std::remove_reference<decltype(GMatrica(1,1,g1[0][0]+g2[0][0]))>::type{
        if(g1.DajBrojRedova()!=g2.DajBrojRedova() || g1.DajBrojKolona()!=g2.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
        
        GMatrica<std::remove_reference<decltype(g1[0][0]+g2[0][0])>::type> mat(g1.DajBrojRedova(), g1.DajBrojKolona());
        for(int i(0); i<g1.DajBrojRedova(); i++){
            for(int j(0); j<g2.DajBrojKolona(); j++){
                mat.niz[i][j]=g1.niz[i][j]+g2.niz[i][j];
            }
        }
        return mat;
    }
    
template<typename Tip1, typename Tip2>
    auto operator -(const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2) std::remove_reference<decltype(GMatrica(1,1,g1[0][0]-g2[0][0]))>::type{
        if(g1.br_redova!=g2.br_redova || g1.br_kolona!=g2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
        
        GMatrica <std::remove_reference<decltype(g1[0][0]+g2[0][0])>::type> mat(g1.br_redova, g1.br_kolona);
        for(int i(0); i<mat.br_redova; i++){
            for(int j(0); j<mat.br_kolona; j++){
                mat.niz[i][j]=g1.niz[i][j]-g2.niz[i][j];
            }
        }
        return mat;
    }
    
template<typename Tip1, typename Tip2>
    auto operator *(const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2) std::remove_referecne<decltype(GMatrica(1,1,g1[0][0]*g2[0][0]))>::type{
        if(g1.br_kolona!=g2.br_redova) throw std::domain_error ("Nedozvoljena operacija");
        
        GMatrica<std::remove_reference<decltype(g1[0][0]*g2[0][0])>::type> mat(g1.br_redova, g2.br_kolona);
        for(int i(0); i<g1.br_redova; i++){
            for(int i(0); i<g2.br_kolona; j++){
                mat.niz[i][j]+=g1.niz[i][k]*g2.niz[k][j];
            }
        }
        return mat;
    }
    
template<typename Tip1, typename Tip2>
    auto operator *(Tip1 varijabla, const GMatrica<Tip2> &g) std::remove_reference<decltype(GMatrica(1,1,g[0][0]*varijabla))>::type{
        GMatrica<std::remove_reference<decltype(g[0][0]*varijabla)>::type> mat(g.br_redova, g.br_kolona);
        for(int i(0); i<g.br_redova; i++){
            for(int j(0); j<g.br_kolona; j++){
                mat.niz[i][j]=g.niz[i][j]*varijabla;
            }
        }
        return mat;
    }
    
template<typename Tip1, typename Tip2>
    auto operator *(const GMatrica<Tip1> &g, Tip1 varijabla) std::remove_reference<decltype(GMatrica(1,1,g[0][0]*varijabla))>::type{
        GMatrica<std::remove_reference<decltype(g[0][0]*varijabla)>::type> mat(g.br_redova, g.br_redova);
        for(int i(0); i<g.br_redova; i++){
            for(int j(0); j<g.br_kolona; j++){
                mat.niz[i][j]=g.niz[i][j]*varijabla;
            }
        }
        return mat;
    }
    
template<typename Tip1>
    GMatrica<Tip1>:: (int red, int kolona){
        if(red<1 || red>br_redova || kolona<1 || kolona>br_kolona) throw std::range_error("Nedozvoljen indeks");
        int i(0), k;
        for(; i<br_redova; i++){
            for(int j(0); j<br_kolona; j++){
                if(i+1==red && j+1==kolona) {
                    k=j; break;
                }
            }
        }
        return
    }


int main ()
{
    
	return 0;
}