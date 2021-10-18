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
#include <string>
#include <vector>

bool Postoji(std::string rijec_v, std::string rec, int pozicija_u_s)
{
	int k(0);
	if(pozicija_u_s+rijec_v.length()<=rec.length()){
	for(int i=pozicija_u_s; i<pozicija_u_s+rijec_v.length();i++){
		if(rijec_v.at(k)!=rec.at(i))
		return false;
		k++;
	}
		int broj=k+pozicija_u_s;
	if(broj<rec.length()&&(rec.at(k+pozicija_u_s)>='A'&&rec.at(k+pozicija_u_s)<='z'))
	return false;
	else if(broj<rec.length()&&rec.at(k+pozicija_u_s)==' '&&pozicija_u_s!=0&&rec.at(pozicija_u_s-1)>='A'&&rec.at(pozicija_u_s-1)<='z')
	return false;
	else if(broj>rec.length()-1&&pozicija_u_s!=0&&rec.at(pozicija_u_s-1)>='A'&&rec.at(pozicija_u_s-1)<='z')
	return false;
	if(broj>rec.length())
	return false;
	return true;}
	return false;
}
std::string okreni(std::string s){
	std::string s1;
	for(int i=s.length()-1; i>=0; i--){
		s1+=s.at(i);
	}
	return s1;
}

std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0;j<s.length();j++)
		{
			if(s.at(j)==v.at(i).at(0)&& Postoji(v.at(i),s,j)){
				std::string s1,s2,nr(okreni(v.at(i)));
				for(int k=0;k<s.length();k++)
				{
					if(k<j+v.at(i).length())
						s1+=s.at(k);
					else
						s2+=s.at(k);
				}
				s=s1+nr+s2;
				j=j+v.at(i).length()*2-1;
			}
		}
	}
	return s;
	
}

std::string okreni_pola(std::string s){
	int n(s.length()), duzina(0);
	duzina=n/2;
	std::string s1;
	std::string s2;
	for(int i=0; i<duzina; i++){
	s1+=s.at(i);
	s2+=s.at(i);}
	if(n%2!=0)
	s2+=s.at(n/2);
	for(int i=s1.length()-1; i>=0; i--)
	s2+=s1.at(i);
	return s2;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.length();j++){
			if(s.at(j)==v.at(i).at(0)&&Postoji(v.at(i),s,j)){
				std::string s1,s2,nr(okreni_pola(v.at(i)));
				for(int k=0; k<s.length(); k++){
					if(k<j)
					s1+=s.at(k);
					if(k>j+v.at(i).length()-1)
					s2+=s.at(k);
				}
				s=s1+nr+s2;
				j=j+v.at(i).length()-1;
			}
		}
	}
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::string recenica1(recenica);
	std::cout<<"Unesite fraze: ";
	std::string s;
	int n(0);
	std::vector<std::string>v;
	while(1){
		std::getline(std::cin, s);
		if(s.length()==0)
			n++;
		if(n==2)
			break;
		if(s.length()!=0)
			v.push_back(s);
	}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	recenica=NapraviPalindrom(recenica, v);
	std::cout<<recenica;
	recenica=std::move(recenica1);
	std::cout<<std::endl<<"Recenica nakon PoluPalindrom transformacije: ";
	recenica=NapraviPoluPalindrom(recenica, v);
	std::cout<<recenica;
	return 0;
}