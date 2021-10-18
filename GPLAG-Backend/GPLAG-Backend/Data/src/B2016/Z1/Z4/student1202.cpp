/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
std::string FJazaNUlu(std::string recenica, std::vector<std::string>rijeci){
	if(rijeci.size()==0 || rijeci[0].size()==0)return recenica;
	for(int i=0;i<rijeci.size();i++){
		std::string novi;
		for(int j=0;j<rijeci[i].size();j++)novi.push_back(rijeci[i][j]);
		   for(int k=0;k<recenica.length();k++){
		   				while(!(((recenica[k]>='A' && recenica[k]<='Z') || (recenica[k]>='a' && recenica[k]<='z')) && k<recenica.size())){
				k++;
				}
		   	int l=0;
		   	int pocetak=k;
		   	
		   	while(recenica[k]==novi[l] && !((recenica[pocetak-1]>='A'&&recenica[pocetak-1]<='Z')|| (recenica[pocetak-1]>='a'&& recenica[pocetak-1]<='z')) ){
		   		if(l==novi.size() || k==recenica.size())break;
		   		if(k!=recenica.size() && l<novi.size()){ l++; k++;}
		   	}
		   	if(l==novi.size() && l!=0){
		   	int p=0;
		    k--;
		   // int prvi=pocetak;
            char zadnji=recenica[pocetak];
		   	   while(p<novi.size()-1 && k<recenica.size()){
		   		 recenica[pocetak]=recenica[pocetak+1];
		   		 p++;
		   		 pocetak++;
		   	   }
		   	    recenica[k]=zadnji;
		   	    if(recenica[k]!='y'&&recenica[k-1]!='a')recenica=recenica.substr(0,k+1)+"ay"+recenica.substr(k+1,recenica.size()-k);      
		   	  
		    }
		    	
		   }
	}
	return recenica;
}
b
ool afrikati(std::vector<std::string>rijecii){
	bool istina=true;
	for(int i=0;i<rijecii.size();i++){
		for(int j=0;j<rijecii[i].size();j++){
			if(!((rijecii[i][j]>='A' && rijecii[i][j]<='Z') || (rijecii[i][j]>='a'&& rijecii[i][j]<='z'))){
				istina=false;
				break;
			}
		}
	}
	return istina;
}
std::string nulaVektor(std::string recenica){
	std::vector<std::string>rijeci;
	for(int i=0;i<recenica.length();i++){
			while(!(((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && i<recenica.size())){
				i++;
				if(i==recenica.size())break;}
		std::string novi;
			while(((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && i<recenica.size()){
				novi.push_back(recenica[i]);
				i++;
			}
			bool istina=true;
			for(int j=0;j<rijeci.size();j++){
				if(rijeci[j]==novi)istina=false;}
		if(istina==true)rijeci.push_back(novi);
	}
	std::string nula_vektor = FJazaNUlu(recenica,rijeci);
	return nula_vektor;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string>rijeci){

	if(rijeci.size()==0 || rijeci[0].size()==0){
		return recenica;
	}
	for(int i=0;i<rijeci.size();i++){
		std::string novi;
		for(int j=0;j<rijeci[i].size();j++)novi.push_back(rijeci[i][j]);
		 for(int k=0;k<recenica.length();k++){
			int l=0;
			while(recenica[k]==novi[l]){
				if(l==novi.size() || k==recenica.size())break;
				if(k!=recenica.size()&& l<novi.size()){l++; k++;}
			}
			if( l==novi.size()){
				int p=0;
				k--;
				if(l==1)continue;
				while(p<novi.size()){
					recenica[k]=novi[p];
					//	std::cout<<recenica[i];
					p++;
					k--;
				}
			}
		} 
	}
	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string>rijeci){
	if(afrikati(rijeci)==false)throw std::domain_error("Nekorektan izbor rijeci");
	if(rijeci.size()==0 || rijeci[0].size()==0)return nulaVektor(recenica);
	for(int i=0;i<rijeci.size();i++){
		std::string novi;
		for(int j=0;j<rijeci[i].size();j++)novi.push_back(rijeci[i][j]);
		   for(int k=0;k<recenica.length();k++){
		   	int l=0;
		   	int pocetak=k;
		   	while(recenica[k]==novi[l] && !((recenica[pocetak-1]>='A'&&recenica[pocetak-1]<='Z')|| (recenica[pocetak-1]>='a'&& recenica[pocetak-1]<='z')) ){
		   		if(l==novi.size() || k==recenica.size())break;
		   		if(k!=recenica.size() && l<novi.size()){ l++; k++;}
		   	}
		   	if(l==novi.size()&& novi.size()!=0){
		   	int p=0;
		    k--;
		   // int prvi=pocetak;
            char zadnji=recenica[pocetak];
		   	
		   	  	
		   	   while(p<novi.size()-1 ){
		   		 recenica[pocetak]=recenica[pocetak+1];
		   		 p++;
		   		 pocetak++;
		   	   }
		   	    recenica[k]=zadnji;
		   	    recenica=recenica.substr(0,k+1)+"ay"+recenica.substr(k+1,recenica.size()-k);                               
		   	    
		    }
		   }
	}
	return recenica;
}
int main ()
{


  
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::string rijeci;
	std::vector<std::string> rijec;
	for(;;){
		std::getline(std::cin,rijeci);
		rijec.push_back(rijeci);
		if(std::cin.peek()=='\n')break;
	}
	
	try{
	std::string PIG;
	PIG=IzmijeniUPigLatin(recenica,rijec);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<PIG<<std::endl;
	}
	catch(std::domain_error e)
    {
        std::cout << "Izuzetak: "<<e.what() << std::endl;
    }
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string OBRNI=ObrniFraze(recenica,rijec);
	std::cout<<OBRNI;
	return 0;

}