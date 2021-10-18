#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

bool IsAlpha(std::string s) {
	for(int i=0; i<s.length(); i++) {
		if (!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) return false;
		
	}
	return true;
}


std::string ObrniFraze(std::string s, std::vector<std::string> v) {
	
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<s.size(); j++) {
		if ((s.substr(j, v[i].size())==v[i]) /* && (s[j+ v[i].size()]==' ') && (j==0 ||  ( j != 0 &&  s[j-1] == ' '))*/) {
         
           	char tmp;
           	int l(0);
           	for(int k=j; k<(j+(v[i].size())/2); k++) {
           	 tmp = s[k]; 
           	 s[k] = s[j+v[i].size()-l-1];
           	 s[j+v[i].size()-l-1] = tmp;
           	 
        	 l++;
           	}
         }
         
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v) {

	if(v.size()==0) {
		
		int p, k;
		for(int i=0; i<s.length(); i++ ) {
      //if(s[i] ==' ' || s[i] =='\t') { while(s[i] ==' ' || s[i] =='\t') i++; }
       if(((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) {
         //  std::cout <<"Testni izlaz";
            p =i;
           while(((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) i++; 
         k=i;     
      
      char tmp = s[p];
		
			s.insert(s.begin()+k, tmp);
			s.insert(s.begin()+k+1, 'a');
			s.insert(s.begin()+k+2, 'y');
			s.erase(s.begin()+p);
       }
	}
}
	
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<(s.size()-v[i].size()); j++) {
	 if ((s.substr(j, v[i].size())==v[i]) && (s[j+ v[i].size()]==' ') && (j==0 ||  ( j != 0 &&  s[j-1] == ' '))) {
         //  if (s.substr(j, v[i].size())==v[i])  {
			char tmp = s[j];
		
			s.insert(s.begin()+j+v[i].size(), tmp);
			s.insert(s.begin()+j+v[i].size()+1, 'a');
			s.insert(s.begin()+j+v[i].size()+2, 'y');
			s.erase(s.begin()+j);
         }
       }
	}
	
	return s;

}
int main ()
{
	
	try {
	std::string recenica, fraza;
	std::vector<std::string> v;
	
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::cout << "Unesite fraze: ";

	
	while(1) {
		std::getline(std::cin, fraza);
		if(fraza=="") break;
		
		v.push_back(fraza); 
		try {
		if(IsAlpha(fraza)==false) throw std::domain_error("Nekorektan izbor riječi");
		}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}

	}


	auto pig (IzmijeniUPigLatin(recenica, v));
	
	std::cout << "Recenica nakon PigLatin transformacije: ";
	std::cout << pig;
	
	std::string obrnut (ObrniFraze(recenica, v));
	
	std::cout <<std::endl << "Recenica nakon obrtanja fraza: ";
	std::cout << obrnut;
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}

	
	return 0;
}