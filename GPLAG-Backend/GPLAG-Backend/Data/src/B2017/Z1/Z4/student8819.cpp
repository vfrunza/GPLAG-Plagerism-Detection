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
#include<string>
#include <vector>

std::string NapraviPalindrom(std::string s1, std::string s2){
    std::string fraz1;
    std::string fraz2;
   int  m=s2.size()-1;
   char c;
  for(int i=0;i<s1.size();i++) {
      for(int k=0;k<s2.size(); k++){
      if(s1[i]==s2[k]){
      for(int j=0; j<m; j++,m--)
       c=s2.at(m);
        s2.at(m)=s2.at(i);
        s2.at(i)=c;
        return s2;
      } 
	
  } 

}
}



int main ()
{
std::string recenica;
std::string a;
 std::cout << "Unesi rečenicu: ";
 std::getline(std::cin, recenica);
 std::cout<<"Unesite fraze: ";
  while(!(std::cin>>a) || std::cin.peek()!='\n\n');
 
 std::cout << "Rečenica izgovorena naopako glasi: ";
 std::string p(NapraviPalindrom(recenica,a));
std::cout<<p;	
	
	return 0;
}




