/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <vector>
#include <iomanip>


template <typename TipEl>
class GMatrica
{
    TipEl matrica[4][4];
    int broj_redova;
    int broj_kolona;

public:
    GMatrica () : broj_redova(0), broj_kolona(0) {}
    GMatrica(int broj_redova, int broj_kolona,TipEl element = {}) {
        if (broj_kolona < 0 or broj_kolona > 4 or broj_redova > 4 or broj_redova < 0) throw std::logic_error ("Ilegalan format matrice");
        GMatrica::broj_kolona = broj_kolona;
        GMatrica::broj_redova = broj_redova;
        for (int i = 0; i < broj_redova; i++) {
            for (int j = 0; j < broj_kolona; j++) {
                matrica[i][j] = element;
            }
        }
    }
    template <typename TipEl2>
    GMatrica (const GMatrica<TipEl2> &m2) {

        broj_kolona = m2.broj_kolona;
        broj_redova = m2.broj_redova;
        for (int i = 0; i < broj_redova; i++) {
            for (int j = 0; j < broj_kolona; j++) {
                matrica[i][j] = m2.matrica[i][j];
            }
        }
    }
    GMatrica (const GMatrica &m2) {

        broj_kolona = m2.broj_kolona;
        broj_redova = m2.broj_redova;
        for (int i = 0; i < broj_redova; i++) {
            for (int j = 0; j < broj_kolona; j++) {
                matrica[i][j] = m2.matrica[i][j];
            }
        }
    }
    GMatrica (GMatrica &&m2) {

        broj_kolona = m2.broj_kolona;
        broj_redova = m2.broj_redova;
        for (int i = 0; i < broj_redova; i++) {
            for (int j = 0; j < broj_kolona; j++) {
                matrica[i][j] = m2.matrica[i][j];
            }
        }
    }
    template <typename TipEl2>
    GMatrica (const TipEl2 m2[4][4]) : broj_redova(4), broj_kolona(4) {
        for (int i = 0; i < broj_redova; i++) {
            for (int j = 0; j < broj_kolona; j++) {
                matrica[i][j] = m2[i][j];
            }
        }
    }
    GMatrica(const std::vector<std::vector<TipEl>> &mat) {
        if (mat.size() > 4 or mat.size() < 0) throw std::logic_error ("Ilegalan format matrice");
        int test(0);
        bool flag(true);
        for (auto &i : mat) {
            if (flag) {
                test = i.size();
                flag = false;
            } else if (test != i.size() or i.size() < 0 or i.size() > 4) throw std::logic_error ("Ilegalan format matrice");
        }
        broj_redova = mat.size();
        broj_kolona = test;
        for (int i = 0; i < broj_redova; i++) {
            for (int j = 0; j < broj_kolona; j++) {
                matrica[i][j] = mat[i][j];
            }
        }
    }
    
    GMatrica(std::initializer_list<std::initializer_list<TipEl>> t) {
        if (t.size() > 4 or t.size() < 0) throw std::logic_error ("Ilegalan format matrice");
        int test;
        bool flag(true);
        for (auto &i : t) {
            if (flag) {
                test = i.size();
                flag = false;
            } else if (test != i.size() or i.size() < 0 or i.size() > 4) throw std::logic_error ("Ilegalan format matrice");
        }
        broj_redova = t.size();
        broj_kolona = test;
        int k(0), j(0);
        for (auto &i : t) {
            j = 0;
            for (auto &i2 : i) {
                matrica[k][j] = i2;
                j++;
            }
            k++;
        }
    }
    int DajBrojRedova() const {
        return broj_redova;
    }
    int DajBrojKolona() const {
        return broj_kolona;
    }
    template <typename TipEl2>
    GMatrica<TipEl> &operator += (const GMatrica<TipEl2> &mat2) {
        if(broj_redova != mat2.broj_redova || broj_kolona != mat2.broj_kolona)
            throw std::domain_error("Nedozvoljena operacija");
        for(int i = 0; i < broj_redova; i++)
            for(int j = 0; j < broj_kolona; j++)
                matrica[i][j] += mat2.matrica[i][j];
        return *this;
    }
    template <typename TipEl2>
    GMatrica<TipEl> &operator *= (TipEl2 broj) {
        for(int i = 0; i < broj_redova; i++)
            for(int j = 0; j < broj_kolona; j++)
                matrica[i][j] *= broj;
        return *this;
    }
    template <typename TipEl2>
    GMatrica<TipEl> &operator -= (const GMatrica<TipEl2> &mat2) {
        if(broj_redova != mat2.broj_redova || broj_kolona != mat2.broj_kolona)
            throw std::domain_error("Nedozvoljena operacija");
        for(int i = 0; i < broj_redova; i++)
            for(int j = 0; j < broj_kolona; j++)
                matrica[i][j] -= mat2.matrica[i][j];
        return *this;
    }
    
    template <typename TipEl2>
    GMatrica<TipEl> &operator *= (const GMatrica<TipEl2> &mat2) {
        if (broj_kolona != mat2.broj_redova)
            throw std::domain_error("Nedozvoljena operacija");
        for(int i = 0; i < broj_redova; i++)
            for(int j = 0; j < mat2.broj_kolona; j++)
                matrica[i][j] *= mat2.matrica[i][j];
        return *this;
    }
    TipEl &operator () (int i, int j) {
        if (i < 1 or i > broj_redova or j < 1 or j > broj_kolona) throw std::range_error ("Nedozvoljenindeks");
        return matrica[i-1][j-1];
    }
    TipEl operator () (int i, int j) const {
        if (i < 1 or i > broj_redova or j < 1 or j > broj_kolona) throw std::range_error ("Nedozvoljenindeks");
        return matrica[i][j];
    }
    TipEl* operator [] (int index) const {
        return matrica[index];
    }
    TipEl* operator [] (int index) {
        return matrica[index];
    }


