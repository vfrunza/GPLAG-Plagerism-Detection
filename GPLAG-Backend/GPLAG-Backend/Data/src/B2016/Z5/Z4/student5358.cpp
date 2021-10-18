/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
using namespace std;
template <typename tip>
class GMatrica{
    int br_redova;
    int br_kolona;
    tip matrica[4][4];
    public:
    GMatrica(){
        br_redova=0;
        br_kolona=0;
    }
    template <typename tipm>
    GMatrica(int br_r, int br_k,tipm poc_vrij={}){
        if(br_r<0||br_r>4||br_k<0||br_k>4) throw std::logic_error("Ilegalan format matrice");
    br_redova=br_r;
    br_kolona=br_k;
    for(int i(0); i<br_r; i++) for(int j(0); j<br_k; j++) matrica[i][j]=poc_vrij;
    }
    template <typename tip2>
    GMatrica(GMatrica<tip2> m){
        br_redova=m.br_redova;
        br_kolona=m.br_kolona;
        for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
        matrica[i][j]=m.matrica[i][j];
    }
    template <typename tip444>
    GMatrica(const std::initializer_list<std::initializer_list<tip444>>  &brojevi)//:br_redova(brojevi.size()),br_kolona(brojevi[0].size()){
    {
        br_redova=brojevi.size();
        br_kolona=(*brojevi.begin()).size();
        auto it=brojevi.begin();
        for(int i=0;i<br_kolona;i++){
            auto it1=it->begin();
            for(int j=0;j<2;j++){
                matrica[i][j]=*it1;
                it1++;
            }
            it++;
        }
    }
    template <typename tip1>
    GMatrica(tip1 matrica[4][4]): br_redova(4), br_kolona(4) {
    for(int i(0); i<4; i++) for(int j(0); j<4; j++) GMatrica::matrica[i][j]=matrica[i][j];
    }
    GMatrica(std::vector<std::vector<int>> v){
        br_redova=v.size();
        br_kolona=v[0].size();
        if(br_redova>4)throw std::logic_error("Ilegalan format matrice");
        for(int i=0;i<br_redova;i++){
            if(v[i].size()!=br_kolona || v[i].size()>4)throw std::logic_error("Ilegalan format matrice");
        }
        for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            matrica[i][j]=v[i][j];
        }
    }
    }
    int DajBrojKolona()const{
        return br_kolona;
    }
    int DajBrojRedova()const{
        return br_redova;
    }
    template <typename tip5,typename tip6>
    friend auto operator +(const GMatrica<tip5> &m1, const GMatrica<tip6> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>;
    template <typename tip7,typename tip8>
    friend auto operator -(const GMatrica<tip7> &m1, const GMatrica<tip8> &m2)->GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])>;
    template <typename tip9,typename tip10>
    friend auto operator *(const GMatrica<tip9> &m1, const GMatrica<tip10> &m2)->GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>;
    template <typename tip11,typename tip100>
    friend auto operator *(const GMatrica<tip11> &m, tip100 t)->GMatrica<decltype(m.matrica[0][0]*t)>;
    template <typename tip101,typename tip12>
    friend auto operator *(tip101 t, const GMatrica<tip12> &m)->GMatrica<decltype(t*m.matrica[0][0])>;
    template <typename tip13>
    GMatrica &operator +=(const GMatrica<tip13> &m){
        if(br_redova!=m.br_redova || br_kolona!=m.br_kolona)throw std::domain_error("Nedozvoljena operacija");
        for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
        matrica[i][j]=matrica[i][j]+m.matrica[i][j];
        return *this;
    }
    template <typename tip14>
    GMatrica &operator -=(const GMatrica<tip14> &m){
        if(br_redova!=m.br_redova || br_kolona!=m.br_kolona)throw std::domain_error("Nedozvoljena operacija");
        for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
        matrica[i][j]=matrica[i][j]-m.matrica[i][j];
        return *this;
        }
    template <typename tip15>
    GMatrica &operator *=(const GMatrica<tip15> &m){
        if(br_redova==m.br_kolona || br_kolona==m.br_redova){
            *this=*this*m;
            return *this;
        }
        else throw std::domain_error("Nedozvoljena operacija");
    }
    GMatrica &operator *=(const double t){
        for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_redova;j++)
        matrica[i][j]*=t;
        return *this;
    }
    template <typename tip16,typename tip17>
    friend bool operator ==(const GMatrica<tip16> &m1, const GMatrica<tip17> &m2);
    template <typename tip18,typename tip19>
    friend bool operator !=(const GMatrica<tip18> &m1, const GMatrica<tip19> &m2);
    template <typename tip4>
    friend istream &operator >>(istream &cin, GMatrica<tip4> &m);
    template <typename tip3>
    friend ostream &operator <<(ostream &cout, const GMatrica<tip3> &m);
    int &operator ()(int i, int j){
        if(i<1 || j<1 || i>br_redova || j>br_kolona)throw range_error("Nedozvoljen indeks");
    return matrica[i-1][j-1];
    }
    int operator ()(int i, int j) const{
        if(i<1 || j<1 || i>br_redova || j>br_kolona)throw range_error("Nedozvoljen indeks");
    return matrica[i-1][j-1];
    }
    int* operator [](int i) {
        //if(i<0 || j<0 || i>br_redova-1 || j>br_kolona-1)throw range_error("Nedozvoljen indeks");
    return matrica[i];
    }
};
template <typename tip3>
ostream &operator <<(std::ostream &cout, const GMatrica<tip3> &m) {
    int sirina(6);
    if (cout.width()>sirina) sirina=cout.width();
    for(int i(0); i<m.br_redova; i++) {
        for(int j(0); j<m.br_kolona; j++)
            cout << setw(sirina) << m.matrica[i][j];
        cout << endl;
    }
    return cout;
}
template <typename tip4>
     istream &operator >>(istream &cin, GMatrica<tip4> &m){
         int a=4,b=4;
         m.br_redova=a;
         m.br_kolona=b;
         int i=0,j=0;
         if(cin.peek()=='[')
         for(;;){
             cin.ignore(1,'\n');
             if(cin.peek()>='0' && cin.peek()<='9'){
                 cin>>m.matrica[i][j++];
             }
             else cin.setstate(ios::failbit);
             if(cin.peek()==',')continue;
             else if(cin.peek()==';'){
                 i++;
                 //std::cout<<j<<std::endl;
                 m.br_kolona=j;
                 j=0;
                 continue;
             }
             else if(cin.peek()==']'){
                 //std::cout<<i+1<<std::endl;
                 m.br_redova=i+1;
                 break;
             }
             else cin.setstate(ios::failbit);
         }
         else cin.setstate(ios::failbit);
         if(m.br_kolona!=j+1 || m.br_redova!=i+1)cin.setstate(ios::failbit);
         return cin;
     }
     template <typename tip5,typename tip6>
     auto operator +(const GMatrica<tip5> &m1, const GMatrica<tip6> &m2)-> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>{
         if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)throw std::domain_error("Nedozvoljena operacija");
         GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> m(m1.br_redova,m1.br_kolona,0);
         for(int i=0;i<m.br_redova;i++)
         for(int j=0;j<m.br_kolona;j++)
         m.matrica[i][j]=m1.matrica[i][j]+m2.matrica[i][j];
         return m;
     }
