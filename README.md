
# LeetCode Problem Collection (Algorithms).
https://leetcode.com/problemset/algorithms/

#Table of Content
[TOC]
# Problems:
## 1. Two Sum (Easy)
Given an array of integers, return **indices** of the two numbers such that they add up to a specific *target*.
You may assume that each input would have **exactly** one solution.

**Example:**
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
### Solution 1: Brute Force [Accepted]
Loop through all pairs of elements and check if the sum equals *target*.

**Time complexity** : *O*(*N*^2^​​ ).
**Space compexity**: *O*(1)
**Execution time**: C++  486ms, C# 615ms

### Solution 2: Hash Table [Accepted]
Pass through elements of the array storing putting indices of values into hash table and checking if hash table already contains a value such that it's sum with current element equals **target**.

**Time complexity** : *O*(*N*^2^​​ )
**Space compexity**: *O*(1)
**Execution time**: C++  486ms, C# 615ms

- - -

## 2. Add Two Numbers 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

**Example:**
```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```

### Solution [Accepted]
Pass through list calculating sum digit by digit and keeping track of carry flag.
 **Time complexity** :Time complexity : *O*(max(*N1*, *N2*))
**Space compexity**: *O*(1)
**Execution time**: C++ 42ms, C# 185ms

## 2.1 Followup: Add Two Numbers Stored in Non-Reversed Order
### Solution
Invert both lists in first pass and then calculate sum as above (optionally inverting lists back).
 **Time complexity** :Time complexity : *O*(2*max(*N1*, *N2*))
**Space compexity**: *O*(1)
**Execution time**: -


- - -
## 3. Longest Substring Without Repeating Characters (Medium)
Given a string, find the length of the *longest substring* without repeating characters.

