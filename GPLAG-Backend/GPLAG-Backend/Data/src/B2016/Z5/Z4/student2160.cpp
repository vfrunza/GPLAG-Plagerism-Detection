/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
template<typename tip>
class GMatrica
{
    tip mat[4][4];
    int redovi, kolone;
public:
    GMatrica() : redovi(0), kolone(0) {}
    GMatrica(int br, int bk, tip el = {});
    template<typename tip2>
    GMatrica(GMatrica<tip2> mat2);
    GMatrica(tip niz[4][4]);
    template<typename tip2>
    GMatrica(std::initializer_list<std::initializer_list<tip2>> l);

    GMatrica(std::vector<std::vector<tip>> vek);
    int DajBrojRedova() const { return redovi; }
    int DajBrojKolona() const { return kolone; }
    template<typename tip1, typename tip2>
    friend auto operator + (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2) -> GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] + m2.mat[0][0])>::type>;
    template<typename tip1, typename tip2>
    friend auto operator - (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2) -> GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] - m2.mat[0][0])>::type>;

    
    auto operator * (double a) -> GMatrica<typename std::remove_reference<decltype(tip() * double())>::type>
    {
        GMatrica<typename std::remove_reference<decltype(mat[0][0] * double())>::type> m3(DajBrojRedova(), DajBrojKolona());
        for(int i = 0; i < DajBrojRedova(); i++)
            for(int j = 0; j < DajBrojKolona(); j++)
                m3.mat[i][j] = mat[i][j] * a;
        return m3;
    }
    template<typename tip1>
    friend auto operator * (double a, const GMatrica<tip1> &m1) -> GMatrica<typename std::remove_reference<decltype(double() * tip1())>::type>
;
        template<typename tip1>
     auto operator * (const GMatrica<tip1> &m2) -> GMatrica<typename std::remove_reference<decltype(mat[0][0] * m2.mat[0][0])>::type>
    {
        if(DajBrojKolona() != m2.DajBrojRedova())
            throw std::domain_error("Nedozvoljena operacija");
    		
        GMatrica<typename std::remove_reference<decltype(mat[0][0] * m2.mat[0][0])>::type> m3(DajBrojRedova(), m2.DajBrojKolona());
    	
        for(int i = 0; i < DajBrojRedova(); i++)
            for(int j = 0; j < m2.DajBrojKolona(); j++)
                for(int k = 0; k < DajBrojRedova(); k++)
                    m3.mat[i][j] += mat[i][k] * m2.mat[k][j];
    				
    	return m3;
    } 
    template<typename tip2>
    GMatrica &operator += (const GMatrica<tip2> &m2);
    template<typename tip2>
    GMatrica &operator -= (const GMatrica<tip2> &m2);
    template<typename tip2>
    GMatrica &operator *= (const GMatrica<tip2> &m2)
    {
        if(kolone != m2.DajBrojRedova())
    		throw std::domain_error("Nedozvoljena operacija");
    		
    	GMatrica<tip> m3 = *this;
    	for(int i = 0; i < redovi; i++)
    		for(int j = 0; j < m2.DajBrojKolona(); j++)
    			for(int k = 0; k < redovi; k++)
    				m3[i][j] += *this[i][k] * m2[k][j];
    				
    	*this = m3;
    	return *this;
    }
    GMatrica &operator *= (double a)
    {
 
        for(int i = 0; i < DajBrojRedova(); i++)
            for(int j = 0; j < DajBrojKolona(); j++)
                mat[i][j] = mat[i][j] * a;
        return *this;
    }
    template<typename tip1, typename tip2>
    friend bool operator == (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2);
    template<typename tip1, typename tip2>
    friend bool operator != (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2);
    tip &operator () (int a, int b)
    {
        if(a <= 0 || b <= 0)
            throw std::range_error("Nedozvoljen indeks");
            
        return mat[a - 1][b - 1];
    }
    tip operator () (int a, int b) const
    {
        if(a <= 0 || b <= 0)
            throw std::range_error("Nedozvoljen indeks");
            
        return mat[a - 1][b - 1];
    }
    const tip *operator [] (int a) const  { return mat[a]; }
    template<typename tip2>
    friend std::ostream &operator << (std::ostream &tok, const GMatrica<tip2> &m);
    template<typename tip2>
    friend std::istream &operator >> (std::istream &tok, GMatrica<tip2> &m);
    
    
        template<typename Tip2>
    friend class GMatrica;
    
    
};
template<typename tip>
GMatrica<tip>::GMatrica(int br, int bk, tip el) : redovi(br), kolone(bk)
{
    if(br < 0 || bk < 0 || br > 4 || bk > 4)
        throw std::logic_error("Ilegalan format matrice");
            
    for(int i = 0; i < br; i++)
        for(int j = 0; j < bk; j++)
            mat[i][j] = el;
}

