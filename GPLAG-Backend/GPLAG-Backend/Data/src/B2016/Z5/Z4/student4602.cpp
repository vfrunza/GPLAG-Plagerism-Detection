/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
using namespace std;

template <typename t>
class GMatrica{
    int br_redova, br_kolona;
    t matrica[4][4];
    public:
    GMatrica() : br_redova(0), br_kolona(0) {}
    GMatrica(int br_redova, int br_kolona, t vrijednost);
    
    GMatrica(initializer_list<initializer_list<t>>lista);
    GMatrica(GMatrica<t>mat[4][4]);
    GMatrica(vector<vector<t>>matt);
    template<typename t1>
    GMatrica(const GMatrica<t1>&mat);
    int DajBrojRedova() const{
        return br_redova;
    }
    int DajBrojKolona() const{
        return br_kolona;
    }
    template<typename t2, typename t1>
    friend auto operator+(const GMatrica<t2> &m1, const GMatrica<t1> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>;
    template<typename t2, typename t1>
    friend auto operator-(const GMatrica<t2> &m1, const GMatrica<t1> &m2)->GMatrica<decltype(m1[0][0]-m2[0][0])>;
    template<typename t2, typename t1>
    friend auto operator*(const GMatrica<t2> &m1, const GMatrica<t1> &m2)->GMatrica<decltype(m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0])>;
    template<typename t2, typename t1>
    friend auto operator*(const GMatrica<t2> &m1, t1 k)->GMatrica<decltype(m1[0][0]*k)>;
    template<typename t2, typename t1>
    friend auto operator*(t1 k, const GMatrica<t2> &m1)->GMatrica<decltype(k*m1[0][0])>;
    template<typename t2>
    friend ostream& operator<<(ostream &tok, GMatrica<t2> &m1);
    GMatrica &operator+=(const GMatrica &m1);
    GMatrica &operator-=(const GMatrica &m1);
    GMatrica &operator*=(const GMatrica &m1);
    template<typename t2, typename t1>
    friend bool operator==(const GMatrica<t2>&m1, const GMatrica<t1>&m2);
    template<typename t2, typename t1>
    friend bool operator!=(const GMatrica<t2>&m1, const GMatrica<t1>&m2);
};
template<typename t>
    GMatrica<t>::GMatrica(int br_redova, int br_kolona, t vrijednost){
        if(br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4) throw logic_error("Ilegalan format matrice");
        GMatrica::br_redova=br_redova;
        GMatrica::br_kolona=br_kolona;
        vrijednost={};
    }
template<typename t>
    GMatrica<t>::GMatrica(GMatrica<t>mat[4][4]){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                matrica[i][j]=mat[i][j];
            }
        }
    }
template<typename t>
    GMatrica<t>::GMatrica(vector<vector<t>>matt){
        if(matt.size()!=matt[0].size()) throw logic_error("Ilegalan format matrice");
        if(matt.size()<0 || matt.size()>4 || matt[0].size()<0 || matt[0].size()>4) throw logic_error("Ilegalan format matrice");
        for(int i=0; i<matt.size(); i++){
            for(int j=0; j<matt.size(); j++){
                matrica[i][j]=matt[i][j];
            }
        }
    }
template<typename t>
    GMatrica<t>::GMatrica(initializer_list<initializer_list<t>>lista){
    vector<vector<t>>pomocni;
    for(auto it=lista.begin(); it!=lista.end(); it++){
        vector<t>pomi;
        for(auto n:*it){
            pomi.push_back(n);
        }
        pomocni.push_back(pomi);
        pomi.clear();
    }
    for(int i=0; i<pomocni.size(); i++){
        for(int j=0; j<pomocni[i].size(); j++){
            matrica[i][j]=pomocni[i][j];
        }
    }
}

/*template<typename t1>
GMatrica<t>::GMatrica(const GMatrica<t1>&mat){
return static_cast<t>(mat);
    }*/

