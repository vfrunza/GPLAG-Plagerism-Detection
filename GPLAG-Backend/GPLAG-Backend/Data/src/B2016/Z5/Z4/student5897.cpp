/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>

template <typename Tip>
class GMatrica{
    int br_redova, br_kolona;
    Tip matrica[4][4];
    
    public:
    GMatrica() { br_kolona=0; br_redova=0;}
    GMatrica(int br_redova, int br_kolona, Tip vrijednost_el=0);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> lista);
    template<typename tip2>
    GMatrica(GMatrica<tip2> &mat);
    GMatrica(Tip niz[4][4]);
    GMatrica(std::vector<std::vector<Tip>> vekt);
    int DajBrojRedova() { return br_redova; }
    int DajBrojKolona() { return br_kolona; }
    
    template<typename tip>
    friend GMatrica<tip> operator +(const GMatrica<tip> &m1, const GMatrica<tip> &m2);
    template<typename tip>
    friend GMatrica<tip> operator -(const GMatrica<tip> &m1, const GMatrica<tip> &m2);
    template<typename tip>
    friend GMatrica<tip> operator *(GMatrica<tip> m1, const GMatrica<tip> &m2);
    template <typename tip,typename Tip2>
    friend GMatrica<tip> operator *(const GMatrica<tip> &m, Tip2 broj);
    template <typename tip, typename Tip2>
    friend GMatrica<tip> operator *(Tip2 broj, GMatrica<tip> &m1) { return m1*broj; }
    GMatrica &operator +=(const GMatrica &m);
    GMatrica &operator -=(const GMatrica &m);
    GMatrica &operator *=(const GMatrica &m);
    GMatrica &operator +=(Tip br);
    GMatrica &operator -=(Tip br);
    GMatrica &operator *=(Tip br);
    bool operator ==(const GMatrica &m1) const;
    bool operator !=(const GMatrica &m1) const;
    Tip operator()(int red, int kolona);
   // Tip* operator [](int red, int kolona) {return mat[red]; }
    template<typename tip>
    friend std::ostream &operator <<(std::ostream &tok, const GMatrica<tip> &m);
    template<typename tip>
    friend std::istream &operator >>(std::istream &tok, GMatrica<tip> &m);
};


template<typename Tip>
GMatrica<Tip>::GMatrica(Tip niz[4][4]) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            matrica[i][j]=niz[i][j];
        }
    }
}

template<typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> vekt) {
    for(int i=0; i<vekt.size(); i++) {
        if(vekt[0].size()!=vekt[i].size()) throw std::logic_error("Ilegalan format matrica");
    }
    if(vekt[0].size()>4 || vekt.size()>4) throw std::logic_error("Ilegalan format matrica");
    
    br_redova=vekt.size(); br_kolona=vekt[0].size();
    for(int i=0; i<vekt.size(); i++) {
        for(int j=0; j<vekt[0].size(); j++) {
            matrica[i][j]=vekt[i][j];
        }
    }
}

template <typename Tip>
GMatrica<Tip>::GMatrica(int br_red, int br_kol, Tip vrijednost_el) {
    if(br_kol>4 || br_kol<0 || br_red>4 || br_red<0) throw std::logic_error("Ilegalan format matrice");
    
            br_kolona=br_kol; br_redova=br_red; 
            for(int i=0; i<br_redova; i++) { 
                for(int j=0; j<br_kolona; j++) {
                    matrica[i][j]=vrijednost_el; //std::cout << matrica[i][j]; } std::cout << std::endl;
                } }
    }

template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista) {
    int red(0), kolona(0);
    for(auto it=lista.begin(); it!=lista.end(); it++) { 
        kolona=0;
        for(auto it2=it->begin(); it2!=it->end(); it2++)  kolona++;
        if(kolona>4) throw std::logic_error("Ilegalan format matrice");
        red++;
    }
    if(red>4) throw std::logic_error("Ilegalan format matrice");
    
    int i=0, j=0; 
    for(auto it=lista.begin(); it!=lista.end(); it++) {
        j=0;
        for(auto it2=(*it).begin(); it2!=it->end(); it2++) {
            matrica[i][j]=*it2;
            j++;
        }
        i++;
    }
    br_redova=i; br_kolona=j;
}

