/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool f (int n)
{
	int br1 = 0, br2 = 0, br3 = 0;
	while (n != 0)
	{
		if (n%3==0)
		   br1++;
		if (n % 3 == 1)
		   br2++;
		if (n % 3 == 2)
		   br3++;
		n/=3;
	}
	if ((br1%2==0 && br2%2==0 && br3%2==0) || (br1%2==0 && br2%2==0 && br3==0) || (br1%2==0 && br3%2==0 && br2==0) || (br1==0 && br2%2==0 && br3%2==0) || (br1%2==0 && br2==0 && br3==0) || (br1==0 && br2%2==0 && br3==0) || (br1==0 && br2==0 && br3%2==0))
	    return true;
	    return false;
}
bool f1 (int n)
{
	int br1=0, br2=0, br3=0;
	while (n!=0)
	{
		if (n%3==0) br1++;
		if (n%3==1) br2++;
		if (n%3==2) br3++;
		n/=3;
	}
	if ((br1%2!=0 && br2%2!=0 && br3%2!=0) || (br1%2!=0 && br2%2!=0 && br3==0) || (br1%2!=0 && br2==0 && br3%2!=0) || (br1==0 && br2%2!=0 && br3%2!=0) || (br1%2!=0 && br2==0 && br3==0) || (br1==0 && br2%2!=0 && br3==0) || (br1==0 && br2==0 && br3%2!=0))
	    return false;
	    return true ;
}

bool PostojiLi (std::vector< int > v, int n ) {
	for (int i=0; i<v.size(); i++)
	{
		if (n==v[i])
		  return true;
		
	}
	return false;
}

std::vector <int> IzdvojiGadne (std::vector <int> v, bool a )
{
	std::vector <int> v1;
	if (a) {
	for (int i=0; i<v.size(); i++)
	{
		if (f(v[i])){
			if (!PostojiLi(v1,v[i])) v1.push_back (v[i]);
		}
	}
	}
	if (a==false)
	{
		for (int i=0; i<v.size(); i++)
		{
			if (!f1 (v[i]))
			{
				if (!PostojiLi(v1, v[i])) v1.push_back (v[i]);
			}
		}
	}
	return v1;
	
}

int main ()
{
	std::vector <int> v, v1;
	int i;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin>>i;
		if(i!=0)
		v.push_back (i);
	} while (i!=0);
	v1=IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for (int i=0; i<v1.size(); i++)
	    std::cout<<v1[i]<<" ";
	std::cout<<std::endl;
	v1=IzdvojiGadne(v,false);
	std::cout<<"Odvratni: ";
	for (int j=0; j<v1.size(); j++)
	    std::cout<<v1[j]<<" ";
	
	return 0;
}