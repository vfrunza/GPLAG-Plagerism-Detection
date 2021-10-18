/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

//Kreira maticu sa zadanim brojem kolona i redova
Matrica KreirajMatricu (int br_redova, int br_kolona)
{
   return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica Grbava (int br_redova, int br_kolona)
{
    Matrica m(br_redova);
    for(int i=0; i<br_redova; i++) m.at(i).resize(i+1);
    return m;
}

// Unosi sa tastature matricu sa zadanim brojem redova i kolona i
//vraća je kao rezultat
Matrica UnesiMatricu(int br_redova,int br_kolona)
{
    if (KreirajMatricu(br_redova,br_kolona) == Grbava(br_redova,br_kolona)) throw std::domain_error ("Matrica nije konkretna.");
    auto m(KreirajMatricu(br_redova, br_kolona));
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
        {
            std::cin >> m[i][j];
        }
        std::cout << std::endl;
    return m;
}

int Duzina(int n)
{
   int brojac(0);
   if (n<0) brojac++;
   while (n)
   {
      n/=10;
      brojac++;
   }
   return brojac;
}
int NajvecaSirina(Matrica m)
{
   if(m.size()==0) return 0;
   int max(0);
   for(int i=0; i<=m.size()-1; i++)
   {
      for(int j=0; j<m.at(i).size(); j++)
      {
         if (Duzina(m.at(i).at(j)) > max) max = Duzina(m.at(i).at(j));
      }
   }
   return max;
}

void IspisiMatricu(Matrica m)
{
   for (int i=0; i<=m.size()-1; i++)
   {
      for (int j=0; j<m.at(i).size(); j++) 
      {
         std::cout << std::setw(NajvecaSirina(m)+1) << std::left << std::setw(3) << std::fixed << std::setprecision(0) << " " <<  m.at(i).at(j) ;
      }
      std::cout << std::endl;
   }
}

Matrica Horizontalna (Matrica m)
 {   
     int a, b;
     a = int(m.size());
     b = int(m.at(0).size());
     for(int i=0; i<a; i++)
     {
         for(int j=0; j<b/2; j++)
         {
             int temp = m.at(i).at(j);
             m.at(i).at(j) = m.at(i).at(b-1-j);
             m.at(i).at(b-1-j) = temp;
         }
     }
	return m;
}
Matrica Vertikalna (Matrica m)
{
    int a, b;
     a = int(m.size());
     b = int(m.at(0).size());
     for (int i=0; i<a-1; i++)
     {
         for(int j=0; j<b; j++)
         {
             int temp = m.at(i).at(j);
             m.at(i).at(j) = m.at(a-i-1).at(j);
             m.at(a-i-1).at(j) = temp;
         }
     }
     return m;
}
Matrica Kombinacija(Matrica m)
{
    int a, b;
     a = int(m.size());
     b = int(m.at(0).size());
     for (int i=0; i<a-1; i++)
     {
         for(int j=i; j<b; j++)
         {
             int temp = m.at(i).at(j);
             m.at(i).at(j) = m.at(a-1-i).at(b-j-1);
             m.at(a-1-i).at(b-j-1) = temp;
         }
     }
     return m;
}
Matrica OgledaloMatrica (Matrica m)
{
     int a, b;
     a = int(m.size());
     b = int(m.at(0).size());
     Matrica o((3*a), std::vector<double> (3*b));
     Matrica h((a), std::vector<double> (b));
     Matrica v((a), std::vector<double> (b));
     Matrica hv((a), std::vector<double> (b));
     h = Horizontalna(m);
     v = Vertikalna(m);
     hv = Kombinacija(m);
    for (int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            o.at(i).at(j) = hv.at(i).at(j);
            o.at(i).at(j+2*b) = hv.at(i).at(j);
            o.at(i+2*a).at(j)= hv.at(i).at(j);
            o.at(i+2*a).at(j+2*b) = hv.at(i).at(j);
            o.at(i).at(j+b) = v.at(i).at(j);
            o.at(i+2*a).at(j+b) = v.at(i).at(j);
            o.at(i+a).at(j) = h.at(i).at(j);
            o.at(i+a).at(j+2*b) = h.at(i).at(j);
            o.at(i+a).at(j+b) = m.at(i).at(j);
        }
    }
    return o;
}

int main ()
{
	int n, m;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> n >> m;
	if (m<0 || n<0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	 if (n>0 && m==0) 
	    {
	        std::cout << "Unesite elemente matrice:";
	   	 auto a(UnesiMatricu(n,m));
	   	 std::cout << "Rezultantna matrica: ";
	   	 std::cout << std::endl;
	   	 IspisiMatricu(OgledaloMatrica(a));
	   	 return 0;
	    }
	try
	{
	    if (n==0 && m==0)
	    {
	        std::cout << "Unesite elemente matrice:";
	   		std::cout << std::endl;
	   		std::cout << "Rezultantna matrica:";
	   		std::cout << std::endl;
	   		return 0;
	   	 }
	   	
	   	 std::cout << "Unesite elemente matrice:";
	   	 auto a(UnesiMatricu(n,m));
	   	 std::cout << "Rezultantna matrica: ";
	   	 std::cout << std::endl;
	   	 
	   //	 IspisiMatricu(a);
	   //	 std::cout << std::endl;
	   //	 std::cout << "Horizontalna:" << std::endl;
	   //	 IspisiMatricu(Horizontalna(a));
	   //	 std::cout << std::endl;
	   //	 std::cout << "Vertikalna:" << std::endl;
	   //	 IspisiMatricu(Vertikalna(a));
	   //	 std::cout << std::endl;
	   //	 std::cout << "Kombinacija:" << std::endl;
	   //	 IspisiMatricu(Kombinacija(a));
	   //std::cout << std::endl;
	   
	   IspisiMatricu(OgledaloMatrica(a));
	 }
	 catch (std::domain_error izuzetak)
	 {
	     std::cout << izuzetak.what() << std::endl;
	 }
	return 0;
}