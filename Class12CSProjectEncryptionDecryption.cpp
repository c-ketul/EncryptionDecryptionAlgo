#include <iostream>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <unistd.h>
using namespace std;

class Data
	{
		char name[100];
		int age;
		long int salary;
		char job[100];
	public:
		void AcceptData()
		{
			cout<<"Enter name : ";
			fflush(stdin);
			gets(name);
			cout<<"Enter age : ";
			cin>>age;
			cout<<"Enter job : ";
			fflush(stdin);
			gets(job);
			cout<<"Enter Salary : ";
			cin>>salary;
		
		}
		void PrintData()
		{
			cout<<"Name : ";
			puts(name);
			cout<<"Age : "<<age<<endl;
			cout<<"Job : ";
			puts(job);
			cout<<"Salary : "<<salary<<endl<<endl;
		}
		char* getname()
		{
			return name;
		}
		char* getjob()
		{
			return job;
		}
		int getage()
		{
			return age;
		}
		int getsalary()
		{
			return salary;
		}
		void MatrixEncryption(int Key[2][2]);
		void MatrixDecryption(int Key[2][2]);
	}D;
	
	int s= (D.getsalary()%10)+1.5;
	
	void Data::MatrixEncryption(int Key[2][2])
	{	
		int i,a;
		for(i=0; i<strlen(name);i++)
		{	
				name[i] += Key[i%2][i%2];
		}
		for(i=0; i<strlen(job);i++)
		{	
				job[i] += Key[i%2][i%2];
		}
	
		salary = pow(salary,s);
		age = pow(age,s);
		age += Key[0][1];
		salary += Key[1][0];
	
	}
	
	void Data::MatrixDecryption(int Key[2][2])
	{
		char choice;
		int i,j;
		
		salary-=Key[1][0];
		age-=Key[0][1];
		
		salary = pow(salary,1/s);
		age = pow(age,1/s);
	
			for(i=0; i<strlen(name);i++)
		{	
				name[i] -= Key[i%2][i%2];
		}
		
		for(i=0; i<strlen(job);i++)
		{	
				job[i] -= Key[i%2][i%2];
		}										//	Matrix Decryption Function
	}
	
void KeyCreation1(int A[2][2])
{
	int i,j;
	cout<<"Enter the matrix values : "<<endl;		// FUNCTION TO ACCEPT THE MATRICES
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			A[i][j]=rand();
	}
	
}

void MatrixEncryption(int C[2][2])
{
	int i,j,k,length;
	int A[2][2];
	int B[2][2];

	cout<<"Generating Encryption Key";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<"."<<endl<<endl;
	sleep(3);
	
		
	KeyCreation1(A);								//FUNCTION TO CREATE THE KEY
	KeyCreation1(B);
	
	 for(i = 0; i < 2; ++i)
        for(j = 0; j < 2; ++j)
        {
            C[i][j]=0;
        }
    // Multiplying matrix A and B and storing in array C to create the key.
    for(i = 0; i < 2; ++i)
        for(j = 0; j < 2; ++j)
            for(k = 0; k < 2; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            
          D.MatrixEncryption(C);	  
/*	int OriginalArray[4][100];
	length = strlen(D.getname());
	for(i=0;i<length;i++)
		{
			OriginalArray[0][i] = D.getname()[i];
			D.getname()[i] -= D.getname()[i] - 42;
		}			*/
				//CALLING THE ENCRYPTION FUNCTION AND ENCRYPTING
		
	D.PrintData();
}
void EncryptionMenu(int C[2][2])
{
	int choice;
	cout<<"Encryption Menu"<<endl<<endl;
	cout<<"1.Matrix Encryption"<<endl;
	cout<<"2.Second Encryption"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Enter choice : "<<endl;
	cin>>choice;
	switch(choice)
		{
			case 1: MatrixEncryption(C);
					break;
			case 2: //Second encryption;
					break;
			case 3: break;
		}
	
}

void DecryptionMenu(int C[2][2])
{	
	int choice;
	cout<<"Decryption Menu : \n"<<endl;
	cout<<"1.Matrix Decryption"<<endl;
	cout<<"2.'Decryption 2'"<<endl;				//MENU
	cout<<"3.Exit"<<endl<<endl;
	cout<<"Enter choice : ";
	cin>>choice;
	cout<<endl;
	switch(choice)
	{
			case 1: D.MatrixDecryption(C);
					D.PrintData();
					break;
			case 2: 
					break;
			case 3: exit(0);
					break;	
	}
}
int main()
{	
	D.AcceptData();
	int choice;
	int C[2][2];
	do{
		cout<<"Menu : \n"<<endl;
		cout<<"1.Encryption"<<endl;
		cout<<"2.Decryption"<<endl;				//MENU
		cout<<"3.Exit"<<endl<<endl;
		cout<<"Enter choice : ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1: EncryptionMenu(C);
					break;
			case 2: DecryptionMenu(C);
					break;
			case 3: break;
		}
	}while(choice!=3);


	return 0;
}
