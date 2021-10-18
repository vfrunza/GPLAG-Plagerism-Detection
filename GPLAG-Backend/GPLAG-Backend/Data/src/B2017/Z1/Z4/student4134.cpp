#include<iostream>
#include<vector>
#include<string>

std::string ObrtanjeStringa(std::string S1) {
	std::string NekiString;
	for(int i=S1.length()-1;i>=0;i--) {
		NekiString.push_back(S1.at(i));
	}
	
	return NekiString;
}

std::string ObrtanjePoluStringa(std::string S1) {
	std::string NekiString;
	std::string NekiString2;
	
	for(int i=0; i<S1.length()/2; i++) {
		NekiString.push_back(S1.at(i));
	}
	
	for(int i=(NekiString.length()-1); i>=0 ; i--) {
		NekiString2.push_back(NekiString.at(i));
	}
	
	return NekiString2;
}

 std::string NapraviPalindrom(std::string S, std::vector<std::string> VS) {
	
std::string p;
int i=0;

	while( i<VS.size()) {
		
		p=VS.at(i);
		
		
		for(int j=0;j<S.length();j++){
			
			std::string Bezveze;
			Bezveze=S.substr(j, p.size() ) ;
			
			if( Bezveze == p && (j+p.size()>=S.size() || (S.at(j+p.size())<'A' || (S.at(j+p.size())>'Z' && S.at(j+p.size())<'a') || S.at(j+p.size())>'z'))){
				S.insert(j+(p.size()), ObrtanjeStringa(p));
			}
		}
		i++;
		
	}
	
	return S;
}

std::string NapraviPoluPalindrom(std::string S, std::vector<std::string> VS) {
	
std::string p;
int i=0;
  
  
    while(i<VS.size()) {
    	p=VS.at(i);
    	
    	
    	for(int j=0; j<S.length(); j++) {
    		
    		std::string Bezveze;
    		Bezveze=S.substr(j, p.size() );
    	
    	  if( Bezveze == p && (j+p.size()>=S.size() || (S.at(j+p.size())<'A' || (S.at(j+p.size())>'Z' && S.at(j+p.size())<'a') || S.at(j+p.size())>'z'))){
    		if(Bezveze.size()%2==0) {
    			S.erase(j+p.size()/2,p.size()/2);
    			S.insert(j+p.size()/2, ObrtanjePoluStringa(p));
    			}
    			else if (Bezveze.size()%2!=0){
    				S.erase(j+p.size()/2+1,p.size()/2);
    				S.insert(j+1+p.size()/2, ObrtanjePoluStringa(p));
    			}
    	 }
    	}
    	i++;
    }
return S;
}

int main() {
	
	std::string S;
	std::string S1;
	std::vector<std::string> VS;
	
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,S);
	std::cout<<"Unesite fraze: ";
	do{
	std::getline(std::cin,S1);
	if(S1=="")
	break;
	
	else VS.push_back(S1);
	}while(S1!="\n");
	
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(S,VS);
	std::cout<<"\nRecenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(S,VS);

	
	return 0;
}
	