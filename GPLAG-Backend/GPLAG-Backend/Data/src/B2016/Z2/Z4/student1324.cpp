/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <algorithm>
int PotencijalniKrivci(char **&p, std::vector<std::string> v){
	
	if(v.size()==0)return 0;
	try{
	    p=new char*[v.size()];                   // alociramo niz pokova
	}
	catch(...){
		return 0;
	}
	for(int i=0;i<v.size();i++)p[i]=nullptr;
	    try{
	    	for(int i=0;i<v.size();i++)p[i]=new char[v[i].size()+1];   // alociramo nizove znakova
	    }
	    catch(...){
	    	for(int i=0;i<v.size();i++) delete[] p[i];    // brisanje
	    	delete []p;                                 
	    	throw;
	    }
	        for(int i=0;i<v.size();i++){
	         	for(int j=0;j<v[i].size();j++){
	    	    	p[i][j]=v[i][j];                  // unos znakova u alocirane nizove
	    	    }
	    	    p[i][v[i].size()]='\0';
	        }
	return v.size();
}

int vel(char *&p){
	int br(0);
	while(*p!='\0'){
		br++;
		p++;
	}
	return br;
}

int OdbaciOptuzbu( char **&p ,int n ,std::string ime){
	int flag(0);
	for(int i=0;i<n;i++){
		if(p[i]==ime){           //provjerava da li je ime u nasem nizu 
			flag=1;
			delete []p[i];
			p[i]=nullptr;          
			    int br(0);
			    for(int j=0;j<n;j++){
				    if(p[j]==nullptr)br++;
			    }
			    if(br>10){
			    	int x(n);
			    	n=n-br;
			    	char **a(new char*[n]);    // alociranje novog niza znakova
			    	try{
			    		for(int k=0;k<n;k++) a[k]=nullptr;
			    		for(int k=0;k<n;k++) a[k]=new char[vel(p[k])+1];
			    		int l(0);                                                     
			    		for(int k=0;k<x;k++){
			    			if(p[k]==nullptr)continue;
			    			for(int z=0;z<vel(p[k]);z++){
			    				a[l][z]=p[k][z];                       //dodati try catch block
			    			}
			    			a[l][vel(p[k])]='\0';
			    			l++;
			    		}
			    		
			    		for(int i=0;i<x;i++)delete []p[i];
			    		delete []p;
			    		p=a;
			    	}
			    	catch(...){
			    		for(int i=0;i<n;i++)delete []a[i];
			    		delete []a;
			    		throw;
			    	}
			   }
		}
	}
	if(!flag)throw std::domain_error("Osoba sa imenom "+ime+" nije bila optuzena");
	return n;
}

int DodajOptuzbu(char **&p ,int n ,std::string ime){
	try{
		char *pok(new char[ime.size()+1]);
		std::copy(ime.begin(),ime.end(),pok);  //alociranje novog niza znakova
		   pok[ime.size()]='\0';
		    for(int i=0;i<n;i++){
	        	if(p[i]==nullptr){    //ako se nalazi nullptr 
	    	    	p[i]=pok;
	    	    	return n;
	    	    }	
	        }
	        try{
	        	n=n+1;
	            char **a(new char*[n]);  
	            for(int i=0;i<n;i++)a[i]=nullptr;   //nullptr
	            for(int i=0;i<n-1;i++)a[i]=p[i];
	            delete []p;
	                a[n-1]=pok;
	                p=a;
	                return n;
	        }
	        catch(...){
	        	delete []pok;
	        	throw;
	        }
	}
	catch(...){
		throw;
	}
}

void IzlistajOptuzbu(char **&p,int n){
	for(int i=0;i<n;i++){
		if(p[i]==nullptr)continue;
		std::cout << p[i] << std::endl;
	}	
}


int main ()
{
	std::vector<std::string>v;
	char **a(nullptr);
	int n;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> n;
	v.resize(n);
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	std::cin.ignore(10000,'\n');
	for(int i=0;i<n;i++)std::getline(std::cin,v[i]);
	n=PotencijalniKrivci(a,v);
	int x;
	do{
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		std::cin >> x;
		
			if(x==1){
				std::cin.ignore(10000,'\n');
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::string ime;
				std::getline(std::cin,ime);
				n=DodajOptuzbu(a,n,ime);
			}	
			
				if(x==2){
					std::cin.ignore(10000,'\n');
					std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
					std::string ime;
				    std::getline(std::cin,ime);
					n=OdbaciOptuzbu(a,n,ime);
				}	
			
			
			if(x==3)IzlistajOptuzbu(a,n);
		
	}while(x!=0);
	for(int i=0;i<n;i++)delete[]a[i];
	delete []a;
	return 0;
}