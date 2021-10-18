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

using namespace std;

bool ProvjeraStringaPig(vector<string> rijeci){
	for(int i = 0; i < rijeci.size(); i++){
		for(int j = 0; j < rijeci[i].size(); j++){
			
			if(rijeci[i][j] < 'A' || (rijeci[i][j] > 'Z' && rijeci[i][j] < 'a') || rijeci[i][j] > 'z' ) return false;
		}
	}
	return true;
}
bool ProvjeraStringaObrnute(vector<string> rijeci){
	for(int i = 0; i < rijeci.size(); i++){
		for(int j = 0; j < rijeci[i].size(); j++){
			if(rijeci[i][j]==' ') continue;
			if(rijeci[i][j] < 'A' || (rijeci[i][j] > 'Z' && rijeci[i][j] < 'a') || rijeci[i][j] > 'z' ) return false;
		}
	}
	return true;
}

string IzmijeniUPigLatin(string recenica, vector<string> rijeci ){
	if(ProvjeraStringaPig(rijeci)==false){
		throw(domain_error("Nekorektan izbor rijeci!\n"));
	}
	if(rijeci.size()==0){
		string pomocna;
		int br(0);
	for(int i = 0; i < recenica.size(); i++){
		if(recenica[i]==' ') {
			string prva;
			prva=recenica[i-br];
			pomocna=prva+"ay";
			recenica.erase(i-br,1);
			recenica.insert(i-1,pomocna);
			br=0;
			i=i+2;
		}
		else if(i==recenica.size()-1){
			string prva;
			prva=recenica[i-br];
			pomocna=prva+"ay";
			recenica.erase(i-br,1);
			recenica.insert(i,pomocna);
			br=0;
			i=i+2;
		}
		else br++;
	}
	return recenica;
	}
	
	else{
		for(int i = 0 ; i < rijeci.size() ; i++) {
		int br(0);
			for(int j = 0 ; j < recenica.size() ; j++ ){
				if(rijeci[i][0] == recenica[j]){
					int brj(1);
					br++;
					for(int k = j+1; k < recenica.size();k++){
						if(brj >= rijeci[i].size()) break;
						if(rijeci[i][brj] != recenica[k]) { br=0; break;}
						br++;
						brj++;
					}
					if(br == rijeci[i].size()){
						string pomocna;
						for(int m = j ;m < j+br ;m++ )
							pomocna.push_back(recenica[m]);
						
							string prva;
				prva =pomocna[0];
			pomocna+=prva+"ay";
			pomocna.erase(0,1);
			recenica.insert(j+br,pomocna);
			recenica.erase(j,br);
			
							
						
						
						}
					}
				}
				
			}
				
	
		
	return recenica;
	}
		
}

																						
string ObrniFraze(string recenica, vector<string> rijeci){
	if(ProvjeraStringaObrnute(rijeci)==false){
		throw(domain_error("Nekorektan izbor rijeci!\n"));
	}
	for(int i = 0 ; i < rijeci.size() ; i++) {
		int br(0);
			for(int j = 0 ; j < recenica.size() ; j++ ){
				if(rijeci[i][0] == recenica[j]){
					int brj(1);
					br++;
					for(int k = j+1; k < recenica.size();k++){
						if(brj >= rijeci[i].size()) break;
						if(rijeci[i][brj] != recenica[k]) { br=0; break;}
						br++;
						brj++;
					}
					if(br == rijeci[i].size()){
						
						int p(0);
						for(int m = j ;m < j+br/2 ;m++ ){
							char temp(recenica[m]);
							recenica[m]=recenica[br+j-1-p];
							recenica[br+j-1-p]=temp;
							p++;
						}
					}
				}
				
			}
				
	}
	return recenica;
}


int main ()
{	
	string recenica;
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	vector<string> rijeci;
	cout<<"Unesite fraze: ";
	do{
		string pomocna;
		getline(cin , pomocna);
		if(pomocna.size() == 0) break;
		else 
		rijeci.push_back(pomocna); 
	}while(1);
	try{
	

	string pigi (IzmijeniUPigLatin (recenica,rijeci));
	
	cout<<"Recenica nakon PigLatin transformacije: "<< pigi<<endl;
	}
	catch(domain_error greska){
		cout<<greska.what();
	}
	try{
		string obrnute (ObrniFraze (recenica,rijeci));
		
		cout<<"Recenica nakon obrtanja fraza: "<<obrnute;
	}
	catch(domain_error greska){
		cout<<greska.what();
	}
	return 0;
}