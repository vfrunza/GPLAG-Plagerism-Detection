/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <new>
#include <string>
#include <stdexcept>
#include <vector>
#include <cstring>

using namespace std;

int PotencijalniKrivci(char **&p,vector<string>vs){
	int br_alociranih(0);
	try{
		p=new char *[vs.size()];
		for(int i=0;i<vs.size();i++){
			p[i]=nullptr;
		}
		try{
			for(int i=0;i<vs.size();i++){
				p[i]=new char[vs[i].length()+1];
				strcpy(p[i],vs[i].c_str());br_alociranih++;
			}
		}
		catch(...){
			for(int i=0;i<br_alociranih;i++)delete[] p[i];
			delete[] p;
			throw;
		}
	}
	catch(...){
		throw bad_alloc();
	}
	return br_alociranih;
	
}

int OdbaciOptuzbu(char **&p,int vel_pok,string s){
	int vrati_vel(vel_pok);
	bool a(false);
	for(int i=0;i<vel_pok;i++){
		if(p[i]==nullptr)continue;
		if(strcmp(p[i],s.c_str())==0){a=true;break;}
	}
	if(a==false){string baci="Osoba sa imenom "+s+" nije bila optuzena";throw domain_error(baci);}
	else{
		for(int i=0;i<vel_pok;i++){
			if(p[i]==nullptr)continue;
			if(strcmp(p[i],s.c_str())==0){delete[] p[i];p[i]=nullptr;}
		}
		int brojac(0);
		for(int i=0;i<vel_pok;i++){
			if(p[i]==nullptr)brojac++;
		}
		if(brojac>10){
			int stvarna_vel(vel_pok-brojac);
			vrati_vel=stvarna_vel;int pomoc(0);
			char**novi_niz_pok=new char *[stvarna_vel];
			for(int i=0;i<vel_pok;i++){
				if(p[i]==nullptr)continue;
				else{
					strcpy(novi_niz_pok[pomoc],p[i]);pomoc++;
				}
				
			}
				for(int i=0;i<vel_pok;i++)delete[] p[i];
				delete[] p;
				p=novi_niz_pok;
			}
		
	}
	return vrati_vel;
}

int DodajOptuzbu(char**&p,int vel_pok,string s){
	int vrati_vel(vel_pok);
	try{
		char *novi_niz=new char [s.length()+1];
		strcpy(novi_niz,s.c_str());
		bool a(false);
		for(int i=0;i<vel_pok;i++){
			if(p[i]==nullptr){p[i]=novi_niz;a=true;break;}
		}
		if(a==false){
			try{
				char **novi_niz_pok=new char*[vel_pok+1];
				for(int i=0;i<vel_pok+1;i++)novi_niz_pok[i]=nullptr;
			try{
				vrati_vel=vel_pok+1;
				for(int i=0;i<vel_pok;i++){
					char *h=p[i];int pom_broj(1);
					while(*h!='\0'){pom_broj++;h++;}
					novi_niz_pok[i]=new char[pom_broj];
					strcpy(novi_niz_pok[i],p[i]);
				}
				novi_niz_pok[vel_pok]=new char[s.length()+1];
				strcpy(novi_niz_pok[vel_pok],novi_niz);delete[] novi_niz;
				for(int i=0;i<vel_pok;i++)delete[] p[i];
				delete[] p;
				p=novi_niz_pok;
			}
			catch(...){
				for(int i=0;i<vel_pok+1;i++)delete[] novi_niz_pok[i];
				delete[] novi_niz_pok;
				throw;
			}
			}
			catch(...){
				delete[] novi_niz;
				throw;
			}
		}
	}
	catch(...){
		vrati_vel=vel_pok;
		throw bad_alloc();
	}
	return vrati_vel;
}

void IzlistajOptuzbu(char **p,int vel_pok){
	for(int i=0;i<vel_pok;i++){
		if(p[i]==nullptr)continue;
		char *help=p[i];
		while(*help!='\0'){
			cout<<*help;
			help++;
		}
		cout<<endl;
	}
}

int main(){
	cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;cin>>n;
	cout<<endl<<"Unesite potencijalne krivce: ";
	vector<string>vs;
	cin.ignore(1000,'\n');
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		vs.push_back(s);
	}
	try{
		char **pot;
		int rez=PotencijalniKrivci(pot,vs);
		for(;;){
			cout<<endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
			int opcija;
			cin>>opcija;
			if(opcija==1){
				cout<<endl<<"Unesite ime novog optuzenog: ";
				cin.ignore(1000,'\n');
				string ime;
				getline(cin,ime);
				rez=DodajOptuzbu(pot,rez,ime);
			}
			if(opcija==2){
				cout<<endl<<"Unesite ime koje zelite izbaciti: ";
				cin.ignore(1000,'\n');
				string ime;
				getline(cin,ime);
				rez=OdbaciOptuzbu(pot,rez,ime);
			}
			if(opcija==3){
				cout<<endl;
				IzlistajOptuzbu(pot,rez);
			}
			if(opcija==0){
				for(int i=0;i<rez;i++)delete[] pot[i];
				delete[] pot;
				break;
				
			}
		}
	}
	catch(domain_error e){
		cout<<e.what();
	}
	catch(bad_alloc){
		
	}
	catch(...){
	}
	return 0;
}