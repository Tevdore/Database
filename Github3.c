//Description 
//Make a structure with parameters - mean, median, stDeviation, max, min.
//Make a file with name "nums.txt" an write numbers, for example: "12,790, -986, 56, 6.89, 12.9008, 45, 567, 78, 17"
//Read those numbers from a file with functions fopen(),open(),OpenFile() and sort them in an ascending order
//find mean, median, stDeviation, max, min and write them in relevant structure members
//1.fwrite is used to write char array symbols in a file.
//2.fread is used to read from a file
//3.Then those numbers are divided in a 2D char array
//4.Sorting in an ascending order
//5.Finding mean, median, min, max, stDeviation
//6. filling the structure
#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{
FILE *hf;
char *array="12, 790, -986, 56, 6.89, 12.9008, 45, 567, 78, 17";
char *arr;
char numbarr[50][20];
double numbers[20];
int amount;
double mean,median,stDeviation,max,min;
char flnm[10]="122.txt";

char tocompare[13]="0123456789-.";
int i=0,j=0,counter=0,ender=0,checker=0;

int start=0;
double changer;
	
double sum,DevSqrSum;

struct Stat
{
	double Mean;
	double Median;
	double StDeviation;
	double Max;
	double Min;
}group;

unlink(flnm);
hf=fopen(flnm,"w");
fwrite(array, strlen(array),1, hf);
fclose(hf);

arr=(char *) malloc(strlen(array));

hf=fopen("122.txt","r");
fread(arr,strlen(array), 1, hf);
fclose(hf);



//By this, numbers from arr array one by one are copied to 2D array
	while(arr[ender]!=0)
	{
		for(counter=0,checker=0; tocompare[counter]!=0; counter++)
		{
			if(arr[ender]==tocompare[counter])
			{
			numbarr[j][i]=arr[ender];
			i++;
			counter=-1;
			checker=1;
			ender++;
			}
		}
		ender++;
		counter=0;
		i=0;
		if(checker==1)//Checker is used to avoid empty arrays
		{
		j++;
		}
		checker=0;
	}

//----------	
amount=j;//j is a number of numbers in a arr

for(i=0;i<amount;i++)
numbers[i]=atof(numbarr[i]);

	while(start<amount-1)//Sorting in an ascending order
	{
		for(min=numbers[start],j=0,i=start;i<amount;i++)
		{
			if(numbers[i]<= min)
			{
			min=numbers[i];
			j=i;
			}
		}
	changer=numbers[start];
	numbers[start]=numbers[j];
	numbers[j]=changer;
		
	start++;
	min=numbers[start];	
	}


min=numbers[0];
max=numbers[amount-1];

	for(i=0, sum=0; i<amount; i++)
	sum=sum+numbers[i];

mean=sum/amount;

	if(amount%2==1)
	median=numbers[amount/2];

	else if(amount%2==0)
	median=(numbers[amount/2-1]+numbers[amount/2])/2;

	for(i=0,DevSqrSum=0;i<amount;i++)
	DevSqrSum=DevSqrSum + (numbers[i]-mean)*(numbers[i]-mean);

stDeviation=sqrt(DevSqrSum/amount);

group.Mean=mean;
group.Median=median;
group.StDeviation=stDeviation;
group.Max=max;
group.Min=min;
}