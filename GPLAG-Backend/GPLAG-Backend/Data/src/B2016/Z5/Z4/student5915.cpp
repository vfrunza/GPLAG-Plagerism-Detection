/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <cmath>

template <typename Tip>
    class GMatrica {
        Tip elementi[4][4];
        int br_redova;
        int br_kolona;
        public:
        GMatrica();
        GMatrica(int redovi, int kolone, Tip vrijednost = 0);
        template <typename Tip2>
            GMatrica(GMatrica<Tip2>);
        template <typename Tip2>
            GMatrica(Tip2 *niz);
        template <typename Tip2>
            GMatrica(std::vector<std::vector<Tip2>> v);
        template <typename Tip2>
            GMatrica(std::initializer_list<std::initializer_list<Tip2>> lista);
        template <typename Tip2>
            GMatrica(GMatrica<Tip2> &m);
        int DajBrojRedova() { return br_redova; }
        int DajBrojKolona() { return br_kolona; }
        template <typename Tip2>
            auto operator +(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] + m.elementi[0][0])> const; // Treba friend
        template <typename Tip2>
            auto operator -(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] - m.elementi[0][0])> const; // Treba friend
        template <typename Tip2>
            auto operator *(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> const; // Treba friend
        template <typename Tip2, typename Tip3>
            friend auto operator *(Tip3 broj, const GMatrica<Tip2> &m) -> GMatrica<decltype(m.elementi[0][0] * broj)> const;
        template <typename Tip2, typename Tip3>
            friend auto operator *(const GMatrica<Tip2> &m, Tip3 broj) -> GMatrica<decltype(m.elementi[0][0] * broj)> const;
        
        template <typename Tip2> // Treba implementirati izvan
            auto operator +=(GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> & {
                if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw std::domain_error("Nedozvoljena operacija"); 
            
            GMatrica rezultujuca(br_redova, br_kolona);
            for(unsigned int i(0); i < br_redova; i++)
                for(unsigned int j(0); j < br_kolona; j++)
                    elementi[i][j] += m.elementi[i][j];
            return *this;
            }
            
        template <typename Tip2> // Treba implementirati izvan
            auto operator -=(GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> & {
                if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw std::domain_error("Nedozvoljena operacija"); 
            
            GMatrica rezultujuca(br_redova, br_kolona);
            for(unsigned int i(0); i < br_redova; i++)
                for(unsigned int j(0); j < br_kolona; j++)
                    elementi[i][j] -= m.elementi[i][j];
            return *this;
            }
            
        template <typename Tip2> // Treba implementirati izvan
            auto operator *=(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> & {
            if(br_kolona != m.br_redova) throw std::domain_error("Nedozvoljena operacija"); 
                        
                for(unsigned int i(0); i < br_redova; i++)
                    for(unsigned int j(0); j < m.br_kolona; j++)
                        for(unsigned int k(0); k < br_kolona; k++)
                            elementi[i][j] += elementi[i][k] * m.elementi[k][j];
                            
                return *this;
            }
            
        template <typename Tip2> // Treba implementirati izvan
            auto operator *=(Tip2 broj) -> GMatrica<decltype(elementi[0][0] * broj)> & {
                for(unsigned int i(0); i < br_redova; i++)
                    for(unsigned int j(0); j < br_kolona; j++)
                        elementi[i][j] *= broj;
                return *this;
            }
        template <typename Tip2, typename Tip3>
            friend bool operator ==(const GMatrica<Tip2> &m1, const GMatrica<Tip3> &m2);
        template <typename Tip2, typename Tip3>
            friend bool operator !=(const GMatrica<Tip2> &m1, const GMatrica<Tip3> &m2);
        Tip &operator ()(int x, int y);
        Tip operator ()(int x, int y) const;
        Tip *operator [](int x) { return elementi[x]; }
        const Tip *operator [](int x) const { return elementi[x]; }
        template <typename Tip2>
            friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip2> m);
        template <typename Tip2>
            friend std::istream &operator >>(std::istream &tok, GMatrica<Tip2> &m);
    };

template <typename Tip>
    GMatrica<Tip>::GMatrica() { br_redova = 0; br_kolona = 0; }

template <typename Tip>
    GMatrica<Tip>::GMatrica(int redovi, int kolone, Tip vrijednost) {
        if(redovi < 0 || redovi > 4 || kolone < 0 || kolone > 4) throw std::logic_error("Ilegalan format matrice");
        br_redova = redovi;
        br_kolona = kolone;
        for(unsigned int i(0); i < br_redova; i++)
            for(unsigned int j(0); j < br_kolona; j++)
                elementi[i][j] = vrijednost;
    }

template <typename Tip>
template <typename Tip2>
    GMatrica<Tip>::GMatrica(GMatrica<Tip2> &m) {
        br_redova = m.br_redova;
        br_kolona = m.br_kolona;
        for(unsigned int i(0); i < br_redova; i++)
            for(unsigned int j(0); j < br_kolona; j++)
                elementi[i][j] = m.elementi[i][j];
    }
   
template <typename Tip>
template <typename Tip2>
    GMatrica<Tip>::GMatrica(Tip2 *niz) {
        br_redova = 4;
        br_kolona = 4;
        for(unsigned int i(0); i < br_redova; i++)
            for(unsigned int j(0); j < br_kolona; j++)
                elementi[i][j] = niz[i][j];
    }

template <typename Tip>
template <typename Tip2>
    GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip2>> v) {
        if(v.size() < 0 || v.size() > 4) throw std::logic_error("Ilegalan format matrice");
        for(unsigned int i(1); i < v.size(); i++)
            if(v[i].size() != v[0].size() || v[0].size() > 4) throw std::logic_error("Ilegalan format matrice");
            
        for(unsigned int i(0); i < v.size(); i++)
            for(unsigned int j(0); j < v[i].size(); j++)
                elementi[i][j] = v[i][j];
        br_redova = v.size();
        br_kolona = v[0].size();
    }
    
template <typename Tip>
template <typename Ti2>
    GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Ti2>> lista) {
        if(lista.size() < 0 || lista.size() > 4) throw std::logic_error("Ilegalan format matrice");
        for(unsigned int i(1); i < lista.size(); i++)
            if(lista.begin()[i].size() != lista.begin()[0].size() || lista.begin()[0].size() > 4) throw std::logic_error("Ilegalan format matrice");
            
        for(unsigned int i(0); i < lista.size(); i++)
            for(unsigned int j(0); j < lista.begin()[i].size(); j++)
                elementi[i][j] = lista.begin()[i].begin()[j];
        br_redova = lista.size();
        br_kolona = lista.begin()[0].size();
    }

