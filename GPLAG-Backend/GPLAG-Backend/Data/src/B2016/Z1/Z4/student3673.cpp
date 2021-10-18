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

using namespace std;

string ObrniFraze(string s,vector<string>vs){
	for(int i=0;i<int(vs.size());i++){
		string pom(vs[i]);
		for(int j=0;j<int(s.length());j++){
			for(int k=0;k<int(pom.length());k++){
				if(pom[0]!=s[j])break;
				while(pom[k++]==s[j++]){
					if(k==int(pom.length())){
					    j--;
					    int pom1(j),pom2;
					    pom2=int(j-pom.length()+1);
						while(pom1>pom2){
						char temp(s[pom2]);
						s[pom2]=s[pom1];
						s[pom1]=temp;
							pom1--;pom2++;
						}
					}
				}
			}
		}
	}
		
	return s;
}

string IzmijeniUPigLatin(string s1,vector<string>vs1){
	vector<char>probni;
	vector<int>mjesta;
	if(vs1[0].length()==0){
		for(int i=0;i<int(s1.length());i++) {
			while(((s1[i]>='a' && s1[i]<='z') || (s1[i]>='A' && s1[i]<='Z')) && i<s1.length()) i++;
			/*if(i!=0 || i!=s1.length()-1){if (s1[i-1]!=' ' || s1[i+1]!=' ')*/mjesta.push_back(i);
		}
		for(int i=0;i<int(s1.length());i++){
			int pomoc(i);
			while(((s1[i]>='a' && s1[i]<='z')||(s1[i]>='A' && s1[i]<='Z')) && i<s1.length()){
				i++;
			}
			//if(i!=0 || i!=s1.length()-1){
			//if(s1[i-1]!=' ' || s1[i+1]!=' '){
			i--;
			//if(s1[i]!=' ' && s1[i+1]==' '){
			char slovo(s1[pomoc]);
			probni.push_back(slovo);
			s1.erase(s1.begin()+pomoc);
			
			
		}
		for(int i=0;i<mjesta.size();i++) {
		s1.insert(s1.begin()+mjesta[i]-1+2*i,probni[i]);
		s1.insert(s1.begin()+mjesta[i]+2*i,'y');
		s1.insert(s1.begin()+mjesta[i]+2*i,'a');
		}
		
	}
	else {
	for(int i=0;i<int(vs1.size());i++){
		string ss(vs1[i]);
		int greska(0);
		string alfabet{'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};
		for(int j=0;j<int(ss.length());j++){
			for(int k=0;k<int(alfabet.length());k++) {if (ss[j]==alfabet[k]) greska++;}
		}
		if(greska!=ss.length()) throw domain_error("Nekorektan izbor rijeci");
	}
	for(int i=0;i<int(vs1.size());i++){
		string help(vs1[i]);
		int duz(help.length());
		for(int j=0;j<int(s1.length());j++){
					if((s1.substr(j,duz)==help && s1[j]!=' ') && (((j!=0)&&((s1[j-1]==' ') || (s1[j-1]==',')) && ((s1[j+duz]==' ') || (s1[j+duz]==',') || (s1[j+duz]=='.'))) || (s1[0]==help[0] && (s1[j+duz]==' '|| s1[j+duz]==',' || s1[j+duz]=='.')) || ((j+duz)==s1.length() && (s1[j-1]==' ' || s1[j-1]=='.')))){
						char prvo_slovo(s1[j]);
						s1.erase(s1.begin()+j);
						s1.insert(s1.begin()+j+duz-1,prvo_slovo);
						s1.insert(s1.begin()+j+duz,'a');
						s1.insert(s1.begin()+j+duz+1,'y');
						//cout<<j<<endl;
					
					}
				 
			
		}
	
		
	}
}
	return s1;
}

int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	getline(cin,recenica);
	cout<<"Unesite fraze: ";
	
	vector<string>vektor;
	string unos;
	do {
	getline(cin,unos);
		vektor.push_back(unos);
	} while(!unos.empty());
	try {
	string promjena1;
	promjena1=IzmijeniUPigLatin(recenica,vektor);
	cout<<"Recenica nakon PigLatin transformacije: ";
	cout<<promjena1;
	}	
	
	catch(domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	
	cout<<endl<<"Recenica nakon obrtanja fraza: ";
	string promjena;
	promjena=ObrniFraze(recenica,vektor);
	cout<<promjena;
		
	return 0;
  
}