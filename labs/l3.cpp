#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <cstring>
#include <cstdlib>
using namespace std;
unsigned char Alph[256] = {};
int phi2(int number, vector <char>&string)
{
	int like = number, s = 0;
	if (like == 0) 
	{
		string.push_back ('1'), s++ ;
		return s;
	}
	if (like==1)
	{
	string.push_back('0');
	s++;
	string.push_back('1');
	s++;
	return s;
	}
	else
	{
		int len = 0;
		while (like != 0) like = like >> 1, len++;
		int likeOfnumber=len;
		int lenOflen = 0;
		while (likeOfnumber != 0) likeOfnumber = likeOfnumber >> 1, lenOflen++;
		for (int zero = 0; zero < lenOflen; zero++) 	string.push_back ('0'), s++;
		string.push_back('1'), s++;
		if (lenOflen != 1)
		{
			unsigned int m = 1 << (lenOflen - 2);
			while (m != 0)
			{
				if ((len & m) != 0) string.push_back('1');
				else string.push_back('0');
				s++;
				m = m >> 1;
			}
		}
		unsigned int r = 1 << (len - 2);
		while (r != 0)
		{
			
			if ((number & r) != 0)
			{
				string.push_back('1');
				s++;
			}
			else
			{
				string.push_back('0');
				s++;
			}
			r = r >> 1;
		}
	}
	return s;
}
void bookstack(char word[],unsigned int amount)
{
	int sp=0;
vector<char>string;
vector<int>num;
for (int letter = 0; letter < 256; letter++)
	{
		Alph[letter] = letter;
	}
for (unsigned int s=0; s < amount; s++)
	{
		for (int m = 0; m < 256; m++)
		{
			if (word[s] == Alph[m])
			{
				num.push_back(m);
				cout<<num.at(s)<<" ";
				
				int number=num.at(s);
				sp+= phi2(number, string);
				
				char n = Alph[m];
				while (m != 0)
				{
					Alph[m] = Alph[m - 1];
					m--;
				}
				Alph[0] = n;
			}
		}
	}
	cout<<"\n";
	for (unsigned int iterator=0; iterator < string.size(); iterator++) cout << string.at(iterator);
cout<<"\n"<<string.size()<<"\n";
	cout << "\n";	
}

bool compare(string a, string b){
    return (a.compare(b) < 0);
}

void convert_swap (string *Arry,int amount)
{
for (int w=0;w<amount;w++)
	{
		for(int l=0;l<(amount-1)/2;l++)
		{
			swap (Arry[w][l],Arry[w][amount-(l+2)]);
		}
		
	}
}

void move_to_left(string *Arryf,char *word,int amount)
{
	for (int i=0;i<amount;i++)
	{
		Arryf[i]=string(word);
		char end=word[0];
		for (int shift=0;shift<(amount-1);shift++)
		{
			
			word[shift]=word[shift+1];
		}
		word[amount-1]=end;
	}
 
}

void cout_arr(string *Arryf,int amount)
{
		for (int cou=0;cou<amount;cou++)
			{cout<<Arryf[cou]<<"\n";}
}

void cout_arr2(char *Arryf,int amount)
{
		for (int cou=0;cou<amount;cou++)
			{cout<<Arryf[cou];}
}

int comp(const void* a, const void* b)
{
    return *((char*)a) - *((char*)b);
}

void convert_bwt(char *A, int num, int amount)//arry ,number of first letter in origin arry,  amount of letters 
{
//char A[]="gmseesa";
	char *B=new char[amount];
	int *C=new int [amount];
	for (int j=0;j<amount;j++)
	{
		B[j]=A[j];
	}
 qsort(A, strlen(A), sizeof(char), comp);
//	for(int i = 0; i <amount; i++ ) cout<<" "<<A[i];
	cout<<"\n\n\n";
	int lb=0;					//start
	int la=0;
	//cout<<B[lb];
	int lon=0;
	while (lon!=amount)
	{
		
		while (B[lb]!=A[la])
		{	
			la++;
			la=la%amount;
			if (A[la]=='\0')
			{
				la++;
				la=la%amount;
			}
		
		}
		A[la]='\0';
		C[lb]=la;
		//cout<<C[lb];
		lb++;
		lon++;
	}	
	lon=0;					//end algoritm for numbers
	
	cout<<"\n\n\n";
	
	lb=num;

	
		while (lon!=amount)
	{
		cout<<B[lb];
		lb=C[lb];
		lon++;
	}	
	delete[]B;
	delete[]C;
	
}


int main ()
{
	char firstlett='a';
	unsigned int amount=0;
	char *word=new char [amount];
	
	ifstream file;
	file.open("/home/louisa/louisa/l3/lui.txt");
	if (!file)
	{
		cout<<"it's not opened:("<<endl;
	}
	else
	{
		cout<<"it's opened :)"<<endl;
		char letters;
		while (file.get(letters))
		{
			word[amount]=letters;
			amount++;
			if (amount==1)
			{
				firstlett=letters;
			}
		}
		amount=(amount-1);
						cout<<"\n";
		bookstack(word,amount);
	string *Arryf =new string [amount];
	
	move_to_left(Arryf,word,amount);
	
	cout_arr(Arryf,amount);
	
	delete [] word;
convert_swap (Arryf, amount);
	

cout<<"\n\n\n";
vector <string> A (Arryf, Arryf+amount);  
vector<string>::iterator it;


 delete [] Arryf;

  sort (A.begin(), A.end(), compare);
	
	/*for (it=A.begin(); it!=A.end(); ++it)
    cout << " " << *it;*/
    
	string *B=new string[amount];
	copy(A.begin(),A.end(),B);
	convert_swap(B,amount);
	
	cout_arr(B,amount);
	char *C=new char[amount];
	for (unsigned int c=0;c<amount;c++)
	{
		C[c]=B[c][amount-1];
	}
	delete[]B;
	cout<<"\n\n";
	cout_arr2(C,amount);

int fl=0;
	while(C[fl]!=firstlett)
	{
		 fl++;
		
	}
	cout<<" ";
	bookstack(C,amount);
	//	cout<<"   ("<<fl<<")"<<endl; 

	C[amount]='\0';	
		convert_bwt(C,fl,amount);


		delete[]C;
	}
	
	file.close ();
	return 0;
}
