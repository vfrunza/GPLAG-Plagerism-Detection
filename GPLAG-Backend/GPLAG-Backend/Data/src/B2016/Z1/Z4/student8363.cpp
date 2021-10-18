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

using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::string;       

typedef std::vector<string> vstring;

//vraca broj na kojem pocinje podstring
//ako ne postoji vraca -1
void izbrisichar(string &s,int poz){
	if(poz>s.size())return;
	else
	for (int i = poz; i < s.size(); i++) {
		if(i==s.size()-1){
			s.resize(s.size()-1);
			break;
		}
		s.at(i)= s.at(i+1);
	}
}
bool isalphabet(char a){
	return ((a<='Z' && a>='A') || (a>='a' && a<='z'));
}
int findfirstoccurence(string recenica, string rijec, bool citava_fraza = false){
	for (int i = 0; i < recenica.size(); i++) {
		if(recenica.at(i)==rijec.at(0)){
			bool jest = true;
			if(rijec.size()+i>recenica.size())jest=false;
			else
			for (int j = 0; j<rijec.size(); j++) {
				if(rijec.at(j)!=recenica.at(j+i))jest=false;
			}
			if (jest) {
				if(citava_fraza){
					if(i>0 && i<recenica.size()-rijec.size()){
						if(isalphabet(recenica.at(i-1)) || isalphabet(recenica.at(rijec.size()+i)))
							continue;
					}
					else if(i==0){
						if(rijec.size()<recenica.size())
						if(isalphabet(recenica.at(rijec.size())))
							continue;
					}
					else if(i==recenica.size()-1){
						if(isalphabet(recenica.at(i-1)))
							continue;
					}
				}
				return i;
			} 
			
		}
	}
	return -1;
}
bool palindrom(string s){
	bool jes = true;
	for (int i = 0; i < s.size(); i++) {
		if(s.at(i)!=s.at(s.size()-1-i))jes=false;
	}
	return jes;
}
string ObrniFraze(string recenica,vstring rijeci){
	for (auto e : rijeci) {
		if(palindrom(e))continue;
		int pos = findfirstoccurence(recenica,e);
		while (pos!=-1) {
			pos = findfirstoccurence(recenica,e);
			int c = 0;
			for (int i = pos; i < pos + e.size(); i++) {
				recenica.at(i)=e.at(e.size()-1-c);
				c++;
			}
		}
	}
	return recenica;
}
void mojinsert(string &a, string b,int poz){
	string tmp;
	for (int i = 0; i < poz; i++) {
		tmp.push_back(a.at(i));
	}
	for (int i = 0; i < b.size(); i++) {
		tmp.push_back(b.at(i));
	}
	for (int i = poz; i < a.size(); i++) {
		tmp.push_back(a.at(i));
	}
	a=tmp;
}
string IzmijeniUPigLatin(string recenica,vstring spisakrijeci){
	string izlaz = recenica;
	int init_size=recenica.size();
	if(spisakrijeci.size()==0){
		int poz = 0;
		for (int i = 0; i < recenica.size(); i++) {
			bool pocetak_rijeci = false;
			if(i==0){
				if(isalphabet(recenica.at(i)))pocetak_rijeci=true;
			}
			else{
				if(isalphabet(recenica.at(i)) && !isalphabet(recenica.at(i-1)))pocetak_rijeci=true;
			}
			if(pocetak_rijeci){
				string tmp ;
				for (int j = i; j < recenica.size(); j++) {
					if(isalphabet(recenica.at(j)))tmp.push_back(recenica.at(j));
					else {
						spisakrijeci.push_back(tmp);
						break;
					}
					if(j==recenica.size()-1){
						spisakrijeci.push_back(tmp);
					}
				}
			}
		}
	}
	for (auto e : spisakrijeci) {
		for (int i = 0; i < e.size(); i++) {
			if(!((e.at(i)>='A' && e.at(i)<='Z') || (e.at(i)>='a' && e.at(i)<='z')))
			throw domain_error("Nekorektan izbor rijeci");
		}
	}
	for (auto e : spisakrijeci) {
		int i = findfirstoccurence(izlaz,e,true);
		while (i!=-1) {
				string vtmp;
				vtmp.push_back(e.at(0));
				mojinsert(izlaz,vtmp,i+e.size());
				mojinsert(izlaz,"ay",i+e.size()+1);
				izbrisichar(izlaz,i);
				init_size+=2;
				i=findfirstoccurence(izlaz,e,true);
	}}
	izlaz.resize(init_size);
	return izlaz;
}

int main (){
	string recenica ;
	vstring rijeci;
	cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica,'\n');
	cout<<"Unesite fraze: ";
	while (true) {
		string tmp;
		std::getline(std::cin,tmp,'\n');
		if(tmp.size()==0)break;
		rijeci.push_back(tmp);
	}
	try{
		cout<<"Recenica nakon PigLatin transformacije: "
			<<IzmijeniUPigLatin(recenica,rijeci)
			<<endl;
	}
	catch(std::domain_error d){
		cout<<"Izuzetak: "<<d.what()<<endl;
	}
	
	cout<<"Recenica nakon obrtanja fraza: "
		<<ObrniFraze(recenica,rijeci);
	return 0;
}