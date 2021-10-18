#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>

using namespace std;


template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 p2, Tip2 q1, Tip3 q3, decltype(*q3+0) f (decltype(*p1+0),decltype(*p1+0)), bool k (decltype(*p1+0),decltype(*p1+0)) )

{
    int duzina_bloka=p2-p1;
    sort(p1,p2,k);
    sort(q1,q1+duzina_bloka,k);
    
    auto P1 = p1;
    auto P2 = q1;
    
    while(P1!=p2)
    {

        Tip3 r = find (q3, q3+(p2-p1), f(*P1,*P2));
        if( r == q3+(p2-p1) ) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
        
        int poz1 = P1-p1;
        swap (*(q3+poz1), *(r));
        P1++; P2++;
    }

}



int f (int x, int y)
{
    return -2*x+y;
}


int Broj_PF (int n)
{
    int brojac = 0;
    int z = 2;

    while (z * z <= n){
        
        if (n % z == 0){
           brojac++;
           n/= z;}
           
           else
               z++;
    }
  brojac++;
  return brojac;
}


bool comp (int x, int y)
{
    if(Broj_PF(x) > Broj_PF(y)) return true;
    else if (Broj_PF(x) == Broj_PF(y)) return x>y;
    else false;
}

  


int main()
{
    int n; 
    cout<<"Unesite broj elemenata: ";
    cin>>n;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    cout<<"Unesite elemente prvog vektora: ";
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
   
if(find(v1.begin(),v1.end(),t) == v1.end()) v1.push_back(t);
else i--;
    }


 cout<<"Unesite elemente drugog vektora: ";
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
   
if(find(v2.begin(),v2.end(),t) == v2.end()) v2.push_back(t);
else i--;
    }

    cout<<"Unesite elemente treceg vektora: \n";
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
   
if(find(v3.begin(),v3.end(),t) == v3.end()) v3.push_back(t);
else i--;
    }
   
   
   try{
       SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),f,comp);
   }
   
catch (std::logic_error izuzetak)  
{
    cout << "Izuzetak: " << izuzetak.what() << "\n" ;
    return 0;
}
   
cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
for(int i=0; i<n; i++)
{
    cout << "f(" << v1[i] << ", " << v2[i] << ") = " << v3[i] << "\n";
}
   

 
    return 0;
}