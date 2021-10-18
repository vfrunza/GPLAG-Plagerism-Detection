// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <stdexcept>
#include <iomanip>

using namespace std;

enum class SmjerKretanja {NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};
template <typename Matrica>

auto TransponujMatricu(Matrica matrica)->typename remove_reference<decltype(matrica)>::type{
typename remove_reference<decltype(matrica)>::type povratna;
int i(0),j(0),t(0);
auto it1=matrica.begin();
for(auto itp1=(*it1).begin();itp1!=(*it1).end();itp1++,t++){
    typename remove_reference<decltype(matrica.at(0))>::type pom;
    for(auto it=matrica.begin();it!=matrica.end();it++,i++){
        j=0;
        for(auto it2=(*it).begin();it2!=(*it).end();it2++,j++){
            if(j==t){
                pom.push_back(*it2);
            }
        }
    }
    povratna.push_back(pom);
}
return povratna;
    
}

template <typename Kont1>
auto IzdvojiDijagonale3D(Kont1 kontejner,SmjerKretanja smjer)->typename remove_reference<decltype(kontejner.at(0))>::type {
    typename remove_reference<decltype(kontejner.at(0))>::type povratna;
//auto it=kontejner.begin();

for(auto it=kontejner.begin();it<kontejner.end();it++){
    auto nesto=it; nesto++;
    if(nesto==kontejner.end()) break;
    if((*it).size()!=(*nesto).size()) throw domain_error("Plohe nemaju isti broj redova");
    for(auto it1=(*it).begin();it1!=(*it).end();it1++){
        auto nesto2=it1;
        nesto2++;
        if(nesto2==(*it).end()) break;
        if((*it1).size()!=(*nesto2).size()) throw domain_error("Redovi nemaju isti broj elemenata");
    }
}
int i=0,j=0,k=0;
if(smjer==SmjerKretanja::NaprijedNazad){
    i=0;
    for(auto it1=kontejner.begin();it1!=kontejner.end();it1++,i++){
        j=0;
        typename remove_reference<decltype(kontejner.at(0).at(0))>::type pom;
        for(auto it2=(*it1).begin();it2!=(*it1).end();it2++,j++){
            k=0;
            for(auto it3=(*it2).begin();it3!=(*it2).end();it3++,k++){
                if(j==k){
                    pom.push_back(*it3);
                }
            }
        }
        povratna.push_back(pom);
    }
}
if(smjer==SmjerKretanja::NazadNaprijed){
    auto t=kontejner.end();
    t--;
    i=0;
    for(auto it1=t;;it1--,i++){
        j=0;
        typename remove_reference<decltype(kontejner.at(0).at(0))>::type pom;
        for(auto it2=(*it1).begin();it2!=(*it1).end();it2++,j++){
            k=0;
            auto x=(*it2).begin();
            auto y=(*it2).end();
            y--;
            for(auto it3=y;it3!=x;it3--,k++){
                if(j==k)
                pom.push_back(*it3);
            }
        }
        povratna.push_back(pom);
        if(it1==kontejner.begin()) break;
    }
}
if(smjer==SmjerKretanja::GoreDolje){
    typename remove_reference<decltype(kontejner.at(0))>::type pomocna;
    auto itPovratna=pomocna.begin();
    auto t=kontejner.end();
    t--;
    i=0;
    for(auto it1=t;;it1--,i++){
        j=0;
        typename remove_reference<decltype(kontejner.at(0).at(0))>::type pom;
        for(auto it2=(*it1).begin();it2!=(*it1).end();it2++,j++){
            k=0;
            for(auto it3=(*it2).begin();it3!=(*it2).end();it3++,k++){
                if(i==k){
                    pom.push_back(*it3);
                }
            }
        }
        pomocna.push_back(pom);
        if(it1==kontejner.begin()) break;
    }
    povratna=TransponujMatricu(pomocna);
}
if(smjer==SmjerKretanja::DoljeGore){
    typename remove_reference<decltype(kontejner.at(0))>::type pomocna;
    auto itPovratna=pomocna.begin();
    auto it1pocetak=kontejner.end();
    it1pocetak--;
    i=0;
    for(auto it1=it1pocetak;;it1--,i++){
        j=0;
        auto it2pocetak=(*it1).end();
        it2pocetak--;
        typename remove_reference<decltype(kontejner.at(0).at(0))>::type pom;
        for(auto it2=it2pocetak;;it2--,j++){
            k=0;
            auto it3pocetak=(*it2).end();
            it3pocetak--;
            for(auto it3=it3pocetak;;it3--,k++){
                if(i==k){
                    pom.push_back(*it3);
                }
                if(it3==(*it2).begin()) break;
            }
            if(it2==(*it1).begin()) break;
        }
        pomocna.push_back(pom);
        if(it1==kontejner.begin()) break;
    }
    povratna=TransponujMatricu(pomocna);
}
if(smjer==SmjerKretanja::LijevoDesno){
    typename remove_reference<decltype(kontejner.at(0))>::type pomocna;
    auto itPovratna=pomocna.begin();
    auto t=kontejner.end();
    t--;
    i=0;
    for(auto it1=t;;it1--,i++){
        j=0;
        typename remove_reference<decltype(kontejner.at(0).at(0))>::type pom;
        for(auto it2=(*it1).begin();it2!=(*it1).end();it2++,j++){
            k=0;
            for(auto it3=(*it2).begin();it3!=(*it2).end();it3++,k++){
                    if(i==j){
                        pom.push_back(*it3);
                    }
                }
            }
            pomocna.push_back(pom);
            if(it1==kontejner.begin()) break;
        }
        povratna=TransponujMatricu(pomocna);
    }
    if(smjer==SmjerKretanja::DesnoLijevo){
        typename remove_reference<decltype(kontejner.at(0))>::type pomocna;
        auto itPovratna=pomocna.begin();
        i=0;
        for(auto it1=kontejner.begin();it1!=kontejner.end();it1++,i++){
            j=0;
            typename remove_reference<decltype(kontejner.at(0).at(0))>::type pom;
            for(auto it2=(*it1).begin();it2!=(*it1).end();it2++,j++){
                k=0;
                auto it3pocetak=(*it2).end();
                it3pocetak--;
                for(auto it3=it3pocetak;;it3--,k++){
                    if(j==i){
                        pom.push_back(*it3);
                    }
                    if(it3==(*it2).begin()) break;
                }
            }
            pomocna.push_back(pom);
        }
        povratna=TransponujMatricu(pomocna);
    }
    return povratna;
}