template<typename tip>
template<typename tip2>
GMatrica<tip> :: GMatrica(GMatrica<tip2> m)
{
    redovi = m.DajBrojRedova();
    kolone = m.DajBrojKolona();
    
    for(int i = 0; i < m.DajBrojRedova(); i++)
        for(int j = 0; j < m.DajBrojKolona(); j++)
            mat[i][j] = m[i][j];
}
template<typename tip>
GMatrica<tip>::GMatrica(tip niz[4][4])
{
    redovi = 4;
    kolone = 4;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            mat[i][j] = niz[i][j];
}
template<typename tip>
GMatrica<tip>::GMatrica(std::vector<std::vector<tip>> vek)
{
    redovi = vek.size();
    kolone = vek.at(0).size();
    
    for(int i = 1; i < vek.size(); i++)
        if(vek.size() > 4 || vek.at(0).size() != vek.at(i).size() || vek.at(i).size() > 4)
            throw std::logic_error("Ilegalan format matrice");
                
    for(int i = 0; i < vek.size(); i++)
        for(int j = 0; j < vek.at(i).size(); j++)
            mat[i][j] = vek.at(i).at(j);
}
template<typename tip>
template<typename tip2>
GMatrica<tip>::GMatrica(std::initializer_list<std::initializer_list<tip2>> l) 
{
    if(l.size() > 4)
        throw std::logic_error("Ilegalan format matrice");
        
    if(l.size() > 0)
    {
        for(auto i : l)
            if(i.size() != (*l.begin()).size() || i.size() > 4)
                throw std::logic_error("Ilegalan format matrice");
    }
    redovi = 0;
    kolone = 0;
    for(auto i : l)
    {
        kolone = 0;
        for(auto s : i)
        {
            mat[redovi][kolone] = s;
            kolone++;
        }
        redovi++;
    }
}
template<typename tip1, typename tip2>
auto operator + (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2) -> GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] + m2.mat[0][0])>::type>
{
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
        
    GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] + m2.mat[0][0])>::type> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
    for(int i = 0; i < m1.DajBrojRedova(); i++)
        for(int j = 0; j < m1.DajBrojKolona(); j++)
            m3.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
            
    return m3;
}
template<typename tip1, typename tip2>
auto operator - (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2) -> GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] - m2.mat[0][0])>::type>
{
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
        
    GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] - m2.mat[0][0])>::type> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
    for(int i = 0; i < m1.DajBrojRedova(); i++)
        for(int j = 0; j < m1.DajBrojKolona(); j++)
            m3.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];
            
    return m3;
}
//template<typename tip1, typename tip2>
//auto operator * (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2) -> GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] * m2.mat[0][0])>::type>

//template<typename tip1>
//auto operator * (const GMatrica<tip1> &m1, double a) -> GMatrica<typename std::remove_reference<decltype(tip1() * double())>::type>

    
template<typename tip>
template<typename tip2>
GMatrica<tip>& GMatrica<tip>::operator += (const GMatrica<tip2> &m2)
{
    if(redovi != m2.DajBrojRedova() || kolone != m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
        
    for(int i = 0; i < redovi; i++)
        for(int j = 0; j < kolone; j++)
            this->mat[i][j] += m2.mat[i][j];
    return *this;
}
template<typename tip>
template<typename tip2>
GMatrica<tip>& GMatrica<tip>::operator -= (const GMatrica<tip2> &m2)
{
    if(redovi != m2.DajBrojRedova() || kolone != m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
        
    for(int i = 0; i < redovi; i++)
        for(int j = 0; j < kolone; j++)
            this->mat[i][j] -= m2.mat[i][j];
    return *this;
}
//template<typename tip>
//template<typename tip2>
//GMatrica<tip>& GMatrica<tip>::operator *= (const GMatrica<tip2> &m2)

template<typename tip1, typename tip2>
bool operator == (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)
{
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");

    for(int i = 0; i < m1.DajBrojRedova(); i++)
        for(int j = 0; j < m1.DajBrojKolona(); j++)
            if(m1[i][j] != m2[i][j])
                return false;
                
    return true;
}
template<typename tip1, typename tip2>
bool operator != (const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)
{
    if(m1.DajBrojKolona() != m2.DajBrojKolona() || m1.DajBrojRedova() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
        
    return !(m1 == m2);
}
template<typename tip2>
std::ostream &operator << (std::ostream &tok, const GMatrica<tip2> &m)
{
    int a = tok.width() < 6 ? 6 : tok.width();
    for(int i = 0; i < m.DajBrojRedova(); i++)
    {
        for(int j = 0; j < m.DajBrojKolona(); j++)
            tok << std::setw(a) << m[i][j];
        tok << std::endl;
    }
    return tok;
}
    template<typename tip1>
    auto operator * (double a, const GMatrica<tip1> &m1) -> GMatrica<typename std::remove_reference<decltype(double() * tip1())>::type>
    {
        GMatrica<typename std::remove_reference<decltype(m1.mat[0][0] * double())>::type> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
        for(int i = 0; i < m1.DajBrojRedova(); i++)
            for(int j = 0; j < m1.DajBrojKolona(); j++)
                m3.mat[i][j] = m1.mat[i][j] * a;
        return m3;
        
        }
template<typename tip2>
std::istream &operator >> (std::istream &tok, GMatrica<tip2> &m)
{
    char znak;
    tok >> std::ws;
    tok >> znak;
    if(znak != '[')
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    for (int j = 0; j < 4; j++)
    {
        m.kolone = 0;
        for(int i = 0; i < 4; i++)
        {
            tip2 br; 
            char z;
            tok >> br >> z;
            if (tok && z == ';') {break;}
            if(!tok || (z != ',' && z != ';'))
            {
                tok.setstate(std::ios::failbit);
                return tok;
            }
            else if(z == ',')
                m.mat[m.redovi][m.kolone++] = br;
        }
        if (!tok) break;
        m.redovi++;
    }
    char z2;
    tok >> z2;
    if(z2 != ']')
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    return tok;
}
int main ()
{ 
    GMatrica<int> m;
    std::cin >> m;
    if (!std::cin) std::cout << "Neispravno";
    else std::cout << m;
   /* GMatrica<int> m1({{1, 2}, {3, 4}});
   GMatrica<int> m2({{1, 2}, {3, 4}});
   std::cout <<  m1 << std::endl;
   m1 += m2;
   std::cout <<  m1 << std::endl;
   m1 -= m2; 
   std::cout <<  m1 << std::endl;
   m1 *= 2;
   std::cout <<  m1 << std::endl;
   return 0;*/
}