    template <typename TipEl2>
    friend std::istream &operator >>(std::istream &tok, GMatrica<TipEl2> &m);

    template <typename TipEl2>
    friend std::ostream &operator << (std::ostream &tok, const GMatrica<TipEl2> &m);

    template <typename Tip1, typename Tip2 >
    friend bool operator == (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);

    template <typename Tip1, typename Tip2 >
    friend bool operator != (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);

    template <typename Tip1, typename Tip2>
    friend GMatrica<decltype(Tip1() + Tip2())> operator - (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);

    template <typename Tip1, typename Tip2 >
    friend GMatrica<decltype(Tip1() + Tip2())> operator + (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);

    template <typename Tip1, typename Tip2>
    friend GMatrica<decltype(Tip1() * Tip2())> operator * (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);

    template <typename Tip1, typename Tip2>
    friend GMatrica<decltype(Tip1() * Tip2())> operator * (const GMatrica<Tip1> &m1, Tip2 broj);
    template <typename Tip1, typename Tip2>
    friend GMatrica<decltype(Tip1() * Tip2())> operator * (Tip1 broj,const GMatrica<Tip2> &m1);
};

template <typename Tip1, typename Tip2>
    GMatrica<decltype(Tip1() * Tip2())> operator * (const GMatrica<Tip1> &m1, Tip2 broj) {
        GMatrica<decltype(Tip1() * Tip2())> m3(m1.broj_redova, m1.broj_kolona);
        for(int i = 0; i < m1.broj_redova; i++)
            for(int j = 0; j < m1.broj_kolona; j++)
                m3.matrica[i][j] = m1.matrica[i][j]*broj;
        return m3;
    }
template <typename Tip1, typename Tip2>
    GMatrica<decltype(Tip1() * Tip2())> operator * (Tip1 broj,const GMatrica<Tip2> &m1) {
        GMatrica<decltype(Tip1() * Tip2())> m3(m1.broj_redova, m1.broj_kolona);
        for(int i = 0; i < m1.broj_redova; i++)
            for(int j = 0; j < m1.broj_kolona; j++)
                m3.matrica[i][j] = m1.matrica[i][j]*broj;
        return m3;
    }
template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const GMatrica<TipEl> &m)
{
    int sirina(std::cout.width());
    if (sirina < 6) sirina = 6;
    for(int i = 0; i < m.DajBrojRedova(); i++) {
        for(int j = 0; j < m.DajBrojKolona(); j++) {
            tok << std::setw(sirina) << m.matrica[i][j];
        }
        tok << std::endl;
    }
    return tok;
}

template <typename TipEl>
std::istream &operator >>(std::istream &tok, GMatrica<TipEl> &m)
{
    char znak;
    tok >> znak;
    TipEl broj;
    int i(0), j(0);
    if (znak != '[') tok.setstate(std::ios::failbit);
    while (1) {
        tok >> broj >> znak;
        m.matrica[i][j] = broj;
        j++;
        if (znak == ']')  {i++; break;}
        else if (znak == ';' or i > 3 or j > 3) {
            i++;
            j = 0;
        } else if (znak != ',') tok.setstate(std::ios::failbit);
    }
    
    m.broj_redova = i;
    m.broj_kolona = j;
    if (znak != ']') tok.setstate(std::ios::failbit);
    return tok;
}

template <typename Tip1, typename Tip2 >
bool operator == (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
{
    if (m1.broj_kolona != m2.broj_kolona or m1.broj_redova != m2.broj_redova) return false;

    for (int i = 0; i < m1.broj_redova; i++) {
        for (int j = 0; j < m1.broj_kolona; j++) {
            if (m1.matrica[i][j] != m2.matrica[i][j]) return false;
        }
    }
    return true;
}

template <typename Tip1, typename Tip2 >
bool operator != (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
{
    if (m1.broj_kolona != m2.broj_kolona or m1.broj_redova != m2.broj_redova) return true;

    for (int i = 0; i < m1.broj_redova; i++) {
        for (int j = 0; j < m1.broj_kolona; j++) {
            if (m1.matrica[i][j] != m2.matrica[i][j]) return true;
        }
    }
    return false;
}

template <typename Tip1, typename Tip2>
GMatrica<decltype(Tip1() + Tip2())> operator + (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
{
    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(Tip1() + Tip2())> m3 (m1.broj_redova, m1.broj_kolona);
    for(int i = 0; i < m1.broj_redova; i++)
        for(int j = 0; j < m1.broj_kolona; j++)
            m3.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
    return m3;
}

template <typename Tip1, typename Tip2>
GMatrica<decltype(Tip1() + Tip2())> operator - (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
{
    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(Tip1() - Tip2())> m3(m1.broj_redova, m1.broj_kolona);
    for(int i = 0; i < m1.broj_redova; i++)
        for(int j = 0; j < m1.broj_kolona; j++)
            m3.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
    return m3;
}

template <typename Tip1, typename Tip2>
GMatrica<decltype(Tip1() + Tip2())> operator * (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
{
    if (m1.broj_kolona != m2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(Tip1() * Tip2())> m3(m1.broj_redova, m2.broj_kolona);
    for (int i = 0; i < m1.broj_redova; i++) {
        for (int j = 0; j < m2.broj_kolona; j++) {
            decltype(Tip1() * Tip2()) suma {};
            for (int k = 0; k < m1.broj_kolona; k++) {
                suma+= m1.matrica[i][k]*m2.matrica[k][j];
            }
            m3.matrica[i][j] = suma;
        }
    }
    return m3;
}


int main ()
{
   GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;
}