/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

template<typename T>
class GMatrica
{
    T matrica[4][4];
    int redova, kolona;
  public:
    GMatrica();
    GMatrica(int redova, int kolona, T defaultna = T{});
    template<typename T2>
    GMatrica(const GMatrica<T2>& gm);
    template<typename T2>
    GMatrica(T2 matr[4][4]);//bzvz
    template<typename T2>
    GMatrica(const std::vector<std::vector<T2> >& vv);
    template<typename T2>
    GMatrica(std::initializer_list<std::initializer_list<T2> > il);
    template<typename T2>
    GMatrica<T>& operator+=(GMatrica<T2> m);
    template<typename T2>
    GMatrica<T>& operator+=(T2 br);
    template<typename T2>
    GMatrica<T>& operator-=(T2 br);
    template<typename T1, typename T2>
    friend auto operator+(GMatrica<T1> m1, GMatrica<T2> m2)->GMatrica<decltype(T1()+T2())>;
    template<typename T2>
    GMatrica<T>& operator-=(GMatrica<T2> m);
    template<typename T1, typename T2>
    friend auto operator-(GMatrica<T1> m1, GMatrica<T2> m2)->GMatrica<decltype(T1()-T2())>;
    template<typename T2>
    GMatrica<T>& operator*=(GMatrica<T2> m);
    template<typename T1, typename T2>
    friend auto operator*(GMatrica<T1> m1, GMatrica<T2> m2)->GMatrica<decltype(T1()*T2())>;
    template<typename T1, typename T2>
    friend auto operator*(GMatrica<T1> m1, T2 broj)->GMatrica<decltype(T1()*T2())>;
    template<typename T1, typename T2>
    friend auto operator*(T1 broj, GMatrica<T2> gm)->GMatrica<decltype(T1()*T2())>;
    template<typename T1>
    GMatrica<T>& operator*=(T1 broj);
    template<typename T1>
    friend bool operator==(GMatrica<T1> m1, GMatrica<T1> m2);
    template<typename T1>
    friend bool operator!=(GMatrica<T1> m1, GMatrica<T1> m2);
    int DajBrojRedova()const{return redova;}
    int DajBrojKolona()const{return kolona;}
    T operator()(int i, int j)const;
    T& operator()(int i, int j);
    T* operator[](int ind){return matrica[ind];}
    const T* const operator[](int ind)const{return matrica[ind];}
    template<typename TIP>
    friend std::ostream& operator<<(std::ostream& out, GMatrica<TIP> gm);
    template<typename TIP>
    friend std::istream& operator>>(std::istream& in, GMatrica<TIP>& gm);
};

