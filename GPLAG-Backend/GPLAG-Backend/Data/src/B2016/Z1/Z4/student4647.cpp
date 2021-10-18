
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using std::string;

string ObrniFraze(string recenica, std::vector<string> rijeci) {
	string s;
	int j;
	for( j=0; j<rijeci.size(); j++) {
		for(int i=0; i<recenica.length(); i++) {
			int k=0;
			while(recenica[i]==rijeci[j][k]) {
				i++;
				k++;
				if (i==recenica.length()) break;
			}
		if(k==rijeci[j].size()) 	{    //provjerava postoji li ta rijec u recenici
			string pomocni;
			pomocni.resize(k);
			i=i-k;
			for(int m=0; m<k; m++){
				pomocni[m]=recenica[i];
				i++;
			}
			i=i-k;
			for(int m=k-1; m>=0; m--){
				recenica[i]=pomocni[m];
				i++;
			}
			i--;
		}
		
		}
	}
	return recenica;
}

string pretvori(string s) {
	string s1=s;
	s.resize(s.size()+2);
	s[(s.size()-3)]=s1[0];
	int j=1;
	for(int i=0; i<s.size()-3; i++) {
		s[i]=s1[j];
		j++;
	}
	s[s.size()-2]='a';
	s[s.size()-1]='y';
	return s;
}

string IzmijeniUPigLatin (string recenica, std::vector<string> rijeci) {
	string novarecenica;
	string rec=recenica;
	for(int i=0; i<rijeci.size(); i++) {
		for(int j=0; j<rijeci[i].length(); j++)
		if(rijeci[i][j]<'A'|| (rijeci[i][j]>'Z' && rijeci[i][j]<'a') || rijeci[i][j]>'z') throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
	}
	if(rijeci.size()==0) {
		string v;
		int p=0;
		for(int i=0; i<recenica.length(); i++) {
			int j=i, h;
			v.resize(0);
			while(recenica[i]!=' ') {
				v.push_back(recenica[i]);
				i++;
				if(i==recenica.length()) break;
			}
			v=pretvori(v);
			recenica.resize(recenica.length()+2);
			for(int k=0; k<v.size(); k++) {	
				recenica[j]=v[k];
				j++;
				}
			p=p+2;
			for(h=j; h<recenica.length(); h++) {
				recenica[h]=rec[h-p];
				
			}
			i+=2;
			}
	}
	
	else {
		int j, i;
		for( j=0; j<rijeci.size(); j++) {
		for(i=0; i<recenica.length(); i++) {
			
			int k=0;
			while(recenica[i]==rijeci[j][k]) {
				i++;
				k++;
				if (i==recenica.length()) break;
			}
			int duzina_r=k;
			if (k==rijeci[j].length() && (recenica.length()==i || recenica[i]<'A' || (recenica[i]>'Z' && recenica[i]<'a') || recenica[i]>'z') && (recenica[i-k-1]<'A' || (recenica[i-k-1]>'Z' && recenica[i-k-1]<'a') || recenica[i-k-1]>'z' || (i-k)==0)) { //provjerava postoji li ta rijec u recenici
				string pomocni;
				pomocni.resize(k);
				int n=i-k;
				for(int m=0; m<k; m++){
					pomocni[m]=recenica[n];
					n++;
				}
				pomocni=pretvori(pomocni);
				n=n-k;
				recenica=recenica.substr(0, n)+pomocni+recenica.substr(n+duzina_r, recenica.size()-n);
	
					
			}
		}
		
		}
		
	}
	return recenica;
}

int main ()
{
	string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<string> rijeci;
	string o;
	std::cout<<"Unesite fraze: ";
	for(;;) {
		std::getline(std::cin, o);
		if(o.length()==0) break;
		rijeci.push_back(o); 
	}
	string s{ObrniFraze(recenica,rijeci)}; 
	try{
	string s1{IzmijeniUPigLatin(recenica, rijeci)};
	std::cout<<"Recenica nakon PigLatin transformacije: "<<s1<<std::endl;}
	catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<s;
	
	return 0;
}