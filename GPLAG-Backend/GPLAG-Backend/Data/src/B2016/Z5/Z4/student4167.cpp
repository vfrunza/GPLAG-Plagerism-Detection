/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <vector>
#include <iomanip>

template <typename Tip>
class GMatrica {
    Tip matrica[4][4];
    int br_redova, br_kolona;
public:
    GMatrica() : br_redova(0), br_kolona(0) {}
    GMatrica(int br_redova, int br_kolona, Tip el={});
    
    template <typename Tip2>
    GMatrica(const GMatrica<Tip2> &mat);
    
    template <typename Tip2>
    GMatrica(Tip2 niz[]);
    
    GMatrica(std::vector<std::vector<Tip>> v);
    GMatrica(std::initializer_list<std::vector<Tip>> lista);
    
    int DajBrojRedova() const {return br_redova;}
    int DajBrojKolona() const {return br_kolona;}
    
    template <typename Tip1, typename Tip2>
    friend auto operator +(const GMatrica<Tip1> m1, const GMatrica<Tip2> m2) -> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> ;
    
    template <typename Tip1, typename Tip2>
    friend auto operator -(const GMatrica<Tip1> m1, const GMatrica<Tip2> m2) -> GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])> ;
    
    template <typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> m1, const GMatrica<Tip2> m2) -> GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>;
    
    template <typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &m, Tip2 x) -> GMatrica<decltype(m.matrica[0][0]*x)>;
    
    template <typename Tip1, typename Tip2>
    friend auto operator *(Tip2 x, const GMatrica<Tip1> &m) -> GMatrica<decltype(m.matrica[0][0]*x)>;
    
    GMatrica<Tip> &operator +=(const GMatrica<Tip> &m);
    GMatrica<Tip> &operator -=(const GMatrica<Tip> &m);
    GMatrica<Tip> &operator *=(const GMatrica<Tip> &m);
    
    GMatrica<Tip> &operator +=(const Tip &x);
    GMatrica<Tip> &operator -=(const Tip &x);
    GMatrica<Tip> &operator *=(const Tip &x);
    
    template <typename Tip1, typename Tip2>
    friend bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
    
    template <typename Tip1, typename Tip2>
    friend bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
    
    auto operator [](int i) const -> decltype(matrica[i]);
	auto operator [](int i) -> decltype(matrica[i]);
	
	auto operator ()(int i, int j) const -> decltype(matrica[i][j]);
	auto operator ()(int i, int j) -> decltype(matrica[i][j]);
	
	template <typename Tip2>
	friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip2> &m);
	
	template <typename Tip2>
	friend std::istream &operator >>(std::istream &tok, GMatrica<Tip2> &m);
	
};

template <typename Tip>
GMatrica<Tip>::GMatrica(int br_redova, int br_kolona, Tip el) : br_redova(br_redova), br_kolona(br_kolona) {
    if(br_redova<0 or br_redova>4 or br_kolona<0 or br_kolona>4)
        throw std::logic_error("Ilegalan format matrice");
    GMatrica<Tip>::br_redova=br_redova;
    GMatrica<Tip>::br_kolona=br_kolona;
    for(int i(0); i<br_redova; i++)
        for(int j(0); j<br_kolona; j++)
            matrica[i][j]=el;
}

template <typename Tip>
template <typename Tip2>
GMatrica<Tip>::GMatrica(const GMatrica<Tip2> &mat) : br_redova(mat.DajBrojRedova()), br_kolona(mat.DajBrojKolona()) {
    for(int i(0); i<br_redova; i++)
        for(int j(0); j<br_kolona; j++)
            matrica[i][j]=mat(i+1,j+1);
}

template <typename Tip>
template <typename Tip2>
GMatrica<Tip>::GMatrica(Tip2 niz[]) : br_redova(4), br_kolona(4) {
    for(int i(0); i<4; i++)
        for(int j(0); j<4; j++)
            matrica[i][j]=niz[i][j];
}

