/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <memory>


struct Cvor {
    std::string ime;
    std::shared_ptr<Cvor> sljedeci;
};



std::vector<std::set<std::string>>  Razvrstavanje(std::vector<std::string> imena, int br_timova) {
    std::shared_ptr<Cvor> pocetak(nullptr);
    std::shared_ptr<Cvor>prethodni(nullptr);
    
    std::vector<std::set<std::string>> vrati;
    
    for(int i=0;i<imena.size();i++){
        std::shared_ptr<Cvor>  novi(std::make_shared<Cvor>());
        novi->ime=imena[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    std::set<std::string> skup;
    int br_ljudi;
    br_ljudi=imena.size();
    int viseclanova=br_ljudi%br_timova;
    int inc=imena.size()/br_timova;
    
    bool u(false);
    int vise=0, in=0;
    for(int i=0;i<imena.size();i++){
        
        in++;
        int broj=pocetak->ime.length();
          skup.insert(pocetak->ime);
        if (in==inc)
        {
            if (vise<viseclanova && !u) 
            {
                
                vise++;
                in--;
                u=!u;
            }
            else
            {
                vrati.push_back(skup);
                skup.clear();
                in=0;
                u=false;
            }
        }
     
    if (i!=imena.size()-1)
        {
            prethodni=pocetak->sljedeci;
            while(prethodni->sljedeci!=pocetak) prethodni=prethodni->sljedeci;
          
            pocetak=pocetak->sljedeci;
            std::shared_ptr<Cvor> pom=prethodni->sljedeci;
            pom=nullptr;
            prethodni->sljedeci=pocetak;
            
            int j=0;
            while (j+1!=broj) 
            {
                pocetak=pocetak->sljedeci;
                j++;
            }
        }
        else
        {  
            
            pocetak=nullptr;
            prethodni=nullptr;
            
        }
   
   
    
        
        }
    
    int br=0;
    for (int i=0;i<vrati.size();i++)
    {
        br=0;
        std::cout<<"Tim "<<i+1<<": ";
        for (auto a : vrati[i])
        { 
            br++;
            
            if(br<vrati[i].size() ) 
            std::cout <<a<<", ";
            else std::cout<<a<<" ";
           
        }
        std::cout << std::endl;
    }
    
    
   /* Cvor *pom=pocetak;
    int br(0);
    while (pom!=pocetak || br==0) 
    {
        std::cout << pom->ime << " ";
        pom=pom->sljedeci;
        br++;
    }*/
    
    
    return vrati;
}




int main ()
{
   try{
    int br_djece;
    std::vector<std::string> imena_djece;
    
    std::cout<<"Unesite broj djece: ";
    std::cin>>br_djece;
    
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore(1000,'\n');
        for(int i=0;i<br_djece;i++)
    {
        std::string pom;
        std::getline(std::cin,pom);
        
        imena_djece.push_back(pom);
        
    }
    int br_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>br_timova;
    if(br_timova<1 || br_timova>br_djece) throw std::logic_error ("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> kraj;
    kraj=Razvrstavanje(imena_djece,br_timova);
    
   }
   catch(...) {
       throw "Ne moze";
       return 0;
   }
    
	return 0;
}