template <typename tip7,typename tip8>
     auto operator -(const GMatrica<tip7> &m1, const GMatrica<tip8> &m2)->GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])>{
         if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)throw std::domain_error("Nedozvoljena operacija");
         GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])> m(m1.br_redova,m1.br_kolona,0);
         for(int i=0;i<m.br_redova;i++)
         for(int j=0;j<m.br_kolona;j++)
         m.matrica[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
         return m;
     }
     template <typename tip9,typename tip10>
    auto operator *(const GMatrica<tip9> &m1, const GMatrica<tip10> &m2)->GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>{
        if(m1.br_redova==m2.br_kolona || m1.br_kolona==m2.br_redova){
            GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])> m(m1.br_redova,m2.br_kolona,0);
            for(int i=0;i<m1.br_redova;i++)
            for(int j=0;j<m2.br_kolona;j++){
                double suma=0;
                for(int k=0;k<m2.br_redova;k++)suma+=m1.matrica[i][k]*m2.matrica[k][j];
                m.matrica[i][j]=suma;
            }
            return m;
        }
        else throw std::domain_error("Nedozvoljena operacija");
    }
    template <typename tip11,typename tip100>
     auto operator *(const GMatrica<tip11> &m, tip100 t)->GMatrica<decltype(m.matrica[0][0]*t)>{
         GMatrica<decltype(m.matrica[0][0]*t)> m1(m.br_redova,m.br_kolona,0);
         for(int i=0;i<m.br_redova;i++)
         for(int j=0;j<m.br_kolona;j++)
         m1.matrica[i][j]=m.matrica[i][j]*t;
         return m1;
     }
     template <typename tip101,typename tip12>
     auto operator *(tip101 t, const GMatrica<tip12> &m)->GMatrica<decltype(t*m.matrica[0][0])>{
         return m*t;
     }
template <typename tip16,typename tip17>
    bool operator ==(const GMatrica<tip16> &m1, const GMatrica<tip17> &m2){
        if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)return false;
        for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
        if(m1.matrica[i][j]!=m2.matrica[i][j])return false;
        return true;
    }
template <typename tip18,typename tip19>
     bool operator !=(const GMatrica<tip18> &m1, const GMatrica<tip19> &m2){
        if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)return true;
        for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
        if(m1.matrica[i][j]!=m2.matrica[i][j])return true;
        return false;
    }
int main ()
{
    /*double m3[4][4]= {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
        double m4[4][4]= {{2,0,0,2},{2,2,2,2},{2,2,2,2},{2,2,2,2}};
        GMatrica<double> m1(m3);
        GMatrica<int> m2(m4);
        GMatrica<int> m(4,4,0);
        m1(1,1)=34;
        cout << setw(2) << m1(1,1)<<endl ;
        GMatrica<int> mm(2,3,0);
    cin >> mm;
    cout << setw(10) << mm;*/
    GMatrica<int> m1;
    std::cin>>m1;
   std::cout << m1 << std::endl;
   //std::cout << m1[1][1] << std::endl;
	return 0;
}