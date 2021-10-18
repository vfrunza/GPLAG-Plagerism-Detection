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
using std :: cin;
using std :: cout;
using std :: string;
typedef std ::vector<string> vektor;
string ObrniFraze (string s, vektor v){
	for (int i=0; i<v.size(); i++){
		for (int j=0; j<s.length(); j++){
			if(s.substr(j, v[i].length())== v.at(i)){
			
				for(int k=j; k<j+v[i].length(); k++){
					s[k]= v[i][v[i].length()-k+j-1];
				
				}
			}
		}
	}
	return s;
}

string IzmijeniUPigLatin ( string s, vektor v){
	for (int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].length(); j++){
			if ((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z'))
			 	continue;
			throw std :: domain_error ("Izuzetak: Nekorektan izbor rijeci");
			
		
		}
	}
	string s1;
	for (int j=0; j<s.length() ; j++){
		int br(0);
		while( ((s.at(j)>='a' && s.at(j)<='z') || (s.at(j)>='A' && s.at(j)<='Z') ) && j<s.length()){
			br++;
			if (j==s.length()-1) break;
			j++;
		}
	     int pocetak(j-br);
	     if (j==s.length()-1) pocetak++;
		bool izmjeni(false);
		if (v.size()==0) izmjeni=1;
		for (int i=0; i<v.size(); i++){
			if(s.substr(pocetak, br)==v[i]) 
				izmjeni=true;
		}
		if(izmjeni) 
			s1=s1 +s.substr(pocetak+1,br-1)+ s[pocetak]+ "ay";
		
		else s1= s1+ s.substr(pocetak, br+1);
		
		if(izmjeni && j!=s.length()-1)
		 s1= s1 + ' ';
		
	}
	s=s1;
	return s;
}

int main (){
 
 cout << "Unesite recenicu: ";
 string s;
 std :: getline(cin , s);
 cout << "Unesite fraze: ";
 vektor v;
 for( ; ; ){
 	string a;
 	std:: getline (cin, a);
 	if(a.length()==0) break;
 	v.push_back(a);
 }
 	try{
 string s1 ( IzmijeniUPigLatin(s,v));
 cout << "Recenica nakon PigLatin transformacije: ";
  cout << s1 << std :: endl;
 	}
 	catch (std:: domain_error){
 	cout << "Izuzetak: Nekorektan izbor rijeci"<< std ::endl;
 }
  cout << "Recenica nakon obrtanja fraza: ";
  string s2(ObrniFraze(s,v));
  cout << s2;
 
	return 0;
}