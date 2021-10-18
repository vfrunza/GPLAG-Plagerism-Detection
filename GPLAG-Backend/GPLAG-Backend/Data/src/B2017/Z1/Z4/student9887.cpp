
#include <string>
#include <iostream>
#include <vector>
bool Slovo(std::string s, int pozicija){
		bool slovo=false;
	for(int i=0;i<s.length();i++){
		if((s.at(pozicija)>='a' && s.at(pozicija)<='z' )||(s.at(pozicija)>='A' &&s.at(pozicija)<='Z') ){
		slovo=true;
		break;}
	}
	return slovo;
}
int BrojRijeci(std::string s){

bool razmak=true;
    int broj_rijeci=0;
    int i(0);
        while(i<s.length()){
        if(s.at(i)==' ')
         razmak=true;
         else if(razmak){
             razmak=false;
             broj_rijeci++;
         }
            i++;
        }
	return broj_rijeci;
}
std::string ObrniRijec(std::string s){
	std::string pomocni;
	for(int i=s.length()-1;i>=0;i--){
		pomocni.push_back(s.at(i));
	}
	return pomocni;
} 
std::string ObrniOdredjenuRijec (std::string s, std::vector<std::string> V, int j){
	int i(0), pozicija(0);
  std::string pomocni=V.at(j);
	while(i<s.length() && j<V.size() && pozicija!=-1){
	
	 	pozicija=s.find(V.at(j), i);
		
		while(i<s.length() && i!=pozicija+V.at(j).size()){ 
			i++;
		}
if(pozicija!=-1 && ((pozicija!=0 && pozicija!=s.length()-V.at(j).size() &&  (Slovo(s, pozicija-1)==false || s.at(pozicija-1)==' ') && (Slovo(s, pozicija+V.at(j).size())==false || s.at(pozicija+V.at(j).size())==' ')) || (pozicija==0 && BrojRijeci(s)!=1 && (( s.at( pozicija+V.at(j).size()))==' ' || Slovo(s, pozicija+V.at(j).size())==false)) || (pozicija==s.length()-V.at(j).size() && (Slovo(s, pozicija-1)==false || s.at(pozicija-1)==' ') ) || (pozicija==0  && s.length()==V.at(j).size())))

        s.insert(i,ObrniRijec(V.at(j))); 

		
	}
	return s;
	
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> V){
if(V.size()==0) throw "Nisu unesene fraze";
	for(int j=0;j<V.size();j++){
		s=ObrniOdredjenuRijec(s,V,j);
	}
	
	return s;}
std::string ObrniDioRijeci(std::string rijec){
	std::string pomocni;
	if(rijec.length()%2!=0){
	for(int i=rijec.length()/2;i>=0;i--){
		pomocni.push_back(rijec.at(i));
	}}
	else{
		for(int i=rijec.length()/2-1;i>=0;i--){
		pomocni.push_back(rijec.at(i));
	}
		
	}
	return pomocni;
}
std::string ObrniPolaRijeci(std::string s, std::vector<std::string> V, int j){
		int i(0), pozicija(0);

	while(i<s.length() && j<V.size() && pozicija!=-1){
	
	 	pozicija=s.find(V.at(j), i);
		
		while(i<s.length() && i!=pozicija+V.at(j).size()/2){ 
			i++;
		}
				if(pozicija!=-1 && ((pozicija!=0 && pozicija!=s.length()-V.at(j).size() &&  (Slovo(s, pozicija-1)==false || s.at(pozicija-1)==' ') && (Slovo(s, pozicija+V.at(j).size())==false || s.at(pozicija+V.at(j).size())==' ')) || (pozicija==0 && (Slovo(s, pozicija+V.at(j).size())==false || s.at( pozicija+V.at(j).size())==' ')) || (pozicija==s.length()-V.at(j).size() && (Slovo(s, pozicija-1)==false || s.at(pozicija-1)==' ') )))


		
{s.erase(s.begin() +i, s.begin()+i +V.at(j).size()/2 +V.at(j).size()%2);
        s.insert(i,ObrniDioRijeci(V.at(j)));}
	}
	
	      
	
	return s;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> V){
	if(V.size()==0) throw "Nisu unesene fraze";
	for(int j=0;j<V.size();j++){
		s=ObrniPolaRijeci(s,V,j);
	}
	return s;
}
int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s, '\n');
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> V;
	do {
		std::string pomocni;
		std::getline(std::cin, pomocni, '\n');
	
		V.push_back(pomocni);
	} while(std::cin.peek()!='\n'); 
	if(V.size()==1 && (!(V.at(0)>="A" && V.at(0)<="Z")) && (!(V.at(0)>="a" && V.at(0)<="z" )) )
	V.resize(0);
		
	std::cout<<"Recenica nakon Palindrom transformacije: ";
    try{
	std::string palindrom=NapraviPalindrom(s,V);
	std::cout<<palindrom<<std::endl;
	
    }catch(...){
    	std::cout<<s;
    }
	
			std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	
	try{std::string polupalindrom=NapraviPoluPalindrom(s,V);
	std::cout<<polupalindrom;}
	catch(...){
		std::cout<<s;
	}
	

		
	
	

return 0;
}
