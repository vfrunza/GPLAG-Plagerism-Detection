#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a)
{
	int  u, z, t, i, j;
	std::vector<int> vv, vvv;
	int x0, x1, x2, x3, x4, x5, x6, x7, x8, x9;
	
	for(int x:v)
	{
		z=x;
		j=0;
		do
		{
		    z=z/3;
		    j++;
		}while(z!=0);
		
		z=x;
		
		for(i=0; i<j; i++)
		{
		    t=z%3;
		    vv.push_back(t);
	    	z=z/3;
		}
		
		x0=0;
		x1=0;
		x2=0;
		x3=0;
		x4=0;
		x5=0;
		x6=0;
		x7=0;
		x8=0;
		x9=0;
		
		for(int xx:vv)
		{
			if(xx==0) x0++;
			else if(xx==1) x1++;
			else if(xx==2) x2++;
			else if(xx==3) x3++;
			else if(xx==4) x4++;
			else if(xx==5) x5++;
			else if(xx==6) x6++;
			else if(xx==7) x7++;
			else if(xx==8) x8++;
			else if(xx==9) x9++;
		}
	
		if(x0%2==0 && x1%2==0 && x2%2==0 && x3%2==0 && x4%2==0 && x5%2==0 && x6%2==0 && x7%2==0 && x8%2==0 && x9%2==0) u=1;
		else u=2;
		
		if(u==2)
		{
			if(x0==0) x0++;
			if(x1==0) x1++;
			if(x2==0) x2++;
			if(x3==0) x3++;
			if(x4==0) x4++;
			if(x5==0) x5++;
			if(x6==0) x6++;
			if(x7==0) x7++;
			if(x8==0) x8++;
			if(x9==0) x9++;
			
			if(x0%2==1 && x1%2==1 && x2%2==1 && x3%2==1 && x4%2==1 && x5%2==1 && x6%2==1 && x7%2==1 && x8%2==1 && x9%2==1) u=0;
		}
		
		for(i=0; i<j; i++) vv.erase(vv.begin());
	
		if(a==true && u==1) vvv.push_back(x);
		else if(a==false && u==0) vvv.push_back(x);
		else continue;
		
	}
	
	for(int i=0; i<vvv.size(); i++)
	{
		for(int j=i+1; j<vvv.size(); j++)
		{
			if(vvv[i]==vvv[j])
			{
				vvv.erase(vvv.begin()+j);
				i--;
			}
		}
	}
	
		return vvv;
}

int main()
{
	int x;
	std::vector<int> v, vv;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	for(int i=0; i<1000; i++)
	{
		std::cin>>x;
		if(x==0) break;
		else v.push_back(x);
	}
	
	v=IzdvojiGadne(v, true);
	vv=IzdvojiGadne(vv, false);
	
	std::cout<<"Opaki: ";
	for(int y:v) std::cout<<y<<" ";
	
	std::cout<<"\nOdvratni: ";
	for(int z:vv) std::cout<<z<<" ";
	
	return 0;
}