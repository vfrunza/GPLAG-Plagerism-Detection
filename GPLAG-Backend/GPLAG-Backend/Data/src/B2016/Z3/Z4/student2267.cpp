/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v_string,int k){
    
    if(k==0 || k>v_string.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> v_skup;
    std::list<std::string>djecica;
    std::vector<int> br_clanova;
    int n=v_string.size();
    int temp=(int)(n%k);
    int poc=(int)((n/k)+1);
    int ostatak=n/k;
    int brojac(0);
    if(temp!=0){
        while(brojac<temp){
            br_clanova.push_back(poc);
            brojac++;
        }
        
    while(brojac<k){
        br_clanova.push_back(ostatak);
        brojac++;
    }   
    }
    
    else if(temp==0){
        while(brojac<k){
            br_clanova.push_back(ostatak);
            brojac++;
        }
    }
    
    for(int i=0;i<v_string.size();i++){
        djecica.push_back(v_string[i]);
    }
   
    std::list<std::string>::iterator it;
    it=djecica.begin();
    int pomjeri;
    int i(0),idi_dalje(0);
    it=djecica.begin();  
    while(idi_dalje<k){
      std::set<std::string> skup;
      int keep_going(0);
       while(keep_going<br_clanova[i]){
         std::string rijec;
        rijec=*it;
         int br(0),duzina(0),o(0);
         //Brojimo slova
        while(o<rijec.size()){
            if((rijec[o]>='A' && rijec[o]<='Z') || (rijec[o]>='a' && rijec[o]<='z') || (rijec[o]>='0' && rijec[o]<='9'))
                duzina++;
            o++;
        } 
        skup.insert(rijec);
        std::list<std::string>::iterator kraj;
        kraj=djecica.end();
        kraj--;
        pomjeri=duzina;
        if(it!=kraj)
           pomjeri--;
        it=djecica.erase(it);
        std::list<std::string>::iterator kraj_liste;
        kraj_liste=djecica.end();
        kraj_liste--;
         int m(0);
         std::list<std::string>::iterator pom;
         pom=it;
        while(m<pomjeri){
            if(pom==(kraj_liste)) { 
            pom=djecica.begin(); m+=1; continue;}
            pom++;
            m++;
        }
            it=pom;
            keep_going++;
        }
      
     idi_dalje++;
     i++;
     v_skup.push_back(skup);
    
    }
 

return v_skup;
}

int main ()
{
  
    int br_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>br_djece;
    std::vector<std::string> v_djeca;
    std::cout<<"Unesite imena djece: ";
    std::cout<<std::endl;
    std::cin.ignore(1000,'\n');
    int i(0);
    while(i<br_djece){
        std::string rijec;
        std::getline(std::cin,rijec);
        v_djeca.push_back(rijec);
        i++;
    }
    int br_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>br_timova;
        try{
           std::vector<std::set<std::string>> v(Razvrstavanje(v_djeca,br_timova));
           
        }
          
        catch(std::logic_error poruka){
             std::cout<<"Izuzetak: "<<poruka.what();
             return 0;
        }
     
        for(int i=0;i<br_timova;i++){
        std::set<std::string>skup;
        std::vector<std::set<std::string>> v(Razvrstavanje(v_djeca,br_timova)); 
        skup=v[i];
        std::cout<<"Tim "<<i+1<<": ";
        std::set<std::string>::iterator it;
        it=skup.begin();
        int brojac(0);
        while(it!=skup.end()){
            if(brojac==skup.size()-1) {
                std::cout<<*it;
                break;
            }
            std::cout<<*it<<", ";
            it++;
            brojac++;
        }
      
        std::cout<<std::endl;
    }

  
	return 0;
}