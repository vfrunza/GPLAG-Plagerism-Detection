/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a) {
	std::vector<int> novi;
	for(int i=0;i<v.size();i++)
	{
		int brojNula=0,brojJedinica=0,brojDvica=0;
		int x=v[i];
		while(x!=0)
		{
			int p=x%3;
			if(p==0 ) brojNula++;
			else if(p==1 || p==-1) brojJedinica++;
			else brojDvica++;
			x=x/3;
		}
		if(a)
		{
			
			//sad izdvoji opake
			bool postoji=false;
			if(brojNula%2==0 && brojJedinica%2==0 && brojDvica%2==0)
			{
			for(int j=0;j<novi.size();j++)
			{
				if(novi[j]==v[i]) postoji=true;
			}
			if(!postoji && v[i]!=0)
			novi.push_back(v[i]);
			}
		}
		else
		{
			if(brojNula==0) brojNula=1;
			if(brojJedinica==0) brojJedinica=1;
			if(brojDvica==0) brojDvica=1;
			//ovi su odvratni
			bool postoji=false;
			if(brojNula%2==1 && brojJedinica%2==1 && brojDvica%2==1)
			{
				for(int j=0;j<novi.size();j++)
				{
				if(novi[j]==v[i]) postoji=true;
				}
				if(!postoji && v[i]!=0)
				novi.push_back(v[i]);
				postoji=false;
			}
		}
	}
return novi;	
}



int main ()
{
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v1;
	int pom;
	 do{
	
		std::cin>>pom;
		  if (!std::cin.good())
		  {
		  	std::cout<<"nije unesen broj ili je broj veci od maksimalnog dozvoljenog!"<<std::endl;
		  	std::cin.clear();
        	std::cin.ignore();
        	continue;
		  }
		if(pom==0) break;
		
		v1.push_back(pom);
	}while(true);
	std::vector<int> parni;
	std::vector<int> neparni;
	parni=IzdvojiGadne(v1, true);
	neparni=IzdvojiGadne(v1, false);
	std::cout<<"Opaki: ";
    for(int i:parni) {
    std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Odvratni: ";
    for(int j:neparni) {
    std::cout<<j<<" ";
    }
    
	return 0;
}