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
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;





bool slovo(char c){
	
	if( (c>='a' && c<='z') || (c>='A' && c<='Z') ) return true;
	
	return false;
}

std::string Daj_Palindrom(std::string s)
{


	std::string palindrom (s.length(),' ');

	for(int i=0; i<s.length(); i++) {

		palindrom.at(i)=s.at(s.length()-1-i);
	}

	return palindrom;

}


std::string NapraviPalindrom(std::string s, std::vector<std::string> v)
{

	bool nalazi_se {false};
	bool ne_veci {true};
	int i(0);



	for(std::string x : v) {


		ne_veci=true;
		nalazi_se=false;

		if(x.length()>s.length()) ne_veci=false;

		if(ne_veci) {

			i=0;


			while( i<s.length() ) {

				while( i<s.length() && s.at(i)!=x.at(0))	i++;

				nalazi_se=false;

				if(i==s.length()) break; // kraj recenice

				if(i+x.length()<=s.length() && s.substr(i,x.length())==x) nalazi_se=true;







					if(nalazi_se){
					
						nalazi_se=false;
						
						if(s.length()==1) nalazi_se=true;
						
						else if(x.length()==s.length()) nalazi_se=true;
						
						else if(i+x.length()==s.length() && !slovo(s.at(i-1)) ) nalazi_se=true;
						
						else if(i==0 && !slovo(s.at(i+x.length())) )  nalazi_se=true;
						
						else if( i>0 && i+x.length()<s.length() && !slovo(s.at(i-1)) && !slovo(s.at(i+x.length()))  ) nalazi_se=true;
						
						
						
						if(nalazi_se){
							
						std::string palindrom {Daj_Palindrom(x)};
						
						std::string s1;

						s1=s.substr(0,i+x.length());
						

						std::string s2;


						s2=s.substr(i+x.length(),s.length()-s1.length());


						s=s1+palindrom+s2;

						i+=2*x.length();
							
							}
					}

				i++;
			}

		}


	}



	return s;
}


std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v)
{

	bool nalazi_se {false};
	bool ne_veci {true};
	int i(0);





	for(std::string x : v) {

		
		ne_veci=true;
		nalazi_se=false;

		if(x.length()>s.length()) ne_veci=false;

		if(ne_veci) {

			i=0;


			while( i<s.length() ) {

				while( i<s.length() && s.at(i)!=x.at(0))	i++;

				nalazi_se=false;

				if(i==s.length()) break; // kraj recenice

				if(i+x.length()<=s.length() && s.substr(i,x.length())==x) nalazi_se=true;




					

				if(nalazi_se) {

					nalazi_se=false;
						
						if(s.length()==1) nalazi_se=true;
						
						else if(x.length()==s.length()) nalazi_se=true;
						
						else if(i+x.length()==s.length() && !slovo(s.at(i-1)) ) nalazi_se=true;
						
						else if(i==0 && !slovo(s.at(i+x.length())) )  nalazi_se=true;
						
						else if( i>0 && i+x.length()<s.length() && !slovo(s.at(i-1)) && !slovo(s.at(i+x.length()))  ) nalazi_se=true;
						
						if(nalazi_se){
						
						std::string s1;

						s1=s.substr(0,i+x.length());

						if(x.length()%2!=0)
							s1=s.substr(0,i+x.length()/2+1);

						else s1=s.substr(0,i+x.length()/2);




						std::string palindrom {Daj_Palindrom(x.substr(0,x.length()/2))};

						std::string s2;


						s2=s.substr(i+x.length(),s.length()-s1.length());


						s=s1+palindrom+s2;

						i+=x.length();
					}

				}

				
				i++;

			}
			


		}


	}



	return s;
}






int main ()
{

	cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(cin,recenica);
	cout<<"Unesite fraze: ";
	std::string fraza;
	std::vector<std::string> v;

	while(true) {
		char znak;
		znak=std::cin.peek();
		if(znak=='\n') break;
		std::getline(cin,fraza);
		v.push_back(fraza);
	}

	
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,v)<<endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,v)<<endl;


	return 0;
}




