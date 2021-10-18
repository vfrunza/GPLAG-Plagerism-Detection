/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
string Obrni(string s)
{
    char slovo;
      for(int i=0;int(i<s.size()/2);i++)
   {
      slovo=s[i];
      s[i]=s[s.size()-1-i];
      s[s.size()-1-i]=slovo;
   }
}
string ObrniFraze(string a,string b)
{
    for(int i=0;i<a.size();i++)
    {
        string znak1;
        znak1=a.substr(i,' ');
        for(int j=0;j<b.size();j++)
        {
            string znak;
            znak=b.substr(j,' ');
            
        }
    }
}

int main()
{
    string s;
    string s1;
    cout<<"Unesite recenicu: ";
    std::getline(cin,s);
    cout<<"Unesite fraze: ";
    std::getline(cin,s1); 
    ObrniFraze(s,s1);
return 0;
}