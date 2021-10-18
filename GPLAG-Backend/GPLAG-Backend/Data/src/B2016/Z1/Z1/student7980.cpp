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
#include <algorithm>
#include <set>

using namespace std;

int OpakIliOdvratanIliNijedno(int n)
{
   int brojJedinica = 0;
   int brojDvica = 0;
   int brojNula = 0;
   int m = abs(n);
   do
   {
      switch(m%3)
      {
         case 0: 
            brojNula++;
         break;
         case 1:
            brojJedinica++;
         break;
         case 2:
            brojDvica++;
         break;
      }
      
      m /= 3;
   } while (m > 0);
   
   if(brojNula%2 == 0 && brojJedinica%2 == 0 && brojDvica%2 == 0)
   {
      return 1;
   } else if(brojNula%2 != 0 && brojJedinica%2 != 0 && brojDvica%2 != 0)
   {
      return 2;
   } else
   {
      return 0;
   }
}

bool postoji(vector<int> v, int x)
{
   for(int i = 0; i < v.size(); i++)
   {
      if(x == v[i])
      {
         return true;
      }
   }
   
   return false;
}

vector<int> IzdvojiGadne (vector<int> n, bool x)
{
   vector<int> odvratni;
   vector<int> opaki;
   
   for(int y : n)
   {
      if(OpakIliOdvratanIliNijedno(y) == 1)
      {
         if(!postoji(opaki,y))
         {
            opaki.push_back(y);
         }
      } else if(OpakIliOdvratanIliNijedno(y) == 2)
      {
         if(!postoji(odvratni,y))
         {
            odvratni.push_back(y);
         }
      }
   }
   
   if(x)
   {
      return opaki;
   } else
   {
      return odvratni;
   }
   
}

int main ()
{
   int n;
   vector<int> a, b, c;
   
   cout << "Unesite brojeve (0 za prekid unosa): ";
   while (true)
   {
      cin >> n;
      if (n == 0) break;
      c.push_back(n);
   }
   
   //c = {56, 656, 20, 61, 552, -6384, 223, 8979, 80812, 26937, 240801, 15, 3608, 5904, 56, 656, 20, 61, 552, -6384, 223, 0 };
   a = IzdvojiGadne(c, true);
   b = IzdvojiGadne(c, false);
   
   cout << "Opaki: ";
   for (int i = 0 ; i < a.size(); i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
   cout << "Odvratni: ";
   for (int i = 0; i < b.size(); i++)
   {
     
      cout << b[i] << " ";
   }
	return 0;
}