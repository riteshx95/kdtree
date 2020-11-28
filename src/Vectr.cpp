#include <cmath>
//#include <cstdlib>
#include <random>
#include <iostream>
#include <Vectr.h>

Vectr::Vectr() {
  x[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  x[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  x[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Vectr::Vectr(float a, float b, float c) {
  x[0] = a; x[1] = b; x[2] = c;
}

float Vectr::mag() {
  return sqrt(*this | *this);
}

Vectr Vectr::normalize() {
  float m;
  m = this->mag();
  return (*this / m);
}

void Vectr::printit() {
  for(int i = 0; i < 3; i++) {
    printf("%f ", x[i]);
  }
  printf("\n");
}
