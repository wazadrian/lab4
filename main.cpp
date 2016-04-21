#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string numToText(int);
string three(int,int,int);
int findK(int);

int main(int argc, char *argv[])
{
	int n=atoi(argv[1]);
	cout << "Dla n = " << numToText(n) <<  " k = " << numToText(findK(n)) << "  n * k = " << numToText(n*findK(n)) << endl;
	cout << endl;
}
string numToText(int N)
{
	string result;
	int t[9] = {0};// max 999 999 999
	for(int i = 0, temp = N; i < 9; i++)
	{
		t[i] = temp%10;
		temp = (temp/10);
	}
  	string T[][3]=	{
  						{"milion","miliony","milionow"},
                		{"tysiac","tysiace","tysiecy"},
                		{"","",""}
            		};
	for(int i = 0, temp = 1000000, n = 8; i<3;i++)
	{
		if(N/temp)
		{
			result += three(t[n-(i*3)],t[n-1-(i*3)],t[n-2-(i*3)]);
			if (t[n-1-(i*3)] == 1)
			result += T[i][2] + " ";	
			else if (t[n-2-(i*3)] > 1 && t[n-2-(i*3)] < 5)
			result += T[i][1] + " ";
			else if (t[n-2-(i*3)] == 1 && t[n-1-(i*3)] ==0 && t[n-(i*3)] ==0)
			result += T[i][0] + " ";
			else if (t[n-2-(i*3)] == 0 && t[n-1-(i*3)] ==0 && t[n-(i*3)] ==0)
			result += "";
			else
			result +=T[i][2] + " ";		
		}
		temp /=1000;	
	}
	if(result=="")
		result = "zero";
	return result;
}
string three(int s,int d, int j)
{
	string result;
	string J[] = {"","jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec","dziesiec","jedenascie","dwanascie","trzynascie","czternascie","pietnascie","szesnascie","siedemnascie","osiemnascie","dziewietnascie"};
	string D[] = {"","","dwadziescia","trzydziesci","czterdziesci","piedziesiat","szescdziesiat","siedemdziesiat","osiemdziesiat","dziewiedziesiat"};
	string S[] = {"","sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset"};
	if(s != 0)
		result += S[s] + " ";
	if(d > 1)
		result +=  D[d] + " ";
	else if (d == 1)
		result += J[j+10] + " ";
	if (d!=1 && j!=0)
		result += J[j] + " ";
	return result;
}
int findK(int n) 
{
	int k = 0;
	int t[9] = {0};
	int check = 0;
	int tn=0;
	while(n*k<999999)
	{
		for(int i = 0; i < 9; i++)
			t[i] = 0;
		k++;
		check = 0;
		tn = n*k;
		for(int i = 0, temp = tn; i < 9; i++)
		{
			t[i] = temp%10;
			temp = (temp/10);
		} 
		for(int i = 0; i < 9; i++)
		{
			if(t[i]==0 || t[i]==1)
			check++;
		}
		if (check == 9)
			break; 	
	}
	if(check!=9)
		k = 0;
	return k;
}
