#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

namespace sortlib 
{
    template <typename T>

    void BubbleSort( T arr[] , int n){

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n-1 ; j++){
                if(arr[j]> arr[j+1]){
                    swap(arr[j] , arr[j+1]);
                }
            }
        }
    }


    template <typename T>

    void CountSort(T arr[] , int n){
        int max=0;
        for(int i = 0 ; i< n ; i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        T arrIndex[max+1] = {0};

        int value=0;

        for(int i =0 ; i<n ; i++){
            value = arr[i];
            arrIndex[value] = arrIndex[value]+1;
        }

        int i=0 , j=0;
        while(i<max+1){
            if(arrIndex[i]!=0){
                arr[j] = i;
                arrIndex[i]= arrIndex[i]-1;
                j++;
            }
            else{
                i++;
            }

        }
    }


    template <typename T>
    void ShellSort(T arr[], int n){
        int r=2;
        int h = n/r;
        while(h!=1){
        for(int i=0 ; i<h  ; i++){
            if(arr[i] > arr[i+h]){
                swap(arr[i] , arr[i+h]);
            }
        }
        r = r*2;
        h = n/(r);
        }
        int j=1;
        for(int i=1 ; i<n; i++ ){
            j=i;
            while(j>0 and arr[j-1]>arr[j]){
                swap(arr[j] , arr[j-1]);
                j--;
            }    
        }


    }






    template <typename T>
    void print(T arr[] ,int n){
        for(int i=0 ; i<n ; i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;

    }


};






int main(){


    using namespace sortlib;
    int arr[]={ 33 , 31 ,40 , 8 , 12 , 17 ,8, 25 ,42};
    int n = sizeof(arr)/ sizeof(arr[0]);
    BubbleSort(arr , n);
    print(arr , n);
    //CountSort(arr , n);
    //print(arr , n);
    ShellSort(arr, n);
    print(arr , n);




}