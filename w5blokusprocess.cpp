// Copyright 2017 Biyao Liang liangb@bu.edu
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
using std::cin;
using std::cout;
int outputing(std::vector<std::string> v_in , char* argv[] ) {
  std::ofstream output_file(argv[3]);
  for (int i = 0; i < v_in.size(); ++i) {
    output_file << v_in[i] << "\n";
  }
  return 0;
}
int line_check(std::vector<std::string> v_in, int argc, char* argv[]) {
  char n_l = '\n';
  int t_c = 0;
  int c_c = 0;
  int size = atol(argv[1]);
  for (int i = 0; i < v_in.size(); i++) {
    for (int j = 0; j< v_in[i].length(); j++) {
      if ( v_in[i][j] == '*' ) {
        t_c++;  // incrementing t_count
        c_c++;  // incrementing total count
      }
      if (v_in[i][j] == '.') {
        c_c++;  // total size count
      }
      if (v_in[i][j] != '*' && v_in[i][j] != '.' && v_in[i][j] != n_l) {
        return 1;  // odd input. exit error code:1
      }
    }
  }
  if ( c_c != size*size ) {  // forloop is over
    return 2;  // format error
  }
  if ( t_c == 0 ) {
    return 3;  // no block
  } else {
    if (argc <=2) {
      for (int i = 0; i < v_in.size(); i++)
        cout << v_in[i] << "\n";
    } else {
      outputing(v_in, argv);
    }
  }
}
int is_tile(int size, int argc , char* argv[]) {  // define if input is tile
  int counter;  // counts blank space
  std::string s_in;  // standard input
  std::vector<std::string> v_in;  // vector for check
  if ( argc <= 1 ) {  // if argu command is nothing/ 1
    std::getline(std::cin, s_in);  // getline from input
    counter = 0;  // initializing counter
    for (auto a : s_in) {  // for each line of input
      if (s_in.length() == 0) {
        counter++;
        v_in.push_back(s_in);
      }
      if (s_in.length() == 5) {
        v_in.push_back(s_in);
        counter = 0;
      }
      if (s_in.length() != 0 && s_in.length() != 5) {
        return 2;
      }
      if (counter >= 2) {
        return 2;
      }
    }  // end of for-loop
    line_check(v_in, argc, argv);
  }
  if ( argc >= 2 ) {
    counter = 0;
    std::ifstream input(argv[2]);
    std::getline(input, s_in);
    for (auto a : s_in) {
      if (s_in.length() == 0) {
        counter++;
        v_in.push_back(s_in);
      }
      if (s_in.length()== 5) {
        v_in.push_back(s_in);
        counter = 0;
      }
      if (s_in.length() != 0 && s_in.length() != 5) {
        return 2;
      }
      if (counter >= 2) {
        return 2;
      }
    }
    line_check(v_in, argc, argv);
  }
}
// check the brackets


int main(int argc, char *argv[]) {
  int a = atol(argv[1]);  // convert argv[1] to int
  if ( argc == 0 ) {
    is_tile(5, 0, argv);
  }
  if ( argc == 1 ) {
    is_tile(5, argc, argv);
  }
  if ( argc == 2 ) {
    std::ifstream input;
    input.open(argv[2]);
    is_tile(a, argc, argv);
  }
  if ( argc >= 3 ) {
    std::ifstream input;
    input.open(argv[2]);
    is_tile(a, argc, argv);
  }
  return 0;
}