template <typename Tip>
    template <typename Tip2>
        auto GMatrica<Tip>::operator +(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] + m.elementi[0][0])> const {
            if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw std::domain_error("Nedozvoljena operacija"); 
            
            GMatrica rezultujuca(br_redova, br_kolona);
            for(unsigned int i(0); i < br_redova; i++)
                for(unsigned int j(0); j < br_kolona; j++)
                    rezultujuca.elementi[i][j] = elementi[i][j] + m.elementi[i][j];
            return rezultujuca;
        }
        
template <typename Tip>
    template <typename Tip2>
        auto GMatrica<Tip>::operator -(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] - m.elementi[0][0])> const {
            if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw std::domain_error("Nedozvoljena operacija"); 
            
            GMatrica rezultujuca(br_redova, br_kolona);
            for(unsigned int i(0); i < br_redova; i++)
                for(unsigned int j(0); j < br_kolona; j++)
                    rezultujuca.elementi[i][j] = elementi[i][j] - m.elementi[i][j];
                    
            return rezultujuca;
        }
        
template <typename Tip>
    template <typename Tip2>
        auto GMatrica<Tip>::operator *(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> const {
            if(br_kolona != m.br_redova) throw std::domain_error("Nedozvoljena operacija"); 
            
            GMatrica rezultujuca(br_redova, m.br_kolona, 0);
                    
            for(unsigned int i(0); i < br_redova; i++)
                for(unsigned int j(0); j < m.br_kolona; j++)
                    for(unsigned int k(0); k < br_kolona; k++)
                        rezultujuca.elementi[i][j] += elementi[i][k] * m.elementi[k][j];
                        
            return rezultujuca;
        }

template <typename Tip2, typename Tip3>
        auto operator *(Tip3 broj, const GMatrica<Tip2> &m) -> GMatrica<decltype(m.elementi[0][0] * broj)> const {
            GMatrica<decltype(m.elementi[0][0] * broj)> rezultujuca(m.br_redova, m.br_kolona);
                    
            for(unsigned int i(0); i < m.br_redova; i++)
                for(unsigned int j(0); j < m.br_kolona; j++)
                    rezultujuca.elementi[i][j] = m.elementi[i][j];
            
            for(unsigned int i(0); i < m.br_redova; i++)
                for(unsigned int j(0); j < m.br_kolona; j++)
                    rezultujuca.elementi[i][j] *= broj;
                        
            return rezultujuca;
        }

template <typename Tip2, typename Tip3>
        auto operator *(const GMatrica<Tip2> &m, Tip3 broj) -> GMatrica<decltype(m.elementi[0][0] * broj)> const {
            GMatrica<decltype(m.elementi[0][0] * broj)> rezultujuca(m.br_redova, m.br_kolona);
                    
            for(unsigned int i(0); i < m.br_redova; i++)
                for(unsigned int j(0); j < m.br_kolona; j++)
                    rezultujuca.elementi[i][j] *= broj;
                        
            return rezultujuca;
        }
/*
template <typename Tip>
    template <typename Tip2>
        auto GMatrica<Tip>::operator +=(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> & {
            if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw std::domain_error("Nedozvoljena operacija"); 
            
            GMatrica rezultujuca(br_redova, br_kolona);
            for(unsigned int i(0); i < br_redova; i++)
                for(unsigned int j(0); j < br_kolona; j++)
                    elementi[i][j] += m.elementi[i][j];
            return *this;
        }
*/

/*
template <typename Tip>
    template <typename Tip2>
        auto GMatrica<Tip>::operator -=(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> & {
            if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw std::domain_error("Nedozvoljena operacija"); 
            
            GMatrica rezultujuca(br_redova, br_kolona);
            for(unsigned int i(0); i < br_redova; i++)
                for(unsigned int j(0); j < br_kolona; j++)
                    elementi[i][j] -= m.elementi[i][j];
            return *this;
        }
*/
/*
template <typename Tip>
    template <typename Tip2>
        auto GMatrica<Tip>::operator *=(const GMatrica<Tip2> &m) -> GMatrica<decltype(elementi[0][0] * m.elementi[0][0])> & {
            if(br_kolona != m.br_redova) throw std::domain_error("Nedozvoljena operacija"); 
                        
                for(unsigned int i(0); i < br_redova; i++)
                    for(unsigned int j(0); j < m.br_kolona; j++)
                        for(unsigned int k(0); k < br_kolona; k++)
                            elementi[i][j] += elementi[i][k] * m.elementi[k][j];
                            
                return *this;
        }
*/

template <typename Tip2, typename Tip3>
    bool operator ==(const GMatrica<Tip2> &m1, const GMatrica<Tip3> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) return false;
    else {
        for(unsigned int i(0); i < m1.br_redova; i++)
            for(unsigned int j(0); j < m1.br_kolona; j++)
                if(m1[i][j] != m2[i][j]) return false;
        return true;
    }
}

