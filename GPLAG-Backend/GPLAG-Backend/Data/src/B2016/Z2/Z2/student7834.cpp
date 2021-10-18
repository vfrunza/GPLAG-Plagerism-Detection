// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <type_traits>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;
enum class SmjerKretanja{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};
template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner Kont,SmjerKretanja smjer)->typename remove_reference <decltype(Kont.at(0))>::type{
    bool imaliga=true;
    for(int i=0;i<Kont.size();i++){
        for(int j=0;j<Kont.at(i).size();j++){
            if(Kont.at(i).at(j).size()!=Kont.at(0).at(0).size()){
                imaliga=false;
                break;
            }
        }
    }
    if(imaliga==false){
        throw domain_error("Redovi nemaju isti broj elemenata");
    }
    if(imaliga==true){
        bool jelisad=true;
        for(int i=1;i<Kont.size();i++){
            if(Kont.at(i).size()!=Kont.at(0).size()){
                jelisad=false;
                break;
            }
        }
        if(jelisad==false){
            throw domain_error("Plohe nemaju isti broj redova");
        }
    }
    if(smjer==SmjerKretanja::NaprijedNazad){
        typename remove_reference<decltype(Kont.at(0))>::type matrica(Kont.size(),typename remove_reference<decltype(Kont.at(0).at(0))>::type(Kont.at(0).size()));
   for(int i=0;i<Kont.size();i++){
       for(int j=0;j<(Kont.at(0)).size();j++){
           matrica[i][j]=Kont.at(i).at(j).at(j);
       }
   }
   return matrica;
    }
    if(smjer==SmjerKretanja::NazadNaprijed){
        typename remove_reference<decltype(Kont.at(0))>::type matrica(Kont.size(),typename remove_reference<decltype(Kont.at(0).at(0))>::type(Kont.at(0).size()));
   for(int i=0;i<Kont.size();i++){
       for(int j=0;j<(Kont.at(0)).size();j++){
           matrica[i][j]=Kont.at(Kont.size()-i-1).at(j).at(Kont.at(0).at(0).size()-j-1);
       }
   }
   return matrica;
    }
    if(smjer==SmjerKretanja::GoreDolje){
       typename remove_reference<decltype(Kont.at(0))>::type matrica(Kont.at(0).size(),typename remove_reference<decltype(Kont.at(0).at(0))>::type(Kont.size()));
   for(int i=0;i<Kont.at(0).size();i++){
       for(int j=0;j<Kont.size();j++){
           matrica[i][j]=Kont.at(Kont.size()-j-1).at(i).at(j);
       }
   }
   return matrica;
    }
    if(smjer==SmjerKretanja::DoljeGore){
       typename remove_reference<decltype(Kont.at(0))>::type matrica(Kont.at(0).size(),typename remove_reference<decltype(Kont.at(0).at(0))>::type(Kont.size()));
   for(int i=0;i<Kont.at(0).size();i++){
       for(int j=0;j<Kont.size();j++){
           matrica[i][j]=Kont.at(Kont.size()-j-1).at(Kont.at(0).size()-i-1).at(Kont.at(0).at(0).size()-j-1);
       }
   }
   return matrica;
    }
    if(smjer==SmjerKretanja::LijevoDesno){
        typename remove_reference<decltype(Kont.at(0))>::type matrica(Kont.at(0).at(0).size(),typename remove_reference<decltype(Kont.at(0).at(0))>::type(Kont.size()));
   for(int i=0;i<Kont.at(0).at(0).size();i++){
       for(int j=0;j<Kont.size();j++){
           matrica[i][j]=Kont.at(Kont.size()-j-1).at(j).at(i);
       }
   }
   return matrica;
    }

if(smjer==SmjerKretanja::DesnoLijevo){
   typename remove_reference<decltype(Kont.at(0))>::type matrica(Kont.at(0).at(0).size(),typename remove_reference<decltype(Kont.at(0).at(0))>::type(Kont.size()));
   for(int i=0;i<Kont.at(0).at(0).size();i++){
       for(int j=0;j<Kont.size();j++){
           matrica[i][j]=Kont.at(j).at(j).at(Kont.at(0).at(0).size()-i-1);
       }
   }
   return matrica;
}


typename remove_reference<decltype(Kont.at(0))>::type matrica(Kont.size(),typename remove_reference<decltype(Kont.at(0).at(0))>::type(Kont.at(0).size()));
return matrica;
}
int main (){

    try{
        int a;
        vector<vector<int>>Matrica;
        int x,y,z;
        cout<<"Unesite dimenzije (x y z): ";
        cin>>x;
        cin>>y;
        cin>>z;
        if(x<0 || y<0 || z<0){
            cout<<"Neispravne dimenzije kontejnera!"<<endl;
            return 0;
        }
        cout<<"Unesite elemente kontejnera: "<<endl;
        vector<vector<vector<int>>> Kont(x,vector<vector<int>>(y,vector<int>(z)));
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    cin>>Kont[i][j][k];
                }
            }
        }
        cout<<"Unesite smjer kretanja [0 - 5]: ";
        cin>>a;
        if(a<0 || a>5)cout<<"Smjer kretanja nije ispravan!"<<endl;
        else{
        if(a==0){
            cout<<"NaprijedNazad: "<<endl;
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    cout<<setw(4)<<IzdvojiDijagonale3D(Kont,SmjerKretanja::NaprijedNazad)[i][j];
                }
                cout<<endl;}
        }
        if(a==1){
            cout<<"NazadNaprijed: "<<endl;
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    cout<<setw(4)<<IzdvojiDijagonale3D(Kont,SmjerKretanja::NazadNaprijed)[i][j];
                }
                cout<<endl;}
        }
        if(a==2){
            
            cout<<"GoreDolje: "<<endl;
            for(int i=0;i<y;i++){
                for(int j=0;j<x;j++){
                    cout<<setw(4)<<IzdvojiDijagonale3D(Kont,SmjerKretanja::GoreDolje)[i][j];
                }
                cout<<endl;}
                
                
        }
        if(a==3){
            cout<<"DoljeGore: "<<endl;
            for(int i=0;i<y;i++){
                for(int j=0;j<x;j++){
                    cout<<setw(4)<<IzdvojiDijagonale3D(Kont,SmjerKretanja::DoljeGore)[i][j];
                }
                cout<<endl;}
        }
        if(a==4){
            cout<<"LijevoDesno: "<<endl;
            for(int i=0;i<z;i++){
                for(int j=0;j<x;j++){
                    cout<<setw(4)<<IzdvojiDijagonale3D(Kont,SmjerKretanja::LijevoDesno)[i][j];
                }
                cout<<endl;}
        }
        if(a==5){
            cout<<"DesnoLijevo: "<<endl;
            for(int i=0;i<z;i++){
                for(int j=0;j<x;j++){
                    cout<<setw(4)<<IzdvojiDijagonale3D(Kont,SmjerKretanja::DesnoLijevo)[i][j];
                }
                cout<<endl;}
                
        }
        }
}
catch(domain_error poruka){
    cout<<poruka.what();
}
        return 0;
    }
	
