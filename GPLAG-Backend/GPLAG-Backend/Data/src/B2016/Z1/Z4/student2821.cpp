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
#include <utility>

using std::cout;
using std::cin;
typedef std::vector<std::string> Spisak;
typedef std::string String;

std::string IzvrniString(std::string &s){
   int j=s.length()-1;
   for(int i=0;i<s.length()/2;i++){
      std::swap(s[i],s[j]);
      j--;
   }
      
     return s; 
   }


String ObrniFraze(String Modifikuj,Spisak Rijeci)
{   std::string Modifikovano;
    for(int i=0; i<Modifikuj.length(); i++) {
        String s=Rijeci[i];
        int indeksi=0;
        int br=0,l=0,m=0;
        for(int j=0; j<Modifikuj.length(); j++) {
            while(s[j]!=Modifikuj[m]) {
                br++;
                m++;
            }
            l=br;
            for(int k=0; k<s.length(); k++) {
                if(s[k]==Modifikuj[br]) indeksi++; br++;
            }
            if(indeksi==s.length()) {
                std::string iz;
                iz(Modifikuj.substr(l,indeksi));
                //std::string &Izdvojena_rijec=iz;
                Modifikovano=IzvrniString(iz);
            }
        }
    }
    return Modifikovano;
    
}

int main ()
{
    String Modifikuj;
    Spisak Rijeci;
    String Fraza;

    cout<<"Unesite recenicu: ";
    std::getline(std::cin,Modifikuj);
    cout<<"Unesite fraze: ";
    for(;;) {
        std::getline(std::cin,Fraza,'\n');
        Rijeci.push_back(Fraza);
        if(Fraza.length()==0) {
            break;
        }
    }
    ObrniFraze(Modifikuj,Rijeci);
    


    return 0;
}