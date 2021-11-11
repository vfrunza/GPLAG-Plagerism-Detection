#include <stdio.h>

int main(){
	int i,ic=0,ip=0,ib=0,iv=0,is=0,Ic=0,Ib=0,Is=0,Iv=0,Ip=0,U;
	char d;
	printf("Unesite vozila: ");
	for(i=1;i<2000000;i++){
		d=getchar();
		if(d=='k' || d=='K') break;
		else if(d=='c' || d=='C'){
			Ic++;
			if(ic==0) ic=i;
		}
		else if(d=='b' || d=='B'){
			Ib++;
			if(ib==0) ib=i;
		}
		else if(d=='s' || d=='S'){
			Is++;
			if(is==0) is=i;
		}
		else if(d=='v' || d=='V'){ 
			Iv++;
			if(iv==0) iv=i;
		}
		else if(d=='p' || d=='P'){
			 Ip++;
			 if(ip==0) ip=i;
		}
		else if(d!='c' && d!='C' && d!='b' && d!='B' && d!='s' && d!='S' && d!='v' && d!='V' && d!='p' && d!='P')
			printf("Neispravan unos\n");
	}
	U=Ic+Ib+Is+Iv+Ip;
	printf("Ukupno evidentirano %d vozila.\n",U);
	if(U==0)
		printf("Najpopularnija boja je crna (0.00%).");
	else 
	{
		if((Ic>Ib && Ic>Is && Ic>Iv && Ic> Ip) || ( Ic==Ib && Ic>Is && Ic>Iv && Ic> Ip && ic<ib) || (Ic>Ib && Ic==Is && Ic>Iv && Ic> Ip && ic<is) || (Ic>Ib && Ic>Is && Ic==Iv && Ic>Ip && ic<iv) || (Ic>Ib && Ic>Is && Ic>Iv && Ic==Ip && ic<ip) || (Ic==Ib && Ic==Is && Ic>Iv && Ic> Ip && ic<ib && ic<is) || (Ic==Ib && Ic>Is && Ic==Iv && Ic>Ip && ic<ib && ic<iv) || (Ic==Ib && Ic>Is && Ic>Iv && Ic==Ip && ic<ib && ic<ip) || (Ic>Ib && Ic==Is && Ic==Iv && Ic>Ip && ic<is && ic<iv) || (Ic>Ib && Ic==Is && Ic>Iv && Ic==Ip && ic<is && ic<ip) || (Ic>Ib && Ic>Is && Ic==Iv && Ic==Ip && ic<iv && ic<ip) || (Ic==Ib && Ic==Is && Ic==Iv && Ic>Ip && ic<ib && ic<is && ic<iv) || (Ic==Ib && Ic==Is && Ic>Iv && Ic==Ip && ic<ib && ic<is && ic<ip) || (Ic==Ib && Ic>Is && Ic==Iv && Ic==Ip && ic<ib && ic<iv && ic<ip) || (Ic>Ib && Ic==Is && Ic==Iv && Ic==Ip && ic<is && ic<iv && ic<ip) || (Ic==Ib && Ic==Is && Ic==Iv && Ic==Ip && ic<ib && ic<is && ic<iv && ic<ip))
			printf("Najpopularnija boja je crna (%.2f%%).",(100.0*Ic)/U);
		else if((Ib>Ic && Ib>Is && Ib>Iv && Ib>Ip) || (Ib==Ic && Ib>Is && Ib>Iv && Ib>Ip && ib<ic) || (Ib>Ic && Ib==Is && Ib>Iv && Ib>Ip && ib<is) || (Ib>Ic && Ib>Is && Ib==Iv && Ib>Ip && ib<iv) || (Ib>Ic && Ib>Is && Ib>Iv && Ib==Ip && ib<ip) || (Ib==Ic && Ib==Is && Ib>Iv && Ib>Ip && ib<ic && ib<is) || (Ib==Ic && Ib>Is && Ib==Iv && Ib>Ip && ib<ic && ib<iv) || (Ib==Ic && Ib>Is && Ib>Iv && Ib==Ip && ib<ic && ib<ip) || (Ib>Ic && Ib==Is && Ib==Iv && Ib>Ip && ib<is && ib<iv) || (Ib>Ic && Ib==Is && Ib>Iv && Ib==Ip && ib<is && ib<ip) || (Ib>Ic && Ib>Is && Ib==Iv && Ib==Ip && ib<iv && ib<ip) || (Ib==Ic && Ib==Is && Ib==Iv && Ib>Ip && ib<ic && ib<is && ib<iv) || (Ib==Ic && Ib==Is && Ib>Iv && Ib==Ip && ib<ic && ib<is && ib<ip) || (Ib==Ic && Ib>Is && Ib==Iv && Ib==Ip && ib<ic && ib<iv && ib<ip) || (Ib>Ic && Ib==Is && Ib==Iv && Ib==Ip && ib<is && ib<iv && ib<ip) || (Ib==Ic && Ib==Is && Ib==Iv && Ib==Ip && ib<ic && ib<is && ib<iv && ib<ip))
			printf("Najpopularnija boja je bijela (%.2f%%).",(100.0*Ib)/U);
		else if((Is>Ib && Is>Ic && Is>Iv && Is>Ip) || (Is==Ib && Is>Ic && Is>Iv && Is>Ip && is<ib) || (Is>Ib && Is==Ic && Is>Iv && Is>Ip && is<ic) || (Is>Ib && Is>Ic && Is==Iv && Is>Ip && is<iv) || (Is>Ib && Is>Ic && Is>Iv && Is==Ip && is<ip) || (Is==Ib && Is==Ic && Is>Iv && Is>Ip && is<ib && is<ic) || (Is==Ib && Is>Ic && Is==Iv && Is>Ip && is<ib && is<iv) || (Is==Ib && Is>Ic && Is>Iv && Is==Ip && is<ib && is<ip) || (Is>Ib && Is==Ic && Is==Iv && Is>Ip && is<ic && is<iv) || (Is>Ib && Is==Ic && Is>Iv && Is==Ip && is<ic && is<ip) || (Is>Ib && Is>Ic && Is==Iv && Is==Ip && is<iv && is<ip) || (Is==Ib && Is==Ic && Is==Iv && Is>Ip && is<ib && is<ic && is<iv) || (Is==Ib && Is==Ic && Is>Iv && Is==Ip && is<ib && is<ic && is<ip) || (Is==Ib && Is>Ic && Is==Iv && Is==Ip && is<ib && is<iv && is<ip) || (Is>Ib && Is==Ic && Is==Iv && Is==Ip && is<ic && is<iv && is<ip) || (Is==Ib && Is==Ic && Is==Iv && Is==Ip && is<ib && is<ic && is<iv && is<ip)) 
			printf("Najpopularnija boja je siva (%.2f%%).",(100.0*Is)/U);
		else if((Iv>Is && Iv>Ic && Iv>Ib && Iv>Ip) || (Iv==Is && Iv>Ic && Iv>Ib && Iv>Ip && iv<is) || (Iv>Is && Iv==Ic && Iv>Ib && Iv>Ip && iv<ic) || (Iv>Is && Iv>Ic && Iv==Ib && Iv>Ip && iv<ib) || (Iv>Is && Iv>Ic && Iv>Ib && Iv==Ip && iv<ip) || (Iv==Is && Iv==Ic && Iv>Ib && Iv>Ip && iv<is && iv<ic) || (Iv==Is && Iv>Ic && Iv==Ib && Iv>Ip && iv<is && iv<ib) || (Iv==Is && Iv>Ic && Iv>Ib && Iv==Ip && iv<is && iv<ip) || (Iv>Is && Iv==Ic && Iv==Ib && Iv>Ip && iv<ic && iv<ib) || (Iv>Is && Iv==Ic && Iv>Ib && Iv==Ip && iv<ic && iv<ip) || (Iv>Is && Iv>Ic && Iv==Ib && Iv==Ip && iv<ib && iv<ip) || (Iv==Is && Iv==Ic && Iv==Ib && Iv>Ip && iv<is && iv<ic && iv<ib) || (Iv==Is && Iv==Ic && Iv>Ib && Iv==Ip && iv<is && iv<ic && iv<ip) || (Iv==Is && Iv>Ic && Iv==Ib && Iv==Ip && iv<is && iv<ib && iv<ip) || (Iv>Is && Iv==Ic && Iv==Ib && Iv==Ip && iv<ic && iv<ib && iv<ip) || (Iv==Is && Iv==Ic && Iv==Ib && Iv==Ip && iv<is && iv<ic && iv<ib && iv<ip))
			printf("Najpopularnija boja je crvena (%.2f%%).",(100.0*Iv)/U);
		else if((Ip>Iv && Ip>Ic && Ip>Is && Ip>Ib) || (Ip==Iv && Ip>Ic && Ip>Is && Ip>Ib && ip<iv) || (Ip>Iv && Ip==Ic && Ip>Is && Ip>Ib && ip<ic) || (Ip>Iv && Ip>Ic && Ip==Is && Ip>Ib && ip<is) || (Ip>Iv && Ip>Ic && Ip>Is && Ip==Ib && ip<ib) || (Ip==Iv && Ip==Ic && Ip>Is && Ip>Ib && ip<iv && ip<ic) || (Ip==Iv && Ip>Ic && Ip==Is && Ip>Ib && ip<iv && ip<is) || (Ip==Iv && Ip>Ic && Ip>Is && Ip==Ib && ip<iv && ip<ib) || (Ip>Iv && Ip==Ic && Ip==Is && Ip>Ib && ip<ic && ip<is) || (Ip>Iv && Ip==Ic && Ip>Is && Ip==Ib && ip<ic && ip<ib) || (Ip>Iv && Ip>Ic && Ip==Is && Ip==Ib && ip<is && ip<ib) || (Ip==Iv && Ip==Ic && Ip==Is && Ip>Ib && ip<iv && ip<ic && ip<is) || (Ip==Iv && Ip==Ic && Ip>Is && Ip==Ib && ip<iv && ip<ic && ip<ib) || (Ip==Iv && Ip>Ic && Ip==Is && Ip==Ib && ip<iv && ip<is && ip<ib) || (Ip>Iv && Ip==Ic && Ip==Is && Ip==Ib && ip<ic && ip<is && ip<ib) || (Ip==Iv && Ip==Ic && Ip==Is && Ip==Ib && ip<iv && ip<ic && ip<is && ip<ib)) 
			printf("Najpopularnija boja je plava (%.2f%%).",(100.0*Ip)/U);
	}
	return 0;
}