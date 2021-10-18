/B16/17 (Zadaća 5, Zadatak 4)
#include <initializer_list>
#include <type_traits>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>

template <typename tip>
    class GMatrica {
        tip mat[4][4];
        int broj_redova, broj_kolona;
    public:
    // Nekoliko konstruktora ..
        GMatrica();
        GMatrica(int broj_redova, int broj_kolona, tip vrijednost = tip());
        GMatrica(std::initializer_list<std::initializer_list<tip>> lista);
//        template<typename novi_tip>
//            GMatrica(const GMatrica &mat_);
        
    // just geteri ..
        int DajBrojRedova() const { return broj_redova; }
        int DajBrojKolona() const { return broj_kolona; }
        
    // Osnovni binarni operatori .... + -> - -> *
        template<typename tipI, typename tipII>
            friend auto operator +(const GMatrica<tipI> &x, const GMatrica<tipII> &y) -> GMatrica<decltype(x.mat[0][0] + y.mat[0][0])>;
        template<typename tipI, typename tipII>
            friend auto operator -(const GMatrica<tipI> &x, const GMatrica<tipII> &y) -> GMatrica<decltype(x.mat[0][0] - y.mat[0][0])>;
        template<typename tipI, typename tipII>
            friend auto operator *(const GMatrica<tipI> &x, const tipII &y) -> GMatrica<decltype(x.mat[0][0] * y)>;
        template<typename tipI, typename tipII>
            friend auto operator *(const tipI &x, const GMatrica<tipII> &y) -> GMatrica<decltype(x * y.mat[0][0])>;
    // Dalje +=, -=, *= ... itd ...
/*        template<typename tip_>
            auto operator +=(GMatrica <tip_> &x) -> GMatrica<decltype(this->mat[0][0] + x.mat[0][0])>;*/
    // Operatori for(;;) >> i << i >> i << i >> i << i >> i << i >> ... break;
        template<typename tip_>
            friend std::ostream &operator <<(std::ostream &tok, const GMatrica<tip_> &mat);
    };
    
// Nekolikoo konstruktoraa ...
template <typename tip> // prvi konstruktor (bez parametara) ..
    GMatrica<tip>::GMatrica () : broj_redova(0), broj_kolona(0) {}
    
template <typename tip> // drugi konstruktor (red, kolona, vrijednost = tip()) ..
    GMatrica<tip>::GMatrica (int broj_redova, int broj_kolona, tip vrijednost) {
        if (broj_redova > 4 and broj_redova < 0 and broj_kolona > 4 and broj_kolona < 0 and broj_redova != broj_kolona)
            throw std::logic_error ("Illegalan format matrice");
        GMatrica::broj_redova = broj_redova; GMatrica::broj_kolona = broj_kolona;
        for (int i=0; i<broj_redova; ++i) 
            for (int j=0; j<broj_kolona; ++j)
                GMatrica::mat[i][j] = vrijednost;
    }
    
template <typename tip> // treci konstruktor (initializer_list) ....
    GMatrica<tip>::GMatrica (std::initializer_list<std::initializer_list<tip>> lista) {
        bool DaLiJeLegalno{true};
            auto temp_it = lista.begin();
                int kolone = temp_it->size();
            
            if (lista.size() > 4 or kolone > 4) {
                DaLiJeLegalno = false;
            }   else {
                for (auto it = lista.begin(); it != lista.end(); ++it) 
                    if (kolone != it->size()) {
                        DaLiJeLegalno = false; break;
                    }
            }
                
        if (DaLiJeLegalno) {
            this->broj_redova = lista.size(); this->broj_kolona = kolone;
            int i{0};
            for (const auto &y : lista) {
                int j{0};
                for (const auto &x : y)
                    this->mat[i][j] = x, j++;  i++;
            }
        }   else {
            throw std::logic_error ("Illegalan format matrice");
        }
    }

    /*
template <typename tip> // petii konstruktor ()
    template <typename novi_tip>
        GMatrica<novi_tip>::GMatrica (const GMatrica<novi_tip> &mat_) {
            this->broj_kolona = mat_.DajBrojKolona();
            this->broj_redova = mat_.DajBrojRedova();
            for (int i=0; i<mat_.DajBrojRedova(); ++i)
                for (int j=0; j<mat_.DajBrojKolona(); ++j)
                    mat_[i][j] = GMatrica<novi_tip>::mat[i][j];
        }*/
        
