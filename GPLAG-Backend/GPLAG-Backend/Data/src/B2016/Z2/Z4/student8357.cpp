#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int PotencijalniKrivci(char **&(ref_na_pok),vector<string> Imena ){
	int broj_nizova(0);
	try{
	ref_na_pok=new char*[Imena.size()];
	for(int i=0;i<Imena.size();i++)
		ref_na_pok[i]=nullptr;
	
	try{
	  	for(int i=0;i<Imena.size();i++){
	  		int x(Imena[i].length()+1);
	  		ref_na_pok[i]=new char[x];
	  		broj_nizova++;
	  	}
	  	for(int i=0;i<Imena.size();i++){
	  		string x(Imena[i]);
	  		strcpy(ref_na_pok[i],x.c_str());
	  	}
	  	
	  	return broj_nizova;
	}catch(...){
		for(int i=0;i<Imena.size();i++){
			delete [] ref_na_pok[i];
		}
		delete [] ref_na_pok;
		throw;
	}
	}catch(...){
		delete [] ref_na_pok;
    	throw;
    }
    
}

int OdbaciOptuzbu(char **&(ref_na_pok),int broj_pok ,string Ime){
	
	// IZUZETAK: U slucaju da se osoba ne nalazi na spisku!
	bool je_li_u_spisku(false);
	for(int i=0;i<broj_pok;i++){
		if(Ime==ref_na_pok[i]) je_li_u_spisku=true;
	}
	if(je_li_u_spisku==false) throw std::domain_error("Osoba sa imenom nije bila optuzena");
	
	// Trazimo ime osobe na spisku i uklanjamo ga 
	for(int i=0;i<broj_pok;i++){
		if(Ime==ref_na_pok[i]){
			delete [] ref_na_pok[i];
			ref_na_pok[i]=nullptr;
		}
	}
	
	// Prebrojavamo koliko je obrisanih
	int broj_praznih(0);
	for(int i=0;i<broj_pok;i++){
		if(ref_na_pok[i]==nullptr) broj_praznih++;
	}
	
	// Ako je vise od 10 obrisanih alociramo novi niz, stari brisemo
	if(broj_praznih>10){
		char **pomocni;
		pomocni=new char*[broj_pok-broj_praznih];
		int k(0);
		for(int i=0;i<broj_pok;i++){
			if(ref_na_pok[i]!=nullptr){
				pomocni[k]=new char[strlen(ref_na_pok[i])];
				k++;
			}
		}
		
		int j(0);
		 for(int i=0;i<broj_pok;i++){
		 	if(ref_na_pok[i]!=nullptr){
		 		pomocni[j]=ref_na_pok[i];
		 		j++;
		 	}
		 
		 }
		 for(int i=0;i<broj_pok;i++){
		 	delete [] ref_na_pok[i];
		 }
		 delete ref_na_pok;
		 ref_na_pok=pomocni;
		return k-1;
	}else return broj_pok;
	
}

int DodajOptuzbu(char **&(ref_na_pok),int broj_pok,string Ime){
	char *pok;
	
	//Alociramo niz za Ime optuzenog
	try{
		pok=new char[Ime.length()+1];
	}catch(...){
		throw;
	}
	
	// Trazimo slobodan pokazivac i usmjeravamo ga na ime optuzenog
	bool upisan(false);
	for(int i=0;i<broj_pok;i++){
		if(ref_na_pok[i]==nullptr){
			ref_na_pok[i]=pok;
			upisan=true;
			break;
		}
	}
	
	// Ako nema slobodnog pokazivaca alociramo novi niz pokazivaca za jedan 
	// veci od onog koji smo imali, prepisemo sva imena i na kraju obrisemo stari niz
	if(upisan==false){
		char **pomocni;
		try{
			pomocni=new char*[broj_pok+1];
			for(int i=0;i<broj_pok+1;i++){
				pomocni[i]=nullptr;
			}
			try{
				for(int i=0;i<broj_pok+1;i++){
	                
					pomocni[i]=new char[5];
				}
				pomocni[broj_pok]=new char[Ime.length()+1];
				
			for(int i=0;i<broj_pok;i++){
				pomocni[i]=ref_na_pok[i];
			}	
			pomocni[broj_pok]=pok;
				
			return broj_pok+1;
			
		}catch(...){
			for(int i=0;i<broj_pok+1;i++){
				delete [] pomocni[i];
			}
			delete [] pomocni;
			throw;
		}
	}catch(...){
		throw;
	}
	}else return broj_pok;
}

void IzlistajOptuzbu(char **pok,int broj_pok){
	for(int i=0;i<broj_pok;i++){
		if(pok[i]!=nullptr){
			cout<<pok[i][0];
			cout<<endl;
		}
	}
	
}
int main ()
{
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	int n;
	cin>>n;
	vector<string> s;
	cout<<"Unesite potencijalne krivce: "<<endl;
	cin.ignore(10000,'\n');
	string temp;
	for(int i=0;i<n;i++){
		getline(cin,temp);
		s.push_back(temp);
	}
    char **p;
	int opcija,x(n);
	do{
		cout<<"Odaberite opciju: 1 za unos novog optuzenog,";
		cout<<" 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
		cin>>opcija;
		if(opcija==1){
			cout<<"Unesite ime novog optuzenog: "<<endl;
			string novi_optuzeni;
			cin.ignore(10000,'\n');
			getline(cin,novi_optuzeni);
			DodajOptuzbu(p,x,novi_optuzeni);
		}
		else if(opcija==2){
			cout<<"Unesite ime koje zelite izbaciti: "<<endl;
			string ime_za_izbaciti;
			getline(cin,ime_za_izbaciti);
		    x=OdbaciOptuzbu(p,x,ime_za_izbaciti);
		}
		else if(opcija==3){
			IzlistajOptuzbu(p,x);
		}
		}while(opcija!=0);
		
	return 0;
}