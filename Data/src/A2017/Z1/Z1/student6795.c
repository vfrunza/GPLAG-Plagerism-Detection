#include <stdio.h>

int main() {
	char tarik,bojan,mirza,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	float pkik = 0,pfft = 0,pbll = 0,hkik = 0,hfft = 0,hbll =0,ckik=0,cfft=0,cbll=0;
	
	//CIJENE-------------------------------------
	if (tarik == 'P')
	{
		pkik = pkik + 6.8;
		pfft = pfft + 8;
		pbll = pbll  + 5.3;
	}
	if (tarik == 'H')
	{
		hkik = hkik + 3.3;
		hfft = hfft + 3;
		hbll = hbll + 5;
	}
	if (tarik == 'C')
	{
		ckik = ckik + 5;
		cfft = cfft + 3.9;
		cbll = cbll + 6;
	}
//------------------------------------------------------
if (bojan == 'P')
	{
		pkik = pkik + 6.8;
		pfft = pfft + 8;
		pbll = pbll  + 5.3;
	}
	if (bojan == 'H')
	{
		hkik = hkik + 3.3;
		hfft = hfft + 3;
		hbll = hbll + 5;
	}
	if (bojan == 'C')
	{
		ckik = ckik + 5;
		cfft = cfft + 3.9;
		cbll = cbll + 6;
	}
//---------------------------------------------------------------
if (mirza == 'P')
	{
		pkik = pkik + 6.8;
		pfft = pfft + 8;
		pbll = pbll  + 5.3;
	}
	if (mirza == 'H')
	{
		hkik = hkik + 3.3;
		hfft = hfft + 3;
		hbll = hbll + 5;
	}
	if (mirza == 'C')
	{
		ckik = ckik + 5;
		cfft = cfft + 3.9;
		cbll = cbll + 6;
	}
//---------------------------------------------------------------
	float kik = 0,bll = 0,fft = 0;
	
	kik = pkik + hkik + ckik;
	fft = pfft + hfft + cfft;
	bll = pbll + hbll + cbll;
	
//-------------------------------------------------------
// KOJI JE NAJJEFTINIJI?

if ((kik < fft) && (kik < bll))
		{
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",kik);
			return 0;
		}
		
if ((fft<kik) && (fft <bll))
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fft);	
		}
		
if ((bll<kik) && (bll <fft))
		{
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bll);	
		}
		
		
float kikp = 0;
if ((tarik == 'P') && (bojan == 'P') && (mirza == 'P'))
{
kikp = pkik * 0.9;
if((kikp < bll) && (kikp<fft)){
printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",kikp);
}
}

if ((tarik == 'H') && (bojan == 'H') && (mirza == 'H'))
{
kikp = hkik * 0.9;
if((kikp < bll) && (kikp<fft)){
printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",kikp);
}
}
if ((tarik == 'C') && (bojan == 'C') && (mirza == 'C'))
{
kikp = ckik * 0.9;
if((kikp < bll) && (kikp<fft)){
printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",kikp);
}
}
if ((tarik == 'P') || (bojan == 'P') || (mirza == 'P'))
{
	kikp = pkik * 0.9;
	kikp = kikp + ckik + hkik;
	if((kikp < bll) && (kikp<fft)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",kikp);
}
// V2
if ((tarik == 'C' && bojan == 'C') || (tarik == 'C' && mirza == 'C') || (mirza == 'C' && bojan == 'C'))
{
	kikp = ckik * 0.9;
	kikp = kikp + pkik + hkik;
		if((kikp < bll) && (kikp<fft)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",kikp);
}
}
}
		
		
		
return 0;
}
