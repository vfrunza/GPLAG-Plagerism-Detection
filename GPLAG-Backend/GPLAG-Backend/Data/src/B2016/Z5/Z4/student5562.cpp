/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <iomanip>

template <typename Tip>
    class GMatrica
    {
        Tip elementi[4][4];
        int br_redova, br_kolona;
    public:
        GMatrica():br_redova(0), br_kolona(0){}
        GMatrica(int br_redova, int br_kolona, Tip vrijednost = Tip());
        template <typename Tip2>
            GMatrica(const GMatrica<Tip2> &m);
        template <typename Tip2>
            GMatrica(Tip2** elementi);
        GMatrica(const std::vector<std::vector<Tip>> &m);
        GMatrica(const std::initializer_list<std::initializer_list<Tip>> &lista);
        int DajBrojRedova()const{ return br_redova;}
        int DajBrojKolona()const{ return br_kolona;}
        template <typename Tip1, typename Tip2>
            friend GMatrica<decltype(Tip1() + Tip2())> operator+(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
        template <typename Tip1, typename Tip2>
            friend GMatrica<decltype (Tip1() - Tip2())> operator-(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
        template <typename Tip1, typename Tip2>
            friend GMatrica<decltype (Tip1() * Tip2())> operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
        template <typename Tip1>
            friend GMatrica<Tip1> operator *(const GMatrica<Tip1> &m, double x);
        template <typename Tip1>
            inline friend GMatrica<Tip1> operator*(double x, const GMatrica<Tip1> &m){return m*x;}
        template <typename Tip1>
            GMatrica<decltype(Tip() + Tip1())>& operator +=(const GMatrica<Tip1> &m);
        GMatrica& operator += (double x);
        template <typename Tip1>
            GMatrica<decltype(Tip() - Tip1())>& operator -=(const GMatrica<Tip1> &m);
        GMatrica& operator -= (double x);
        template <typename Tip1>
            GMatrica& operator*=(const GMatrica<Tip1> &m); 
        GMatrica &operator *=(double x);
        template <typename Tip1>
            friend bool operator == (const GMatrica<Tip1> &m1, const GMatrica<Tip1> &m2);
        template <typename Tip1>
            inline friend bool operator != (const GMatrica<Tip1> &m1, const GMatrica<Tip1> &m2){ return !(m1 == m2);}
        Tip& operator()(int i, int j);
        Tip operator()(int i, int j)const;
        Tip* operator[](int i){ return elementi[i];}
        Tip* operator[](int i)const{return elementi[i];}
        template<typename Tip1>
            friend std::ostream &operator << (std::ostream &tok, const GMatrica<Tip1> &m);
        template<typename Tip1>
            friend std::istream &operator >> (std::istream &tok, GMatrica<Tip1> &m);
    };

template <typename Tip>
    GMatrica<Tip>::GMatrica(int br_redova, int br_kolona, Tip vrijednost)
    {
        if (br_redova < 0 || br_redova > 4 || br_kolona < 0 || br_kolona > 4)
            throw std::logic_error("Ilegalan format matrice");
        GMatrica::br_redova = br_redova; GMatrica::br_kolona = br_kolona;
        for (int i = 0; i < br_redova; i++)
            for (int j = 0; j< br_kolona; j++)
                elementi[i][j] = vrijednost;
    }
template<typename Tip>
    template <typename Tip2>
        GMatrica<Tip>::GMatrica(const GMatrica<Tip2> &m)
        {
            for (int i = 0; i < m.br_redova; i++)
                std::copy(m.elementi[i], m.elementi[i] + m.br_kolona, elementi[i]);
            br_redova = m.br_redova; br_kolona = m.br_kolona;
        }
template <typename Tip>
    template <typename Tip2>
        GMatrica<Tip>::GMatrica(Tip2** elementi)
        {
            for (int i = 0; i < 4; i++)
                std::copy(elementi[i], elementi[i] + 4, GMatrica::elementi);
            br_kolona = br_redova = 4;
        }
template <typename Tip>
    GMatrica<Tip>::GMatrica(const std::vector<std::vector<Tip>> &m)
    {
        if (m.size() > 4)
            throw std::logic_error("Ilegalan format matrice");
        for (int i = 0; i < m.size(); i++)
            if (m[i].size() > 4 || m[i].size() != m[0].size())
                throw std::logic_error("Ilegalan format matrice");
        for (int i = 0; i < m.size(); i++)
            std::copy(m[i].begin(), m[i].end(), elementi[i]);
        br_redova = m.size();
        br_kolona = m[0].size();
    }
template <typename Tip>
    GMatrica<Tip>::GMatrica(const std::initializer_list<std::initializer_list<Tip>> &lista)
    {
        if (lista.size() > 4)
            throw std::logic_error("Ilegalan format matrice");
        for (auto lista2:lista)
            if (lista2.size() > 4 || lista2.size() != lista.begin()->size())
                throw std::logic_error("Ilegalan format matrice");
        int i(0);
        for (auto l:lista)
            std::copy(l.begin(),  l.end(), elementi[i++]);
        br_redova = lista.size();
        br_kolona = lista.begin()->size();
    }
template <typename Tip1, typename Tip2>
    GMatrica<decltype (Tip1() + Tip2())> operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
    {
        if (m1.br_kolona != m1.br_kolona || m1.br_redova != m2.br_redova)
            throw std::domain_error("Nedozvoljena operacija");
        typedef decltype (Tip1() + Tip2()) Tip3;
        GMatrica<Tip3> zbir(m1.br_redova, m1.br_kolona);
        for (int i = 0; i < m1.br_redova; i++)
            for (int j = 0; j < m1.br_kolona; j++)
                zbir.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return zbir;
    }
template <typename Tip1, typename Tip2>
    GMatrica<decltype (Tip1() - Tip2())> operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
    {
        if (m1.br_kolona != m1.br_kolona || m1.br_redova != m2.br_redova)
            throw std::domain_error("Nedozvoljena operacija");
        typedef decltype (Tip1() - Tip2()) Tip3;
        GMatrica<Tip3> razlika(m1.br_redova, m1.br_kolona);
        for (int i = 0; i < m1.br_redova; i++)
            for (int j = 0; j < m1.br_kolona; j++)
                razlika.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
        return razlika;
    }
template <typename Tip1, typename Tip2>
    GMatrica<decltype (Tip1() * Tip2())> operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
    {
        if (m1.br_kolona != m2.br_redova)
            throw std::domain_error("Nedozvoljena operacija");
        typedef decltype (Tip1() * Tip2()) Tip3;
        GMatrica<Tip3> produkt(m1.br_redova, m2.br_kolona);
        for (int i = 0; i < m1.br_redova; i++)
            for (int j = 0; j < m2.br_kolona; j++)
                for (int k = 0; k < m2.br_redova; i++)
                    produkt.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
        return produkt;
        
    }
template <typename Tip1>
    GMatrica<Tip1> operator *(const GMatrica<Tip1> &m, double x)
    {
        GMatrica<Tip1> produkt(m.br_redova, m.br_kolona);
        for (int i = 0; i < m.br_redova; i++)
            for (int j = 0; j < m.br_kolona; j++)
                produkt.elementi[i][j] = m.elementi[i][j]*x;
        return produkt;
    }
template <typename Tip>
    template <typename Tip1>
        GMatrica<decltype(Tip() + Tip1())>& GMatrica<Tip>::operator +=(const GMatrica<Tip1> &m)
        {
            if (br_kolona != m.br_kolona || br_redova != m.br_redova)
                throw std::domain_error("Nedozvoljena operacija");
            for (int i = 0; i < br_redova; i++)
                for (int j = 0; j < br_kolona; j++)
                    elementi[i][j] += m.elementi[i][j];
            return *this;
        }
template<typename Tip>
    template <typename Tip1>
        GMatrica<decltype(Tip() - Tip1())>& GMatrica<Tip>::operator -=(const GMatrica<Tip1> &m)
        {
            if (br_kolona != m.br_kolona || br_redova != m.br_redova)
                throw std::domain_error("Nedozvoljena operacija");
            for (int i = 0; i < br_redova; i++)
                for (int j = 0; j< br_kolona; j++)
                    elementi[i][j] -= m.elementi[i][j];
            return *this;
        }
template<typename Tip>
    GMatrica<Tip>& GMatrica<Tip>::operator +=(double x) 
    {
        for (int i = 0; i < br_redova; i++)
            for (int j = 0; j < br_kolona; j++)
                elementi[i][j] += x;
        return *this;
    }
template<typename Tip>
    GMatrica<Tip>& GMatrica<Tip>::operator -=(double x)
    {
        for (int i = 0; i < br_redova; i++)
            for (int j = 0; j< br_kolona; j++)
                elementi[i][j] -= x;
        return *this;
    }
template<typename Tip>
    template <typename Tip1>
        GMatrica<Tip>& GMatrica<Tip>::operator*=(const GMatrica<Tip1> &m)
        {
            if (br_kolona != m.br_redova)
                throw std::domain_error("Nedozvoljena operacija");
            typedef decltype(Tip() * Tip1()) Tip3;
            GMatrica<Tip3> produkt(br_redova, m.br_kolona);
            for (int i = 0; i < br_redova; i++)
                for (int j = 0; j < m.br_kolona; j++)
                    for (int k = 0; k < m.br_redova; k++)
                        produkt.elementi[i][j] += elementi[i][k]*m.elementi[k][j];
        *this = produkt;
        return *this;
        }
template<typename Tip>
    GMatrica<Tip>& GMatrica<Tip>::operator*=(double x)
    {
        for (int i = 0; i < br_redova; i++)
            for (int j = 0; j < br_redova; j++)
                elementi[i][j] *= x;
        return *this;
    }
template<typename Tip>
    bool operator == (const GMatrica<Tip> &m1, const GMatrica<Tip> &m2)
    {
        if (m1.br_kolona != m2.br_kolona || m1.br_redova != m2.br_redova)
            return false;
        for (int i = 0; i < m1.br_redova; i++)
            if (!std::equal(m1.elementi[i], m1.elementi[i] + m1.br_kolona, m2.elementi[i]))
                return false;
        return true;
    }
template <typename Tip>
    Tip& GMatrica<Tip>::operator()(int i, int j)
    {
        if (i < 1 || i > br_redova || j < 1 || j > br_kolona)
            throw std::range_error("Nedozvoljen indeks");
        return elementi[i - 1][j - 1];
    }
template <typename Tip>
    Tip GMatrica<Tip>::operator()(int i, int j)const
    {
        if (i < 1 || i > br_redova || j < 1 || j > br_kolona)
            throw std::range_error("Nedozvoljen indeks");
        return elementi[i - 1][j - 1];
    }
template <typename Tip>
    std::ostream &operator << (std::ostream &tok, const GMatrica<Tip> &m)
    {
        int sirina;
        if (tok.width() < 6) sirina = 6;
        else sirina = tok.width();
        for (int i = 0; i < m.br_redova; i++)
        {
            for (int j = 0; j < m.br_kolona; j++)
                tok << std::setw(sirina) << m.elementi[i][j];
            tok << std::endl;
        }
        return tok;
    }
template <typename Tip>
    std::istream &operator >> (std::istream &tok, GMatrica<Tip> &m)
    {
        GMatrica<Tip> pomocna;
        bool greska(false);
        if (tok.peek() != '[') greska = true;
        else
        {
            tok.get();
            int i(0), j(0);
            for (;;)
            {
                char z(tok.peek());
                if (!(z >= '0' && z <= '9')){greska = true; break;}
                tok >> pomocna.elementi[i][j++];
                if (tok.peek() == ';'){
                    if (i > 0 && j != pomocna.br_kolona){greska = true; break;}
                    pomocna.br_kolona = j; j = 0; i++;
                }
                else if (tok.peek() == ']'){
                    if (i > 0 && j != pomocna.br_kolona) 
                        greska = true; break;
                }
                else if (tok.peek() != ','){
                    greska = true; break; 
                }
                tok.get();
            }
        }
        pomocna.br_kolona = 2; pomocna.br_redova = 2;
        if (greska) tok.setstate(std::ios::failbit);
        else m = pomocna;
        return tok;
    }
    
int main ()
{
    return 0;
}