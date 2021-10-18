/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string S, std::vector<std::string> v)
{
	std::string s(S);
	bool a=true;
	int d=-1;
	for(int k=0; k<v.size(); k++) {
		d=-1;
		int j=0;
		do {
			while(j<s.size() && v[k][0]!=s[j] && j!=0 && s[j-1]<'a' && s[j-1]>'z' && s[j-1]<'A' && s[j-1]>'Z') {
				j++;
			}
			if(d!=s.size()) d=j;
			a=true;
			for(int l=0; l<v[k].size(); l++) {
				if((((d+l)<=(s.size()-1)) && v[k][l]!=s[d+l]) || ((d+l)>(s.size()-1))) {
					a=false;
					break;
				}
			}
			int g=(v[k].size()-1);
			if(a && g<s.size() && d<s.size()) {
				for(int m=d ; m<d+v[k].size(); m++) {
					if(m<s.size()) {
						s[m]=v[k][g];
						g--;
					}
				}
				k--;
			} else j++;
		} while(a==false && j<s.size());
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string S, std::vector<std::string> v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v[i].size(); j++) {
			if((v[i][j]<'a' && v[i][j]>'Z') || v[i][j]<'A' || v[i][j]>'z') {
				throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
	}

	std::string s(S);
	bool a=true;
	int d=-1;
	int m(s.size());
	for(int k=0; k<v.size(); k++) {
		d=-1;
		int j=0;
		do {

			if(j>=s.size()) break;
			while(j<s.size() && v[k][0]!=s[j] ) {
				j++;
			}
			if(j!=s.size()) d=j;
			else break;

			a=true;

			for(int l=0; l<v[k].size(); l++) {
				if(((d+l+1)<=(s.size()-1)) && ((d+l)<=(s.size()-1)) &&(v[k][l]!=s[d+l] || (s[d+l+1]<'a' && s[d+l+1]>'z' && s[d+l+1]<'A' && s[d+l+1]>'Z') || (s[d-1]>'a' && s[d-1]<'z') || (s[d-1]>'A' && s[d-1]<'Z') /*s[d+l+1]!=' ' || s[d+l+1]!='.' || s[d+l+1]!=','*/)) {
					a=false;
					break;
				}
			}

			int g=(v[k].size()+d);

			//	std::cout<<"D je "<<d<<" a g je"<< g<<" a fraza je"<<" "<<v[k]<<"\n";
			if(j>=s.size())break;
			if(a && g<=s.size() && d<s.size()) {


				if(g<s.size() && d<s.size()) {
					s[g]=s[d];
					s.erase(s.begin()+d);
					g--;
					d--;
					s.insert(s.begin()+g+1, ' ');
					g++;
					d++;
					s.insert(s.begin()+g, 'a');
					g++;
					d++;
					s.insert(s.begin()+g, 'y');
					std::cout<<s<<" "<<j<<std::endl;
					j=g;
					if(j==m||j==(m+1)) break;
				}
				else if(g==s.size()) {
					s.resize(s.size()+2);
					s[g]=s[d];
					s.erase(s.begin()+d);
					g--;
					d--;
					s.insert(s.begin()+g+1, ' ');
					g++;
					d++;
					s.insert(s.begin()+g-1, 'a');
					g++;
					d++;
				s.insert(s.begin()+g, 'y');
					std::cout<<s<<" "<<j<<std::endl;
					j=g;
					if(j==m||j==(m+1)) break;
				}
			} else j++;
		} while(j<s.size());

	}

	return s;
}

int main ()
{

	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";

	std::vector<std::string> v(10000);
	std::string s;
	int i=0, duzinas=0;
	while(s[0]!='\n') {

		std::getline(std::cin, s);
		duzinas=s.size();
		if(duzinas==0) break;
		v[i]=s;
		i++;

	}

	try {
		std::string recenicapig;
		recenicapig=IzmijeniUPigLatin(recenica, v);
		std::cout<<"Recenica nakon PigLatin transformacije: "<<recenicapig<<"\n";
	} catch(std::domain_error greska) {
		std::cout<<"Izuzetak: "<<greska.what()<<std::endl;
	}
	recenica=ObrniFraze(recenica, v);
	std::cout<<"Recenica nakon obrtanja fraza: "<<recenica;
	return 0;
}