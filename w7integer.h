// Copyright 2017 ShimingGao tonygao@bu.edu
// Copyright 2017 BiyaoLiang liangb@bu.edu
#ifndef Integer_w7
#define Integer_w7
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
std::string addition_ss(std::string a, std::string b) {
  char char1 = '1';
  char charneg = '-';
  std::string astr;
  std::string bstr;
  int asize = a.length();
  int bsize = b.length();
  bool asign1 = true;
  bool bsign1 = true;
  if (a[0] == '-') {
    asize = asize - 1;
    astr = (a).substr(1, asize);
    asign1 = false;
  } else {
    astr = a;
  }
  if (b[0] == '-') {
    bsize = bsize - 1;
    bstr = (b).substr(1, bsize);
    bsign1 = false;
  } else {
    bstr = b;
  }
  int size1;
  if (asize > bsize) {
    int i;
    std::string zeros;
    for (i = 0; i < (asize - bsize); i++) {
      zeros = zeros + "0";
    }
    bstr = zeros + bstr;
    size1 = asize;
  }
  if (asize < bsize) {
    int i;
    std::string zeros;
    for (i = 0; i < (bsize - asize); i++) {
      zeros = zeros + '0';
    }
    astr = zeros + astr;
    size1 = bsize;
  }
  if (asize == bsize) {
    size1 = asize;
  }
  if (asign1 == true && bsign1 == true) {
    int n = 0;
    std::string resstring;
    for (int j = size1 - 1; j >= 0; j--) {
      int res;
      int res1;
      res = astr[j] + bstr[j] - '0' - '0' + n;
      if (res >= 10)
        n = 1;
      if (res < 10)
        n = 0;
      res1 = res % 10;
      char c = res1 + '0';
      resstring = resstring + c;
    }
    if (n == 1)
      resstring = resstring + char1;
    reverse(resstring.begin(), resstring.end());
    std::string result;
    result = resstring;
    return result;
  }
  if (asign1 == false && bsign1 == false) {
    std::string resstring;
    int n = 0;
    for (int j = size1 - 1; j >= 0; j--) {
      int res;
      int res1;
      res = astr[j] + bstr[j] - '0' - '0' + n;
      if (res >= 10)
        n = 1;
      if (res < 10)
        n = 0;
      res1 = res % 10;
      char c = res1 + '0';
      resstring = resstring + c;
    }
    if (n == 1) {
      resstring = resstring + char1;
    }
    resstring = resstring + charneg;
    reverse(resstring.begin(), resstring.end());
    std::string result;
    result = resstring;
    return result;
  }
  if (asign1 == false ^ bsign1 == false) {
    int comp;
    int k;
    for (k = 0; k < size1; k++) {
      if (astr[k] > bstr[k]) {
        comp = 1;
        break;
      }
      if (astr[k] < bstr[k]) {
        comp = 0;
        break;
      }
    }
    if (k == size1) {
      comp = 2;
    }
    if (comp == 1) {  // start a>b
      int n = 0;
      std::string resstring;
      int res;
      int res1;
      for (int j = size1 - 1; j >= 0; j--) {
        res = astr[j] - bstr[j] - n + 10;
        if (res < 10)
          n = 1;
        if (res >= 10)
          n = 0;
        res1 = res % 10;
        char c = res1 + '0';
        resstring = resstring + c;
      }
      int z;
      int countzero = 0;
      for (z = resstring.length() - 1; z >= 0; z--) {
        if (resstring[z] == '0')
          countzero += 1;
        else
          break;
      }
      std::string replac;
      for (int x = 0; x < resstring.length() - countzero; x++) {
        replac = replac + resstring[x];
      }
      resstring = replac;
      bool d;
      if (asign1 == false && bsign1 == true) {
        d = false;
        resstring = resstring + charneg;
        reverse(resstring.begin(), resstring.end());
      }
      if (asign1 == true && bsign1 == false) {
        d = true;
        reverse(resstring.begin(), resstring.end());
      }
      std::string result;
      result = resstring;
      return result;
    }
    if (comp == 0) {  // start a<bs
      int n = 0;
      std::string resstring;
      int res;
      int res1;
      for (int j = size1 - 1; j >= 0; j--) {
        res = bstr[j] - astr[j] - n + 10;
        if (res < 10)
          n = 1;
        if (res >= 10)
          n = 0;
        res1 = res % 10;
        char c = res1 + '0';
        resstring = resstring + c;
      }
      int z;
      int countzero = 0;
      for (z = resstring.length() - 1; z >= 0; z--) {
        if (resstring[z] == '0')
          countzero += 1;
        else
          break;
      }
      std::string replac;
      for (int x = 0; x < resstring.length() - countzero; x++) {
        replac = replac + resstring[x];
      }
      resstring = replac;
      bool d;
      if (asign1 == false && bsign1 == true) {
        d = true;
        reverse(resstring.begin(), resstring.end());
      }
      if (asign1 == true && bsign1 == false) {
        d = false;
        resstring = resstring + charneg;
        reverse(resstring.begin(), resstring.end());
      }
      std::string result;
      result = resstring;
      return result;
    }
    if (comp == 2) {  // start a=b
      std::string result = "0";
      return result;
    }
  }
}

