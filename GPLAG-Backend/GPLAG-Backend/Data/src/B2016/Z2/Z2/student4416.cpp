// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>
#include <string>
typedef std::vector<std::deque<std::deque<int>>> Kontejner;
enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename ktip>
auto IzdvojiDijagonale3D(ktip kont,SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type{
    typename std::remove_reference<decltype(kont.at(0))>::type povratni;
    if(kont.size()==0) return povratni;
    for(int i=0;i<kont.size();i++){
        for(int j=0;j<kont.at(i).size()-1;j++){
            if(kont.at(i).at(j).size()!=kont.at(i).at(j+1).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(int i=0;i<kont.size()-1;i++){
        if(kont.at(i).size()!=kont.at(i+1).size()) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    if(smjer==SmjerKretanja::NaprijedNazad){
        for(int i=0;i<kont.size();i++){
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type temp;    
            for(int j=0;j<kont.at(0).size();j++){
                for(int k=0;k<kont.at(0).at(0).size();k++){
                    if(j==k) temp.push_back(kont.at(i).at(j).at(k));
                }
            }
            povratni.push_back(temp);            
        }
    }
    if(smjer==SmjerKretanja::NazadNaprijed){
        for(int i=kont.size()-1;i>=0;i--){
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type temp; 
            for(int j=0;j<kont.at(0).size();j++){
                for(int k=0;k<kont.at(0).at(0).size();k++){
                    if(j==kont.at(0).at(0).size()-1-k) temp.push_back(kont.at(i).at(j).at(k));
                }
            }
            povratni.push_back(temp);
        }
    }
    if(smjer==SmjerKretanja::GoreDolje){
        for(int j=0;j<kont.at(0).size();j++){
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type temp;
            for(int i=kont.size()-1;i>=0;i--){
                for(int k=0;k<kont.at(0).at(0).size();k++){
                    if(i==kont.size()-1-k) temp.push_back(kont.at(i).at(j).at(k));
                }
            }
            povratni.push_back(temp);
        }
    }
    if(smjer==SmjerKretanja::DoljeGore){
        for(int j=kont.at(0).size()-1;j>=0;j--){
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type temp;
            for(int i=kont.size()-1;i>=0;i--){
                for(int k=0;k<kont.at(0).at(0).size();k++){
                    if(kont.size()-kont.at(0).at(0).size()==i-k) temp.push_back(kont.at(i).at(j).at(k));
                }
            }
            povratni.push_back(temp);
        }
    }
    if(smjer==SmjerKretanja::LijevoDesno){
        for(int k=0;k<kont.at(0).at(0).size();k++){
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type temp;
            for(int j=0;j<kont.at(0).size();j++){
                for(int i=0;i<kont.size();i++){
                    if(i==kont.size()-1-j) temp.push_back(kont.at(i).at(j).at(k));
                }
            }
            povratni.push_back(temp);
        }
    }
    if(smjer==SmjerKretanja::DesnoLijevo){
        for(int k=kont.at(0).at(0).size()-1;k>=0;k--){
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type temp;
            for(int j=0;j<kont.at(0).size();j++){
                for(int i=0;i<kont.size();i++){
                    if (i==j) temp.push_back(kont.at(i).at(j).at(k));
                }
            }
            povratni.push_back(temp);
        }
    }
    return povratni;
}
int main (){
    int smjer;
    std::deque<std::deque<int>> rezultat;
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x>>y>>z;
    if(x<=0||y<=0||z<=0){
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    Kontejner k(x,std::deque<std::deque<int>>(y,std::deque<int>(z)));
    std::cout<<"Unesite elemente kontejnera: ";
    for(int i1=0;i1<x;i1++){
        for(int i2=0;i2<y;i2++){
            for(int i3=0;i3<z;i3++){
                std::cin>>k[i1][i2][i3];
            }
        }
    }
    std::cout<<"\nUnesite smjer kretanja [0 - 5]: ";
    std::cin>>smjer;
    SmjerKretanja niz[6]={SmjerKretanja::NaprijedNazad,SmjerKretanja::NazadNaprijed,SmjerKretanja::GoreDolje,SmjerKretanja::DoljeGore,SmjerKretanja::LijevoDesno,SmjerKretanja::DesnoLijevo};
	switch(smjer){
	    case 0:std::cout<<"NaprijedNazad: \n"; break;
	    case 1:std::cout<<"NazadNaprijed: \n"; break;
	    case 2:std::cout<<"GoreDolje: \n"; break;
	    case 3:std::cout<<"DoljeGore: \n"; break;
	    case 4:std::cout<<"LijevoDesno: \n"; break;
	    case 5:std::cout<<"DesnoLijevo: \n"; break;
        default:{ 
            std::cout<<"Smjer kretanja nije ispravan!\n";
            return 0;
        }
	}
	try{
    	rezultat=IzdvojiDijagonale3D(k,niz[smjer]);
    	for(int i=0;i<rezultat.size();i++){
    	    for(int j=0;j<rezultat.at(0).size();j++){
    	        std::cout<<std::fixed<<std::setw(4)<<rezultat[i][j];
    	    }
    	    std::cout<<std::endl;
    	}
	} catch(std::exception a){
	    std::cout<<"Izuzetak: "<<a.what();
	}
	return 0;
}