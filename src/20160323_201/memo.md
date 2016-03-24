# A

* n integers (n < 100)
* maximize the sum of differences between all pairs of two adjacent elements
* fix a remained element if the number of elements is odd

* greedy?

# B

* a permutation of length n (n < 10^5)
* n integers from 0 to n-1
* we can swap two elements at most once
* maximize fixed points
  * a fixed point => a[x] = x

* count fixed points of the initial permutation

# C

* game
* n distinct integers (n <= 100)
* allowed moves
  * choose two integers x,y from the set
    * if the set does not contains |x-y|
  * then add |x-y|
* who win?

## Example 1

A = {2, 3}

Alice: {2, 3} => {1}

## Example 2

A = {5, 3}

Alice: {5, 3} => {2}

## Example 3

A = {5, 6, 7}

Alice: {5, 6, 7} => {1, 7} or {2, 6} or {1, 2}
Bob: can move

* a player can win if n = 2

##

{2, 4, 6}
{3, 6, 9}

* multiples?

# D

* subsequence
* two strings s1, s2 and a string virus (|s1|, |s2|, |virus| <= 100)
* find the longest common subsequence of s1 and s2
  * such that it does not contain virus as a substring

* dp + hashing?

# E

* n integers x[1], x[2], ..., x[n]
* two integers a, b (0 <= b <= a <= 10^9)
* a - b <= 10^6
  * we can iterate
* allowed moves
  * subtract 1 from a
  * subtract a mod x[i] from a
* find the minimum number of moves needed to a => b

* maximum moves = b - a

## Example 1

```
n = 3
x = {3, 4, 5}
a = 30, b = 17
```

```
a = 30 / [3, 4, 5] => [0, 2, 0]
a = 29 / [3, 4, 5] => [2, 1, 4]
a = 28 / [3, 4, 5] => [1, 0, 3]
a = 27 / [3, 4, 5] => [0, 3, 2]
a = 26 / [3, 4, 5] => [2, 2, 1]
a = 25 / [3, 4, 5] => [1, 1, 0]
a = 24 / [3, 4, 5] => [0, 0, 4]
a = 23 / [3, 4, 5] => [2, 3, 3]
a = 22 / [3, 4, 5] => [1, 2, 2]
a = 21 / [3, 4, 5] => [0, 1, 1]
a = 20 / [3, 4, 5] => [2, 0, 0]
a = 19 / [3, 4, 5] => [1, 3, 4]
a = 18 / [3, 4, 5] => [0, 2, 3]
a = 17 / [3, 4, 5] => [2, 1, 2]
a = 16 / [3, 4, 5] => [1, 0, 1]
a = 15 / [3, 4, 5] => [0, 3, 0]
a = 14 / [3, 4, 5] => [2, 2, 4]
a = 13 / [3, 4, 5] => [1, 1, 3]
a = 12 / [3, 4, 5] => [0, 0, 2]
a = 11 / [3, 4, 5] => [2, 3, 1]
a = 10 / [3, 4, 5] => [1, 2, 0]
a = 9 / [3, 4, 5] => [0, 1, 4]
a = 8 / [3, 4, 5] => [2, 0, 3]
a = 7 / [3, 4, 5] => [1, 3, 2]
a = 6 / [3, 4, 5] => [0, 2, 1]
a = 5 / [3, 4, 5] => [2, 1, 0]
a = 4 / [3, 4, 5] => [1, 0, 4]
a = 3 / [3, 4, 5] => [0, 3, 3]
a = 2 / [3, 4, 5] => [2, 2, 2]
a = 1 / [3, 4, 5] => [1, 1, 1]
```