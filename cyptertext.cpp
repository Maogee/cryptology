#include <iostream>
using namespace std;
int mod(int u,int n);
void main()
{
	int a,b,i,t;
	int n=26;
	char m[10000];
	cout<<"please input ciphertext as m:";
    gets(m);
	cout<<"please input a :";
	cin>>a;
	cout<<"please input b:";
	cin>>b;
	cout<<"密文:";
	for(i=0;i<strlen(m);i++)
	{
		cout<<m[i];
	}
	cout<<endl;
	t=mod(a,n);
	for(i=0;i<strlen(m);i++)
	{
		if(m[i]<='z'&&m[i]>='a')
			{
			     m[i]=m[i]-'a';
				 m[i]=(t*(m[i]-b+n))%n;
				 m[i]=m[i]+'a';
			}
			else if(m[i]<='Z'&&m[i]>='A')
			{
				m[i]=m[i]-'A';
				m[i]=(t*(m[i]-b+n))%n;
				m[i]=m[i]+'A';
			}
			else
			{
				m[i]=m[i];
			}
	}
	cout<<"解密后明文:";
	for(i=0;i<strlen(m);i++)
	{
		cout<<m[i];
	}
	cout<<endl;
}
int mod(int u,int n)
{
	int n1,n2,b1,b2,t,k,r,w;
    n1=n,n2=u,b1=0,b2=1;
	k=n1/n2;
	r=n1-k*n2;
	while(r!=0)
	{
		n1=n2;
		n2=r;
		t=b2;
		b2=b1-k*b2;
		b1=t;
		k=n1/n2;
	    r=n1-k*n2;
	}
	if(n2==1)
	{
		w=(n+b2)%n;
		return w;
	}
	return 0;		  
}
