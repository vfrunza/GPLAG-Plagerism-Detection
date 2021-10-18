#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <string>
int PotencijalniKrivci(char **& nizovi,std::vector<std::string> imena){
    int brojac=0;
    nizovi=nullptr;
    try{
    nizovi=new char *[imena.size()];
    for(int i=0;i<imena.size();i++) nizovi[i]=nullptr;
    }
    catch(...){
        delete[]nizovi;
        nizovi=nullptr;
        throw std::bad_alloc();
    }
    try{
    for(int i=0;i<imena.size();i++){

        nizovi[i]=new char[imena[i].size()+1];
         brojac++;
        strcpy(nizovi[i],imena[i].c_str());
    }
    }
    catch(...){
        for(int i=0;i<brojac;i++) delete[] nizovi[i];
        delete[]nizovi;
        nizovi=nullptr;
        throw std::bad_alloc();
    }
    return imena.size();
}
int OdbaciOptuzbu(char **& nizovi,int vel,std::string ime){
    bool izbrisan=false;
    for(int i=0;i<vel;i++){
        if(nizovi[i]!=nullptr &&strcmp(nizovi[i],ime.c_str())==0){
            delete[] nizovi[i];
            nizovi[i]=nullptr;
            izbrisan=true;
        }
    }
    if(!izbrisan){
          throw std::domain_error("Osoba sa imenom "+ime+" nije bila optuzena");
    }
    int brojacnulla=0,brojac=0;
    for(int i=0;i<vel;i++){
        if(nizovi[i]==nullptr) brojacnulla++;
        else brojac++;
    }
    if(brojacnulla>=10){
        char **novi=nullptr;
        bool greska=false;int z{};
        try{
        novi=new char *[brojac];
        for(int i=0;i<brojac;i++) novi[i]=nullptr;
        for(int i=0;i<vel;i++){
            if(nizovi[i]!=nullptr){
               novi[z++]=nizovi[i];
            }
        }
        }
        catch(...){
            delete[] novi;
            greska=true;
        }
        if(!greska){
        delete[]nizovi;
        nizovi=novi;
        novi=nullptr;
        vel=z;
        }
    }
    return vel;
}
int DodajOptuzbu(char **& nizovi,int vel,std::string ime){
    char *papak=nullptr;
    try{
    papak=new char[ime.length()+1];
    }
    catch(...){
        delete[] papak;
        throw std::bad_alloc();
    }
    strcpy(papak,ime.c_str());
    bool ubacio=false;
    for(int i=0;i<vel;i++){
        if(nizovi[i]==nullptr){
            ubacio=true;
            nizovi[i]=papak;
            papak=nullptr;
            break;
        }
    }
    if(!ubacio){
        bool uspjelo=false;
        char **novi=nullptr;
        try{
        novi=new char *[vel+1];
        for(int i=0;i<vel+1;i++) novi[i]=nullptr;
        uspjelo=true;
        }
        catch(...){
            delete[] novi;
            throw;
        }
        if(uspjelo){
        for(int i=0;i<vel;i++) novi[i]=nizovi[i];
        delete[] nizovi;
        novi[vel]=papak;
        nizovi=novi;
        vel+=1;
        }
    }
    return vel;
}
void IzlistajOptuzbu(char **niz,int vel){
    for(int i=0;i<vel;i++){
        if(niz[i]!=nullptr) std::cout<<niz[i]<<std::endl;
    }
}
int main ()
{
    std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
    int n; 
    std::cin>>n;
    std::vector<std::string> imena(n);
    std::cout<<"Unesite potencijalne krivce: "<<std::endl;
     std::cin.ignore(10000,'\n');
    for(int i=0;i<n;i++){
        std::cin.clear();
        std::getline(std::cin,imena[i]);
    }
    char **p=nullptr;
    int br=0;
    try{
         br=PotencijalniKrivci(p,imena);
    }catch(std::bad_alloc){
         std::cout << "Neuspjela alokacija" << std::endl;
    }
    for(;;){
        std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
        int f;
        std::cin>>f;
        if(f==0) break;
        if(f==1){
            std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
            std::string ime;
            std::cin.ignore(10000,'\n');
            std::getline(std::cin,ime);
            try{
            br=DodajOptuzbu(p,br,ime);}
            catch(std::bad_alloc){
            std::cout << "Neuspjela alokacija" << std::endl;
            }
        }
        if(f==2){
            std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
            std::string ime;
            std::cin.ignore(10000,'\n');
            std::getline(std::cin,ime);
            try{
            br=OdbaciOptuzbu(p,br,ime);
            }catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what()<<std::endl;
            }
        }
        if(f==3){
            IzlistajOptuzbu(p,br);
        }
    }
    for(int i=0;i<br;i++) delete[] p[i];
    delete[] p;
	return 0;
}