template <typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> v) {
    if(v.size()>4 or v.size<0)
        throw std::logic_error("Ilegalan format matrice");
    int broj(v[0].size());
    for(auto x : v)
        if(x.size()!=broj)
            throw std::logic_error("Ilegalan format matrice");
    br_redova=v.size();
    br_kolona=broj;
    for(int i(0); i<br_redova; i++)
        for(int j(0); j<br_kolona; j++)
            matrica[i][j]=v[i][j];
}

template <typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::vector<Tip>> lista) {
    if(lista.size()>4 or lista.size()<0)
        throw std::logic_error("Ilegalan format matrice");
    int broj((*lista.begin()).size());
    for(auto x : lista)
        if(x.size()!=broj)
            throw std::logic_error("Ilegalan format matrice");
    br_redova=lista.size();
    br_kolona=broj;
    auto it(lista.begin());
    int i(0);
    while(it!=lista.end()) {
        int j(0);
        for(auto it2(it->begin()); it2!=it->end(); it2++) {
            matrica[i][j]=*it2;
            j++;
        }
        it++; i++;
    }
    /*for(int i(0); i<br_redova; i++)
        for(int j(0); j<br_kolona; j++)
            matrica[i][j]=lista[i][j];*/
}

template <typename Tip1, typename Tip2>
auto operator +(const GMatrica<Tip1> m1, const GMatrica<Tip2> m2) -> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> {
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() or m1.DajBrojKolona()!=m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> mat(m1.DajBrojRedova(), m1.DajBrojKolona());
    for(int i(0); i<mat.br_redova; i++)
        for(int j(0); j<mat.br_kolona; j++)
            mat.matrica[i][j]=m1.matrica[i][j]+m2.matrica[i][j];
    return mat;
}

template <typename Tip1, typename Tip2>
auto operator -(const GMatrica<Tip1> m1, const GMatrica<Tip2> m2) -> GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])> {
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() or m1.DajBrojKolona()!=m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])> mat(m1.DajBrojRedova(), m1.DajBrojKolona());
    for(int i(0); i<mat.br_redova; i++)
        for(int j(0); j<mat.br_kolona; j++)
            mat.matrica[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
    return mat;
}
    
template <typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1> m1, const GMatrica<Tip2> m2) -> GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>{
    if(m1.DajBrojKolona()!=m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])> mat(m1.DajBrojRedova(), m2.DajBrojKolona());
    for(int i(0); i<mat.br_redova; i++)
		for(int j(0); j<mat.br_kolona; j++)
			for(int k(0); k<m1.br_kolona; k++)
				mat.matrica[i][j] += m1.matrica[i][k]*m2.matrica[k][j];
    return mat;
}

template <typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1> &m, Tip2 x) -> GMatrica<decltype(m.matrica[0][0]*x)> {
	GMatrica<Tip1> m3(m.br_redova, m.br_kolona);
	for(int i(0); i<m3.br_redova; i++)
		for(int j(0); j<m3.br_kolona; j++)
			m3.matrica[i][j]=x*m.matrica[i][j];
	return m3;
}

