QUESTION : Given three stacks S1, S2, and S3 of the positive numbers, 
the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. 
Stacks are represented as an array, and the first index of the array represents the top element of the stack;

Input:
N1 = 3, N2 = 4, N3 = 2
S1 = {4,2,3}
S2 = {1,1,2,3}
S3= {1,4}
Output:
5
Explanation:
We can pop 1 element from the 1st stack, and 2
elements from the 2nd stack. Now remaining elements
yield the equal sum of the three stacks, that is 5.;

Input:
N1 =2, N2 = 1, N3 = 3
S1 = {4,7}
S2 = {10}
S3 = {1,2,3}
Output:
0
Explanation:
We will never get an equal sum after popping
some elements, so the answer will be 0.;


ALGORITHM :

Algorithm for solving this problem: 

Find the sum of all elements of in individual stacks.
If the sum of all three stacks is the same, then this is the maximum sum.
Else remove the top element of the stack having the maximum sum among three of stacks. Repeat step 1 and step 2.;
\

CODE :::::::::::::




// C++ program to calculate maximum sum with equal
// stack sum.
#include <bits/stdc++.h>
using namespace std;

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed
int maxSum(int stack1[], int stack2[], int stack3[], int n1,
		int n2, int n3)
{
	int sum1 = 0, sum2 = 0, sum3 = 0;

	// Finding the initial sum of stack1.
	for (int i = 0; i < n1; i++)
		sum1 += stack1[i];

	// Finding the initial sum of stack2.
	for (int i = 0; i < n2; i++)
		sum2 += stack2[i];

	// Finding the initial sum of stack3.
	for (int i = 0; i < n3; i++)
		sum3 += stack3[i];

	// As given in question, first element is top
	// of stack..
	int top1 = 0, top2 = 0, top3 = 0;
	while (1) {
		// If any stack is empty
		if (top1 == n1 || top2 == n2 || top3 == n3)
			return 0;

		// If sum of all three stack are equal.
		if (sum1 == sum2 && sum2 == sum3)
			return sum1;

		// Finding the stack with maximum sum and
		// removing its top element.
		if (sum1 >= sum2 && sum1 >= sum3)
			sum1 -= stack1[top1++];
		else if (sum2 >= sum1 && sum2 >= sum3)
			sum2 -= stack2[top2++];
		else if (sum3 >= sum2 && sum3 >= sum1)
			sum3 -= stack3[top3++];
	}
}

// Driven Program
int main()
{
	int stack1[] = { 3, 2, 1, 1, 1 };
	int stack2[] = { 4, 3, 2 };
	int stack3[] = { 1, 1, 4, 1 };

	int n1 = sizeof(stack1) / sizeof(stack1[0]);
	int n2 = sizeof(stack2) / sizeof(stack2[0]);
	int n3 = sizeof(stack3) / sizeof(stack3[0]);

	cout << maxSum(stack1, stack2, stack3, n1, n2, n3)
		<< endl;
	return 0;
}