template <typename Tip2, typename Tip3>
    bool operator !=(const GMatrica<Tip2> &m1, const GMatrica<Tip3> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) return true;
    else {
        for(unsigned int i(0); i < m1.br_redova; i++)
            for(unsigned int j(0); j < m1.br_kolona; j++)
                if(m1[i][j] != m2[i][j]) return true;
        return false;
    }
}

template <typename Tip>
    Tip &GMatrica<Tip>::operator ()(int x, int y) {
        if(x > br_redova || x < 0 || y > br_kolona || y < 0) throw std::range_error("Nedozvoljen indeks");
        else return elementi[x - 1][y - 1];
    }

template <typename Tip>
    Tip GMatrica<Tip>::operator ()(int x, int y) const {
        if(x > br_redova || x < 0 || y > br_kolona || y < 0) throw std::range_error("Nedozvoljen indeks");
        else return elementi[x - 1][y - 1];
    }

template <typename Tip>
std::ostream &operator <<(std::ostream &tok, GMatrica<Tip> m) {
    int sirina;
    if(tok.width() == 0) sirina = 6;
    else sirina = tok.width();
    for(unsigned int i(0); i < m.br_redova; i++) {
        for(unsigned int j(0); j < m.br_kolona; j++)
            tok << std::setw(sirina) << m.elementi[i][j];
        tok << "\n";
    }
    
    return tok;
}

