/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
template<typename tip>
class GMatrica {
    tip matrica[4][4];
    int broj_redova;
    int broj_kolona;
    public:
    
    GMatrica() {
        broj_redova=0;
        broj_kolona=0;
    }
    
    GMatrica(int brredova, int brkolona, tip vrijednost=tip()) {
        if(brredova<0 || brredova>4 || brkolona<0 || brkolona>4) throw std::logic_error("Ilegalan format matrice");
        broj_redova = brredova;
        broj_kolona = brkolona;
        for(int i(0); i<brredova; i++) 
            for(int j(0); j<brkolona; j++) 
                matrica[i][j] = vrijednost;
    }
    
    template<typename tip2>
    GMatrica(const GMatrica<tip2> &mat) {
       for(int i(0); i<mat.broj_redova; i++) 
            for(int j(0); j<mat.broj_kolona; j++)
                matrica[i][j] = mat.matrica[i][j];
        broj_redova = mat.broj_redova;
        broj_kolona = mat.broj_kolona;
    }
    
    template<typename tip2>
    GMatrica(tip2 mat[4][4]) {
        for(int i(0); i<4; i++) 
            for(int j(0); j<4; j++)
                matrica[i][j] = mat[i][j];
        broj_kolona = 4;
        broj_redova = 4;
    }
    
    GMatrica(std::vector<std::vector<tip>> v) {
        if(v.size()<0 || v.size()>4 || v[0].size() <0 || v[0].size() >4) throw std::logic_error("Ilegalan format matrice");
        for(int i(0); i<v.size(); i++) {
            if(v[0].size()!=v[i].size()) throw std::logic_error("Ilegalan format matrice");
        }
        broj_kolona = v[0].size();
        broj_redova = v.size();
        for(int i(0); i<v.size(); i++) 
            for(int j(0); j<v[0].size(); j++)
                matrica[i][j] = v[i][j];
    }
    
    GMatrica(std::initializer_list<std::initializer_list<tip>> v) {
        auto it(v.begin());
        if(v.size()<0 || v.size()>4 || it->size() <0 || it->size() >4) throw std::logic_error("Ilegalan format matrice");
        for(auto i(v.begin()); i!= v.end()-1; i++) 
            if(i->size()!=(i+1)->size()) throw std::logic_error("Ilegalan format matrice");
        auto it1(v.begin());
        broj_kolona = it->size();
        broj_redova = v.size();
        
        for(int i(0); i<broj_redova; i++) {
            auto it2 = it1->begin();
            for(int j(0); j<broj_kolona; j++) {
                matrica[i][j] = *it2++;
            }
            it1++;
        }
    }
    
    int DajBrojRedova() const { return broj_redova; }
    int DajBrojKolona() const { return broj_kolona; }
    template <typename tip2>
    friend GMatrica<tip2> operator +(const GMatrica<tip2> &m1, const GMatrica<tip2> &m2);
    template <typename tip2>
    friend GMatrica<tip2> operator +(const GMatrica<tip2> &m1, tip2 broj);
    template <typename tip2>
    friend GMatrica<tip2> operator +(tip2 broj, const GMatrica<tip2> &m2);
    
    template <typename tip2>
    friend GMatrica<tip2> operator -(const GMatrica<tip2> &m1, const GMatrica<tip2> &m2);
    template <typename tip2>
    friend GMatrica<tip2> operator -(const GMatrica<tip2> &m1, tip2 broj);
    template <typename tip2>
    friend GMatrica<tip2> operator -(tip2 broj, const GMatrica<tip2> &m2);
    
    template <typename tip2>
	friend GMatrica<tip2> operator *(const GMatrica<tip2> &m1, const GMatrica<tip2> &m2);
	template <typename tip2>
	friend GMatrica<tip2> operator *(const GMatrica<tip2> &m1, tip2 broj);
	template <typename tip2>
	friend GMatrica<tip2> operator *(tip2 broj, const GMatrica<tip2> &m1);
    
    tip *operator[] (int broj) {
    	return matrica[broj];
    }
    
    auto operator ()(int x, int y) ->decltype(matrica[0][0]);
    auto operator ()(int x, int y) const->decltype(matrica[0][0]+matrica[0][0]);
    template <typename tip2>
    friend std::ostream &operator <<(std::ostream &tok, const GMatrica<tip2> &mat);
    template <typename tip2>
	friend std::istream &operator >>(std::istream &tok, GMatrica<tip2> &mat);
	template <typename tip2>
	friend bool operator ==(const GMatrica<tip2> &m1, const GMatrica<tip2> &m2);
	template <typename tip2>
	friend bool operator !=(const GMatrica<tip2> &m1, const GMatrica<tip2> &m2);
	
	template <typename tip2>
	friend GMatrica<tip2> &operator *=(GMatrica<tip2> &m1, GMatrica<tip2> &m2);
	template <typename tip2>
	friend GMatrica<tip2> &operator *=(GMatrica<tip2> &m1, tip2 broj);
	