std::string addition_si(std::string a, int b) {
  std::string c = std::to_string(b);
  std::string result;
  result = addition_ss(a, c);
  return result;
}

std::string negative(std::string a) {
  int asize;
  if (a[0] != '-') {
    std::string acopy;
    acopy = '-' + a;
    return acopy;
  }
  if (a[0] == '-') {
    asize = a.length() - 1;
    std::string acopy;
    acopy = a.substr(1, asize);
    return acopy;
  }
}

std::string substraction_ss(std::string a, std::string b) {
  std::string result;
  std::string c = negative(b);
  result = addition_ss(a, c);
  return result;
}

std::string substraction_si(std::string a, int b) {
  std::string c = std::to_string(b);
  std::string result;
  result = substraction_ss(a, c);
  return result;
}

std::string substraction_is(int a, std::string b) {
  std::string c = std::to_string(a);
  std::string result;
  result = substraction_ss(c, b);
  return result;
}

std::string multiplication_ss(std::string a, std::string b) {
  std::string astr;
  std::string bstr;
  int asize = a.length();
  int bsize = b.length();
  bool asign1 = true;
  bool bsign1 = true;
  if (a[0] == '-') {
    asize = asize - 1;
    astr = a.substr(1, asize);
    asign1 = false;
  } else {
    astr = a;
  }
  if (b[0] == '-') {
    bsize = bsize - 1;
    bstr = b.substr(1, bsize);
    bsign1 = false;
  } else {
    bstr = b;
  }
  std::string sum ="0";
  int i = 0;
  int j = 0;
  int k = 0;
  int x = 0;
  std::string c = astr;
  std::string d = c;
  for (i = 0; i < bsize; i++) {
    c = d;
    for (k = 0; k < bsize - 1 - i; k++) {
      c = c + '0';
    }
    for (j = 0; j < bstr[i] - '0'; j++) {
      sum = addition_ss(sum, c);
    }
  }
  if ((!asign1 ^ !bsign1) && ((a != "0") && (b != "0")))
    sum = '-' + sum;
  if ((a == "0") ^ (b == "0"))
    sum = "0";
  return sum;
}
std::string multiplication_si(std::string a, int b) {
  std::string c = std::to_string(b);
  std::string result;
  result = multiplication_ss(a, c);
  return result;
}
std::string division_ss(std::string a, std::string b) {
  std::string astr;
  std::string bstr;
  int asize = a.length();
  int bsize = b.length();
  bool asign1 = true;
  bool bsign1 = true;
  if (a[0] == '-') {
    asize = asize - 1;
    astr = a.substr(1, asize);
    asign1 = false;
  } else {
    astr = a;
  }
  if (b[0] == '-') {
    bsize = bsize - 1;
    bstr = b.substr(1, bsize);
    bsign1 = false;
  } else {
    bstr = b;
  }
  std::string a1 = astr;
  std::string b1 = bstr;
  int c = 0;
  for (int i = 0; true; i++) {
    a1 = substraction_ss(a1, b1);
    if (a1[0] == '-')
      break;
    c++;
  }
  if (asign1 ^ bsign1)
    c = -c;
  std::string result = std::to_string(c);
  return result;
}

std::string division_si(std::string a, int b) {
  std::string c = std::to_string(b);
  std::string result = division_ss(a, c);
  return result;
}
std::string division_is(int a, std::string b) {
  std::string c = std::to_string(a);
  std::string result = division_ss(c, b);
  return result;
}

