Question : Given an array a[ ] of N elements. Consider array as a circular array i.e. 
  element after an is a1. The task is to find maximum sum of the absolute difference between consecutive elements with rearrangement of array elements allowed i.e.
  after any rearrangement of array elements find |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1|;


Input:
N = 4
a[] = {4, 2, 1, 8}
Output: 
18
Explanation: Rearrangement done is {1, 8, 
2, 4}. Sum of absolute difference between 
consecutive elements after rearrangement = 
|1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 
7 + 6 + 2 + 3 = 18.;


Input:
N = 2
a[] = {10, 12}
Output: 
4;


Approach ::
i) Sort the Array;
ii) In every loop iteration, Take the Sum of the difference of 1st element and last element :+: 2nd element and the last element;
iii) At last return total + abs(arr[o] - arr[i]);


Code Below :::::::::::::::



long long int maxSum(int arr[], int n)
{
    long long total = 0;
    sort(arr,arr+n);
    int i = 0,j = n-1;
    while(i < j) {
        total = total + abs(arr[i] - arr[j]);
        total = total + abs(arr[i+1] - arr[j]);
        i++; j--;
    }
    return total + abs(arr[0] - arr[i]);
}



