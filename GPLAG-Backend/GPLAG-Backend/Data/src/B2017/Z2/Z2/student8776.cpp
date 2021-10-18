#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
using namespace std;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


template <typename tip>
tip PjescaniSat(tip kont, SmjerKretanja s){
    tip rezultat=kont;
    int siz=kont.size();
       if(s==SmjerKretanja::GoreDolje){
           
        int brojac=0;
        for(int k=0;k<siz;k++){
            brojac=0;
            for(int i=0; i<siz; i++){
                for(int j=0;j<siz-1;j++) rezultat.at(k).at(i).at(j)=rezultat.at(k).at(i).at(j+brojac);
                
                if(i<siz/2)brojac++;
                else brojac--;
                
            }
            
            
        }
        
        for(int k=0;k<siz;k++){
            brojac=0;
            for(int i=0; i<siz; i++){
                rezultat.at(k).at(i).resize(siz-brojac);
                if(i<siz/2)brojac+=2;
                else brojac-=2;
            }
            
        }
       
    }else if(s==SmjerKretanja::DoljeGore){
        
         int brojac=0;
        for(int k=0;k<siz;k++){
            brojac=0;
            for(int i=0; i<siz; i++){
                for(int j=0;j<siz-1;j++) rezultat.at(k).at(i).at(j)=rezultat.at(k).at(i).at(j+brojac);
                
                if(i<siz/2)brojac++;
                else brojac--;
                
            }
            
            
        }
        
        for (int k=0;k<siz;k++){
            for(int i=0;i<siz;i++){
                for(int j=0;j<siz;j++){
                    auto temp=rezultat.at(k).at(i).at(j);
                    rezultat.at(k).at(i).at(j)=rezultat.at(k).at(siz-1-i).at(j);
                    rezultat.at(k).at(siz-1-i).at(j)=temp;
                }
            }
        }
        
        for(int k=0;k<siz;k++){
            brojac=0;
            for(int i=0; i<siz; i++){
                rezultat.at(k).at(i).resize(siz-brojac);
                if(i<siz/2)brojac+=2;
                else brojac-=2;
            }
            
        }
       
        
    }else if(0){}
        
        
    return rezultat;
    }


int main (){
    vector<deque<deque<int>>>mat3D;
	cout<<"Unesite dimenziju (x/y/z): ";
	int x;
    cin>>x;
    mat3D.resize(x);
    for(int k=0;k<x;k++)mat3D.at(k).resize(x);
    for(int k=0;k<x;k++){
        for(int i=0;i<x;i++){
            mat3D.at(k).at(i).resize(x);
        }
    }
    cout<<"Unesite elemente kontejnera: ";
    for(int k=0;k<x;k++){
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                int a;
                cin>>a;
                mat3D.at(k).at(i).at(j)=a;
            }
        }
    }
    cout<<"Unesite smjer kretanja [0 - 5]: "<<endl;
   
    int a;
    cin>>a;
    
   
    cout<<"Pjescani sat unesene matrice je: "<<endl;
    auto rezultat =PjescaniSat(mat3D,SmjerKretanja(a));
    int siz=rezultat.size();
     for(int k=0;k<rezultat.size();k++){
            for(int i=0; i<rezultat.at(k).size(); i++){
                for(int j=0;j<rezultat.at(k).at(i).size();j++){
                    if(i!=0 and i<=siz/2) for(int l=0;l<(rezultat.at(k).at(i-1).size()-rezultat.at(k).at(i).size())/2; l++) cout<<"    ";
                   
                    cout<<setw(4)<<rezultat.at(k).at(i).at(j);

                        
}
                cout<< endl;
            }
            cout<< endl;
            
        }
       
	return 0;
}