**Examples:**
```
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

### Solution 0: Brute Force [Time Limit Exceeded (C++ accepted, surprisingly)]
Check all substrings.

**Time complexity** : *O*(N^3^​​).
**Space compexity**: *O*(1).
**Execution time**: C++ 599ms, C# Time Limit Exceeded

### Solution 1: Brute Force with HashSet [Time Limit Exceeded, C++ Accepted]
Store scanned substring characters in hash set so we can quickly check if next character is repeating.
*Note*: If set of characters is small (for example, letters only) we can use array of boolean instead of hash set.

**Time complexity** : *O*(*N*^2^​​ ).
**Space compexity**: *O*(k), where k is number of acceptable character.
**Execution time**: C++ 32ms, C# Time Limit Exceeded

### Solution 2: Sliding Window [Accepted]
Use a window of non-repeating substring [*i*, *j*] and keep indices of window's characters in hash map. First set window to [*i*=0, *j*=0]. Then for next character *s*[*j*+1] check if it is already in the window (in the hash map). If there is such character at index *prev* then remove from hash map all characters from *i* to *prev* and slide the beginning of the window: *i* = *prev* + 1. Then add new character to hash map and increase window: *j* = *j* + 1. Keep track of maximum encountered window length.
*Note*: As in previous solution, when set of characters is small (for example, letters only) we can use array ro store idices instead of hash map.

**Time complexity** : *O*(*N*).
**Space compexity**: *O*(k), where k is number of acceptable character.
**Execution time**: C++ 12ms, C# 119ms.

- - -

## 4. Median of Two Sorted Arrays (Hard)
There are two sorted arrays *nums1* and *nums2* of size *N1* and *N2* respectively.
Find the median of the two sorted arrays. The overall run time complexity should be *O*(log (*N1*+*N2*)).

**Example 1:**
```
nums1 = [1, 3]
nums2 = [2]
The median is 2.0
```

**Example 2:**
```
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
```

### Solution 1: "Merge" method [Accepted]
We need to find element *k* = (*N1*+*N2*)/2 in merged sorted array *M*. When *N*=*N1*+*N2* is odd then median is *M*[*k*], otherwise it is (*M*[*k*] + *M*[*k-1*]) / 2.
*Note*: No actual merging is necessary, we need just count elements as with merge sort algorithm. 

**Time complexity** : *O*(min(*N1*, *N2*))
**Space compexity**: *O*(1)
**Execution time**: C++ 48ms, C# 196ms

### Solution 2: Binary search for *k*-th element [Accepted]
As above we need to find *k*-th element in the merged sequence.
First we compare middle points *k1* = *N1*/2 and *k2* = *N2*/2. Suppose, *nums1*[*k1*] < *nums2*[*k2*]. Then if *k* < *k1*+ *k2* the *k*-th element belong to arrays *nums1*[0..N1] and *nums2*[0..k2-1]. Otherwise it is *(k-k1-1)*-th element in arrays *nums1*[k1+1..N1] and *nums2*[0..N2]. Similar formulas work for case where *nums1*[*k1*] > *nums2*[*k2*].
Now we can do recursive binary search for selected subarrays. 

**Time complexity** : *O*(log *N*)
**Space compexity**: *O*(1)
**Execution time**: C++ 32ms, C# 189ms

- - -
## 5. Longest Palindromic Substring (Medium)
Given a string *S*, find the longest palindromic substring in *S*. You may assume that the maximum length of *S* is 1000, and there exists one unique longest palindromic substring.

### Solution 0: Brute Force [Accepted]
Check all substrings.

**Time complexity** : *O*(N^3^​​).
**Space compexity**: *O*(1).
**Execution time**: C++ 576ms, C# 372ms

### Solution 1: Dynamic programming [Accepted, C++ Memory Limit Exceeded]
Build table *DP*[*N*, *N*] of boolean values where *DP*[*i*, *j*] is *true* when substring *S*[*i*..*j*] is palindromic.
First initialize the table for substring of length 1 (*DP*[*i*, *i*] = *true*) and length 2 (*DP*[*i*,*i*+1] = *true*, when *S*[*i*] = *S*[*i*+1]).
Then fill table for lengths 3 to N using formula: *DP*[*i*, *j*] is *true* when *DP*[*i*+1,*j*-1] is *true* and *S*[*i*] = *S*[*j*].

**Time complexity** : *O*(N^2^​​).
**Space compexity**: *O*(N^2^).
**Execution time**: C++ Memory Limit Exceeded, C# 239ms

### Solution 2: Expand palindrome from center [Accepted]
For each character of the string *S*[*i*] try to build palindrome around that character and around *S*[*i*..*i*+1] if *S*[*i*] = *S*[*i*+1]

**Time complexity** : *O*(N^2^​​).
**Space compexity**: *O*(1).
**Execution time**: C++ 59ms, C# 129ms


* * *
# Summary

  N | Problem                                         | Diff.  | Solution/Comlexyty                           |  C++   |  C#    | Java
--- | ----------------------------------------------- | ------ | -------------------------------------------- | ------ | ------ | -----
  1 | Two Sum                                         | Easy   | 1) Brute Force: *O*(*N*²)                    |  486*ms* |  615*ms* |
    |                                                 |        | 2) Hash Table: time *O*(*N*), space *O*(*N*) |   16*ms* |  412*ms* |
  2 | Add Two Numbers                                 | Medium | *O*(max(*N1*,*N2*))                          |   42ms |  185ms |
2.1 | Followup: Add Two Numbers Stored in Non-Reversed Order | Medium | *O*(max(*N1*,*N2*))                   |        |        |
  3 | Longest Substring Without Repeating Characters  | Medium | 0) Brute Force: *O*(*N*³)                    |  599ms | Time Limit |
    |                                                 |        | 1) Brute Force with HashSet: *O*(*N*²)       |  32 ms | Time Limit |
    |                                                 |        | 2) Sliding Window: *O*(*N*)                  |   12ms |  119ms |
  4 | Median of Two Sorted Arrays                     | Hard   | 1) "Merge" method: *O*(min(*N1*, *N2*))      |   48ms |  196ms |
    |                                                 |        | 2) Binary search for *k*-th element: *O*(log *N*) |   32ms |  189ms |
  5 | Longest Palindromic Substring                   | Medium | 0) Brute Force: *O*(*N*³)                    |  576ms |  372ms |
    |                                                 |        | 1) Dynamic programming: time *O*(*N*²), space *O*(*N*²) | Memory Limit | 239ms |
    |                                                 |        | 2) Expand palindrome from center: time *O*(*N*²), space *O*(1) | 59ms | 129ms²

