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
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::string>rijeci;
std::string ObrniFraze(std::string s1,rijeci s2)
{
	std::string s3=s1,obrni;
	for(int i=0; i<s2.size(); i++)  {
		obrni="";
		for(int k=s2[i].length()-1; k>=0; k--)
			obrni=obrni+s2[i][k];
		while(s3.find(s2[i])!=std::string::npos)
			s3.replace(s3.find(s2[i]),s2[i].length(),obrni);
	}
	return s3;
}
std::string IzmijeniUPigLatin(std::string s1,rijeci s2)
{
	std::string s4=s1,pig;
	std::string s3=s1;
	for(int i=0; i<s2.size(); i++)
		for(int j=0; j<s2[i].length(); j++)
			if(s2[i][j]<'A' || s2[i][j]>'Z' && s2[i][j]<'a' || s2[i][j]>'z')
           throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
	if(s2.size()==0) {
		s3=" "+s3+" ";
		int p=-1,k=-2;
		for(int i=0; i<s3.length()-1; i++) {
			if(s3[i]==' ' && s3[i+1]!=' ' ) p=i+1;
			if(s3[i]!=' ' && s3[i+1]==' ') k=i;
			if(p<=k) {
				pig="";
				for(int j=p; j<=k; j++)
					pig=pig+s3[j];
				s2.push_back(pig);
			}
		}
		for(int i=0; i<s3.length()-2; i++)
			s4[i]=s3[i+1];
	}
	for(int i=0; i<s2.size(); i++) {
		pig="";
		for(int k=1; k<s2[i].length(); k++) pig=pig+s2[i][k];
		pig=pig+s2[i][0];
		pig=pig+"ay";
		while(s4.find(" "+s2[i]+" ")!=std::string::npos)
		s4.replace(s4.find(" "+s2[i]+" "),s2[i].length()+2," "+pig+" ");
		}
	return s4;
}


int main()
{
	std::string recenica;
	std::string kopija;
	rijeci rijec;
	try {
		std::cout<<"Unesite recenicu: ";
		std::getline(std::cin, recenica);
		std::cout<<"Unesite fraze: ";
		std::string rij;
		do {
			std::getline(std::cin,rij);
			if(rij!="") rijec.push_back(rij);
		} while(rij!="");
		kopija=IzmijeniUPigLatin(recenica,rijec);
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<IzmijeniUPigLatin(recenica,rijec)<<std::endl;
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<ObrniFraze(recenica,rijec);
	return 0;
}