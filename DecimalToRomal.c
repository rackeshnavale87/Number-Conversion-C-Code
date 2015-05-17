#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int dec= 5001, temp =0, i =13,j=0,x=0,flag =0;
char *rom[10];
int Iarray[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
char *Rarray[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

while(1)
{

	if(dec < 1)
	{
		if(flag)
		printf("ERROR! Can not convert decimal less than 0 and greater than 1000 to roman number. \nTry again!\n");
		printf("Enter the decimal number : greater than 0 & less than 1999 : ");
		scanf("%d",&dec);
		flag = 1;
		continue;
	}

	if(dec > 1000)
	{
		if(flag)
		printf("ERROR! Can not convert decimal less than 0 and greater than 1000 to roman number. \nTry again!\n");
		printf("Enter the decimal number : greater than 0 & less than 1999 : ");
		scanf("%d",&dec);
		flag = 1;
		continue;
	}
	if(0 < dec < 1000)
		break;

}
printf("Decimal Number : %d\nRoman Number   : ",dec);
	for(i = 12; i>=0 ; i--)
	{
		temp = dec / Iarray[i];
		dec = dec % Iarray[i];
		if(temp > 0)
		{
			rom[j]=Rarray[i];
			j++;
		}
	}

for(x = 0 ; x< j; x++)
printf("%s",rom[x]);
printf("\n");

return 0;
}
