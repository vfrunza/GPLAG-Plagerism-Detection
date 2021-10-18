/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <stdexcept>
template <typename tip>
class GMatrica {
    tip matrica[4][4];
    int br_redova, br_kolona;
public:
    // -------------------- konstrukcija ------------------
    GMatrica();
    GMatrica(int br_redova, int br_kolona, int pocVrj);
    template <typename tip2> 
    GMatrica(GMatrica<tip2> &a);
    template <typename tip2>
    GMatrica(tip2 **Vedranovniz);
    GMatrica(std::vector<std::vector<tip>> &vektor);
    GMatrica(std::initializer_list<std::initializer_list<tip>> lista);
    // --------------------- operacija --------------------
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; }
    template <typename tip1, typename tip2>
    friend auto operator +(const GMatrica<tip1> &a, const GMatrica<tip2> &b) -> GMatrica<decltype(a.matrica[0][0] + b.matrica[0][0])>;
    template <typename tip1, typename tip2>
    friend auto operator -(const GMatrica<tip1> &a, const GMatrica<tip2> &b) -> GMatrica<decltype(a.matrica[0][0] - b.matrica[0][0])>;
    template <typename tip1, typename tip2>
    friend auto operator *(const GMatrica<tip1> &a, const GMatrica<tip2> &b) -> GMatrica<decltype(a.matrica[0][0] * b.matrica[0][0])>;
    template <typename tip1, typename tip2>
    friend auto operator *(tip1 broj, const GMatrica<tip2> &b) -> GMatrica<decltype(broj * b.matrica[0][0])>;
    template <typename tip1, typename tip2>
    friend auto operator *(const GMatrica<tip1> &b, tip2 broj) -> GMatrica<decltype(b.matrica[0][0] * broj)>;
    // -------------------- unutrasnja -------------------
    GMatrica<tip> &operator += (const GMatrica<tip> &b);
    GMatrica<tip> &operator -= (const GMatrica<tip> &b);
    GMatrica<tip> &operator *= (const GMatrica<tip> &b);
    GMatrica<tip> &operator *= (tip broj);
    template <typename tip1, typename tip2>
    friend bool operator ==(const GMatrica<tip1> &a, const GMatrica<tip2> &b);
    template <typename tip1, typename tip2>
    friend bool operator !=(const GMatrica<tip1> &a, const GMatrica<tip2> &b);
    // --------- ostala jos 4 braco mila -----------------
    const tip operator ()(int indeks1, int indeks2) const;
    tip operator ()(int indeks1, int indeks2);
    const tip* operator [](int indeks) const;
    tip* operator [](int indeks);
    template<typename tip2>
	friend std::ostream &operator << (std::ostream& ispis, GMatrica<tip2> m);		
	template <typename Tip3>
	friend std::istream &operator >> (std::istream& ispis, GMatrica<Tip3> &m);
    
};

// -------------------- konstrukcija -----------------

template <typename tip>
GMatrica<tip>::GMatrica() { br_kolona = 0; br_redova = 0; }

template <typename tip>
GMatrica<tip>::GMatrica(int br_redova, int br_kolona, int pocVrj) {
    if(br_redova < 0 || br_kolona < 0 || br_redova >= 4 || br_kolona >= 4) throw std::logic_error("Ilegalan format matrice");
    this->br_redova = br_redova; this->br_kolona = br_kolona;
    for(int i=0; i < br_redova; i++) for(int j=0; j < br_kolona; j++) matrica[i][j] = pocVrj;
}

template <typename tip>
template <typename tip2> 
GMatrica<tip>::GMatrica(GMatrica<tip2> &a) : br_redova(a.br_redova), br_kolona(a.br_kolona) {
    for(int i = 0; i < a.br_redova; i++) for(int j = 0; j < a.br_kolona; j++) matrica[i][j] = a.matrica[i][j];
}

template <typename tip>
template <typename tip2>
GMatrica<tip>::GMatrica(tip2 **Vedranovniz) : br_redova(4), br_kolona(4) {
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) matrica[i][j] = Vedranovniz[i][j];
}

template <typename tip>
GMatrica<tip>::GMatrica(std::vector<std::vector<tip>> &vektor){
    int brojRV(vektor.size());
    int brojKV(vektor[0].size());
    if(brojRV < 0 || brojKV <0 || brojRV >= 4 || brojKV >= 4) throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i < brojRV; i++) if(vektor[i] != brojKV) throw std::logic_error("Ilegalan format matrice");
    br_redova = brojRV; br_kolona = brojKV;
    for(int i=0; i < br_redova; i++) for(int j=0; j < br_kolona; j++) matrica[i][j] = vektor[i][j];
}

