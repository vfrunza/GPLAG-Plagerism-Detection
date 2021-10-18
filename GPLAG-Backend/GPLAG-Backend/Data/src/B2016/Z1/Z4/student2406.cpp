#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<stdexcept>


using namespace std;
 
 std::string ObrniFraze(std::string Recenica,std::vector<std::string>SpisakRijeci){
 	for(int i = 0; i < SpisakRijeci.size(); i++){
 		for(int j = 0; j < Recenica.size(); j++){
 			if(Recenica.substr(j, SpisakRijeci[i].size()) == SpisakRijeci[i]){
 				
 				int p=j, k=j+SpisakRijeci[i].size()-1;
 				while(p < k){
 					char m=Recenica[p];
 					Recenica[p]=Recenica[k];
 					Recenica[k]=m;
 					k--;
 					p++;
 				}
 			}
 		}
 	} 
 	return Recenica;
 }
 
 string pigl(string s)
 {
 	string p;
 	for(int i=1; i<s.size(); i++) p+=s[i];
 	p+=s[0];
 	p+="ay";
 	return p;
 	
 }
 
 std::string IzmijeniUPigLatin(std::string Recenica, std::vector<std::string> PopisRijeci){
 	for(int i = 0; i < PopisRijeci.size(); i++){
 		for( int j  = 0; j < PopisRijeci[i].size(); j++)
 		{
 			if(PopisRijeci[i][j] < 'A' || (PopisRijeci[i][j] >'Z' && PopisRijeci[i][j]< 'a') || PopisRijeci[i][j]> 'z'){
 				throw domain_error (" Nekorektan izbor rijeci");
 			}
 		}
 	}
 	
 	for(int i = 0; i <PopisRijeci.size(); i++){
 		for(int j=0; j<Recenica.size(); j++)
 		{
 			if(Recenica.substr(j, PopisRijeci[i].size())==PopisRijeci[i])
 			{
 				Recenica=Recenica.substr(0,j)+pigl(PopisRijeci[i])+Recenica.substr(j+PopisRijeci[i].size(), Recenica.size()-j);
 			}
 		}
 	}
 	
 	return Recenica;
 }
 
 

int main ()
{    

    
    
	std::string Recenica;
	std::vector<std::string> v;
	
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin , Recenica);
	std::cout<<"Unesite fraze: ";
	
	while(7){
		std::string rijec;
		std::getline(std::cin , rijec);
		if(rijec.size() == 0) break;
		v.push_back(rijec);
	}
	try{
		string a=IzmijeniUPigLatin(Recenica , v);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<a<<endl;
	}
	catch(domain_error	e)
	{
		cout<<"Izuzetak: "<<e.what()<<endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(Recenica , v);
		
	
	
	return 0;
}