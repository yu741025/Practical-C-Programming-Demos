
/*This implementation demonstrates how to pass the address of a variable to a function, return it as a pointer, and use that pointer to access the original variable’s value and address.
 * 1. Declare an integer variable `val` in the main function and initialize it to 5.
 */

/*
 * 2. Use the address-of operator `&` to pass the address of `val` to the function `f1()`,
 *    where it is received as a pointer parameter `int *p2val`.
 *    - Internally, this works as: `int *p2val = &val;`
 */

/*
 * 3. The function `f1()` then returns the pointer `p2val`.
 */

/*
 * 4. In the main function, use an external pointer variable to store the pointer 
 *    returned by `f1()`: `int *p2val = f1();`
 */

/*
 * 5. As a result, `p2val` is a pointer that points to the originally declared 
 *    variable `val`.
 */

/*
 * 6. Key concepts:
 *    - `p2val` represents the memory address of `val`.
 *    - `*p2val` represents the value of `val`.
 *    - `&p2val` represents the memory address of the pointer variable `p2val` itself.
 */
#include <stdio.h>

int *f1(int *p2Val) { return p2Val; }

int main(int argc, char const *argv[]) {
  int val = 5;
  // printf("Value %d is at %p\n", val, &val);

  int *p2Val = f1(&val);
  printf("Value %d is at %p\n", *p2Val, p2Val);

  return 0;
}
