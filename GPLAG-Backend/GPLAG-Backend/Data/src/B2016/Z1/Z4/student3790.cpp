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

bool DaLiJeSlovo (char a){
	if((a>='A' && a<='Z') || (a>='a' && a<='z')) return 1;
	return 0;
}

string ObrniFraze (string recenica, vector<string> rijeci){
	if(!recenica.length()) return "";
	
	for(int i=0; i<rijeci.size(); i++){
		for(int j=0; j<recenica.length()-rijeci[i].length()+1; j++){
			if(rijeci[i]==recenica.substr(j,rijeci[i].length()) ){
				string rijec;
				rijec=recenica.substr(j,rijeci[i].length());
				for(int k=0; k<rijeci[i].length(); k++){
					recenica[j+k]=rijec[rijeci[i].length()-1-k];
				}
			}
		}
	}
	return recenica;
}

string IzmijeniUPigLatin (string recenica, vector<string> rijeci){
	if(!recenica.length()) return "";
	
	//izuzetak rijeci
	for(int i=0; i<rijeci.size(); i++){
		for(int j=0; j<rijeci[i].length(); j++){
			if((rijeci[i][j]>='A' && rijeci[i][j]<='Z') || (rijeci[i][j]>='a' && rijeci[i][j]<='z')) ;
			else throw domain_error ("Nekorektan izbor rijeci");
		}
	}
	
	//velicina 0, kreiranje stringa rijeci
	if(!rijeci.size()){
		for(int i=0; i<recenica.length(); i++){
			if(!DaLiJeSlovo(recenica[i])) continue;
			for(int j=0; j<recenica.length()-i; j++){
				if(DaLiJeSlovo(recenica[i+j])) continue;
				rijeci.push_back(recenica.substr(i,j));
				i+=j;
				break;
			}
		}
	}
	
	//piglatin
	for(int i=0; i<rijeci.size(); i++){
		for(int j=0; j<recenica.length()-rijeci[i].length()+1; j++){
			if(rijeci[i]==recenica.substr(j,rijeci[i].length()) && (j==0 || recenica[j-1]<'A' || (recenica[j-1]>'Z' && recenica[j-1]<'a') || recenica[j-1]>'z') && (j>recenica.length()-rijeci[i].length() || recenica[j+rijeci[i].length()]<'A' || (recenica[j+rijeci[i].length()]>'Z' && recenica[j+rijeci[i].length()]<'a') || recenica[j+rijeci[i].length()]>'z')){
				string rijec;
				rijec=recenica.substr(j+1,rijeci[i].length()-1)+recenica.substr(j,1)+"ay";
				recenica=recenica.substr(0,j)+rijec+recenica.substr(j+rijeci[i].length(),recenica.length()-j-rijeci[i].length());
				j++;
			}
		}
	}
	return recenica;
}


int main () {
	
	string recenica;
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	vector<string> rijeci;
	cout<<"Unesite fraze: ";
	for(;;){		
		string rijec;
		getline(cin,rijec);
		if(rijec.length()==0) break;
		rijeci.push_back(rijec);
	}
	
	string nova_recenica1;
	try{
		nova_recenica1=IzmijeniUPigLatin(recenica,rijeci);
		cout<<"Recenica nakon PigLatin transformacije: ";
		cout<<nova_recenica1<<endl;
	}
	catch(domain_error s){
		cout<<"Izuzetak: "<<s.what()<<endl;
	}
	
	string nova_recenica2(ObrniFraze(recenica,rijeci));
	cout<<"Recenica nakon obrtanja fraza: ";
	cout<<nova_recenica2<<endl;
	
	return 0;
}