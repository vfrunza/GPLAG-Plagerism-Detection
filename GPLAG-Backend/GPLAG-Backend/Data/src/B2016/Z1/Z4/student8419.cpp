/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

template <typename T> std::string PretvoriUString (T x){
	std::ostringstream s; s<<x; return s.str();
}

int BrojRijeci(std::string s){
	int razmak(1), broj_rijeci(0);
	for(int i=0; i<s.length(); i++){
		if(s[i]==' '){
			razmak=1;
		}
		else if(razmak==1){
			razmak=0;
			broj_rijeci++;
		}
	}
	return broj_rijeci;
}

bool JeLiEngleski(std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].length(); j++){
			if(!(v[i][j]>64 && v[i][j]<91) && !(v[i][j]>96 && v[i][j]<123) ){
				return false;
			}
		}
	}
	return true;
}

std::string ObrniFraze(std::string s, std::vector<std::string> fraze){
//	int razmak=1;
	for(int i=0; i<fraze.size(); i++){
	//	razmak=1;
		for(int j=0; j<s.length(); j++){
	/*		if(s.at(j)==' '){
				razmak=1;
			}
			else if(razmak==1){
				razmak=0;   */
				if(fraze[i]==s.substr(j, fraze[i].size())  /*  && (!(s[j+fraze[i].size()]>96 && s[j+fraze[i].size()]<123) || j+fraze[i].size()==s.length())  */){
					/*obrni*/
					int brojac(0);
					for(int k=j; k<j+(fraze[i].size()/2); k++){
						int l=j+fraze[i].size()-1-brojac;
						brojac++;
						char c=s[k];
						s[k]=s[l];
						s[l]=c;
					}
				}
		//	}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> fraze){
	try{
		if(JeLiEngleski(fraze)==false) throw std::domain_error("Nekorektan izbor rijeci");
	if(fraze.size()!=0){
		for(int i=0; i<fraze.size(); i++){
			int razmak(1);
			for(int j=0; j<s.length(); j++){
				if(s.at(j)==' '){
					razmak=1;
				}
				else if(razmak==1){
					razmak=0; 
					if(fraze[i]==s.substr(j, fraze[i].size())  && (!(s[j+fraze[i].size()]>96 && s[j+fraze[i].size()]<123) || j+fraze[i].size()==s.length())){
						/*prebacivanje slova na kraj rijeci*/
						int k=j;
						int l=j+fraze[i].size()-1;
						std::string c=PretvoriUString(s[k]);
						s.erase(k,1);
						s.insert(l, c);
						/*dodavanje sloga na kraj rijeci*/
						s.insert(l+1, "ay");
					}
				}
			}
		}
	}
	
	else{
		int razmak(1), brojac(0);
		int broj_rijeci=BrojRijeci(s);
		for(int i=0; i<s.length(); i++){
			if(s[i]==' '){
				razmak=1;
			}
			else if(s[i]!=' '){
				razmak=0;
				int k=i;
				while(s[k]!=' ' && k<s.length() && ((s[k]>96 && s[k]<123) || (s[k]>64 && s[k]<91))) k++;
				k--;
				int j=i;
				std::string c=PretvoriUString(s[j]);
				s.erase(j,1);
				s.insert(k,c);
				s.insert(k+1, "ay");
				i+=k-i+2;
				while(s[i]!=' ' && i<s.length()) i++;
				brojac++;
				if(brojac==broj_rijeci) break;
			}
		}
	}  
	return s;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	s.resize(0);
	return s;
}



int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string rijec;
	do{
		std::getline(std::cin, rijec);
		if(rijec.length()!=0) fraze.push_back(rijec);
	}while(rijec.length()!=0);

	std::string s2=IzmijeniUPigLatin(s, fraze);
	if(s2.length()!=0){
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<s2<<std::endl; }
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string obrnuti=ObrniFraze(s, fraze);
	std::cout<<obrnuti<<std::endl;

	
	return 0;
}