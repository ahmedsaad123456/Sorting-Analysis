#include "Sorting.h"

//----------------------------------------------------------

// Insertion sort
template<typename T>
void sortlib::Insertion_sort(T arr[],int n){
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

//----------------------------------------------------------

// selection sort function
template <typename T>
void sortlib::selectionSort(T arr[] , int n){
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

//----------------------------------------------------------

// Bubble sort function
template <typename T>
void sortlib::BubbleSort( T arr[] , int n){

    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j]> arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

//----------------------------------------------------------

// shell sort function
template <typename T>
void sortlib::ShellSort(T arr[], int n){
    int gap = n/2;
    while(gap>0){
        for(int i=gap ; i <n  ; i++){
            int j=i;
            while(j>=gap && arr[j-gap]>arr[j] ){
                swap(arr[j] , arr[j-gap]);
                j= j-gap;
            }
        }
        gap /= 2;
    }
}

//----------------------------------------------------------

// count sort function
void sortlib::CountSort(int arr[] , int n){
    int max=*max_element(arr , arr+n); 
    
    int arrIndex[max+1] = {0};  
    
    for(int i =0 ; i<n ; i++){
        arrIndex[arr[i]] ++;
    }

    for(int i =1 ; i<max+1 ; i++){
        arrIndex[i] += arrIndex[i-1];
    }
    
    int sortarr[n];

    for(int i=n-1 ; i>=0 ; i--){
        sortarr[arrIndex[arr[i]]-1]=arr[i];
        arrIndex[arr[i]]--;
    }

    for(int i=0 ; i<n ; i++){
        arr[i]= sortarr[i];
    }
}

//----------------------------------------------------------

// merge sort function
template<typename T>
void sortlib::Merge(T arr[] , int left , int middle , int right){
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
void sortlib::MergeSort(T arr[] , int left , int right){
    if (left < right)
    {
        int middle = left + (right-left) / 2;

        //sort the first and second halves
        MergeSort(arr , left , middle);
        MergeSort(arr , middle+1 , right);

        Merge(arr , left , middle , right);
    }
}


//----------------------------------------------------------

// quick sort function
template<typename T>
int sortlib::partition (T arr[], int left ,int right){
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
void sortlib::quick_sort(T arr[],int left,int right){
    if(left < right){
        int Pivot = partition(arr , left, right);
        quick_sort(arr ,left, Pivot-1);
        quick_sort(arr ,Pivot+1, right);
    }
}


//----------------------------------------------------------

//Generate array of random numbers
template<typename T>
void generateRandom (T arr[],int n){
    srand(time(0));
    for(int i=0 ; i<n ; i++){
        arr[i] = rand();
    }
}


//----------------------------------------------------------

//calculate Time on each dataset
void CalculateTime(){
    int arr[7]  ={200 , 500 , 1000 , 5000 , 10000 , 20000 , 50000};
    for(int i=0 ; i<7; i++){
        int arr1[arr[i]];
        generateRandom(arr1,arr[i]);
        auto start = high_resolution_clock::now();
        sortlib::quick_sort(arr1 ,0, arr[i]-1);
        auto end = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(end-start);

        cout<<"Time Taken by quick sort with size "<<arr[i]<<" = "<< time.count()<<"  microseconds"<<endl;
        cout << "------------------------------------------------------------"<<endl;

    }
}

//----------------------------------------------------------

//Print
template <typename T>
void print(T arr[] ,int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



