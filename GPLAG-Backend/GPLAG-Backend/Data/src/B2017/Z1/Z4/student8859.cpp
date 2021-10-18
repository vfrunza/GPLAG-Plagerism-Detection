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
#include <string>
#include <iterator>
#include <vector>

bool znak(char c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z')) return false;
	return true;

}

std::string IzvrniString(std::string s)
{
	char pom;
	for(int i=0; i<s.length()/2; i++) {
		pom=s.at(i);
		s.at(i)=s.at(s.length()-i-1);
		s.at(s.length()-i-1)=pom;
	}
	return s;
}

std::string NapraviPalindrom(std::string s, std::vector<std::string> vs)
{
	if(s.size()==0) return s;
	if(vs.size()==0) return s;

	for(int i=0; i<vs.size(); i++) {
		std::string fraza= vs.at(i);
		//std::cout<<fraza<<std::endl;
		for(int j=0; j<=int(s.size())-fraza.size(); j++) {
			if(fraza.at(0)==s.at(j)) {
				std::string k=s.substr(j,fraza.size());
				if(j!=0) {
					if((k==fraza && j+fraza.size()==s.size() && znak(s.at(j-1))) || (j+fraza.size()!=s.size() && k==fraza && znak(s.at(j+fraza.size())) && znak(s.at(j-1)))) {

						k=IzvrniString(k);
						s.insert(j+fraza.size(),k);
						if(j+(fraza.size()*2)>s.size()) j=j+(fraza.size()*2) -1;
						else{
						j=j+(fraza.size()*2);
						}
					}

				} else if(j==0){
					if((k==fraza && j+fraza.size()==s.size()) || (j+fraza.size()!=s.size() &&  k==fraza && znak(s.at(j+fraza.size())))){

						k=IzvrniString(k);
						s.insert(j+fraza.size(),k);
						if(j+(fraza.size()*2)>s.size()) j=j+(fraza.size()*2) -1;
						else{
						j=j+(fraza.size()*2);
						}
					}

				}
			}
		}


	}

	return s;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> vs)
{
	if(s.size()==0) return s;
	if(vs.size()==0) return s;

	if(s.size()==0) return s;

	for(int i=0; i<vs.size(); i++) {
		std::string fraza= vs.at(i);
		//std::cout<<fraza<<std::endl;
		for(int j=0; j<=int(s.size())-fraza.size(); j++) {
			if(fraza.size()%2==0 && fraza.at(0)==s.at(j)) {
				std::string pods=s.substr(j,fraza.size());
				if(j!=0) {
					if((pods==fraza && j+fraza.size()==s.size() && znak(s.at(j-1))) || (j+fraza.size()!=s.size() && pods==fraza && znak(s.at(j+fraza.size())) && znak(s.at(j-1)))){
					//if(pods==fraza && znak(s.at(j+fraza.size())) && znak(s.at(j-1)) || (pods==fraza && j+fraza.size()==s.size())) 
						int a=j, k;
						j+=fraza.size()/2;
						k=j-1;

						while((a+fraza.size())>j) {
							s.at(j)=s.at(k);
							j++;
							k--;
						}
						
					}
				} else {
					if((pods==fraza && j+fraza.size()==s.size()) || (j+fraza.size()!=s.size() && pods==fraza && znak(s.at(j+fraza.size()))) && j+fraza.size()){
				//	if(pods==fraza && znak(s.at(j+fraza.size())) || (pods==fraza && j+fraza.size()==s.size())) 
						int a=j, k;
						j+=fraza.size()/2;
						k=j-1;

						while((a+fraza.size())>j) {
							s.at(j)=s.at(k);
							j++;
							k--;
						}
						

					}
				}


			}

			if(fraza.size()%2!=0 && fraza.at(0)==s.at(j)) {
				std::string pods=s.substr(j,fraza.size());
				if(j!=0) {
					if((pods==fraza && j+fraza.size()==s.size() && znak(s.at(j-1))) || (j+fraza.size()!=s.size() && pods==fraza && znak(s.at(j+fraza.size())) && znak(s.at(j-1)))){
				//	if(pods==fraza && znak(s.at(j+fraza.size())) && znak(s.at(j-1)) || (pods==fraza && j+fraza.size()==s.size())) 
						int a=j, k;
						j=j+(fraza.size()/2)+1;
						k=j-2;
						
						while((a+fraza.size())>j) {
							s.at(j)=s.at(k);
							j++;
							k--;
						}
						

					}
				} else {
					if((pods==fraza && j+fraza.size()==s.size()) || (j+fraza.size()!=s.size() && pods==fraza && znak(s.at(j+fraza.size())))){
				//	if(pods==fraza && znak(s.at(j+fraza.size())) || (pods==fraza && j+fraza.size()==s.size())) 
						int a=j, k;
						j=j+(fraza.size()/2)+1;
						k=j-2;
						
						while((a+fraza.size())>j) {
							s.at(j)=s.at(k);
							j++;
							k--;
						}
						

					}
				}


			}




		}
	}


	return s;
}


int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string rec, pom;
	std::getline(std::cin,rec);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fra;
//	std::cin.ignore(1000, '\n');

	while(1) {
		std::getline(std::cin,pom);
		if(std::cin.peek()!='\n') fra.push_back(pom);
		else break;
	}
	fra.push_back(pom);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::string p(NapraviPalindrom(rec,fra));
	std::cout<<p;

	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::string pp(NapraviPoluPalindrom(rec, fra));
	std::cout<<pp;

	return 0;
}