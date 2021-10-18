#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
enum class SmjerKretanja {NaprijedNazad,NazadNaprijed, GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};
template<typename NekiTip,typename SmjerKretanja>
auto IzdvojiDijagonale3D(NekiTip kont,SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    typename std::remove_reference<decltype(kont.at(0))>::type dvaD;
    int brR(0),h,k,ulaz(0),p;
        if(smjer==SmjerKretanja::NaprijedNazad){
        h=kont.at(0).size()-1;
        dvaD.resize(h);
        k=kont.size()-1;
        dvaD.resize(k);
             for(int j=0; j<kont.at(0).size(); j++){
                for(int i=0; i<kont.size(); i++){
                    for(int k=0; k<kont.at(i).at(j).size(); k++){
                        if(i==k){dvaD.at(brR).push_back(kont.at(i).at(j).at(k)); ulaz=1;}
                        }
                    }
                    brR++;
                }
        }        
        if(smjer==SmjerKretanja::GoreDolje){
                h=kont.at(0).size()-1;
                dvaD.resize(h);
                k=kont.at(0).at(0).size()-1;
                dvaD.resize(k);
            for(int i=0; i<kont.size(); i++){
                for(int j=kont.at(0).size()-1; j>=0; j--){
                    for(int k=0; k<kont.at(0).at(0).size(); k++){
                        if(j==(kont.at(0).size()-1)-k){ dvaD.at(brR).push_back(kont.at(i).at(j).at(k)); ulaz=1;}  
                    }
                }
                brR++;
            }       
        }
        if(smjer==SmjerKretanja::LijevoDesno){
            h=kont.at(0).size()-1;
            dvaD.resize(h);
            k=kont.at(0).at(0).size();
            dvaD.resize(k);
            for(int k=0; k<kont.at(0).at(0).size(); k++){
            for(int i=0; i<kont.size(); i++){
                for(int j=kont.at(0).size()-1; j>=0; j--){
                        if(i==(kont.at(0).size()-1)-j){ dvaD.at(brR).push_back(kont.at(i).at(j).at(k)); ulaz=1;}  
                    }
                }
                brR++;
            }       
        }
                    
            if(ulaz==0){
                brR=0;
            if(smjer==SmjerKretanja::NazadNaprijed){
            for(int j=kont.size()-1; j>=0; j--){
                 h=kont.at(0).size()-1;
                 dvaD.resize(h);
               for(int i=0; i<kont.at(0).size(); i++){
                    p=kont.size();
                    dvaD.resize(p);
                  for(int k=kont.at(j).at(i).size()-1; k>=0; k--){
                        if(i==kont.at(j).at(i).size()-1-k){dvaD.at(brR).push_back(kont.at(j).at(i).at(k));} 
                    }
                }
                brR++;
            }
        }
        if(smjer==SmjerKretanja::DoljeGore){
                int brojac(0);
                h=kont.at(0).size()-1;
                dvaD.resize(h);
                p=kont.at(0).at(0).size()-1;
                dvaD.resize(p);
            for(int i=kont.size()-1; i>=0; i--){
             for(int j=kont.at(0).size()-1; j>=0; j--){
                  for(int k=kont.at(i).at(j).size()-1; k>=0; k--){
                        if(i+j+brojac==k){dvaD.at(brR).push_back(kont.at(i).at(j).at(k));} 
                    }
                }
                brR++;
                brojac++;
            }
        }
         if(smjer==SmjerKretanja::DesnoLijevo){
             int brojac(0);
            h=kont.at(0).size()-1;
            dvaD.resize(h);
            k=kont.at(0).at(0).size();
            dvaD.resize(k);
            for(int k=kont.at(0).at(0).size()-1; k>=0; k--){
            for(int i=0; i<kont.size(); i++){
                for(int j=kont.at(0).size()-1; j>=0; j--){
                        if(i+j==brojac){ dvaD.at(brR).push_back(kont.at(i).at(j).at(k)); ulaz=1;}  
                    }
                    brojac+=2;
                }
                brR++;
                brojac=0;
            }  
            
        }
    }
    return dvaD;           
} 
int main (){
    enum SmjerKretanja smjer;
    int a,b,c;
    std::vector<std::deque<std::deque<int>>> v;
    
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>a>>b>>c;
    if(a<0 || b<0 || c<0){ std::cout<<"Neispravne dimenzije kontejnera!"; return 0;}
    std::cout<<"Unesite elemente kontejnera: ";
    //petlja za prosirivanje veličine
    v.resize(b);
        for(int i=0; i<v.size(); i++){
            v.at(i).resize(a);
        }
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.at(i).size(); j++){
                v.at(i).at(j).resize(c);
                }
            }
        for(int j=0; j<v.at(0).size(); j++){
            for(int i=0; i<v.size(); i++){
                for(int k=0; k<v.at(i).at(j).size(); k++){
                    std::cin>>v.at(i).at(j).at(k);

}
            }
        }
    int broj;
    std::cout<<std::endl;
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    std::cin>>broj;
    if(broj<0 || broj>5){
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
    if(broj==0){ smjer=SmjerKretanja::NaprijedNazad; std::cout<<"NaprijedNazad: "<<std::endl;}
    if(broj==1){ smjer=SmjerKretanja::NazadNaprijed; std::cout<<"NazadNaprijed: "<<std::endl;}
    if(broj==2){ smjer=SmjerKretanja::GoreDolje; std::cout<<"GoreDolje: "<<std::endl;}
    if(broj==3){ smjer=SmjerKretanja::DoljeGore; std::cout<<"DoljeGore: "<<std::endl;}
    if(broj==4){ smjer=SmjerKretanja::LijevoDesno; std::cout<<"LijevoDesno: "<<std::endl;}
    if(broj==5){ smjer=SmjerKretanja::DesnoLijevo; std::cout<<"DesnoLijevo: "<<std::endl;}
    
    for (const auto &red : IzdvojiDijagonale3D (v, smjer)){
    for (const auto x : red)
    std::cout.width (4), std::cout << x;
    std::cout << std::endl;
    }

    
	return 0;
}