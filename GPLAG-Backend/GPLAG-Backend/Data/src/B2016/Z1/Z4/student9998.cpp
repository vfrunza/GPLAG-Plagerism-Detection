#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

std::string obrni(std::string s){
	std::string s1;
	for(int i=s.length()-1;i>=0;i--)
		s1.push_back(s[i]);
	return s1;
}

std::string svinja(std::string s){
	std::string s1;
	for(int i=1;i<s.length();i++)
		s1.push_back(s[i]);
	s1=s1+s[0]+"ay";
	return s1;
}

bool engl_alph(std::string s){
	for(int i=0;i<s.length();i++)
		if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))) return false;
	return true;
}

bool slovo(char s){
	if(!((s>='a' && s<='z') || (s>='A' && s<='Z'))) return false;
	return true;
}

std::string ObrniFraze(std::string s, std::vector<std::string>rijeci){
	if(rijeci.size()==0) return s;
	for(int i=0;i<rijeci.size();i++){
		for(int j=0;j<s.length();j++){
			if(s.substr(j,rijeci[i].length())==rijeci[i]){
				std::string pomocni=obrni(s.substr(j,rijeci[i].length()));
				s=s.substr(0,j)+pomocni+s.substr(j+rijeci[i].length(),s.length());
			//	j+=(rijeci[i].length()-1);
			}
		}
	}
	
	return s;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string>fraze){
	for(int i=0;i<fraze.size();i++)
		if(!engl_alph(fraze[i])) throw std::domain_error ("Nekorektan izbor rijeci");
	
	if(s.length()==0) return s;
	
	if(fraze.size()==0){
		for(int i=0;i<s.length();i++){
			bool dobro=false;
			for(int i=0;i<s.length();i++){	if(slovo(s[i])) dobro=true; }
		if(dobro==false) return s;
		else{
			int index1, index2;
			while(!slovo(s[i]) && i!=s.length()) i++;
			index1=i;
			while(slovo(s[i]) && i!=s.length()) i++;
			index2=i;
			std::string pomocni=svinja(s.substr(index1, index2-index1));
			if(index1==index2) return s; 
			s=s.substr(0,index1)+pomocni+s.substr(index2,s.length());
			i+=2; 
		}
	  }
	}
	
	for(int i=0;i<fraze.size();i++){
	//	if(!engl_alph(fraze[i])) throw std::domain_error ("Nekorektan izbor rijeci");
		for(int j=0;j<s.length();j++){
			int index1, index2;
			while(!slovo(s[j]) && j!=s.length()) j++;
			index1=j;
			while(slovo(s[j]) && j!=s.length()) j++;
			index2=j;
			if(s.substr(index1, index2-index1)==fraze[i]){
				std::string pomocni=svinja(s.substr(index1,index2-index1));
				s=s.substr(0,index1)+pomocni+s.substr(index2,s.length());
				j+=(fraze[i].length()-1);
			}
		}
	}
	return s;
}

int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector <std::string> h ;
	std::cout<<"Unesite fraze: ";
	for(;;){
		std::string s1;
		std::getline(std::cin,s1);
	    if(!s1.length()) break;
	    h.push_back(s1);
		if(std::cin.peek()=='\n') break;
	}
	try{
		IzmijeniUPigLatin(s,h);
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<IzmijeniUPigLatin(s,h);
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	std::cout<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<ObrniFraze(s,h);
	return 0;
}