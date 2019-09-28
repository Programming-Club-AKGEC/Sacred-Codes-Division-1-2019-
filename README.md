# Editorials

## Intercept The Message
[Problem Link](https://www.codechef.com/SCD12019/problems/SCD1A)

Let's find the value w — the length of the longest common suffix of s and t. You can easily find it in one linear loop: just compare the last letters of s and t. If they are equal then compare before the last letters of s and t. And so on.
The last w letters of s and t are two equal strings which will be the result of after optimal moves. So the answer is |s|+|t|−2⋅w.

## Atapi Vatapi
[Problem Link](https://www.codechef.com/SCD12019/problems/SCD1B)

Precalculate the factorial upto 10^5 in order to minimize repeated calculations. This can be calculated iteratively and the values will not overflow due to mod operation at each step.

```
  for(int i = 1;i<=100000;i++) {
    fact[i] = (fact[i-1] * i) % MOD;
  }

```

For solution, the following relation holds good:-

```
  F(N) = N! - F(N-1)
  This is because R.H.S. can be expanded as :-
  N! - ((N-1)! - (N-2)! + (N-3)! ...... ) 
```
## Duvidha

[Problem Link](https://www.codechef.com/SCD12019/problems/SCD1C)

This problem can be simply solved using graph. Consider each ID as a node of an undirected graph and the pair of IDs represents an edge between the nodes of the graph. A gang represents a connected component of this graph. Firstly we find the size of the connected component which contains node 1(say Gaitonde's Gang). Now we find the size of all remaining components and check whether size of those components is greater than or equal to size of Gaitonde's Gang. If such a component is present then print NO else print YES.

Refer to the following link to learn about connected components:-

[Connected Components](https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/)

## Radcliffe

[Problem Link](https://www.codechef.com/SCD12019/problems/SCD1D)

The problem can be easily classified as 1-Dimensional Dynamic Programming. 

First we will define a recursive function to find the solution.

```
Pseudo Code:

MOD = pow(10, K)

func(curr, str)
{
	sol = 0;
	for(int i = curr;i < min(curr + 11, str.size());i++)
	{
		curr *= 10;
		curr += (str[i] - '0');

		// If all conditions are satisfied like,
		// 1. curr should be less than or equal to C 
		// 2. Must not contain any leading zero
		// 3. However, a single zero is allowed
		sol += func(i + 1, str);
	}
	return sol % MOD;
}
```
The logic behind using (curr + 11) is that the number should not exceed C and C has at max 10 digits.

This function will be able to pass the substasks, but it is too slow for Original Constraints.
This is due to repeated calculation of subproblems.
We can introduce Dynamic Programming here to optimize this recursive solution.
The code for that is given below.

## Gochi
[Problem Link](https://www.codechef.com/SCD12019/problems/SCD1E)

Approach 1:-
The key in the question is the retrieval of kth smallest element and updating the frequencies of the costs. In order to do that we can use Fenwick Tree to maintain the changes. If you are new to fenwick tree then you can refer the following links:-

[Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)

[Fenwick Tree](https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/)

So, now as the range of the cost is upto 10^5 we can create a fenwick tree of that size where each index represents the frequency of that particular cost. So for query of type 1 we can increament by 1. This basically creates a prefix sum of the frequencies.

Since we have prefix sums of frequencies from fenwick tree for the query of type 2 we can perform the binary search in such a way that we get Kth cheapest cost.

Once we got the cost of the pill now to find the number of factors simply find the power of all prime factors(p1, p2.... pn) and the number of factors will be (p1+1)(p2+1)...(pn+1).
You can refer the following link to find the number of factors:-

[Number of Factors](https://www.geeksforgeeks.org/total-number-divisors-given-number/)

Approach 2:-

Another easier approach is to make use of Policy based data structure. But here also one should know how to maintain multiple values in the set. In order to do that we just replace int with pair<int, int> in the syntax where the first value is your cost and second value is the ID to maintain distinction between two elements.

To know more about policy based data structure refer to the following link:-

[Policy Based Data Structure](https://www.geeksforgeeks.org/policy-based-data-structures-g/)

[Custom changes in PBDS](https://codeforces.com/blog/entry/13279)

## Saviours Play Game

[Problem Link](https://www.codechef.com/SCD12019/problems/SCD1F)

Solution:
The particularity of this problem which makes it different by other problem of this kind is that paths need to cross exactly one cell and Sartaj can go only right and down, Majid can go only right and up. Let's try to come up with a solution based on these facts. A good start is to analyze configurations possible for meeting cell. Sartaj can come either from right or down and Majid can come either from right or up. However, if both Sartaj and Majid come from right, they must have met in other cell as well before (the cell in the left of the meet one). Similarly, if one comes from up and other one from down, their paths will cross either on upper cell, lower cell or right cell.

Only 2 possible cases are: Sartaj comes from right, Majid comes from up or Sartaj comes from down, Majid comes from right. By drawing some skatches on paper, you'll see next cell visited after meeting one will have the same direction for both of them. More, they will never meet again. So Sartaj comes from right, goes to right, Majid comes from up, goes to up or Sartaj comes from down, goes to down and Majid comes from right, goes to right.

We can precalculate for dynamic programming matrixes and we're done.

dp1[i][j] = maximal cost of a path going from (1, 1) to (i, j) only down and right.

dp2[i][j] = maximal cost of a path from (i, j) to (1, m) going only up and right.

dp3[i][j] = maximal cost of a path from (m, 1) to (i, j) going only up and right.

dp4[i][j] = maximal cost of a path from (i, j) to (n, m) going only down or right.
