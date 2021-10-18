#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <cstdlib>

using namespace std;

int PotencijalniKrivci(char** &pok,vector<string> imena){
    char** alocirani(nullptr);
    int size(0),br(0);
    for(int i=0; i<imena.size(); i++) size++;
    if(imena.size()==0) return 0;
    try{
        alocirani=new char*[imena.size()];
        for(int i=0; i<imena.size(); i++) alocirani[i]=nullptr;
        try{
            for(int i=0; i<imena.size(); i++){
                if(imena.at(i).size()==0) continue; //Preskoci eventualno prazne stringove
                alocirani[br]=new char[imena.at(i).size()+1](); //Inicijalizacija na nulu, tj \0
                strcpy(alocirani[br],imena.at(i).c_str());
                br++;
            }
            pok=alocirani;
        }
        catch(bad_alloc){
            for(int i=0; i<imena.size(); i++) delete[] alocirani[i];
            throw;
        }
    }
    catch(bad_alloc){
        delete[] alocirani;
        throw;
    }
    return br;
}

int OdbaciOptuzbu(char** &pok, int broj_alociranih, string ime){
    bool ima(false);
    for(int i=0; i<broj_alociranih; i++){
        if(!strcmp(pok[i],ime.c_str())){
            ima=true;
            delete[] pok[i];
            pok[i]=nullptr;
            break;
        }
    }
    if(!ima) throw domain_error("Osoba sa imenom "+ime+" nije bila optuzena");
    int brojac(0);
    for(int i=0; i<broj_alociranih; i++){
        if(pok[i]==nullptr) brojac++;
    }
    char **pok2=nullptr;
    try{
        if(brojac>10){
            pok2 = new char*[broj_alociranih-brojac]; //Ako ovdje ne uspije, idemo na prazni catch - nema se sta brisat
            int br(0);
            for(int i=0; i<broj_alociranih; i++){
                if(pok[i]!=nullptr){
                    pok2[br]=pok[i];
                    pok[i]=nullptr;
                    br++;
                }
                delete[] pok[i];
            }
            delete[] pok;
            pok=pok2;
            return broj_alociranih-brojac;
        }
    }
    catch(bad_alloc){
            //Nemam sta brisati, jedna alokacija ima, ako nije uspjela, nije se nista alociralo svakako
    }
    return broj_alociranih;
}

int DodajOptuzbu(char** &pok, int broj_alociranih, string ime){
    bool ima(false);
    try{
        for(int i=0; i<broj_alociranih; i++){
            if(pok[i]==nullptr){
                ima=true;
                pok[i]=new char[ime.size()+1]();
                strcpy(pok[i],ime.c_str());
                break;
            }
        }
    }
    catch(bad_alloc) {
        return broj_alociranih;
    }
    if(!ima){
        char** pok2=nullptr;
        try{
            pok2=new char*[broj_alociranih+1];
            pok2[broj_alociranih]=nullptr; //Jedina alokacija koja ce se izvrsit
            pok2[broj_alociranih]=new char[ime.size()+1]();
            strcpy(pok2[broj_alociranih],ime.c_str());
            for(int i=0; i<broj_alociranih; i++) pok2[i]=pok[i];
            delete[] pok;
            pok=pok2;
            return broj_alociranih+1;

        }
        catch(bad_alloc){
            delete[] pok2;
            throw;
        }
    }
    return broj_alociranih;

}

void IzlistajOptuzbu(char** pok, int broj_alociranih){
    for(int i=0; i<broj_alociranih; i++){
        if(pok[i]==nullptr) continue;
        for(int j=0; pok[i][j]!=0; j++) cout<<pok[i][j];
        cout<<endl;
    }
}


int main(){
	int broj_krivaca;
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	cin>>broj_krivaca;
	cin.ignore(10000,'\n');
	vector<string> Imena(broj_krivaca);
	cout<<"Unesite potencijalne krivce: "<<endl;
	for(int i=0; i<broj_krivaca; i++) getline(cin,Imena[i]);
	char**pok;
	int broj_alociranih;
	try{
	    broj_alociranih=PotencijalniKrivci(pok,Imena);
		int opcija;
	    do{
	        cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
	        cin>>opcija;
	        cin.ignore(10000,'\n');
	        switch(opcija){
	            case 1:{
	                cout<<"Unesite ime novog optuzenog: "<<endl;
	                string ime; getline(cin,ime); broj_alociranih=DodajOptuzbu(pok,broj_alociranih,ime); break;
	            }
	            case 2:{
	                cout<<"Unesite ime koje zelite izbaciti: "<<endl;
	                try{
	                    string ime; getline(cin,ime); broj_alociranih=OdbaciOptuzbu(pok,broj_alociranih,ime); break;
	                }
	                catch(domain_error e){
	                    cout<<e.what()<<endl;
	                }
	                
	            }
	            case 3:{
	                IzlistajOptuzbu(pok,broj_alociranih); break;
	            }
	            case 0: break;
	
	        }
		}
		while(opcija!=0);
		for(int i=0; i<broj_alociranih; i++) delete[] pok[i];
		delete[] pok;
	}
	catch(bad_alloc){
	    cout<<"Neuspjela alokacija!"<<endl; 
	}
    return 0;

}
