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

string ObrniFraze(string s, vector<string> vec) {
	int i=0,k=0,l,w;
	char temp;
	
	for(int j=0;j<vec.size();j++) {
		i=0;
		while(i<s.length()){
			if(s[i]==vec[j][0]) {
				l=i;
				w=i;
				k=0;
				while(k<vec[j].length() && l<s.length() && s[l]==vec[j][k]) {
					k++; l++;
				}

				if(k==vec[j].length()) {
					
					 int lj=l-1;
					 i=l-1;
					while(lj>w) {
						temp=s[w];
						s[w]=s[lj];
						s[lj]=temp;
						w++; lj--;
					}
				}
			}
			i++;
		} 
	}
	return s;
}
string IzmijeniUPigLatin(string s, vector<string> vec) {
	int i=0,k=0,l,lj;
	char temp;
	for(int m(0);m<vec.size();m++) {
		for( int n(0);n<vec[m].length();n++) {
			
			if(vec[m][n]<'A' || vec[m][n]>'z' || (vec[m][n]>'Z' && vec[m][n]<'a')) throw domain_error ("Nekorektan izbor rijeci");
		}
	}
	if(vec.size()==0)  {
		int m(0),n(0);
		vec.resize(vec.size()+1);
		while(m<s.length()) {
			if(s[m]<'A' || s[m]>'z' || (s[m]>'Z' && s[m]<'a')) { vec.resize(vec.size()+1); n++; m++; }
			else {
				vec[n].push_back(s[m]);
				m++;
			}
		}
	}

	while(i<s.length()) {
		for(int j=0;j<vec.size();j++) {
			if(s[i]==vec[j][0]) {
				l=i; lj=i;
				k=0;
				while(k<vec[j].length() && lj<s.length() && s[lj]==vec[j][k]) {
					k++; lj++;
				}
				if((s[lj]<'A' || s[lj]>'z' || (s[lj]>'Z' && s[lj]<'a')) && k==vec[j].length() && ( l==0 || (s[l-1]<'A' || s[l-1]>'z' || (s[l-1]>'Z' && s[l-1]<'a')))) {
					
					temp=s[l];
					while(l!=lj) {
						s[l]=s[l+1];
						l++;
					}
					s[lj-1]=temp;
					s = s.substr(0,lj) + "ay" + s.substr(lj,s.length());
					}
				}
			}
			i++;
		}
	return s;
}
int main ()
{
	cout<< "Unesite recenicu: ";
	string s;
	getline(cin,s);
	cout<< "Unesite fraze: ";
	vector<string> v;
	string rijec;
	getline(cin,rijec);
	while(rijec != ""){
		v.push_back(rijec);
		getline(cin,rijec);
	}
	try {
	IzmijeniUPigLatin(s,v);
	cout<< "Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,v);
	}catch (domain_error izuzetak) { cout<<"Izuzetak: "<< izuzetak.what(); }
	
	cout<< "\nRecenica nakon obrtanja fraza: "<<ObrniFraze(s,v);
	
	return 0;
}