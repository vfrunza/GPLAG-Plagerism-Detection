/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <iomanip>

template <typename Tip>
class GMatrica
{
    Tip elementi[4][4];
    int broj_redova, broj_kolona;
public:
    GMatrica() ;
    GMatrica(int broj_redova, int broj_kolona, Tip x=Tip());
    template <typename Tip1>
    GMatrica(const GMatrica<Tip1>&m);
    template <typename Tip1>
    GMatrica(Tip1 niz[4][4]);
    GMatrica(const std::vector<std::vector<Tip>> &v);
    GMatrica( std::initializer_list<std::vector<Tip>> m);

    int DajBrojRedova()const {
        return broj_redova;
    }
    int DajBrojKolona()const {
        return broj_kolona;
    }
    template<typename Tip1>
    friend std::ostream &operator <<(std::ostream &tok,const GMatrica<Tip1> &m);
    template <typename Tip1, typename Tip2>
    friend auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] + m2.elementi[0][0]) >;
    template <typename Tip1, typename Tip2>
    friend auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] - m2.elementi[0][0]) >;
    template <typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] * m2.elementi[0][0]) >;
    template <typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &m, Tip2 x)->GMatrica < decltype(m.elementi[0][0] * x) >;
    template <typename Tip1, typename Tip2>
    friend auto operator *(Tip2 x, const GMatrica<Tip1> &m)->GMatrica < decltype(m.elementi[0][0] * x) >;
    template <typename Tip1, typename Tip2>
    friend auto operator +=(GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] + m2.elementi[0][0]) >;
    template <typename Tip1, typename Tip2>
    friend auto operator -=(GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] - m2.elementi[0][0]) > ;
    template <typename Tip1, typename Tip2>
    friend auto operator *=(GMatrica<Tip1> &m1, Tip2 x)->GMatrica < decltype(m1.elementi[0][0] * x) >;
    template <typename Tip1, typename Tip2>
    friend auto operator *=(GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] * m2.elementi[0][0]) > ;
    template <typename Tip1, typename Tip2>
    friend bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
    template <typename Tip1, typename Tip2>
    friend bool operator!= (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2);
    Tip operator ()(int broj_redova, int broj_kolona) const;
    Tip &operator ()(int broj_redova, int broj_kolona);
    Tip* &operator [](int broj_redova)const;
    Tip* operator [](int broj_redova);
    template<typename Tip1>
    friend std::istream &operator >>(std::istream &tok, GMatrica<Tip1> &m);
};
template<typename Tip>
GMatrica<Tip>::GMatrica()
{
    broj_redova=0;
    broj_kolona=0;
}
template<typename Tip>
GMatrica<Tip>::GMatrica(int broj_redova, int broj_kolona, Tip x)
{
    if(broj_redova<0 || broj_redova>4 ||broj_kolona>4 || broj_kolona<0) throw std::logic_error("Ilegalan format matrice");
    GMatrica::broj_kolona=broj_kolona;
    GMatrica::broj_redova=broj_redova;
    for(int i=0; i<broj_redova; i++) {
        for(int j=0; j<broj_kolona; j++) {
            elementi[i][j]=x;
        }
    }

}
template<typename Tip>template<typename Tip1> GMatrica<Tip>::GMatrica(const GMatrica<Tip1>&m)
{
    if(m.broj_redova<0 || m.broj_kolona<0 || m.broj_redova>4 || m.broj_kolona>4) throw std::logic_error("Ilegalan format matrica");
    GMatrica::broj_kolona=m.broj_kolona;
    GMatrica::broj_redova=m.broj_redova;
    for(int i=0; i<broj_redova; i++) {
        for(int j=0; j<broj_kolona; j++) {
            elementi[i][j]=m.elementi[i][j];
        }
    }
}
template<typename Tip>template<typename Tip1> GMatrica<Tip>::GMatrica(Tip1 niz[4][4])
{
    GMatrica::broj_kolona=4;
    GMatrica::broj_redova=4;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            elementi[i][j]=niz[i][j];
        }
    }
}

