#include "Coordinate.h"

Coordinate::Coordinate(int x) {
  cord = x;
}
Coordinate::~Coordinate() {
}
void Coordinate::OverRideCord(int x) {
  cord = x;
}

void Coordinate::UpdateX(int x) {
  cord = x;
}
int Coordinate::GetX() {
  return cord;
}
