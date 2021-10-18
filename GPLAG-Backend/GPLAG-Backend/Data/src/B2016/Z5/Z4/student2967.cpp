/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <iomanip>
#include <cctype>

template <typename Tip>
class GMatrica
{
    Tip Mat[4][4];
    int br_redova,br_kolona;
public:
    GMatrica(): br_redova(0),br_kolona(0) {}
    GMatrica(int redovi,int kolone,Tip M);
    template <typename Tip2>
    GMatrica(const GMatrica<Tip2> &G);
    GMatrica<Tip>(const GMatrica<Tip> &G);
    GMatrica(std::vector<std::vector<Tip>> V);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> lista);
    int DajBrojRedova() {
        return br_redova;
    }
    int DajBrojKolona() {
        return br_kolona;
    }
    template <typename TipEl1,typename TipEl2>
    friend auto operator +(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2)-> GMatrica<decltype(m1.Mat[0][0]+m2.Mat[0][0])>;

    template <typename TipEl1,typename TipEl2>
    friend auto operator -(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2)-> GMatrica<decltype(m1.Mat[0][0]-m2.Mat[0][0])>;
    template <typename TipEl1,typename TipEl2>
    friend auto operator *(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2)-> GMatrica<decltype(m1.Mat[0][0]*m2.Mat[0][0])>;
    template <typename Tip1,typename Tip2>

    friend GMatrica<Tip1> operator *(const GMatrica<Tip1> &m1,Tip2 d);

    template <typename TipEl2>
    GMatrica<Tip> &operator +=(const GMatrica<TipEl2> &m2);

    template <typename TipEl2>
    GMatrica<Tip> &operator -=(const GMatrica<TipEl2> &m2);

    template <typename TipEl2>
    GMatrica<Tip> &operator *=(const GMatrica<TipEl2> &m2);
    template <typename TipEl2>
    GMatrica<Tip> &operator *=(TipEl2 d);
    auto operator[](int i)-> decltype(Mat[0]) {
        
        return Mat[i];
    }

    auto operator[](int i) const -> decltype(Mat[0]) {
        return Mat[i];
    }
    Tip &operator()(int i,int j) {
        if(i < 1 || i > br_redova || j < 1 || j > br_kolona)
            throw std::range_error("Nedozvoljen indeks");
        return Mat[i-1][j-1];
    }
    const Tip operator ()(int i,int j)const {
        if(i < 1 || i > br_redova || j < 1 || j > br_kolona)
            throw std::range_error("Nedozvoljen indeks");
        return Mat[i-1][j-1];
    }
    template<typename Tip1>
    friend std::ostream &operator <<(std::ostream &tok,const GMatrica<Tip1> &m);
    bool operator== ( const GMatrica<Tip> &B);
    bool operator!= ( const GMatrica<Tip> &B);
    template<typename Tip1>
    friend std::istream &operator >>(std::istream &tok, GMatrica<Tip1> &m);
};
template <typename TipEl1,typename TipEl2>
auto operator +(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2)-> GMatrica<decltype(m1.Mat[0][0]+m2.Mat[0][0])> {
    GMatrica<decltype(m1.Mat[0][0]+m2.Mat[0][0])> m3(m1.br_redova, m1.br_kolona,5);
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona || m1.br_redova>4 || m2.br_kolona>4)
        throw std::domain_error("“Nedozvoljena operacij");
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.Mat[i][j] = m1.Mat[i][j] + m2.Mat[i][j];
    return m3;
}
template <typename TipEl1> template<typename TipEl2>
GMatrica<TipEl1> &GMatrica<TipEl1>::operator +=(const GMatrica<TipEl2> &m2)
{
    if(br_redova != m2.br_redova || br_kolona != m2.br_kolona || br_redova>4 || m2.br_kolona>4)
        throw std::domain_error("“Nedozvoljena operacij");
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Mat[i][j] += m2.Mat[i][j];
    return *this;
}
template <typename TipEl1>template<typename TipEl2>
GMatrica<TipEl1> &GMatrica<TipEl1>::operator *=(TipEl2 d)
{
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Mat[i][j] *=d;
    return *this;
}
template <typename TipEl1> template<typename TipEl2>
GMatrica<TipEl1> &GMatrica<TipEl1>::operator -=(const GMatrica<TipEl2> &m2)
{
    if(br_redova != m2.br_redova || br_kolona != m2.br_kolona || br_redova>4 || m2.br_kolona>4)
        throw std::domain_error("“Nedozvoljena operacij");
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Mat[i][j] -= m2.Mat[i][j];
    return *this;
}
template <typename TipEl1> template<typename TipEl2>
GMatrica<TipEl1> &GMatrica<TipEl1>::operator *=(const GMatrica<TipEl2> &m2)
{
    if(br_kolona != m2.br_redova || br_redova>4 || br_kolona>4 || m2.br_redova>4 || m2.br_kolona>4)
        throw std::domain_error("Nedozvoljena operacij");
    GMatrica<TipEl1> m3(br_redova, br_kolona,5);
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++) {
            m3.Mat[i][j] = 0;
            for(int k = 0; k < br_kolona; k++)
                m3.Mat[i][j] += Mat[i][k] * m2.Mat[k][j];
        }
    *this=m3;
    return *this;
}
template <typename TipEl1,typename TipEl2>
auto operator -(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2)-> GMatrica<decltype(m1.Mat[0][0]-m2.Mat[0][0])> {
    GMatrica<decltype(m1.Mat[0][0]-m2.Mat[0][0])> m3(m1.br_redova, m1.br_kolona,5);
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona || m1.br_redova>4 || m1.br_kolona>4)
        throw std::domain_error("“Nedozvoljena operacij");
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.Mat[i][j] = m1.Mat[i][j] - m2.Mat[i][j];
    return m3;
}


