/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool JeLiOpak (int n) {
int brojac1=0,brojac2=0,brojac3=0;
while(n!=0)
{
	if(n%3==0) brojac1++;
	if(n%3==1) brojac2++;
	if(n%3==2) brojac3++;
	
	n=n/3;
}
if((brojac1 % 2 == 0 || brojac1 == 0) && (brojac2 % 2 == 0 || brojac2 == 0) && (brojac3 % 2 == 0 || brojac3 == 0))
return true;
else
return false;
}

bool JeLiOdvratan (int n) {
int brojac1=0,brojac2=0,brojac3=0;
while(n!=0)
{
	if(n%3==0) brojac1++;
	if(n%3==1) brojac2++;
	if(n%3==2) brojac3++;
	n=n/3;
}
if((brojac1 % 2 == 1 || brojac1 == 0) && (brojac2 % 2 == 1 || brojac2 == 0) && (brojac3 % 2 == 1 || brojac3 == 0))
return true;
else 
return false;
}



std::vector<int> IzdvojiGadne (std::vector<int> v, bool gadni) {
std::vector<int>v1;
for(int i=0;i<v.size();i++)
{
	if(JeLiOpak(v[i]) && gadni) v1.push_back(v[i]);
	if(JeLiOdvratan(v[i]) && !gadni) v1.push_back(v[i]);
}


for(int i=0;i<v.size();i++)
{
	for(int j=i+1;j<v.size();j++)
	{
		if(v[i]==v[j])
		{
			for(int k=j;k<v.size()-1;k++)
			{
				v1[k] = v[k+1];
			}
			v1.resize(v1.size()-1);
			j--;
			
			}
		}
	}

	return v1;
}
	int main() {
std::vector<int>v;
std::vector<int>v1;
int n;

std::cout<<"Unesite brojeve(0 za prekid unosa) : ";
std::cin>>n;
if(n==0)
std::cout<<"Broj elemenata mora biti veci od 0!";
v.resize(n);
b