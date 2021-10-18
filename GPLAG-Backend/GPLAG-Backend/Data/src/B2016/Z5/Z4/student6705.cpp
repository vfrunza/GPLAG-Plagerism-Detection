/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
#include <string>

template <typename Tip>
class GMatrica
{
    Tip matrica[4][4];
    int BrojRedova = 0;
    int BrojKolona = 0;
    void ProvjeriDimenziju(int redovi, int kolone);
    int VratiBroj(std::string s)
    {
        int suma(0), kolicnik(1);
        
        for(int i(s.size() - 1);; i--)
        {
            if(s[0] == '-')
                if(i == 0)
                    break;
            if(i < 0)
                break;
            suma += (s[i] - 48) * kolicnik;
            kolicnik *= 10;
        }
        if(s[0] == '-')
            return -suma;
        else
            return suma;
    }
public:
    GMatrica() {}
    explicit GMatrica(int){}
    GMatrica(int r, int k, Tip element = 0);
    template<typename Tip2>
    GMatrica(const GMatrica<Tip2>& mat);
    GMatrica(Tip niz[4][4]);
    GMatrica(const std::vector<std::vector<Tip>>& v);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> lista);
    int DajBrojRedova() const{
        return BrojRedova;
    }
    int DajBrojKolona() const{
        return BrojKolona;
    }
    
    template<typename Tip1, typename Tip2>
    friend auto operator +(const GMatrica<Tip1>& m1, const GMatrica<Tip2>& m2) -> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>;
    template<typename Tip1, typename Tip2>
    friend auto operator -(const GMatrica<Tip1>& m1, const GMatrica<Tip2>& m2) -> GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])>;
    template<typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1>& m1, const GMatrica<Tip2>& m2) -> GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>;
    
    template<typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1>& m1, Tip2 broj) -> GMatrica<decltype(m1[0][0] * broj)>;
    template<typename Tip1, typename Tip2>
    friend auto operator *(Tip1 broj, const GMatrica<Tip2>& m1) -> GMatrica<decltype(m1[0][0] * broj)>;
    
    template<typename Tip2>
    friend bool operator ==(const GMatrica<Tip2>& m1, const GMatrica<Tip2>& m2);
    template<typename Tip2>
    friend bool operator !=(const GMatrica<Tip2>& m1, const GMatrica<Tip2>& m2);
    template<typename Tip2>
    friend std::ostream& operator <<(std::ostream& Itok, const GMatrica<Tip2>& m1);
    template<typename Tip2>
    friend std::istream& operator >>(std::istream& Utok, GMatrica<Tip2>& m1);
 
    template<typename Tip2>
    GMatrica<Tip>& operator +=(const GMatrica<Tip2>& m2);
    template<typename Tip2>
    GMatrica<Tip>& operator -=(const GMatrica<Tip2>& m2);
    template<typename Tip2>
    GMatrica<Tip>& operator *=(const GMatrica<Tip2>& m2);
    template<typename Tip2>
    GMatrica<Tip>& operator *=(Tip2 broj);
    
    Tip& operator () (int r, int k);
    Tip operator () (int r, int k) const;
    Tip* operator [](int r);
    const Tip* operator [](int r) const;
    
};
template<typename Tip1>
void GMatrica<Tip1>::ProvjeriDimenziju(int r, int k)
{
    if(r < 0 || k < 0 || r > 4 || k > 4)
        throw std::logic_error("Ilegalan format matrice");
}
template<typename Tip1>
GMatrica<Tip1>::GMatrica(int r, int k, Tip1 element): BrojRedova(r), BrojKolona(k)
{
    ProvjeriDimenziju(r, k);
    for(int i(0); i < BrojRedova; i++)
        for(int j(0); j < BrojKolona; j++)
            matrica[i][j] = element;
}
template<typename Tip1>
template<typename Tip2>
GMatrica<Tip1>::GMatrica(const GMatrica<Tip2>& mat)
{
    BrojRedova = mat.BrojRedova;
    BrojKolona = mat.BrojKolona;
    for(int i(0); i < BrojRedova; i++)
        for(int j(0); j < BrojKolona; j++)
            matrica[i][j] = mat.matrica[i][j];
}
template<typename Tip>
GMatrica<Tip>::GMatrica(Tip niz[4][4])
{
    BrojKolona = 4; BrojRedova = 4;
    for(int i(0); i < BrojRedova; i++)
        for(int j(0); j < BrojKolona; j++)
            matrica[i][j] = niz[i][j];
}
template<typename Tip>
GMatrica<Tip>::GMatrica(const std::vector<std::vector<Tip>>& v)
{
    BrojKolona = v[0].size(); BrojRedova = v.size();
    ProvjeriDimenziju(BrojRedova, BrojKolona);
    
    for(int i(0); i < BrojRedova; i++)
        for(int j(0); j < BrojKolona; j++)
        {
            if(v[i].size() != v[0].size())
                throw std::logic_error("Ilegalan format matrice");
            matrica[i][j] = v[i][j];
        }
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista)
{
    BrojRedova = lista.size();
    BrojKolona = lista.begin()->size();
    ProvjeriDimenziju(BrojRedova, BrojKolona);
    int r = 0, k = 0;
    for(auto i(lista.begin()); i != lista.end(); i++)
    {
        k = 0;
        for(auto j(i->begin()); j != (i->end()); j++)
        {
            if(BrojKolona != i->size())
                throw std::logic_error("Ilegalan format matrice");
            matrica[r][k] = (*j);
            k++;
        }
        r++;
    }
}
template<typename Tip1, typename Tip2>
auto operator +(const GMatrica<Tip1>& m1, const GMatrica<Tip2>& m2) -> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>
{
    if(m1.DajBrojKolona() != m2.DajBrojKolona() || m1.DajBrojRedova() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])> pomocna(m1);
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            pomocna.matrica[i][j] += m2.matrica[i][j];
    return pomocna;
}
template<typename Tip1, typename Tip2>
auto operator -(const GMatrica<Tip1>& m1, const GMatrica<Tip2>& m2) -> GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])>
{
    if(m1.DajBrojKolona() != m2.DajBrojKolona() || m1.DajBrojRedova() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])> pomocna(m1);
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            pomocna.matrica[i][j] -= m2.matrica[i][j];
    return pomocna;
}
template<typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1>& m1, const GMatrica<Tip2>& m2) -> GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>
{
    if(m1.DajBrojKolona() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])> pomocna(m1.DajBrojRedova(), m2.DajBrojKolona());
    for(int i(0); i < m1.DajBrojRedova(); i++)
    {
        for(int j(0); j < m2.DajBrojKolona(); j++)
        {
            decltype(m1.matrica[0][0] * m2.matrica[0][0]) s{};
            for(int k(0); k < m1.DajBrojKolona(); k++)
                s += m1.matrica[i][k] * m2.matrica[k][j];
            pomocna.matrica[i][j] = s;
        }
    }
    return pomocna;
}
template<typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1>& m1, Tip2 broj) -> GMatrica<decltype(m1[0][0]*broj)>
{
    GMatrica<decltype(m1[0][0] * broj)> pomocna(m1);
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            pomocna[i][j] *= broj;
    return pomocna;
}
template<typename Tip1, typename Tip2>
auto operator *(Tip1 broj, const GMatrica<Tip2>& m1) -> GMatrica<decltype(m1[0][0] * broj)>
{
    GMatrica<decltype(broj * m1[0][0])> pomocna(m1);
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            pomocna[i][j] *= broj;
    return pomocna;
}
template<typename Tip1>
template<typename Tip2>
GMatrica<Tip1>& GMatrica<Tip1>::operator +=(const GMatrica<Tip2>& m2)
{
    if(this->DajBrojKolona() != m2.DajBrojKolona() || this->DajBrojRedova() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    for(int i(0); i < this->DajBrojRedova(); i++)
        for(int j(0); j < this->DajBrojKolona(); j++)
            this->matrica[i][j] += m2.matrica[i][j];
    return *this;
}
template<typename Tip1>
template<typename Tip2>
GMatrica<Tip1>& GMatrica<Tip1>::operator -=(const GMatrica<Tip2>& m2)
{
    if(this->DajBrojKolona() != m2.DajBrojKolona() || this->DajBrojRedova() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    for(int i(0); i < this->DajBrojRedova(); i++)
        for(int j(0); j < this->DajBrojKolona(); j++)
            this->matrica[i][j] -= m2.matrica[i][j];
    return *this;
}
template<typename Tip1>
template<typename Tip2>
GMatrica<Tip1>& GMatrica<Tip1>::operator *=(const GMatrica<Tip2>& m2)
{
    if(this->DajBrojKolona() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip1> pomocna(*this);
    this->BrojKolona = m2.DajBrojKolona();
    for(int i(0); i < pomocna.DajBrojRedova(); i++)
    {
        for(int j(0); j < m2.DajBrojKolona(); j++)
        {
            Tip1 s{};
            for(int k(0); k < pomocna.DajBrojKolona(); k++)
                s += pomocna.matrica[i][k] * m2.matrica[k][j];
            this->matrica[i][j] = s;
        }
    }
    return *this; 
}
template<typename Tip1>
template<typename Tip2>
GMatrica<Tip1>& GMatrica<Tip1>::operator *=(Tip2 broj)
{
    for(int i(0); i < this->DajBrojRedova(); i++)
        for(int j(0); j < this->DajBrojKolona(); j++)
            this->matrica[i][j] *= broj;
    return *this;
}
template<typename Tip2>
bool operator !=(const GMatrica<Tip2>& m1, const GMatrica<Tip2>& m2)
{
    if(m1.DajBrojKolona() != m2.DajBrojKolona() || m1.DajBrojRedova() != m2.DajBrojRedova())
        return true;
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            if(m1.matrica[i][j] != m2.matrica[i][j])
                return true;
    return false;
}
template<typename Tip2>
bool operator ==(const GMatrica<Tip2>& m1, const GMatrica<Tip2>& m2)
{
    return !(m1 != m2);
}
template<typename Tip1>
Tip1& GMatrica<Tip1>::operator () (int r, int k)
{
    if(r < 1 || k < 1 || r > DajBrojRedova() || k > DajBrojKolona())
        throw std::range_error("Nedozvoljen indeks");
    return matrica[r - 1][k - 1];
}
template<typename Tip1>
Tip1 GMatrica<Tip1>::operator () (int r, int k) const
{
    if(r < 1 || k < 1 || r > DajBrojRedova() || k > DajBrojKolona())
        throw std::range_error("Nedozvoljen indeks");
    return matrica[r - 1][k - 1];
}
template<typename Tip1>
Tip1* GMatrica<Tip1>::operator [](int r)
{
    return matrica[r];
}
template<typename Tip1>
const Tip1* GMatrica<Tip1>::operator [](int r) const
{
    return matrica[r];
}
template<typename Tip2>
std::ostream& operator <<(std::ostream& Itok, const GMatrica<Tip2>& m1)
{
    auto sirina(Itok.width());
    if(sirina < 6)
        sirina = 6;
    for(int i(0); i < m1.DajBrojRedova(); i++)
    {
        for(int j(0); j < m1.DajBrojKolona(); j++)
            Itok << std::setw(sirina) << m1.matrica[i][j];
        Itok << std::endl;
    }
    return Itok;
}
template<typename Tip2>
std::istream& operator >>(std::istream& Utok, GMatrica<Tip2>& m1)
{
    char c;
    Utok >> c;
    if(c != '['){
        Utok.setstate(std::ios::failbit);
        return Utok;
    }
    Tip2 broj; int red = 0;
    std::vector<std::vector<Tip2>> v;
    v.push_back(std::vector<Tip2>());
    while(c != ']' || c == EOF)
    {
        Utok >> broj >> c;
        v[red].push_back(broj);
        if(c == ';'){
            red++;
            v.push_back(std::vector<Tip2>());
        }
        if(!Utok.good())
            return Utok;
    }
    if(c != ']'){
        Utok.setstate(std::ios::failbit);
        return Utok;
    }
    GMatrica<Tip2> temp(v);
    m1 = temp;
    return Utok;
    
}
int main ()
{
    GMatrica<int> m1({{1, 2}, {3, 4}});
    GMatrica<int> m2({{1, 2}, {3, 4}});
    GMatrica<int> m3({{2, 5}, {7, 5}});
    if(m1 == m2) std::cout << "Matrice su iste" << std::endl;
    if(m1 != m2) std::cout << "Matrice su razlicite" << std::endl;
    std::cout << "Matrica m1:" << std::endl << std::setw(3) << m1; 
    std::cout << "Matrica m2:" << std::endl << std::setw(3) << m2; 
    std::cout << "Matrica m3:" << std::endl << std::setw(3) << m3;
    try
    {
        auto p1(m1 + m3);
        auto p2(m3 - m2);
        m1 += m2;
        m2 -= m3;
        std::cout << std::endl;
        std::cout << "M1 + M3: " << std::endl << p1 << std::endl;
        std::cout << "M3 - M2: " << std::endl << p2 << std::endl;
        std::cout << "M1 + M2: " << std::endl << m1 << std::endl;
        std::cout << "M2 - M3: " << std::endl << m2 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << std::endl;
        auto p3(m1 * m2);
        std::cout << "M1 + M2: " << std::endl << p3 << std::endl;
        m3 *= m2;
        std::cout << "M3 + M2: " << std::endl << m3 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
     try
    {
        std::cout << std::endl;
        m1 *= 2;
        std::cout << "M1 *= 2: " << std::endl << m1 << std::endl;
        std::cout << m1(1,1) << std::endl;
        std::cout << m1[1][1] << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
   
	return 0;
}