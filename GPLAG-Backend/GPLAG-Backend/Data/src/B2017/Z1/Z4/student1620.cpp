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
#include <cmath>
#include <vector>
#include <string>
std::string NapraviPalindrom (std::string a,std::vector<std::string> b){
	int i(0),o(0);
	std::string temp,re;
	re = a;
	for (std::string k : b){
		i =0;
		for (int h= 0;h<re.size();h++){
			if (re.at(h) == k.at(i)){
				if(i == k.size() - 1){
					if(h != re.size() - 1){
						if((re.at(h+1) >= 'a' && re.at(h+1) <= 'z') || (re.at(h+1) >= 'A' && re.at(h+1) <= 'Z') ){
							continue;
						}
					}
					for(int j = k.size() - 1; j >=0;j--){
						temp.insert(o,1,k.at(j));
						o++;
					}
					if(h == re.size() - 1){
						re.append(temp);
					} else {
					re.insert(h + 1,temp);
					}
					h = h + k.size();
					o =0;
					i =0;
					temp.clear();
					
				}
				i++;
			} else {
				i =0;
			}
		}
	}
	return re;
}
std::string NapraviPoluPalindrom (std::string a,std::vector<std::string> b){
	int i(0),o(0);
	std::string temp,re;
	re = a;
	for(std::string k : b){
		i = 0;
		for(int h =0;h<re.size();h++){
			if (re.at(h) == k.at(i)){
				if (i == k.size() - 1){
					if(i % 2 ==0){
						for(int j = (k.size() / 2) - 1; j >=0;j--){
							temp.insert(o,1,k.at(j));
							o++;
						}
						re.replace(h - temp.size() + 1,temp.size(),temp);
						h = h + k.size();
						o =0;
						i =0;
						temp.clear();
					} else {
						for(int j = (k.size() / 2) - 1; j >=0;j--){
							temp.insert(o,1,k.at(j));
							o++;
						}
						re.replace(h - temp.size() + 1,temp.size(),temp);
						h = h + k.size();
						o =0;
						i =0;
						temp.clear();
					}
				}
				i++;
			} else {
				i =0;
			}
			
		}
	}
	return re;
}

int main ()
{
	std::vector<std::string>c;
	std::string a,b,re,re2;
	std::cout << "Unesite recenicu: ";
	std::getline (std::cin,a);
	std::cout <<"Unesite fraze: ";
	while(1){
		std::getline (std::cin,b);
		if (b.size() == 0){
			break;
		} else {
			c.push_back(b);
		}
	}
	re = NapraviPalindrom(a,c);
	re2 = NapraviPoluPalindrom(a,c);
	std::cout << "Recenica nakon Palindrom transformacije: " << re << "\nRecenica nakon PoluPalindrom transformacije: " << re2;
	
	return 0;
}