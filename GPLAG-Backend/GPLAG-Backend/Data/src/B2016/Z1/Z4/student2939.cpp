/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::string string;
typedef std::vector<string> vektor;

string ObrniFraze(string s, vektor v){
	if(s.size()==0) return s;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.size(); j++){
			if(s.substr(j,v[i].size())==v[i]){
				for(int k=0; k<v[i].size()/2; k++){
					char c;
					c=std::move(s[j+k]);
					s[j+k]=std::move(s[j+v[i].size()-k-1]);
					s[j+v[i].size()-k-1]=std::move(c);
				}
			j=v[i].size();
			}
		}
	}
	return s;
}

string IzmijeniUPigLatin(string s, vektor v){
	if(s.size()==0) return s;
	if(v.size()==0){
		vektor v1(0);
		int a(0);
		for(int i=0; i<s.size(); i++){
			if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
				v1.resize(v1.size()+1);
			while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) {
				v1[a].push_back(s[i]);
				i++;
			}
			a++;
			}
		}
		for(int i=0; i<v1.size(); i++){
			for(int j=0; j<s.size(); j++){
				if(s.size()<v1[i].size()) return s;
				if(j==0 && (j+v1[i].size() <= s.size()) && s.substr(j,v1[i].size())==v1[i] && ((j+v1[i].size()==s.size()) || (!((s[j+v1[i].size()]>='A' && s[j+v1[i].size()]<='Z') || (s[j+v1[i].size()]>='a' && s[j+v1[i].size()]<='z'))))){
					string b(v1[i]);
						char c(v1[i][0]);
						b.erase(b.begin()+0);
						b= b + c + "ay";
						if(j==0) s= b + s.substr(v1[i].size(),s.size()-v1[i].size());
						else s=s.substr(0,j) + b + s.substr(j+v1[i].size(), s.size()-(j-1-v1[i].size()));
				j=v1[i].size()+2;
				}
				else if((j+v1[i].size() <= s.size()) && s.substr(j,v1[i].size())==v1[i] && (!((s[j-1]>='A' && s[j-1]<='Z') || (s[j-1]>='a' && s[j-1]<='z'))) && ((j+v1[i].size()==s.size()) || (!((s[j+v1[i].size()]>='A' && s[j+v1[i].size()]<='Z') || (s[j+v1[i].size()]>='a' && s[j+v1[i].size()]<='z'))))){
						string b(v1[i]);
						char c(v1[i][0]);
						b.erase(b.begin()+0);
						b= b + c + "ay";
						if(j==0) s= b + s.substr(v1[i].size(),s.size()-v1[i].size());
						else s=s.substr(0,j) + b + s.substr(j+v1[i].size(), s.size()-(j-1-v1[i].size()));
				j=v1[i].size()+2;
				}
			}
		}
	}
	else{
			for(int i=0; i<v.size(); i++){
					for(int j=0; j<v[i].size(); j++){
						if(!((v[i][j]>='A' && v[i][j]<='Z') || (v[i][j]>='a' && v[i][j]<='z'))) throw std::domain_error("Nekorektan izbor rijeci");
					}
				}
		for(int i=0; i<v.size(); i++){
			for(int j=0; j<s.size(); j++){
				if(v[i].size()>s.size()) return s;
				if(j==0 && (j+v[i].size() <= s.size()) && s.substr(j,v[i].size())==v[i] && ((j+v[i].size() == s.size()) || !((s[j+v[i].size()]>='A' && s[j+v[i].size()]<='Z') || (s[j+v[i].size()]>='a' && s[j+v[i].size()]<='z')))){
					string b(v[i]);
						char c(v[i][0]);
						b.erase(b.begin()+0);
						b= b + c + "ay";
						if(j==0) s= b + s.substr(v[i].size(),s.size()-v[i].size());
						else s=s.substr(0,j) + b + s.substr(j+v[i].size(), s.size()-(j-1-v[i].size()));
				j=v[i].size()+2;
				}
				else if((j+v[i].size() <= s.size()) && s.substr(j,v[i].size())==v[i] && (!((s[j-1]>='A' && s[j-1]<='Z') || (s[j-1]>='a' && s[j-1]<='z'))) && ((j+v[i].size()==s.size()) || (!((s[j+v[i].size()]>='A' && s[j+v[i].size()]<='Z') || (s[j+v[i].size()]>='a' && s[j+v[i].size()]<='z'))))){
						string a(v[i]);
						char c(v[i][0]);
						a.erase(a.begin()+0);
						a= a + c + "ay";
						if(j==0) s= a + s.substr(v[i].size(),s.size()-v[i].size());
						else s=s.substr(0,j) + a + s.substr(j+v[i].size(), s.size()-(j-1-v[i].size()));
				j=v[i].size()+2;
				}
			}
		}
		
			
		}
		return s;
}
int main ()
{
	std::cout<<"Unesite recenicu: ";
	string s;
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	vektor v;
	string x;
	for(;;){
		int c=std::cin.peek();
		if(c=='\n') break;
		std::getline(std::cin, x);
		v.push_back(x);
	}
	string a(ObrniFraze(s, v));
	try{
		string b(IzmijeniUPigLatin(s, v));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<b;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<a;
	
	return 0;
}