#include <iostream>
#include <tuple>
#include <random>
#include <chrono>

#include <Kdtree.h>

#define TOTAL 100000
#define TSIZE 1000

int main() {
  srand (time(NULL));

  std::vector <Vectr> tps;
  for(int i = 0; i < TSIZE; i++) {
    tps.push_back(Vectr() * 10);
  }

  Kdtree tree;

  for(int i = 0; i < TOTAL; i++) {
    Vectr a = (Vectr() * 10);
    tree.add(a);
  }

  std::vector <Vectr> with_tree;
  std::vector <Vectr> without_tree;

  auto start_t = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < TSIZE; i++) {
    with_tree.push_back(tree.findNearest(tps[i]));
  }
  auto end_t = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_t - start_t);
  std::cout << "Duration with tree: " << duration.count() << "us" << std::endl;

  auto count1 = duration.count();

  start_t = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < TSIZE; i++) {
    without_tree.push_back(tree.suckyFindNearest(tps[i])->me);
  }
  end_t = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end_t - start_t);
  std::cout << "Duration withOUT tree: " << duration.count() << "us" << std::endl;

  std::cout << "Improvement: " << ((double)duration.count() / count1) << std::endl;

  int erc = 0;

  for(int i = 0; i < TSIZE; i++) {
    if(!(with_tree[i] == without_tree[i])) {
      tps[i].printit();
      with_tree[i].printit();
      without_tree[i].printit();
      std::cout << "-------------------------------" << std::endl;
      erc++;
    }
  }

  std::cout << "Total: " << TSIZE << std::endl;
  std::cout << "Passed: " << (TSIZE - erc) << std::endl;

  tree.burn();

  return 0;
}