template<typename Tip>
GMatrica<Tip>::GMatrica(const std::vector<std::vector<Tip>> &v)
{
    if(v.size()<0 || v[0].size()<0 || v.size()>4|| v[0].size()>4) throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(v[i].size()!=v[j].size()) throw std::logic_error("Ilegalan format matrice");
        }
    }
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[0].size(); j++) {
            elementi[i][j]=v[i][j];
        }
    }
    GMatrica::broj_redova=v.size();
    GMatrica::broj_kolona=v[0].size();
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::vector<Tip>> lista)
{
    GMatrica::broj_kolona=lista.begin()->size();
    GMatrica::broj_redova=lista.size();
    auto it=lista.begin();
    for(int i=0; i<lista.size(); i++) {
        int k(0);
        for(int j=0; j<lista.begin()->size(); j++) {
            elementi[i][j]=(*it)[k];
            k++;
        }
        it++;
    }

}
template<typename Tip>
std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip>&m)
{
    std::streamsize n;
    if(tok.width()<6) n=6;
    else n=tok.width();
    for(int i=0; i<m.broj_redova; i++) {
        for(int j=0; j<m.broj_kolona; j++) {
            tok<<std::setw(n)<<m.elementi[i][j];
        }
        tok<<std::endl;
    }
    return tok;

}
template <typename Tip1, typename Tip2>
auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] + m2.elementi[0][0]) > {
    if (m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.elementi[0][0] + m2.elementi[0][0])> mat(m1.DajBrojRedova(), m1.DajBrojKolona());
    for (int i=0; i < m1.DajBrojRedova(); i++) {
        for (int j=0; j < m1.DajBrojKolona(); j++) {
            mat.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return mat;
}
template <typename Tip1, typename Tip2>
auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] - m2.elementi[0][0]) > {
    if (m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.elementi[0][0] - m2.elementi[0][0])> mat(m1.DajBrojRedova(), m1.DajBrojKolona());
    for (int i=0; i < m1.DajBrojRedova(); i++) {
        for (int j=0; j < m1.DajBrojKolona(); j++) {
            mat.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
        }
    }
    return mat;
}

template<typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.elementi[0][0]*m2.elementi[0][0])> {
    if (m1.DajBrojKolona() != m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.elementi[0][0]*m2.elementi[0][0])> mat(m1.DajBrojRedova(), m2.DajBrojKolona());
    for (int i=0; i < m1.DajBrojKolona(); i++) {
        for (int j=0; j < m2.DajBrojKolona(); j++) {
            for(int k=0; k<m2.DajBrojRedova(); k++) {
                mat.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return mat;
}
template <typename Tip1, typename Tip2>
auto operator +=(GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] + m2.elementi[0][0]) > {
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m1.DajBrojKolona(); j++) {
            m1.elementi[i][j]+=m2.elementi[i][j];
        }
    }
    return m1;
}
template <typename Tip1, typename Tip2>
auto operator -=(GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] - m2.elementi[0][0]) > {
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m1.DajBrojKolona(); j++) {
            m1.elementi[i][j]-=m2.elementi[i][j];
        }
    }
    return m1;
}
template <typename Tip1, typename Tip2>
auto operator *=(GMatrica<Tip1> &m1, Tip2 x)->GMatrica < decltype(m1.elementi[0][0] * x) > {
    for (int i=0; i < m1.DajBrojRedova(); i++)
        for (int j=0; j < m1.DajBrojKolona(); j++)
            m1.elementi[i][j] *=x;
    return m1;
}

