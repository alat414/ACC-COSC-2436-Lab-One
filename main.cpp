#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>

// https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.h"

using namespace std;

#define MIN_ARRAY_LEN 2

int factorial(int n) 
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int numberPairs) 
{
    if (numberPairs < 0)
    {
        throw invalid_argument("Fibonacci Sequence does not apply for negative numbers");
    }
    else if (numberPairs == 0)
    {
        return 0;
    }
    else if (numberPairs == 1)
    {
        return 1;
    }
    
    int leftVariable = 0, rightVariable = 1, followingVariable;

    for (int i = 2; i <= numberPairs; i++)
    {
        followingVariable = leftVariable + rightVariable;
        leftVariable = rightVariable;
        rightVariable = followingVariable;
    }
    return rightVariable;

}

int towers(char src, char target, char spare, int n) 
{
    if (n <= 0)
    {
        return 0;
    }
    towers(src, spare, target, n - 1);

    cout << "move disk " << n << " to pole " << target << endl;

    return towers(spare, target, src, n - 1);
}

int towerMovesCount(int n)
{
    if (n < 0)
    {
        return 0;
    }
    return static_cast<int>(pow(2,n)) - 1;
}

void testFactorial(const string& testName, bool condition)
{
    if (condition)
    {
        cout << "test passed :" << testName << endl;
    }
    else
    {
        cout << "test failed :" << testName << endl;
    }
}

// Warning: Be sure to free the returned copy.
int* copyArray(const int arr[], int n) 
{
    int* r = new int[n];
    for (int i = 0; i < n; ++i) 
    {
        r[i] = arr[i];
    }
    return r;
}


int chooseRandomPivotIndex(int start, int end) 
{
    int n = (end + 1) - start;
    return start + rand() % n;
}

int partition(int pivotIndex, int arr[], int start, int end) 
{
    int n = end - start + 1;
    assert(n != 0 && pivotIndex >= start && pivotIndex <= end);

    if (n == 1) 
    {
        return pivotIndex;
    }

    int pivotValue = arr[pivotIndex];

    swap(arr[pivotIndex], arr[end]);
    
    int storeIndex = start;

    for (int i = 0; i < end; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[end]);

    return pivotIndex;
}

int findKthSmallestValue(int k, int arr[], int start, int end) 
{
    int n = (end + 1) - start;

    if (n == 0 || k <= 0 || k > n) 
    {
        throw runtime_error("Invalid input.");
    }

    if (n == 1) 
    {
        return arr[start];
    }

    int chosenPivotIndex = chooseRandomPivotIndex(start, end);

    int pivotIndex = partition(chosenPivotIndex, arr, start, end);

    int kZeroBased = k - 1;

    int s1 = pivotIndex - start;

    if (s1 == kZeroBased) 
    {
        return arr[pivotIndex];
    }

    if (kZeroBased < s1) 
    {
        return findKthSmallestValue(k, arr, start, pivotIndex - 1);
    } 

    else 
    {
        int newK = kZeroBased - s1;
        return findKthSmallestValue(newK, arr, pivotIndex + 1, end);
    }
    
}

// Used to test our results. Warning: Sorts the input array in place.
int findKthSmallestValueViaSorting(int k, int arr[], int start, int end) {
    int n = (end + 1) - start;
    if (n == 0 || k >= n) 
    {
        throw runtime_error("Invalid input.");
    }

    if (n == 1) 
    {
        return arr[start];
    }

    sort(arr, arr + n);

    return arr[k];
}

// Tests findKthSmallestValue for an array of length n.
void testFindKthSmallestValueForArraySizeN(int n) {
    if (n == 0 || n == 1) 
    {
        throw runtime_error("Invalid input.");
    }

    int* arr = new int[n];

    // Populate the array with random numbers
    for (int i = 0; i < n; ++i)
    {
        int x = rand() % 100;
        arr[i] = x; // Random number between 0 and 99
    }

    for (int k = 0; k < n; ++k) {
        // Copying the array to ensure our input doesn't get sorted.
        int* copyArray1 = copyArray(arr, n);
        int expectedResult = findKthSmallestValueViaSorting(k, copyArray1, 0, n - 1);
        delete[] copyArray1;

        // Copying here to ensure the implementation doesn't mutate the array between different k iterations.
        int* copyArray2 = copyArray(arr, n);
        int result = findKthSmallestValue(k, copyArray2, 0, n - 1);
        delete[] copyArray2;

        if (result != expectedResult) 
        {
            throw runtime_error("Test failed.");
        }
        else 
        {
            cout << "Success for input array of size " << n << endl;
        }
    }

    delete[] arr;
}

void testFindKthSmallestValue(int repetitions, int maxArraySize) {
    if (maxArraySize < MIN_ARRAY_LEN) 
    {
        throw runtime_error("Invalid input.");
    }

    for (int n = MIN_ARRAY_LEN; n <= maxArraySize; ++n) 
    {
        for (int i = 0; i < repetitions; ++i) {
            testFindKthSmallestValueForArraySizeN(n);
        }
    }
}

void testFindSmallestKValue()
{
    int arr[] = {2, 9, 1, 4, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int result = findKthSmallestValue(k, arr, 0, size -1);
    assert(result == 2);
    cout << "Test Passed, third smallest value is: " << result << endl;
}

void testFibonacci(const string& testName, bool condition)
{

    if (condition)
    {
        cout << "Test passed" << testName << endl;
    }
    else
    {
        cout << "Test failed!" << testName << endl;
    }
}

void towersTest(const string& testName, bool condition)
{
    if (condition)
    {
        cout << "Test passed " << testName << endl;
    }
    else
    {
        cout << "Test failed! " << testName << endl;
    }
}


int main()
{
    //cout << "Running towers of hanoi function: \n";
    //cout << "Running factorial tests: \n";
    //cout << "Running fibonacci tests: \n";
    //testFactorial("factorial of three is six: ", factorial(3) == 6);
    //testFactorial("factorial of four is twenty four: ", factorial(4) == 24);
    //testFibonacci("The 6th value in the fibonacci sequence is 8", fibonacci(6) == 8);
    //towers('A', 'B', 'C', 3);
    //towersTest("Number of disk moves for three disks is seven", towerMovesCount(3) == 7);
    //cout << towerMovesCount(3);

    testFindSmallestKValue();

    return 0;
}
