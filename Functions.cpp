#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
using namespace std::chrono;

namespace sortlib 
{
    //--------------------------------------------
    //Insertion sort
    template<typename T>
    void Insertion_sort(T arr[],int n){
        for (int i = 1; i < n; ++i) {
            T key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    //--------------------------------------------
    //Bubble sort
    template <typename T>

    void BubbleSort( T arr[] , int n){

        for(int i=0 ; i<n-1 ; i++){
            for(int j=0 ; j<n-i-1 ; j++){
                if(arr[j]> arr[j+1]){
                    swap(arr[j] , arr[j+1]);
                }
            }
        }
    }
    //--------------------------------------------
    //Count sort
    void CountSort(int arr[] , int n){
        // ex : arr= [4 , 1 , 3 , 4 , 3]
        int max=*max_element(arr , arr+n); // get the max element
        
        int arrIndex[max+1] = {0};  // create new array index with size of (max+1)

        // Add 1 to the index of the arrindex if the number of the index exists in the arr as value 
        for(int i =0 ; i<n ; i++){
            arrIndex[arr[i]] ++;
        }
        // after this loop the arrindex will be [0 , 1 , 0 , 2 , 2]

        // sort the data from the arrindex to the arr 
        int i=0 , j=0;
        while(i<max+1){
            if(arrIndex[i]!=0){        // arrIndex[i]==0 means the i number does not exist in the arr
                arr[j] = i;
                arrIndex[i]= arrIndex[i]-1;
                j++;
            }
            else{
                i++;
            }
        }
        // after this loop the arr will be [1 , 3 , 3 , 4 , 4]
    }
    //--------------------------------------------
    //Shell sort
    template <typename T>
    void ShellSort(T arr[], int n){

        int gap = n/2;

        while(gap != 1){
        for(int i=0 ; i < gap  ; i++){
            if(arr[i] > arr[i+gap]){
                swap(arr[i] , arr[i+gap]);
            }
        }
        gap /= 2;
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
    //--------------------------------------------
    //Quick sort
    template<typename T>
    int partition (T arr[], int left ,int right){
        int i = left;
        int j = right;
        int Pivot = i;
        while(true){
            while(arr[Pivot] <= arr[j] && Pivot!=j){
                j--;
            }
            if(Pivot == j)
                break;
            else if(arr[j]<arr[Pivot]){
                swap(arr[j],arr[Pivot]);
                Pivot = j;
            }
            while(arr[Pivot]>=arr[i] && Pivot !=i){
                i++;
            }
            if(Pivot == i)
                break;
            else if(arr[i]>arr[Pivot]){
                swap(arr[i],arr[Pivot]);
                Pivot = i;
            }
        }
        return Pivot;
    }
    template<typename T>
    void quick_sort(T arr[],int left,int right){
        if(left < right){
            int Pivot = partition(arr , left, right);
            quick_sort(arr ,left, Pivot-1);
            quick_sort(arr ,Pivot+1, right);
        }
    }
    //-------------------------------------------
    //Selection Sort
    template <typename T>
    void selectionSort(T arr[] , int n){
        for(int i = 0 ; i < n - 1 ; i++)
        {
            int min = i;
            for(int j = i+1 ; j < n  ; j++)
            {
                if(arr[j] < arr[min])
                    min = j ;
            }
            if (min != i)
                swap(arr[i] , arr[min]);
        }
    }
   //--------------------------------------------
   //Merge Sort
   template<typename T>
   void Merge(T arr[] , int left , int middle , int right)
   {
       int i , j , k;
       int n1 = middle -left + 1;
       int n2 = right - middle;

       //create temporary
       T L[n1] , R[n2] ;

       //copy data to temporary arrays
       for (i = 0 ; i < n1 ; i++)
           L[i] = arr[left+i];
       for (j = 0 ; j < n2 ; j++)
           R[j] = arr[middle + j + 1];

       //merge temporary arrays back into arr
       i = 0;
       j = 0;
       k = left;
       while (i < n1 && j < n2)
       {
           if(L[i] <= R[j])
           {
               arr[k] = L[i];
               i++;
           }
           else
           {
               arr[k] = R[j];
               j++;
           }
           k++;
       }

       //copy the remaining elements if any
       while(i < n1)
       {
           arr[k] = L[i];
           i++;
           k++;
       }

       while (j < n2)
       {
           arr[k] = R[j];
           j++;
           k++;
       }
   }


    template<typename T>
    void MergeSort(T arr[] , int left , int right)
    {
        if (left < right)
        {
            int middle = left + (right-left) / 2;

            //sort the first and second halves
            MergeSort(arr , left , middle);
            MergeSort(arr , middle+1 , right);

            Merge(arr , left , middle , right);
        }
    }
   //--------------------------------------------
   //Print
    template <typename T>
    void print(T arr[] ,int n){
        for(int i=0 ; i<n ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    //--------------------------------------------
    //Generate array of random numbers
    template<typename T>
    void generateRandom (T arr[],int n){
        srand(time(0));
        for(int i=0 ; i<n ; i++){
            arr[i] = rand();
    }
        
    }
    //--------------------------------------------
    //calculate Time on each dataset
    void CalculateTime(){
        int arr[7]  ={200 , 500 , 1000 , 5000 , 10000 , 20000 , 50000};
        for(int i=0 ; i<7; i++){
            int arr1[arr[i]];
            generateRandom(arr1,arr[i]);
            auto start = high_resolution_clock::now();
            CountSort(arr1 , arr[i]);
            auto end = high_resolution_clock::now();
            auto time = duration_cast<microseconds>(end-start);

            cout<<"Time Taken by CountSort with size "<<arr[i]<<" = "<< time.count()<<"  microseconds"<<endl;
        }
    }


}






int main(){


    using namespace sortlib;
    int arr[]={ 33 , 31 ,40 , 8 , 12 , 17 ,8, 25 ,42};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    
//    BubbleSort(arr , n);
//    print(arr , n);
    //CountSort(arr , n);
    //print(arr , n);
    ShellSort(arr, n);
//    print(arr , n);
//    quick_sort(arr,0,n-1);
//    selectionSort(arr , n);
    print(arr,n);

//    CalculateTime();






    
    
    
    




}