template <typename t,typename t1>
auto operator+(const GMatrica<t> &m1, const GMatrica<t1> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>{
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() && m1.DajBrojRedova()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]+m2[0][0])> m3;
    for(int i=0; i<m1.DajBrojRedova(); i++){
        for(int j=0; j<m1.DajBrojKolona(); i++) {
            m3.matrica[i][j]=m1.matrica[i][j]+m2.matrica[i][j];
        }
    }
    return m3;
}
//template <typename t>
template <typename t,typename t1>
auto operator-(const GMatrica<t> &m1, const GMatrica<t1> &m2)-> GMatrica<decltype(m1[0][0]-m2[0][0])>{
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() && m1.DajBrojRedova()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]-m2[0][0])> m3;
    for(int i=0; i<m1.DajBrojRedova(); i++){
        for(int j=0; j<m1.DajBrojKolona(); i++) {
            m3.matrica[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
        }
    }
    return m3;
}
template<typename t2, typename t1>
auto operator*(const GMatrica<t2> &m1, const GMatrica<t1> &m2)-> GMatrica <decltype(m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0])>{
    if(m1.DajBrojKolona()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0])>m3;
    //GMatrica<decltype(m1[0][0]+m2[0][0])>suma;
    for(int i=0; i<m1.DajBrojRedova(); i++){
        for(int j=0; j<m2.DajBrojKolona(); j++){
            m3.matrica[i][j]=0;
            for(int k=0; k<m2.DajBrojRedova(); k++) m3.matrica[i][j]+=m1[i][k]*m2[k][j];
        }
    }
    return m3;
}
template<typename t2, typename t1>
auto operator*(const GMatrica<t2> &m1, t1 k)->GMatrica<decltype(m1[0][0]*k)>{
    GMatrica<decltype(m1[0][0]*k)>m;
    for(int i=0; i<m1.DajBrojRedova(); i++){
        for(int j=0; j<m1.DajBrojKolona(); j++){
            m.matrica[i][k]*=k;
        }
    }
    return m;
}
template<typename t2, typename t1>
auto operator*(t1 k, const GMatrica<t2>&m1)->GMatrica<decltype(k*m1[0][0])>{
    return m1*k;
}
template<typename t>
GMatrica<t> &GMatrica<t>::operator+=(const GMatrica<t> &m1){
    for(int i=0; i<DajBrojRedova(); i++){
        for(int j=0; j<DajBrojKolona(); j++){
            matrica[i][j]+=m1.matrica[i][j];
        }
    }
    return *this;
}


template<typename t>
GMatrica<t> &GMatrica<t>::operator-=(const GMatrica<t> &m1){
    for(int i=0; i<DajBrojRedova(); i++){
        for(int j=0; j<DajBrojKolona(); j++){
            matrica[i][j]-=m1.matrica[i][j];
        }
    }
    return *this;
}
template<typename t>
GMatrica<t> &GMatrica<t>::operator*=(const GMatrica &m1){
    if(m1.DajBrojKolona()!=DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    for(int i=0; i<DajBrojRedova(); i++){
        for(int j=0; j<DajBrojKolona(); j++){
            matrica[i][j]=0;
            for(int k=0; k<m1.DajBrojRedova(); k++) matrica[i][j]+=m1.matrica[i][k]*m1.matrica[k][j];
        }
    }
    return *this;
}

/*template<typename t2, typename t1>
bool operator==(const GMatrica<t2>&m1, const GMatrica<t1>&m2){
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    if(m1.DajBrojKolona()<1 || m1.DajBrojRedova()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    template<typename t2, typename t1>
    friend bool operator!=(const GMatrica<t2>&m1, const GMatrica<t1>&m2);
*/
template<typename t2>
ostream &operator<<(ostream &tok, GMatrica<t2>&m1){
   //if(m1.DajBrojKolona()<6 && m1.DajBrojRedova()<6){
        for(int i=0; i<m1.DajBrojRedova(); i++){
            for(int j=0; j<m1.DajBrojKolona(); j++){
                tok<<m1.matrica[i][j];
                tok<<endl;
            }
        }
    return tok;
}
int main ()
{
   GMatrica<double> m1({{1, 2}, {3, 4}});
   //GMatrica<double> m2({{1, 2}, {3, 4}});
   //auto m3 = m1 + m2;
   std::cout << m1 << std::endl;
   //GMatrica<double> m4({{1, 2}, {3, 4}});
   //auto m5 = m3-m4;
   //std::cout << m5 << std::endl;

  return 0;      
    }