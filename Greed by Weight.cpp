#include <iostream>
using namespace std;

void mergesort(double [],double [],double [],int,int);
void merge(double[],double[],double[],int,int);
int main() {
	int i,n,m;
	cout<<"Banyaknya item = ";
	cin>>n;
	double weight[n],profit[n],ratio[n],wt=0,ans=0;

	cout<<"\nMasukkan nilai item\n";
	for(i=0;i<n;i++)
	{
		cout<<"Masukkan nilai w"<<i+1<<" = ";
		cin>>weight[i];
		cout<<"Masukkan nilai p"<<i+1<<" = ";
		cin>>profit[i];
	}

	cout<<"\nKapasitas Knapsack W = ";
	cin>>m;
	for(i=0;i<n;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}

	mergesort(ratio,weight,profit,0,n-1);

	for(i=0;i<n;i++)
	{
		ratio[i]=0;
	}

	for(i=0;i<n;i++)
	{
		if(wt+weight[i]<m)
		{
			ratio[i]=1;
			wt=wt+weight[i];
		}
		else
		{
			if(wt!=m)
			{
			ratio[i]=(m-wt)/weight[i];
			wt=m;
			}
			else
			{
				ratio[i]=0;
			}
		}
	}

	cout<<"\nGreedy by Weight\n";
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			cout<<"\t\t(1)\t\t";
		}
		else
		{
			cout<<"("<<i<<")\t\t";
		}
	}
	cout<<"\nWeight\t\t";
	for(i=0;i<n;i++)
	{
		cout<<weight[i]<<"\t\t";
	}
	cout<<"\nProfit\t\t";
	for(i=0;i<n;i++)
	{
		cout<<profit[i]<<"\t\t";

	}
	cout<<"\np/w\t\t";
	for(i=0;i<n;i++)
	{
		cout<<profit[i]/weight[i]<<"\t\t";
	}
	cout<<"\nInstance\t";
	for(i=0;i<n;i++)
	{
		if(ratio[i]==1 || ratio[i]==0)
		{
			cout<<ratio[i]<<"\t\t";
			ans=ans+(profit[i]*ratio[i]);
		}
		else
		{
			cout<<"0\t\t";
			ans=ans+(profit[i]*0);
		}
	}
return 0;
}

void mergesort(double ratio[],double weight[],double profit[],int l, int h)
{
  if(h>l)
  {
    mergesort(ratio,weight,profit,l,(l+h)/2);
    mergesort(ratio,weight,profit,((l+h)/2)+1,h);
    merge(ratio,weight,profit,l,h);
  }
}

void merge(double ratio[],double weight[],double profit[], int l, int h)
{
    int b[h],a[h],c[h];
    int i,j,m,k=l;
    i=l;
    j=((l+h)/2)+1;
    m=j-1;
    while (i<=m && j<=h)
    {
      if(weight[i]<weight[j])
      {
        b[k]=ratio[i];
        a[k]=weight[i];
        c[k]=profit[i];
        i++;
      }
      else
      {
        b[k]=ratio[j];
        a[k]=weight[j];
        c[k]=profit[j];
        j++;
      }
      k++;
    }

    if(i>m)
    {
      while(j<=h)
      {
        b[k]=ratio[j];
        a[k]=weight[j];
        c[k]=profit[j];
        j++;
        k++;
      }
    }
    else
    {
      while(i<=m)
      {
        b[k]=ratio[i];
        a[k]=weight[i];
        c[k]=profit[i];
        i++;
        k++;
      }
    }
    k=l;
    while(k<=h)
    {
      ratio[k]=b[k];
      weight[k]=a[k];
      profit[k]=c[k];
      k++;
    }
}
