/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <type_traits>

template <typename tip>
class GMatrica{
        tip m[4][4];
        int row, col;
    public:
    GMatrica();
    GMatrica(int row, int col, tip val = tip());
    template<typename blah>
    GMatrica(const GMatrica<blah> &m2);
    template<typename tip2>
    GMatrica(const tip2 mat[4][4]);
    GMatrica(const std::vector<std::vector<tip>> &v);
    GMatrica(const std::initializer_list<std::initializer_list<tip>> &l);
    tip DajBrojRedova()const{ return row; }
    tip DajBrojKolona()const{ return col; }
    template<typename tip1,typename tip2>
    friend auto operator+(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2)->
     GMatrica<typename std::remove_reference<decltype(m2.m[0][0] +m1.m[0][0])>::type>;
     
    template<typename tip1,typename tip2>
    friend auto operator-(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2)->
    GMatrica<typename std::remove_reference<decltype(m2.m[0][0]-m1.m[0][0])>::type>;
    
    template<typename tip1,typename tip2>
    friend auto operator*(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2)->
    GMatrica<typename std::remove_reference<decltype(m2.m[0][0]*m1.m[0][0])>::type>;
    
    template<typename tip1,typename tip2>
    friend auto operator*( GMatrica<tip1> m1, tip2 n)->
    GMatrica<typename std::remove_reference<decltype(m1.m[0][0]*n)>::type>;
    
    template<typename tip1, typename tip2>
    friend auto operator*(tip2 n,  GMatrica<tip1> m1)->
    GMatrica<typename std::remove_reference<decltype(m1.m[0][0]*n)>::type>;
    //////
    template<typename tip1>
    GMatrica &operator*=(const GMatrica<tip1> &m1);
    
    template<typename tip1>
    GMatrica &operator*=(tip1 x);
    
    template<typename tip1>
    GMatrica &operator-=(const GMatrica<tip1> &m1);
    
    template<typename tip1>
    GMatrica &operator+=(const GMatrica<tip1> &m1);
    
    template<typename tip1>
    bool operator==(const GMatrica<tip1> &m1)const;
    
    template<typename tip1>
    bool operator!=(const GMatrica<tip1> &m1)const;
    
    tip operator()(int x, int y)const;
    tip &operator()(int x, int y);
    
    const tip* operator[](int x)const;
    tip* operator[](int x);
    
    template<typename tip1>
    friend std::ostream &operator<<(std::ostream &tok, const GMatrica<tip1> &m);
    
    template<typename tip1>
    friend std::istream &operator>>(std::istream &tok, GMatrica<tip1> &m1);
};
bool white(char c){
    return (c == ' ' || c == '\n' || c == '\f' || c == '\v' || c == '\t' || c == '\r');
}
template<typename tip1>
std::istream &operator>>(std::istream &tok, GMatrica<tip1> &m1){
    std::vector<std::vector<tip1>> v;
    char b, e;
    tok >> b;
    if(b != '[' ){ tok.setstate(std::ios::failbit); return tok; }
    if(tok.peek() != ']') b = ';'; int red(0);
    
    while(b == ';'){
        red++; v.resize(red);
        int kol(0);
        do{
            kol++; v[red-1].resize(kol);
            tok >> v[red-1][kol-1];
            tok>> e;
        }while(e != ';' && e != EOF && e != ']');
        b = e;
    }
    if(b != ']' || (tok.peek() != EOF && !white(tok.peek()) )){
        tok.setstate(std::ios::failbit); return tok; 
    }
    m1.row = v.size(); //m1.col = v[0].size();
    m1.col = 0;
    if(v.size()) m1.col = v[0].size();
    if(v.size() > 4) { tok.setstate(std::ios::failbit); return tok; }
    for(int i = 1; i < v.size(); i++){
            if(v[i-1].size() != v[i].size())
                {tok.setstate(std::ios::failbit); return tok; }
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++)
            m1.m[i][j] = v[i][j];
    }
    return tok;
}
template<typename tip> 
template<typename tip1>
GMatrica<tip> &GMatrica<tip>::operator*=(tip1 x){
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) m[i][j] *= x;
    return *this;
}
template<typename tip1>
std::ostream &operator<<(std::ostream &tok, const GMatrica<tip1> &m1){
    int sirina = tok.width();
    if(sirina < 6) sirina = 6;
    for(int i = 0; i < m1.row; i++){
        for(int j = 0; j < m1.col; j++){
            tok.width(sirina);
            tok << m1[i][j];
        }
        tok << std::endl;
    }
    return tok;
}
template<typename tip>
tip* GMatrica<tip>::operator[](int x){
    return m[x];
}
template<typename tip>
const tip* GMatrica<tip>::operator[](int x)const{
    return m[x];
}
template<typename tip>
tip &GMatrica<tip>::operator()(int x, int y){
    if(x < 1 || x > row || y < 1 || y > col)
        throw std::range_error("Nedozvoljen indeks");
    return m[x-1][y-1];
}
template<typename tip>
tip GMatrica<tip>::operator()(int x, int y)const{
    if(x < 1 || x > row || y < 1 || y > col)
        throw std::range_error("Nedozvoljen indeks");
    return m[x-1][y-1];
}
template<typename tip>
template<typename tip1>
bool GMatrica<tip>::operator!=(const GMatrica<tip1> &m1)const{
    return !(*this == m1);
}
template<typename tip>
template<typename tip1>
bool GMatrica<tip>::operator==(const GMatrica<tip1> &m1)const{
    bool isti = true;
    if(row != m1.row || col != m1.col) return false;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(m[i][j] != m1.m[i][j]){ isti = false; break; }
    return isti;
}
template<typename tip>
template<typename tip1>
GMatrica<tip> &GMatrica<tip>::operator-=(const GMatrica<tip1> &m1){
    if(row != m1.row || col != m1.col) throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) m[i][j] -= m1.m[i][j];
    return *this;
}

