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
using namespace std;
string ObrniFraze(string s, vector<string>c){
	for(int i=0; i<c.size(); i++){
		int j=0,k;
		while(j<s.length()){
		k=0;
		if(s[j]=='"'){ j++; continue;}
		if(c[i][k]==s[j]){
			int pocetak=j;
			string p=c[i];
			while(k!=c[i].length()){
				if(c[i][k]!=s[j]) break;
				k++;
				j++;
			}
			if(k==c[i].length()) {
			int kraj=j;
			for(int b=0; b<kraj-pocetak;b++) s.erase(s.begin()+pocetak);
			for(int b=0; b<p.length();b++) s.insert(s.begin()+pocetak,p[b]);
       }
	}
		j++;
}
	}
	return s;
}
string IzmijeniUPigLatin(string s, vector<string> c){
	for(int i=0;i<c.size();i++){
		int k=0;
		while(k!=c[i].length()){
			if((c[i][k]>='a' && c[i][k]<='z') || (c[i][k]>='A' && c[i][k]<='Z')) k++; 
			else break;
		}
		if(k!=c[i].length()) throw domain_error("Nekorektan izbor rijeci");
	}
	if(c.size()==0){
		for(int i=0; i<s.length();i++){
		 if(((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && (s[i-1]==' ' || i==0)){
		 	int pocetak=i;
		 	char p=s[i];
		 	while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) i++;
		 	int kraj=--i;
		 	s.erase(s.begin()+pocetak);
			s.insert(s.begin()+kraj,p);
			s.insert(s.begin()+kraj+1,'a');
			s.insert(s.begin()+kraj+2,'y');
		 }
		} 
	}
	else
	for(int i=0; i<c.size(); i++){
		int j=0,k=0;
		while(j<s.length()){
			if(s[j]=='"'){ j++; continue;}
			k=0;
		if(c[i][k]==s[j] && (s[j-1]==' ' || j==0 ||s[j-1]=='"' || s[j-1]==',' )) {
			int pocetak=j;
		    char p=s[j];
			while(k!=c[i].length()){
				if(c[i][k]!=s[j]) break;
				k++;
				j++;
			}
			if(k==c[i].length() && (s[j]==' ' || j==s.length()|| s[j]=='.'|| s[j]==',' || s[j]=='"') ) {
			int kraj=--j;
			s.erase(s.begin()+pocetak);
			s.insert(s.begin()+kraj,p);
			s.insert(s.begin()+kraj+1,'a');
			s.insert(s.begin()+kraj+2,'y');
       }
	}
		j++;
}
	}
	return s;
}
int main (){
string s;
cout<<"Unesite recenicu: ";
getline(cin,s);
vector<string>c;
string p;
cout<<"Unesite fraze: ";
do{
	getline(cin,p);
	if(p=="\0") break;
	c.push_back(p);
}while(1);
try{
cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,c)<<endl;
}
catch(domain_error izuzetak){
	cout<<"Izuzetak: "<<izuzetak.what()<<endl;
}
cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,c)<<endl;
	return 0;
}