template <typename Tip1, typename Tip2>
auto operator *(Tip2 x, const GMatrica<Tip1> &m) -> GMatrica<decltype(m.matrica[0][0]*x)> {
	GMatrica<Tip1> m3(m.br_redova, m.br_kolona);
	for(int i(0); i<m3.br_redova; i++)
		for(int j(0); j<m3.br_kolona; j++)
			m3.matrica[i][j]=x*m.matrica[i][j];
	return m3;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator +=(const GMatrica<Tip> &m) {
    if(br_redova!=m.br_redova or br_kolona!=m.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
    for(int i(0); i<br_redova; i++)
        for(int j(0); j<br_kolona; j++)
            matrica[i][j]+=m.matrica[i][j];
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator -=(const GMatrica<Tip> &m) {
    if(br_redova!=m.br_redova or br_kolona!=m.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
    for(int i(0); i<br_redova; i++)
        for(int j(0); j<br_kolona; j++)
            matrica[i][j]-=m.matrica[i][j];
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator *=(const GMatrica<Tip> &m) {
    if(br_kolona!=m.br_redova)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> mat(m);
    for(int i(0); i<mat.br_redova; i++)
		for(int j(0); j<mat.br_kolona; j++)
			for(int k(0); k<m.br_kolona; k++)
				matrica[i][j] += mat.matrica[i][k]*m.matrica[k][j];
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator +=(const Tip &x) {
    for(int i(0); i<br_redova; i++)
		for(int j(0); j<br_kolona; j++)
			matrica[i][j] += x;
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator -=(const Tip &x) {
    for(int i(0); i<br_redova; i++)
		for(int j(0); j<br_kolona; j++)
			matrica[i][j] -= x;
    return *this;
}

template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator *=(const Tip &x) {
    for(int i(0); i<br_redova; i++)
		for(int j(0); j<br_kolona; j++)
			matrica[i][j] *= x;
    return *this;
}

template <typename Tip1, typename Tip2>
bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) {
    if(m1.br_redova!=m2.br_redova) return false;
    if(m1.br_kolona!=m2.br_kolona) return false;
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++)
            if(m1.matrica[i][j]!=m2.matrica[i][j]) return false;
    return true;
}

template <typename Tip1, typename Tip2>
bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) {
    return !(m1==m2);
}

template <typename Tip>
auto GMatrica<Tip>::operator [](int i) const -> decltype(matrica[i]) { 
    return matrica[i];
}
    
template <typename Tip>
auto GMatrica<Tip>::operator [](int i) -> decltype(matrica[i]) {
    return matrica[i];
}

template <typename Tip>
auto GMatrica<Tip>::operator ()(int i, int j) const -> decltype(matrica[i][j]) {
		if(i<1 or i>br_redova+1 or j<1 or j>br_kolona+1)
			throw std::range_error("Nedozvoljen indeks");
		return matrica[i-1][j-1];
}

template <typename Tip>
auto GMatrica<Tip>::operator ()(int i, int j) -> decltype(matrica[i][j]) {
		if(i<1 or i>br_redova+1 or j<1 or j>br_kolona+1)
			throw std::range_error("Nedozvoljen indeks");
		return matrica[i-1][j-1];
}

template <typename Tip>
std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip> &m) {
    int sirina(tok.width());
    if(sirina==0) sirina=6;
    for(int i(0); i<m.br_redova; i++) {
		for(int j(0); j<m.br_kolona; j++)
			tok << std::setw(sirina) << m.matrica[i][j];
		tok << std::endl;
	}
	return tok;
}

template <typename Tip>	
std::istream &operator >>(std::istream &tok, GMatrica<Tip> &m) {
    tok >> std::ws;
    int i(0), j(0); char znak;
    tok >> znak;
    if(znak!='[') {
        tok.setstate(std::ios::failbit);
    } else {
        while(1) {
        if(i==4) tok.setstate(std::ios::failbit);
        while(1) {
        if(j==4) tok.setstate(std::ios::failbit);
        tok.clear();
        tok >> m.matrica[i][j]; j++; tok >> znak;
        //std::cout << "O" << znak << "O";
        if(znak==';') break;
        if(znak==']') {
            m.br_redova=i+1;
            m.br_kolona=j;
            return tok;
        }
        if(znak!=',') tok.setstate(std::ios::failbit);
        }
        i++; j=0;
        }
    }
	return tok;
}

int main ()
{
    GMatrica<int> g;
    std::cin >> g;
    std::cout << std::endl << "Matrica g:" << std::endl << std::setw(6) << g;
    GMatrica<double> g3(g);
    std::cout << std::endl << "Matrica g3:" << std::endl << std::setw(6) << g3 << std::endl;
    int niz[4][4]{{1,2,3},{0,0,2}};
    GMatrica<double> g2(niz);
    std::cout << std::endl << "Matrica g2:" << std::endl << std::setw(6) << g2;
	return 0;
}