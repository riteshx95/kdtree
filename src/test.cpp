#include <Kdtree.h>

int main() {
  Kdtree tree;

  tree.add(Vectr(1, 0, 0));
  tree.add(Vectr(2, 0, 0));
  tree.add(Vectr(3, 0, 0));
  tree.add(Vectr(4, 0, 0));
  tree.add(Vectr(5, 0, 0));

  Vectr near = tree.findNearest(Vectr(3.6, 0, 0));
  near.printit();

  tree.burn();

  return 0;
}