template <typename tip>
GMatrica<tip>::GMatrica(std::initializer_list<std::initializer_list<tip>> lista){
    int brojRV(lista.size());
    int brojKV((lista.begin())->size());
    if(brojRV < 0 || brojKV <0 || brojRV >= 4 || brojKV >= 4) throw std::logic_error("Ilegalan format matrice");
    for(auto it = lista.begin(); it != lista.end(); it++) if(it->size() != brojKV) throw std::logic_error("Ilegalan format matrice");
    br_redova = brojRV; br_kolona = brojKV;
    int i(0), j(0);
    for(auto it1 = lista.begin(); it1 != lista.end(); it1++){
        for(auto it2 = it1->begin(); it2 != it1->end(); it2++){
            matrica[i][j] = *it2;
            j++;
        }
        i++; j=0;
    }
}

// -------------------- operacija -----------------

template <typename tip1, typename tip2>
auto operator +(const GMatrica<tip1> &a, const GMatrica<tip2> &b) -> GMatrica<decltype(a.matrica[0][0] + b.matrica[0][0])> {
    if(a.DajBrojRedova() != b.DajBrojRedova() || a.DajBrojKolona() != b.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(a[0][0] + b[0][0])> Nova(a.DajBrojRedova(), a.DajBrojKolona(), 0);
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) Nova.matrica[i][j] = a.matrica[i][j] + b.matrica[i][j];
    return Nova;
}

template <typename tip1, typename tip2>
auto operator -(const GMatrica<tip1> &a, const GMatrica<tip2> &b) -> GMatrica<decltype(a.matrica[0][0] - b.matrica[0][0])> {
    if(a.DajBrojRedova() != b.DajBrojRedova() || a.DajBrojKolona() != b.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(a[0][0] - b[0][0])> Nova(a.DajBrojRedova(), a.DajBrojKolona(), 0);
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) Nova.matrica[i][j] = a.matrica[i][j] - b.matrica[i][j];
    return Nova;
}

template <typename tip1, typename tip2>
auto operator *(const GMatrica<tip1> &a, const GMatrica<tip2> &b) -> GMatrica<decltype(a.matrica[0][0] * b.matrica[0][0])> {
    if(b.DajBrojKolona() != b.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<typename std::remove_reference<decltype(a[0][0] * b[0][0])>> Nova(a.DajBrojRedova(), b.DajBrojKolona(), 0);
    
    for(int i=0; i < a.DajBrojRedova(); i++) {
        for(int j=0; j < b.DajBrojKolona(); j++) {
            typename std::remove_reference<decltype(a[0][0] * b[0][0])> suma = 0;
            for(int k=0; k < b.DajBrojRedova(); k++) {
                suma += a.matrica[i][k] * b.matrica[k][j];
            }
            Nova.matrica[i][j] = suma;
        }
    }
    return Nova;
}

template <typename tip1, typename tip2>
auto operator *(tip1 broj, const GMatrica<tip2> &b) -> GMatrica<decltype(broj * b.matrica[0][0])> {
    GMatrica<decltype(broj * b.matrica[0][0])> Nova(b.DajBrojRedova(), b.DajBrojKolona(), 0);
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) Nova.matrica[i][j] = broj * b.matrica[i][j];
    return Nova;
}

template <typename tip1, typename tip2>
auto operator *(const GMatrica<tip1> &b, tip2 broj) -> GMatrica<decltype(b.matrica[0][0] * broj)> {
    return broj * b;
}

// -------------------- unutrasnja -----------------

template <typename tip>
GMatrica<tip> &GMatrica<tip>::operator += (const GMatrica<tip> &b) {
    GMatrica<tip> a(*this);
    if(a.DajBrojRedova() != b.DajBrojRedova() || a.DajBrojKolona() != b.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<tip> Nova(a.DajBrojRedova(), a.DajBrojKolona(), 0);
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) Nova.matrica[i][j] = a.matrica[i][j] + b.matrica[i][j];
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) matrica[i][j] = Nova.matrica[i][j];
    return *this;
}