template<typename tip>
template<typename tip1>
GMatrica<tip> &GMatrica<tip>::operator+=(const GMatrica<tip1> &m1){
    if(row != m1.row || col != m1.col) throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) m[i][j] += m1.m[i][j];
    return *this;
}

template<typename tip>
template<typename tip1>
GMatrica<tip> &GMatrica<tip>::operator*=(const GMatrica<tip1> &m1){
    if(col != m1.row) throw std::domain_error("Nedozvoljena operaacija");
    GMatrica<tip> ret(row,col,tip());
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) ret.m[i][j] = m[i][j];
    col = m1.col;
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) m[i][j] = tip();
        
    for(int i = 0; i < row; i++)
        for(int j = 0; j < m1.col; j++)
            for(int k = 0; k < m1.row; k++)
                m[i][j] += ret.m[i][k] * m1.m[k][j];
    return *this;
}


template<typename tip1, typename tip2>
 auto operator*(tip2 n, GMatrica<tip1> m1)->
GMatrica<typename std::remove_reference<decltype(m1.m[0][0]*n)>::type>{
    return m1 * n;
}

template<typename tip1,typename tip2>
auto operator*(GMatrica<tip1> m1, tip2 n)->
GMatrica<typename std::remove_reference<decltype(m1.m[0][0]*n)>::type>{
    for(int i = 0; i < m1.row; i++)
        for(int j = 0; j < m1.col; j++) m1.m[i][j] *= n;
    return m1;
}

template<typename tip1,typename tip2>
auto operator*(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2)->
GMatrica<typename std::remove_reference<decltype(m2.m[0][0]*m1.m[0][0])>::type>{
    if(m1.col != m2.row) throw std::domain_error("Nedozvoljena operacija");
    typedef typename std::remove_reference<decltype(m2.m[0][0]*m1.m[0][0])>::type novi;
    GMatrica<novi> ret(m1.row,m2.col,novi());
    for(int i = 0; i < m1.row; i++)
        for(int j = 0; j < m2.col; j++)
            for(int k = 0; k < m2.row; k++)
                ret.m[i][j] += m1.m[i][k] * m2.m[k][j];
    return ret;
}
template<typename tip1,typename tip2>
auto operator-(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2)->
GMatrica<typename std::remove_reference<decltype(m2.m[0][0]-m1.m[0][0])>::type>{
    typedef typename std::remove_reference<decltype(m2.m[0][0]-m1.m[0][0])>::type novi;
    GMatrica<novi> ret(m1.row,m1.col,novi());
    for(int i = 0; i < m2.row; i++)
        for(int j = 0; j < m2.col; j++) ret.m[i][j] = -m2.m[i][j];
    return m1+ret;
}
template<typename tip1, typename tip2>
auto operator+(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2)->
 GMatrica<typename std::remove_reference<decltype(m2.m[0][0] + m1.m[0][0])>::type>{
    if(m2.row != m1.row || m2.col != m1.col)
        throw std::domain_error("Nedozvoljena operacija");
    typedef typename std::remove_reference<decltype(m2.m[0][0]*m1.m[0][0])>::type novi;
    GMatrica<novi> ret(m1.row,m1.col, novi()); 
    for(int i = 0; i < m1.row; i++)
        for(int j = 0; j < m1.col; j++)
            ret.m[i][j] = m1.m[i][j] + m2.m[i][j];
    return ret;
}
    