template<typename T>
GMatrica<T>::GMatrica()
{
    redova = kolona = 0;
}
template<typename T>
GMatrica<T>::GMatrica(int redova, int kolona, T def)
{
    if( redova < 0 || redova > 4 || kolona < 0 || kolona > 4)
        throw std::logic_error("Ilegalan format matrice");
    GMatrica::redova = redova;
    GMatrica::kolona = kolona;
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++)
            matrica[i][j] = def;
}
template<typename T>
template<typename T2>
GMatrica<T>::GMatrica(const GMatrica<T2>& gm)
{
    redova = gm.DajBrojRedova();
    kolona = gm.DajBrojKolona();
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++)
            matrica[i][j] = gm(i+1,j+1);
}
template<typename T>
template<typename T2>
GMatrica<T>::GMatrica(T2 m[4][4])//bzvz
{
    redova = kolona = 4;
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++)
            matrica[i][j] = m[i][j];
}
template<typename T>
template<typename T2>
GMatrica<T>::GMatrica(const std::vector<std::vector<T2> >& vv)
{
    bool iyuyetak = false;
    redova = kolona = 0;
    if(vv.size() == 0 ) return;
    if(vv.size() > 4 || vv.size() < 0) iyuyetak = true;
    else if(vv.size() != 0)
    {
        int b = vv[0].size();
        for(auto& e: vv) if(e.size() != b) iyuyetak = true;
        for(int i=0;i<vv.size();i++)
            for(int j=0;j<b;j++)
                matrica[i][j] = vv[i][j];
    }
    if(iyuyetak) 
        throw std::logic_error("Ilegalan format matrice");
    redova = vv.size();
    if(redova != 0) kolona = vv[0].size();
}
template<typename T>
template<typename T2>
GMatrica<T>::GMatrica(std::initializer_list<std::initializer_list<T2>> il)
{
    redova = kolona = 0;
    if(il.size() == 0) return;
    int brel = -1;
    if(il.size() < 0 || il.size() > 4)
        throw std::logic_error("Ilegalan format matrice");
    for(auto e: il) 
    {
        if(brel == -1) brel = e.size();
        else if(brel != e.size() || e.size() > 4)
            throw std::logic_error("Ilegalan format matrice");
    }
    if(brel == -1) brel = 0;
    auto it1 = il.begin();
    for(int i=0; i<il.size(); i++)
    {
        auto it2 = it1->begin();
        for(int j=0;j<it1->size();j++) matrica[i][j] = *it2++;
        it1++;
    }
    redova = il.size();
    kolona = brel;
}
template<typename T>
template<typename T2>
GMatrica<T>& GMatrica<T>::operator+=(GMatrica<T2> m)
{
    if(redova != m.DajBrojRedova() || kolona != m.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++) matrica[i][j] += m(i+1,j+1);
    return *this;
}
template<typename T>
template<typename T2>
GMatrica<T>& GMatrica<T>::operator+=(T2 broj)
{
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++)
            matrica[i][j] += broj;
}
template<typename T>
template<typename T2>
GMatrica<T>& GMatrica<T>::operator-=(T2 broj)
{
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++)
            matrica[i][j] -= broj;
}
template<typename T1, typename T2>
auto operator+(GMatrica<T1> m1, GMatrica<T2> m2)->GMatrica<decltype(T1()+T2())>
{
    typedef decltype(T1()+T2()) GM;
    if(m1.redova != m2.redova || m1.kolona != m2.kolona)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<GM> rez(m1.redova, m1.kolona);
    for(int i=0;i<rez.redova;i++)
        for(int j=0;j<rez.kolona;j++)
            rez.matrica[i][j] = GM(m1.matrica[i][j]) + GM(m2.matrica[i][j]);
    return rez;
}
template<typename T>
template<typename T2>
GMatrica<T>& GMatrica<T>::operator-=(GMatrica<T2> m)
{
    if(redova != m.DajBrojRedova() || kolona != m.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++) matrica[i][j] -= m(i+1,j+1);
    return *this;
}
template<typename T1, typename T2>
auto operator-(GMatrica<T1> m1, GMatrica<T2> m2)->GMatrica<decltype(T1()-T2())>
{
    typedef decltype(T1()+T2()) GM;
    if(m1.redova != m2.redova || m1.kolona != m2.kolona)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<GM> rez(m1.redova, m1.kolona);
    for(int i=0;i<rez.redova;i++)
        for(int j=0;j<rez.kolona;j++)
            rez.matrica[i][j] = GM(m1.matrica[i][j]) - GM(m2.matrica[i][j]);
    return rez;
}
template<typename T>
template<typename T2>
GMatrica<T>& GMatrica<T>::operator*=(GMatrica<T2> m2)
{
    if(DajBrojKolona() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<T> rez(redova, m2.kolona);
    for(int i=0;i<redova;i++)
    for(int j=0;j<m2.kolona;j++)
    {
        rez.matrica[i][j] = T();
        for(int k=0;k<kolona;k++) rez(i+1,j+1) += this->operator()(i+1,k+1) * m2(k+1,j+1);
    }
    return *this = rez;
}
template<typename T1, typename T2>
auto operator*(GMatrica<T1> m1, GMatrica<T2> m2)->GMatrica<decltype(T1()*T2())>
{
    typedef decltype(T1() * T2()) tip;
    if(m1.DajBrojKolona() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<tip> rez(m1.redova, m2.kolona);
    for(int i=0;i<m1.redova;i++)
    for(int j=0;j<m2.kolona;j++)
    {
        rez.matrica[i][j] = tip();
        for(int k=0;k<m1.kolona;k++) rez(i+1,j+1) += m1(i+1,k+1) * m2(k+1,j+1);
    }
    return rez;
}
template<typename T>
std::istream& operator>>(std::istream& in, GMatrica<T>& matr)
{
    GMatrica<T> gm;
    bool ok = true;
    gm.redova = gm.kolona = 0;
    char x;
    T broj;
    int R = 0, C = 0;
    std::cin >> x;
    if(x != '[') ok = false;
    else
    {
        if(in.peek() == ']') return in;
        for(;;)
        {
            int tren = 0;
            for(;;)
            {
                tren++;
                in >> broj >> x;
                if(!in) return in;
                gm.matrica[R][tren-1] = broj;
                if(x == ';') {if(R==0) C++; break;}
                else if(x == ',')
                {
                    if(R == 0) C++;
                    if(R == 0 && C > 3)
                    {
                        in.setstate(std::ios::failbit);
                        return in;
                    }
                }
                else 
                {
                    if(x == ']' && (tren == C || R == 0)) {if(R==0)C++; R++; goto label;}
                    in.setstate(std::ios::failbit);
                    return in;
                }
                if(R != 0 && C == tren && x == ',')
                {
                    in.setstate(std::ios::failbit);
                    return in;
                }
            }
            R++;
            if(R == 4) 
            {
                in.setstate(std::ios::failbit);
                return in;
            }
        }
    }
    label:
    gm.redova = R;
    gm.kolona = C;
    matr = gm;
    return in;
}

template<typename T1, typename T2>
auto operator*(GMatrica<T1> m1, T2 broj)->GMatrica<decltype(T1()*T2())>
{
    GMatrica<decltype(T1()*T2())> rez(m1.redova, m1.kolona);
    for(int i=0;i<m1.redova;i++)
    {
        for(int j=0;j<m1.kolona;j++) rez.matrica[i][j] = broj * m1.matrica[i][j];
    }
    return rez;
}
template<typename T1, typename T2>
auto operator*(T1 broj, GMatrica<T2> gm)->GMatrica<decltype(T1()*T2())>
{
    return gm * broj;
}
template<typename T>
template<typename T1>
GMatrica<T>& GMatrica<T>::operator*=(T1 broj)
{
    for(int i=0;i<redova;i++)
        for(int j=0;j<kolona;j++)
            matrica[i][j] *= broj;
    return *this;
}
template<typename T1>
bool operator==(GMatrica<T1> m1, GMatrica<T1> m2)
{
    if(m1.redova != m2.redova || m1.kolona != m2.kolona)
        return false;
    for(int i=0;i<m1.redova;i++)
        for(int j=0;j<m1.kolona;j++)
            if(m1.matrica[i][j]!=m2.matrica[i][j]) return false;
    return true;
}
template<typename T1>
bool operator!=(GMatrica<T1> m1, GMatrica<T1> m2)
{
    return !(m1 == m2);
}
template<typename T>
T GMatrica<T>::operator()(int i, int j)const
{
    if( i > redova || i < 1 || j > kolona || j < 1)
        throw std::range_error("Neispravan indeks");
    return matrica[i-1][j-1];
}
template<typename T>
T& GMatrica<T>::operator()(int i, int j)
{
    if( i > redova || i < 1 || j > kolona || j < 1)
        throw std::range_error("Neispravan indeks");
    return matrica[i-1][j-1];
}
template<typename T>
std::ostream& operator<<(std::ostream& out, GMatrica<T> gm)
{
    int sirina = std::max((long)6, (long)out.width());
    for(int i=0;i<gm.redova;i++)
    {
        for(int j=0;j<gm.kolona;j++) out<< std::setw(sirina)<<gm.matrica[i][j];
        out << "\n";
    }
    return out;
}
int main ()
{
    GMatrica<long double> m1(3,3);
  
    std::vector<std::vector<double> > vv(3);
    GMatrica<int> m2;
    std::cin>> m2; 
    const GMatrica<int> gm(3,3);
    gm(3,3);
    std::cout<< gm[0][0]<<"\n";
    m2 * m2;
    GMatrica<double> m(m2);
    std::cout<< m2.DajBrojKolona()<<m2.DajBrojRedova()<<"-\n";
    std::cout<< std::setw(7)<< (m2);
	return 0;
}
