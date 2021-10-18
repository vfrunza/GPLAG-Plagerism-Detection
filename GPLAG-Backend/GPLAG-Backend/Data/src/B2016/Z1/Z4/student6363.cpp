#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	for (unsigned int i(0); i<v.size(); i++){
		std::string t(v[i]);
		for( unsigned int j(0); j<s.length(); j++){
			if(s[j]==t[0]){
				std::string temp = s.substr(j, t.length());
				if(temp == t){
				int pocetak(j), kraj(j+t.length()-1);
					while (pocetak<kraj){
						char te(s[pocetak]);
						s[pocetak] = s[kraj];
						s[kraj] = te;
						pocetak++;
						kraj--;
					}
				}
			}
		}
		
	}
	return s;
}

bool DaLiJeAlfa(std::vector<std::string> v){
	if(v.size() == 0) return false;
	for(unsigned int i(0); i<v.size(); i++){
		std::string t(v[i]);
		for(unsigned int j(0); j < t.size(); j++){
			
			if(!((t[j]>='a' && t[j]<='z') || (t[j]>='A' && t[j]<='Z'))) return true;
		}
	}
	return false;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	if(DaLiJeAlfa(v)) throw std::domain_error("Nekorektan izbor rijeci");
	if(v.size() != 0){
	for(unsigned int i(0); i < v.size(); i++){
		for(unsigned int j(0); j < s.length(); j++){
				if((j!=0 && s[j-1]==' ' && s[j]==v[i][0]) || (j==0 && s[j]==v[i][0])){
					std::string temp = s.substr(j, v[i].length());
					if(temp == v[i]){
						int pocetak(j), kraj(j+v[i].length()-1);
						char tempo = s[pocetak];
						s.erase(s.begin() + pocetak);
						s.insert(s.begin()+kraj, tempo);
						s.insert(s.begin()+kraj + 1, 'a');
						s.insert(s.begin() + kraj + 2, 'y');
					}
				}
			
		}
	}
	}
	else {
		for(unsigned int i(0); i < s.length(); i+=3){
		while (i<s.length()&&(s[i] == ' ' || s[i]==',' || s[i]=='.')) i++;
		if(i == s.length()) break;
		int pocetak(i);
		while(i<s.length() && s[i]!= ' ' && s[i]!='.' && s[i]!=',') i++;
		
		int kraj(i-1);
		char timo(s[pocetak]);
		s.erase(s.begin()+pocetak);
		s.insert(s.begin()+kraj, timo);
		s.insert(s.begin() + kraj +1, 'a');
		s.insert(s.begin() + kraj +2, 'y');
		
		
		
	}
	}
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	while(1){
		std::string f;
		do{
			char c = std::cin.get();
			if(c!='\n') f.push_back(c);
			else break;
		}while(1);
		v.push_back(f);
		if(std::cin.peek() == '\n') break;
	}
	std::cin.ignore(1000, '\n');
	try{
	std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s,v)<<std::endl;
	}
	catch(std::domain_error e) {std::cout <<"Izuzetak: "<< e.what()<<std::endl;}
	
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s,v);
	
	return 0;
}