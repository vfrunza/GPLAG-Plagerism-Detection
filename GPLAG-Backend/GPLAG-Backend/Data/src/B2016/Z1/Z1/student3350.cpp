
#include<iostream>
#include<vector>
#include<cmath>
int Dec_to_Ter(int broj)
{
	int tmp(0), stepen(0);
while(broj!=0)
	{
		tmp+=((broj%3)*pow(10,stepen++));
		broj /=3;
	}	
return tmp;
}
void opak_odvratan(int broj , bool &opak , bool &odvratan)
{
	opak=true;
	odvratan=true;
	int ternar=Dec_to_Ter(broj);
	int tmpopak1=ternar,tmpopak11=ternar;
	int tmpodvratan2=ternar,tmpodvratan22=ternar;
	std::vector<int>vecopak;
	while (tmpopak11!=0) 
		{
			vecopak.push_back(tmpopak11 % 10);
			tmpopak11 /=10;
		}
	std::vector<int>vecodvratan;
	while (tmpodvratan22 !=0) 
		{
			vecodvratan.push_back(tmpodvratan22 %10);
			tmpodvratan22 /=10;
		}
	while(tmpopak1!=0)
	{
		int cifra=tmpopak1 %10;
		int brojacCifara(0);
		tmpopak1 /=10;
		for(int i=0;i<vecopak.size();i++)
			if(vecopak[i]==cifra) { brojacCifara++; }
		if (brojacCifara%2==1) opak=false; 
	}
	while (tmpodvratan2!=0) 
	{
		int cifra(tmpodvratan2 %10);
		int brojacCifara(0);
		tmpodvratan2 /=10;
		for(int i=0;i<vecodvratan.size();i++)
			if(vecodvratan[i]==cifra) { brojacCifara++; }
			if(brojacCifara % 2==0) odvratan=false;
	}
}	
std::vector<int>IzdvojiGadne(std::vector<int>original,bool opakodvratan)
{
	std::vector<int>tmp ;
	bool opak,odvratan;
	for(int i=0;i<original.size();i++)
	{
	opak_odvratan(original[i],opak,odvratan);
	if(opakodvratan&&opak) tmp.push_back(original[i]);
	if(!opakodvratan&&odvratan) tmp.push_back(original[i]);
	}
		for(int i=0;i<tmp.size();i++)
	{
		for(int j=i+1;j<tmp.size();j++)
		{
			if(tmp[j]==tmp[i])
			{
				for(int l=j;l<tmp.size()-1;l++)
				{
					tmp[l]=tmp[l+1];
				}
			tmp.resize(tmp.size()-1);
			j--;
			}
		}
	}

	return tmp;
}

int main ()
{
	int n(0);
	std::vector<int>a ;
	std::vector<int>b ;
	std::vector<int>x ;
	std::cout <<"Unesite brojeve (0 za prekid unosa): ";
	do
	{
	  std::cin >>n;
	  x.push_back(n);
	}
	while(n!=0);
a=IzdvojiGadne(x,1);
b=IzdvojiGadne(x,0);
std::cout <<"Opaki: ";
for(int i=0;i<a.size()-1;i++)
std::cout <<a[i]<< " ";
std::cout<< std::endl;
std::cout <<"Odvratni: ";
for(int j=0;j<b.size()-1;j++)
	std::cout <<b[j]<<" ";
	return 0;
}