#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <cstdio>
#include <exception>

using namespace std;


FixedCapBiMapIterator::FixedCapBiMapIterator(const FixedCapBiMap& d) : map(d)
{
  currentPosition = 0;	
}
// BC = WC = TC: Theta(1)

void FixedCapBiMapIterator::first() {
	currentPosition = 0;
}
// BC = WC = TC: Theta(1)

void FixedCapBiMapIterator::next() {
  if (currentPosition == map.mapSize) {
    throw exception();
  }
	currentPosition += 1;
}
// BC = WC = TC: Theta(1)

TElem FixedCapBiMapIterator::getCurrent(){
  if (currentPosition == map.mapSize) {
    throw exception();
  }
	return map.elements[currentPosition];
}
// BC = WC = TC: Theta(1)

bool FixedCapBiMapIterator::valid() const {
	return currentPosition < map.mapSize;
}
// BC = WC = TC: Theta(1)