template <typename Tip1, typename Tip2>
auto operator *=(GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica < decltype(m1.elementi[0][0] * m2.elementi[0][0]) > {
    if (m1.DajBrojKolona() != m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica < decltype(m1.elementi[0][0] * m2.elementi[0][0])> mat(m1.DajBrojRedova(), m2.DajBrojKolona());
    for (int i=0; i < m1.DajBrojKolona(); i++)
        for (int j=0; j < m2.DajBrojKolona(); j++)
            for (int k=0; k < m2.DajBrojRedova(); k++)
                mat.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
    m1 = mat;
    return m1;
}
template <typename Tip1, typename Tip2>
auto operator *(Tip2 x, const GMatrica<Tip1> &m)->GMatrica < decltype(m.elementi[0][0] * x) > {
    return m*x;
}

template <typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1> &m, Tip2 x)->GMatrica < decltype(m.elementi[0][0] * x) > {
    GMatrica<decltype(m.elementi[0][0] * x)> mat(m.DajBrojRedova(), m.DajBrojKolona());
    for (int i=0; i < m.DajBrojRedova(); i++)
        for (int j=0; j < m.DajBrojKolona(); j++)
            mat.elementi[i][j] = m.elementi[i][j] * x;
    return mat;
}
template <typename Tip1, typename Tip2>
bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
{
    int isti(0);
    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m1.DajBrojKolona(); j++) {
            if(m1.elementi[i][j]==m2.elementi[i][j]) isti=1;
            else {
                isti=0;
                break;
            }
        }
    }
    if(isti) return 1;
    return 0;
}

template <typename Tip1, typename Tip2>
bool operator!= (const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)
{
    return !(m1==m2);
}
template<typename Tip>
Tip  &GMatrica<Tip>::operator ()(int broj_redova, int broj_kolona)
{
    if(broj_redova>GMatrica<Tip>::broj_redova || broj_redova<1 || broj_kolona>GMatrica<Tip>::broj_kolona || broj_kolona<1) throw std::range_error("Nedozvoljen indeks");
    return elementi[broj_redova-1][broj_kolona-1];
}
template<typename Tip>
Tip  GMatrica<Tip>::operator ()(int broj_redova, int broj_kolona) const
{
    if(broj_redova>DajBrojRedova() || broj_redova<1 || broj_kolona>DajBrojKolona() || broj_kolona<1) throw std::range_error("Nedozvoljen indeks");
    return elementi[broj_redova-1][broj_kolona-1];
}
template <typename Tip>
Tip* &GMatrica<Tip>::operator [](int broj_redova) const
{
    return elementi[broj_redova];
}

template <typename Tip>
Tip* GMatrica<Tip>::operator [](int broj_redova)
{
    return elementi[broj_redova];
}
template<typename Tip1>
std::istream &operator >>(std::istream &tok,  GMatrica<Tip1> &m)
{
    char znak;
    tok >> std::ws;
    tok>>znak;
    if(znak!='[') tok.setstate(std::ios::failbit);
    Tip1 x;
    int i(0), j(0);
    if(m.broj_redova==0 && m.broj_kolona==0) {
        for(;;) {
            tok>>x>>znak;
            m[i][j]=x;
            if(znak!=',') {
                m.broj_redova++;
                i++;
                j=0;
            }
            if(znak==',') {
                j++;
                m.broj_kolona++;
            }
            if(znak==']') break;
            if(znak!=',' && znak!=';' && znak!=']') tok.setstate(std::ios::failbit);

        }
    } else {
        int br(0), br2(0);
        for(;;) {
            Tip1 x;
            tok>>x>>znak;
            m.elementi[i][j]=x;
            if(znak!=',') {
                br++;
                i++;
                j=0;
            }
            if(znak==',') {
                j++;
                br2++;
            }
            if(znak==']') break;
            if(br!=m.broj_redova-1 && br2!=m.broj_kolona-1) tok.setstate(std::ios::failbit);
            if(znak!=',' && znak!=';' && znak!=']') tok.setstate(std::ios::failbit);

        }
    }
    return tok;
}

int main ()
{
    return 0;
}