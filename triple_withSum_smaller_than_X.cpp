long long countTriplets(long long arr[], int n, long long sum)
{
    long long c=0;
    sort(arr,arr+n);
    int p=n-1;
   while(p>=0){
       int i=0,j=p-1;
       long long x=sum-arr[p];
       while(i<j){
           if(arr[i]+arr[j]<x){
               c=c+j-i;
               ++i;
           }
           else if(arr[i]+arr[j]==x){
               --j;
           }
           else if(arr[i]+arr[j]>=x){
               --j;
           }
       }
       p--;
   }
   return c;
    // Your code goes here
}