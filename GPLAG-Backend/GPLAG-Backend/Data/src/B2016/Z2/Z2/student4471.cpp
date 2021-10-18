// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <type_traits>
#include <deque>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <iomanip>

enum class SmjerKretanja{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};


int min(int x,int y){
    if(x<=y)return x;
    return y;
}

template <typename Tipkontenjera>
auto IzdvojiDijagonale3D(Tipkontenjera kont,SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type{
    
    typedef typename std::remove_reference<decltype(kont.at(0))>::type kontenjer;
    
    for(auto &ploha: kont){
        for(auto &red: ploha){
            if(red.size() != kont.at(0).at(0).size())throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    
    for(auto &ploha: kont){
        if(ploha.size() != kont.at(0).size())throw std::domain_error("Plohe nemaju isti broj redova");
    }
    
    
    int x = kont.size();     //2
    int y = kont.at(0).size();    //3   
    int z = kont.at(0).at(0).size();    //4
    
    //provjera prazne matrice
    if(x == 0 || y==0 || z==0){
        kontenjer v;
        return v;
    }
    
    int br_red(0),br_kol(0);
    if(int(smjer)<=1){
        br_red = x;
        br_kol = min(y,z);
    }else if(int(smjer)<=3){
        br_red = y;
        br_kol = min(x,z);
    }else if(int(smjer)<=5){
        br_red = z;
        br_kol = min(x,y);
    }
    kontenjer v(br_red);
    
    if(int(smjer)==0){
        
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    if(j==k){
                        v.at(i).push_back(kont.at(i).at(j).at(k));
                    }
                }
            }
        }
        return v;
    }else if(int(smjer)==1){
  
        for(int i=x-1;i>=0;i--){
                for(int j=0;j<y;j++){
                    for(int k=0;k<z;k++){
                        //uslov za sporednu dijagonalu !!!!
                        if(k+j==z-1){
                                        

                            v.at(x-i-1).push_back(kont.at(i).at(j).at(k));
                        }
                }
            }
                            
        }
        
        return v;
        //goredolje!
    }else if(int(smjer)==2){
        
        int h=0,g=0;
        kontenjer t(br_kol);
        for(int i=x-1;i>=0;i--){
            for(int j=0;j<y;j++){
           t.at(h).push_back(kont.at(i).at(j).at(h));
           
        }
        h++;
        }
        
        //sada obrcemo !!!
        for(int i=0;i<br_kol;i++){
            for(int j=0;j<br_red;j++){
               // v[j][i] = t[i][j];
                v.at(j).push_back(t.at(i).at(j));
            }
        }
        
        return v;
    }else if(int(smjer)==3){
        
        int h=0,g=kont.at(0).at(0).size()-1;                        //ovdje bilo samo g = kont.at(0).size();
        kontenjer t(br_kol);
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
           t.at(h).push_back(kont.at(i).at(j).at(g));
           
        }
        g--;
        h++;
        }
        
        //sada obrcemo !!!
        for(int i=0;i<br_kol;i++){
            for(int j=0;j<br_red;j++){
               // v[j][i] = t[i][j];
                v.at(j).push_back(t.at(i).at(j));
            }
        }
        
        return v;
        
    }else if(int(smjer)==4){
        
        kontenjer t(br_kol);
        int h = 0;
        int g=0;
        for(int i=x-1;i>=0;i--){
            for(int j=g;j<y;j++){
                for(int k=0;k<kont.at(i).at(j).size();k++){
                    t[h].push_back(kont.at(i).at(j).at(k));
                }
                g++;
                h++;
                break;
                
            }
        }
        
        //sada obrcemo !
        
        for(int i=0;i<br_kol;i++){
            for(int j=0;j<br_red;j++){
               
                v.at(j).push_back(t.at(i).at(j));
            }
        }
        
        return v;
    

    
    }else if(int(smjer)==5){
        
        kontenjer t(br_kol);
        int h = 0;
        int g=0;
        for(int i=0;i<x;i++){
            for(int j=g;j<y;j++){
                for(int k=kont.at(i).at(j).size()-1;k>=0;k--){
                    t[h].push_back(kont.at(i).at(j).at(k));
                }
                g++;
                h++;
                break;
                
            }
        }
        
        //sada obrcemo !
        
        for(int i=0;i<br_kol;i++){
            for(int j=0;j<br_red;j++){
               
                v.at(j).push_back(t.at(i).at(j));
            }
        }
        
        return v;
    
    }
    

}






int main ()
{
   // std::vector<std::vector<std::vector<double>>> v;
    
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x>>y>>z;
    if(x<0 || y<0 || z<0){
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    
 
    std::vector<std::vector<std::vector<double>>> v(x,std::vector<std::vector<double>>(y,std::vector<double>(z)));

    std::cout<<"Unesite elemente kontejnera: \n";
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                std::cin>>v.at(i).at(j).at(k);
            }
        }
    }
    
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin>>smjer;
    
    if(int(smjer)<0 || int(smjer)>5 ){
        std::cout<<"Smjer kretanja nije ispravan!\n";
        return 0;
    }
    
    try{
   auto  t = IzdvojiDijagonale3D(v,SmjerKretanja(smjer));
    if(smjer==0){
        std::cout<<"NaprijedNazad: \n";
    }else if(smjer == 1){
        std::cout<<"NazadNaprijed: \n";
    }else if(smjer==2){
        std::cout<<"GoreDolje: \n";
    }else if(smjer == 3){
        std::cout<<"DoljeGore: \n";
    }else if(smjer==4){
        std::cout<<"LijevoDesno: \n";
    }else if(smjer==5){
        std::cout<<"DesnoLijevo: \n";
    }
     
     
     
    for(int i=0;i<t.size();i++){
        for(int j=0;j<t.at(i).size();j++){
            std::cout<<std::setw(4)<<t[i][j];
        }
        std::cout<<std::endl;   
    }
    }catch(std::domain_error temp){std::cout<<temp.what();}
   
    
    
	return 0;
}




    