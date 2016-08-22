#include<istream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
int main()
{
int n, i, j;
float r,h,b[20],c[20],g,pyes,pno,pattryes[20],pattrno[20],resultyes,resultno;
string a[20];
cout<<"enter the no. of records";
cin>>r;
cout<<"enter the number of attributes\n";
cin>>n;
cout<<"enter the name  of each attribute\n";
for(i=0;i<n;i++)
	{cin>>a[i];
	}

cout<<"enter the no. of yes in each attribute\n";
for(i=0;i<n;i++)
{
	cin>>b[i];
}
cout<<"enter the no. of no in each attribute\n";
for(i=0;i<n;i++)
{cin>>c[i];

}
cout<<"enter the  total no. of yes\n";
cin>>g;
cout<<"enter the total no. of no\n";
cin>>h;
pyes=(g/(g+h));
pno=(h/(g+h));
for(i=0;i<n;i++)
{
pattryes[i]=(b[i]/g);
pattrno[i]=(c[i]/h);
}
for(i=0;i<n;i++)
{
resultyes=pyes*pattryes[i];
resultno=pno*pattrno[i];

if(resultyes>resultno)
{
 cout<<"\ndiagnosis of the attribute "<<a[i]<<" is yes";
}
else if(resultyes<resultno)
{
 cout<<"\ndiagnosis of the attribute "<<a[i]<<" is no";
}
}
return 0;
}
