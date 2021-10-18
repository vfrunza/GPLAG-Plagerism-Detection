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
#include <vector>
#include <string>

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> vekStringova)
{
    for(int i=0; i<vekStringova.size(); i++)
    {
        for(int j=0; j<recenica.length(); j++)
        {
            std::string rijec=vekStringova[i];
            std::string pomocnaRijec;
            while(recenica[j]==' ' && j<recenica.length()) j++;
            if(recenica[j]==rijec[0])
            {
                int z=0;
                while(recenica[j]==rijec[z] && j<recenica.length())
                {
                    pomocnaRijec.push_back(recenica[j]);
                    j++;
                    z++;
                    if(z==rijec.length() && (recenica[j]>='a' && recenica[j]<='z'))
                    {
                        pomocnaRijec.push_back('*');
                        break;
                    }
                }
                if(pomocnaRijec==rijec)
                {
                    rijec="";
                    for(int k=pomocnaRijec.size()-1; k>=0; k--) rijec.push_back(pomocnaRijec[k]);
                    recenica=recenica.substr(0,j)+rijec+recenica.substr(j);
                    j+=rijec.size();
                }
            }
            else while(recenica[j]!=' ' && j<recenica.length()) j++;
        }
    }
    return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> vekStringova)
{
    for(int i=0; i<vekStringova.size(); i++)
    {
        for(int j=0; j<recenica.length(); j++)
        {
            std::string rijec=vekStringova[i];
            std::string pomocnaRijec;
            while(recenica[j]==' ' && j<recenica.length()) j++;
            if(recenica[j]==rijec[0])
            {
                int z=0;
                while(recenica[j]==rijec[z] && j<recenica.length())
                {
                    pomocnaRijec.push_back(recenica[j]);
                    j++;
                    z++;
                }
                if(pomocnaRijec==rijec)
                {
                    rijec="";
                    int vel=pomocnaRijec.size()/2;
                    if(pomocnaRijec.size()%2==0) vel--;
                    for(int k=vel; k>=0; k--) rijec.push_back(pomocnaRijec[k]);
                    vel=0;
                    recenica=recenica.substr(0,j-rijec.size()-vel)+rijec+recenica.substr(j);
                    j+=rijec.size();
                }
            }
            else while(recenica[j]!=' ' && j<recenica.length()) j++;
        }
    }
    return recenica;
}


int main()
{
    std::cout << "Unesite recenicu: ";
    std::string recenica;
    std::getline(std::cin, recenica);
    std::vector<std::string> rjecnik;
    std::cout << "Unesite fraze: ";
    for(;;)
    {
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec.size()==0) break;
        //if(std::cin.peek()=='\n') break;
        else rjecnik.push_back(rijec);
    }
    std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, rjecnik) << std::endl;
    std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, rjecnik);
    return 0;
}