template <typename tip>
GMatrica<tip> &GMatrica<tip>::operator -= (const GMatrica<tip> &b) {
    GMatrica<tip> a(*this);
    if(a.DajBrojRedova() != b.DajBrojRedova() || a.DajBrojKolona() != b.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<tip> Nova(a.DajBrojRedova(), a.DajBrojKolona(), 0);
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) Nova.matrica[i][j] = a.matrica[i][j] - b.matrica[i][j];
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) matrica[i][j] = Nova.matrica[i][j];
    return *this;
}

template <typename tip>
GMatrica<tip> &GMatrica<tip>::operator *= (const GMatrica<tip> &b) {
    GMatrica<tip> a(*this);
    if(b.DajBrojKolona() != b.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<tip> Nova(a.DajBrojRedova(), b.DajBrojKolona(), 0);
    
    for(int i=0; i < a.DajBrojRedova(); i++) {
        for(int j=0; j < b.DajBrojKolona(); j++) {
            decltype(a.matrica[0][0] * b.matrica[0][0]) suma = 0;
            for(int k=0; k < b.DajBrojRedova(); k++) {
                suma += a.matrica[i][k] * b.matrica[k][j];
            }
            Nova.matrica[i][j] = suma;
        }
    }
    for(int i=0; i < Nova.DajBrojRedova(); i++) for(int j=0; j < Nova.DajBrojKolona(); j++) matrica[i][j] = Nova.matrica[i][j];
    return *this;
}

template <typename tip>
GMatrica<tip> &GMatrica<tip>::operator *= (tip broj){
    for(int i=0; i < br_redova; i++) for(int j=0; j < br_kolona; j++) matrica[i][j] *= broj;
    return *this;
}
    
template <typename tip1, typename tip2>
bool operator ==(const GMatrica<tip1> &a, const GMatrica<tip2> &b) {
    for(int i=0; i < a.DajBrojRedova(); i++) for(int j=0; j < a.DajBrojKolona(); j++) if(a.matrica[i][j] != b.matrica[i][j]) return false;
    return true;
}

template <typename tip1, typename tip2>
bool operator !=(const GMatrica<tip1> &a, const GMatrica<tip2> &b){
    return !(a == b);
}

// --------- ostala jos 4 braco mila -----------------

template <typename tip>
const tip GMatrica<tip>::operator ()(int indeks1, int indeks2) const {
    if(indeks1 < 1 || indeks1 > br_redova || indeks2 < 1 || indeks2 > br_kolona) throw std::range_error("Nedozvoljen indeks"); 
    return matrica[indeks1-1][indeks2-1];
}

template <typename tip>
tip GMatrica<tip>::operator ()(int indeks1, int indeks2) {
    if(indeks1 < 1 || indeks1 > br_redova || indeks2 < 1 || indeks2 > br_kolona) throw std::range_error("Nedozvoljen indeks"); 
    return matrica[indeks1-1][indeks2-1];
}

template <typename tip>
const tip* GMatrica<tip>::operator [](int indeks) const {
    return matrica[indeks];
}

template <typename tip>
tip* GMatrica<tip>::operator [](int indeks) {
    return matrica[indeks];
}

template <typename TipEl>
std::ostream &operator <<(std::ostream &ispis, GMatrica<TipEl> m) {
	int duzina = ispis.width();
	if(duzina < 6) duzina = 6;
	for(int i=0; i < m.DajBrojRedova(); i++) {
		for(int j=0; j < m.DajBrojKolona(); j++) {
			ispis.width(duzina);
			ispis << m.matrica[i][j];
		}
		std::cout << std::endl;
	}
	return ispis;
}


template <typename TipEl>
std::istream &operator >>(std::istream &ispis, GMatrica<TipEl> &m){
    std::vector<TipEl> novi;
    char a;
    ispis >> a;
    if(a != '[')  ispis.setstate(std::ios::failbit);
    int i(0),j(0), brojac(1);
    for(;;){
        ispis >> m.matrica[i][j] >> a;
        if(a == ';' || a == ']') {
            if( j > 4) ispis.setstate(std::ios::failbit);
            for(int i=0; i < novi.size(); i++) if(j != novi[i]) ispis.setstate(std::ios::failbit);
            novi.push_back(brojac);
            i++;
            if( i > 4 ) ispis.setstate(std::ios::failbit);
            j = 0; brojac=0;
            if(a == ']') break; 
            else continue;
        }
        j++; brojac++;
        if(a == ']') break; 
    }
    m.br_redova = i; m.br_kolona = novi[0];
	return ispis;
}

int main ()
{
   GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;
   return 0;
}