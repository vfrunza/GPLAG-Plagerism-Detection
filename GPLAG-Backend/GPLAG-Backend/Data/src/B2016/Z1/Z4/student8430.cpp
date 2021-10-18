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

string pomocnaFunkcijaObrniFraze(string s, string fraza){
	
	for(int i = 0 ; i < s.length() ; i++){
		
		if(s[i] == fraza[0]){

			int pocetak = i;
			bool zamjeni = true;
			int k = i + 1;
			for(int j = 1 ; j < fraza.length() ; j++){
				if(fraza[j] != s[k]){
					zamjeni = false;
					break;
				}
				k++;
			}
			
			/*if(pocetak != 0){
				if(s[pocetak - 1] != ' '){
					zamjeni = false;
				}
			}
			if((s[k] >= 'A' && s[k] <= 'Z') || (s[k] >= 'a' && s[k] <= 'z')){
				zamjeni = false;
			}*/
			
			if(zamjeni == true){
				int kraj = pocetak + fraza.length() - 1;
				int brojac = 0;
				for(int b = pocetak ; b <= pocetak + (kraj - pocetak)/2 ; b++){
					char pomocna = s[b];
					s[b] = s[kraj - brojac];
					s[kraj - brojac] = pomocna;
					brojac++;
				}
				//i = kraj + 1;
				  i = pocetak;
			}
			
		}
		
	}
	
	return s;
}

string ObrniFraze(string s, vector<string> v){
	
	for(int i = 0 ; i < v.size() ; i++){
		s = pomocnaFunkcijaObrniFraze(s, v[i]);
	}
	
	return s;
}



vector<string> razdvojiRijeci(string s){
	vector<string> pom;
	
	s = "  " + s + "  ";
	int pocetak = 1; 
	for(int i = 1 ; i < s.length() - 1 ; i++){
		
		if(s[i] == '.'){
			s[i] = ' ';
		}
		
		if(s[i] == ' '){
			if(pocetak != i){
				pom.push_back(s.substr(pocetak , i - pocetak));
			}
			pocetak = i + 1; 
		}
		
	}
	
	return pom;
}

string pomocnaFunkcijaIzmijeniUPigLatin(string s, string fraza){
	
	for(int i = 0 ; i < s.length() ; i++){
		
		if(s[i] == fraza[0]){
				
			int pocetak = i;
			bool nadena = true;
			int k = i + 1;
			for(int j = 1 ; j < fraza.length() ; j++){
				if(fraza[j] != s[k]){
					nadena = false;
					break;
				}
				k++;
			}
			if(pocetak != 0){
				if(s[pocetak - 1] != ' '){
					nadena = false;
				}
			}
			if((s[k] >= 'A' && s[k] <= 'Z') || (s[k] >= 'a' && s[k] <= 'z')){
				nadena = false;
			}
			if(nadena == true){
				char pomocna = s[pocetak];
				for(int j = pocetak + 1 ; j < pocetak + fraza.length(); j++){
					s[j - 1] = s[j];
				} 
				s[pocetak + fraza.length() - 1] = pomocna;
				
				string s1 = s.substr(0,pocetak + fraza.length());
				string s2 = "ay";
				string s3 = s.substr(pocetak + fraza.length() , s.length() - 1);
				
				s = s1 + s2 + s3;
				
			}
			
		}
		
	}
	
	return s;
}

bool provjeriRijeci(vector<string> v){
	
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = 0 ; j < v[i].length() ; j++){
			if(!((v[i][j] >= 'A' && v[i][j] <= 'Z') || (v[i][j] >= 'a' && v[i][j] <= 'z'))){
				return false;
			}
		}
	}
	return true;
}

string IzmijeniUPigLatin(string s, vector<string> v){
	
	if(provjeriRijeci(v) == false){
		throw domain_error("Nekorektan izbor rijeci");
	}
	
	if(v.size() == 0){
		v = razdvojiRijeci(s);
	}
	
	for(int i = 0 ; i < v.size() ; i++){
		s = pomocnaFunkcijaIzmijeniUPigLatin(s,v[i]);
	}
	
	return s;	
}

int main ()
{
	
	cout << "Unesite recenicu: ";
	string recenica;
	getline(cin , recenica);
	cout << "Unesite fraze: ";
	vector<string> fraze;
	
	while(1){
		
		char pom = cin.get();
		if(pom == '\n'){
			break;
		}	
		string p;
		getline(cin , p);
		p = pom + p;
		fraze.push_back(p);
	}
	try{
		cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica , fraze) << endl;
	}
	catch(domain_error e){
		cout << "Izuzetak: " << e.what() << endl;
	}
	try{
		cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica , fraze) << endl;
	}
	catch(domain_error e){
		cout << e.what() << endl;
	}
  

	return 0;
}