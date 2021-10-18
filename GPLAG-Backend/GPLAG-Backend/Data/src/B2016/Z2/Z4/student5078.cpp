/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <string>
#include <vector>
#include <new>
#include <iostream>
#include <stdexcept>
#include <malloc.h>
#include <cstdlib>
#include <stdlib.h>

int PotencijalniKrivci(char** &pok_imena,std::vector<std::string> spisak_imena){
	pok_imena=nullptr;
	try{
		pok_imena=new char*[spisak_imena.size()];
	}
	catch(...){
		delete[] pok_imena;
		throw std::bad_alloc();
	}
	for(int i=0;i<spisak_imena.size();i++){
		pok_imena[i]=nullptr;
	}
	try{
		for(int i=0;i<spisak_imena.size();i++){
			pok_imena[i]=new char[spisak_imena[i].size()+1];
		}
	}
	catch(...){
		for(int i=0;i<spisak_imena.size();i++){
			delete[] pok_imena[i];
		}
		delete[] pok_imena;
		throw std::bad_alloc();
	}
	for(int i=0;i<spisak_imena.size();i++){
		for(int j=0;j<spisak_imena[i].size();j++){
			pok_imena[i][j]=spisak_imena[i][j];
			if(j==spisak_imena[i].size()-1){
				pok_imena[i][j+1]='\0';
				j++;
				break;
			}
		}
	}
	return spisak_imena.size();
}

int OdbaciOptuzbu(char** &pok_imena,int broj_rijeci,std::string ime){
	int brojac_rijeci=0;
	int brojac_nulpok=0;
	int sacuvaji=0;
	bool status(false);
	for(int i=0;i<broj_rijeci;i++){
        status=false;
        if(pok_imena[i]==nullptr){
                brojac_nulpok++;continue;
        }
		for(int j=0;j<ime.size();j++){
            if(pok_imena[i][j]==ime[j])brojac_rijeci++;
            if(pok_imena[i][j]!=ime[j]){break;}
            if(brojac_rijeci==ime.size()-1){status=true;break;}
		}
		sacuvaji=i;
		if(status)break;
	}
    if(sacuvaji+1!=broj_rijeci){
        delete[] pok_imena[sacuvaji];
        pok_imena[sacuvaji]=nullptr;
        brojac_nulpok++;
        }
    if(sacuvaji+1==broj_rijeci){
        std::string throwstring{"Osoba sa imenom "};
        throwstring=throwstring+ime;
        throwstring=throwstring+(" nije bila optuzena");
        throw std::domain_error(throwstring);
		}
    //_____________________________________________________//
    if(brojac_nulpok==10){
        char** nova_kopija=nullptr;
        nova_kopija=new char*[broj_rijeci-brojac_nulpok];
        int j=0;
        for(int i=0;i<broj_rijeci;i++){
            if(pok_imena[i]==nullptr){
                    delete[] pok_imena[i];
                continue;
            }
            else{
                int vel=0;
                auto setac=pok_imena[i];
                while(*(setac+vel)!='\0'){
                    vel++;
                }
                nova_kopija[j]=new char[vel+1];
                for(int k=0;k<=vel;k++){
                nova_kopija[j][k]=pok_imena[i][k];
                }
                delete[] pok_imena[i];
                j++;
            }
            if(j==broj_rijeci-brojac_nulpok)break;
        }
    delete[] pok_imena;
    pok_imena=nova_kopija;
    broj_rijeci=broj_rijeci-brojac_nulpok;
    }
	return broj_rijeci;
}
int DodajOptuzbu(char** &pok_imena,int &broj_rijeci,std::string ime){
    int broj_nullptr=0;
    for(int i=0;i<broj_rijeci;i++){
        if(pok_imena[i]==nullptr){
            broj_nullptr++;
            pok_imena[i]=new char[ime.size()+1];
            for(int j=0;j<ime.size();j++){
                pok_imena[i][j]=ime[j];
                if(j==ime.size()-1){
                    pok_imena[i][j+1]='\0';
                    return broj_rijeci;
                }
            }
        }
    }
    auto pok_imena_kopija=pok_imena;
    if(broj_nullptr==0){
        int limit=broj_rijeci;
        broj_rijeci++;
        try{
            pok_imena=new char*[limit+1];

        }
        catch(...){
            delete[] pok_imena;
            pok_imena=pok_imena_kopija;
            throw std::bad_alloc();
        }
        try{
            for(int i=0;i<=limit;i++){
                int j=0;
                if(i<limit){
                    while(pok_imena_kopija[i][j]!='\0'){
                    j++;
                    }
                }
                if(i==limit){pok_imena[i]=new char[ime.size()+1];break;}
                pok_imena[i]=new char[j+1];
            }
        }
        catch(...){
            throw std::bad_alloc();
        }
        auto setaj=pok_imena_kopija;
        for(int i=0;i<=limit;i++){
            int j=0;
            while(i<limit){
                pok_imena[i][j]=setaj[i][j];
                if(setaj[i][j]=='\0'){
                    delete[] setaj[i];
                    break;
                }
            j++;
            }
            if(i==limit){
                for(int k=0;k<ime.size();k++){
                    pok_imena[i][k]=ime[k];
                    if(k==ime.size()-1){
                        pok_imena[i][k+1]='\0';
                    }
                }
            }
        }
        delete[] setaj;
    }

    return broj_rijeci;
}
void IzlistajOptuzbu(char** pok_imena, int broj_rijeci){
	for(int i=0;i<broj_rijeci;i++){
        if(pok_imena[i]==nullptr)continue;
		char *setac=pok_imena[i];
		while(*setac!='\0'){
			std::cout<<*setac;
			setac++;
			if(*setac=='\0')break;
		}std::cout<<std::endl;
	}
}
int main ()
{
    char **pok_pok=nullptr;
	std::vector<std::string> spisak_imena;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int br_krivaca;
	std::cin>>br_krivaca;
	spisak_imena.resize(br_krivaca);
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
    for(int i=0;i<br_krivaca;i++){
        std::string rijec;
        std::cin>>rijec;
        spisak_imena[i]=(rijec);
    }
    PotencijalniKrivci(pok_pok,spisak_imena);
    int komanda;
    while(1){
        std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
        std::cin>>komanda;
        if(komanda==2){
        	std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
            std::string ime;
            std::cin>>ime;
            try{
                br_krivaca=OdbaciOptuzbu(pok_pok,br_krivaca,ime);
                }
            catch(std::domain_error grsk){
                std::cout<<grsk.what()<<std::endl;
                }
            continue;
        }
        if(komanda==1){
        	std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
            std::string ime;
            std::cin>>ime;
            try{
            br_krivaca=DodajOptuzbu(pok_pok,br_krivaca,ime);
            }
            catch(std::bad_alloc){
            std::cout<<"Neuspjela alokacija";
            }
            continue;
        }
        if(komanda==3){
            IzlistajOptuzbu(pok_pok,br_krivaca);
        }
        if(komanda==0){
            break;
        }
    }
    for(int i=0;i<br_krivaca;i++){
    	delete[] pok_pok[i];
    }
    delete[] pok_pok;

	return 0;
}
