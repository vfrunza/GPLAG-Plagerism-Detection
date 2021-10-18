#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>

template <typename TipEl>
class GMatrica {
    
    TipEl matrica[4][4];
    int br_redova, br_kolona;
    
    public:
    
    GMatrica();
    GMatrica(int br_redova, int br_kolonam, TipEl vrijednost = TipEl() );
    template<typename TipEl2>
    GMatrica( GMatrica<TipEl2> m);
    GMatrica(TipEl niz[4][4]);
    GMatrica(std::vector<std::vector<TipEl>> &m);
    GMatrica(std::initializer_list<std::initializer_list<TipEl>>  lista);
    
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; }
    
    TipEl &operator () (int i, int j);
    TipEl const operator () (int i, int j) const;
    TipEl *operator[](int indeks);
    TipEl const *operator[](int indeks) const;
    template<typename TipEl2, typename TipEl3>
    friend auto operator+(GMatrica<TipEl3> m1, const GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0]+0)>;
    template<typename TipEl2, typename TipEl3>
    friend auto operator-(GMatrica<TipEl3> m1, const GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0]+0)>;
    template<typename TipEl2, typename TipEl3>
    friend auto operator*(GMatrica<TipEl2> m1, const GMatrica<TipEl3> &m2) -> GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0]+0)>;
    template<typename TipEl2, typename TipEl3>
    friend GMatrica<TipEl3> operator*(TipEl2 broj, GMatrica<TipEl3> m);
    template<typename TipEl3, typename TipEl2>
    friend GMatrica<TipEl3> operator*(GMatrica<TipEl3> m, TipEl2 broj);
    template<typename TipEl2>
    GMatrica<TipEl> &operator+=(const GMatrica<TipEl2> &m1);
    template<typename TipEl2>
    GMatrica<TipEl> &operator-=(const GMatrica<TipEl2> &m1);
    template<typename TipEl2>
    GMatrica<TipEl> &operator*=(const GMatrica<TipEl2> &m1);
    template<typename TipEl2>
    GMatrica<TipEl> &operator*=(TipEl2 broj);
    template<typename TipEl2>
    friend bool operator==(const GMatrica<TipEl2> &m1, const GMatrica<TipEl2> &m2);
    template<typename TipEl2>
    friend bool operator!=(const GMatrica<TipEl2> &m1, const GMatrica<TipEl2> &m2);
    template<typename TipEl2>
    friend std::ostream& operator<<(std::ostream &tok, const GMatrica<TipEl2> &m);
    template<typename TipEl2>
    friend std::istream& operator>>(std::istream &tok, GMatrica<TipEl2> &m);
};

//KONSTRUKTORI
template<typename TipEl>
GMatrica<TipEl>::GMatrica() : br_redova(0), br_kolona(0) {}

template<typename TipEl>
GMatrica<TipEl>::GMatrica(int r, int k, TipEl vrijednost) {
    if(r<0 || k<0 || r>4 || k>4) throw std::logic_error ("Ilegalan format matrice");
    br_redova=r; br_kolona=k;
    for(int i=0; i<r; i++) {
        for(int j=0; j<k; j++)
            matrica[i][j]=vrijednost;
    }
}

template<typename TipEl>
template<typename TipEl2>
GMatrica<TipEl>::GMatrica(GMatrica<TipEl2> m) {
    br_redova=m.DajBrojRedova(); br_kolona=m.DajBrojKolona();
    for(int i=0; i<br_redova; ++i) {
        for(int j=0; j<br_kolona; ++j)
            matrica[i][j]=m(i+1,j+1);
    }
}

template<typename TipEl>
GMatrica<TipEl>::GMatrica(TipEl niz[4][4]) {
    br_redova=4; br_kolona=4;
    for(int i=0; i<br_redova; ++i) {
        for(int j=0; j<br_kolona; ++j)
            matrica[i][j]=niz[i][j];
    }
}

template<typename TipEl>
GMatrica<TipEl>::GMatrica(std::vector<std::vector<TipEl>> &m) {
    if(m.size()<0 || m.size()>4) throw std::logic_error ("Ilegalan format matrice");
    for(int i=0; i<m.size(); ++i) {
        if(m[i].size()!=m[0].size() || m[i].size()>4) throw std::logic_error ("Ilegalan format matrice");
    }
    br_redova=m.size(); br_kolona=m[0].size();
    for(int i=0; i<m.size(); ++i) {
        for(int j=0; j<m[0].size(); ++j)
            matrica[i][j]=m[i][j]; 
    }
}

template<typename TipEl>
GMatrica<TipEl>::GMatrica(std::initializer_list<std::initializer_list<TipEl>> lista) {
    if(lista.size()<0 || lista.size()>4) throw std::logic_error ("Ilegalan format matrice");
    auto it(lista.begin());
    br_redova=lista.size(); br_kolona=lista.begin()->size();
    for(int i=0; i<lista.size(); ++i) {
        if(it->size()!=lista.begin()->size() || it->size()>4) throw std::logic_error ("Ilegalan format matrice");
        it++;
    }
    
    for(int i=0; i<lista.size(); i++) {
        auto it2=(lista.begin()+i)->begin();
        for(int j=0; j<lista.begin()->size(); j++)  {
            matrica[i][j]=*it2;
            it2++;
    }
    }
    
}

//OPERATORI
template<typename TipEl>
TipEl &GMatrica<TipEl>::operator () (int i, int j) {
        if(i<1 || j<1 || i>4 || j>4) throw std::range_error ("Nedozvoljen indeks");
    return matrica[i-1][j-1];
    }

