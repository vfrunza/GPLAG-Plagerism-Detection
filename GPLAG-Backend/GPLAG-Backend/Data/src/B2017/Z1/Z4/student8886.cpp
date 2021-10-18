/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
std::vector<int> ConvertToASCII(std::string s){
	std::vector<int> v;
	for(int i=0; i<s.length(); i++){
		char x=s.at(i);
		v.push_back(int(x));
	}
	return v;
}
std::string ConvertToString(std::vector<int> v){
	std::string s;
	for(int i=0; i<v.size(); i++){
		int broj=v.at(i);
		s.push_back((char) broj);
	}
	return s;
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	if(v.size() == 0) throw std::domain_error("");
	std::vector<int> pomocna;
	int k(0);
	auto vecrecenica = ConvertToASCII(s);
	
	for(int i=0; i<v.size(); i++){
		pomocna.clear();
		auto vecrijec = ConvertToASCII(v.at(i));
		bool slaganje = false;
		for(int j=0; j<vecrecenica.size(); j++){
			k=0;
			slaganje=false;
			int broj=j;
			pomocna.push_back(vecrecenica.at(j));
			if(j+vecrijec.size()>vecrecenica.size()) slaganje=false;
			else if((j==0 && j+vecrijec.size()==vecrecenica.size()) || (j==0 && (vecrecenica.at(j+vecrijec.size())==32 || vecrecenica.at(j+vecrijec.size()) < 65)) || (j+vecrijec.size()==vecrecenica.size() && vecrecenica.at(j-1)==32))
			while(j < vecrecenica.size() && k < vecrijec.size() && vecrecenica.at(broj)==vecrijec.at(0)  ){
				if(j!=broj) pomocna.push_back(vecrecenica.at(j));
				if(vecrecenica.at(j)!=vecrijec.at(k)){
					slaganje=false; 
					
					break;
				}
				else{
					slaganje = true;
				}
				j++;
				k++;
			}
			else
			while(j < vecrecenica.size() && k<vecrijec.size() && vecrecenica.at(broj)==vecrijec.at(0) && vecrecenica.at(broj-1)==32 && (vecrecenica.at(broj+vecrijec.size())==32 || vecrecenica.at(broj+vecrijec.size())<65 )){
				if(j!=broj) pomocna.push_back(vecrecenica.at(j));
				if(vecrecenica.at(j)!=vecrijec.at(k)){
					slaganje=false;
					break;
				}
				else{
					slaganje = true;
				}
				j++;
				k++;
			}
		//	std::cout<<j;
		//	std::cout<<j;
			k=0;
		
			if(slaganje == true){
				for(int l=vecrijec.size()-1; l>=0; l--){
					pomocna.push_back(vecrijec.at(l));
				}
				j--;
			} 
//			std::cout<<ConvertToString(pomocna)<<std::endl;
		}
		vecrecenica=pomocna;
	}
//	for(int l=0; l<pomocna.size(); l++) std::cout<<pomocna.at(l)<<",";
	auto recenica=ConvertToString(pomocna);
//	std::cout<<recenica;
	return recenica;
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v){
	if(v.size()==0) throw std::domain_error("");
	std::vector<int> pomocna;
	int k(0);
	auto vecrecenica=ConvertToASCII(s);
	for(int i=0; i<v.size(); i++){
		pomocna.clear();
		auto vecrijec=ConvertToASCII(v.at(i));
		bool slaganje= false;
		k=0;
		for(int j=0; j<vecrecenica.size(); j++){
			slaganje=false;
			int broj=j;
			k=0;
			if(j+vecrijec.size()>vecrecenica.size()) slaganje=false;
		    else if((j==0 && j+vecrijec.size()==vecrecenica.size() && vecrecenica.at(broj)==vecrijec.at(0)) || (j==0 && (vecrecenica.at(j+vecrijec.size())==32 || vecrecenica.at(j+vecrijec.size())<65) && vecrecenica.at(broj)==vecrijec.at(0)) || (j+vecrijec.size()==vecrecenica.size() && vecrecenica.at(j-1)==32 && vecrecenica.at(broj)==vecrijec.at(0)))
			while(k < vecrijec.size() && j < vecrecenica.size() && vecrecenica.at(broj)==vecrijec.at(0) ){
				if(vecrecenica.at(j)!=vecrijec.at(k)){
					slaganje=false;
					
					break;
				}
				else slaganje=true;
				k++;
				j++;
			//	std::cout<<j<<"...";
			}
			else
			while(k < vecrijec.size() && j < vecrecenica.size() && vecrecenica.at(broj)==vecrijec.at(0) && vecrecenica.at(broj-1)==32 && (vecrecenica.at(broj+vecrijec.size())==32 || vecrecenica.at(broj+vecrijec.size())<65)){
				if(vecrecenica.at(j)!=vecrijec.at(k)){
					slaganje=false;
					break;
				}
				else slaganje=true;
				k++;
				j++;
			}
			
		//	std::cout<<slaganje<<", ";
		 //   std::cout<<j<<" ...";
			if(slaganje == false){
				for(int l=j-k; l<j+1; l++) pomocna.push_back(vecrecenica.at(l));
			}
			if(slaganje == true){
				j--;
				for(int l=0; l<vecrijec.size()/2; l++) pomocna.push_back(vecrijec.at(l));
				if(vecrijec.size()%2==0) for(int l=vecrijec.size()/2-1; l>=0; l--) pomocna.push_back(vecrijec.at(l));
				else for(int l=vecrijec.size()/2; l>=0; l--) pomocna.push_back(vecrijec.at(l));
				
			}
			
		
		}
//			std::cout<<ConvertToString(pomocna);
		vecrecenica=pomocna;
	}
	auto recenica=ConvertToString(pomocna);
	return recenica;
}
int main ()
{
	std::string recenica;
	std::vector<std::string> v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::string fraza;
	
	while(std::cin.peek()!='\n'){
		std::getline(std::cin, fraza);
		v.push_back(fraza);
		
		
	}
	try{
	    NapraviPalindrom(recenica,v);
	    NapraviPoluPalindrom(recenica,v);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
		std::cout<<"Recenica nakon Palindrom transformacije: "<<recenica;
		std::cout<<std::endl;
		std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<recenica;
		return 0;
	}
//	auto palindrom=NapraviPalindrom(recenica,v);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	for( const char x: NapraviPalindrom(recenica, v)){
		std::cout<<x;
	}
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	for(const char x : NapraviPoluPalindrom(recenica,v)){
		std::cout<<x;
	}
	
	
	return 0;
}