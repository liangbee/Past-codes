// Copyright 2017 Biyao Liang liangb@bu.edu
# include <iostream>  // include the iostream library

int main() {
  int n = 2;  // have an interger set to two
  int sum;  // the sum of all of n's proper divisors
  int a = 1;  // this term is used to find all proper divisors
  int flag = 1;
    while (n <= 888) {
      flag = 1;
      std::cout << n << " : ";
      a = 1;
      sum = 0;  // include 1
        while (a < n) {
            if (n%a == 0) {
              sum += a;
              if (flag == 1) {
                std::cout << a;
                flag = 0;
              } else {
              std::cout << "+" << a;  //  + the a to sum
              }
          }
        a++;  // plus 1 to a to check the next number
      }
      std::cout << " = " << sum << '\n';  // print result
      n++;
  }
  return 0;
}
