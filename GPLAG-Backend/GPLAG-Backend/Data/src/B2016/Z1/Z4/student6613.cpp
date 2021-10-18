/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
std::string StringZaUbaciti(std::string s){
	std::string v;
	for(int i=s.length()-1; i>=0; i--)
		v.push_back(s[i]);

	return v;
}
std::string PigLatinStringZaUbaciti(std::string s){
	std::string v;
	for(int i=1; i<s.length(); i++)
		v.push_back(s[i]);
	v.push_back(s[0]);
	v+="ay";
	return v;
	
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string>v){
	int x(1);
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].length(); j++){
			if(v[i][j]<'A' || (v[i][j]>'Z' && v[i][j]<'a') || v[i][j]>'z') throw std::domain_error("Nekorektan izbor rijeci");
			if(v[i].size()!=0) x=0;
		}
	}
	if(v.size()==0) x=1;

	if(x){
			for(int j=0; j<s.length(); j++){
				
				if(s[j]<'A' || (s[j]>'Z' && s[j]<'a') || s[j]>'z') continue;
				int z(j);
				std::string f;
				for( ; ; ){
					if(z == s.size() || s[z]<'A' ||(s[z]>'Z' && s[z]<'a') || s[z]>'z') break;
					f.push_back(s[z]);
					z++;
				}
				std::string c=PigLatinStringZaUbaciti(f);
				s.resize(s.length()+2);
				for(int p=s.length()-3; p>=j; p--)
					s[p+2]=s[p];
				int h(0);
				for(int z=j; z<j+c.length(); z++){
					s[z]=c[h];
					h++;
				}
				j+=c.length();
				j--;
			}
			
	return s;
	}
	
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.length(); j++){
			
			if(s[j]==v[i][0]){
				bool r(0);
				int k;
				for(k=0; k<v[i].length(); k++){
					if(j+k>s.length()){
						r=1;
						break;
					}
					if(s[j+k]!=v[i][k]) r=1;
				}
				if(r) continue;
				if(r==0 && ((j!=0 && (s[j-1]<'A' || (s[j-1]>'Z' && s[j-1]<'a') || s[j-1]>'z') && (s[j+v[i].length()]<'A' ||(s[j+v[i].length()]>'Z' && s[j+v[i].length()]<'a') ||  s[j+v[i].length()]>'z')) || (j==0 && (s[j+v[i].length()]<'A' || (s[j+v[i].length()]>'Z' && s[j+v[i].length()]<'a') || s[j+v[i].length()]>'z'))) ){
				std::string t(PigLatinStringZaUbaciti(v[i]));
				s.resize(s.length()+2);
				for(int p=s.length()-3; p>=j; p--)
					s[p+2]=s[p];
				int h(0);
				for(int z=j; z<j+t.length(); z++){
					s[z]=t[h];
					h++;
				}
				j+=t.length();
				j--;
				}
			}
		}
	}
	return s;
}
std::string ObrniFraze(std::string s, std::vector<std::string>v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.length(); j++){
			if(s[j]==v[i][0]){
				bool r(0);
				for(int k=0; k<v[i].length(); k++){
					if(j+k>s.length()){
						r=1;
						break;
					}
					if(s[j+k]!=v[i][k]) r=1;
				}
				if(r) continue;
				std::string t(StringZaUbaciti(v[i]));
				int h(0);
				for(int z=j; z<j+v[i].length(); z++){
					s[z]=t[h];
					h++;
				}
			}
		}
	}
	return s;
}

int main ()
{
	cout<<"Unesite recenicu: ";
	std:: string s;
	std::getline(cin,s);
	std::vector<std::string>v;
	std::string d;
	
	cout<<"Unesite fraze: ";
	for( ; ; ){
		std::getline(cin,d);
		if(d.size()!=0) v.push_back(d);
		else break;
	}
	try{
	std::string x=IzmijeniUPigLatin(s,v);
	cout<<"Recenica nakon PigLatin transformacije: "<<x<<endl;
	}
	catch(std::domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v);
	return 0;
}
