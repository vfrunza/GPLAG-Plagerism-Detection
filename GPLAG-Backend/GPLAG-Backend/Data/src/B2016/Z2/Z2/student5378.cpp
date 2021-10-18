// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <type_traits>
#include <iomanip>
using namespace std;
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename TipMat> 
TipMat Okreni(TipMat m);
template <typename Kontejnerr>
auto IzdvojiDijagonale3D(Kontejnerr Kontejner,SmjerKretanja smjer)->typename remove_reference<decltype(Kontejner[0])>::type{
    for(int i=0;i<Kontejner.size();i++){
        for(int j=0;j<Kontejner.size();j++){
            if(Kontejner[0][0].size()!=Kontejner[i][j].size()) throw domain_error("Redovi nemaju isti broj elemenata");
        }
        if(Kontejner[0].size()!=Kontejner[i].size()) throw domain_error("Plohe nemaju isti broj redova");
    }
    typedef typename remove_reference<decltype(Kontejner[0])>::type v;
    typedef typename remove_reference<decltype(Kontejner[0][0])>::type m;
    v mat,matrica;
    for(unsigned int i=0;i<Kontejner.size();i++){
        m vektor;
        for(unsigned j=0;j<Kontejner[0].size();j++){
            for(unsigned s=0;s<Kontejner[i][j].size();s++){
                if(smjer==SmjerKretanja(0)){
                    if(j==s) vektor.push_back(Kontejner[i][j][s]);
                }
                if(smjer==SmjerKretanja(1)){
                    if(j+s==Kontejner[i].size()) vektor.push_back(Kontejner[Kontejner.size()-1-i][j][s]);
                }
                if(smjer==SmjerKretanja(4)){
                    if(i==j) vektor.push_back(Kontejner[Kontejner.size()-1-i][j][s]);
                }
                if(smjer==SmjerKretanja(5)){
                    if(i+j==Kontejner.size()) vektor.push_back(Kontejner[i][Kontejner[i].size()-1-j][Kontejner[i][j].size()-1-s]);
                    
                    if(smjer==SmjerKretanja(2)){
                        if(i==s) vektor.push_back(Kontejner[Kontejner.size()-1-i][j][s]);
                    }
                    if(smjer==SmjerKretanja(3)){
                        if(i+s==Kontejner[i][j].size()-1) vektor.push_back(Kontejner[Kontejner.size()-1-i][Kontejner[i].size()-1-j][s]);
                    }
                }
            }
        }
        //NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
        mat.push_back(vektor);
    }
    if(smjer==SmjerKretanja(2)||smjer==SmjerKretanja(3)||smjer==SmjerKretanja(4)||smjer==SmjerKretanja(5)) 
    mat=Okreni(mat);
    return mat;
}
template <typename tip>
void IspisiMatricu(tip mat){
    for(unsigned int i=0;i<mat.size();i++){
        for(unsigned int j=0;j<mat[i].size();j++){
        cout<<setw(4)<<mat[i][j];
        }
        cout<<endl;
    }
}
int main ()
{
    int x,y,z;
    cout<<"Unesite dimenzije (x y z): ";
    cin>>x>>y>>z;
    if(x<0 || y<0 || z<0) {
        cout<<"Neispravne dimenzije kontejnera!"; return 0;
    }
    vector<deque<deque<int>>>Kontejner(x);
    for(int i=0;i<Kontejner.size();i++){
        Kontejner[i].resize(y);
    }
    for(int i=0;i<Kontejner.size();i++){
        for(int j=0;j<Kontejner[i].size();j++){
            Kontejner[i][j].resize(z);
        }
    }
    cout<<"Unesite elemente kontejnera: "<<endl;
    for(int i=0;i<Kontejner.size();i++){
        for(int j=0;j<Kontejner[i].size();j++){
            for(int s=0;s<Kontejner[i][j].size();s++){
                cin>>Kontejner[i][j][s];
            }
        }
    }
     //NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
    cout<<"Unesite smjer kretanja [0 - 5]: ";
    int S;
    cin>>S;
    try{
        switch(S){
            case 0:cout<<"NaprijedNazad: "<<endl;
            IspisiMatricu(IzdvojiDijagonale3D(Kontejner,SmjerKretanja(0)));
            break;
            case 1:cout<<"NazadNaprijed: "<<endl;
            IspisiMatricu(IzdvojiDijagonale3D(Kontejner,SmjerKretanja(1)));
            break;
            case 2:cout<<"GoreDolje: "<<endl;
            IspisiMatricu(IzdvojiDijagonale3D(Kontejner,SmjerKretanja(2)));
            break;
            case 3:cout<<"DoljeGore: "<<endl;
            IspisiMatricu(IzdvojiDijagonale3D(Kontejner,SmjerKretanja(3)));
            break;
            case 4:cout<<"LijevoDesno: "<<endl;
            IspisiMatricu(IzdvojiDijagonale3D(Kontejner,SmjerKretanja(4)));
            break;
            case 5:cout<<"DesnoLijevo: "<<endl;
            IspisiMatricu(IzdvojiDijagonale3D(Kontejner,SmjerKretanja(5)));
            break;
            default:cout<<"Smjer kretanja nije ispravan! "<<endl;
            break;
        }
    }
    catch(domain_error Izuzetak){
        cout<<Izuzetak.what();
    }
	return 0;
}
template<typename TipMat>
TipMat Okreni(TipMat m){
    TipMat Nova(m[0].size());
    for(int i=0;i<Nova.size();i++){
        Nova[i].resize(m.size());
    }
    for(int i=0;i<Nova.size();i++){
        for(int j=0;j<Nova[i].size();j++){
            Nova[i][j]=m[j][i];
        }
    }
    return Nova;
}