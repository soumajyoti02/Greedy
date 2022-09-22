QUESTION : You are given N pairs of numbers. In every pair, the first number is always smaller than the second number.
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion.
You have to find the longest chain which can be formed from the given set of pairs. 
  
Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}

Input:
N = 2
P[] = {5 10 , 1 11}
Output: 1
Explanation:The max length chain possible is only of
length one.
  
  
---------------------------------------------------------------------
  
  
Approach for this program is as follows :

Sort given pairs in increasing order of second values.
Take ans = 0 initially and prev = INT_MIN.
Now iterate on the given array and id arr[i].first>prev , then increase answer and prev=arr[i].second.
Finally return answer.
  
  -------------------------------
Let's take example arr=[ [1,2] , [7,8] , [4,5] ].

Sorting the array in increasing order of second point will give arr=[ [1,2] , [4,5] , [7,8] ].
Now we take  ans=0 and prev=INT_MIN.
Traverse in array.
At i=0, arr[i].first>prev, so ans=1 and prev=arr[i].second=2.
At i=1, arr[i].first>prev, so ans=2 and prev=5.
At i=2, arr[i].first>prev, so ans=3 and prev=8.
So our final answer will be 3.
  
  
  ### CODE BELOW ###

  

class Solution{
public:
    /*You are required to complete this method*/
    
    bool static comp(val fst, val sec){
        return fst.second < sec.second;
    }
    
    int maxChainLen(struct val p[], int n){
        sort(p, p + n, comp); //Sort by value of second
        int ans = 0;
        int prev = INT_MIN; // Because before p[0] nothing is present
        for(int i = 0; i < n; i++)
        {
            if(p[i].first > prev) // Check if p[i]'s first is greater than last second.
            {
                prev = p[i].second;
                ans++;
            }
        }
        return ans;
    }
};
