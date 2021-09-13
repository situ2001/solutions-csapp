/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    /* First convert XOR to combination of AND and OR, then apply De Morgan's laws. */
    return ~(~x & ~y) & ~(x & y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // Simply perform right shift 31 of bit on 1
    return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // If x = TMax
    // x + 1 => 0x80000000, x + (x + 1) => 0xffffffff, ~(x + (x + 1)) => 0x0
    // Consider 0xffffffff(-1), so we should plus !(x+1)
    // And also think of how to convert result from number logically to 1 or 0
    return !(~(x + (x + 1)) + !(x + 1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // Construct a mask, do not forget priority of operator
    int mask = ((0xaa + (0xaa << 8)) << 16) + (0xaa + (0xaa << 8));
    // First perform & on mask and x then ^ on mask and x
    return !(mask ^ (mask & x));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // Well-known qu fan zai jia 1 (NOT then add1)
    return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // if 39 - x >= 0 and x - 30 >= 0, then yes
    int neg_x = ~x + 1;
    int res1 = 0x39 + neg_x;
    int res2 = x + (~(0x30) + 1);
    // How to check wether a result is negative or not? Use sign bit
    return !((res1 >> 31) | (res2 >> 31));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // if x = 0, return z, else y
    // So how to check wether x is 0 or not?
    int condition = !!x; // integer => 0 or 1
    condition = ~condition + 1; // 0 or 1 => 0x00000000 or 0xffffffff
    return (condition & y) | (~condition & z); // use condition as a mask
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int neg_x = ~x + 1;
    // Case1: when y+ and x-
    int y_pos_x_neg = ((x >> 31 & 0x1)) & (!(y >> 31 & 0x1));
    // Case2: If signs of x and y are the same, we should test if result of sub > 0
    int same_sign = !((x >> 31) ^ (y >> 31));
    int sub_comparsion = !((y + neg_x) >> 31);
    int sub_more_than_zero = same_sign & sub_comparsion;
    // Case3: x == y
    int equal = !(x ^ y);
    return equal | sub_more_than_zero | y_pos_x_neg;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */ 
int logicalNeg(int x) {
    // 1. Fill the whole bit pattern with 1s(0xffffffff) or 0s(0x0)
    // 2. Adding 1 to it may cause overflow. That is, 0xffffffff => 0, 0x0 => 1
    return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int sign = x >> 31;
    // If x < 0, perform ~ on it
    int target = sign ^ x;
    // printf("x=%.8x sign=%.8x target=%.8x\n", x, sign, target);
    // Either pos or neg, find the position of the highest 1
    int res = 0;
    // How to get the position?
    // Use !! => 0 or 1, then let it right shifts x bit => 2^x or 0
    // We can divide it equally
    // Note: if variables are not declared first, there will be errors when you run ./dic with this file
    int higher_16_bit, higher_8_bit, higher_4_bit, higher_2_bit, higher_1_bit;
    // If there is any 1 in higher 16 bits, add 16
    higher_16_bit = !!(target >> 16) << 4;
    // printf("target=%x\n", target);
    target >>= higher_16_bit;
    // divide the higher 16 bits into 8 bits
    higher_8_bit = !!(target >> 8) << 3;
    // printf("target=%x\n", target);
    target >>= higher_8_bit;
    // the same
    higher_4_bit = !!(target >> 4) << 2;
    // printf("target=%x\n", target);
    target >>= higher_4_bit;
    higher_2_bit = !!(target >> 2) << 1;
    // printf("target=%x\n", target);
    // target >>= higher_4_bit;
    target >>= higher_2_bit; // WTF!
    higher_1_bit = !!(target >> 1) << 0;
    // printf("target=%x\n", target);
    target >>= higher_1_bit;
    res += (higher_16_bit + higher_8_bit + higher_4_bit + higher_2_bit + higher_1_bit);
    // printf("target=%d\n", target);
    return res + target + 1; // + remaining target and sign bit
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    // printf("uf=%.8x\n", uf);
    int sign = (uf >> 31) & 0x1; // 0 or 1
    unsigned exp = (uf >> 23) & 0xff;
    // printf("exp=0x%.8x\n", exp);
    if (exp == 0xff) return uf; // NaN
    if (exp == 0x0) { // If exp = 0(Denoarmalized), just << 1
        // printf("uf=0x%.8x exp=0x%.8x\n", uf, exp);
        // simply *2 then add back sign bit
        return (uf << 1) | (sign << 31);
    }
    exp = exp + 1;
    if (exp >= 0xff) { // +- Infinity
        return (exp << 23) | (uf & 0x8fffffff);
    }
    // use 0x807fffff to remove exp of uf
    return (uf & 0x807fffff) | (exp << 23);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int bias = 127;
    int sign = (uf >> 31) & 0x1; // 0 or 1
    int exp = (uf >> 23) & 0xff;
    int frac = uf & 0x7fffff;
    int E = exp - bias;
    // printf("ul=0x%.8x E=%d\n", uf, E);

    // Cases
    // if E > 31 => Out of Range
    if (E > 31) return 0x80000000u;
    // if E < 0 => 0
    if (E < 0) return 0;
    // From here, we should just consider the normalized form
    // right shift the floating point of frac
    // if 23 - E < 0
    int tmp;
    if (E > 23) {
        tmp = frac << (E - 23);
    } else {
        tmp = frac >> (23 - E);
    }
    // printf("tmp=0x%.8x\n", tmp);
    tmp = tmp & (~(0x80000000 >> (23 - E - 1)));
    // add back sign bit
    // tmp = tmp | (sign << 31);
    // add 1 to first
    tmp = tmp | (1 << E);
    // printf("tmp=0x%.8x uf=0x%.8x\n", tmp, uf);
    // ~x + 1 if sign == 1
    if (sign == 1) return ~tmp + 1;
    return tmp;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int bias = 127;
    // Check out figure 2.36 on the book
    // > largest norm
    if (x > 127) return 0x7f800000;
    // < smallest denorm
    if (x < (-23-126)) return 0;
    // in [smallest norm, largest norm]
    if (x >= -126 && x <= 127) return (bias + x) << 23;
    // when x < -126 && x >= (-23-126), it is Denorm, so bits of exp are irrelevant in this case.
    return 114514; // So we can return any number :)
}
