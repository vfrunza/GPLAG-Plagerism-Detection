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
#include <iomanip>
#include <vector>

bool ImaLiPraznika( std::string d){
	for(int i=0;i<d.length();i++)
	if(d.at(i)==' ') return true;
	return false;
}
std::string NapraviPalindrom(std::string a, std::vector<std::string> b){
	
	for(int i=0;i<b.size();i++){
		for(int j=0;j<a.size();j++){
			if(!ImaLiPraznika(b.at(i))){
			if(b.at(i)==a.substr(j,b.at(i).size()) && (a.at(j+b.at(i).size())==' '|| a.at(j+b.at(i).size())=='\0' )){
				for(int k=j;k<j+b.at(i).size();k++){
					a.insert(a.begin()+(j+b.at(i).size()),a.at(k));
				}
			}
		}
		if(ImaLiPraznika(b.at(i))){
			if(b.at(i)==a.substr(j,b.at(i).size())){
				for(int k=j;k<j+b.at(i).size();k++){
					a.insert(a.begin()+(j+b.at(i).size()),a.at(k));
				}
		}
		}
	}
	}
	return a;
}
std::string NapraviPoluPalindrom(std::string a, std::vector<std::string> b){
for(int i=0;i<b.size();i++){
		for(int j=0;j<a.size();j++){
			if(!ImaLiPraznika(b.at(i))){
			if(b.at(i)==a.substr(j,b.at(i).size()) && (a.at(j+b.at(i).size())==' '|| a.at(j+b.at(i).size())=='\0' )) {

				/*for(int k=j;k<j+b[i].size()/2;k++){
					a.insert(a.begin()+(j+b[i].size()/2),a[k]);
				}
				}*/
				if (b.at(i).size()%2==0){
					for(int k=j, l=j+(b.at(i).size()-1);k<j+b.at(i).size()/2 && l>=j+b.at(i).size()/2;k++, l--){
						a.at(l)=a.at(k);}
				}
				else	 if (b.at(i).size()%2!=0){
						for(int k=j, l=j+(b.at(i).size()-1);k<=j+b.at(i).size()/2 && l>j+b.at(i).size()/2;k++, l--)
						a.at(l)=a.at(k);
					
						
					}
					}
			}
			if(ImaLiPraznika(b.at(i))){
			if(b.at(i)==a.substr(j,b.at(i).size())) {

				if (b.at(i).size()%2==0){
					for(int k=j, l=j+(b.at(i).size()-1);k<j+b.at(i).size()/2 && l>=j+b.at(i).size()/2;k++, l--){
						a.at(l)=a.at(k);}
				}
				else	 if (b.at(i).size()%2!=0){
						for(int k=j, l=j+(b.at(i).size()-1);k<=j+b.at(i).size()/2 && l>j+b.at(i).size()/2;k++, l--)
						a.at(l)=a.at(k);
			
			}
			}
		}
		}
}
	return a;
}
int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	for(int i=0;;i++){
		if(std::cin.peek()=='\n')
		break;
		else {
			std::string fraza;
			std::getline(std::cin,fraza);
			fraze.push_back(fraza);
		}
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze)<<std::endl;

	
	return 0;
}