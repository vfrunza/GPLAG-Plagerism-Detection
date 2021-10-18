#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <string>
#include <initializer_list>
#include <type_traits>

template <typename T>
    class GMatrica {
        T matrica[4][4]{};
        int redova, kolona;
    public: 
        //konstruktori
        GMatrica();
        GMatrica (int redova, int kolona, T val = T());
        GMatrica (std::vector<std::vector<T>> v);
        template <typename Tip>
            GMatrica<T> (GMatrica<Tip> &m);
        template <typename Tip>
            GMatrica<T> (Tip **niz);
        template <typename Tip>
            GMatrica<T> (std::initializer_list<std::initializer_list<Tip>> m);
            
        //metode //done
        int DajBrojRedova() const {return redova;}
        int DajBrojKolona() const {return kolona;}
        
        //operatori
        template <typename Tip1>
            friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip1> &m);
        template <typename Tip1> 
            friend std::istream &operator >>(std::istream &tok, GMatrica<Tip1> &m);
            
        template <typename Tip1, typename Tip2> //done
            friend auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) 
                -> GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])>;
        template <typename Tip1, typename Tip2> //done
            friend auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) 
                -> GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])>;
        template <typename Tip1, typename Tip2> //done
            friend auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) 
                -> GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])>;
        template <typename Tip1, typename Tip2> //done
            friend auto operator *(Tip1 skalar, const GMatrica<Tip2> &m) 
                -> GMatrica<decltype(skalar * m.matrica[0][0])>;
        template <typename Tip1, typename Tip2> //done
            friend auto operator *(const GMatrica<Tip1> &m, Tip2 skalar) 
                -> GMatrica<decltype(skalar * m.matrica[0][0])>;
        
        template <typename Tip1> 
            auto operator +=(const GMatrica<Tip1> &m) 
                -> GMatrica<decltype(this->matrica[0][0] + m.matrica[0][0])>;
        template <typename Tip1>
            auto operator +=(Tip1 skalar) 
                -> GMatrica<decltype(this->matrica[0][0] + skalar)>;
        template <typename Tip1>
            auto operator -=(const GMatrica<Tip1> &m) 
                -> GMatrica<decltype(this->matrica[0][0] - m.matrica[0][0])>;
        template <typename Tip1>
            auto operator -=(Tip1 skalar) 
                -> GMatrica<decltype(this->matrica[0][0] - skalar)>;
        template <typename Tip1>
            auto operator *=(const GMatrica<Tip1> &m) 
                -> GMatrica<decltype(this->matrica[0][0] * m.matrica[0][0])>;
        template <typename Tip1>
            auto operator *=(Tip1 skalar) 
                -> GMatrica<decltype(this->matrica[0][0] * skalar)>;
        
        template <typename Tip1, typename Tip2>
            friend bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
        template <typename Tip1, typename Tip2>
            friend bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);

        // operator []
        auto operator [](int i) -> typename std::add_lvalue_reference<decltype(matrica[0])>::type;
        auto operator [] (int i) const -> decltype(matrica[0]);
        
        //operator ()
        T operator ()(int i, int j) const;
        T &operator ()(int i, int j);
    };

template <typename Tip1>
    std::istream &operator >>(std::istream &tok, GMatrica<Tip1> &m) {
        char znak;
        int rows(0), cols(0);
        Tip1 unos;
        znak = tok.peek();
        //std::cout << "1";
        if (znak != '[') {
            tok.setstate(std::ios::failbit);
            return tok;
            //std::cout << "2";
        }
        tok >> znak;
        std::vector<int> v;
        while(1) {
            //std::cout << "u petlji sam";
            tok >> unos;
            if (!tok) return tok;
            //std::cout << "3";
            if (cols > 3 || rows > 3) {
                tok.setstate(std::ios::failbit);
                //std::cout << "4";
                break;
            }
            m.matrica[rows][cols] = unos;
            //std::cout <<"5";
            znak = tok.peek();
            if (znak == ',') {
                //std::cout <<"6";
                tok >> znak;
                cols++;
                continue;
            } else if (znak == ';') {
                //std::cout <<"7";
                tok >> znak;
                v.push_back(cols);
                cols = 0;
                rows++;
                continue;
            } else if (znak == ']') {
                //std::cout << "8";
                tok >> znak;
                v.push_back(cols);
                m.redova = rows + 1;
                m.kolona = cols + 1;
                bool a(false);
                for (auto x : v) if (x != v[0]) {a = true; break;}
                if (a) tok.setstate(std::ios::failbit);
                break;
            } else {
                //std::cout << "9";
                tok.setstate(std::ios::failbit);
                break;
            }
        }
        //std::cout << "10";
        return tok;
    }

template <typename T>
    auto GMatrica<T>::operator [] (int i) -> typename std::add_lvalue_reference<decltype(matrica[0])>::type {
        return matrica[i];
    }