std::string yu_ss(std::string a, std::string b) {
  std::string c = division_ss(a, b);
  std::string d = multiplication_ss(b, c);
  std::string result = substraction_ss(a, d);
  return result;
}
std::string yu_si(std::string a, int b) {
  std::string e = std::to_string(b);
  std::string result = yu_ss(a, e);
  return result;
}
std::string yu_is(int a, std::string b) {
  std::string e = std::to_string(a);
  std::string result = yu_ss(e, b);
  return result;
}

class Integer {
 public:
  Integer();
  Integer(int x);
  Integer(std::string s);
  std::string val;
  operator bool() const {
    if (val == "0")
      return false;
    else
      return true;
  }
  Integer& operator++ () {   // prefix ++
    Integer i(1);
    Integer j(this->val);
    // std::cout << "->=" <<this->val;
    std::string k;
    k = addition_ss(i.val, j.val);
    // std::cout << "k="<< k;
    this->val = k;
    // std::cout << "k="<< k;
    return *this;
  }
  // You want to make the ++ operator work like the standard operators
  // The simple way to do this is to implement postfix in terms of prefix.
  Integer operator++ (int) {  // postfix ++
    Integer tmp(*this);  // copy
    operator++();  // pre-increment
    return tmp;   // return old value        // return the copy (the old) value.
  }
  Integer& operator-- () {   // prefix ++
    Integer i(1);
    Integer j(this->val);
    // std::cout << "->=" <<this->val;
    std::string k;
    k = substraction_ss(j.val, i.val);
    // std::cout << "k="<< k;
    this->val = k;
    // std::cout << "k="<< k;
    return *this;
  }
  // You want to make the ++ operator work like the standard operators
  // The simple way to do this is to implement postfix in terms of prefix.
  //
  Integer operator-- (int) {  // postfix ++
    Integer tmp(*this);  // copy
    operator--();  // pre-increment
    return tmp;   // return old value
  }
  Integer& operator+=(const Integer& rhs) {  // compound assignment
    std::string k;
    k = addition_ss(rhs.val, this->val);
    this->val = k;
    return *this;
  }
  Integer& operator+=(const int& rhs) {  // compound assignment
    std::string k;
    k = addition_si(this->val, rhs);
    this->val = k;
    return *this;
  }
  Integer& operator-=(const Integer& rhs) {  // compound assignment
    std::string k;
    k = substraction_ss(this->val, rhs.val);
    this->val = k;
    return *this;
  }
  Integer& operator-=(const int& rhs) {  // compound assignment
    std::string k;
    k = substraction_si(this->val, rhs);
    this->val = k;
    return *this;
  }
  Integer& operator*=(const Integer& rhs) {  // compound assignment
    std::string k;
    k = multiplication_ss(this->val, rhs.val);
    this->val = k;
    return *this;
  }
  Integer& operator*=(const int& rhs) {  // compound assignment
    std::string k;
    k = multiplication_si(this->val, rhs);
    this->val = k;
    return *this;
  }
  Integer& operator/=(const Integer& rhs) {  // compound assignment
    std::string k;
    k = division_ss(this->val, rhs.val);
    this->val = k;
    return *this;
  }
  Integer& operator/=(const int& rhs) {  // compound assignment
    std::string k;
    k = division_si(this->val, rhs);
    this->val = k;
    return *this;
  }
  Integer& operator%=(const Integer& rhs) {  // compound assignment
    std::string k;
    k = yu_ss(this->val, rhs.val);
    this->val = k;
    return *this;
  }
  Integer& operator%=(const int& rhs) {  // compound assignment
    std::string k;
    k = yu_si(this->val, rhs);
    this->val = k;
    return *this;
  }
};
Integer::Integer() {
  val = "0";
}
Integer::Integer(int x) {
  std::string temp;
  temp = std::to_string(x);
  if (x >= 0) {
    val = std::to_string(x);
  }
  if (x < 0) {
    val = std::to_string(x);
  }
}
Integer::Integer(std::string s) {
  int a = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == '0') {
      a++;
    } else {
      break;
    }
  }
  bool seezero = false;
  if (a == s.length() - 1)
    seezero = true;
  if (s[0] == '-') {
    if (seezero == true) {
      val = '0';
    } else {
      val = s;
    }
  } else {
    if (s[0] != '0')
      val = s;
    else
      val = '0';
  }
}

