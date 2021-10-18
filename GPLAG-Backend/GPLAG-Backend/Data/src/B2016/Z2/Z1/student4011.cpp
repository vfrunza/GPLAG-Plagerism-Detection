/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
int main()
{
   /* int niz[] = {21,22,23};
    std::vector<int> b  {12,44,32,22};
    auto p = UvrnutiPresjek(niz,niz+3,b.begin(),b.end());
    for(auto x:p)
        {for(auto y:x) cout<<y<<" ";
    cout<<"\n";}*/
    int a(5);
    decltype(a) b(a);
    b++;
    cout<<a;
    return 0;
}