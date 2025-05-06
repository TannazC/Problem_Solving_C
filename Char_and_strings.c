/*
Character and String Practice Module
Author: Tannaz Chowdhury  
Date: 2025

This file contains various C and Python exercises for understanding character arrays, string manipulation, and pointer behavior. Each function is annotated to help beginners understand what’s happening at each step.
*/

// -----------------------------------------------------------------------------
// Question 1: Reverse words in a string (C)
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reverses the order of words in a string, returns a new string.
// Input is unchanged.
char* reverse_words(const char *str) {
    char *copy = strdup(str);  // Duplicate input (safe, won't modify original)
    char *words[50];           // Array to store pointers to each word
    int count = 0;             // Number of words

    // Tokenize input string into words using space as delimiter
    char *token = strtok(copy, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // Allocate memory for result string
    int len = strlen(str);
    char *result = malloc(len + 1);  // +1 for null terminator
    result[0] = '\0'; // Initialize as empty string

    // Concatenate words in reverse order into result
    for (int i = count - 1; i >= 0; i--) {
        strcat(result, words[i]);
        if (i > 0) strcat(result, " ");
    }

    free(copy); // Free duplicated input string
    return result;  // Caller must free returned string
}


// -----------------------------------------------------------------------------
// Question 2: Count lowercase alphabet letters (C)
// -----------------------------------------------------------------------------
// Given a string, counts how many times each lowercase letter appears.
// Result is stored in a 26-element int array (index 0 = 'a', 1 = 'b', ..., 25 = 'z')
void count_letters(const char *s, int counts[26]) {
    for (int i = 0; i < 26; i++) counts[i] = 0;  // Initialize counts
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            counts[s[i] - 'a']++;
        }
    }
}


// -----------------------------------------------------------------------------
// Question 3: Replace 'winter' with 'summer' in string (C)
// -----------------------------------------------------------------------------
void replace_ws(char *s) {
    char *copy = strdup(s);              // Make a safe copy to modify
    char *words[100];                    // Store word pointers
    int count = 0;
    char result[1000];                   // Output buffer
    result[0] = '\0';                   // Start with empty result

    // Split into tokens
    char *token = strtok(copy, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // Reconstruct string, replacing "winter"
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], "winter") == 0) {
            strcat(result, "summer");
        } else {
            strcat(result, words[i]);
        }
        if (i < count - 1) strcat(result, " ");
    }

    strcpy(s, result);  // Copy result back to original
    free(copy);
}


// -----------------------------------------------------------------------------
// Question 4: Sort lists of integers by average (Python)
// -----------------------------------------------------------------------------
// Implements a class MyList that can be sorted by average value
class MyList:
    def __init__(self, numbers):
        self.numbers = numbers

    def average(self):
        return sum(self.numbers) / len(self.numbers)

    def __lt__(self, other):  # Define less-than comparison based on average
        return self.average() < other.average()

    def __repr__(self):       # Define string representation for printing
        return str(self.numbers)


// -----------------------------------------------------------------------------
// Question 5: Convert decimal string to binary string (C)
// -----------------------------------------------------------------------------
char* dec2bin(const char *decimal) {
    int num = atoi(decimal); // Convert string to integer

    // Handle special case: input is 0
    if (num == 0) {
        char *bin = malloc(2);
        strcpy(bin, "0");
        return bin;
    }

    char temp[64]; // Temporary buffer to store reversed binary
    int index = 0;

    // Convert to binary (in reverse)
    while (num > 0) {
        temp[index++] = (num % 2) + '0'; // Get binary digit as character
        num = num / 2;
    }

    // Allocate final string and reverse the order
    char *binary = (char *)malloc(index + 1);
    for (int i = 0; i < index; i++) {
        binary[i] = temp[index - i - 1];
    }
    binary[index] = '\0';  // Null-terminate

    return binary;  // Caller must free
}


// -----------------------------------------------------------------------------
// Question 6: Concatenate all strings in a string array (C)
// -----------------------------------------------------------------------------
char* concat_all(char **strs, int strs_sz){
    int total_len = 0;
    for (int i = 0; i < strs_sz; i++) {
        total_len += strlen(strs[i]);  // Sum total length of all strings
    }

    char *result = (char *)malloc(total_len + 1);  // +1 for null terminator
    result[0] = '\0';  // Start as empty string

    for (int i = 0; i < strs_sz; i++) {
        strcat(result, strs[i]);  // Append each string
    }

    return result;  // Caller must free
}

// Example main (not part of function submission)
// int main(void){
//     char *strs[] = {"ESC", "MAT", "MSE", "CIV"};
//     char *all = concat_all(strs, 4);
//     printf("%s\n", all);  // Should print: ESCMATMSECIV
//     free(all);
// }
