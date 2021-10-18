#include<iostream>
#include <stdexcept>
#include <vector>
#include <string>

std::string Piiiig(std::string pig){
	pig=pig.substr(1,pig.length()-1)+pig[0]+"ay";
	return pig;
}

bool neslovo(char p){
	if((!(p>='a' && p<='z')||(p>='A' && p<='Z')) ) return true;
	return false;
}
std::string ObrniFraze(std::string striing,std::vector<std::string>v)
{
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<striing.length(); j++){
			if(striing.substr(j,v[i].length())==v[i]){
				for(int k=0; k<(v[i].length()/2); k++){
					char tmp=v[i][k];
					v[i][k]=v[i][v[i].length()-k-1];
					v[i][v[i].length()-k-1]=tmp;
				}
				striing=striing.substr(0,j)+v[i]+striing.substr(j+v[i].length(),striing.size()-j-v[i].length());
			}
			
		}
	}
	
	return striing;
	
}

std::string IzmijeniUPigLatin(std::string striing, std::vector<std::string>v){
	bool p=1; for(std::string red : v){
		for(int x: red){
			if(!((x>='A' && x<='Z')||(x>='a' && x<='z'))) p=0;
		}
	}
	if(p==0) throw std::domain_error("Nekorektan izbor riječi");
	if(v.size()!=0){
		std::string pig;
		for(std::string c : v){
			for(int j=0; j<striing.length(); j++){
				if(striing.substr(j,c.length())==c && (neslovo(striing[c.length()+j] || c.length()+j==striing.length() )) && (neslovo(striing[j-1]) || j==0))
				
				striing=striing.substr(0,j)+Piiiig(c)+striing.substr(c.length()+j,striing.length()-j-c.length());
				
			}
		}
	}
	else{
		p=1;
		for(int i=0; i<striing.length(); i++){
			if(neslovo(striing[i]))p=1;
			else if(p==1){
				p=0;
			int k=i;
			while(!neslovo(striing[k]) && k<striing.length())
			{
				k++;
			}	
			for(int j=i; j<k/2; j++){
				char tmp=striing[j];
				striing[j]=striing[k-i-1];
				striing[k-i-1]=tmp;
			}	
				
				
				
			}
		}
		
		

		
}
return striing;
}


int main ()
{   
	std::vector<std::string>vektor;
	std::string s,f;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	do{
		std::getline(std::cin,f);
		if(f.length()==0)break;
		vektor.push_back(f);
	}while(f.length()!=0);
	std::string noovi;
	noovi=s;
   std::string novi;
   try {
   novi=IzmijeniUPigLatin(s,vektor);
   std::cout<<"Recenica nakon PigLatin transformacije: ";
   std::cout<<novi<<std::endl;
   }
   catch (std:: domain_error izuzetak) {
   	std::cout <<"Izuzetak: "<<izuzetak.what()<< std::endl;
   }
   
   std::string novi2;
   novi2=ObrniFraze(noovi,vektor);
   std::cout<<"Recenica nakon obrtanja fraza: ";
   std::cout<<novi2;
	return 0;
}