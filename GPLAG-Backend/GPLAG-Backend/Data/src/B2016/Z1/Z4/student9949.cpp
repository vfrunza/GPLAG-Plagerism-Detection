/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
bool sengPIG(string s){
	for(int i=0; i<s.length(); i++){
		if(s[i]<'A'|| (s[i]>'Z' && s[i]<'a') || s[i]>'z') return false;
	}
	return true;
}
bool Eng(vector<string> s){
	for(int i=0; i<s.size(); i++){
		if(!sengPIG(s[i])) return false;
		}
	return true;
}
bool sengFRAZE(string s){
	for(int i=0; i<s.length(); i++){
		if((s[i]<'A'|| (s[i]>'Z' && s[i]<'a') || s[i]>'z') && s[i]!=' ' && s[i]!=',') return false;
	}
	return true;
}
bool Eng1(vector<string>s){
	for(int i=0; i<s.size(); i++){
		if(!sengFRAZE(s[i])) return false;
		}
	return true;
}
/*string IzdvojiRijecFraze(string s, string d){
	string s1="";
	string s2="";
	if(d.length()>s.length()) return s1;
	if(s[0]==d[0]){
		s1=s.substr(0, d.length());
		if(s1==d) return s1;
		return s2;
	}
	else{
		bool a(Podstring(s,d));
		
	}
	return s1;
}*/

string IzdvojiRijec(string s){
	string s1="";
	int index1(0);
	int index2(0);
	for(int i=0; i<s.length(); i++){
		if((toupper(s[i])>='A' && toupper(s[i])<='Z') && (i==0|| s[i-1]==' '|| s[i-1]=='.'||s[i-1]==',')) index1=i;
		if(s[i]==' '||s[i]==','||s[i]=='.') {
			index2=i;
			s1=s.substr(index1, index2-index1);
		}
		if(i==s.length()-1){
			s1=s.substr(index1, s.length());
		}
		if(s1.size()!=0) break;
	}
	return s1;
}
bool IstaRijec(string s, string d){
	if(d.length()==s.length() && d==s) return true;
	for(int i=0; i<s.length(); i++){
		//if(i==0 && s[i]==' ') s.erase(0,1);
		if(s[i]==' ') s.erase(i,1);
	}
	for(int i=0; i<d.length(); i++){
		//if(i==0 && d[i]==' ') d.erase(0,1)
		if(d[i]==' ') d.erase(i,1);
		
	}
	if( d.length()<s.length() || d.length()>s.length()) return false;
	if(d==s) return true;
	return false;
	
}
/*bool Podstring(string s, string d){
	string s1;
	if(d.length()>=s.length()){
		bool a(IstaRijec(s,d));
		return a;
	} 
	else {
		for(int i=0; i<s.length(); i++){
			if(s[i]==d[0]){
				s1=s.substr(i, d.length());
			}
		}
		if(s1==d) return true;
	}
	return false;
}*/
string IzvrniRijec(string s){
	for(int i=0; i<s.length()/2; i++){
		char temp(s[i]);
		s[i]=s[s.length()-1-i];
		s[s.length()-1-i]=temp;
	}
	return s;
}
string Pig(string s){
	char a(s[0]);
	for(int i=0; i<s.length(); i++){
		if(i==0) {
			a=s[0];
			for(int j=1; j<s.length(); j++){
				s[j-1]=s[j];
			}
		}
		if(i==s.length()-1) s[i]=a;
	}
	s+="ay";
	return s;
}
string podstring(string s, string d){
	string novi="";
	string novistring="";
	for(int i=0; i<s.length(); i++){
		if(d[0]==s[i]) {
			novi=s.substr(i, d.length());
			if(novi==d){
				novi=IzvrniRijec(novi);
				novistring+=novi;
				//novistring+=" ";
				i+=d.length()-1;
			}
			else novistring+=s[i];
		}
		else novistring+=s[i];
	}
	return novistring;
}
string ObrniFraze(string s, vector<string> v){
	if(v.size()==0) return s;
	if(!Eng1(v)) throw std::domain_error ("Nekorektan izbor rijeci");
	string novi(s);
	for(int i=0; i<v.size(); i++){
		novi=podstring(novi,v[i]);
	}
	return novi;
	/*		int index1(0);
		string s2; 
		if((toupper(s[i])>='A'&& toupper(s[i])<='Z') && (i==0|| s[i-1]==' ')){
			string fraza;
			index1=i;
			string s1(s.substr(index1, s.length()-index1));
			for(int j=0; j<v.size(); j++){
				fraza=IzdvojiRijecFraze(s1, v[j]);
				if(fraza.length()!=0) {
					s1=IzvrniRijec(s1);
				}
				else {
					s1=IzdvojiRijec(s1);
				}
			}
			novi+=s1;
			novi+=" ";
		}
	}
	return novi;*/
}
string IzmijeniUPigLatin(string s, vector<string> v){
	string novi;
	if(v.size()==0){
		for(int i=0; i<s.length(); i++){
		int index;
		string s3;
		if((toupper(s[i]>='A') && toupper(s[i])<='Z')&& (i==0 || s[i-1]==' ')){
			index=i;
			string s4(s.substr(index, s.length()-index));
			s3=IzdvojiRijec(s4);
			s3=Pig(s3);
			novi+=s3;
			novi+=" ";
			}
		}
	return novi;
	}
	if(!Eng(v)) throw std::domain_error ("Nekorektan izbor rijeci");
	for(int i=0; i<s.length(); i++){
		int index1;
		string s2;
		if((toupper(s[i]>='A') && toupper(s[i])<='Z')&& (i==0 || s[i-1]==' ')){
			index1=i;
			string s1(s.substr(index1, s.length()-index1));
			s2=IzdvojiRijec(s1);
			for(int j=0; j<v.size(); j++){
				if(IstaRijec(s2, v[j])) s2=Pig(s2);
			}
			novi+=s2;
			novi+=" ";
		}
	}
	return novi;
}
int main ()
{
	std::cout<<"Unesite recenicu: ";
	string s;
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	vector<string> v;
	string s1;
	do{
		s1="";
		std::getline(std::cin, s1);
		if(s1.size()==0) break;
		v.push_back(s1);
	}while(s1.size()!=0);
	string pig;
	try{
		pig=IzmijeniUPigLatin(s, v);
		std::cout<<"Recenica nakon PigLatin transformacije: "<<pig<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<< std::endl;
	}

	string fraza;
	try{
		fraza=ObrniFraze(s,v);
		std::cout<<"Recenica nakon obrtanja fraza: "<<fraza;
	}
	catch(std::domain_error izuzetak1){
		std::cout<<"Izuzetak: "<<izuzetak1.what()<<std::endl;
	}
	
	
	return 0;
}