template <typename tipI, typename tipII>
    auto operator +(const GMatrica<tipI> &x, const GMatrica<tipII> &y) -> GMatrica<decltype(x.mat[0][0] + y.mat[0][0])> {
        if ( not(x.DajBrojRedova() == y.DajBrojRedova()) or not(x.DajBrojKolona() == y.DajBrojKolona())) 
            throw std::domain_error ("Nedozvoljena operacija");
        
        GMatrica<decltype(x.mat[0][0] + y.mat[0][0])> temp(x.DajBrojRedova(), x.DajBrojKolona());
        for (int i=0; i<x.DajBrojRedova(); ++i)
            for (int j=0; j<x.DajBrojKolona(); ++j)
                temp.mat[i][j] = x.mat[i][j] + y.mat[i][j]; return temp;
    }

template <typename tipI, typename tipII>
    auto operator -(const GMatrica<tipI> &x, const GMatrica<tipII> &y) -> GMatrica<decltype(x.mat[0][0] - y.mat[0][0])> {
        if ( not(x.DajBrojRedova() == y.DajBrojRedova()) or not(x.DajBrojKolona() == y.DajBrojKolona()))
            throw std::domain_error ("Nedozvoljena operacija");
            
        GMatrica<decltype(x.mat[0][0] - y.mat[0][0])> temp(x.DajBrojRedova(), x.DajBrojKolona());
        for (int i=0; i<x.DajBrojRedova(); ++i) 
            for (int j=0; j<x.DajBrojKolona(); ++j)
                temp.mat[i][j] = x.mat[i][j] - y.mat[i][j]; return temp;
    }
    
template <typename tipI, typename tipII>
    auto operator *(const GMatrica<tipI> &x, const tipII &y) -> GMatrica<decltype(x.mat[0][0] * y)> {
        GMatrica<decltype(x.mat[0][0] * y)> temp (x.DajBrojRedova(), x.DajBrojKolona());
        for (int i=0; i<x.DajBrojRedova(); ++i)
            for (int j=0; j<x.DajBrojKolona(); ++j)
                temp.mat[i][j] = x.mat[i][j] * y;   return temp;
    }
    
template <typename tipI, typename tipII>
    auto operator *(const tipI &x, const GMatrica<tipII> &y) -> GMatrica<decltype(x * y.mat[0][0])> {
        GMatrica<decltype(x * y.mat[0][0])> temp (y.DajBrojRedova(), y.DajBrojKolona());
        for (int i=0; i<y.DajBrojRedova(); ++i)
            for (int j=0; j<y.DajBrojKolona(); ++j)
                temp.mat[i][j] = x * y.mat[i][j];   return temp;
    }
// Dalje .........................
/*
template <typename tip_>
    auto &operator +=(GMatrica<tip_> &x) -> GMatrica<decltype(this->mat[0][0] + x.mat[0][0])> {
        return *this = *this + x;
    }*/

template <typename tip>
    std::ostream &operator <<(std::ostream &tok, const GMatrica<tip> &mat) {
        for (int i=0; i<mat.DajBrojRedova(); ++i) {
            for (int j=0; j<mat.DajBrojKolona(); ++j)
                tok << std::setw(6) << mat.mat[i][j]; tok << std::endl;
        }   return tok;
    }

int main ()
{
    GMatrica<int> nesto{{1,2,3}, {1,2,3}};
    GMatrica<int> drugo{{1,2,3}, {1,2,3}};
    GMatrica<int> trece = nesto*2;
    std::cout << trece;
	return 0;
}