template <typename T> 
    auto GMatrica<T>::operator [](int i) const -> decltype(matrica[0]) {
        return matrica[i];
    }

template <typename T>
    T &GMatrica<T>::operator ()(int i, int j) {
        if (i < 1 || j < 1 || i > this->redova || j > this->redova)
            throw std::range_error("Nedozvoljen indeks");
        return this->matrica[i-1][j-1];
    } 
    
template <typename T>
    T GMatrica<T>::operator ()(int i, int j) const {
        if (i < 1 || j < 1 || i > this->redova || j > this->kolona)
            throw std::range_error("Nedozvoljen indeks");
        return this->matrica[i-1][j-1];
    }

template <typename Tip1, typename Tip2>
    bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) {
        if (m1 == m2) return false;
        return true;
    }

template <typename Tip1, typename Tip2>
    bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) {
        bool a(m1.redova == m2.redova && m1.kolona == m2.kolona);
        if (!a) return false;
        a = true;
        for (int i = 0; i < m1.redova; i++) for (int j = 0; j < m1.kolona; j++) if (m1.matrica[i][j] != m2.matrica[i][j]) {a = false; break;}
        if (!a) return false;
        return true;
    }

template <typename T>
    template <typename Tip1>
        auto GMatrica<T>::operator -=(Tip1 skalar) -> GMatrica<decltype(this->matrica[0][0] - skalar)> {
            for (int i = 0; i < this->redova; i++) for (int j = 0; j < this->kolona; j++) this->matrica[i][j] -= skalar;
            return *this;
        }

template <typename T>
    template <typename Tip1>
        auto GMatrica<T>::operator +=(Tip1 skalar) -> GMatrica<decltype(this->matrica[0][0] + skalar)> {
            for (int i = 0; i < this->redova; i++) for (int j = 0; j < this->kolona; j++) this->matrica[i][j] += skalar;
            return *this;
        }

template <typename T>
    template <typename Tip1>
        auto GMatrica<T>::operator *= (const GMatrica<Tip1> &m) -> GMatrica<decltype(this->matrica[0][0] * m.matrica[0][0])> {
            if (this->kolona != m.redova) throw std::domain_error("Nedozvoljena operacija");
            typedef decltype(this->matrica[0][0] * m.matrica[0][0]) ReturnTip;
            GMatrica<ReturnTip> proizvod(this->redova, m.kolona);
            for (int i = 0; i < this->redova; i++) {
                for (int j = 0; j < m.kolona; j++) {
                    proizvod.matrica[i][j] = 0;
                    for (int k = 0; k < this->kolona; j++) 
                        proizvod.matrica[i][j] += this->matrica[i][k] * m.matrica[k][j];
                }
            }
            *this = proizvod;
            return *this;
        }

template <typename T>
    template <typename Tip1>
        auto GMatrica<T>::operator *=(Tip1 skalar) -> GMatrica<decltype(this->matrica[0][0] * skalar)> {
            for (int i = 0; i < this->redova; i++) for (int j = 0; j < this->kolona; j++) this->matrica[i][j] *= skalar;
            return *this;
        }

template <typename T>
    template <typename Tip1>
        auto GMatrica<T>::operator -=(const GMatrica<Tip1> &m) -> GMatrica<decltype(this->matrica[0][0] - m.matrica[0][0])> {
            if (!(this->redova == m.redova && this->kolona == m.kolona)) throw std::domain_error("Nedozvoljena operacija");
            for (int i = 0; i < m.redova; i++) for (int j = 0; j < m.kolona; j++) this->matrica[i][j] -= m.matrica[i][j];
            return *this;
        }

template <typename T>
    template <typename Tip1>
        auto GMatrica<T>::operator +=(const GMatrica<Tip1> &m) -> GMatrica<decltype(this->matrica[0][0] + m.matrica[0][0])> {
            if (!(this->redova == m.redova && this->kolona == m.kolona)) throw std::domain_error("Nedozvoljena operacija");
            for (int i = 0; i < m.redova; i++) for (int j = 0; j < m.kolona; j++) this->matrica[i][j] += m.matrica[i][j];
            return *this;
        }

template <typename Tip1, typename Tip2>
    auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])> {
        if (m1.kolona != m2.redova) throw std::domain_error("Nedozvoljena operacija");
        typedef decltype(m1.matrica[0][0] * m2.matrica[0][0]) ReturnTip;
        GMatrica<ReturnTip> proizvod(m1.redova, m2.kolona);
        for (int i = 0; i < m1.redova; i++) {
            for (int j = 0; j < m2.kolona; j++) {
                proizvod.matrica[i][j] = 0;
                for (int k = 0; k < m1.kolona; k++)
                    proizvod.matrica[i][j] += m1.matrica[i][k] * m2.matrica[k][j]; 
            }
        }
        return proizvod;
    }

