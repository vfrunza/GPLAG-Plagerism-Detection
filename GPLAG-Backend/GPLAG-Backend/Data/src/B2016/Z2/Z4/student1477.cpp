/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>



int PotencijalniKrivci (char **&znak, std::vector<std::string>v){
	int br(0);
	char **pok=nullptr;
	char **pok1;
	pok=new char *[v.size()];
	pok1=pok;
	for(int i=0; i<v.size(); i++) pok[i]=nullptr;
	try{
		for(int i=0; i<v.size(); i++){ pok[i]=new char(v[i].length()); br++;}
	}
	catch(...){
		for(int i=0; i<v.size(); i++) delete [] pok[i];
		delete pok;
		throw;
	}
/*	for(int i=0; i<v.size(); i++){
		int nul(0);
		for(int j=0; j<v[i].size(); j++){
		//	pok[i][j]=v[i][j];
			nul=j;
		}
	//	pok[i][v[i].size()]='\0';
	}*/
	znak=pok1;
	
	return br;
}
int OdbaciOptuzbu(char **&pok, int n, std::string s){
		int br(0);

for(int i=0; i<n; i++){
	for(int j=0; pok[i][j]!='\0'; j++){
		for(int k=0; k<s.length(); k++){
			if(pok[i][0]==s[0]){
				while(k<s.length() &&pok[i][j]==s[k]){
					j++;
					k++;
				}
				if(k==s.length()-1){
					pok[i][0]='\0';
					pok[i]=nullptr;
					br++;
				}
			}
			else break;
		
		}
		break;
	}
}


char **pok2=nullptr;
if(br>10){
	n=n-br;
	pok2=new char *[n];
	for(int i=0; i<n; i++) pok2[i]=nullptr;
	int br2(0);
	for(int i=0; i<n; i++){
		if(pok[i]!=nullptr){
		for(int j=0; pok[i][j]!='\0'; j++){
		while(pok[i][j]!='\0'){br2++; j++;}}
		try{
		for(int k=0; k<n; k++) pok2[i]=new char [br2-1];
		}
		catch(...){
			for(int i=0; i<n; i++) delete[] pok2[i];
			delete [] pok2;
		}
	
		
	}
	}
		pok=pok2;

	
	
}
return n;
}

int main ()
{

	return 0;
}