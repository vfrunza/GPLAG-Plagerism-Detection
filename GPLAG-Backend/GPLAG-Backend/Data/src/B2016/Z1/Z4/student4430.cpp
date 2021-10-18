/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

string ObrniFraze(string s, vector<string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			if((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z') || v[i][j]==' ') continue; 
			else throw domain_error ("Izuzetak: Nekorektan izbor rijeci");
		}
	}
	
	for(int i=0; i<v.size(); i++){						// petlja za fraze
		string pomocni=v[i]; 							// jedna rijec i fraza 
		
		for(int j=0; j<s.length(); j++){				// petlja za string
			int k=0; 
			int pocetak=j;
			if(pomocni[k]==s[j]){						// ako se podudaraju slova fraze i stringa
				while(pomocni[k]==s[j]){				// prozlazi kroz frazu i kroz string dok ne dodje do kraja fraze
					j++; 									// povecava indexe
					k++; 
					if(j==s.length()) break;
					if(k==pomocni.size()) break; 
				}
				if(pomocni.size()==k){	
					
					string obrnuto;
					for(int l=pomocni.size()-1; l>=0; l--){
						 obrnuto.push_back(pomocni[l]); 
					}
					string prvi_dio=s.substr(0, pocetak); 
					string drugi_dio=s.substr(pocetak+pomocni.size(), s.size()-prvi_dio.size()-obrnuto.size());
					s=prvi_dio+obrnuto+drugi_dio; 
				}
			}
		}
	}
	return s; 
}
	
string IzmijeniUPigLatin(string s, vector<string> v){
	
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			if((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z')) continue; 
			else throw domain_error ("Izuzetak: Nekorektan izbor rijeci");
		}
	}

	for(int i=0; i<v.size(); i++){
		string pomocni=v[i]; 
		for(int j=0; j<s.length(); j++){
			int k=0; 
			int pocetak=j; 
			if(pomocni[k]==s[j] && s[j-1]==' '){
			while(pomocni[k]==s[j]){
				j++; 
				k++;
				if(j==s.length())
					break; 
				if(k==pomocni.size())
					break; 
			}
			if(pomocni.size()==k){ 
		
			char prvo_slovo=pomocni[0]; 
			int duzina=pomocni.size(); 
			pomocni.erase(pomocni.begin());
			pomocni.push_back(prvo_slovo); 
			string dodatak="ay"; 
			pomocni=pomocni+dodatak; 
			string prvi_dio=s.substr(0, pocetak);
			string drugi_dio=s.substr(pocetak+duzina, s.size()-prvi_dio.size()-duzina);
			s=prvi_dio+pomocni+drugi_dio;
			}
			}	
		
	}
	}
	
	return s;  
}
	
int main ()
{
	string recenica, unos; 
	vector <string> fraze; 
	cout << "Unesite recenicu: "; 
	getline(cin, recenica); 
	cout << "Unesite fraze: "; 
	for(int i=0; ;i++){
		getline(cin,unos);  
		fraze.push_back(unos); 
		if(cin.peek()=='\n')
		break; 
	}
	
	
	try{
	string svinja=IzmijeniUPigLatin(recenica, fraze); 
	cout << "Recenica nakon PigLatin transformacije: "; 
	cout << svinja; 
	}
	catch(domain_error poruka){
		cout << poruka.what(); 
	}
	cout << endl; 
	
	try{
	string obrni=ObrniFraze(recenica,fraze); 
	cout << "Recenica nakon obrtanja fraza: "; 
	cout << obrni; 
	}
	catch(domain_error poruka){
		cout << poruka.what(); 
	}
	
	
	
	
	
	return 0;
}