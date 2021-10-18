/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
/*#include <iostream>
#include <vector>
#include <string>

std::vector <int> IzdvojiGadne (std::vector<int> v, bool b){
	std::vector<int> a ;
	for(int i=0; i<v.size(); i++){
		
		int br_nula(0), br_jedinica(0), br_dvojki(0);
	
		int c;
		if(v[i]<0)
		   c = v[i]*(-1);
		else
		   c = v[i];
		while(c!=0){
			if(c%3==0)
			  br_nula++;
			else if(c%3==1)
			  br_jedinica++;
			else
			  br_dvojki++;
			c/=3;
		}
	bool vec_ima(false);
	for(int j=0; j<a.size(); j++){
		if(v[i]==a[j]){
			vec_ima = true;
			break;
		}
	}
	
	if(b && br_nula%2==0 && br_jedinica%2==0 && br_dvojki%2==0 && !vec_ima && v[i]!=0)
	   a.push_back(v[i]);
	else if(!b && (br_nula%2!=0 || br_nula==0) && (br_jedinica%2!=0 || br_jedinica==0) && (br_dvojki%2!=0 || br_dvojki==0) && !vec_ima)
	   a.push_back(v[i]);
	}
return a;	
}

int main ()
{
    int broj;
    std::vector <int> v;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		
		std::cin>>broj;
		if(broj!=0)
		  v.push_back(broj);
	}while(broj!=0);
	
	std::vector <int> a(IzdvojiGadne(v,true));
	std::cout<<"Opaki: ";
	for(int i=0; i<a.size(); i++)
	   std::cout<<a[i]<<" ";
    std::vector<int> b(IzdvojiGadne(v, false));
    std::cout<<"\nOdvratni: ";
    for(int i=0; i<b.size(); i++)
      std::cout<<b[i]<<" ";
    
	return 0;
}*/
#include <iostream>
#include <string>
using namespace std;
class Praksa{
      private:
      string s = "On my freshman year I realised that writing codes makes me really happy. Even writing something fairly simple was fun. I would love to learn something new and see what it's like in real life. Hope that my aplication will be of interest to you.";
     public:
void Funkcija(){
    cout<<s<<endl;
}
};
int main(){
Praksa p;
p.Funkcija();
return 0;
}

