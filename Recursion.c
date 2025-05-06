/*
Recursion Practice Module
Author: Tannaz Chowdhury
Date: 2025

This file includes recursive functions and exercises designed to help understand
recursive thinking in C programming. Each function is annotated to explain step-by-step
what it does, how recursion unfolds, and when base cases are hit.
*/

#include <stdio.h>

// -----------------------------------------------------------------------------
// Question 1: Factorial using recursion
// -----------------------------------------------------------------------------
// Computes factorial of n recursively: n! = n * (n-1) * ... * 1
// Assumes n >= 1
int fact(int n) {
    if (n == 1) return 1;           // Base case
    return n * fact(n - 1);         // Recursive case
}

// -----------------------------------------------------------------------------
// Question 2: Strictly increasing array (recursive check)
// -----------------------------------------------------------------------------
// Returns 1 if the array is strictly increasing, 0 otherwise
// No loops or helper functions allowed
int is_increasing(int *arr, int sz) {
    if (sz <= 1) return 1;               // Base case: 0 or 1 elements = increasing
    if (arr[0] >= arr[1]) return 0;      // Not increasing if this pair fails
    return is_increasing(arr + 1, sz - 1); // Check the rest of the array
}

// -----------------------------------------------------------------------------
// Question 3: Compare two arrays recursively
// -----------------------------------------------------------------------------
// Compares arr1 and arr2 for element equality
// Returns 1 if same size and all elements match, 0 otherwise
int compare_blocks(int* arr1, int arr1_sz, int* arr2, int arr2_sz) {
    if (arr1_sz != arr2_sz) return 0;     // Mismatched sizes
    if (arr1_sz == 0) return 1;           // Base case: both empty
    if (*arr1 != *arr2) return 0;         // Current elements differ
    return compare_blocks(arr1 + 1, arr1_sz - 1, arr2 + 1, arr2_sz - 1);
}

// -----------------------------------------------------------------------------
// Question 4: Count digits recursively
// -----------------------------------------------------------------------------
// Counts the number of digits in a positive integer
int count_digits(int n) {
    if (n < 10) return 1;             // Base case: single digit
    return 1 + count_digits(n / 10);  // Strip one digit and count again
}

// -----------------------------------------------------------------------------
// Question 5: Sum of array using recursion
// -----------------------------------------------------------------------------
// Returns sum of array elements
int sum_array(int *arr, int sz) {
    if (sz == 0) return 0;           // Base case: no elements
    return arr[0] + sum_array(arr + 1, sz - 1);
}

// -----------------------------------------------------------------------------
// Question 6: Reverse print an array using recursion
// -----------------------------------------------------------------------------
// Prints elements in reverse order
void print_reverse(int *arr, int sz) {
    if (sz == 0) return;             // Base case
    printf("%d ", arr[sz - 1]);
    print_reverse(arr, sz - 1);
}

// -----------------------------------------------------------------------------
// Question 7: Binary representation of an integer (recursive)
// -----------------------------------------------------------------------------
void print_binary(int n) {
    if (n == 0) return;
    print_binary(n / 2);             // Recurse before printing (MSB to LSB)
    printf("%d", n % 2);
}

// -----------------------------------------------------------------------------
// MAIN (optional test driver)
// -----------------------------------------------------------------------------
/*
int main() {
    int nums[] = {1, 2, 3, 4};
    printf("Factorial of 5: %d\n", fact(5));
    printf("Is increasing: %d\n", is_increasing(nums, 4));

    int a[] = {7, 8, 9};
    int b[] = {7, 8, 9};
    int c[] = {7, 8};
    printf("Compare A and B: %d\n", compare_blocks(a, 3, b, 3));
    printf("Compare A and C: %d\n", compare_blocks(a, 3, c, 2));

    printf("Digit count in 12345: %d\n", count_digits(12345));
    printf("Sum of array: %d\n", sum_array(nums, 4));
    printf("Reverse print: "); print_reverse(nums, 4); printf("\n");
    printf("Binary of 13: "); print_binary(13); printf("\n");

    return 0;
}
*/
