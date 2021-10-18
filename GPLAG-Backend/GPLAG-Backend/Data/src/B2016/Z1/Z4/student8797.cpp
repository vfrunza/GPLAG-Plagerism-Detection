/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>

std::string ObrniFraze(std::string recenica, std::vector<std::string> v){
	
	for(unsigned int n=0; n<v.size();n++){
		for(unsigned int i =0; i<recenica.length(); i++){
			unsigned int k=i;
			unsigned int j=0;
			while(j<v.at(n).length() && k<recenica.length()&& recenica.at(k)==v.at(n).at(j)){
				k++;j++;
				if(j==v.at(n).length()){                                                                                           // && (i==0 || !((recenica[i-1]>='a' && recenica[i-1]<='z' ) ||  (recenica[i-1]>='A' && recenica[i-1]<='Z' ))) && (k==recenica.length() || !((recenica[k]>='a' && recenica[k]<='z' ) ||  (recenica[k]>='A' && recenica[k]<='Z' )) )  ){
					j=0;
					for(unsigned int p=i; p<k;p++){
						recenica[p]=v[n][v[n].size()-j-1];
						j++;
					}
		    	}   
			}
		}
	}
    return recenica;	
}

std::string IzmijeniSve(std::string recenica){
	
	std::vector<char> v;
	for(unsigned int i=0; i<recenica.length(); i++){
		while(i<recenica.length() &&  !((recenica[i]>='a' && recenica[i]<='z' ) ||  (recenica[i]>='A' && recenica[i]<='Z' ))  )
	    	i++;
	    v.clear();
	    unsigned int k=i;
	    while(k<recenica.length() &&  ((recenica[k]>='a' && recenica[k]<='z' ) ||  (recenica[k]>='A' && recenica[k]<='Z' ))  ){
	    	v.push_back(recenica[k]);
			k++;
		}
		unsigned int j=1;
		for(unsigned int p=i;p<k;p++){
			if(j<v.size()){
				recenica[p]=v[j];
				j++;
			}
			else 
				recenica[p]=v[0];
		}
		if(v.size()!=0){
		recenica.push_back(' ');
		recenica.push_back(' ');
		for(unsigned int r = recenica.length()-1; r>k+1; r--){
			recenica[r]=recenica[r-2];
		}
		recenica[k]='a';
        recenica[k+1]='y';
        i=k+2;}
	}
	
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> v){
	
	for(unsigned int n=0; n< v.size();n++){
		for(unsigned int i=0; i<v[n].length(); i++){
			if(  !((v[n][i]>='a' && v[n][i]<='z' ) ||  (v[n][i]>='A' && v[n][i]<='Z' ) ) ) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	
	if(v.size()==0 || v[0]==""){
		recenica=IzmijeniSve(recenica);
		return recenica;
	}
	
	for(unsigned int n=0; n<v.size();n++){
		for(unsigned int i =0; i<recenica.length(); i++){
			unsigned int k=i;
			unsigned int j=0;
			while(j<v.at(n).length() && k<recenica.length()&& recenica.at(k)==v.at(n).at(j)){
				k++;j++;
				if(j==v.at(n).length() && (i==0 || !((recenica[i-1]>='a' && recenica[i-1]<='z' ) ||  (recenica[i-1]>='A' && recenica[i-1]<='Z' )))&& (k==recenica.length() || !((recenica[k]>='a' && recenica[k]<='z' ) ||  (recenica[k]>='A' && recenica[k]<='Z' )) )   ){
					j=1;
					for(unsigned int p=i; p<k;p++){
						
						if(j<v[n].length()){
							recenica[p]=v[n][j];
							j++;}
						else
							recenica[p]=v[n][0];
					}
					recenica.push_back(' ');
					recenica.push_back(' ');
					for(unsigned int r=recenica.length()-1; r>k+1; r--){
						recenica[r]=recenica[r-2];
					}
					recenica[k]='a';
					recenica[k+1]='y';
					break;
		    	}   
			}
		}
	}
    return recenica;	
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
    std::cout << "Unesite fraze: ";
	std::vector<std::string> v;
	std::string s;
	char znak;
	do {
		std::getline(std::cin, s);
		znak=char(std::cin.peek());
		v.push_back(s);
	}while (znak!='\n');
	
    
    try {
    	std::cout <<"Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica,v) << std::endl;
    }
     catch (std::domain_error greska) {
      std::cout <<"Izuzetak: "<< greska.what() << std::endl;
    }
    
	std::cout<<"Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,v);
	return 0;
}