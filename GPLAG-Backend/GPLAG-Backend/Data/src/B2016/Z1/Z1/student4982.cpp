#include<iostream>
#include<vector>
#include<limits>


long long int PretvoriUTernarni(int a)
{
	
	long long int z=0;
	if(a<0) a=-a;
	std::vector<int> cifre;
	while(a!=0)
	{
		cifre.push_back((a%3));
		a=a/3;
	}
	
	
	for(int j=cifre.size()-1;j>=0;j--)
	{
		
		z=z*10;
		z+=cifre[j];
		
	}
	
	return z;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t)
{
	std::vector<int> v2;
	if(t==true)
	{
		for(int i=0;i<v.size();i++)
		{
			bool ponavlja_se=false;
			if(v.size()!=0)
			{
				for(int j=0;j<i;j++)
				{
					if(v[j]==v[i])
					{
						ponavlja_se=true;
						break;
					}
				}
			}
			if(ponavlja_se) continue;
			long long int z=PretvoriUTernarni(v[i]);
			long long int l=z;
			std::vector<int> cifre;
			
			while(z!=0)
			{
				if(cifre.size()==0) cifre.push_back(z%10);
				else
				{
					bool ponavlja_se=false;
					for(int k: cifre)
					{
						if(k==(z%10)) {ponavlja_se=true; break;}
					}
					if(ponavlja_se==false) cifre.push_back(z%10);
				}
				z=z/10;
			}
			std::vector<int> brojaci(cifre.size(),0);
			while(l!=0)
			{
				for(int i=0;i<cifre.size();i++)
				{
					if(cifre[i]==(l%10)) brojaci[i]++;
				}
				l=l/10;
			}
			
			bool svi_parni=true;
			for(int k: brojaci){ if(k%2!=0) {svi_parni=false; break;} }
			if(svi_parni) v2.push_back(v[i]);
			
		}
	}
	
	else
	{
		for(int i=0;i<v.size();i++)
		{  bool ponavlja_se=false;
			if(v.size()!=0)
			{
				for(int j=0;j<i;j++)
				{
					if(v[j]==v[i])
					{
						ponavlja_se=true;
						break;
					}
				}
			}
			if(ponavlja_se) continue;
			long long int z=PretvoriUTernarni(v[i]);
			if(z==4) continue;
			long long int l=z;
			std::vector<int> cifre;
			while(z!=0)
			{
				if(cifre.size()==0) cifre.push_back(z%10);
				else
				{
					bool ponavlja_se=false;
					for(int k: cifre)
					{
						if(k==(z%10)) {ponavlja_se=true; break;}
					}
					if(ponavlja_se==false) cifre.push_back(z%10);
				}
				z=z/10;
			}
			std::vector<int> brojaci(cifre.size(),0);
			while(l!=0)
			{
				for(int i=0;i<cifre.size();i++)
				{
					if(cifre[i]==l%10) brojaci[i]++;
				}
				l=l/10;
			}
			bool svi_neparni=true;
			for(int k:brojaci) 
			{ 
				if(k%2==0) 
				{
					svi_neparni=false; break;
					
				} 
				
			}
			if(svi_neparni) v2.push_back(v[i]);
			}
		}
		return v2;
	}


int main ()
{
	std::vector<int> v1,v2,v3;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	while(1)
	{
		std::cin>>n;
		if(n==0) break;
		v1.push_back(n);
	}
	v2=IzdvojiGadne(v1,true);
	v3=IzdvojiGadne(v1,false);
	std::cout<<"Opaki: ";
	for(int x: v2) std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int x: v3) std::cout<<x<<" ";
	
	return 0;
}