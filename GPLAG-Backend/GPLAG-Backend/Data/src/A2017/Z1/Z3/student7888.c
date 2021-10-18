#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void unesi (char niz[], int velicina)	{
	char znak = getchar ();
	
		if (znak == '\n') znak=getchar();
			int i=0;
	
	while (i<velicina-1 && znak != '\n')	{
			niz [i] = znak;
			i++;
			znak = getchar();
	
		
	}

	niz[i] = '\0';
}

int main() {
	int option,accountCounter=0,passError=0,blocked[100]={0},accN,accountNum[100],phone[100],amount,intAmount[100],password[100],repassword;
    char name[100][100],address[100][100];
    while(1)
    {
        printf("Welcome to our bank\n1.New account\n2.Operations\n3.Exit\nSelection: ");
        scanf("%d",&option);
        if(option==1)
        {
            if(accountCounter<100)
            {
                printf("Name: ");
                unesi(name[accountCounter],100);
                printf("Address: ");
                unesi(address[accountCounter],100);
                printf("Phone: ");
                scanf("%d",&phone[accountCounter]);
                printf("Inital Amount: ");
                scanf("%d",&intAmount[accountCounter]);
                printf("Password: ");
                scanf("%d",&password[accountCounter]);
                while(1)
                {
                    printf("Re-type Password: ");
                    scanf("%d",&repassword);
                    if(repassword!=password[accountCounter])
                        printf("Passwords do not match.\n");
                    else
                        break;
                }
                printf("Password successfully created.\n");
                accountNum[accountCounter]=accountCounter+1;
                printf("Account number: %d\n",accountNum[accountCounter]);
                accountCounter++;
            }
        }
        else if(option==2)
        {
            printf("Enter your account number: ");
            scanf("%d",&accN);
            if(blocked[accN-1]==1)
            {
                printf("Account blocked.\n");
                    goto block;
            }
            while(passError<3)
            {
                printf("Enter password: ");
                scanf("%d",&repassword);
                if(repassword==password[accN-1])
                {
                    break;
                }
                else
                {
                    printf("Wrong password.\n");
                    passError++;
                }
            }
            if(passError==3)
            {
                printf("Account blocked.\n");
                blocked[accN-1]=1;
                goto block;
            }
            while(1)
            {
                printf("\n1.Change password\n2.Deposit\n3.Withdraw\n4.Print\n5.Exit\nSelection: ");
                scanf("%d",&option);
                if(option==1)
                {
                    printf("Enter new password: ");
                    scanf("%d",&password[accN-1]);
                    while(1)
                    {
                        printf("Re-type Password: ");
                        scanf("%d",&repassword);
                        if(repassword!=password[accN-1])
                            printf("Passwords do not match.\n");
                        else
                            break;
                    }
                    printf("Password changed");
                }
                else if(option==2)
                {
                    printf("Amount: ");
                    scanf("%d",&amount);
                    intAmount[accN-1]+=amount;
                    printf("Operation Successful");
                }
                else if(option==3)
                {
                    printf("Amount: ");
                    scanf("%d",&amount);
                    if(intAmount[accN-1]>=amount)
                    {
                        intAmount[accN-1]-=amount;
                        printf("Operation Successful");
                    }
                    else
                        printf("Not enough money on account.");
                    }
                else if(option==4)
                {
                    printf("Name: %s\nAddress: %s\nPhone: %d\nAmount: %d\n",name[accN-1],address[accN-1],phone[accN-1],intAmount[accN-1]);
                }
                else if(option==5)
                    break;
            }
        }
        block:
        if(option==3)
        {
            printf("Exiting...");
            break;
        }

    }
    return 0;
}