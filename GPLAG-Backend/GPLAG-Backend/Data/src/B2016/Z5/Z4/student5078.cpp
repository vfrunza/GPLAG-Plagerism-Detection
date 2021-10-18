/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <iomanip>

template<typename Tip>
class GMatrica{
    Tip matrica[4][4];
    int br_redova,br_kolona;
    public:
    GMatrica():br_redova(0),br_kolona(0){};
    GMatrica(int red,int kolona, Tip element=Tip());
    template<typename tip2>
    GMatrica(const GMatrica<tip2> &mm);
    explicit GMatrica(const Tip mm[4][4]);
    GMatrica(const std::vector<std::vector<Tip>> &vm);
    GMatrica(const std::initializer_list<std::initializer_list<Tip>> &vm);
    int DajBrojRedova()const{return br_redova;}
    int DajBrojKolona()const{return br_kolona;}
    template<typename Tip1,typename Tip2>
    friend auto operator+(GMatrica<Tip1> m1,GMatrica<Tip2> m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>;
    template<typename Tip1,typename Tip2>
    friend auto operator-(GMatrica<Tip1> m1,GMatrica<Tip2> m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>;
    template<typename Tip1,typename Tip2>
    friend auto operator*(GMatrica<Tip1> m1,GMatrica<Tip2> m2)->GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>;
    Tip &operator() (int i,int j);
    Tip operator()(int i,int j)const;
    Tip *operator[](int i);
    const Tip* operator[](int i)const;
    GMatrica &operator*=(const GMatrica<Tip> &m1);
    GMatrica &operator*=(const Tip broj);
    GMatrica &operator+=(const GMatrica<Tip> &m1);
    GMatrica &operator+=(const Tip broj);
    GMatrica &operator-=(const GMatrica<Tip> &m1);
    GMatrica &operator-=(const Tip broj);
    template<typename Tip1,typename Tip2>
    friend bool operator==(const GMatrica<Tip1> m1,const GMatrica<Tip2> m2);
    template<typename Tip1,typename Tip2>
    friend bool operator!=(const GMatrica<Tip1> m1,const GMatrica<Tip2> m2);
    template<typename Tip1>
    friend std::ostream &operator<<(std::ostream &ispis,const GMatrica<Tip1> &m);
    template<typename Tip1>
    friend std::istream &operator>>(std::istream &ulaz,GMatrica<Tip1> &matrica1);
};
template<typename Tip>
GMatrica<Tip>::GMatrica(int red,int kolona,Tip element){
    if(red>4 || red<0 || kolona>4 || kolona<0)throw std::logic_error("Ilegalan format matrice");
    br_redova=red;br_kolona=kolona;
    for(int i=0;i<red;i++){
        for(int j=0;j<kolona;j++){
            matrica[i][j]=element;
        }
    }
}
template<typename Tip>
GMatrica<Tip>::GMatrica(const Tip mm[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            matrica[i][j]=mm[i][j];
        }
    }br_redova=4;br_kolona=4;
}
template<typename Tip>
template<typename tip2>
GMatrica<Tip>::GMatrica(const GMatrica<tip2> &mm){
    if(mm.br_redova>4 || mm.br_redova<0 || mm.br_kolona>4 || mm.br_redova<0){
        throw std::logic_error("Ilegalan format matrice");}
    for(int i=0;i<mm.br_redova;i++){
        for(int j=0;j<mm.br_kolona;j++){
            matrica[i][j]=mm.matrica[i][j];
        }
    }br_redova=mm.br_redova;br_kolona=mm.br_kolona;
    }
template<typename Tip>
GMatrica<Tip>::GMatrica(const std::vector<std::vector<Tip>> &vm){
    if(vm.size()==0);
    else if(vm.size()>4){throw std::logic_error("Ilegalan format matrice");}
    else{
        for(int i=0;i<vm.size();i++){
            if(vm[i].size()>4 || vm[0].size()!=vm[i].size())throw std::logic_error("Ilegalan format matrice");
        }
    }
    for(int i=0;i<vm.size();i++)
        for(int j=0;j<vm[i].size();j++){
            matrica[i][j]=vm[i][j];
        }
    br_kolona=vm.size();br_redova=vm[0].size();
}
template<typename Tip>
GMatrica<Tip>::GMatrica(const std::initializer_list<std::initializer_list<Tip>> &vm){
    int sluc=0;
    if(vm.size()==0);
    else if(vm.size()>4){throw std::logic_error("Ilegalan format matrice");}
    else{
        for(const auto i: vm){
            if(sluc==0)sluc=i.size();
            if(vm.size()>4 || sluc!=i.size() || i.size()>4)throw std::logic_error("Ilegalan format matrice");
        }
    }
    int i=0;int j=0;
    for(const auto &l: vm){
        for(const auto &k:l){
            matrica[i][j]=k;
            j++;
        }
        i++;
        j=0;
    }
    br_kolona=sluc;br_redova=vm.size();
}
template<typename tip1,typename tip2>
auto operator+(GMatrica<tip1> m1,GMatrica<tip2> m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>{
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()){
        throw std::domain_error("Nedozvoljena operacija");}
        GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> a;
        a.br_kolona=m1.br_kolona;a.br_redova=m2.br_redova;
        for(int i=0;i<m1.DajBrojKolona();i++){
            for(int j=0;j<m1.DajBrojRedova();j++){
                a.matrica[i][j]=m2.matrica[i][j]+m1.matrica[i][j];
            }
        }
    return a;
}
template<typename tip1,typename tip2>
auto operator-(GMatrica<tip1> m1,GMatrica<tip2> m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>{
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()){
        throw std::domain_error("Nedozvoljena operacija");}
        GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> a;
        a.br_kolona=m1.br_kolona;a.br_redova=m2.br_redova;
        for(int i=0;i<m1.DajBrojKolona();i++){
            for(int j=0;j<m1.DajBrojRedova();j++){
                a.matrica[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
            }
        }
    return a;
}
template<typename tip1,typename tip2>
auto operator*(GMatrica<tip1> m1,GMatrica<tip2> m2)->GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>{
    if(m1.br_kolona!=m2.br_redova)throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])> a;
    a.br_kolona=m1.br_kolona;a.br_redova=m2.br_redova;
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            for(int k=0;k<m1.br_kolona;k++){
            a.matrica[i][j]+=m1.matrica[i][k]*m2.matrica[k][j];
            }
        }
    }
    return a;
}
template<typename Tip>
Tip &GMatrica<Tip>::operator ()(int i ,int j){
    i--;j--;
    if(i<0 || j<0 || i>br_redova || j>br_kolona)throw std::range_error("Nedozvoljen indeks");
    return matrica[i][j];
}
template<typename Tip>
Tip GMatrica<Tip>::operator ()(int i ,int j)const{
    i--;j--;
    if(i<0 || j<0 || i>br_redova || j>br_kolona)throw std::range_error("Nedozvoljen indeks");
    Tip a=matrica[i][j];
    return a;
}
template<typename Tip>
Tip *GMatrica<Tip>::operator[](int i){
    if(i<0 ||  i>br_redova)throw std::range_error("Nedozvoljen indeks");
    return &(*matrica[i]);
}
template<typename Tip>
const Tip* GMatrica<Tip>::operator[](int i)const{
    if(i<0 ||  i>br_redova)throw std::range_error("Nedozvoljen indeks");
    return matrica[i];
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator*=(const GMatrica<Tip> &m1){
    if(br_kolona!=m1.br_redova)throw std::domain_error("Nedozvoljena operacija");
    auto a=*this;
    a.br_kolona=br_kolona;a.br_redova=m1.br_redova;
    br_kolona=a.br_kolona;br_redova=m1.br_redova;
    for(int i=0;i<a.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            for(int k=0;k<a.br_kolona;k++){
            matrica[i][j]+=a.matrica[i][k]*m1.matrica[k][j];
            }
        }
    }
    return *this;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator*=(const Tip broj){
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]*=broj;
    return *this;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator+=(const GMatrica<Tip> &m1){
    if(br_redova!=m1.DajBrojKolona() || br_redova!=m1.DajBrojRedova()){
    throw std::domain_error("Nedozvoljena operacija");}
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]+=m1[i][j];
    return *this;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator+=(const Tip broj){
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]+=broj;
    return *this;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator-=(const GMatrica<Tip> &m1){
    if(br_redova!=m1.DajBrojKolona() || br_redova!=m1.DajBrojRedova()){
    throw std::domain_error("Nedozvoljena operacija");}
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]-=m1[i][j];
    return *this;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator-=(const Tip broj){
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]-=broj;
    return *this;
}
template<typename Tip,typename Tip1>
bool operator==(const GMatrica<Tip> m1,const GMatrica<Tip1> m2){
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)return false;
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++){
            if(fabs(m1.matrica[i][j]-m2.matrica[i][j])<0.00000001)continue;
            else return false;
        }
    return true;
}
template<typename Tip,typename Tip1>
bool operator!=(const GMatrica<Tip> m1,const GMatrica<Tip1> m2){
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)return true;
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++){
            if(fabs(m1.matrica[i][j]-m2.matrica[i][j])<0.00000001)continue;
            else return true;
        }
    return false;
}
template<typename Tip1,typename Tip2>
auto operator*(const GMatrica<Tip1> m1,Tip2 m2)->GMatrica<decltype(m1(1,1)*m2)>{
    GMatrica<decltype(m2*m1(1,1))> a(m1.DajBrojRedova(),m1.DajBrojKolona(),decltype(m2*m1(1,1))());
    for(int i=0;i<m1.DajBrojRedova();i++){
        for(int j=0;j<m1.DajBrojKolona();j++){
            a(i+1,j+1)=m1(i+1,j+1)*m2;
        }
    }
    return a;
}
template<typename Tip2,typename Tip1>
auto operator*(Tip2 m2,const GMatrica<Tip1> m1)->GMatrica<decltype(m2*m1(1,1))>{
    GMatrica<decltype(m2*m1(1,1))> a(m1.DajBrojRedova(),m1.DajBrojKolona(),decltype(m2*m1(1,1))());
    for(int i=0;i<m1.DajBrojRedova();i++){
        for(int j=0;j<m1.DajBrojKolona();j++){
            a(i+1,j+1)=m1(i+1,j+1)*m2;
        }
    }
    return a;
}
template<typename Tip1>
std::ostream &operator<<(std::ostream &ispis,const GMatrica<Tip1> &m){
    int a(0);
    if(ispis.width()==0)a=6;
    else a=ispis.width();
	for(int i = 0; i < m.DajBrojRedova();i++) {
		for(int j = 0; j < m.DajBrojKolona(); j++)
			ispis<<std::setw(a)<<m(i+1,j+1)<<std::setw(a);
		ispis << std::endl;
	}
	return ispis;
}
template<typename Tip1>
std::istream &operator>>(std::istream &ulaz,GMatrica<Tip1> &matrica1){
    GMatrica<Tip1> matrica(4,4,Tip1());
    int br_kol(0);
    int br_kolfix(0);
    int br_red(0);
    if(ulaz.get()=='['){
    for(int i=1;i<=16;i++){
        if(br_kol>=4){ulaz.setstate(std::ios::failbit);break;}
        if(br_red>=4){ulaz.setstate(std::ios::failbit);break;}
        ulaz>>matrica[br_red][br_kol];
        char znak=char(ulaz.get());
        if(znak==','){br_kol++;}
        else if(znak==';'){
            br_red++;
            if(br_kolfix==0){br_kolfix=br_kol;}
            if(br_kolfix!=0 && br_kolfix!=br_kol){ulaz.setstate(std::ios::failbit);break;}
            br_kol=0;
        }
        else if(znak==']'){
            matrica1=matrica;
            matrica1.br_kolona=br_kolfix+1;
            matrica1.br_redova=br_red+1;
            break;
        }
        else{ulaz.setstate(std::ios::failbit);break;}
    }}
    else ulaz.setstate(std::ios::failbit);
    return ulaz;
}
int main ()
{
    GMatrica<double> A(3,3,2);
    GMatrica<double>  const B(3,3,4);
    GMatrica<float> g(3,3,4);
    if(A!=B)std::cout<<"A i B nisu isti\n";
    if(B==g)std::cout<<"B i G su isti\n";
    auto c=operator+(A,B);
    operator==(A,B);
    std::cout<<"Testiranje (): "<<c(1,1)<<'\n';
    auto n=B*A;
    n=n*A;
    n=n*g;
    g=g*g;
    g+=3;
    g-=3;
    g*3;
    3*g;
    GMatrica<double> unesi;
    std::cout<<"Unesi matricu:\n";
    std::cin>>unesi;
    std::cout<<"Testiranje []: "<<B[0][0]<<"\n";
    std::cout<<"Testiraj mnozenje oduzimanje i sabiranje A*B-C+A: \n";
    std::cout<<std::setw(7)<<unesi;
	return 0;
}