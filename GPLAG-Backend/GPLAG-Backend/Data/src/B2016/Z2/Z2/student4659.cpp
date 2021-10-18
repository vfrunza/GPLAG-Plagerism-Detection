// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>
#include <stdexcept>
enum class SmjerKretanja { NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template <typename Tip>
auto IzdvojiDijagonale3D(Tip a,SmjerKretanja r)->typename std::remove_reference<decltype(a[0])>::type{
    for(int i=0;i<a.size();i++)if(a[0].size()!=a[i].size() )throw std::domain_error("Plohe nemaju isti broj redova");
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++)if(a[0][0].size()!=a[i][j].size())throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    int n=static_cast<int>(r);
    if(a.empty()){ 
        typename std::remove_reference<decltype(a[0])>::type x;
        return x;
    }
    if(n==0 || n==1){
        typename std::remove_reference<decltype(a[0])>::type x(a.size());
        int k=a[0][0].size()-1;
        for(int j=0;j<a[0].size();j++){
            for(int i=0;i<a.size();i++){
                    if(n==0)x[i].push_back(a[i][j][j]);
                    if(n==1)x[i].push_back(a[a.size()-1-i][j][k]);
            }
            k--;
        }
        return x;
    }
    if(n==2 || n==3){
        typename std::remove_reference<decltype(a[0])>::type x(a[0].size());
        int i=a.size()-1;
            for(int k=0;k<a.size();k++){
                for(int j=0;j<a[i].size();j++){
                    if(n==2)x[j].push_back(a[i][j][k]);
                    if(n==3)x[j].push_back(a[i][a[0].size()-1-j][a[i][0].size()-1-k]);
                }
                if(i==a.size()-a[0].size())break;
                i--;
            }
        return x;
    }
    if(n==4 || n==5){
        typename std::remove_reference<decltype(a[0])>::type x(a[0][0].size());
            for(int j=0;j<x.size();j++){
                int i=a.size()-1;
                for(int k=0;k<a.size();k++){
                    if(n==4)x[j].push_back(a[i][k][j]);
                    if(n==5)x[j].push_back(a[k][k][x.size()-1-j]);
                    i--;
                }
            }
        return x;    
    }
}

int main ()
{
try{
    std::vector<std::deque<std::deque<int>>> a;
    std::deque<std::deque<int>> b;
    int smjer(0);
do{ 
    int x(0),y(0),z(0);
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0)throw std::domain_error("Neispravne dimenzije kontejnera!");
        a.resize(x);
        for(int i=0;i<x;i++)a[i].resize(y);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                a[i][j].resize(z);
            }
        }
        std::cout << "Unesite elemente kontejnera: " << std::endl;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    std::cin >> a[i][j][k];
                }
            }
        }
        
        std::cout << "Unesite smjer kretanja [0 - 5]: " ;
        std::cin >> smjer;
        
        if(smjer<0 || smjer>5){
            std::cout << "Smjer kretanja nije ispravan!" << std::endl;
            return 0;
        }    
        
    }while(smjer<0 || smjer>5);    

    SmjerKretanja r=static_cast<SmjerKretanja>(smjer);
   
        b=IzdvojiDijagonale3D(a,r);
            if(smjer==0)std::cout << "NaprijedNazad: " << std::endl;
            if(smjer==1)std::cout << "NazadNaprijed: " << std::endl;
            if(smjer==2)std::cout << "GoreDolje: " << std::endl;
            if(smjer==3)std::cout << "DoljeGore: " << std::endl;
            if(smjer==4)std::cout << "LijevoDesno: " << std::endl;
            if(smjer==5)std::cout << "DesnoLijevo: " << std::endl;
         
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                std::cout << std::setw(4) << b[i][j] ;
            }
            std::cout << std::endl;
        }    

    }
    catch(std::domain_error e){
        std::cout << e.what() << std::endl;
        return 0;
    }

	return 0;
}