template <typename TipEl1,typename TipEl2>
auto operator *(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2)-> GMatrica<decltype(m1.Mat[0][0]*m2.Mat[0][0])> {
    if(m1.br_kolona != m2.br_redova || m1.br_redova>4 || m1.br_kolona>4 || m2.br_redova>4 || m2.br_kolona>4)
        throw std::domain_error("Nedozvoljena operacij");
    GMatrica<decltype(m1.Mat[0][0]*m2.Mat[0][0])> m3(m1.br_redova, m1.br_kolona,5);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++) {
            m3.Mat[i][j] = 0;
            for(int k = 0; k < m1.br_kolona; k++)
                m3.Mat[i][j] += m1.Mat[i][k] * m2.Mat[k][j];
        }
    return m3;
}
template <typename TipEl,typename Tip2>
GMatrica<TipEl> operator *(const GMatrica<TipEl> &m, Tip2 d)
{
    GMatrica<TipEl> m2(m.br_redova, m.br_kolona,d);
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
            m2.Mat[i][j] = m.Mat[i][j] * d;
    return m2;
}
template <typename TipEl,typename Tip2>
inline GMatrica<TipEl> operator *(Tip2 d, const GMatrica<TipEl> &m)
{
    return m*d;
}
template <typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista)
{
    br_redova=(lista.size());
    br_kolona=lista.begin()->size() ;
    if(br_redova>4) throw std::logic_error ("Ilegalan format matrice");
    auto it(lista.begin());
    while(it!=lista.end()) {
        if(br_redova!=it->size())
            throw std::logic_error ("Ilegalan format matrice");
        it++;
    }
    int i(0),j(0);
    for(auto it1=lista.begin(); it1!=lista.end(); it1++) {
        j=0;
        for(auto it2=it1->begin(); it2!=it1->end(); it2++) {
            Mat[i][j]=*it2;
            j++;
        }
        i++;
    }

}

template <typename Tip>
GMatrica<Tip>::GMatrica(int redovi,int kolone,Tip M): br_kolona(kolone),br_redova(redovi)
{
    if(redovi<0 || redovi>4 || kolone<0 || kolone>4) throw std::logic_error ("Ilegalan format matrice");
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            Mat[i][j]=M;
}

template <typename Tip> template<typename Tip2>
GMatrica<Tip>::GMatrica(const GMatrica<Tip2> &G):br_kolona(G.br_kolona),br_redova(G.br_redova)
{
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            Mat[i][j]=G.Mat[i][j];
}

