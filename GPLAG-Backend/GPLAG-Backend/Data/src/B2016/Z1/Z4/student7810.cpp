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
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::domain_error;
using std::getline;

string IzmijeniUPigLatin(string s, vector<string> v){
	if (v.size()==0){
		int i(0);
		vector<string> rijeci;
		while (i<s.length()){
			if(!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z')){
				while(!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z'))
					i++;
			}
			vector<int> brojac;
			string rijec;
			if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
				while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
					brojac.push_back(i);
					rijec.push_back(s[i]);
					i++;
				}
			}
			rijeci.push_back(rijec);
			brojac.clear();
			rijec.clear();
		}
		
		i=0;
		while (i<s.length()){
		if(!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z')){
			while(!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z'))
				i++;
		}
		string rijec;
		vector<int> brojac;
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
			while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
				brojac.push_back(i);
				rijec.push_back(s[i]);
				i++;
			}
			for(int j=0;j<rijeci.size();j++){
				if(rijec==rijeci[j]){
					s.resize(s.length()+2);
					for(int k=s.length()-3;k>(brojac.size()+brojac.at(0));k--){
						s.at(k+2)=s.at(k);
					}
					char temp;
					temp=s[brojac.at(0)];
					for(int z=brojac.at(0)+1;z<(brojac.size()+brojac.at(0));z++){
						s.at(z-1)=s.at(z);
					}
					s[brojac.size()+brojac.at(0)-1]=temp;
					s[brojac.size()+brojac.at(0)]='a';
					s[brojac.size()+brojac.at(0)+1]='y';
					s[brojac.size()+brojac.at(0)+2]=' ';
				}
			}
		}
		brojac.clear();
		rijec.clear();
		i++;
	}
	return s;
	}
	else{
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].length();j++){
				if(!(v[i][j]>='A' && v[i][j]<='Z') && !(v[i][j]>='a' && v[i][j]<='z'))
				throw domain_error ("Nekorektan izbor rijeci");
			}
		}
	int i(0);
	while (i<s.length()){
		if(!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z')){
			while(!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z'))
				i++;
		}
		string rijec;
		vector<int> brojac;
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
			while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
				brojac.push_back(i);
				rijec.push_back(s[i]);
				i++;
			}
			for(int j=0;j<v.size();j++){
				if(rijec==v[j]){
					s.resize(s.length()+2);
					for(int k=s.length()-3;k>(brojac.size()+brojac.at(0));k--){
						s.at(k+2)=s.at(k);
					}
						char temp;
						temp=s[brojac.at(0)];
						for(int z=brojac.at(0)+1;z<(brojac.size()+brojac.at(0));z++){
							s.at(z-1)=s.at(z);
						}
						s[brojac.size()+brojac.at(0)-1]=temp;
						s[brojac.size()+brojac.at(0)]='a';
						s[brojac.size()+brojac.at(0)+1]='y';
						s[brojac.size()+brojac.at(0)+2]=' ';
				}
			}
		}
		brojac.clear();
		rijec.clear();
		i++;
	}
	return s;
	}
}
string ObrniFraze (string s, vector<string> v){
	for (int i=0;i<v.size();i++){
		for(int j=0;j<s.length();j++){
			if(v[i][0]==s[j]){
				int k(0);
				vector<int> brojac;
				while (v[i][k]==s[j] && k<v[i].length() && j<s.length()){
					brojac.push_back(j);
					k++;
					j++;
				}
				if (k==v[i].length()){
					int p(1);
					for(int q=brojac.at(0); q<(brojac.size()/2+brojac.at(0));q++){
						char temp;
						temp=s[q];
						s[q]=s[brojac.size()+brojac.at(0)-p];
						s[brojac.size()+brojac.at(0)-p]=temp;
						p++;
					}
				}
			}
		}
	}
	return s;
}

int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	getline(cin, recenica);
	cout<<"Unesite fraze: ";
	vector<string> fraze;
	while(1){
		string s;
		getline(cin, s);
		if (s=="") break;
		fraze.push_back(s);
	}
	try{
	string piglatin;
	piglatin=IzmijeniUPigLatin(recenica, fraze);
	cout<<"Recenica nakon PigLatin transformacije: ";
	cout<<piglatin<<endl;
	cout<<"Recenica nakon obrtanja fraza: ";
	recenica=ObrniFraze(recenica,fraze);
	for(char c : recenica) cout<<c;
	}
	catch(domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
		cout<<"Recenica nakon obrtanja fraza: ";
		recenica=ObrniFraze(recenica,fraze);
		for(char c : recenica) cout<<c;
	}
	return 0;
}