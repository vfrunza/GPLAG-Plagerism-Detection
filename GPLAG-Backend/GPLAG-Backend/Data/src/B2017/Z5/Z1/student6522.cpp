#include <iostream>
#include <cmath>
#include <string>

int main ()
{
    std::string s("SMRBOBUJIJMVMXNHMMJUZBUHIDPUJULUSUHOLBOZUGORXUGILIJIGSBOLHOCULOCULISO");
    for(int i(0); i<s.length(); i++){
        s[i]=360-5*s[i];
        if(s[i]<65)
        while(s[i]<65) s[i]+=26;
        else if(s[i]>90) while(s[i]>90) s[i]-=26;
    }
    std::cout<<s;
	return 0;
}
