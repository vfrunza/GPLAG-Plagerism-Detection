/*B 2017/2018, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<boost/algorithm/string/replace.hpp>
using namespace std;

string Obrnut(string b){
	string c=b;
	int n=b.length();
	for(int i=0;i<n/2;i++){
		swap(b.at(i),b.at(n-i-1));
	}
	return c+b;
}
string Poluobrnut(string b){
	string c=b;
	if(c.size()%2==1) b.resize(b.size()/2 + 1);
	else b.resize(b.size()/2);
    c.resize(c.size()/2);
	int n=b.length();
	for(int i=0;i<n/2;i++){
		swap(b.at(i),b.at(n-i-1));
	}
	return c+b;
}

    string NapraviPolindrom(string s,vector <string> v){
	for(string x:v){
	   boost::replace_all(s,x,Obrnut(x));
	}
	return s;
}

string NapraviPoluPalindrom(string s,vector <string> v){
	for(string x:v){
		boost::replace_all(s,x,Poluobrnut(x));
	}
	return s;
}



int main ()
{
    char temp[200];
    string recenica;
    cout<<"Unesite recenicu: ";
    cin.getline(temp,200,'\n');
    recenica=temp;
    vector <string> a;
    cout<<"Unesite fraze: ";
    char temp2[100];
    cin.getline(temp2,100,'\n');
    while(temp2[0]!='\0'){
    	a.push_back(temp2);
    	cin.getline(temp2,100,'\n');
    }
    cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPolindrom(recenica,a)<<endl;
    cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,a);
	return 0;
}