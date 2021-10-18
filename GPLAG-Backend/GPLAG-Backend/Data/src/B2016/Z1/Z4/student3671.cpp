#include <iostream>
#include <string>
#include <vector>

//using namespace std;
typedef std::vector<std::string> st;

void IzvrniRijec(std::string &rijec){
	int i(0), k(rijec.length()-1);
	while(i!=k){
		char p(rijec[i]);
		rijec[i]=rijec[k];
		rijec[k]=p;
		i++;
		k--;
	}
}
std::string IzmijeniUPigLatin(std::string recenica, st fraze){
	std::string s;
	
	std::cout<<fraze[0];
	int i(0), j(0), k(0), pok, z;
	while(i<fraze.size()){
		while((recenica[k]==' ' || recenica[k]!=fraze[i][j]) && (recenica[k]<recenica.size()))
			k++;
		
		while(k<recenica.size()){
			if(recenica[k]==fraze[i][j]){	
				z=k;
					while(k<recenica.size() && j<fraze[i].size() && recenica[k]==fraze[i][j]){
						k++;
						j++;
					}
				//IzvrniRijec(recenica.substr(z,brojac-z))
			}
			k++;
		}
		
		if(j==fraze[i].size()){
			pok=k;
			s = recenica.substr(z,k-z);
			IzvrniRijec(s);
			std::cout<<s;
		}
		j=0;
		k=0;
		i++;
	}
	
	return recenica;
}

int main ()
{
	st fraze{"Hosmo, hopica"};
	std::string recenica="   Hosmo hopica huhu", s;
	int i(0);
	s = IzmijeniUPigLatin(recenica,fraze);
	/*cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	cout<<"Unesite fraze: ";*/
	
	
	return 0;
}