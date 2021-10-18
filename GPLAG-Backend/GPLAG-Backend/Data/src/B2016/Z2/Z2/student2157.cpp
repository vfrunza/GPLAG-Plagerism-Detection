// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!
#include <vector>
#include <deque>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <stdexcept>
enum class SmjerKretanja {
NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner kont3d,SmjerKretanja smjer)->typename std::remove_reference<decltype(*kont3d.begin())>::type {
    typename std::remove_reference<decltype(*kont3d.begin())>::type kont2d;
    if(kont3d.size()==0)return kont2d;
    for(int i=0;i<kont3d.size();i++){
        if(kont3d[0].size()!=kont3d[i].size())throw std::domain_error("Plohe nemaju isti broj redova");
        for(int j=0;j<kont3d[i].size();j++){
            if(kont3d[0][0].size()!=kont3d[i][j].size())throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    if(smjer==SmjerKretanja::NaprijedNazad){
        for(int i=0;i<kont3d.size();i++){
            for(int j=0;j<kont3d.at(i).size();j++){
                for(int k=0;k<kont3d.at(i).at(j).size();k++){
                    if(j==k){
                    kont2d.resize(kont3d.at(i).size());
                    kont2d.at(i).resize(kont3d.at(i).size());
                    kont2d.at(i).at(k)=kont3d.at(i).at(j).at(k);
                    }
                }
            }
        }

    }
    else if(smjer==SmjerKretanja::NazadNaprijed){
        kont2d.resize(kont3d.size());
        int br_2d=0;
        for(int i=kont3d.size()-1;i>=0;i--){
            for(int j=0;j<kont3d.at(i).size();j++){
                for(int k=kont3d.at(i).at(j).size()-1;k>=0;k--){
                    if(j+k==kont3d.at(i).at(j).size()-1){
                    kont2d.at(br_2d).resize(kont3d.at(i).size());
                    kont2d.at(br_2d).at(kont3d.at(i).at(j).size()-k-1)=kont3d.at(i).at(j).at(k);
                    }
                }
            }br_2d++;
        }
    }
    if(smjer==SmjerKretanja::GoreDolje){
        kont2d.resize(kont3d.at(0).size());
        int k=0;
        for(int i=kont3d.size()-1;i>=0;i--){
            for(int j=0;j<kont2d.size();j++){
                kont2d.at(j).resize(kont3d.size());
                kont2d.at(j).at(k)=kont3d.at(i).at(j).at(k);
            }
            k++;
        }
    }
    if(smjer==SmjerKretanja::DoljeGore){
        kont2d.resize(kont3d.at(0).size());
        int br_2d(0);
        int k=kont3d.at(0).at(0).size()-1;
        for(int i=kont3d.size()-1;i>=0;i--){
            for(int j=0;j<kont2d.size();j++){
                kont2d.at(kont2d.size()-1-j).resize(kont3d.size());
                kont2d.at(kont2d.size()-1-j).at(br_2d)=kont3d.at(i).at(j).at(k);
            }
            k--;
            br_2d++;
        }
    }
    if(smjer==SmjerKretanja::LijevoDesno){
        kont2d.resize(kont3d.at(0).at(0).size());
        for(int i=0;i<kont2d.size();i++){
          kont2d.at(i).resize(kont3d.size());
        }
        int br_3d=kont3d.size()-1;
        for(int i=0;i<kont3d.size();i++){
            for(int j=0;j<kont2d.size();j++){
                kont2d.at(j).at(i)=kont3d.at(br_3d).at(i).at(j);
            }
            br_3d--;
        }
    }
    if(smjer==SmjerKretanja::DesnoLijevo){
        kont2d.resize(kont3d.at(0).at(0).size());
        for(int i=0;i<kont2d.size();i++){
          kont2d.at(i).resize(kont3d.size());
        }
        for(int i=0;i<kont3d.size();i++){
            for(int j=0;j<kont2d.size();j++){
                kont2d.at(kont2d.size()-1-j).at(i)=kont3d.at(i).at(i).at(j);
            }
        }
    }

    return kont2d;
}

int main(){
    std::vector<std::vector<std::vector<int>>> kont;
    int a,b,c;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>a>>b>>c;
    if(a<=0 || b<=0 || c<=0){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: ";
    kont=std::vector<std::vector<std::vector<int>>>(a,std::vector<std::vector<int>>(b,std::vector<int>(c)));
    for(int i=0;i<a;i++){
        int g;
        for(int j=0;j<b;j++){
            for(int k=0;k<c;k++){
                std::cin>>g;
                kont.at(i).at(j).at(k)=g;
            }
        }
    }
    std::cin.ignore(10000,'\n');
    char clovo;
    int smjr;
    for(;;)
	{
        clovo='A';
        std::cout<<std::endl<<"Unesite smjer kretanja [0 - 5]: ";
        std::cin >> clovo;
        if(int(clovo)>=48 && int(clovo)<=53){
                smjr=int(clovo)-48;
                break;
        }
    	else{
    	std::cin.ignore(100000,'\n');
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
        break;
    	}
	}
    SmjerKretanja smjer;
    smjer=SmjerKretanja(smjr);
    if(smjer==SmjerKretanja::NaprijedNazad)std::cout<<"NaprijedNazad: "<<std::endl;
    if(smjer==SmjerKretanja::DesnoLijevo)std::cout<<"DesnoLijevo: "<<std::endl;
    if(smjer==SmjerKretanja::LijevoDesno)std::cout<<"LijevoDesno: "<<std::endl;
    if(smjer==SmjerKretanja::DoljeGore)std::cout<<"DoljeGore: "<<std::endl;
    if(smjer==SmjerKretanja::GoreDolje)std::cout<<"GoreDolje: "<<std::endl;
    if(smjer==SmjerKretanja::NazadNaprijed)std::cout<<"NazadNaprijed: "<<std::endl;
    try{
    for (const auto &red : IzdvojiDijagonale3D (kont,smjer))
        {
            for (const auto &x : red)
                std::cout.width (4), std::cout << x;
            std::cout << std::endl;
        }
    }
    catch(std::domain_error x){
    std::cout<<x.what();
    }
    return 0;
}
