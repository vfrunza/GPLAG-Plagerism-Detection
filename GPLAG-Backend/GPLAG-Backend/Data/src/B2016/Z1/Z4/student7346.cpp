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
using  namespace std;

string ObrniFraze(string recenica, vector<string> fraze){
	for(int i=0; i<fraze.size(); i++)
		for(int j=0; j<recenica.size(); j++)
			if(recenica.substr(j, fraze[i].size())==fraze[i]){
				int n=j+fraze[i].size()-1; int m=j;
				while(m<n){
					char pom=recenica[m];
					recenica[m]=recenica[n];
					recenica[n]=pom;
					m++; n--;
				}
			}
	return recenica;
}

string Pretvori_Rijec_U_Pig(string s){
	string m;
	for(int k=1; k<s.size(); k++)
	    m=m+s[k];
	m=m+s[0];
	m=m+"a";
	m=m+"y";
	return m;
}

string IzmijeniUPigLatin(string recenica, vector<string> fraze){
	for(int i=0; i<fraze.size(); i++)
	    for(int j=0; j<fraze[i].size(); j++)
	        if(fraze[i][j]<'A' || fraze[i][j]>'z' || (fraze[i][j]>'Z' && fraze[i][j]<'a'))
               throw domain_error("Nekorektan izbor rijeci\n");

	for(int m=0; m<fraze.size(); m++)
	    for(int n=1; n<recenica.size(); n++)
	        if((recenica[n-1]==' ' || n==1) && recenica.substr(n, fraze[m].size()) == fraze[m]){
	           int duzina=fraze[m].size();
	           int duzina1=recenica.size();
	           recenica=recenica.substr(0,n)+Pretvori_Rijec_U_Pig(fraze[m])+recenica.substr(n+duzina, duzina1-n);
	        }
	return recenica;
}

int main (){
	cout<<"Unesite recenicu: ";
	string recenica;
	getline(cin, recenica);
	cout<<"Unesite fraze: ";
	vector<string> fraze;
	for(;;){
		string fraze1;
		getline(cin, fraze1);
		if(fraze1.size()==0)
		   break;
		fraze.push_back(fraze1);
	}
	vector<string> fraze2;
	fraze2=fraze;
	if(fraze.size()==0)
       fraze2.push_back(recenica);
	
	try{
	   string nova_rec;
	   nova_rec=IzmijeniUPigLatin(recenica, fraze2);
	   cout<<"Recenica nakon PigLatin transformacije: "<<nova_rec<<endl;
	} catch (domain_error nekorektno){
		cout<<"Izuzetak: "<<nekorektno.what();
	}
    cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze)<<endl;
	return 0;
}