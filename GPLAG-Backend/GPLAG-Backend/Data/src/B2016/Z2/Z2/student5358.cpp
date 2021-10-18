// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <iomanip>
#include <type_traits>
#include <deque>
#include <stdexcept>
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename tip>
auto Spreda(tip v,int k)-> typename std::remove_reference<decltype(v[0])>::type{
    typename std::remove_reference<decltype(v[0])>::type m(v[0].size(),typename std::remove_reference<decltype(v[0][0])>::type (v[0][0]));
    for(int i=0;i<v[0].size();i++){
    for(int j=0;j<v[0][0].size();j++){
        //std::cout<<v[0][i][j]<<" ";
        m[i][j]=v[k][i][j];
    }
    //std::cout<<std::endl;
 }
 return m;
}
template <typename tip>
auto Odozgo(tip v,int k) -> typename std::remove_reference<decltype(v[0])>::type{
    //Matrica m(v.size(),std::vector<int>(v[0][0].size()));
    typename std::remove_reference<decltype(v[0])>::type m(v.size(),typename std::remove_reference<decltype(v[0][0])>::type (v[0][0]));
    for(int i=v.size()-1;i>=0;i--){
    for(int j=0;j<v[0][0].size();j++){
        //std::cout<<v[i][0][j]<<" ";
        m[i][j]=v[i][k][j];
    }
    //std::cout<<std::endl;
 }
 int br=m.size()-1;
        for(int i=0;i<m.size()/2;i++){
            typename std::remove_reference<decltype(v[0][0])>::type pom=m[i];
        //double br=ma.size()-1;
        m[i]=m[br];
        m[br]=pom;
        br--;
        }
 return m;
}
template <typename tip>
auto Bok(tip v,int k)-> typename std::remove_reference<decltype(v[0])>::type{
    //Matrica m(v[0].size(),std::vector<int>(v.size()));
    typename std::remove_reference<decltype(v[0])>::type m(v[0].size(),typename std::remove_reference<decltype(v[0][0])>::type (v.size()));
    for(int i=0;i<v[0].size();i++){
    for(int j=0;j<v.size();j++){
        m[i][j]=v[j][i][k];
    }
 }
 return m;
}
template <typename tip>
void Ispisi(tip m){
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++)
        std::cout<<std::setw(4)<<m[i][j];
        std::cout<<std::endl;
    }
}
template <typename tip>
auto razmjena(tip m,SmjerKretanja s)-> typename std::remove_reference<decltype(m[0])>::type{
    typename std::remove_reference<decltype(m[0])>::type v;
    //std::cout<<"ff"<<m.size();
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            if((i+j==m[i].size()-1 &&(s==SmjerKretanja::NazadNaprijed || s==SmjerKretanja::DoljeGore || s==SmjerKretanja::LijevoDesno)) || (i==j &&(s==SmjerKretanja::NaprijedNazad || s==SmjerKretanja::GoreDolje || s==SmjerKretanja::DesnoLijevo)))v.push_back(m[i][j]);
        }
    }
    return v;
}
template<typename tip>
auto IzdvojiDijagonale3D(tip v,SmjerKretanja s) -> typename std::remove_reference<decltype(v[0])>::type
{
    int f=v[0].size(),g=v[0][0].size();
    for(int i=0;i<v.size();i++){
        if(v[i].size()!=f)throw std::domain_error("Plohe nemaju isti broj elemenata");
    for(int j=0;j<v[i].size();j++){
        if(v[i][j].size()!=g)throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    }
    //std::cout<<"jest"<<v.size();
    //decltype(0 + v[0]) mat;
    typename std::remove_reference<decltype(v[0])>::type mat;
    if(s==SmjerKretanja::NaprijedNazad || s==SmjerKretanja::NazadNaprijed){
 for(int k=0;k<v.size();k++){
    mat.push_back(razmjena(Spreda(v,k),s));
 }
    }
    if(s==SmjerKretanja::DoljeGore || s==SmjerKretanja::GoreDolje){
 for(int k=0;k<v[0].size();k++){
    mat.push_back(razmjena(Odozgo(v,k),s));
 }
    }
    if(s==SmjerKretanja::LijevoDesno || s==SmjerKretanja::DesnoLijevo){
 for(int k=0;k<v[0][0].size();k++){
    mat.push_back(razmjena(Bok(v,k),s));

    //Ispisi(Bok(v,k));
 }
    }

    if(s==SmjerKretanja::NazadNaprijed || s==SmjerKretanja::DoljeGore || s==SmjerKretanja::DesnoLijevo){
 int br=mat.size()-1;
        for(int i=0;i<mat.size()/2;i++){
            typename std::remove_reference<decltype(mat[0])>::type pom=mat[i];
        //double br=ma.size()-1;
        mat[i]=mat[br];
        mat[br]=pom;
        br--;
        }
    }
    /*if(s==SmjerKretanja::DesnoLijevo){
        int d=mat[0].size();
    for(int i=0;i<mat.size();i++){
            int kr=mat[0].size()-1;
    for(int j=0;j<mat[i].size()/2;j++){
            int pom;
        //double kr=ma[0].size()-1;
        pom=mat[i][j];
        mat[i][j]=mat[i][kr];
        mat[i][kr]=pom;
        //if(d%2==0 && d!=2 )
            kr--;
    }}
    }*/
 return mat;
}
int main ()
{
    try{
    std::vector<std::deque<std::deque<int> > > v;
    std::cout<<"Unesite dimenzije (x y z): ";
    int duz,sir,dub;
    std::cin>>duz>>sir>>dub;
    if(duz<0 || sir<0 || dub<0){std::cout<<"Neispravne dimenzije kontejnera!";return 0;}
    v.resize(duz);
  for (int i = 0; i < duz; ++i) {
    v[i].resize(sir);
    for (int j = 0; j < sir; ++j)
      v[i][j].resize(dub);
  }
  std::cout<<"Unesite elemente kontejnera: "<<std::endl;
 for(int i=0;i<duz;i++)
    for(int j=0;j<sir;j++)
    for(int k=0;k<dub;k++){
    std::cin>>v[i][j][k];
    }
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int c;
    std::cin>>c;
    if(c<0 || c>5){std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;return 0;}
    SmjerKretanja s=SmjerKretanja(c);
 //s=SmjerKretanja(c);
 if(c==0) {std::cout<<"NaprijedNazad: "<<std::endl;s=SmjerKretanja::NaprijedNazad;}
 else if(c==1){std::cout<<"NazadNaprijed: "<<std::endl;s=SmjerKretanja::NazadNaprijed;}
 else if(c==2){std::cout<<"GoreDolje: "<<std::endl;s=SmjerKretanja::GoreDolje;}
 else if(c==3){std::cout<<"DoljeGore: "<<std::endl;s=SmjerKretanja::DoljeGore;}
 else if(c==4){std::cout<<"LijevoDesno: "<<std::endl;s=SmjerKretanja::LijevoDesno;}
 else {std::cout<<"DesnoLijevo: "<<std::endl;s=SmjerKretanja::DesnoLijevo;}
 Ispisi(IzdvojiDijagonale3D(v,s));
    }
    catch(std::domain_error e){
        std::cout<<"Izuztak: "<<e.what();
    }
	return 0;
}