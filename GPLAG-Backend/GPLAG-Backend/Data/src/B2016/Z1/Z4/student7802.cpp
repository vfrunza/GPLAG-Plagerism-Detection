/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/


#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>

typedef std::vector<std::string> SVector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

string DeObrni(string s){
	string h;
	for(int i(s.length()-1);i>=0;i--)
		h.push_back(s[i]);
	
	return h;
}

bool Provjeri(string rijeci, int n, string s){
	if(n>(s.length()-rijeci.length())) return false;
	string h;
	
	for(int j(0);j<rijeci.length();j++){
		h.push_back(s.at(n));
		n++;}
	
		if(rijeci==h) return true;
		else return false;
	
}

string BrOdFr (string rijeci, string s) {
	

	string h;
	string d;
	for(int i(0);i<s.length();i++){
	bool imal(Provjeri(rijeci, i, s));

	if(imal){
			
			d=DeObrni(rijeci);
			h+=d;
			i+=rijeci.length();
			i=i-1;
			if(i==s.length()) break;
			
		
	}else{
		h.push_back(s.at(i));
	
}
	if(i==s.length()) break;
		
	}

	
	return h;
}
string ObrniFraze(string s, SVector rijeci){
	string &h(s);
	

	
	for(int i(0);i<(rijeci.size());i++){
		int k(0);
		bool jel(false);
		
		while(k!=rijeci[i].length()){
			if((rijeci[i][k]>='A' && rijeci[i][k]<='Z')||(rijeci[i][k]>='a' && rijeci[i][k]<='z')){ jel=true;break;}
		}
		if(jel)
		h=(BrOdFr(rijeci[i],s));
		
		
	}
	
	return h;
}

bool Provjera(SVector rijeci){
	
	int br(0);
	
	for(int i(0);i<rijeci.size();i++){
		string m(rijeci[i]);
		for(int j(0);j<rijeci[i].length();j++){
			
			if(!((m[j]>='A' && m[j]<='Z')||(m[j]>='a' && m[j]<='z'))) br++;
			
		}
		if(br!=0) return true;
		
	}
	
	
	return false;
}



string Uzmi (string s){
	string h;
	for(int i(1);i<s.length();i++)
		h.push_back(s[i]);
	return h;
}

bool ProvjeraR(string s, SVector rijeci){
	
	
	for(int i(0);i<rijeci.size();i++)
		if(s==rijeci[i])return true;
	return false;
}



string IzmijeniUPigLatin(string s, SVector rijeci){
	if(rijeci.size()==0){
		
			string h;
	for(int i(0);i<s.size();i++){
		string k;
		int br(i);
		while((s[br]>='A' && s[br]<='Z')||(s[br]>='a' && s[br]<='z')){
			k.push_back(s[br]);
			br++;
			if(br==s.size()) break;
		}
		
			string d(Uzmi(k));
			for(int p(0);p<d.length();p++)
			h.push_back(d[p]);
			h.push_back(k[0]);
			h.push_back('a');
			h.push_back('y');
			h.push_back(s[br]);
			i=br;

		
		if(i==s.size()) break;
	}
	
	
	return h;
		
		
	}else{
	if(rijeci.size()==0 || bool(Provjera(rijeci)==true)) throw std::domain_error("Nekorektan izbor rijeci");
	string h;
	for(int i(0);i<s.size();i++){
		string k;
		int br(i);
		if(!((s[br]>='A' && s[br]<='Z')||(s[br]>='a' && s[br]<='z')))
			h.push_back(s[i]);
		else{
			
		while((s[br]>='A' && s[br]<='Z')||(s[br]>='a' && s[br]<='z')){
			k.push_back(s[br]);
			br++;
			if(br==s.size()) break;
		}
		if(ProvjeraR(k,rijeci)==true){
			string d(Uzmi(k));
			for(int p(0);p<d.length();p++)
			h.push_back(d[p]);
			h.push_back(k[0]);
			h.push_back('a');
			h.push_back('y');
			h.push_back(s[br]);
			i=br;
		}else{
			
			for(int l(0);l<k.size();l++){
				h.push_back(k[l]);
			
			i=br;
			}
			
			if(i==s.size()) break;
				h.push_back(s[i]);
		}
		}
		
		if(i==s.size()) break;
	}
	
	
	return h;
}}




int main ()
{
	cout<<"Unesite recenicu: ";
	string s;
	std::getline(std::cin,s);
	string s1;
	SVector rijeci;

	
	cout<<"Unesite fraze: ";
	cin>>std::ws;
	
	do{
		std::getline(std::cin,s1);
		
		rijeci.push_back(s1);

	
	}while(s1.length()!=0);
	try{
	string b(IzmijeniUPigLatin(s,rijeci));
	cout<<"Recenica nakon PigLatin transformacije: ";
	for(int i(0);i<b.size();i++){
		cout<<b[i];
	}
	}catch(std::domain_error izuzetak){
		cout<< "Izuzetak: " <<izuzetak.what()<<endl; 
	}
	string c(ObrniFraze(s,rijeci));
	
	cout<<"\nRecenica nakon obrtanja fraza: ";
	for(int i(0);i<c.length();i++){
		cout<<c[i];
	}


	return 0;
}
