/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::string;


typedef std::vector<string> VS;



int PotencijalniKrivci(char **&q, VS s){
 	int br(0);
 try{
 	q=new char* [s.size()];
 		try{
 			for(int i(0);i<s.size();i++){
 			q[i]=new char[(s[i].length())+1]; 
 				br++;
 			}
 		for(int i(0);i<s.size();i++){
 			int h(0);
 			for(int j(0);j<s[i].length();j++){
 				q[i][j]=s[i][j];
 				h=j;
 			}
 			h++;
 			q[i][h]='\0';
 		}
 		return br;
 	}catch(std::bad_alloc){
 		for(int i(0);i<br;i++)
			delete[] q[i];
		delete q;
		throw;
		
 	}
 	
 }catch(std::bad_alloc){
 		delete q;
 		throw;
 	}
 	
 }
 
 
 int OdbaciOptuzbu(char** &q, int &n, string s){
 	int &br(n);
 	int brojac(0);

 	
 	for(int i(0);i<n;i++){
 	if(q[i]==nullptr)brojac++;
 	else{
 		if(q[i]==s){
 		delete[] q[i];//potenc greška;
 		q[i]=nullptr;
 		//br--;
 		brojac++;
 		
 	}	}
 	}
 	
 	if(brojac==0) {
 		string k("Osoba sa imenom ");
 		string h(" nije bila optuzena");
 		string e;
 		e=k+s+h;
 		throw std::domain_error(e);
 		
 	}/*
 	if(brojac>10){
 		int novi(n-brojac);
 		char** p(new char*[novi]);
 		int k(0);
 		for(int i(0);k<novi;i++){
 			
 			int ima(0);
 			for(int o(0);q[i][o]!='\0';o++)
 				ima++;//potencijalna greška
 			if(q[i]!=nullptr) {p[i]=new char[ima];k++;}
 		}k=0;
 		for(int i(0);k<novi;i++){
 			if(q[i]!=nullptr) {p[i]=q[i];k++;}
 		}
 		for(int i(0);i<n;i++){
 			delete[] q[i];
 		}
 		
 		q=p;
 		return novi;
 	}*/
 	return br;
 }
 
int DodajOptuzbu (char** &q, int &n, string s){
	int onaj(0);
	int del(0);
	int &br(n);
	char* b(nullptr);
	try{
		b=new char[s.length()+1];
	
	bool ugurose(false);
	for(int i(0);i<s.length();i++){
		b[i]=s[i];
		onaj++;
	}
	for(int i(0);i<n;i++){
		if(q[i]==nullptr){
			q[i]=b;
			br++;
			ugurose=true;
			break;
		}}
	if(!ugurose){
		br++;
		char** p(nullptr);
		try{
		p= new char*[br];
		for(int i(0);i<br;i++){
			if(i==br-1){
				p[i]=new char[s.length()+1];
			}else{
			int ima(0);
 			for(int o(0);q[i][o]!='\0';o++)
 				ima++;//potencijalna greška
				p[i]=new char[ima];
			}
			del++;
		}
		for(int i(0);i<br;i++){
			if(i==br-1){
				int zadnji(0);
				for(int j(0);j<s.length();j++){
					p[i][j]=s[j];
					
					zadnji++;
				}
				p[i][zadnji]='\0';
				
			}else{
				p[i]=q[i];
				
			}
		}
			q=p;
	}catch(std::bad_alloc){
		for(int i(0);i<del;i++)
			delete[] p[i];
		delete p;
		throw;
	}
		
	}
	return br;
	}catch(std::bad_alloc){
	
		delete b;
		throw;
	}
}
void IzlistajOptuzbu (char** q,int n){
	cout<<endl;
	for(int i(0);i<n;i++){
		
		if(q[i]==nullptr){}
		else{
		cout<<q[i]<<endl;
		
			
		}}
}
int main ()
{	
	char** q(nullptr);
	cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<endl;
	int koliko;
	cin>>koliko;
	std::cin.ignore(100000,'\n');
	cout<<"Unesite potencijalne krivce: "; 	
	VS a;
	for(int i(0);i<koliko;i++){
		string imena;
		std::getline(std::cin, imena);
		a.push_back(imena);
	}
	try{
	int br(PotencijalniKrivci(q,a));
	int unos;
		int b(br);
		int ma_daj_ba(0);
	do{
		
	
		cout<<"\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		cin>>unos;
		
		std::cin.ignore(100000,'\n');
		
		
		if(unos==2){
			cout<<"\nUnesite ime koje zelite izbaciti: ";
		string klm;
		std::getline(std::cin,klm);
		
				try{
		b=(OdbaciOptuzbu(q,b,klm));
				}catch(std::domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
		}
		
		}
	
		if(unos==1){
	
		cout<<"\nUnesite ime novog optuzenog: ";
		string krivi;
		std::getline(std::cin, krivi);
		
		
			try{
		b=(DodajOptuzbu(q,b,krivi));	
			}catch(std::bad_alloc){
			
			}
	
			
		}if(unos==3){
			
	IzlistajOptuzbu(q,b);
		}
	}while(unos!=0);
	}catch(std::bad_alloc){
		cout<<"Nevaljaa";
	}
	return 0;
}