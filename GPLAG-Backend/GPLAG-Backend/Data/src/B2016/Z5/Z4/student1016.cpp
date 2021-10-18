/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename TipEl>
class GMatrica{
    TipEl elementi[4][4];
    int br_redova, br_kolona;
    public:
    int DajBrojKolona() const { return br_kolona;}
    int DajBrojRedova() const { return br_redova;}
    GMatrica(): br_kolona(0), br_redova(0){};
    GMatrica(int brkolona, int brredova, TipEl vrijednost);
    GMatrica(const GMatrica<TipEl>& m);
    GMatrica<TipEl>(TipEl** n);
    GMatrica<TipEl>(std::vector<std::vector<TipEl>> v);
    GMatrica<TipEl>(std::initializer_list<std::initializer_list<TipEl>> lista);
    
    template<typename TipEl1, typename TipEl2>
    friend GMatrica<TipEl1> operator + (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2); //-> decltype(m1.elementi[0][0]+m2.elementi[0][0]);
    
    template<typename TipEl1>
	auto operator +=(GMatrica<TipEl1> &m2)-> decltype(elementi[0][0]+m2.elementi[0][0]);
	
	template<typename TipEl1, typename TipEl2>
	friend GMatrica<TipEl1> operator - (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2); // -> decltype(m1.elementi[0][0]-m2.elementi[0][0]);
	
	template<typename TipEl1>
	auto operator -=(GMatrica<TipEl1> &m2)-> decltype(elementi[0][0]-m2.elementi[0][0]);
	
	template<typename TipEl1, typename TipEl2>
	friend auto operator * (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2) -> decltype(m1.elementi[0][0]*m2.elementi[0][0]);
	
	template<typename TipEl1>
	auto operator *=(GMatrica<TipEl1> &m2)-> decltype(elementi[0][0]*m2.elementi[0][0]);
	
	template<typename TipEl1, typename TipEl2>
	friend bool operator == (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2);
	
	template<typename TipEl1, typename TipEl2>
	friend bool operator != (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2);
	
	TipEl &operator ()(int i, int j);
	template <typename TipEl1>
    friend std::ostream &operator <<(std::ostream &tok, const GMatrica<TipEl1> &m);
	template <typename TipEl1>
    friend std::istream &operator >>(std::istream &tok,  GMatrica<TipEl1> &m);
	TipEl* operator [](int index1) const;
	TipEl* operator [](int index1);
};

template<typename TipEl>
    GMatrica<TipEl>::GMatrica(int brkolona, int brredova, TipEl vrijednost){
        if(brkolona<0 or brkolona>4 or brredova<0 or brredova>4) throw std::logic_error ("Ilegalan format matrice");
        br_kolona=brkolona;
        br_redova=brredova;
        for(int i=0; i<br_redova; i++){
            for(int j=0; i<br_kolona; j++){
                elementi[i][j]=vrijednost;
            }
        }
    }

template< typename TipEl>
    GMatrica<TipEl>::GMatrica(const GMatrica<TipEl>& m){
        for(int i=0; i<m.br_redova; i++){
            for(int j=0; j<m.br_kolona; j++){
                elementi[i][j]=m.elementi[i][j];
            }
        }
        br_kolona=m.br_kolona; br_redova=m.br_redova;
    }
template <typename TipEl>
    GMatrica<TipEl>::GMatrica(TipEl** n){
        br_kolona=4;
        br_redova=4;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                elementi[i][j]=n[i][j];
            }
        }
    }
template<typename TipEl>
    GMatrica<TipEl>::GMatrica(std::vector<std::vector<TipEl>> v){
        if(v.size()>4) throw std::logic_error("Ilegalan format matrice");
        for(int i=0; i<v.size(); i++){
            if(v[i].size()!=v[0].size()) throw std::logic_error("Ilegalan format matrice");
        }
        br_kolona=v[0].size(); br_redova=v.size();
        for(int i=0; i<br_redova; i++){
            for(int j=0; j<br_kolona; j++){
                elementi[i][j]=v[i][j];
            }
        }
    }
template <typename TipEl>
    GMatrica<TipEl>::GMatrica(std::initializer_list<std::initializer_list<TipEl>> lista){
        if(lista.size()>4) throw std::logic_error("Ilegalan format matrice");
        int x=lista.begin()->size();
        for(auto i=lista.begin(); i!=lista.end(); i++){
            if(i->size()!=x) throw std::logic_error("Ilegalan format matrice");
        }
        br_kolona=x;
        br_redova=lista.size();
        int y(0); x=0;
        for(auto it=lista.begin(); it!=lista.end(); it++){
            y=0;
            for(auto itt=it->begin(); itt!=it->end(); itt++){
                elementi[x][y]=*itt;
                y++;
            }
            x++;
        }
    }
template<typename TipEl1, typename TipEl2>
    GMatrica<TipEl1> operator + (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2) /*-> decltype(GMatrica<(decltype(m1.elementi[0][0]+m2.elementi[0][0]))>)*/{
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
	GMatrica<TipEl1> m(m1.br_redova, m2.br_kolona, 0);
	m.br_redova=m1.br_redova;
	m.br_kolona=m1.br_kolona;
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	    return m;
    }
   // template<typename TipEl>
	//auto GMatrica<TipEl>::operator +=(GMatrica<TipEl> &m2)-> decltype(elementi[0][0]+m2.elementi[0][0]);
