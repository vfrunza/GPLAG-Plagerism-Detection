#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <new>
#include <cstring>

int vel(0);
int PotencijalniKrivci(char** &parametar,std::vector<std::string> imena) {
	int broj(0);
	try {
	   parametar=nullptr;
	parametar=new char* [imena.size()];
	for(int i=0;i<imena.size();i++) {
		parametar[i]=nullptr;
	}
	for(int j=0;j<imena.size();j++) {
		parametar[j]= new char [imena[j].length()+1];
		broj++;
		std::strcpy(parametar[j],imena[j].c_str());
	}
}
catch(std::bad_alloc) {
	std::cout<<"Neuspjela alokacija"<<std::endl;
	}
	return broj;
}
int OdbaciOptuzbu(char** &parametar,int velicina,std::string ime) {
	int broj(0);
	for(int i=0;i<velicina;i++) {
		if(parametar[i]!=nullptr) {
		if(std::strcmp(parametar[i],ime.c_str())==0) {
			delete[] parametar[i];
			parametar[i]=nullptr;
			broj++;
		}
	}
	}
	if(broj>=10) {
		int razlika(velicina-broj);
		char **pokazivac;
		try {
			char** pomocni(parametar);
		  pokazivac=nullptr;
		  pokazivac=new char* [razlika];
		  for(int j=0;j<razlika;j++) {
		  	pokazivac[j]=nullptr;
		  }
		  for(int f=0;f<velicina;f++) {
		  for(int k=0;k<razlika;k++) {
		  	if(parametar[f]!=nullptr) {
		  	pokazivac[k]=parametar[f];
		  	f++;
		  }
		  else {
		  k--;
		  f++;
	}
		  }
		  }
		  delete[] pomocni;
		  parametar=pokazivac;
		}
	catch(std::bad_alloc) {
		
	std::cout<<"Neuspjela alokacija!"<<std::endl;	
	}
	return razlika;
}
else {
try {
if(broj==0) {
	std::string greska("Osoba sa imenom ");
	greska+=ime;
	greska+=" nije bila optuzena";
	throw std::domain_error (greska);
}
}
catch(std::domain_error s) {
	std::cout<<s.what()<<std::endl;
}
}
return velicina;
}
int DodajOptuzbu(char** &parametar,int velicina,std::string krivac) {
	try {
	char*novi(nullptr);
	novi=new char [krivac.length()+1];
	std::strcpy(novi,krivac.c_str());
	int i(0);
	for(i=0;i<velicina;i++) {
		if(parametar[i]==nullptr) {
			parametar[i]=novi;
		break;
		}
	}
	
	if(i==velicina) {
		char** pomocni=parametar;
		char (** alocirano)(nullptr);
		alocirano=new char* [velicina+1];
		for(int j=0;j<velicina;j++) {
			if(j<velicina-1) {
				alocirano[j]=parametar[j];
			}
			alocirano[j]=novi;
		}
	delete[] pomocni;
	parametar=alocirano;
		return velicina+1;
	}
}
catch(std::bad_alloc) {
	std::cout<<"Neuspjela alokacija"<<std::endl; 
}
return velicina;
}

void IzlistajOptuzbu(char** parametar,int velicina) {
	for(int i=0;i<velicina;i++) {
		if(parametar[i]!=nullptr) {
			std::cout<<parametar[i]<<std::endl;
		}
	}
}


int main ()
{
	char** nizPotencijalnih(nullptr);
	std::vector<std::string> imena;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?: ";
	int s(0);
	std::cin>>s;
	vel=s;
	std::cin.ignore(1000,'\n');
	std::cout<<std::endl<<"Unesite potencijalne krivce: ";
	std::string ulaz;
for(int i=0;i<s;i++) {
	std::getline(std::cin,ulaz);
if(ulaz.length()!=0) {
imena.push_back(ulaz);
}
std::cin.ignore(1000,'\n');
}
int n=PotencijalniKrivci(nizPotencijalnih,imena);
int x;
  do {
	std::cout<<std::endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavnje optuzenih, 0 za kraj: ";
	std::cin>>x;
 switch(x) {
 	case 0:
 	break;
 	case 1:
 	{
 		std::cin.ignore(1000,'\n');
 	std::cout<<std::endl<<"Unesite ime novog optuzenog: ";
 	std::string sumnjivac;
 	std::getline(std::cin,sumnjivac);
 	imena.push_back(sumnjivac);
     DodajOptuzbu(nizPotencijalnih,vel+1,sumnjivac);
     vel+=1;
     break;
     
 	}
     case 2:
     {
     	std::cin.ignore(1000,'\n');
     std::cout<<std::endl<<"Unesite ime koje zelite izbaciti: ";
     std::string nijeon;
     std::getline(std::cin,nijeon);
     OdbaciOptuzbu(nizPotencijalnih,vel,nijeon);
     vel-=1;
     break;
     }
     case 3:
     IzlistajOptuzbu(nizPotencijalnih,vel);
     break;
     default:
     std::cout<<"Nepoznata opcija!"<<std::endl;
 }
}while(x!=0);
	return 0;
}