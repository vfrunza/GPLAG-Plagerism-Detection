/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze (std::string rec, std::vector<std::string> fraze)
{
	for(int j=0;j<fraze.size();j++)
	{
		for(int i=0;i<rec.size();i++)
		{
			if(fraze[j].size()==0)continue;
			if(fraze[j][0]==rec[i])
			{
				bool p=true;
				int k;
				for(k=0;k<fraze[j].size()&&i+k<rec.size();k++)			//gleda da li se rijec nalazi u stringu
				{
					if(fraze[j][k]!=rec[i+k])
					{
						p=false;
						break;
					}
				}
				if(k+i==rec.size()&&k<fraze[j].size()) p=false;
				if(p)
				{														//ako da, obrce je
					for( k=i;k<fraze[j].size()+i;k++)
					{
						rec[k]=fraze[j][fraze[j].size()+i-k-1];
					}
				}
			}
		}
	}
	return rec;
}

std::string IzmijeniUPigLatin (std::string rec, std::vector<std::string> fraze)
{
	if(fraze.size()!=0)
	for(int i=0;i<rec.size();i++)
	{
		for(int j=0;j<fraze.size();j++)
		{
			for(int l=0;l<fraze[j].size();l++) if(fraze[j][l]<'A'||fraze[j][l]>'z'||(fraze[j][l]>'Z'&&fraze[j][l]<'a')) throw std::domain_error("Nekorektan izbor rijeci"); //provjerava ispravnost
			if(fraze[j].size()==0)continue;
			if(fraze[j][0]==rec[i])
			{
				bool p=true;
				int k;
				if(i!=0) if((rec[i-1]>='A'&&rec[i-1]<='Z')||(rec[i-1]>='a'&&rec[i-1]<='z')) p=false;   //ako nije na pocetku rijeci ne gleda je
				for(k=0;k<fraze[j].size()&&i+k<rec.size()&&p;k++)
				{
					if(fraze[j][k]!=rec[i+k])
					{																				//gleda da li se rijec nalazi u stringu
						p=false;
						break;
					}
				}
				if(k+i==rec.size()&&k<fraze[j].size()) p=false;										//ako je dosao do kraja stringa ali ne i do kraja rijeci ne treba mijenjati
				else if((rec[i+k]>='A'&&rec[i+k]<='Z')||(rec[i+k]>='a'&&rec[i+k]<='z')) p=false;	//ako nije dosao do kraja rijeci u stringu ne treba mijenjati
				if(p)
				{
					for(k=0;k<fraze[j].size()-1;k++)
					{
						rec[i+k]=fraze[j][k+1];
					}
					rec[i+k]=fraze[j][0];
					rec.insert(rec.begin()+i+k+1,'y');
					rec.insert(rec.begin()+i+k+1,'a');
					i+=2;
				}
			}
		}
	}
	else
	for(int i=0;i<rec.size();i++)
	{
		std::string r;
		int k=i;
		while((rec[k]>='A'&&rec[k]<='Z')||(rec[k]>='a'&&rec[k]<='z'))
		{
			r.push_back(rec[k]);
			k++;
			if(k>=rec.size()) break;
		}
		if(r.size()!=0)
		{
			rec[k-1]=r[0];
			for(;i<k-1;i++)
			{
				rec[i]=r[r.size()-k+i+1];
			}
			rec.insert(rec.begin()+i+1,'y');
			rec.insert(rec.begin()+i+1,'a');
			i+=3;
		}
	}
	return rec;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string x;
	std::getline(std::cin, x);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	char z;
	for(;;)
	{
		if((z=getchar())=='\n') break;
		std::string s;
		std::getline(std::cin, s);
		s.insert(s.begin(),z); 
		fraze.push_back(s);
	}
	std::string zn;
	try{
	zn=IzmijeniUPigLatin(x,fraze);
	std::cout << "Recenica nakon PigLatin transformacije: " << zn;
	}
	catch(std::domain_error greska)
	{
		std::cout << "Izuzetak: " << greska.what();
	}
	zn=ObrniFraze(x,fraze);
	std::cout << "\nRecenica nakon obrtanja fraza: " << zn;
	return 0;
}