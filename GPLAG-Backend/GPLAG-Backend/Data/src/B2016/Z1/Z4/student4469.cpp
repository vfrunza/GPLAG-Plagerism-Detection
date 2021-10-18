/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string piglatin(std::string rijec) {

char temp;
temp=rijec[0];
rijec.erase(rijec.begin());
rijec=rijec+temp+"ay";


return rijec;
}



std::string obrnirijec(std::string rijec) {

char temp;
for(int i=0;i<(rijec.size()/2);i++) {
temp=rijec[i];
rijec[i]=rijec[rijec.size()-1-i];
rijec[rijec.size()-1-i]=temp;

}
return rijec;
}


bool slovo(char a) {

if((a>='a' && a<='z') || (a>='A' && a<='Z'))
return true;

return false;
}


bool razlicitznak(std::string rijec) {

for(int i=0;i<rijec.size();i++) {
	
	if(!slovo(rijec[i]))
	return true;
}
return false;
}



std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> vektorrijeci) {

int velicina;
std::string novarecenica;



int j=0;

for(int i=0;i<recenica.size();i++) {
	
	while( !slovo(recenica[i]) )
	i++;
	j=i;
	while( slovo(recenica[j]) ) {
	j++;
	}

std::string pomocni=recenica.substr(i,j-i);


if(vektorrijeci.size()!=0) {

for(int k=0;k<vektorrijeci.size();k++) {
	if(pomocni==vektorrijeci[k]) {
		
		pomocni=piglatin(pomocni);
	}
}
}

else {
pomocni=piglatin(pomocni);
}


novarecenica=novarecenica+pomocni;
if(j!=recenica.size()){
	novarecenica=novarecenica+recenica[j];
}


i=j;
}


return novarecenica;
}


std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze) {
	

if(fraze.size()!=0)
{

	for(int i=0; i<fraze.size(); i++)
	{


		for(int j=0; j<recenica.size()-fraze[i].size(); j++)
		{

			std::string pomocni=recenica.substr(j,j+fraze[i].size());
			if (pomocni==fraze[i])
			{

				pomocni=obrnirijec(pomocni);
				int z=j;
				int b=0;
				while(z<j+fraze[i].size())
				{

					recenica[z]=pomocni[b];
					z++;
					b++;

				}

				j=j+b;

			}


		}


	}

}




/*int j;
for(int i=0;i<recenica.size();i++) {
	
	while( !slovo(recenica[i]) )
	i++;
	j=i;
	while( slovo(recenica[j]) ) {
	j++;
	}

std::string pomocni=recenica.substr(i,j-i);


for( int k=0;k<fraze.size();k++) {

if (pomocni==fraze[k]){

	pomocni=obrnirijec(pomocni);
	int z=i;
	int b=0;
	while (z<j) {
		recenica[z]=pomocni[b];
		z++;
		b++;
	}
}

}

i=j;

}

*/

return recenica;

}

int main ()
{
	std::string recenica;
	std::string ofrecenica;
	std::string plrecenica;
	bool razlicit=false;
	
   std::cout<<"Unesite recenicu: ";
   std::getline(std::cin,recenica);
   
   
std::vector<std::string> vektorfraza;

std::string fraza;
std::cout<<"Unesite fraze: ";
char znak=std::cin.get();
while(znak!='\n') {

std::getline(std::cin,fraza);
fraza=znak+fraza;
	vektorfraza.push_back(fraza);
    znak=std::cin.get();
}

try {

for(int i=0;i<vektorfraza.size();i++) {
if(razlicitznak(vektorfraza[i])) {
throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
}
  
}
}

catch(std::domain_error izuzetak){
	std::cout<<izuzetak.what();
	std::cout<<std::endl;
	ofrecenica=ObrniFraze(recenica,vektorfraza);
std::cout<<"Recenica nakon obrtanja fraza: "<<ofrecenica;
return 0;
}


plrecenica=IzmijeniUPigLatin(recenica,vektorfraza);
ofrecenica=ObrniFraze(recenica,vektorfraza);

std::cout<<"Recenica nakon PigLatin transformacije: "<<plrecenica;
std::cout<<std::endl;
std::cout<<"Recenica nakon obrtanja fraza: "<<ofrecenica;






	return 0;
}