template<typename TipEl1, typename TipEl2>
    GMatrica<TipEl1> operator - (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2)/* -> decltype(m1.elementi[0][0]-m2.elementi[0][0])*/{
	    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
    	GMatrica<decltype(m1.elementi[0][0]+m2.elementi[0][0])> m3(m1.br_redova, m1.br_kolona, 0);
    	m3.br_redova=m1.br_redova;
    	m3.br_kolona=m1.br_kolona;
	    for(int i = 0; i < m1.br_redova; i++)
		    for(int j = 0; j < m1.br_kolona; j++)
			    m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	    return m3;
	 }
	//template<typename TipEl1>
	//auto GMatrica<TipEl>::operator -=(GMatrica<TipEl1> &m2)-> decltype(elementi[0][0]-m2.elementi[0][0]);
template<typename TipEl1, typename TipEl2>
    GMatrica<TipEl2> operator * (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2){ //-> decltype(m1.elementi[0][0]*m2.elementi[0][0]){
	    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    	GMatrica<decltype(m1.elementi[0][0]*m2.elementi[0][0])> m3(m1.br_redova, m2.br_kolona, 0);
    	m3.br_redova=m1.br_redova;
    	m3.br_kolona=m2.br_kolona;
	    for(int i=0; i<m1.br_redova; i++) {
		    for(int j=0; j<m2.br_kolona; j++) {
			    m3.elementi[i][j]=0;
		    	for(int k=0; k<m1.br_kolona; k++) {
			    	m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
			    }
		    }
	    }
	    return m3;
    }
template<typename TipEl1>
	GMatrica<TipEl1> operator * (const GMatrica<TipEl1> &m1, double x){
	    GMatrica<TipEl1> m3(m1.br_redova, m1.br_kolona, 0);
    	m3.br_redova=m1.br_redova;
    	m3.br_kolona=m1.br_kolona;
	    for(int i=0; i<m1.br_redova; i++) {
		    for(int j=0; j<m1.br_kolona; j++) {
			    m3.elementi[i][j]=m1.elementi[i][j]*x;
		    }
	    }
	    return m3;
	}
template<typename TipEl1>
	GMatrica<TipEl1> operator * (double x,const GMatrica<TipEl1> &m1){
	    GMatrica<TipEl1> m3(m1.br_redova, m1.br_kolona, 0);
    	m3.br_redova=m1.br_redova;
    	m3.br_kolona=m1.br_kolona;
	    for(int i=0; i<m1.br_redova; i++) {
		    for(int j=0; j<m1.br_kolona; j++) {
			    m3.elementi[i][j]=m1.elementi[i][j]*x;
		    }
	    }
	    return m3;
	}
//template<typename TipEl1, typename TipEl>
//	 GMatrica<TipEl> GMatrica<TipEl>::operator *=(GMatrica<TipEl1> &m2)
	 
template<typename TipEl1, typename TipEl2>
	bool operator == (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2){
	    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) return false;
	    for(int i=0; i<m1.br_redova; i++){
	        for(int j=0; j<m1.br_kolona; j++){
	            if(m1.elementi[i][j]!=m2.elementi[i][j]) return false;
	        }
	    }
	    return true;
	}
template<typename TipEl1, typename TipEl2>
	bool operator != (const GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2){
	    return !(m1==m2);
	}
template <typename TipEl>
    TipEl &GMatrica<TipEl>::operator ()(int i, int j){
        if(i>br_redova or i<1 or j<1 or j>br_kolona) throw std::range_error("Nedozvoljen indeks");
        return elementi[i-1][j-1];
    }
template <typename TipEl>
    TipEl* GMatrica<TipEl>::operator [](int index1){
    	return elementi[index1];
    }
template <typename TipEl>
    TipEl* GMatrica<TipEl>::operator [](int index1) const{
    	return elementi[index1];
}
template <typename TipEl1>
    std::ostream &operator << (std::ostream &tok, const GMatrica<TipEl1> &m){
        int x(tok.width());
        if(x<6) x=6;
        for(int i=0; i<m.br_redova; i++){
            for(int j=0; j<m.br_kolona; j++){
                tok << std::setw(x) <<m.elementi[i][j];
            }
            tok << std::endl;
        }
        return tok;
    }
template <typename TipEl1>
    std::istream &operator >>(std::istream &tok, GMatrica<TipEl1> &m){
        std::string s;
        std::getline(std::cin, s);
        if(s[0]!='[') tok.setstate(std::ios::failbit);
        int i=1;
        int x(0), y(0);
        while(s[i]!=']'){
            y=0;
            while(s[i]!=';' and s[i]!=']'){
               m.elementi[x][y]=s[i]-'0';

               y++;
               if(s[i+1]!=',' or s[i+1]!=';' or s[i+1]!=']')  tok.setstate(std::ios::failbit);
               i++;
               if(s[i]==']') break;
               if(s[i]==',') i++;
            }
            if(s[i]==']') break;
            i++;
            x++;
        }
        m.br_kolona=y;
        m.br_redova=x+1;
        return tok;
    }
using std::cout;
using std::cin;

int main ()
{
    GMatrica<double> m1, m2;
    cout << "Unesite prvu matricu: ";
    cin >> m1;
    cin >> m2;
    cout << "Matrice ";
    if(m1==m2) cout << "su iste";
    else cout << "nisu iste";
    cout << "Matrice ";
    if(m1!=m2) cout << "su razlicite";
    else cout << "nisu razlicite";
    int x,y;
    cout << "Koji element prve matice zelite procitati: ";
    cin >> x>> y;
    cout << m1[x][y];
     cout << "Koji element druge matice zelite procitati: ";
    cin >> x>> y;
    cout << m2[x][y];
	return 0;
}