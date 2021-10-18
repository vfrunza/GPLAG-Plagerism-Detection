#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> vs) {
	for(std::string x : vs) {
		for(int i(0); i<s.length(); i++) {
			if(s[i]==x[0] and s.substr(i, x.length())==x) {					//pronadjen podstring
				std::string s3;
				for(int k(x.length()-1); k>=0; k--)
					s3.push_back(x[k]);
				int y(i);
				for(int t(0); t<s3.length(); t++, y++)
					s[y]=s3[t];
			}
		}
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> vs) {
	if(vs.size()==0) {
		//bool a(false);
		for(int i(0); i<s.length(); i++) {
			int prvo, vel(0);
			while((s[i] < 'A' or s[i] > 'Z') and (s[i] < 'a' or s[i] > 'z')) i++;
			prvo=i;
			i++;
			while((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z')) {
				//if(!a) prvo=i;
				vel++;
				//a=true;
				i++;
			}
			//if((s[i] < 'A' or s[i] > 'Z') and (s[i] < 'a' or s[i] > 'z')) {
				char c(s[prvo]);
				s.erase(s.begin() + prvo);
				s.insert(s.begin() + prvo+vel, c);
				s.insert(s.begin() + prvo+vel+1, 'a');
				s.insert(s.begin() + prvo+vel+2, 'y');
				//a=false;
				i+=2;
			//}
		}
	}
	for(std::string x : vs)
			for(char y : x)
				if((y < 'A' or y > 'Z') and (y < 'a' or y > 'z')) throw std::domain_error("Nekorektan izbor rijeci");
				
	for(std::string x : vs) {
		for(int i(0); i<s.length(); i++) {
			if(s[i]==x[0] and s.substr(i, x.length())==x) {
				
				if(i==0 and (((s[i+x.length()]<'A' or s[i+x.length()]>'Z') and (s[i+x.length()]<'a' or s[i+x.length()]>'z')) or (i+x.length()-1)==(s.length()-1))) {
					char c(s[i]);
					s.erase(s.begin() + i);
					s.insert(s.begin() + i+x.size()-1, c);
					s.insert(s.begin() + i+x.size(), 'a');
					s.insert(s.begin() + i+x.size()+1, 'y');
					i+=x.size()+1;
				}
				if(i>0)
					if(((s[i-1]<'A' or s[i-1]>'Z') and (s[i-1]<'a' or s[i-1]>'z')) and (((s[i+x.length()]<'A' or s[i+x.length()]>'Z') and (s[i+x.length()]<'a' or s[i+x.length()]>'z')) or i+x.length()-1==s.length()-1)) {
						char c(s[i]);
						s.erase(s.begin() + i);
						s.insert(s.begin() + i+x.size()-1, c);
						s.insert(s.begin() + i+x.size(), 'a');
						s.insert(s.begin() + i+x.size()+1, 'y');
						i+=x.size()+1;
					}
			}
		}
	}
	return s;
}

int main ()
{
		std::string s;
		std::cout << "Unesite recenicu: ";
		std::getline(std::cin, s);
		int i(1);
		std::vector<std::string> vs(0);
		std::cout << "Unesite fraze: ";
		while(std::cin.peek()!='\n') {
			vs.resize(i);
			std::getline(std::cin, vs[i-1]);
			i++;
		}
	try {
	std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s, vs) << std::endl;
	}
	catch(std::domain_error a) {
		std::cout <<"Izuzetak: " << a.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, vs) << std::endl;
	return 0;
}