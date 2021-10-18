/*B 2016/2017, Zadaća 1, Zadatak 4
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
*/
#include<iostream>
#include<vector>
using std::cout;
using std::vector;
using std::cin;
using std::string;
using std::getline;

int NajduzaRijec(string s){
	int n(0),max(0);
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			n++;
			if(n>max)max=n;
		}
		else
		n=0;
	}
	return max;
}

vector<string> RazloziRecenicu(string s){
	int n(NajduzaRijec(s));
	vector<char> v1;
	v1.resize(n);
	vector<string> a(0);
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			v1.push_back(s[i]);
		}
		else{
			a.resize(a.size()+1);
			a.push_back(str(v1));
		}
	}
	return a;
}

string ObrniFraze(string s,vector<string> v){
	vector<string> v1;
	return s;
}

int main ()
{
	string s("Izasla je prvazadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta");
	vector<string> v(3);
	v[0]="Tehnike programiranja";
	v[1]="drugih predmeta";
	v[2]="meso od sira";
	cout<<"Unesite recenicu: ";
/*	getline(cin,s);
	cout<<s;
	cout<<"\nUnesite fraze: ";
	do{
		cin>>s;
		std::erase(s.size()-1);
		cout<<s;
		}while(s!="\n");*/
		
	
	return 0;
}