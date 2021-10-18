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
using std::string;
using std::cout;
using std::cin;
using std::vector;

string ObrniFraze(string s,vector<string>lista)
{
	string returnstring,buffer;
	std::string::size_type n;
	for(int i=0; i<(int)lista.size(); i++) { //clan po clan idemo po listi rijeci
		while(1) {
			n=s.find(lista[i]);			//u n se pohranjuje pozicija prvog cuda, ako nema sljedeceg, breaka se inf. petlja
			if (n==std::string::npos) {
				break;
			}

			if(n!=std::string::npos) {		//nadje li se, ide standardni nacin za obrtanje rijeci
				
				for(int j=0;j<(int)lista[i].length()/2;j++){
					char temp;
					temp=s[n];
						s[n]=s[(int)lista[i].length()-1-j];
						s[(int)lista[i].length()-1-j]=temp;
						n++;
				}




			}
		}




	}
	return returnstring;

}
int main ()
{
	string str="Reverse this pls mane thanks mane mane name hame";
	vector<string>lista(1,"mane");
	ObrniFraze(str,lista);
	cout<<str;
	return 0;
}