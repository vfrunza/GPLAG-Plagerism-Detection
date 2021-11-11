#include <iostream>
#include <cmath>

using namespace std;

const float restoranP = 6.80,
	        restoranH = 3.30,
	        restoranC = 5.00,
	        fastFoodP = 8.00,
            fastFoodH = 3.00,
            fastFoodC = 3.90,
            bistroP = 5.30,
	        bistroH = 5.00,
	        bistroC = 6.00;
	            
float cijenaRestoran = 0,
      cijenaFastfood = 0,
      cijenaBistro = 0;

void proracun(char ime);

int main()
{
	float najjeftiniji;
	            
	char tarik, bojan, mirza;
	
	do
	{
	    cout << "Unesite jelo za Tarika: " << endl;
	    cin >> tarik;
	    
	}while(tarik != 'P' && tarik != 'H' && tarik != 'C');
	
	do
	{
	    cout << "Unesite jelo za Bojana: " << endl;
	    cin >> bojan;
	    
	}while(bojan != 'P' && bojan != 'H' && bojan != 'C');
	
	do
	{
	    cout << "Unesite jelo za Mirzu: " << endl;
	    cin >> mirza;
	    
	}while(mirza != 'P' && mirza != 'H' && mirza != 'C');
	
	proracun(tarik);
	proracun(bojan);
	proracun(mirza);
	
	if(cijenaRestoran < cijenaFastfood && cijenaRestoran < cijenaBistro)
	{
	    najjeftiniji = cijenaRestoran;
	    cout << "Najjeftiniji je restoran \"Kod Konja i konjusara\" : " << najjeftiniji << endl;
	}
	else if(cijenaFastfood < cijenaRestoran && cijenaRestoran < cijenaBistro)
	{
	    najjeftiniji = cijenaFastfood;
	    cout << "Najjeftiniji je fast-food \"Trovac\" : " << najjeftiniji << endl;
	}
	else
	{
	    najjeftiniji = cijenaBistro;
	    cout << "Najjeftiniji je bistro \"Lorelai\" : " << najjeftiniji << endl;
	}
	
	if(najjeftiniji < cijenaRestoran)
	{
	    if(tarik == 'P' || bojan == 'P' || mirza == 'P')
	    {
	        //cijenaRestoran -= restoranP;
	        //cijenaRestoran = cijenaRestoran + restoranP - restoranP * 0.1;
	        cijenaRestoran = cijenaRestoran - restoranP * 0.1;
	        
	    }
	    else if(tarik == 'C' || bojan == 'C' || mirza == 'C')
	    {
	        //cijenaRestoran -= restoranC;
	        //cijenaRestoran = cijenaRestoran + restoranC - restoranC * 0.1;
	        cijenaRestoran = cijenaRestoran - restoranC * 0.1;
	    }
	    else
	    {
	        //cijenaRestoran -= restoranH;
	        //cijenaRestoran = cijenaRestoran + restoranH - restoranH * 0.1;
	        cijenaRestoran = cijenaRestoran - restoranH * 0.1;
	    }
	    
	}
	
	if(cijenaRestoran < najjeftiniji)
	{
	    cout << "Sa popustom bi restoran bio najjeftiniji : " << cijenaRestoran << endl;
	}
	
	return 0;
}

void proracun(char ime)
{
    switch(ime)
    {
        case 'P':
            cijenaRestoran += restoranP;
            cijenaFastfood += fastFoodP;
            cijenaBistro += bistroP;
            break;
        case 'H':
            cijenaRestoran += restoranH;
            cijenaFastfood += fastFoodH;
            cijenaBistro += bistroH;
            break;
        case 'C':
            cijenaRestoran += restoranC;
            cijenaFastfood += fastFoodC;
            cijenaBistro += bistroC;
            break;
        default: 
            cout << "Greska!" << endl;
    }
}