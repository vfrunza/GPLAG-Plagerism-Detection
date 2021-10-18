#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

std::vector<int> GadniOpakiOdvratni(std::vector<std::vector<int>> A, bool z,std::vector<int> tr)
{
	int y=0;
	std::vector<int>B1,C1;
	for(auto p:A){
	int n(0);
	
	int par=0,nepar=0;
	for(int i=0; i<3; i++)
	{
		n=0;
		for(auto j: p){
			i=std::abs(i);
			j=std::abs(j);
			if(i==j)
			n++;}
		if(n!=0&&n%2==0)
			par++;
		else if(n!=0&&n%2==1)
			nepar++;
	}
		if(par!=0&&nepar==0)
			B1.push_back(tr[y]);
		else if(nepar!=0&&par==0)
			C1.push_back(tr[y]);
		y++;
	}
	if(z)
		return B1;
	return C1;
}




std::vector<int> IzdvojiGadne (std::vector<int>v, bool k)
{
	for (int i=0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			if(v[i]==v[j]){
			v.erase(v.begin()+j);
			if(i>0)
			i--;}
		}
	}
	
	std::vector<std::vector<int>> A;
	std::vector<int>B,C;
	int p, q;
	for (int i: v)
	{
		std::vector<int> m;
		p=i;
		do
		{
			q=p%3;
				m.push_back(q);
			p/=3;
			p=std::abs(p);
		}while(p!=0);
		A.push_back(m);
	}
	B=GadniOpakiOdvratni( A, true,v);
	C=GadniOpakiOdvratni( A, false,v);
	if(k)
	return B;
	return C;
}

int main ()
{
	int n;
	std::vector<int>v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		std::cin>>n;
		if(!std::cin&&n!=0)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else if(std::cin&&n!=0)
		{
			v.push_back(n);
		}
		else break;
	}
	std::vector<int>b;
	std::vector<int>c;
	b=IzdvojiGadne(v, true);
	c=IzdvojiGadne(v, false);
	std::cout<<"Opaki: ";
	if(b.size()==0)
	{ 
		std::cout<<std::endl;
	}
	else{
	for (int i=0; i<b.size(); i++)
	{
		std::cout<<b[i]<<" ";
	}
	}
	std::cout<<std::endl<<"Odvratni: ";
	if(c.size()==0)
	{
		std::cout<<std::endl;
	}
	else
	{
		for(int j=0; j<c.size(); j++)
		{
			std::cout<<c[j]<<" ";
		}
	}
	return 0;
}