	template <typename tip2>
	friend GMatrica<tip2> &operator +=(GMatrica<tip2> &m1, GMatrica<tip2> &m2);
	template <typename tip2>
	friend GMatrica<tip2> &operator +=(GMatrica<tip2> &m1, tip2 broj);
	
	template <typename tip2>
	friend GMatrica<tip2> &operator -=(GMatrica<tip2> &m1, GMatrica<tip2> &m2);
	template <typename tip2>
	friend GMatrica<tip2> &operator -=(GMatrica<tip2> &m1, tip2 broj);
	
};

template <typename tip>
auto GMatrica<tip>::operator ()(int x, int y) ->decltype(matrica[0][0]){
	if(x<0 || x>4 || y<0 || y>4) throw std::logic_error("Ilegalan format matrice");
	return matrica[x-1][y-1];
}
template <typename tip>
auto GMatrica<tip>::operator ()(int x, int y) const->decltype(matrica[0][0]+matrica[0][0]) {
	if(x<0 || x>4 || y<0 || y>4) throw std::logic_error("Ilegalan format matrice");
	return matrica[x-1][y-1];
}

template <typename tip>
GMatrica<tip> operator +(const GMatrica<tip> &m1, const GMatrica<tip> &m2)
{
	if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
		throw std::domain_error("Nedozvoljena operacija");
	GMatrica<tip> m3;
	m3.broj_kolona = m1.broj_kolona;
	m3.broj_redova = m1.broj_redova;
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m3.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
			
	return m3;
}

template <typename tip>
GMatrica<tip> operator +(const GMatrica<tip> &m1, tip broj)
{
	GMatrica<tip> m3;
	m3.broj_kolona = m1.broj_kolona;
	m3.broj_redova = m1.broj_redova;
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m3.matrica[i][j] = m1.matrica[i][j] + broj;
	return m3;
}

template <typename tip>
GMatrica<tip> &operator +=(GMatrica<tip> &m1, tip broj)
{
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m1.matrica[i][j] = m1.matrica[i][j] + broj;
	return m1;
}

template <typename tip>
GMatrica<tip> operator +(tip broj, const GMatrica<tip> &m2)
{
	GMatrica<tip> m3;
	m3.broj_kolona = m2.broj_kolona;
	m3.broj_redova = m2.broj_redova;
	for(int i = 0; i < m2.broj_redova; i++)
		for(int j = 0; j < m2.broj_kolona; j++)
			m3.matrica[i][j] = m2.matrica[i][j] + broj;
	return m3;
}

template <typename tip>
GMatrica<tip> &operator +=(GMatrica<tip> &m1, GMatrica<tip> &m2)
{
	if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
		throw std::domain_error("Nedozvoljena operacija");

	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m1.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
			
	return m1;
}


template <typename tip>
GMatrica<tip> operator -(const GMatrica<tip> &m1, const GMatrica<tip> &m2)
{
	if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
		throw std::domain_error("Nedozvoljena operacija");
	GMatrica<tip> m3;
	m3.broj_kolona = m1.broj_kolona;
	m3.broj_redova = m1.broj_redova;
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m3.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
			
	return m3;
}

template <typename tip>
GMatrica<tip> operator -(const GMatrica<tip> &m1, tip broj)
{
	GMatrica<tip> m3;
	m3.broj_kolona = m1.broj_kolona;
	m3.broj_redova = m1.broj_redova;
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m3.matrica[i][j] = m1.matrica[i][j] - broj;
	return m3;
}

template <typename tip>
GMatrica<tip> operator -(tip broj, const GMatrica<tip> &m1)
{
	GMatrica<tip> m3;
	m3.broj_kolona = m1.broj_kolona;
	m3.broj_redova = m1.broj_redova;
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m3.matrica[i][j] = m1.matrica[i][j] - broj;
	return m3;
}

template <typename tip>
GMatrica<tip> &operator -=(GMatrica<tip> &m1, GMatrica<tip> &m2)
{
	if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
		throw std::domain_error("Nedozvoljena operacija");

	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m1.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
			
	return m1;
}

template <typename tip>
GMatrica<tip> &operator -=(GMatrica<tip> &m1, tip broj)
{
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m1.matrica[i][j] = m1.matrica[i][j] - broj;
	return m1;
}

template <typename tip>
std::ostream &operator <<(std::ostream &tok, const GMatrica<tip> &mat) {
	int n = tok.width();
	if(n<6) n=6;
	for(int i = 0; i < mat.broj_redova; i++) {
		for(int j = 0; j < mat.broj_kolona; j++)
			tok << std::setw(n) << mat.matrica[i][j];
		tok << std::endl;
	}
	return tok;
}

