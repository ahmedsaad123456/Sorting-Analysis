#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

namespace sortlib 
{

    template<typename T>

    T sum (T x , T y){
        return x + y;
    }

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
    void print(T arr[] ,int n){
        for(int i=0 ; i<n ; i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;

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

};






int main(){


    using namespace sortlib;
    int arr[9]={ 4 ,5 , 7 ,9 ,3,45  ,4 , 1 , 4,};
    BubbleSort(arr , 9);
    print(arr , 9);
    CountSort(arr , 9);
    print(arr , 9);

    int x = 10 , y=45 ;
    cout<< sum(x,y)<<endl;

}