// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iomanip>
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename MojTip>
auto IzdvojiDijagonale3D(MojTip kont, SmjerKretanja smjerovi)-> typename std::remove_reference<decltype(kont.at(0))>::type{
typedef typename std::remove_reference<decltype(kont.at(0))>::type Matrica;
typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
Matrica Mat2d;

    for(int i=0;i<kont.size();i++){
        for(int j=0;j<kont.at(i).size();j++){
            for(int k=0;k<kont.at(i).at(j).size();k++){
                if(kont.at(0).at(0).size()!=kont.at(i).at(j).size())throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
        }
    }
    /*for(int i=0;i<kont.size();i++){
        for(int j=0;j<kont.at(i).size();j++){
            for(int k=0;k<kont.at(i).at(j).size();k++){
                if(kont.at(0).size()!=kont.at(i).size())throw std::domain_error("Plohe nemaju isti broj redova");
            }
        }
    }*/
    for(int i=0;i<kont.size();i++){
        for(int j=i+1;j<kont.size()-1;j++){
            if(kont.at(i).size()!= kont.at(j).size())throw std::domain_error("Plohe nemaju isti broj redova");
        }
    }
    if(kont.size()==0 ||  kont.at(0).at(0).size()==0 ||  kont.at(0).size()==0)return Mat2d;
    if(kont.size()==1 && kont.at(0).at(0).size()==1 && kont.at(0).size()==1){
    vektor neki;
    neki.push_back(kont.at(0).at(0).at(0));
    Mat2d.push_back(neki);
    return Mat2d;
}
    if(smjerovi==SmjerKretanja::NaprijedNazad){
        for(int i=0;i<kont.size();i++){
            Mat2d.resize(Mat2d.size()+1);
            for(int j=0;j<kont.at(i).size();j++){
                vektor neki;
                
                for(int k=0;k<kont.at(i).at(j).size();k++){
                    if(j==k)Mat2d.at(i).push_back(kont.at(i).at(j).at(k));
                }
                
            }
        }
    }
    else if(smjerovi==SmjerKretanja::NazadNaprijed){
        for(int i=0;i<kont.size();i++){
            Mat2d.resize(Mat2d.size()+1);
           // int zadnji=kont.at(i).size()-i-1;
            for(int j=0;j<kont.at(i).size();j++){
               // int zadnji=kon.at(i).size()-i-1;
                for(int k=0;k<kont.at(i).at(j).size();k++){
                    if(k+j==kont.at(i).at(j).size()-1)Mat2d.at(i).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        Matrica nova;
         nova.resize(Mat2d.size());
         int brojac(0);
         for(int i=Mat2d.size()-1;i>=0;i--){
            nova[brojac++].resize(Mat2d[i].size());
            for(int j=0;j<Mat2d[i].size();j++){
                nova[Mat2d.size()-1-i][j]=Mat2d[i][j];
            }
        }
        return nova;
    }
    else if(smjerovi==SmjerKretanja::GoreDolje){
        int brojac(0);
        for(int i=kont.size()-1;i>=0;i--){
            for(int j=0;j<kont.at(i).size();j++){
                Mat2d.resize(Mat2d.size()+1);
                for(int k=0;k<kont.at(i).at(j).size();k++){
                    if(k==brojac)Mat2d.at(j).push_back(kont.at(i).at(j).at(k));
                }
            }
            brojac++;
        }
    }
    else if(smjerovi==SmjerKretanja::DoljeGore){
         for(int i=kont.size()-1;i>=0;i--){
            int brojac(0);
            for(int j=kont.at(i).size()-1;j>=0;j--){
                Mat2d.resize(Mat2d.size()+1);
                for(int k=kont.at(i).at(j).size()-1;k>=0;k--){
                    if(kont.at(i).at(j).size()==2){
                   if(k==i ) Mat2d.at(brojac).push_back(kont.at(i).at(j).at(k));}
                    else{
                        if(k-i==kont.size())Mat2d.at(brojac).push_back(kont.at(i).at(j).at(k));
                    }
                }
                brojac++;
                }
            }  
             
         }
    
    else if(smjerovi==SmjerKretanja::DesnoLijevo){
        for(int i=0;i<kont.size();i++){
            for(int j=0;j<kont.at(i).size();j++){
                int brojac(0);
                for(int k=kont.at(i).at(j).size()-1;k>=0;k--){
                    Mat2d.resize(Mat2d.size()+1);
                    if(i==j)Mat2d.at(brojac).push_back(kont.at(i).at(j).at(k));
                    brojac++;
                }
            }
        }
    }
    else if(smjerovi==SmjerKretanja::LijevoDesno){
        int brojac1(0);
        for(int i=kont.size()-1;i>=0;i--){
           // int brojac1(0);
            for(int j=0;j<kont.at(i).size();j++){
               int brojac(1);
                for(int k=0;k<kont.at(i).at(j).size();k++){
                    Mat2d.resize(Mat2d.size()+1);
                    if(j+k==brojac)Mat2d.at(k).push_back(kont.at(i).at(brojac1).at(k));
                     brojac++;
                }}
           brojac1++;
            
        }
    }
    
    return Mat2d;
}
int main ()
{
    //#include <string>
//AT28#include (zamger): stringovi: GoreDolje (2x3x2)
  /*  std::deque<std::vector<std::deque<std::string>>> kont = {
        {
            {"AT6", "Dva"},
            {"AT4", "Cetiri"},
            {"AT2", "Sest"}
        },
        {
            {"Jedan", "AT5"},
            {"Tri", "AT3"},
            {"Pet", "AT1"}
        }
    };

    std::vector<std::deque<std::string>> d = IzdvojiDijagonale3D(kont, SmjerKretanja::DoljeGore);
    for (const auto &r : d)
    {
        for (const auto &x : r)
            std::cout << x << " ";
        std::cout << std::endl;
    }*/


  
    int n,m,l;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>n;
    std::cin>>m;
    std::cin>>l;
    if(m<0|| n<0 || l<0){std::cout<<"Neispravne dimenzije kontejnera!"<<std::endl;return 0;}
    std::vector<std::deque<std::vector<int>>>triD;
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    for(int i=0;i<n;i++){
        std::deque<std::vector<int>> dek;
        for(int j=0;j<m;j++){
            std::vector<int>v1;
            for(int k=0;k<l;k++){
                int broj;
                std::cin>>broj;
                v1.push_back(broj);
            }
          dek.push_back(v1);
        }
       triD.push_back(dek);
    }
    int broj;
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    std::cin>>broj;
    SmjerKretanja smjer;
    if(broj==0){
        smjer=SmjerKretanja::NaprijedNazad;
        std::cout<<"NaprijedNazad: "<<std::endl;
    }
    else if(broj==1){
        smjer=SmjerKretanja::NazadNaprijed;
        std::cout<<"NazadNaprijed: "<<std::endl;
    }
    else if(broj==2){
        smjer=SmjerKretanja::GoreDolje;
        std::cout<<"GoreDolje: "<<std::endl;
    }
    else if(broj==3){
        smjer=SmjerKretanja::DoljeGore;
        std::cout<<"DoljeGore: "<<std::endl;
    }
    else if(broj==4){
        smjer=SmjerKretanja::LijevoDesno;
        std::cout<<"LijevoDesno: "<<std::endl;
    }
    else if(broj==5){
        smjer=SmjerKretanja::DesnoLijevo;
        std::cout<<"DesnoLijevo: "<<std::endl;
    }
    else{
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
    try{
        auto Matrica(IzdvojiDijagonale3D(triD,smjer));
        for(int i=0;i<Matrica.size();i++){
            for(int j=0;j<Matrica[i].size();j++){
                std::cout<<std::setw(4)<<Matrica[i][j];
            }
            std::cout<<std::endl;
        }
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
  return 0;  
} 