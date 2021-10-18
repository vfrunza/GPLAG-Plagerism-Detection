/*B 2016/2017, Zadaca 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
std::string IzmijeniUPigLatin(std::string recenica , std::vector<std::string> fraze){
	for(int i=0;i<fraze.size();i++){
		for(int j=0;j<fraze[i].length();j++){
			if(fraze[i][j]==' ') throw std::domain_error ("Nekorektan izbor rijeci");
			if(!((fraze[i][j]>='A' && fraze[i][j]<='Z') || (fraze[i][j]>='a' && fraze[i][j]<='z'))) throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	for(int i=0;i<recenica.length();i++){
		while((i<recenica.length()) && (recenica[i]==' ')) i++;

		if(i==recenica.length()) break;
		int poc_rijeci(i);
		int duz_rijeci(0);
		while(i<recenica.length() && recenica[i]!=' ') {
			duz_rijeci++;
			i++;
		}
		std::string s(recenica.substr(poc_rijeci,duz_rijeci));
		for(int j=0;j<fraze.size();j++){
		if(s==fraze[j]){
			std::string prvo_slovo(s.substr(0,1));
			for(int k=0;k<s.size()-1;k++){
				s[k]=s[k+1];
			}
			s.erase(s.size()-1,1);
			s+=prvo_slovo;
			s+="ay";
			i+=2;
			recenica.erase(poc_rijeci,duz_rijeci);
			recenica.insert(poc_rijeci,s);
			}
		}
	}
	return recenica;
}

std::string ObrniFraze (std::string recenica,std::vector<std::string> fraze)
{
    for(int i=0;i<fraze.size();i++){
        std::string prvo_slovo=fraze[i].substr(0,1);
        int duzina_fraze=fraze[i].length();
        for(int j=0;j<recenica.length();j++)
        {
        	if (j==recenica.length()-duzina_fraze+1) break;
            std::string pr=recenica.substr(j,1);
            if (pr==prvo_slovo)
            {
                int poc=j;
                std::string rijec=recenica.substr(poc,duzina_fraze);
                if(rijec==fraze[i])
                {
                    for(int k=poc;k<poc+duzina_fraze;k++)
                    {
                        recenica[k]=fraze[i][poc+duzina_fraze-1-k];
                    }
                }
            }
        }
    }
    return recenica;
}

int main(){
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string fraza;
	while(std::getline(std::cin,fraza),fraza!=""){
		fraze.push_back(fraza);
	}
	std::string s(ObrniFraze(recenica,fraze));
	try{
	std::string s1(IzmijeniUPigLatin(recenica,fraze));
	std::cout<<"Recenica nakon PigLatin transformacije: "<<s1<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<s<<std::endl;
	return 0;
}