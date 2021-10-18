// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
enum class SmjerKretanja {NaprijedNazad=0, NazadNaprijed=1, GoreDolje=2, DoljeGore=3, LijevoDesno=4, DesnoLijevo=5};
//definisanje smjera kretanja

template <typename lopata>
auto IzdvojiDijagonale3D(lopata D, SmjerKretanja smjer) -> typename std::remove_reference<decltype(D.at(0))>::type {
    typename std::remove_reference<decltype(D.at(0))>::type izlaz(D.size()); //napravljen izlaz
    switch(smjer){
        // NIJE PODRŽANO INDEKSIRANJE, KORISTITI .at(); !!!
        case SmjerKretanja::NaprijedNazad:{
            //glavna dijagonala D[0] u prvu vrstu izlaza, glavnu od D[1] u drugu... itd...;
            izlaz.resize(D.size()); //treba onoliko vrsta izlaza koliko ima matrica ulaza.
            for(int i=0;i<D.size();i++){
                //ide po matricama.
                for(int j=0;j<D.at(i).size();j++){
                    //ide po vrstama matrica.
                    for(int k=0;k<D.at(i).at(j).size();k++){
                        //ide po kolonama matrica.
                        if(j==k) izlaz.at(i).push_back(D.at(i).at(j).at(k));
                        //šutaj glavnu dijagonalu i-te matrice u i-ti red izlaza.
                    }
                }
            }
          break;  
        }
        case SmjerKretanja::NazadNaprijed:{
        //sporedna dijagonala D[0] u prvu vrstu izlaza, sporednu od D[1] u drugu... itd...;
            izlaz.resize(D.size()); //treba onoliko vrsta izlaza koliko ima matrica ulaza.
            for(int i=0;i<D.size();i++){
                //ide po matricama.
                for(int j=0;j<D.at(i).size();j++){
                    //ide po vrstama matrica.
                    for(int k=D.at(i).at(j).size()-1;k>=0;k--){
                        //ide po kolonama matrica.
                        if(k+j == D.at(i).at(j).size()-1) izlaz.at(i).push_back(D.at(i).at(j).at(k));
                        //šutaj glavnu dijagonalu i-te matrice u i-ti red izlaza.
                    }
                }
            }typename std::remove_reference<decltype(D.at(0))>::type izlaz1(D.size());
            int k=0;
            for(int i=izlaz.size()-1;i>=0;i--){
                izlaz1.at(k++)=izlaz.at(i);
            }
            for(int i=0;i<izlaz.size();i++){
                izlaz.at(i)=izlaz1.at(i);
            }
          break;    
        }
        case SmjerKretanja::DesnoLijevo:{
            int velicina = D.at(0).at(0).size()-1;// velicina prve vrste (-1 prvi legalan index)
            for(int i=0;i<D.at(0).at(0).size();i++){ // ide po prvoj vrsti 
            izlaz.resize(izlaz.size()+1);
                for(int j=0;j<D.size();j++){ 
                    int k=0;// ide po broju matrica
                    izlaz.at(i).push_back(D.at(j).at(j).at(velicina-k));
                    k++;
                }
                velicina--;
            }
          break;    
        }
        case SmjerKretanja::LijevoDesno:{
//          int velicina = D.at(0).at(0).size()-1;// velicina prve vrste (-1 prvi legalan index)
            for(int i=0;i<D.at(0).at(0).size();i++){ // ide po prvoj vrsti 
            izlaz.resize(izlaz.size()+1);
            int k=0;
                for(int j=D.size()-1;j>=0;j--){ 
                    // ide po broju matrica odzada
                    izlaz.at(i).push_back(D.at(j).at(k).at(i));
                 k++;
                }
//                velicina--;
            } 
          break;
        }
        case SmjerKretanja::GoreDolje:{
            for(int i=0;i<D.at(0).size();i++){
                int k=0;
                izlaz.resize(izlaz.size()+1);
                for(int j=D.size()-1;j>=0;j--){
                    izlaz.at(i).push_back(D.at(j).at(i).at(k++));
                }
            }
          break;    
        }
        case SmjerKretanja::DoljeGore:{
           for(int i=D.at(0).size()-1;i>=0;i--){
               izlaz.resize(izlaz.size()+1);
               int k=D.at(0).at(0).size()-1;
               for(int j=D.size()-1;j>=0;j--){
                   izlaz.at(i).push_back(D.at(j).at(i).at(k--));
               }
           }
           
           typename std::remove_reference<decltype(D.at(0))>::type izlaz1(D.size());
            int k=0;
            izlaz1.resize(izlaz.size());
            for(int i=izlaz.size()-1;i>=0;i--){
                izlaz1.at(k++)=izlaz.at(i);
            }
            for(int i=0;i<izlaz.size();i++){
                izlaz.at(i)=izlaz1.at(i);
            }
          break;    
        }
        default : return izlaz;
        ;
        
    }
    return izlaz;    
}
typedef std::deque<std::vector<short int>> matrica;
int main (){
    try{
std::cout<<"Unesite dimenzije (x y z): ";
int x,y,z;
std::cin>>x>>y>>z;
if(x<0 || y<0 || z<0) throw std::range_error("Neispravne dimenzije kontejnera!");
std::deque<matrica> kont(x,matrica(y,std::vector<short int>(z)));
std::cout<<"Unesite elemente kontejnera: "<<std::endl;
for(int i=0;i<kont.size();i++){
    for(int j=0;j<kont.at(i).size();j++){
        for(int k=0;k<kont.at(i).at(j).size();k++){
            std::cin>>kont.at(i).at(j).at(k);
        }
    }
}
std::cout<<"Unesite smjer kretanja [0 - 5]: "; 
int smjer;
std::cin>>smjer;
try{
matrica izlaz = IzdvojiDijagonale3D(kont,(SmjerKretanja)(smjer));
switch(smjer){
    case 0:{std::cout<<"NaprijedNazad: "<<std::endl;break;}
    case 1:{std::cout<<"NazadNaprijed: "<<std::endl;break;}
    case 2:{std::cout<<"GoreDolje: "<<std::endl;break;}
    case 3:{std::cout<<"DoljeGore: "<<std::endl;break;}
    case 4:{std::cout<<"LijevoDesno: "<<std::endl;break;}
    case 5:{std::cout<<"DesnoLijevo: "<<std::endl;break;}
    default : throw std::domain_error("Smjer kretanja nije ispravan!\n");
}
for(int i=0;i<izlaz.size();i++){
    if(!izlaz.at(i).size()) continue;
    for(int j=0; j<izlaz.at(i).size();j++){
        std::cout<<std::setw(4)<<izlaz.at(i).at(j);
    }
    std::cout<<std::endl;
}
}catch(std::domain_error &ex){std::cout<<ex.what();}}catch(std::range_error &ex){std::cout<<ex.what();}
    return 0;
}