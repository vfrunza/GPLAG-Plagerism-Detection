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

bool DaLiJeZnak(char z){
	if ((z>='A' && z<='Z') || (z>='a' && z<='z')) return true;
	return false;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string>v){
	std::string trenutnarijec;
	char pomocni;
	int k(0);
	for (int i=0;i<v.size();i++){
		trenutnarijec=v[i];
		for (int j=0;j<recenica.length();j++){
			k=0;
			while (k<trenutnarijec.length() && j<recenica.length() && trenutnarijec[k]==recenica[j]){
				k++;
				j++;
			}
			if (k==trenutnarijec.length()){
				j--;
				k--; 
				for (int pocetak=0;pocetak<trenutnarijec.length()/2;pocetak++){
					pomocni=recenica[j-k+pocetak];
					recenica[j-k+pocetak]=recenica[j-pocetak];
					recenica[j-pocetak]=pomocni;
				}
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string>v){
	std::string trenutnarijec;
	for (int i=0;i<v.size();i++){
		trenutnarijec=v[i];
		for (int j=0;j<trenutnarijec.length();j++){
			if (!((trenutnarijec[j]>='A' && trenutnarijec[j]<='Z') || (trenutnarijec[j]>='a' && trenutnarijec[j]<='z'))) 
				throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	
	char pomocna;
	int k(0);
	int brojac=0;
	if (v.size()==0){
		for (int i=0;i<recenica.length();i++){
			brojac=0;
			if(i<recenica.length() && ((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))){
				while(i<recenica.length() && ((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))){
					brojac++;
					i++;
				}
				recenica.resize(recenica.size()+2);
				i--;
				brojac--;
				for (int j=recenica.length()-1;j>i+2;j--){
					recenica[j]=recenica[j-2];
				}
				recenica[i+1]='a';
				recenica[i+2]='y';
				pomocna=recenica[i-brojac];
				for (int k=0;k<brojac;k++){
					recenica[i-brojac+k]=recenica[i-brojac+k+1];
				}
				recenica[i]=pomocna;
				i+=2;
			}
		}
	}
	else{
		for (int i=0;i<v.size();i++){
			trenutnarijec=v[i];
			for (int j=0;j<recenica.length()-1;j++){
				k=0;
				
				while (k<trenutnarijec.length() && j<recenica.length() && trenutnarijec[k]==recenica[j]){
					j++;
					k++;
				}
				
				if ((j==recenica.length() && !DaLiJeZnak(recenica[j-k-1]) && k==trenutnarijec.length() ) || ( j-k==0 && !DaLiJeZnak(recenica[j]) && k==recenica.length()) || (!DaLiJeZnak(recenica[j]) && !DaLiJeZnak(recenica[j-k-1]) && k==trenutnarijec.length())){
					k--;
					j--;
					recenica.resize(recenica.size()+2);
					for (int l=recenica.length()-1;l>j+2;l--){
						recenica[l]=recenica[l-2];
					}
					recenica[j+1]='a';
					recenica[j+2]='y';
					pomocna=recenica[j-k];
					for (int m=0;m<trenutnarijec.length()-1;m++){
						recenica[j-k+m]=recenica[j-k+m+1];
					}
					recenica[j]=pomocna;
				}
			}
		}
	}
	
	return recenica;
}

int main (){
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string pomocni;
	for (;;){
		std::getline(std::cin,pomocni);
		if (pomocni.length()==0) break;
		fraze.push_back(pomocni);
	}
	try{
		std::string s1(IzmijeniUPigLatin(recenica,fraze));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<s1<<std::endl;
	}	

	catch (std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
		}
    std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,fraze);
	return 0;
}