int main(){
    try{
        int x,y,z;
        vector<SmjerKretanja> smjerovi={SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed,SmjerKretanja::GoreDolje,SmjerKretanja::DoljeGore,SmjerKretanja::LijevoDesno,SmjerKretanja::DesnoLijevo};
        vector<string>stringovi={"NaprijedNazad","NazadNaprijed","GoreDolje","DoljeGore","LijevoDesno","DesnoLijevo"};
        cout<<"Unesite dimenzije (x y z): ";
        cin>>x>>y>>z;
        if(x<=0 || y<=0 || z<=0){
            cout<<"Neispravne dimenzije kontejnera!";
            return 0;
        }
        vector<deque<deque<int>>>kontejner(x,deque<deque<int>>(y,deque<int>(z,0)));
        cout<<"Unesite elemente kontejnera: \n";
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                for(int k=0;k<z;k++){
                    int broj;
                    cin>>broj;
                    kontejner[i][j][k]=broj;
                }
        int smjer;
        cout<<"Unesite smjer kretanja [0 - 5]: ";
        cin>>smjer;
        if(smjer<0 || smjer>5){
            cout<<"Smjer kretanja nije ispravan!\n";
            return 0;
        }
        auto ispisi=IzdvojiDijagonale3D(kontejner,smjerovi[smjer]);
        cout<<stringovi[smjer]<<": \n";
        for(auto i: ispisi){
            for(auto j:i){
                cout<<setw(4)<<j;
            }
            cout<<endl;
        }
    }
    catch(domain_error e){
        cout<<e.what();
    }
    return 0;
}