template<typename tip>
GMatrica<tip>::GMatrica(const std::initializer_list<std::initializer_list<tip>> &l){
    int i(0),j(0);
    for(auto &p:l){
        for(auto &q:p) m[i][j++] = q;
        i++; col = j; j = 0;
    }
    row = i;
}
template<typename tip>
GMatrica<tip>::GMatrica(const std::vector<std::vector<tip>> &v){
    for(int i = 1; i < v.size(); i++)
        if(v[i].size() != v[i-1].size() || v[i].size() < 0 || v[i].size() > 4)
            throw std::logic_error("Ilegalan format matrice");
    row = v.size();
    col = 0; if(row) col = v[0].size();
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) m[i][j] = v[i][j];
}
template<typename tip>
template<typename tip2>
GMatrica<tip>::GMatrica(const tip2 mat[4][4]):row(4),col(4){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) m[i][j] = mat[i][j];
}

template<typename tip>
template<typename blah>
GMatrica<tip>::GMatrica(const GMatrica<blah> &m2):row(m2.row),col(m2.col){
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) m[i][j] = m2[i][j];
}

template<typename tip>
GMatrica<tip>::GMatrica():row(0),col(0){ }

template<typename tip>
GMatrica<tip>::GMatrica(int row, int col, tip val):row(row),col(col){
    if(row > 4 || row < 0 || col > 4 || col < 0)
        throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) m[i][j] = val;
}


int main () {
    //operator+ i operator- i <<
   {
   GMatrica<double> m1({{1, 2}, {3, 4}});
   GMatrica<double> m2({{1, 2}, {3, 4}});
   auto m3 = m1 + m2;
   std::cout << m3 << std::endl;
   GMatrica<double> m4({{1, 2}, {3, 4}});
   auto m5 = m3-m4;
   std::cout << m5 << std::endl;
   //operator* i <<
   }
   {
   GMatrica<int> m1({{1, 2}, {3, 4}});
   //GMatrica<int> m2 = m1 * 2;
   //GMatrica<int> m3 = 2 * m1;  
   //std::cout <<  m2 << std::endl;
   //std::cout << m3 << std::endl;
   //binarni operatori += -= *=
   }
   {
   GMatrica<int> m1({{1, 2}, {3, 4}});
   GMatrica<int> m2({{1, 2}, {3, 4}});
   std::cout <<  m1 << std::endl;
   m1 += m2;
   std::cout <<  m1 << std::endl;
   m1 -= m2;
   std::cout <<  m1 << std::endl;
   m1 *= 2;
   std::cout <<  m1 << std::endl;
   //operatori == i !=
   }
   {
   GMatrica<int> m1({{1, 2}, {3, 4}});
   GMatrica<int> m2({{1, 2}, {3, 4}});
   GMatrica<int> m3({{1, 2}, {3, 5}});
   if(m1 == m2 && m1 != m3 && !(m1 != m2) && !(m1 != m2)) std::cout << "OK" << std::endl;
   else std::cout << "NOK" << std::endl;
    //operatori {} i []
   }
   {
   GMatrica<int> m1({{1, 2}, {3, 4}});
   std::cout << m1(1,1) << std::endl;
   std::cout << m1[1][1] << std::endl;
   //operatori << i >>
   }
   {
   GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;
   //konstruktori, DajBrojKolona, DajBrojRedova
    }
    {
   GMatrica<int> m1;
   std::cout << m1.DajBrojKolona() <<"," <<m1.DajBrojRedova() << std::endl;
   
   
   GMatrica<int> m2({{1, 2}, {3, 4}});
   std::cout << m2.DajBrojKolona() <<"," <<m2.DajBrojRedova() << std::endl;
   
   GMatrica<int> m3{{1, 2}, {3, 4}};
   std::cout << m3.DajBrojKolona() <<"," <<m3.DajBrojRedova() << std::endl;
    }
	return 0;
}