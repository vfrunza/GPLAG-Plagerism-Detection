#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> fraze){
    char x;
    int l;
    if(fraze.size() == 0)
    	return s;
	for(unsigned int i = 0; i < fraze.size(); i++){
	    if(fraze[i].length() > s.length() || fraze[i].length() == 0)
	        continue;
	    for(unsigned int j = 0; j <= s.length() - fraze[i].length(); j++){
	        if(s.substr(j, fraze[i].length()) == fraze[i]){
		            l = 1;
		            for(unsigned int k = j; k < j + (fraze[i].length()/2); k++){
		                x = s[k];
		                s[k] = s[j + fraze[i].length() - l];
		                s[j + fraze[i].length() - l] = x;
		                l++;
		            }
	        }
	    }
	}
	return s;
}
bool jeSlovo(char x){
	return ((x >= 'A' && x <= 'Z') ||(x >= 'a' && x <= 'z'));
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> fraze){
    std::string tmp;
    bool sve = false;
    if(fraze.size() == 0){
    	sve = true;
    }
    for(unsigned int i = 0; i < fraze.size(); i++){
    	for(unsigned int j = 0; j < fraze[i].length(); j++){
    		if(!jeSlovo(fraze[i][j]))
    			throw std::domain_error("Nekorektan izbor rijeci");
    	}
    }
	for(unsigned int i = 0; i < fraze.size() || sve; i++){
		unsigned int j(0), p , q;
		while(j < s.length()){
			while(j != 0 && !jeSlovo(s[j]) && j < s.length()) j++;
			p = j;
			while(jeSlovo(s[j]) && j < s.length()) j++;
			q = j-1;
			if(sve || s.substr(p, q-p+1) == fraze[i]){
				tmp = s.substr(p, q-p+1);
				if(tmp.length()>0){
					tmp.push_back(tmp[0]);
					tmp += "ay";
					tmp.erase(tmp.begin());
					s = s.substr(0, p) + tmp + s.substr(j, s.length() - j);
					j = q + 2;
				}
			}
			j++;
		}
		if(sve) break;
	}
	return s;
}
int main () {
    std::cout <<"Unesite recenicu: ";
    std::string s;
    std::getline(std::cin, s);
    std::string s2(s);
    std::vector <std::string> fraze;
    std::string tmp;
    std::cout << "Unesite fraze: ";
    for(;;){
    	std::getline(std::cin, tmp);
    	if(tmp.length() < 1)
    		break;
    	fraze.push_back(tmp);
    }
    try{
    	tmp = IzmijeniUPigLatin(s, fraze);
    	std::cout <<"Recenica nakon PigLatin transformacije: ";
    	std::cout << tmp << std::endl;
    }catch(std::domain_error except){
    	std::cout << "Izuzetak: " << except.what()<< std::endl;
    }
    std::cout <<"Recenica nakon obrtanja fraza: " << ObrniFraze(s2,fraze);
	return 0;
}