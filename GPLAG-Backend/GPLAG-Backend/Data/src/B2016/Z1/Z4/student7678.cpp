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

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string ObrniFraze(string s, vector<string> v){
	for(int i=0; i<v.size(); i++){
		string fraza = v[i];
		int j=0;
		for(int k=0; k<s.length(); k++){
			if(s[k]==fraza[j]){
				int m=k;
				int n=j;
				while(n<fraza.length()){
					if(s[m]==fraza[n]){m++; n++;}
					else break;
				}
				
				if(m-k==fraza.length()){
					for(int p=m-1; p>=k; p--){
						char tmp = s[k];
						s[k]=s[p];
						s[p]=tmp;
						k++;
					}
				}
			}
		}
	}
	
	return s;
}

string IzmijeniUPigLatin (string s, vector<string> v){
	
	if(v.size()==0){  //izmjena svih rijeci, ako je vektor 0
	
		for(int j=0; j<s.length(); j++){
			int m;
			if(s[j]<'A' || (s[j]>'Z' && s[j]<'a') || s[j]>'z')continue;
			else {
				
				m=j;
				
				while(m<s.size() && (s[m]>='A' && s[m]<='Z') || (s[m]>='a' && s[m]<='z'))m++;
				
				char tmp = s[j];
				char tmp2 = 'a';
				char tmp3 = 'y';
				
				s.insert(s.begin()+m, tmp);
				s.insert(s.begin()+m+1, tmp2);
				s.insert(s.begin()+m+2, tmp3);
				s.erase(s.begin()+j);
				
				m=m+2;
			}
			
			j=m;
			
			
		}
		
		return s;
	}
	
	for(int i=0; i<v.size(); i++){
		string fraza = v[i];
		for(int g=0; g<fraza.length(); g++){
			if(fraza[g]<'A' || fraza[g]>'Z' && fraza[g]<'a' || fraza[g]>'z')throw std::domain_error("Nekorektan izbor rijeci");
		}
		
		for(int j=0; j<s.length(); j++){
			
			if(s[j]<'A' || (s[j]>'Z' && s[j]<'a') || s[j]>'z')continue;
			else {
				
				int m = j;
				
				while(m<s.size() && (s[m]>='A' && s[m]<='Z') || (s[m]>='a' && s[m]<='z'))m++;
				
				int n = 0;
				if(s[j]==fraza[n]){
					int k = j;
					while(n<fraza.length()){
						if(s[k]==fraza[n]){n++; k++;}
						else break;
					}
					
					
					if(fraza.length()==m-j && s.substr(j,fraza.length())==fraza){
						
						char tmp = s[j];
						char tmp2 = 'a';
						char tmp3 = 'y';
						
						s.insert(s.begin()+m, tmp);
						s.insert(s.begin()+m+1, tmp2);
						s.insert(s.begin()+m+2, tmp3);
						s.erase(s.begin()+j);
					}
				}
				else j=m;
			}
		}
		
		
	
}
return s;
}
int main ()
{
	string s;
	string fraza,novi,novi1;
	vector<string> v;
	
	cout<<"Unesite recenicu: ";
	getline(cin,s);
	
	cout<<"Unesite fraze: ";
	while(getline(cin,fraza)){
		
		if(fraza.length()==0)break;//getline ucitava u string do /n, dva entera-string prazan
		v.push_back(fraza);
	}
	try{
		
		novi=IzmijeniUPigLatin(s,v);
		cout<<"Recenica nakon PigLatin transformacije: ";
		cout<<novi;
	}
	catch(std::domain_error izuzetak){
		std::cout <<"Izuzetak: "<< izuzetak.what();
	}
	
	cout<<endl;
	
	cout<<"Recenica nakon obrtanja fraza: ";
	novi1=ObrniFraze(s,v);
	
	cout<<novi1;
	
	return 0;
}