Integer operator+(Integer a, Integer b) {
  char char1 = '1';
  char charneg = '-';
  std::string astr;
  std::string bstr;
  int asize = (a.val).length();
  int bsize = (b.val).length();
  bool asign1 = true;
  bool bsign1 = true;
  if (a.val[0] == '-') {
    asize = asize - 1;
    astr = (a.val).substr(1, asize);
    asign1 = false;
  } else {
    astr = a.val;
  }
  if (b.val[0] == '-') {
    bsize = bsize - 1;
    bstr = (b.val).substr(1, bsize);
    bsign1 = false;
  } else {
    bstr = b.val;
  }
  int size1;
  if (asize > bsize) {
    int i;
    std::string zeros;
    for (i = 0; i < (asize - bsize); i++) {
      zeros = zeros + "0";
    }
    bstr = zeros + bstr;
    size1 = asize;
  }
  if (asize < bsize) {
    int i;
    std::string zeros;
    for (i = 0; i < (bsize - asize); i++) {
      zeros = zeros + '0';
    }
    astr = zeros + astr;
    size1 = bsize;
  }
  if (asize == bsize) {
    size1 = asize;
  }
// finish with aline the length
// start (+++)
  if (asign1 == true && bsign1 == true) {
    int n = 0;
    std::string resstring;
    for (int j = size1 - 1; j >= 0; j--) {
      int res;
      int res1;
      res = astr[j] + bstr[j] - '0' - '0' + n;
      if (res >= 10)
        n = 1;
      if (res < 10)
        n = 0;
      res1 = res % 10;
      char c = res1 + '0';
      resstring = resstring + c;
    }
    if (n == 1)
      resstring = resstring + char1;
    reverse(resstring.begin(), resstring.end());
    Integer result;
    result.val = resstring;
    return result;;
  }
// start (-+-)
  if (asign1 == false && bsign1 == false) {
    std::string resstring;
    int n = 0;
    for (int j = size1 - 1; j >= 0; j--) {
      int res;
      int res1;
      res = astr[j] + bstr[j] - '0' - '0' + n;
      if (res >= 10)
        n = 1;
      if (res < 10)
        n = 0;
      res1 = res % 10;
      char c = res1 + '0';
      resstring = resstring + c;
    }
    if (n == 1) {
      resstring = resstring + char1;
    }
    resstring = resstring + charneg;
    reverse(resstring.begin(), resstring.end());
    Integer result;
    result.val = resstring;
    return result;
  }
// start (++-)(-++)
  if (asign1 == false ^ bsign1 == false) {
    int comp;
    int k;
    for (k = 0; k < size1; k++) {
      if (astr[k] > bstr[k]) {
        comp = 1;
        break;
      }
      if (astr[k] < bstr[k]) {
        comp = 0;
        break;
      }
    }
    if (k == size1) {
      comp = 2;
    }
    if (comp == 1) {  // start a>b
      int n = 0;
      std::string resstring;
      int res;
      int res1;
      for (int j = size1 - 1; j >= 0; j--) {
        res = astr[j] - bstr[j] - n + 10;
        if (res < 10)
          n = 1;
        if (res >= 10)
          n = 0;
        res1 = res % 10;
        char c = res1 + '0';
        resstring = resstring + c;
      }
      int z;
      int countzero = 0;
      for (z = resstring.length() - 1; z >= 0; z--) {
        if (resstring[z] == '0')
          countzero += 1;
        else
          break;
      }
      std::string replac;
      for (int x = 0; x < resstring.length() - countzero; x++) {
        replac = replac + resstring[x];
      }
      resstring = replac;
      bool d;
      if (asign1 == false && bsign1 == true) {
        d = false;
        resstring = resstring + charneg;
        reverse(resstring.begin(), resstring.end());
      }
      if (asign1 == true && bsign1 == false) {
        d = true;
        reverse(resstring.begin(), resstring.end());
      }
      Integer result;
      result.val = resstring;
      return result;
    }
    if (comp == 0) {  // start a<bs
      int n = 0;
      std::string resstring;
      int res;
      int res1;
      for (int j = size1 - 1; j >= 0; j--) {
        res = bstr[j] - astr[j] - n + 10;
        if (res < 10)
          n = 1;
        if (res >= 10)
          n = 0;
        res1 = res % 10;
        char c = res1 + '0';
        resstring = resstring + c;
      }
      int z;
      int countzero = 0;
      for (z = resstring.length() - 1; z >= 0; z--) {
        if (resstring[z] == '0')
          countzero += 1;
        else
          break;
      }
      std::string replac;
      for (int x = 0; x < resstring.length() - countzero; x++) {
        replac = replac + resstring[x];
      }
      resstring = replac;
      bool d;
      if (asign1 == false && bsign1 == true) {
        d = true;
        reverse(resstring.begin(), resstring.end());
      }
      if (asign1 == true && bsign1 == false) {
        d = false;
        resstring = resstring + charneg;
        reverse(resstring.begin(), resstring.end());
      }
      Integer result;
      result.val = resstring;
      return result;
    }
    if (comp == 2) {  // start a=b
      Integer result("0");
      return result;
    }
  }
}

