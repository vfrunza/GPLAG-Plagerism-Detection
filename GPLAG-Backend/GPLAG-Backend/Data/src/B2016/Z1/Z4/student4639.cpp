/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/


//... STRINGOVI..
#include <iostream>
#include <vector>
#include <string>
std::string ObrniFraze (std::string s, std::vector<std::string>spisak){

	for(int i = 0; i < spisak.size();i++){
		
		size_t pos = s.find(spisak[i],0);
		
		while(pos != std::string::npos){
			int j = pos, k = pos + spisak[i].size() - 1;
			
			while(j < pos + spisak[i].size() / 2){
				std::swap(s[j],s[k]);
				j++;
				k--;
			}
			pos = s.find(spisak[i],pos + 1);
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string rec,std::vector<std::string>l){
	std::string t = rec;
	for(int i = 0; i < l.size();i++){
		size_t pos = rec.find(l[i],0);
		
		while(pos != std::string::npos){
			l[i] += l[i][0];
			l[i] += "ay";

			if(l[i].size() > 1){
				int o(0), p (1);
			
				while(p < l[i].size()){
					l[i][o] = l[i][p];
					o++;
					p++;
						
				}
				l[i].resize(l[i].size() - 1);
			}
			rec.replace(rec.begin() + pos,rec.end(),l[i]);
			pos += l[i].size();
			
		//	size_t s_p = 0;
			
			pos = rec.find(l[i],pos + 1);
		//	std::cout<<pos<<" "<<std::endl;
	
		}
		
	}
	return rec;

}
int main ()
{
	std::cout << ObrniFraze( "Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta.", 
			{"zadaca", "Tehnike programiranja", "drugih predmeta", "meso od sira"}) << std::endl;
	
	std::cout<<"\n\n";
	
	std::cout<<IzmijeniUPigLatin("Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta.", 
	//	std::vector<std::string>({"zadaca", "Tehnike programiranja", "drugih predmeta", "meso od sira"}))<<std::endl;
	{"zadaca", "Tehnike programiranja", "drugih predmeta", "meso od sira"})<<std::endl;
		
	return 0;
}