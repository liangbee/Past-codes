// Copyright 2017 EC327/Carruthers jbc@bu.edu
// Copyright 2017 Biyao Liang liangb@bu.edu

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::make_pair;

typedef std::pair<int, int> CellType;

typedef vector<CellType> PieceType;

const int DefaultTSize = 5;

// Error codes
const int BADCHAR = 1;
const int BADSIZE = 2;
const int NOTILE = 3;

PieceType shift(PieceType p, int size) {
  vector <int> x_s;
  vector <int> y_s;
  PieceType copy = p;
  for (int i = 0; i < size-1; i++) {
    CellType a = copy[i];
    x_s.push_back(a.first);
    y_s.push_back(a.second);
  }
  if ( std::find(x_s.begin(), x_s.end(), 0) != x_s.end() ) {
  } else {
    for (int i=0; i < size; i++) {
      copy[i].first -= 1;  // shift all * left by 1.
    }
    shift(copy, size);  // reduce again
  }
  if ( std::find(y_s.begin(), y_s.end(), size-1) != y_s.end() ) {
  } else {
    for (int i = 0; i < size; i++) {
      copy[i].second++;  // shift all * up by 1.
    }
    shift(copy, size);  // reduce again
  }
  return copy;
}
PieceType r(PieceType p, int size) {  // rotate
  PieceType copy = p;
  for (int i = 0; i < p.size(); i++) {
    copy[i].first =  p[i].second;  // newx = size-oldy
    copy[i].second = (size-1)-p[i].first;  // newy = oldx
  }
  return copy;  // of 1 rotation
}

PieceType flip(PieceType p, int size) {  // flip left to right
  PieceType copy = p;
  for (int i = 0; i < p.size(); i++) {
    copy[i].first = (size-1) - p[i].first;
  }
  return copy;  // of 1 left and right rotation
}

vector<PieceType> check_repeat(PieceType p, int size) {
  PieceType shifted;  // shifted original
  PieceType a_r;  // 1st 90
  PieceType b_r;  // 2nd 180
  PieceType c_r;  // 3rd 270
  PieceType d_f;  // flip
  PieceType e_f;  // flip 90
  PieceType f_f;  // flip 180
  PieceType g_f;  // flip 270
  vector<PieceType> storage;  // store everything
  shifted = shift(p, size);
  a_r = r(shifted, size);
  b_r = r(a_r, size);
  c_r = r(b_r, size);
  d_f = flip(shifted, size);
  e_f = r(d_f, size);
  f_f = r(e_f, size);
  g_f = r(f_f, size);
  a_r = shift(a_r, size);
  b_r = shift(b_r, size);
  c_r = shift(c_r, size);
  d_f = shift(d_f, size);
  e_f = shift(e_f, size);
  f_f = shift(f_f, size);
  g_f = shift(g_f, size);
  storage.push_back(shifted);
  storage.push_back(a_r);
  storage.push_back(b_r);
  storage.push_back(c_r);
  storage.push_back(d_f);
  storage.push_back(e_f);
  storage.push_back(f_f);
  storage.push_back(g_f);
  return storage;
}
PieceType find_neighbors(CellType in , PieceType p) {
  PieceType result;
  CellType r = make_pair(in.first+1, in.second);
  CellType l = make_pair(in.first-1, in.second);
  CellType u = make_pair(in.first, in.second+1);
  CellType d = make_pair(in.first, in.second-1);
  if ( std::find(p.begin(), p.end(), r) != p.end() ) {
    result.push_back(r);
  }
  if ( std::find(p.begin(), p.end(), l) != p.end() ) {
    result.push_back(l);
  }
  if ( std::find(p.begin(), p.end(), u) != p.end() ) {
    result.push_back(u);
  }
  if ( std::find(p.begin(), p.end(), d) != p.end() ) {
    result.push_back(d);
  }
  return result;
}


