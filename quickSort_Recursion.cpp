// #include<iostream>
// using namespace std;

// int partition(int arr[], int s , int e)
// {
//     int pivot = arr[s];
//     int cnt = 0;

//     // finding the correct place to place pivot element so left me chote ho aur right me bade ho

//     for(int i =s+1;i<=e;i++)
//     {   
//         if(arr[i]<=pivot){
//             cnt++;
//         }
//     }

//     // place the pivot at correct position
//     int pivotIndex = s + cnt;
//     swap(arr[pivotIndex],arr[s]);

//     // ab left wala aur rigth wala smbhal lete hai 
//     int i = s, j = e;
//     while(i<pivotIndex && j>pivotIndex){
//         //agr shi position hai left ki toh aage bado
//         while(arr[i]<=pivot){
//             i++;
//         }
//         //agr shi position hai right ki toh peeche laao pointer ko
//         while(arr[i]>pivot){
//             j--;
//         }

//             while(i<pivotIndex && j>pivotIndex){
//                 swap(arr[i++],arr[j--]);
//             }

//     }
//     return pivotIndex;
// }

// void quickSort(int arr[], int s, int e)
// {
//     //base case 
//     if(s>=e)
//         return;
    
//     // partition krege
//     int p = partition(arr,s,e);

//     //left part ko sort krege
//     quickSort(arr,s,p-1);

//     //right part ko sort krege
//     quickSort(arr,p+1,e);
// }

// int main()
// {
//     int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
//     int n = 10;

//     quickSort(arr, 0, n-1);

//     for(int i=0; i<n; i++) 
//     {
//         cout << arr[i] << " ";
//     } cout << endl;


//     return 0;
// }
#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            //i++
            //j-- can be written instead of ek sath increment and decrement with call
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);

}

int main() {

    int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}