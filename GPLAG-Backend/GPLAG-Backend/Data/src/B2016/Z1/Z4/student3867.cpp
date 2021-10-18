//s:~PROGRAMMERS DON'T SEE WOMEN AS objects.
//s:~THEY CONSIDER EACH TO BE IN A class OF HER OWN.

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

std::string ObrniFraze(std::string recenica, std::vector<std::string> frase)
{
	std::string rec{recenica};
	if(frase.size()==0)
		return rec;
	for(int i=0;i<frase.size();i++)
	{
		int count{0};
		bool flag{false};
		int begin_posit,end_posit;
		for(int j=0;j<rec.length();j++)
		{
//izuzetak za "frazu" duzine 1
			if(frase[i].length()==1)
				break;
//provjera pocetka fraze u recenici
			if(flag==false && rec.at(j)==frase[i].at(count))
			{
				flag=true;
				begin_posit=j;
				count++;
			}
	//provjera nastavka na pocetak u recenici za istu frazu
			else if(flag==true && rec.at(j)==frase[i].at(count))
			{
				end_posit=j;
				count++;
		//provjera kraza fraze
				if(frase[i].length()==count)
				{
					flag=false;
					count=0;
					int position{0};
			//obrtanje rijeci u recenici koja odgovara frazi
					for(int k=begin_posit;k<=(begin_posit+(end_posit-begin_posit)/2);k++)
					{
						char znak{rec.at(k)};
						rec.at(k)=rec.at(end_posit-position);
					    rec.at(end_posit-position)=znak;
					    position++;
					}
				}
			}
	//provjera pocetka istih slova jedno do drugog, i vracanje na novi pocetak
			else
			{
				if(j>0 && rec.at(j)==rec.at(j-1) && flag==true)
				{
					begin_posit=j;
					count=1;
				}
	//nema podudaranja
				else
				{
					count=0;
					flag=false;
				}
			}
		}
	}
	return rec;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> frase)
{
	std::string rec{recenica};
	if(frase.size()==0)
	{
		bool faza{false};
		int begin_save;
		for(int i=0;i<rec.size();i++)
		{
			if(faza==false && ((rec.at(i)>='A' && rec.at(i)<='Z') || (rec.at(i)>='a' && rec.at(i)<='z')))
			{
				begin_save=i;
				faza=true;
			}
			else if(faza==true && (rec.at(i)<'A' || (rec.at(i)>'Z' && rec.at(i)<'a') || rec.at(i)>'z'))
			{
				reform:
				int pos{i};
				faza=false;
				int fo;
				char znak{rec.at(begin_save)};
			//pomjeranje svih slova za jedno mjesto unazad(osim prvo naravno)
				for(fo=begin_save;fo<pos-1;fo++)
					rec.at(fo)=rec.at(fo+1);
			//prvo slovo ide na kraj
				rec.at(fo)=znak;
				rec.resize(rec.length()+2);
			//pomjeranje svih karaktera od mjesta izmjene za dva mjesta
				for(int teta=rec.length()-1;teta>=pos+2;teta--)
					rec.at(teta)=rec.at(teta-2);
				rec.at(fo+1)='a';
				rec.at(fo+2)='y';
				i+=2;
			}
			else if(faza==true && ((rec.at(i)>='A' && rec.at(i)<='Z') || (rec.at(i)>='a' && rec.at(i)<='z')))
			{
			//zadnji karakter u recenici
				if(i==rec.size()-1)
					goto reform;
				continue;
			}
			else faza=false;
		}
		return rec;
	}
//test alfabetskog formata fraza
	for(int i=0;i<frase.size();i++)
		for(int j=0;j<frase[i].length();j++)
			if((frase[i].at(j)<'A' || (frase[i].at(j)>'Z' && frase[i].at(j)<'a') || frase[i].at(j)>'z'))
				throw std::domain_error("Nekorektan izbor rijeci");
	std::vector<std::vector<int>> position(1);
	for(int i=0;i<frase.size();i++)
	{
		int count{0};
		bool morph{false};
		int begin_save;
		for(int j=0;j<rec.length();j++)
		{
//pocetak fraze u recenici
			if(morph==false && rec.at(j)==frase[i].at(count))
			{
		//izuzetak za "frazu" duzine 1
				if(frase[i].length()==1 && (j==rec.size()-1 || ((rec.at(j+1)<'A' || (rec.at(j+1)>'Z' && rec.at(j+1)<'a') || rec.at(j+1)>'z') && 
				(rec.at(j-1)<'A' || (rec.at(j-1)>'Z' && rec.at(j-1)<'a') || rec.at(j-1)>'z'))))
				{
					rec.resize(rec.length()+2);
			//pomjeranje svih karaktera od mjesta izmjene za dva mjesta
					for(int teta=rec.length()-1;teta>=j+2;teta--)
						rec.at(teta)=rec.at(teta-2);
					rec.at(j+1)='a';
					rec.at(j+2)='y';
					count=0;
			//povecanje svake koordinate od izmjene za (+2) zbog izmjene
					for(int red=0;red<position.size();red++)
					{
						for(int x=0;x<position[red].size();x++)
							if(position[red][x]>j)
								position[red][x]+=2;
					}
					morph=false;
					continue;
				}
				if(j>0)
				{
					if((rec.at(j-1)<'A' || (rec.at(j-1)>'Z' && rec.at(j-1)<'a') || rec.at(j-1)>'z'))
					{
						morph=true;
						begin_save=j;
						count++;
					}
				}
				else
				{
					morph=true;
					begin_save=j;
					count++;
				}
			}
	//nastavak na pocetak fraze u recenici
			else if(morph==true && rec.at(j)==frase[i].at(count))
			{
				count++;
		//kraj fraze i podudaranje
				if(frase[i].length()==count)
				{
					if(j==rec.size()-1)
					{
			//zadnji karakter u recenici
						position[position.size()-1].push_back(begin_save);
						position[position.size()-1].push_back(j);
						position.resize(position.size()+1);
					}
			//prekid rijeci sa nealfabetskim karakterom
					else if((rec.at(j+1)<'A' || (rec.at(j+1)>'Z' && rec.at(j+1)<'a') || rec.at(j+1)>'z'))
					{
						morph=false;
						count=0;
				//postavljanje u matricu "koordinata" pocetka i kraja fraze u recenici
						position[position.size()-1].push_back(begin_save);
						position[position.size()-1].push_back(j);
						position.resize(position.size()+1);
					}
					else
					{
						count=0;
						morph=false;
					}
				}
			}
			else
			{
	//nema podudaranja
				count=0;
				morph=false;
			}
		}
	}
//brisanje praznih redova matrice u slucaju pogresnog sirenja
	do
		position.resize(position.size()-1);
	while(position[position.size()-1].size()==0);
	int temp,prom;
//sortiranje "koordinata" matrice od manjeg ka vecem

//sortira se da bi se lakse kretalo po recenici i islo redom tokom mijenjanja u pig latin
	for(int i=0;i<position.size()-1;i++)
	{
		int min=i;
		for(int j=i+1;j<position.size();j++)
			if(position[j][0]<position[min][0])
				min=j;
		temp=position[i][0];
		prom=position[i][1];
		position[i][0]=position[min][0];
		position[i][1]=position[min][1];
		position[min][0]=temp;
		position[min][1]=prom;
	}
//promjena u piglatin
	int begin{0};
	do
	{
		char znak{rec.at(position[begin][0])};
		int fo;
//pomjeranje svih slova za jedno mjesto unazad(osim prvo naravno)
		for(fo=position[begin][0];fo<position[begin][1];fo++)
			rec.at(fo)=rec.at(fo+1);
//prvo slovo ide na kraj
		rec.at(fo)=znak;
//prosirenje za "ay"
		rec.resize(rec.length()+2);
//pomjeranje svih karaktera od mjesta izmjene za dva mjesta
		for(int teta=rec.length()-1;teta>=fo+2;teta--)
			rec.at(teta)=rec.at(teta-2);
		rec.at(fo+1)='a';
		rec.at(fo+2)='y';
		begin++;
//povecanje svake koordinate od izmjene za (+2) zbog izmjene
		for(int red=begin;red<position.size();red++)
			for(int x=0;x<position[red].size();x++)
				position[red][x]+=2;
	}while(begin!=position.size());
	return rec;
}

int main()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string novi;
//unos fraza sa zavrsetkom '\n'
	do
	{
		std::getline(std::cin,novi);
		if(novi.length()!=0)
			fraze.push_back(novi);
	}while(novi.length()!=0);
//try za piglatin test nepravilan format	
	try
	{
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::string pigey{IzmijeniUPigLatin(recenica,fraze)};
		for(char c:pigey)
			std::cout<<c;
		std::cout<<std::endl;
	}
	catch(std::domain_error alfabet)
	{
		std::cout<<"Izuzetak: "<<alfabet.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string obrnuti{ObrniFraze(recenica,fraze)};
	for(char c:obrnuti)
		std::cout<<c;
	return 0;
}