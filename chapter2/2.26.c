// You are given the assignment of writing a function that determines whether one
// string is longer than another. You decide to make use of the string library function
// strlen having the following declaration:
#include <string.h>

// Here is your first attempt at the function:
/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
int strlonger(char *s, char *t)
{
    return strlen(s) - strlen(t) > 0;
}

// When you test this on some sample data, things do not seem to work quite
// right. You investigate further and determine that, when compiled as a 32-bit
// program, data type size_t is defined (via typedef) in header file stdio.h to be
// unsigned.
// A. For what cases will this function produce an incorrect result?
// B. Explain how this incorrect result comes about.
// C. Show how to fix the code so that it will work reliably.

// NOTE: You should run gcc with arg -m32
/* FIXED Code */
int strlonger_fixed(char *s, char *t)
{
    return (int) (strlen(s) - strlen(t)) > 0;
    // OR
    // return strlen(s) > strlen(t);
}

#include <stdio.h>

int main()
{
    // When result is correct
    printf("1145 is longer than 14? %d\n", strlonger("1145", "14"));
    printf("114 is longer than 514? %d\n", strlonger("114", "514"));
    // A. Found some cases (when length of s is shorter then length of t)
    printf("1 is longer than 14514?! %d\n", strlonger("1", "14514"));
    // B. Explain it
    // In this case, strlen("1") yields 1 and strlen("14514") yields 4, but both the types of them are unsigned!
    // So we do our comparsion with the type unsigned
    // 1 - 4 == 0xfffffffd and 0 == 0x00000000, so the unsigned comparsion of -3 > 0 returns true
    // C. How to fix the code?
    // Just EXPLICITLY do type casting
    printf("1 is longer than 14514?? %d\n", strlonger_fixed("1", "14514"));
}