void print_piece(PieceType p, std::ostream *out, int TSize) {
  std::string base(TSize, '.');
  vector<std::string> e(TSize, base);

  for (auto const & loc : p)
    e[loc.first][loc.second] = '*';

  for (int y = TSize - 1; y >= 0; y--) {
    for (int x = 0; x < TSize; x++)
      *out << e[x][y];
    *out << std::endl;
  }
  *out << std::endl;
}
PieceType check_connectivity(PieceType p) {
  PieceType stor;  // where we have been to
  PieceType next;  // where to check next
  PieceType temp;  // temporary storage
  PieceType next_2;
  next = find_neighbors(p[0], p);
  stor.push_back(p[0]);
  while (next.size() != 0) {
    if ( std::find(stor.begin(), stor.end(), next[0]) != stor.end() ) {
      next.erase(next.begin()+ 0);
    } else if ( std::find(stor.begin(), stor.end(), next[0]) == stor.end() ) {
      stor.push_back(next[0]);
      temp = find_neighbors(next[0], p);
      for (int i = 0; i < temp.size(); i++) {
        next.push_back(temp[i]);
      }
      next.erase(next.begin() + 0);
    }
  }
  if (stor.size() == p.size()) {
    return p;
  }
}
vector<PieceType> get_tileset(std::istream* in, int TSize, int * errorcode) {
  vector<PieceType> pieces;
  vector<PieceType> r_check;
  vector<PieceType> s_s;  // shift_store
  PieceType p_new;
  std::string row;
  PieceType p;
  *errorcode = 0;
  int npieces;
  vector<std::string> filelines;
  while (getline(*in, row)) {
    filelines.push_back(row);
  }

  if (filelines.size() % (TSize + 1) != 0) {
    *errorcode = BADSIZE;
    return pieces;
  }

  for (int i = 0 ; i < filelines.size() ; i++) {
    if (i % (TSize + 1) == TSize) {
      if (filelines[i].size() != 0)
        *errorcode = BADSIZE;
    } else  {
      if (filelines[i].size() != TSize)
        *errorcode = BADSIZE;
    }
  }
  if (*errorcode)
    return pieces;

  npieces = filelines.size() / (TSize + 1);

  for (int i = 0; i < npieces; i++) {
    p.clear();
    for (int y = 0; y < TSize ; y++) {
      row = filelines[i * (TSize + 1) + y];

      for (int x = 0; x < TSize; x++)
        if (row[x] == '*') {
          p.push_back(make_pair(x, TSize - 1 - y));
        } else if (row[x] != '.') {
          *errorcode = BADCHAR;
          return pieces;
        }
    }
    if (p.empty()) {
      *errorcode = NOTILE;
      return pieces;
    }
    // above is valid check. now run connectivity check.
    p_new = check_connectivity(p);
    // above is connectivity check. now run repeat check.
    r_check = check_repeat(p_new, TSize);
    if (pieces.size() == 0) pieces.push_back(p_new);

    else
    {for (int j = 0; j < pieces.size(); j++) {
        bool flag = true;
        s_s = check_repeat(pieces[j], TSize);
        for (int k = 0; k < r_check.size(); k++) {
          if (std::find(s_s.begin(), s_s.end(), r_check[k]) != s_s.end()) {
            flag = false;  // do nothing.
          }
        }
        if (flag) {  // unique input
          // std::cout<<"pushing back a p"<<std::endl;
          pieces.push_back(p_new);  // push back p original
        }
      }
    }
  }
  return pieces;
}
int main(int argc, char const *argv[]) {
  int TSize;
  std::istream * in = &std::cin;
  std::ostream * out = &std::cout;
  std::ifstream infile;
  std::ofstream outfile;
  TSize = (argc == 1) ? DefaultTSize : std::stoi(argv[1]);

  if (argc > 2) {
    infile.open(argv[2]);
    in = &infile;
  }
  if (argc > 3) {
    outfile.open(argv[3]);
    out = &outfile;
  }

  int errorcode;

  vector<PieceType> p_new = get_tileset(in, TSize, &errorcode);
  if (errorcode) {
    return errorcode;
  }
  for (auto const & e : p_new)
    print_piece(e, out, TSize);
  return 0;
}