Integer operator+(int x, Integer b) {
  Integer xcopy;
  std::string temp;
  int xcopysize;
  bool xcopysign1;
  temp = std::to_string(x);
  if (x >= 0) {
    xcopysign1 = true;;
    xcopy.val = std::to_string(x);
    xcopysize = temp.length();
  }
  if (x < 0) {
    xcopysign1 = false;
    xcopy.val = std::to_string(x);
    xcopysize = temp.length() - 1;
  }
  Integer result;
  result = xcopy + b;
  return result;
}

Integer operator+(Integer b, int x) {
  Integer xcopy;
  std::string temp;
  int xcopysize;
  bool xcopysign1;
  temp = std::to_string(x);
  if (x >= 0) {
    xcopysign1 = true;;
    xcopy.val = std::to_string(x);
    xcopysize = temp.length();
  }
  if (x < 0) {
    xcopysign1 = false;
    xcopy.val = std::to_string(x);
    xcopysize = temp.length() - 1;
  }
  Integer result;
  result = xcopy + b;
  return result;
}

Integer operator-(Integer a) {
  int asize;
  if (a.val[0] != '-') {
    Integer acopy;
    acopy.val = '-' + a.val;
    return acopy;
  }

  if (a.val[0] == '-') {
    asize = (a.val).length() - 1;
    Integer acopy;
    acopy.val = (a.val).substr(1, asize);
    return acopy;
  }
}

Integer operator-(Integer a, Integer b) {
  Integer result;
  result = a + (-b);
  return result;
}

Integer operator-(int a, Integer b) {
  Integer result;
  result = a + (-b);
  return result;
}
Integer operator-(Integer b, int a) {
  Integer result;
  result = -a + b;
  return result;
}
Integer operator*(Integer a, Integer b) {
  std::string astr;
  std::string bstr;
  int asize = (a.val).length();
  int bsize = (b.val).length();
  bool asign1 = true;
  bool bsign1 = true;
  if (a.val[0] == '-') {
    asize = asize - 1;
    astr = (a.val).substr(1, asize);
    asign1 = false;
  } else {
    astr = a.val;
  }
  if (b.val[0] == '-') {
    bsize = bsize - 1;
    bstr = (b.val).substr(1, bsize);
    bsign1 = false;
  } else {
    bstr = b.val;
  }
  Integer sum(0);
  int i = 0;
  int j = 0;
  int k = 0;
  int x = 0;
  Integer c(astr);
  Integer d = c;
  for (i = 0; i < bsize; i++) {
    c = d;
    for (k = 0; k < bsize - 1 - i; k++) {
      c.val = c.val + '0';
    }
    for (j = 0; j < bstr[i] - '0'; j++) {
      sum = sum + c;
    }
  }
  if ((!asign1 ^ !bsign1) && ((a.val != "0") && (b.val != "0")))
    sum.val = '-' + sum.val;
  if ((a.val == "0") ^ (b.val == "0"))
    sum.val = "0";
  return sum;
  //}
}
Integer operator*(Integer a, int b) {
  Integer c(b);
  Integer result = a * c;
  return result;
}
Integer operator*(int b, Integer a) {
  Integer c(b);
  Integer result = a * c;
  return result;
}
Integer operator/(Integer a, Integer b) {
  std::string astr;
  std::string bstr;
  int asize = (a.val).length();
  int bsize = (b.val).length();
  bool asign1 = true;
  bool bsign1 = true;
  if (a.val[0] == '-') {
    asize = asize - 1;
    astr = (a.val).substr(1, asize);
    asign1 = false;
  } else {
    astr = a.val;
  }
  if (b.val[0] == '-') {
    bsize = bsize - 1;
    bstr = (b.val).substr(1, bsize);
    bsign1 = false;
  } else {
    bstr = b.val;
  }
  Integer a1(astr);
  Integer b1(bstr);
  int c = 0;
  for (int i = 0; true; i++) {
    a1 = a1 - b1;
    if (a1.val[0] == '-')
      break;
    c++;
  }
  if (asign1 ^ bsign1) {
    c = -c;
    if (a1.val != "0")
      c = c - 1;
  }
  Integer result(c);
  return result;
}
Integer operator/(Integer a, int b) {
  Integer b1(b);
  Integer result = a / b1;
  return result;
}
Integer operator/(int b, Integer a) {
  Integer b1(b);
  Integer result = b1 / a;
  return result;
}
Integer operator%(Integer a, Integer b) {
  Integer result = a - b * (a / b);
  return result;
}
Integer operator%(Integer a, int b) {
  Integer b1(b);
  Integer result = a % b1;
  return result;
}
Integer operator%(int b, Integer a) {
  Integer b1(b);
  Integer result = b1 % a;
  return result;
}
std::ostream& operator<<(std::ostream& os, const Integer& a) {
  os << a.val;
  return os;
}

