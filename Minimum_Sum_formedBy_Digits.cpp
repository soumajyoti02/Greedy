Question : Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array;
All digits of the given array must be used to form the two numbers.
Any combination of digits may be used to form the two numbers to be summed.  Leading zeroes are permitted.
If forming two numbers is impossible (i.e. when n==0) then the "sum" is the value of the only number that can be formed;


Input:
N = 6
arr[] = {6, 8, 4, 5, 2, 3}
Output:
604
Explanation:
The minimum sum is formed by numbers 
358 and 246;


Input:
N = 5
arr[] = {5, 3, 0, 7, 4}
Output:
82
Explanation:
The minimum sum is formed by numbers 
35 and 047;


Approach :
i) Sort the Array;
ii) Make a digit from even indexes and make another digit from odd indexes of that sorted array;
iii) Return their sum;


Code Below :::


class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        long long int num1 = 0, num2 = 0;
        sort(arr,arr + n);
        for(int i = 0; i < n; i++) 
        {
            if(i % 2 == 0)
            {
                num1 = num1 * 10 + arr[i];
            }
            else num2 = num2 * 10 + arr[i];
        }
        return num1 + num2;
    }
};










  
  