template<typename TipEl>
TipEl const GMatrica<TipEl>::operator () (int i, int j) const {
        if(i<1 || j<1 || i>4 || j>4) throw std::range_error ("Nedozvoljen indeks");
    return matrica[i-1][j-1];
    }
    
template<typename TipEl>
TipEl *GMatrica<TipEl>::operator[](int indeks) {
    return &matrica[indeks][0];
}

template<typename TipEl>
TipEl const *GMatrica<TipEl>::operator[](int indeks) const {
    return &matrica[indeks][0];
}
    
template<typename TipEl2, typename TipEl>
auto operator+(GMatrica<TipEl> m1, const GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0]+0)> {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Nedozvoljena operacija");
    return m1+=m2;
}

template<typename TipEl2, typename TipEl>
auto operator-(GMatrica<TipEl> m1, const GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0]+0)> {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Nedozvoljena operacija");
    return m1-=m2;
}

template<typename TipEl2, typename TipEl>
auto operator*(GMatrica<TipEl2> m1, const GMatrica<TipEl> &m2) -> GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0]+0)> {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error ("Nedozvoljena operacija");
    return m1*=m2;
}

template<typename TipEl2, typename TipEl>
GMatrica<TipEl> operator*(TipEl2 broj, GMatrica<TipEl> m) {
     
     return m*=broj;
}

template<typename TipEl2, typename TipEl>
GMatrica<TipEl2> operator*(GMatrica<TipEl2> m, TipEl broj) {
    return m*=broj;
}

template<typename TipEl>
template<typename TipEl2>
GMatrica<TipEl> &GMatrica<TipEl>::operator+=(const GMatrica<TipEl2> &m1){
    if(this->br_redova!=m1.br_redova || this->br_kolona!=m1.br_kolona) throw std::domain_error ("Nedozvoljena operacija");
    for(int i=0; i<this->br_redova; ++i) {
        for(int j=0; j<m1.br_kolona; ++j)
            this->matrica[i][j]+=m1.matrica[i][j];
    }
    return *this;
}

template<typename TipEl>
template<typename TipEl2>
GMatrica<TipEl> &GMatrica<TipEl>::operator-=(const GMatrica<TipEl2> &m1){
    if(this->br_redova!=m1.br_redova || this->br_kolona!=m1.br_kolona) throw std::domain_error ("Nedozvoljena operacija");
    for(int i=0; i<this->br_redova; ++i) {
        for(int j=0; j<m1.br_kolona; ++j)
            this->matrica[i][j]-=m1.matrica[i][j];
    }
    return *this;
}

template<typename TipEl>
template<typename TipEl2>
GMatrica<TipEl> &GMatrica<TipEl>::operator*=(const GMatrica<TipEl2> &m1) {
    if(this->br_kolona!=m1.br_redova) throw std::domain_error ("Nedozvoljena operacija");
    GMatrica<TipEl> nova(*this);
    for(int i=0; i<this->br_redova; ++i) {
        for(int j=0; j<m1.br_kolona; ++j) {
           double suma(0);
           for(int k=0; k<m1.br_redova; ++k)
                suma+=nova.matrica[i][k]*m1.matrica[k][j];
            this->matrica[i][j]=suma;
        }
    }
    return *this;
}

template<typename TipEl>
template<typename TipEl2>
GMatrica<TipEl> &GMatrica<TipEl>::operator*=(TipEl2 broj) {
    for(int i=0; i<this->br_redova; ++i) {
         for(int j=0; j<this->br_kolona; ++j)
            this->matrica[i][j]*=broj;
     }
     return *this;
}

template<typename TipEl>
bool operator==(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Nedozvoljena operacija");
    for(int i=0; i<m1.br_redova; ++i) {
        for(int j=0; j<m1.br_kolona; ++j) {
            if(m1.matrica[i][j]!=m2.matrica[i][j]) return false;
        }
    }
    return true;
}

template<typename TipEl>
bool operator!=(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2) {
    return !(m1==m2);
}

template<typename TipEl>
std::ostream& operator<<(std::ostream &tok, const GMatrica<TipEl> &m) {
    int sirina(tok.width());
    if(sirina<6) sirina=6;
    for(int i=0; i<m.br_redova; ++i) {
        for(int j=0; j<m.br_kolona; ++j)
            tok<<std::setw(sirina)<<m.matrica[i][j];
        tok<<std::endl;
    }
    return tok;
}

template<typename TipEl>
std::istream& operator>>(std::istream &tok, GMatrica<TipEl> &m) {
    char znak;
    std::vector<std::vector<TipEl>> pom(4, std::vector<TipEl> (4));
    tok>>std::ws;
    tok>>znak;
    int i(0), j(0);
    if(znak=='[') {
        for(;;) {
            if(i>4 || j>=4) { tok.setstate(std::ios::failbit); break; }
            tok>>m.matrica[i][j]>>znak;
            j++;
            if(znak==']') {  break; }
            if(znak==';') { i++; j=0; continue; }
            if(znak!=',') { tok.setstate(std::ios::failbit); break; }
            
        }
    }
    
    else tok.setstate(std::ios::failbit);
    if(tok)
        m.br_redova=i+1; m.br_kolona=j;
    return tok;
}



int main () {
GMatrica<int> m1({{2,2},{4,5}}) ;
GMatrica<int> m2({{1,1},{4,6}})   ;
m1=m1*m2;
std::cout<<m1;
	return 0;
}