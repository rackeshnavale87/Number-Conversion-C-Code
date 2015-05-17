#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//####################	pow function in c  ####################	
int power(int x, unsigned int y)
{
	if( y == 0)
		return 1;
	else if (y%2 == 0)
		return power(x, y/2)*power(x, y/2);
	else
		return x*power(x, y/2)*power(x, y/2);
}

//####################	Binary to Decimal conversion  //####################	
void BinToDec()
{
	char bin[20];
	int i = 0, j=0, itemp=0, len = 0,x=2,y=0, res=0, dec = 0;

	printf("Enter binary number: ");
	scanf("%s",bin);

	for(len = 0; bin[i] != '\0';len++)
	{
		i++;
	}
	for(j=len-1;j>=0;j--)
	{
		res =1;
		y = (len-j-1);
		if(bin[j]=='0')
		{
			for(i = 0; i < y; i++)
			{
				if(y==0)
					res = 1;
				else
					res = res*2;
			}
			dec = (dec + (0 * res));
		}
		if(bin[j]=='1')
		{
			for(i = 0; i < y; i++)
			{
				if(y==0)
					res = 1;
				else
					res = res*2;
			}
			dec = (dec + (1 * res));
		}
	}
	printf("Decimal number of [%s] is [",bin);
	printf("decimal = %d",dec);
	printf("]\n###############################");
printf("\n");
}

//####################	Decimal to Hex conversion   //####################	
void DecToHex()
{
	int value = 0;
	int Q;
	int i = 0, temp,j=0;
	char hexadecimalNo[100];

	printf("Enter Decimal number: ");
	scanf("%d",&value);

	Q = value;
	while(Q!=0)
	{
	    temp = Q % 16;
    
	    if(temp < 10)
	    {
	        temp = temp + 48;
	    }
	    else 
	    {
	        temp = temp + 55;
	    }
	    hexadecimalNo[i++] = temp;
	    Q = Q /16;    
	}
	printf("Hexadecimal(32-bit) number of [%d] is [",value);
	for(j=i;j>=0;j--)
	{
	    printf("%c",hexadecimalNo[j]);
	}
	printf("]\n###############################");
printf("\n");
}


//####################	Hex to decimal conversion   //####################	
void HexToDec()
{
	char hex[9], *hexString;
	int length = 0, i=0;
	const int base = 16;
	unsigned long decimalNumber = 0;

	printf("Enter Hexadecimal(32-bit) Number : ");
	scanf("%s", hex);
	for (hexString = hex; *hexString != '\0'; hexString++)
	{
		length++;
	}

	hexString = hex;
	for (i = 0; *hexString != '\0' && i < length; i++, hexString++)
	{
		if (*hexString >= 48 && *hexString <= 57)   // is *hexString Between 0-9
			{decimalNumber += (((int)(*hexString)) - 48) * power(base, length - i - 1);}
		else if ((*hexString >= 65 && *hexString <= 70))   // is *hexString Between A-F
			{decimalNumber += (((int)(*hexString)) - 55) * power(base, length - i - 1);}
		else if (*hexString >= 97 && *hexString <= 102)   // is *hexString Between a-f
			{decimalNumber += (((int)(*hexString)) - 87) * power(base, length - i - 1);}
		else
			{printf(" Invalid Hexadecimal(32-bit) Number \n");return;}
	}

	printf("Decimal Number of [%s] is [%lu]",hex, decimalNumber);
	printf("\n###############################\n");
}



//####################	Decimal to Binary conversion   //####################	
void DecToBin()
{
	int value = 0;
	int Q;
	int i = 0, temp,j=0;
	char bindecimalNo[100];

	printf("Enter Decimal value: ");
	scanf("%d",&value);

	Q = value;
	while(Q!=0)
	{
	    temp = Q % 2;
    	    temp = temp + 48;
	    bindecimalNo[i++] = temp;
	    Q = Q /2;    
	}
	printf("Binary value of [%d] is [",value);
	for(j=i-1;j>=0;j--)
	{
	    printf("%c",bindecimalNo[j]);
	}
	printf("]\n###############################");
printf("\n");
}

//####################	Main function //####################	
int main()
{

        int option;
        while(1)
        {
	        printf("\n----------------------------------------------");
	        printf("\n######## Number conversion operations ########");
	        printf("\n----------------------------------------------\n");
	        printf("1 - Decimal to Hexadecimal(32-bit)\n");
	        printf("2 - Decimal to Binary\n");
	        printf("3 - Hexadecimal(32-bit) to Decimal\n");
	        printf("4 - Binary to Decimal\n");
	        printf("5 - Exit\n");
	        printf("\n-------------------------------");
            printf("\nEnter your choice :- ");
            scanf("%d", &option);
            switch (option)
            {
            case 1:    
                DecToHex();
                break;
            case 2:    
                DecToBin();
                break;
            case 3:    
                HexToDec();
                break;
            case 4:    
                BinToDec();
                break;
            case 5:
                exit(0);
            default :     
                printf("Error! Wrong choice, Please enter correct choice");
                break;
            }	    
        }
	return 0;
}
