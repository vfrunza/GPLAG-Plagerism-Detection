/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/


std::string ObrniFraze(std::string s, std::vector<std::string> f){
std::string s;

 for(int i=0;i=s.length()-1;i++){
 	for( int j=0;j<i;j--){
 		char pom=s[j];
 		s[i]=s[j];
 		s[j]=pom;
 	}
 	
 	
 }
 return s;
 
}

int main ()
{    
	std::cout <<"Unesite recenicu: ";
	std::string s;
	
	std::cout <<"Unesite fraze: ";
	
	return 0;
}