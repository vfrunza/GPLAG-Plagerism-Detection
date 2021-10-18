/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<new>
#include<cstring>


int PotencijalniKrivci(char **&pok,std::vector<std::string> imena){
	
	int n(imena.size());
	
	int brojac(0);
try{
	pok=nullptr;
	pok=(new char *[n]);
}catch(...){
	
//	delete [] pok;
	
	
	throw ;
	
}


	for(int i=0;i<n;i++){
			int m(imena[i].length());
		
		try{
			pok[i]=nullptr;
		pok[i]=new char[m+1];
		
		}catch(...){
		for(int i=0;i<n;i++){
			delete [] pok[i];	
			
			}
			delete [] pok;
		
		throw;}
	
		for(int j=0;j<m;j++){
			pok[i][j]=imena[i][j];
		}
		pok[i][m]='\0';
		
	brojac++;
		
		
	}

	return brojac;
	
}

int OdbaciOptuzbu(char **&pok,int n,std::string ime){
	int brnul(0);

	

	
	char **pok2(pok);

bool ima(false);

	for(int i=0;i<n;i++){
		if(pok2[i]==nullptr) continue;
		
	//	if(ime.length()==std::strlen(pok2[i])){
	
		if(pok2[i]==ime){
			delete [] pok2[i];
			pok2[i]=nullptr;
			brnul++;
			ima=true;
		}
	//	}
		
}
bool pr(false);
if(ima){



	
	if(brnul>=10){
		pr=true;
		try{
		char **p(new char *[n-brnul]);
		int j(0);
		for(int i=0;i<n;i++){
			if(pok2[i]==nullptr) continue;
		
			p[j]=pok2[i];
			j++;
		}
		for(int i=0;i<n;i++){
			pok[i]=nullptr;
		delete [] pok[i];
		}
		delete []pok;
		pok=p;
		
	}
	catch(...){
		throw;
	}
	}
} else {
	std::cout<<"Osoba sa imenom "<<ime<<" nije bila optuzena";
}
	
	if(pr) return n-brnul;
	else	return n;
	
}

int DodajOptuzbu(char **&pok,int n,std::string ime){
	

	int m(ime.length());
	
	char **pok2(pok);
	/*
for(int i=0;i<n;i++){
	std::cout<<pok2[i];
}

*/


	bool provjera(true);
//	char **pomniz=nullptr;
	

	char *pomocni(nullptr);
	
	try{
		
	//	std::cout<<"pr++";
	pomocni=new char[m+1];
		
	}
	catch(...){
	
//	delete [] pomocni;
	
	throw ;
		return n;
	}
	
	for(int i=0;i<m;i++){
		pomocni[i]=ime[i];
		
		
	}
	pomocni[m]='\0';
	

	//std::cout<<pomocni;
	//bool provjera(true);
	
	
	
	for(int i=0;i<n;i++){
		
		if (pok2[i]==nullptr){
		
			pok2[i]=pomocni;
			
			provjera=false;
			
		//	delete [] pomocni;
			
			break;
			
		}
		
		
	}
	if(provjera==false) return n;
	




	else{
		//char **pok2=nullptr;
	//	int m(n+1);
		//char **pomniz2(pomniz);
	
 char**pomniz=nullptr;

		try{
		pomniz=new char *[n+1];
			for(int i=0;i<n;i++){
			
			pomniz[i]=&pok[i][0];
			//pomniz[i]=new char [std::strlen(pok[i])];
			//std::strcpy(pomniz[i],pok[i]);
		
		}
			pomniz[n]=pomocni;
			delete [] pok;
		
		
		pok=nullptr;
		
		pok=pomniz;
		
	
		
		}
		catch(...){
			
			for(int i=0;i<n+1;i++){
				delete [] pomniz[i];
			}
			delete [] pomniz ;
			throw;
			return n;
		}
	//	pomniz=pok2;
	   // pomniz2 = pomniz;
		
	
		
		


	

	
		/*
	//	pomniz=nullptr;
		for(int i=0;i<n+1;i++){
			std::cout<<"|"<<pok[i]<<"|"<<std::endl;
		}
		*/
		
	//	pomniz=nullptr;
		
	
	//	pok=nullptr;
	/*	try{
	pok=new char*[n+1];

    

	for(int i=0;i<n+1;i++){
		pok[i]=nullptr;
		pok[i]=pomniz[i];
	}
	
	
		}catch(...){
			for(int i=0;i<n+1;i++){
			delete[] pok[i];
			}
			delete [] pok;
			throw;
		}
		*/
/*	
	for(int i=0;i<n+1;i++){
		std::cout<<pomniz[i]<<std::endl;
	}

*/
//    pok=&pomniz[0];
  /*  
    for(int i=0;i<n;i++){
    	pomniz[i]=nullptr;
    	delete [] pomniz[i];
    }
   delete [] pomniz;
    pomniz=nullptr;
    */
 
    return n+1;
    
}



}





	



void IzlistajOptuzbu(char **pok,int n){
	
	for(int i=0;i<n;i++){
		
		if(pok[i]==nullptr) continue;
		std::cout<<pok[i]<<std::endl;
	}
	
	
	
}
int main ()
{


	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int n;
	std::cin>>n;
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> lista(0);
	for(int i=0;i<n;i++){
		
		std::string ime;
		std::cin>>ime;
		lista.push_back(ime);
	
	}
	char **pok;
	int br1(PotencijalniKrivci(pok,lista));
	
	
	int a;
	do{
	
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	std::cin>>a;
	int br2(0),br3(0);
	if(a==1){
		std::string s;
		std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
		std::cin>>s;
		br2=DodajOptuzbu(pok,br1,s);
	//	std::cout<<br2<<"*";
		br1=br2;
		
	}
	
	if(a==2){
		std::string s;
		std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
		std::cin>>s;
		br3=OdbaciOptuzbu(pok,br1,s);
		br1=br3;
		
	}
	if(a==3){
		IzlistajOptuzbu(pok,br1);
		
	}
	
	

	}while(a!=0);


	return 0;
}