template <typename Tip>
std::istream &operator >>(std::istream &tok, GMatrica<Tip> &m) {
    char c;
    Tip el;
    std::vector<Tip> v;
    tok >> std::ws;
    tok >> c;
    if(c != '[') tok.setstate(std::ios::failbit);
    else {
        for(;;) {
            for(;;) {
                tok >> el >> c;
                if(c != ',' && c != ';') tok.setstate(std::ios::failbit);
                v.push_back(el);
                if(c == ';' || c == ']') break;
            }
            if(c == ']') break;
        }
    }
    m.br_redova = std::sqrt(v.size());
    m.br_kolona = std::sqrt(v.size());
    int brojac(0);
    for(unsigned int i(0); i < m.br_redova; i++)
        for(unsigned int j(0); j < m.br_kolona; j++) {
            m.elementi[i][j] = v[brojac];
            brojac++;
        }
    return tok;
}

int main ()
{
    // Konstrutktori
    GMatrica<int> m1;
    
    GMatrica<double> m2(2, 2, 0.5);
    std::cout << m2 << std::endl;
    
    GMatrica<double> m3(m2);
    std::cout << m3 << std::endl;
    
    int niz[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    GMatrica<int> m4(niz);
    std::cout << m4 << std::endl;
    
    std::vector<std::vector<long long int>> v(2);
    v[0].push_back(1000);
    v[0].push_back(2000);
    v[1].push_back(3000);
    v[1].push_back(4000);
    GMatrica<double> m5(v);
    std::cout << m5 << std::endl;
    
    GMatrica<int> m6({{1, 2}, {3, 4}});
    std::cout << m6 << std::endl;
    
    // Operatori +, -, +=, -=
    m2 = m2 + m3;
    std::cout << "m2 = m2 + m3:\n";
    std::cout << m2 << std::endl;
    
    m2 += m3;
    std::cout << "m2 += m3:\n";
    std::cout << m2 << std::endl;
    
    m2 = m2 - m3;
    std::cout << "m2 = m2 - m3:\n";
    std::cout << m2 << std::endl;
    
    m2 -= m3;
    std::cout << "m2 -= m3:\n";
    std::cout << m2 << std::endl;
    
    // Opratori *, *=, * (broj sa matricom)
    m2 *= m3;
    std::cout << "m2 *= m3:\n";
    std::cout << m2 << std::endl;
    
    m2 = 2 * m3;
    std::cout << "m2 = 2 * m3:\n";
    std::cout << m2 << std::endl;
    
    // Operatori () i []
    std::cout << "m6(1,1) = " << m6(1,1) << std::endl;
    std::cout << "m6[1][0] = " << m6[1][0] << std::endl << std::endl;
    
    // Operatori == i !=
    if(m2 != m3) std::cout << "m2 i m3 su razlicite\n";
    m2 = m3;
    if(m2 == m3) std::cout << "m2 i m3 su iste";
    
	return 0;
}