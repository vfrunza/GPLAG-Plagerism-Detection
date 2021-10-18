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

using namespace std;

string ObrniFraze(string recenica,vector<string> spisak)
{
	for(int i(0);i<spisak.size();i++){
		if(spisak[i].length()>0){
			int j(0);
			while(j<recenica.length()){
				while(j<recenica.length() && recenica[j]!=spisak[i][0]) j++;
				int k(j+1);
				int brojac(1);
				while(k<recenica.length() && brojac<spisak[i].length()){
					if(recenica[k]!=spisak[i][brojac]) break;
					k++;
					brojac++;
				}
				int pamti(k);
				if(brojac==spisak[i].length()){
					while(j<k){
						recenica[j]=spisak[i][brojac-1];
						brojac--;
						j++;
					}
				}
				j=pamti;
			}
		}
	}
	return recenica;
}

string IzmijeniUPigLatin(string recenica,vector<string> rijeci)
{
	string dodaj("ay");
//	bool mijenaj(false);
//	if(rijeci.size()==0) mijenaj=true;
	for(int i(0);i<rijeci.size();i++){
		for(int j(0);j<rijeci[i].size();j++){
			if((rijeci[i][j]<'a' && rijeci[i][j]>'Z')|| rijeci[i][j]<'A' || rijeci[i][j]>'z' ) throw domain_error("Nekorektan izbor rijeci");
		}
	}
	
	int j(0);
	while(j<recenica.length()){
		while(j<recenica.length() && recenica[j]==' ') j++;
		int k(j);
		while(k<recenica.length() && recenica[k]!=' ') k++;
		for(int i=0;i<rijeci.size();i++){
			if(recenica.substr(j,k-j)==rijeci[i]){
				recenica=recenica.substr(0,j)+recenica.substr(j+1,k-j-1)+recenica.substr(j,1)+dodaj+recenica.substr(k,recenica.length()-k);
				break;
			}
		}
		j=k;
	}
	return recenica;
}
	



int main()
{
	string recenica;
	string unos;
	vector<string>vektor;
	try{
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	cout<<"Unesite fraze: ";
	while(cin.peek()!='\n'){
		getline(cin,unos);
		vektor.push_back(unos);
	}
	
	cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,vektor);
	cout<<endl;
	cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,vektor);
	}
	catch(domain_error e){
		cout<<"Izuzetak: "<<e.what()<<endl;
		cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,vektor);
	}
	return 0;
}

