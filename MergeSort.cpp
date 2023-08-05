//MERGE SORT

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int>a(n1);
    vector<int>b(n2);

    for(int i=0;i<n1;++i)
        a[i]=arr[i+l];
    for(int i=0;i<n2;++i)
        b[i]=arr[mid+1+i];
    ///////////////////////////
    //merging

    int i=0,j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
            arr[k++]=a[i++];
        else
            arr[k++]=b[j++];
    }

    while(i<n1)
        arr[k++]=a[i++];
    while(j<n2)
        arr[k++]=b[j++];
}

void mergeSort(vector<int>&arr,int l,int r)
{
    if(l<r) // if there is atleast 2 elements
    {
        int mid=(l+r)/2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&it:arr)
        cin>>it;

    mergeSort(arr,0,n-1);
    for(auto&it:arr)
        cout<<it<<" ";

    return 0;
}

// https://www.youtube.com/watch?v=aDX3MFL0tYs&t=1010s --> FOR CONCEPT
// https://www.youtube.com/watch?v=9Xaz01KOPuo&t=642s --> FOR CODE 