template <typename Tip1, typename Tip2>
    auto operator *(const GMatrica<Tip1> &m, Tip2 skalar) -> GMatrica<decltype(skalar * m.matrica[0][0])> {
        typedef decltype(skalar * m.matrica[0][0]) ReturnTip;
        GMatrica<ReturnTip> proizvod(m.redova, m.kolona);
        for (int i = 0; i < m.redova; i++) for (int j = 0; j < m.kolona; j++) proizvod.matrica[i][j] = skalar * m.matrica[i][j];
        return proizvod;
    }

template <typename Tip1, typename Tip2>
    auto operator *(Tip1 skalar, const GMatrica<Tip2> &m) -> GMatrica<decltype(skalar * m.matrica[0][0])> {
        typedef decltype(skalar * m.matrica[0][0]) ReturnTip;
        GMatrica<ReturnTip> proizvod(m.redova, m.kolona);
        for (int i = 0; i < m.redova; i++) for (int j = 0; j < m.kolona; j++) proizvod.matrica[i][j] = skalar * m.matrica[i][j];
        return proizvod;
    }

template <typename Tip1>
    std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip1> &m) {
        int sirina(tok.width());
        if (sirina < 6) sirina = 6;
        for (int i = 0; i < m.redova; i++) {
            for (int j = 0; j < m.kolona; j++)
                tok << std::setw(sirina) << m.matrica[i][j];
            tok << std::endl;
        }
        return tok;
    }

template <typename Tip1, typename Tip2>
    auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])> {
        if (!(m1.redova == m2.redova && m1.kolona == m2.kolona))
            throw std::domain_error("Nedozvoljena operacija");
        typedef decltype(m1.matrica[0][0] + m2.matrica[0][0]) ReturnTip;
        GMatrica<ReturnTip> zbir(m1.redova, m1.kolona);
        for (int i = 0; i < zbir.redova; i++)
            for (int j = 0; j < zbir.kolona; j++)
                zbir.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
        return zbir;
    }

template <typename Tip1, typename Tip2>
    auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])> {
        if (!(m1.redova == m2.redova && m1.kolona == m2.kolona))
            throw std::domain_error("Nedozvoljena operacija");
        typedef decltype(m1.matrica[0][0] - m2.matrica[0][0]) ReturnTip;
        GMatrica<ReturnTip> razlika(m1.redova, m1.kolona);
        for (int i = 0; i < razlika.redova; i++)
            for (int j = 0; j < razlika.kolona; j++) 
                razlika.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
        return razlika;
    }
    
template <typename T>
    GMatrica<T>::GMatrica (std::vector<std::vector<T>> v) {
        int row(v.size());
        if (row < 0 || row > 4) throw std::logic_error("Ilegalan format matrice");
        int column(v[0].size());
        for (int i = 0; i < row; i++) if (v[i].size != column) throw std::logic_error("Ilegalan format matrice");
        redova = row;
        kolona = column;
        for (int i = 0; i < redova; i++) 
            for (int j = 0; j < kolona; j++) 
                matrica[i][j] = v[i][j];
    }

template <typename T>   
    GMatrica<T>::GMatrica() : redova(0), kolona(0) {}

template <typename T>
    GMatrica<T>::GMatrica (int redova, int kolona, T val) {
        if (redova < 0 || redova > 4 || kolona < 0 || kolona > 4)
            throw std::logic_error("Ilegalan format matrice");
        GMatrica<T>::redova = redova;
        GMatrica<T>::kolona = kolona;
        for (int i = 0; i < redova; i++)
            for (int j = 0; j < kolona; j++) 
                matrica[i][j] = val;
    }

template <typename T>
    template <typename Tip>
        GMatrica<T>::GMatrica (GMatrica<Tip> &m) {
            for (int i = 0; i < m.redova; i++) 
                for (int j = 0; j < m.kolona; j++) 
                    GMatrica::matrica[i][j] = static_cast<T>(m.matrica[i][j]);
            GMatrica::redova = m.redova;
            GMatrica::kolona = m.kolona;
        }

template <typename T>
    template <typename Tip>
        GMatrica<T>::GMatrica (Tip **niz) {
            for (int i = 0; i < 4; i++) 
                for (int j = 0; j < 4; j++) 
                    GMatrica::matrica[i][j] = niz[i][j];
            GMatrica::redova = 4;
            GMatrica::kolona = 4;
        }

template <typename T>
    template <typename Tip>
        GMatrica<T>::GMatrica (std::initializer_list<std::initializer_list<Tip>> m) {
            for (auto p(m.begin()), q(m.begin()); q != m.end(); q++)
                if (p->size() != q->size())
                    throw std::logic_error("Ilegalan format matrice");
            auto p(m.begin());
            redova = m.size();
            kolona = p->size();
            for (int i = 0; i < redova; i++, p++) {
                auto q(p->begin());
                for (int j = 0; j < kolona; j++, q++)
                    matrica[i][j] = *q;
            }
        }


int main () {
    
   //operatori << i >>
   
   GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;
   return 0;
}