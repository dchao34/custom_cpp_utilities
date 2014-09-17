#include <iostream>
#include "trie.h"

using namespace std;
using namespace bdtaunu;

int main() {

  trie<int, int, -1, -1> t;

  cout << "add and search methods: " << endl;
  cout << t.find({1, 1, 2, -1}) << endl;
  t.insert({1, 1, 2, -1}, 112);
  cout << t.find({1, 1, 2, -1}) << endl;
  cout << t.find({2, 1, 2, -1}) << endl;
  t.insert({2, 1, 2, -1}, 212);
  cout << t.find({2, 1, 2, -1}) << endl;
  cout << t.find({3, 3, 1, -1}) << endl;
  t.insert({3, 3, 1, -1}, 331);
  cout << t.find({3, 3, 1, -1}) << endl;
  t.insert({3, 3, 1, -1}, 331);
  cout << t.find({3, 3, 1, -1}) << endl;

  t.insert({-1}, -1);

  cout << t.find({5, 2, 9, -1}) << endl;
  t.insert({5, 2, 9, -1}, 529);
  cout << t.find({5, 2, 9, -1}) << endl;

  cout << t.find({2, 5, 9, -1}) << endl;
  t.insert({2, 5, 9, -1}, 259);
  cout << t.find({2, 5, 9, -1}) << endl;

  cout << "copy constructor: " << endl;
  trie<int, int, -1, -1> t1(t);
  cout << t1.find({1, 1, 2, -1}) << endl;
  cout << t.find({2, 1, 2, -1}) << endl;
  cout << t.find({3, 3, 1, -1}) << endl;
  cout << t.find({5, 2, 9, -1}) << endl;
  cout << t.find({2, 5, 9, -1}) << endl;

  cout << "copy assignment: " << endl;
  trie<int, int, -1, -1> t2;
  t2.insert({1, 1, 1, -1}, 111);
  t2.insert({2, 2, 2, -1}, 222);
  t = t1 = t2;
  cout << t1.find({1, 1, 1, -1}) << endl;
  cout << t1.find({2, 2, 2, -1}) << endl;
  cout << t.find({1, 1, 1, -1}) << endl;
  cout << t.find({2, 2, 2, -1}) << endl;

  cout << "self assignment: " << endl;
  t = t;
  cout << t.find({1, 1, 1, -1}) << endl;
  cout << t.find({2, 2, 2, -1}) << endl;

  return 0;
}
