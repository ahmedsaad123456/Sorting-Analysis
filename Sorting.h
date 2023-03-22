#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

namespace sortlib 
{
    // insertion sort function
    template<typename T>
    void Insertion_sort(T arr[],int n);

//----------------------------------------------------------

    // selection sort function
    template <typename T>
    void selectionSort(T arr[] , int n);

//----------------------------------------------------------

    // Bubble sort function
    template <typename T>
    void BubbleSort( T arr[] , int n);

//----------------------------------------------------------

    // shell sort function
    template <typename T>
    void ShellSort(T arr[], int n);

//----------------------------------------------------------

    // count sort function
    void CountSort(int arr[] , int n);

//----------------------------------------------------------

    // merge sort function
    template<typename T>
    void Merge(T arr[] , int left , int middle , int right);
    
    template<typename T>
    void MergeSort(T arr[] , int left , int right);

//----------------------------------------------------------

    // quick sort function
    template<typename T>
    int partition (T arr[], int left ,int right);

    template<typename T>
    void quick_sort(T arr[],int left,int right);

}

//----------------------------------------------------------

//Generate array of random numbers
template<typename T>
void generateRandom (T arr[],int n);

//----------------------------------------------------------

//calculate Time on each dataset
void CalculateTime();

//----------------------------------------------------------

//Print
template <typename T>
void print(T arr[] ,int n);