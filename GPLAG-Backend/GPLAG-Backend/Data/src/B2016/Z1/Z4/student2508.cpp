/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v)
{


	for(int i(0); i<v.size(); i++) {
		int j(0),len(s.size());
		while(j<len) {
			if(s[j]==v[i][0]) {
				int poc(j),duzina(0),k(0);
				bool jednaki(true);
				while(j<len && k<v[i].length()) {
					duzina++;
					if(s[j]!=v[i][k]) {
						jednaki=false;
						break;
					}

					j++;
					k++;

				}
				j--;
				std::string rijec(s.substr(poc,duzina));
				if(rijec!=v[i]) jednaki=false;
				if(jednaki) {

					std::string rijec(s.substr(poc,duzina));
					std::string obrnuti(rijec);
					for(int k(0); k<duzina/2; k++) {
						char pom(obrnuti[k]);
						obrnuti[k]=obrnuti[duzina-k-1];
						obrnuti[duzina-k-1]=pom;
					}
					int l(0);
					for(int k(poc); k<poc+duzina; k++) {
						s[k]=obrnuti[l];
						l++;
					}

				}
			j=poc;
			}
	
			j++;
		}
	}

	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{
	for(int i(0); i<v.size(); i++) {
		for(int j(0); j<v[i].length(); j++) {
			if((v[i][j]<'A' || v[i][j]>'Z')&&(v[i][j]<'a' || v[i][j]>'z'))
				throw std::domain_error("Nekorektan izbor rijeci");
		}
	}

	if(v.size()>0) {
		for(int i(0); i<v.size(); i++) {
			int j(0);
			bool razmak(true);
			while(j<s.length()) {
				if(!((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z'))) razmak=true;
				else if (razmak==true) {
					razmak=false;
					int poc(j),duzina(0);
					while(j<s.length() && ((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z')) ) {
						j++;
						duzina++;
					}
					j--;
					std::string rijec(s.substr(poc,duzina));
					char pom(s[poc]);
					if(rijec==v[i]) {
						if((poc+duzina)>=s.length()) {
							s.erase(s.begin()+poc);
							s.push_back(pom);
							s.push_back('a');
							s.push_back('y');
						} else {
							s.erase(s.begin()+poc);
							s.insert(s.begin()+poc+duzina-1,'y');
							s.insert(s.begin()+poc+duzina-1,'a');
							s.insert(s.begin()+poc+duzina-1,pom);
							j+=2;
						}
					}
				}

				j++;
			}
		}
	} else {
		int j(0);
		bool razmak(true);
		while(j<s.length()) {
			if(!((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z'))) razmak=true;
			else if (razmak==true) {
				razmak=false;
				int poc(j),duzina(0);
				while(j<s.length() && ((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z')) ) {
					j++;
					duzina++;
				}
				j--;
				char pom(s[poc]);
				if((poc+duzina)>=s.length()) {
					s.erase(s.begin()+poc);
					s.push_back(pom);
					s.push_back('a');
					s.push_back('y');
				} else {
					s.erase(s.begin()+poc);
					s.insert(s.begin()+poc+duzina-1,'y');
					s.insert(s.begin()+poc+duzina-1,'a');
					s.insert(s.begin()+poc+duzina-1,pom);
					j+=2;
				}
			}
			j++;
		}
	}

	return s;

}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string s,poms;
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	for(;;)
	{
		std::getline(std::cin,poms);
		if(poms.length()==0) break;
		else v.push_back(poms);
	}
	std::string s1,s2(ObrniFraze(s,v));
	try{
	s1=IzmijeniUPigLatin(s,v);
	std::cout<<"Recenica nakon PigLatin transformacije: "<< s1<<std::endl;
	}
		catch(std::domain_error izuzetak)
	{
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<< s2<<std::endl;
	return 0;
}