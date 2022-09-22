QUESTION : The task is to find the smallest number with given sum of digits as S and number of digits as D.
  
Input:
S = 9 
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.
  
Input:
S = 20
D = 3
Output:
299
Explanation:
299 is the smallest number
possible with sum = 20
and total digits = 3.
  
Simple Approach For this program is as follows :

--->> Given D Blank spaces. We have to put numbers there such that their sum is equals to S.
1) If we put 9 in all place and still their sum is less than given sum then no answer is possible. So return -1;

2) Else start filling numbers from the end. Fill with 9 till sum is greater than 9.
  2.1) Then Check if i == 0 or not. If 0 then No option left, so put that remaining sum in that place;
    2.1.1) ELse : Put sum - 1 in that place and decreament i ( i -- ) to move the pointer to previous value.
    2.1.2) Then Put 0 till i = 0 by a while loop.
    2.1.3) Then put 1 in i == 0 position and return the string.
      
      
VIDEO LINK : https://youtu.be/H7iqIjbWty4     
      
      ### CODE BELOW ###
      
      
      
class Solution{   
public:
    string smallestNumber(int S, int D){
        if(9*D < S) return "-1"; 
        // If Sum is greater than Maximum possible value i.e. the sum of numbers by putting 9 in all vacant places.
      
        string ans = "";
        for(int i = D-1; i >= 0; i--) // Start Filling from end
        {
            if(S > 9) // If sum is greater than 9 then Put 9 in that position.
            {
                ans = '9' + ans;
                S = S - 9;;
            }
            else
            {
                if(i == 0) ans = to_string(S) + ans; // If i == 0 then No options are left. So put the remaining value
                else
                {
                    ans = to_string(S-1) + ans; // Put S-1 in that place and put 0 till i == 0, then Put 1 in i=0;
                    i--;
                    while(i > 0)
                    {
                        ans = '0' + ans;
                        i--;
                    }
                    ans = '1' + ans;
                    break;
                }
            }
        }
         return ans;
    }
};  