template <typename tip>
std::istream &operator >>(std::istream &tok, GMatrica<tip> &mat) {
	std::string s;
	tok >> s;
	int r=0, k=0;
	int ko;
	for(int i(0); i<s.length(); i++) {
		if(s[i]=='[') {
			greska: i++;
			if(s[i]<'0' || s[i]>'9') {
				tok.setstate(std::ios::failbit);
			}
			if(s[i]>='0' && s[i]<='9') mat.matrica[r][k++] = s[i]-'0';
			i++;
			if(s[i]==',') goto greska;
			if(s[i]==';') {
				ko = k;
				k=0;
				r++;
				goto greska;
			}
			if(s[i]==']') break;
		}
	}
	mat.broj_redova = r+1;
	mat.broj_kolona=ko;
	return tok;
}

template <typename tip>
GMatrica<tip> operator *(const GMatrica<tip> &m1, tip broj) {
	GMatrica<tip> m2;
	m2.broj_redova = m1.broj_redova;
	m2.broj_kolona = m1.broj_kolona;
	
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m2.matrica[i][j] = m1.matrica[i][j]*broj;
	return m2;
}

template <typename tip>
GMatrica<tip> &operator *=(GMatrica<tip> &m1, tip broj) {
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m1.matrica[i][j] = m1.matrica[i][j]*broj;
	return m1;
}

template <typename tip>
GMatrica<tip> operator *(tip broj, const GMatrica<tip> &m1) {
	GMatrica<tip> m2;
	m2.broj_redova = m1.broj_redova;
	m2.broj_kolona = m1.broj_kolona;
	
	for(int i = 0; i < m1.broj_redova; i++)
		for(int j = 0; j < m1.broj_kolona; j++)
			m2.matrica[i][j] = m1.matrica[i][j]*broj;
	return m2;
}

template <typename tip>
GMatrica<tip> operator *(const GMatrica<tip> &m1, const GMatrica<tip> &m2)
{
	if(m1.broj_kolona != m2.broj_redova)
		throw std::domain_error("Nedozvoljena operacija");
	GMatrica<tip> m3;
	m3.broj_redova = m1.broj_redova;
	m3.broj_kolona = m2.broj_kolona;
	for(int i(0); i<m1.broj_redova; i++) 
		for(int j(0); j<m2.broj_kolona; j++) 
			m3.matrica[i][j] = 0;
	
	for(int i(0); i<m1.broj_redova; i++) 
		for(int j(0); j<m2.broj_kolona; j++) 
			for(int k(0); k<m1.broj_redova; k++)
				m3.matrica[i][j] += m1.matrica[i][k] * m2.matrica[k][j]; 
	return m3;
}

template <typename tip>
GMatrica<tip> operator *=(const GMatrica<tip> &m1, const GMatrica<tip> &m2)
{
	if(m1.broj_kolona != m2.broj_redova)
		throw std::domain_error("Nedozvoljena operacija");
	GMatrica<tip> m3;
	m3.broj_redova = m1.broj_redova;
	m3.broj_kolona = m2.broj_kolona;
	for(int i(0); i<m1.broj_redova; i++) 
		for(int j(0); j<m2.broj_kolona; j++) 
			m3.matrica[i][j] = 0;
	
	for(int i(0); i<m1.broj_redova; i++) 
		for(int j(0); j<m2.broj_kolona; j++) 
			for(int k(0); k<m1.broj_redova; k++)
				m3.matrica[i][j] += m1.matrica[i][k] * m2.matrica[k][j];
	
	m1.broj_kolona = m2.broj_kolona;
	
	for(int i(0); i<m3.br_redova; i++)
		for(int j(0); j<m3.br_kolona; j++) 
			m1.matrica[i][j] = m3.matrica[i][j];
			
	return m1;
}
template <typename tip>
bool operator ==(const GMatrica<tip> &m1, const GMatrica<tip> &m2) {
    if(m1.broj_redova!= m2.broj_redova || m2.broj_kolona!= m1.broj_kolona) return false;
    for(int i(0); i<m1.broj_redova; i++) 
		for(int j(0); j<m1.broj_kolona; j++)
		    if(m1.matrica[i][j] != m2.matrica[i][j]) return false;
		    
	return true;
}
template <typename tip>
bool operator !=(const GMatrica<tip> &m1, const GMatrica<tip> &m2) {
    if(m1.broj_redova!= m2.broj_redova || m2.broj_kolona!= m1.broj_kolona) return true;
    for(int i(0); i<m1.broj_redova; i++) 
		for(int j(0); j<m1.broj_kolona; j++)
		    if(m1.matrica[i][j] != m2.matrica[i][j]) return true;
		    
	return false;
}

int main ()
{
    GMatrica<int> m1;
   std::cout << m1.DajBrojKolona() <<"," <<m1.DajBrojRedova() << std::endl;
   
   
   GMatrica<int> m2({{1, 2}, {3, 4}});
   std::cout << m2.DajBrojKolona() <<"," <<m2.DajBrojRedova() << std::endl;
   
   GMatrica<int> m3{{1, 2}, {3, 4}};
   std::cout << m3.DajBrojKolona() <<"," <<m3.DajBrojRedova() << std::endl;
	return 0;
}