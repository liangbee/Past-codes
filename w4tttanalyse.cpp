// Copyright 2017 Biyao Liang liangb@bu.edu

#include <iostream>  // indluce necessary libraries
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
std::string analyser(std::string line) {
  std::string result = "";  // declare the result as a string called result
  int x_c = 0;  // declare the variable x_c for x count
  int o_c = 0;  // declare the variable o_c for o count
  int w_C = 0;  // counts how many winners there are
  for ( int i = 0; i < 9; i++ ) {
    if ( line[i] == 'x' )
      x_c++;
    else if ( line[i] == 'o' )
      o_c++;
  }
  if ( x_c - o_c >= 2 || o_c > x_c ) {
    result = "i";  // result is invalid game
    return result;
  } else {
    if ( line[0] == line[1] && line[1] == line[2] && line[0] != '#' ) {
      result = result + line[0];
    }
    if ( line[3] == line[4] && line[4] == line[5] && line[3] != '#' ) {
      result = result + line[3];
    }
    if  ( line[6] == line[7] && line[7] == line[8] && line[6] != '#' ) {
      result = result + line[6];
    }
    if ( line[0] == line[3] && line[3] == line[6] && line[0] != '#' ) {
      result = result + line[0];
    }
    if ( line[1] == line[4] && line[4] == line[7] && line[1] != '#' ) {
      result = result + line[1];
    }
    if ( line[2] == line[5] && line[5] == line[8] && line[2] != '#' ) {
      result = result + line[2];
    }
    if ( line[0] == line[4] && line[4] == line[8] && line[0] != '#' ) {
      result = result + line[0];
    }
    if ( line[2] == line[4] && line[4] == line[6] && line[2] != '#' ) {
      result = result + line[2];
    }
  }
  if ( result == "xx" || result == "oo" ) {  // double winner
    result = result[0];
    if (result == "x") {
      if (x_c <= o_c) {
        result = "i";
      } else {
        return result;
      }
    }
  }
  if ( result == "ox" || result == "xo" ) {  // invalid
    result = "i";
    if ( result == "x" ) {
      if ( x_c <= o_c ) {
        result = "i";
      } else {
        return result;
      }
    }
  }
  if ( result == "o" ) {
    if ( x_c != o_c ) {
      result = "i";
      return result;
    } else {
      return result;
    }
  }
  if ( result == "x" ) {
    if ( x_c <= o_c ) {
      result = "i";
    } else {
      return result;
    }
  }
  if ( result == "o" ) {
    if ( x_c <= o_c ) {
      result = "i";
    } else {
      return result;
    }
  }
  if ( x_c + o_c == 9 && result != "i" && result != "o" && result != "x" ) {
    result = result;
    result = 't';
    return result;
  }
  if ( x_c +o_c < 9 && result != "i" && result != "o" && result != "x" ) {
    result = "c";
    return result;
  }
  return result;
}
int main() {
  std::ifstream thisfile;
  std::string theline;
  std::vector<std::string> contents;
  std::string result;
  thisfile.open("tictactoeboards.txt");
  std::ofstream newfile("tttstatus.txt");
  while ( std::getline(thisfile, theline) )
    contents.push_back(theline);
  thisfile.close();
  for ( auto line : contents ) {  // for each line of contents
    result = analyser(line);
    newfile<< line << " "<< result << "\n";
  }
  newfile.close();  // close the file
  return 0;
}