std::istream& operator>>(std::istream& is, Integer& a) {
  is >> a.val;
  return is;
}

bool operator==(Integer a, Integer b) {
  Integer c = a - b;
  if (c.val == "0") {
    return true;
  }
  if (c.val != "0") {
    return false;
  }
}
bool operator==(Integer a, int b) {
  Integer bcopy(b);
  return (a == bcopy);
}
bool operator==(int b, Integer a) {
  Integer bcopy(b);
  return (a == bcopy);
}
bool operator!=(Integer a, Integer b) {
  Integer c = a - b;
  if (c.val == "0") {
    return false;
  }
  if (c.val != "0") {
    return true;
  }
}
bool operator!=(Integer a, int b) {
  Integer bcopy(b);
  return (a != bcopy);
}
bool operator!=(int b, Integer a) {
  Integer bcopy(b);
  return (a != bcopy);
}
bool operator<(Integer a, Integer b) {
  Integer c = a - b;
  if (c.val[0] == '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return true;
  }
  if (c.val[0] != '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return false;
  }
  if (c.val[0] == '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return true;
  }
  if (c.val[0] != '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return false;
  }
  if (a.val[0] == '-' && b.val[0] != '-') {
    return true;
  }
  if (a.val[0] != '-' && b.val[0] == '-') {
    return false;
  }
}
bool operator<(Integer a, int b) {
  Integer bcopy(b);
  return (a < bcopy);
}
bool operator<(int b, Integer a) {
  Integer bcopy(b);
  return (bcopy < a);
}
bool operator>=(Integer a, Integer b) {
  Integer c = a - b;
  if (c.val[0] == '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return false;
  }
  if (c.val[0] != '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return true;
  }
  if (c.val[0] == '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return false;
  }
  if (c.val[0] != '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return true;
  }
  if (a.val[0] == '-' && b.val[0] != '-') {
    return false;
  }
  if (a.val[0] != '-' && b.val[0] == '-') {
    return true;
  }
}
bool operator>=(Integer a, int b) {
  Integer bcopy(b);
  return (a >= bcopy);
}
bool operator>=(int b, Integer a) {
  Integer bcopy(b);
  return (bcopy >= a);
}
bool operator>(Integer a, Integer b) {
  Integer c = b - a;
  if (c.val[0] == '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return true;
  }
  if (c.val[0] != '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return false;
  }
  if (c.val[0] == '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return true;
  }
  if (c.val[0] != '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return false;
  }
  if (a.val[0] == '-' && b.val[0] != '-') {
    return false;
  }
  if (a.val[0] != '-' && b.val[0] == '-') {
    return true;
  }
}
bool operator>(Integer a, int b) {
  Integer bcopy(b);
  return (a > bcopy);
}
bool operator>(int b, Integer a) {
  Integer bcopy(b);
  return (bcopy > a);
}
bool operator<=(Integer a, Integer b) {
  Integer c = b - a;
  if (c.val[0] == '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return false;
  }
  if (c.val[0] != '-' && (a.val[0] != '-' && b.val[0] != '-')) {
    return true;
  }
  if (c.val[0] == '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return false;
  }
  if (c.val[0] != '-' && (a.val[0] == '-' && b.val[0] == '-')) {
    return true;
  }
  if (a.val[0] == '-' && a.val[0] != '-') {
    return true;
  }
  if (a.val[0] != '-' && a.val[0] == '-') {
    return false;
  }
}
bool operator<=(Integer a, int b) {
  Integer bcopy(b);
  return (a <= bcopy);
}
bool operator<=(int b, Integer a) {
  Integer bcopy(b);
  return (bcopy <= a);
}
#endif  // Integer_w7
