#include <gtest/gtest.h>

unsigned int Fibonacci(unsigned int number) {
  if (number == 0) return 0;
  return number == 1 ? 1 : Fibonacci(number - 1) + Fibonacci(number - 2);
}

TEST (FibonacciTest, numbers) {
  
  EXPECT_EQ(0, Fibonacci(0));
  EXPECT_EQ(1, Fibonacci(1));
  EXPECT_EQ(5, Fibonacci(5));
  EXPECT_EQ(21, Fibonacci(8));
}