//template<typename Tip, typename tip2>
//GMatrica<Tip>::GMatrica(GMatrica<tip2> &mat) {}

template<typename Tip>
GMatrica<Tip> operator +(const GMatrica<Tip> &m1, const GMatrica<Tip> &m2) {
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> m3(m1);
    m3+=m2;
    return m3;
} 

template <typename Tip>
GMatrica<Tip> operator -(const GMatrica<Tip> &m1, const GMatrica<Tip> &m2) {
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> m3(m1);
    m3-=m2;
    return m3;
}

template <typename Tip>
GMatrica<Tip> operator *(const GMatrica<Tip> &m1, const GMatrica<Tip> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> m3(m1);
    m3*=m2;
    return m3;
}

template <typename Tip,typename tip2>
GMatrica<Tip> operator *(const GMatrica<Tip> &m, tip2 broj) {
    GMatrica<Tip> m1(m);
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) m1.matrica[i][j]*=broj;
    }
    return m1;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator +=(const GMatrica<Tip> &m) {
    if(br_redova!=m.br_redova || br_kolona!=m.br_kolona) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) matrica[i][j]+=m.matrica[i][j];
    }
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator +=(Tip br) {
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) matrica[i][j]+=br;
    }
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator *=(Tip br) {
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) matrica[i][j]*=br;
    }
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator -=(Tip br) {
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) matrica[i][j]-=br;
    }
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator -=(const GMatrica<Tip> &m) {
    if(br_kolona!=m.br_kolona || br_redova!=m.br_redova) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) matrica[i][j]-=m.matrica[i][j];
    }
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator *=(const GMatrica<Tip> &m) {
    if(br_kolona!=m.br_redova) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) {
            int suma(0);
            for(int k=0; k<m.br_redova; k++) suma+=matrica[i][k]*m.matrica[k][j];
        matrica[i][j]=suma;
        }
    }
   // *this=m3;
    return *this;
}

template <typename Tip>
bool GMatrica<Tip>::operator ==(const GMatrica<Tip> &m1) const {
    if(br_kolona!=m1.br_kolona || br_redova!=m1.br_redova) return false;
    
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) 
        if(matrica[i][j]!=m1.matrica[i][j]) return false;
    }
    return true;
}

template <typename Tip>
bool GMatrica<Tip>::operator !=(const GMatrica<Tip> &m1) const {
    if(!(*this==m1)) return true;
    return false;
}

template <typename Tip>
std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip> &m) {
    int sirina(tok.width());
    if(sirina<6) {
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) tok << std::setw(6) << m.matrica[i][j];
        tok << std::endl;
    }
    }
    return tok;
}

template <typename Tip>
std::istream &operator >>(std::istream &tok, GMatrica<Tip> &m) {
    char znak;
    int i=0, j=0;
    tok >> std::ws;
        tok>> znak;
        if(znak!='[') tok.setstate(std::ios::failbit);
        while(znak!=']') {
            tok >> m.matrica[i][j] >> znak;
            if(znak!=';' && znak!=']' && znak!=',') tok.setstate(std::ios::failbit);
            j++;
            if(znak==';') { i++; j=0; }
        }
        m.br_redova=i+1; m.br_kolona=j;
    return tok;
}

template<typename Tip>
Tip GMatrica<Tip>::operator ()(int red, int kolona) {
    if(red>4 || red<1 || kolona>4 || red<1) throw std::range_error("Nedozvoljen indeks");
    return matrica[red-1][kolona-1];
}

//template<typename Tip>
/*Tip &GMatrica<Tip>::operator [](int red, int kolona) {
  return matrica[red][kolona];
    
} */


int main ()
{
 
    	return 0;
}