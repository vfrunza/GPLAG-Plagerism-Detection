/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
typedef std::vector<int> vector;

vector IzbaciDuplikate(vector v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(v.at(i)==v.at(j))
			{
				v.erase(v.begin()+ j);
				j--;
		    }
		}
	}
	return v;

}

vector IzdvojiGadne(vector v, bool b)
{
	if(v.size()==0) return v;
	vector p=IzbaciDuplikate(v);
	vector r;
	for(int i=0; i<p.size();i++)
	{
		int y,m;
		m=p.at(i);
		vector c;
		do{
			
			int x=m/3;
			if(x==0) 
			y=m;
			else 
			y=m-3*x;
			c.push_back(y);
			m=x;
		}while(m!=0);
			
			int nula{0},jedan{0},dva{0};
            for(int j=0;j<c.size();j++)
			{
			if(c.at(j)==0) nula++;
			if(c.at(j)==1||c.at(j)==-1) jedan++;
			if(c.at(j)==2||c.at(j)==-2) dva++;
			}
		if(b)
			{
			if((nula==0||nula%2==0)&&(jedan==0||jedan%2==0)&&(dva==0||dva%2==0))
			r.push_back(p.at(i));
			}	
		if(!b)
			{
			if((nula==0||nula%2!=0)&&(jedan==0||jedan%2!=0)&&(dva==0||dva%2!=0))
			r.push_back(p.at(i));	
			}	
	}
		return r;
}

int main ()
{
int x;
vector a;
std::cout<<"Unesite brojeve (0 za prekid unosa): ";
while(std::cin>>x,x!=0) a.push_back(x);
vector b=IzdvojiGadne(a,true);
vector c=IzdvojiGadne(a,false);
std::cout<<"Opaki: ";
for(int z:b) std::cout<<z<<" ";
std::cout<<std::endl;
std::cout<<"Odvratni: ";
for(int z:c)std::cout<<z<<" ";
	return 0;
}