template <typename Tip>
GMatrica<Tip>::GMatrica(const GMatrica<Tip> &G):br_kolona(4),br_redova(4)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            Mat[i][j]=G.Mat[i][j];
}
template <typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> V):br_redova(V.size()), br_kolona(V[0].size())
{
    if(br_redova>4) throw std::logic_error ("Ilegalan format matrice");
    for(int i=0; i<br_redova; i++) {
        if(br_redova!=V[i].size())
            throw std::logic_error ("Ilegalan format matrice");
    }
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_redova; j++)
            Mat[i][j]=V[i][j];
}
template <typename Tip2>
std::ostream &operator <<(std::ostream &tok,const GMatrica<Tip2> &m)
{
    int sirina_ispisa(tok.width());
    if(sirina_ispisa<6)
        sirina_ispisa=6;
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            tok<<std::setw(sirina_ispisa)<<m.Mat[i][j];
        }
        tok<<std::endl;
    }
    return tok;
}
template <typename Tip1>
bool GMatrica<Tip1>::operator== (const GMatrica<Tip1> &B)
{
    if(br_kolona!=B.br_kolona || br_redova!=B.br_redova)
        return false;
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            if(Mat[i][j]!=B.Mat[i][j])
                return false;
    return true;
}
template <typename Tip2>
std::istream &operator >>(std::istream &tok, GMatrica<Tip2> &m)
{
    GMatrica<Tip2> unos;
    
    if(tok.peek() != '[')//ako nije otvorena zagrada
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    
    tok.get();
    int red{0}, kolona{0};
    while(true)
    {
        if(red > 4) //matrica smije imati najvise cetiri elementa u redu
        {
            tok.setstate(std::ios::failbit);
            break;
        }
        
        kolona = 0;
        while(std::isdigit(tok.peek()))
        {
            if(kolona > 4) //matrica smije imati najvise cetiri elementa u koloni
            {
                tok.setstate(std::ios::failbit);
                break;
            }
            
            tok >> unos.Mat[red][kolona++]; //uzima broj
            
            if(tok.peek() == ',') 
            {
                tok.get();
                if(!std::isdigit(tok.peek())) 
                {
                    //ako poslije zareza nije cifra ne valja
                    tok.setstate(std::ios::failbit);
                    break;
                }
            }
            else if(tok.peek() == ';')
            { 
                tok.get();
                if(!unos.br_kolona) unos.br_kolona = kolona;//prvi red setuje broj kolona 
                if(unos.br_kolona && kolona != unos.br_kolona) tok.setstate(std::ios::failbit);//ako je bilo koji sljedeci red razlicit po broju kolona
                break;
            }
            else if((tok.peek() == ']' && kolona == unos.br_kolona) || (tok.peek() == ']' && kolona > 0 && kolona < 5 && tok))  //ako je zadnji red i broj kolona odgovara prvom redu
            {
                if(tok)
                {
                    if(!unos.br_kolona) unos.br_kolona = kolona;
                    unos.br_redova = red + 1;
                    m = unos;
                }
                return tok;
            }
            else tok.setstate(std::ios::failbit);//ako nije neki od navedenih znakova ne valja
        }
        if(!tok) break;
        if(!unos.br_kolona) tok.setstate(std::ios::failbit);//ako ima neki znak na pocetku koji nije broj
        red++;
    }

    return tok;
}
template <typename Tip1>
bool GMatrica<Tip1>::operator!= ( const GMatrica<Tip1>& B)
{
    return !(*this == B);

}
int main ()
{
    GMatrica<int> a{{1,2,3},{4,5,6},{7,8,9}}, b{{3,2,1},{6,5,4},{9,8,7}}, c;
	std::cout << "Zbir ove dvije matrice je:\n";
	std::cout << std::setw(7) << a + b;
	a+=b;
	std::cout << "Razlika ove dvije matrice je: \n"<<std::setw(7)<<a-b << std::endl;
	a-=b;
	std::cout << "Proizvod je: \n" << a * b;
	std::cout << "Matrica pomnozena sa 4 : \n" << std::endl;
	a*=4;
	std::cout << a;
	a*=b;
	std::cout << "Proizod matrice A i B: \n" << a << std::endl;
	std::cout << "Unesi matricu c: ";
	std::cin >> c;
	std::cout << c << std::endl;
	if(a == c) std::cout << "Matrice a i c su iste." << std::endl;
	if(a != c) std::cout << "Matrice a i c nisu iste." << std::endl;
}