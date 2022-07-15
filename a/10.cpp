/*

Let number chosen to represent N as a sum of consecutive numbers be X + 1, X + 2, X + 3 …. Y 

Sum of these chosen numbers = Sum of first Y natural numbers – Sum of first X natural number 

Sum of first Y natural number = \frac {Y \cdot (Y + 1)} {2}
Sum of first X natural number = \frac {X \cdot (X + 1)} {2}
We know that,
N = Sum of first Y natural number – Sum of first X natural number
N = \frac {Y \cdot (Y + 1)} {2} - \frac {X \cdot (X + 1)} {2}
2N = Y \cdot (Y + 1) - X \cdot (X + 1)
2N = Y ^ 2 - X ^ 2 + Y - X
2N = (Y - X) \cdot (Y + X + 1)
Let Y – X = a, Y + X + 1 = b
Y + X + 1 > Y – X, b > a
X = \frac {a - b - 1} {2}, Y = \frac {a + b + 1} {2}
2N = a * b
It means that a and b are factor of 2N, we know that X and Y are integers so,
1. b – a – 1 => multiple of 2 (Even number)
2. b + a + 1 => multiple of 2 (Even number)

Both conditions must be satisfied

From 1 and 2 we can say that either one of them (a, b) should be Odd and another one Even

So if the number (2N) has only odd factors (can’t be possible as it is an even number (2N not N) ) or only even factors we can’t represent it as a sum of any consecutive natural numbers

So now, we have to now only check whether it has an odd factor or not

1. If the number (2N not N) does not have any odd factor (contains only even factor means can be represented as 2 ^ k               ) then we can’t represent it as a sum of consecutive number

2. If the number (2N not N) has an odd factor then we can represent it as a sum of a consecutive number

After this we have to only check whether we can represent (2N as 2^k) or not

if Yes then answer is false or 0
if No then answer is true or 1

*/

#include <bits/stdc++.h>
using namespace std;

long long int canBeSumofConsec(long long int n)
{
	// Updating n with 2n
	n = 2 * n;
	// (n & (n - 1)) => Checking whether we can write 2n as 2^k
	// if yes (can't represent 2n as 2^k) then answer 1
	// if no (can represent 2n as 2^k) then answer 0
	return ((n & (n - 1)) != 0);
}

int main()
{
	long long int n = 10;
	cout<<canBeSumofConsec(n)<<"\n";
}
