/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::getline;
using std::string;


string ObrniFraze (string recenica, vector <string> v ) {
	int p(0);
	for(int i=0; i<v.size(); i++) {
		p=0;
		for(int j=0; j<recenica.length(); j++) {
			int t,br(0);
			t=j;
			if( v[i][0]==recenica[j]) {
				p=0;
				while( p<v[i].length() && j<recenica.length() && v[i][p]==recenica[j] ) {
					if(p==v[i].length()) break;
					br++;
					j++;
					p++;
				}
				p--;
				int q;
				q=p;
				if(  br==v[i].length() ) {
				p=0;
				j=t;
				while(j<recenica.length() && p<v[i].length() && v[i][p]==recenica[j]) {
					recenica[j]=v[i][q];
					
					j++;
					p++;
					q--;
				}
			
				j=t;
				}
				j--;
			}
		
			
		}
	}

	return recenica;
}



string IzmijeniUPigLatin (string recenica, vector <string> v ) {
	for(int i=0; i<v.size(); i++) 
		for(int j=0; j<v[i].length(); j++)
			if(isalpha(v[i][j])==false) throw std::domain_error ("Nekorektan izbor rijeci");
	
	
	for(int i=0; i<v.size(); i++) { 
		int broji(0);
		for(int j=0; j<v[i].length(); j++)
			if(isalpha(v[i][j])==false) broji++;
			
		if(broji>0) throw std::domain_error ("Nekorektan izbor rijeci");
	
	}
	

	if(v.size()==0) {
		
		for(int i=0; i<recenica.length(); i++) { 
		
			if(isalpha(recenica[i]) ) {
				char tmp=recenica[i];
				int t=i+1;
				
				while(i<recenica.length() && t<recenica.length() && isalpha(recenica[t]))	{
					recenica[i]=recenica[t];
					i++; 
					t++;
				}
				recenica[i]=tmp;
				
				t--;
				int d;
				d=recenica.length()-t;
				
				recenica=recenica.substr(0,t+1)+"ay"+recenica.substr(t+1,d);
				
				i=i+3;
			}
		
		}
		
	}
	
	
	else {
	int p(0);
	for(int i=0; i<v.size(); i++) {
		p=0;
		for(int j=0; j<recenica.length(); j++) {
			int t,br(0);
			t=j;
			p=0;
			if( v[i][p]==recenica[j]) {
				while(p<v[i].length() && j<recenica.length() && v[i][p]==recenica[j] ) {
					if(p==v[i].length()) break;
					
					br++;
					j++;
					p++;
				}
			p--;
			
			if ( isalpha(recenica[j])==false && br==v[i].size() && (t==0 || isalpha(recenica[t-1])==false) ) {
				p=0; 
				while(p<v[i].length() && t<recenica.length() && p!=v[i].length()) {
					recenica[t]=v[i][p+1];
					t++;
					p++;
				}
				t--;
				recenica[t]=v[i][0];
				t++;
				int d;
				d=recenica.length()-t;
				recenica=recenica.substr(0,t)+string("ay")+recenica.substr(t,d);
				
				}
			}
			
		}
	}
	}

	return recenica;
}



int main ()
{
	
	cout<<"Unesite recenicu: ";
	string recenica,a;
	getline(cin,recenica);
	vector<string> v;
	
	cout<<"Unesite fraze: ";
	
	do {
		getline(cin,a);
		if(a.size()==0) break;
		v.push_back(a);
		
	} while(a.size()!=0);
	
	try {
		IzmijeniUPigLatin(recenica,v);
	cout<<"Recenica nakon PigLatin transformacije: ";
	cout<<IzmijeniUPigLatin(recenica, v);
	
	}
	catch (std::domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	
	cout<<endl;
	cout<<"Recenica nakon obrtanja fraza: ";
	cout<<ObrniFraze(recenica, v);
	
	
	return 0;
}


