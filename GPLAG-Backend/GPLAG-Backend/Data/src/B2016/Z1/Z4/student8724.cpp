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

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::getline;

string Pomocnafija(string rijec, bool x){
	if(x){
		string obrnuta_rijec;
	for(int i=rijec.length()-1; i>=0; i--){
		obrnuta_rijec.push_back(rijec[i]);
	}
		obrnuta_rijec.push_back(' ');
		return obrnuta_rijec;
	}

	else{
		string pig_latin;
		for(int i(1); i<rijec.length();i++){
			pig_latin.push_back(rijec[i]);
		}
		pig_latin.push_back(rijec[0]);
		return pig_latin;
		
	}
	
}
string IzmijeniUPigLatin(string recenica, vector<string> rijeci){
		for(int i(0);i<rijeci.size();i++){
		string rijec=rijeci[i];
		for( int j=0;j<recenica.size();j++){
			
						if(recenica[j]==rijec[0]){
						int br1=0;
						int br2=j;
						//bool x=(isti(recenica, j, rijec));
						do{
							br1++;
							j++;
						}while(rijec.length()>br1 && recenica[j]==rijec[br1]);
						
						if(br1==rijec.length()){
							
							
							string pig_latin(Pomocnafija(rijec, false));
							int h=0;
							while(br1>h){
								recenica[br2]=pig_latin[h];
								br2++;
								h++;
							}
							
							recenica.insert(recenica.begin()+br2,'a');
							recenica.insert(recenica.begin()+br2+1, 'y');
							j=br2;
							
						}
					}
				}
			}
			return recenica;
}
/*
bool isti(string s, int pozicija, string l){
	int i(0);
	for(;;){
		if((s[pozicija])<'A' || (s[pozicija]>'Z' && s[pozicija]<'a') || s[pozicija]>'z'){
			break;
		}
		if(s[pozicija]!=l[i]) return false;
		
		pozicija++;
		i++;
	}
	return true;
}
*/
string ObrniFraze(string recenica, vector<string> rijeci){
			for(int i(0);i<rijeci.size();i++){
					string rijec=rijeci[i];
					for( int j=0;j<recenica.size();j++){
						if(recenica[j]==rijec[0]){
						int br1=0;
						int br2=j;
						do{
							br1++;
							j++;
						}while(rijec.length()>br1 && recenica[j]==rijec[br1]);
						
						if(br1==rijec.length()){
							string obrnuta_rijec(Pomocnafija(rijec, true));
							int h=0;
							while(br1+1>h){
								recenica[br2]=obrnuta_rijec[h];
								br2++;
								h++;
							}
							j=j-1;
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
	getline(cin, recenica);
	vector<string> rijeci;
	cout<<"Unesite fraze: ";
	while(1){
		string temp;
		getline(cin, temp);
		if(temp.length()!=0) rijeci.push_back(temp);
			
		else break;
		
	}
    string ObrnuteFraze(ObrniFraze(recenica, rijeci));
    string PigLatinovano(IzmijeniUPigLatin(recenica, rijeci));
	cout<<"Recenica nakon PigLatin transformacije: "<<PigLatinovano<<endl;
	cout<<"Recenica nakon obrtanja fraza: "<<ObrnuteFraze<<endl;
	return 0;
}