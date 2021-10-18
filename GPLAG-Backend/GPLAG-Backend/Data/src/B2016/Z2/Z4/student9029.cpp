#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
void UnistiMatricu(char **pok, int vel){
    for(int i=0;i<vel;i++)
        delete[] pok[i];
    delete[] pok;
}

int PotencijalniKrivci(char **&imena, std::vector<std::string> vektor){
    try{
        char **pok=new char*[vektor.size()];
        try{
            for(int i=0;i<(int)vektor.size();i++){
                pok[i]=new char[(int)vektor[i].size()+1];
                std::strcpy(pok[i],vektor[i].c_str());
            }
        }catch(std::bad_alloc){UnistiMatricu(pok, (int)vektor.size());throw std::bad_alloc();}
        imena=pok;
        return vektor.size();
    }
    catch(std::bad_alloc){throw std::bad_alloc();}
}

int OdbaciOptuzbu(char **&imena, int velicina, std::string ime){
    bool pronadjeno(false);
    for(int red=0;red<velicina;red++){
        if(imena[red]==nullptr)continue;
        if(std::strcmp(imena[red], ime.c_str())==0){
            pronadjeno=true;
            delete[] imena[red];
            imena[red]=nullptr;
        }
    }
    int broj_izbrisanih(std::count(imena, imena+velicina, nullptr));
    if(broj_izbrisanih>10){
        try{
            char **nova_imena=new char*[velicina-broj_izbrisanih];
            int poz{};
            for(int red_2=0;red_2<velicina;red_2++)
                if(imena[red_2]!=nullptr)
                    nova_imena[poz++]=imena[red_2];
            delete[] imena;
            velicina-=broj_izbrisanih;
            imena=nova_imena;
            }catch(...){}
    }
            
    if(!pronadjeno)
        throw std::domain_error ("Osoba sa imenom "+ime+" nije bila optuzena");
    
    return velicina;
}

int DodajOptuzbu(char **&imena, int velicina, std::string ime){
    try{
    char *pok=new char[(int)ime.size()+1];
    std::strcpy(pok,ime.c_str());
    
    for(int red=0;red<velicina;red++)
        if(imena[red]==nullptr){
            imena[red]=pok;
            return velicina;
        }
    try{
    char **nova_imena=new char*[velicina+1];
    int red{};
    for(red=0;red<velicina;red++)
        nova_imena[red]=imena[red];
    nova_imena[red]=pok;
    delete[] imena;
    imena=nova_imena;
    return velicina+1;
    }catch(...){delete[] pok; throw std::bad_alloc();}
    }catch(...){throw std::bad_alloc();}
}

void IzlistajOptuzbu(char **imena, int velicina){
    for(int ime=0;ime<velicina;ime++){
        if(imena[ime]==nullptr) continue;
        std::string str(imena[ime]);
        std::cout<<std::endl<<str;
    }
}

int main (){
    std::cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
    int pot_krivci;
    std::cin>>pot_krivci;
    std::cout<<"Unesite potencijalne krivce: ";
    std::vector<std::string> krivci;
    std::cin.ignore(100,'\n');
    for(int i=0;i<pot_krivci;i++){
        std::string ime;
        std::getline(std::cin, ime);
        krivci.push_back(ime);
    }
    char **nizPotencijalnih;
    int velicina=PotencijalniKrivci(nizPotencijalnih, krivci);
    int opcija;
    while(std::cout<<"\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " && std::cin>>opcija && opcija!=0){
        std::cin.ignore(1000,'\n');
        if(opcija==0) break;
        if(opcija==1){
            std::cout<<"\nUnesite ime novog optuzenog: ";
            std::string ime;
            std::getline(std::cin, ime);
            try{
            velicina=DodajOptuzbu(nizPotencijalnih, velicina, ime);
            }catch(...){}
        }
        if(opcija==2){
            std::cout<<"\nUnesite ime koje zelite izbaciti: ";
            std::string ime;
            std::getline(std::cin, ime);
            try{
            velicina=OdbaciOptuzbu(nizPotencijalnih, velicina, ime);
            }catch(std::domain_error izuzetak){std::cout<<izuzetak.what()<<std::endl;}
        }
        if(opcija==3){IzlistajOptuzbu(nizPotencijalnih, velicina);}
    }
    
    UnistiMatricu(nizPotencijalnih, velicina);
    
	return 0;
}