#include<iostream>
 
using namespace std;
 
int kadane(int a[], int n)
{
    int overall_sum=0;  //overall maximum subarray sum
    int new_sum=0;      //sum obtained by including the current element
 
    for(int i=0;i<n;i++)
    {
        //new_sum is the maximum value out of current element or the sum of current element
        //and the previous sum
        new_sum=max(a[i], new_sum+a[i]);
 
        //if the calculated value of new_sum is greater than the overall sum,
        //it replaces the overall sum value
        overall_sum=max(overall_sum, new_sum);
    }
 
    return overall_sum;
 
}
 
int main()
{
    int i,n;
 
    cout<<"Enter the number of elements in the array  ";
    cin>>n;
 
    int a[n];
 
    //read the vector
    cout<<"enter the elements in the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    //now,make a call to kadane function to calculate maximum subarray sum
    cout<<endl<<"The maximum subarray sum for the given array is "<<kadane(a,n); 
 
    return 0;
}