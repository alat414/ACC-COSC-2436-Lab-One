#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <cmath>

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

    //return (static_cast<unsigned int>(pow(2, n) - 1));

    return towers(spare, target, src, n - 1);
}

unsigned int towerMovesCount(int n)
{
    if (n < 0)
    {
        return 0;
    }
    return static_cast<unsigned int>(pow(2,n)) - 1;
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
int main()
{
    cout << "Running towers of hanoi function: \n";
    //testFactorial("factorial of three is six: ", factorial(3) == 6);
    //testFactorial("factorial of four is twenty four: ", factorial(4) == 24);
    //testFibonacci("The 6th value in the fibonacci sequence is 8", fibonacci(6) == 8);

    towers('A', 'B', 'C', 3);
    towerMovesCount(3);
}
/*


TEST_CASE("testing the towers function") {
    CHECK(false); // TODO: replace with your tests.
}

// Warning: Be sure to free the returned copy.
int* copyArray(const int arr[], int n) {
    int* r = new int[n];
    for (int i = 0; i < n; ++i) {
        r[i] = arr[i];
    }
    return r;
}

int chooseRandomPivotIndex(int start, int end) {
    int n = (end + 1) - start;
    return start + rand() % n;
}

// Partitions an array into segments s1, and s2 where s1 contains all the values less
// than or equal to the pivot value, and s2 contains the values greater or equal to the pivot.
//
// pivotIndex: Index whose value is used to partition the input array.
// start: The index in the array to start at.
// end: The inclusive index in the array to end at.
//
// Returns: Index where the pivotIndex has moved to and the input array arr partitioned.
int partition(int pivotIndex, int arr[], int start, int end) {
    int n = (end + 1) - start;
    assert(n != 0 && pivotIndex >= start && pivotIndex <= end);

    if (n == 1) {
        return pivotIndex;
    }
    int pivotValue = arr[pivotIndex];

    // Hints:
    //       * The partition function itself is not recursive, but is used recursively.
    //       * The pivot is not included in s1 or s2, although there can be other elements equal to the pivot in s1 or s2.
    //       * The pivot value determines what needs to move to s1 or s2;
    //       * If you change the location of the pivot value don't forget to return the new pivotIndex.
    //       * You might want to temporarily move the pivot value to aid in the process.
    //       * You can do this multiple ways; one pass, two passes, from center out, from ends in.
    //       * Use std::swap
    //       * If you are stuck, check out Lomuto or Hoare. (Try it yourself first.)

    // TODO: finish

    return pivotIndex;
}

// Quickly finds the k-th smallest value without sorting the entire array.
//
// k: 0 based index k into array arr
// arr: mutable pointer to an array
// start: start index of the array
// end: end index of the array
int findKthSmallestValue(int k, int arr[], int start, int end) {
    int n = (end + 1) - start;
    if (n == 0 || k >= n) {
        throw runtime_error("Invalid input.");
    }

    // Return the single value in an array of length 1.
    if (n == 1) {
        return arr[start];
    }

    int chosenPivotIndex = chooseRandomPivotIndex(start, end);

    int pivotIndex = partition(chosenPivotIndex, arr, start, end);

    int s1 = pivotIndex - start;

    // Base case where s1 == k.
    if (s1 == k) {
        // TODO: Replace -1 with the value for the base case.
        return -1;
    }

    // Figure out which segment the kth smallest is in and recurse.
    // Note that the pivot is not included in s1 or s2. This guarantees that the problem reduces while recursing.
    // TODO: Replace true with a boolean expression that determines which segment to recurse into.
    if (true) {
        // TODO: Replace -1 with a recursive call to findKthSmallestValue.
        return -1;
    } else {
        // TODO: Replace -1 with a recursive call to findKthSmallestValue.
        return -1;
    }
}

// Used to test our results. Warning: Sorts the input array in place.
int findKthSmallestValueViaSorting(int k, int arr[], int start, int end) {
    int n = (end + 1) - start;
    if (n == 0 || k >= n) {
        throw runtime_error("Invalid input.");
    }

    if (n == 1) {
        return arr[start];
    }

    sort(arr, arr + n);

    return arr[k];
}

// Tests findKthSmallestValue for an array of length n.
void testFindKthSmallestValueForArraySizeN(int n) {
    if (n == 0 || n == 1) {
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

        if (result != expectedResult) {
            throw runtime_error("Test failed.");
        }
        else {
            cout << "Success for input array of size " << n << endl;
        }
    }

    delete[] arr;
}

void testFindKthSmallestValue(int repetitions, int maxArraySize) {
    if (maxArraySize < MIN_ARRAY_LEN) {
        throw runtime_error("Invalid input.");
    }

    for (int n = MIN_ARRAY_LEN; n <= maxArraySize; ++n) {
        for (int i = 0; i < repetitions; ++i) {
            testFindKthSmallestValueForArraySizeN(n);
        }
    }
}

TEST_CASE("test kth smallest value") {
    srand(0);
    CHECK_NOTHROW(testFindKthSmallestValue(3, 5));
}

*/