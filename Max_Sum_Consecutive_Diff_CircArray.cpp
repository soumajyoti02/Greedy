QUESTION : Given an array of n elements. Consider array as circular array i.e element after an is a1. 
The task is to find maximum sum of the difference between consecutive elements with rearrangement of array element allowed 
i.e after rearrangement of element find |a1 – a2| + |a2 – a3| + …… + |an – 1 – an| + |an – a1|;

Input : arr[] = { 4, 2, 1, 8 }
Output : 18
Rearrange given array as : { 1, 8, 2, 4 }
Sum of difference between consecutive element
= |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1|
= 7 + 6 + 2 + 3
= 18.

Input : arr[] = { 10, 12, 15 }
Output : 10;

-----------------------------------------------------------------
  
Simple Approach For Solving this Problem : 

arrange element in following manner: 
a1, an, a2, an-1,…., an/2, a(n/2) + 1;

 { 1, 8, 2, 4 }
Sum of difference between consecutive element
= |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1|
= 7 + 6 + 2 + 3
= 18
  
We Can Obtain this Configuration by Sorting that Array and Taking --> 1st, last, 2nd, 2nd'Last', 3rd, 3rd'Last',....
Now Run a While Loop (i-->biggining < j-->end) 
 
  Add the absolute difference of 1st(i) and last(j)
  Add the Absolute difference of arr[i+1] and arr[j] also; because in array {1, 2, 4, 8} We have to find (1-8)+(2-8)+(2-4)+(4-1)
    ---> From this step we will get (2 - 8) part.

END WHILE

Add sum = sum + abs(arr[0] + arr[i]) to get last value i.e.(4 - 1);
return the sum;



  ### CODE BELOW ###

long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int i = 0;
    int j = n - 1;
    long long sum = 0;
    while(i < j)
    {
        sum = sum + abs(arr[i] - arr[j]);
        sum = sum + abs(arr[i+1] - arr[j]);
        i++;
        j--;
    }
    sum = sum + abs(arr[0] - arr[i]); // To add the absolute difference of 1st and last.
    return sum;
}
