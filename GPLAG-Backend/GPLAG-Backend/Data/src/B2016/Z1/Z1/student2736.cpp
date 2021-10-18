/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>



std::vector<int> IzdvojiGadne(std::vector<int> v,bool b)
{
	std::vector<int> opaki,odvratni;
	int var,n,br0(0),br1(0),br2(0),br(0);
	
	for(int i=0;i<v.size();i++)
    {

        for(int j=i+1;j<v.size()-1;j++)
        {
            if(v[j]==v[i])
            {
                v.erase(v.begin()+j);
            	j--;
            }	
        }
    }
	
	for(int i=0;i<v.size();i++)
	{
		
		for(int j=0;j<opaki.size();j++)
			{
				if(v[i]==opaki[j])
					br++;
			}
		for(int k=0;k<odvratni.size();k++)
			{
				if(v[i]==odvratni[k])
					br++;
			}	
		if((v[0]!=0 && v[i]==0) || br>0)
			continue;
		else if(v[0]==0)
			odvratni.push_back(v[0]);
		else
		{
		n=v[i];
		while(n!=0)
		{
			var=fabs(n%3);
			if(var==0) br0++;
			if(var==1) br1++;
			if(var==2) br2++;
			n/=3;
		}
		if((br0==0 && br1==0) || (br1==0 && br2==0) || (br0==0 && br2==0))
			{
				if(br0%2!=0 || br1%2!=0 || br2%2!=0)
					odvratni.push_back(v[i]);
				else if(br0%2==0 || br1%2==0 || br2%2==0)
					opaki.push_back(v[i]);	
			}
		else if(br0==0)
		{
			if(br1%2==0 && br2%2==0)
				opaki.push_back(v[i]);
			 if(br1%2!=0 && br2%2!=0)
				odvratni.push_back(v[i]);
		}
		else if(br1==0)
		{
			if(br0%2==0 && br2%2==0)
				opaki.push_back(v[i]);
			else if(br0%2!=0 && br2%2!=0)
				odvratni.push_back(v[i]);
		}
		else if(br2==0)
		{
			if(br1%2==0 && br0%2==0)
				opaki.push_back(v[i]);
			else if(br1%2!=0 && br0%2!=0)
				odvratni.push_back(v[i]);
		}		
		else
		{
			if(br1%2==0 && br2%2==0 && br0%2==0)
				opaki.push_back(v[i]);
			else if(br1%2!=0 && br2%2!=0 && br0%2!=0)
				odvratni.push_back(v[i]);
		}
		}
		br=0;
		br0=0;
		br1=0;
		br2=0;
	}
	
	if(b)
		return opaki;
		
	return odvratni;
}


int main ()
{
	std::vector<int> v,opaki,odvratni;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
   do
   {
      std::cin>>broj;
      v.push_back(broj);
      if(broj==0) break;
        std::cin.clear();
        std::cin.ignore(100,' ');
   }while(broj!=0);
   
   opaki=(IzdvojiGadne(v,true));
   odvratni=(IzdvojiGadne(v,false));
   
   std::cout<<"Opaki: ";
   for(int i=0;i<opaki.size();i++)
      std::cout<<opaki[i]<<" ";
   
   std::cout<<std::endl;   
      
   std::cout<<"Odvratni: ";   
   for(int i=0;i<odvratni.size();i++)
      std::cout<<odvratni[i]<<" ";
	return 0;
}