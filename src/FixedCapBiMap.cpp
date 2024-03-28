#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>
#include <stdio.h>

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if (capacity <= 0) {
    throw exception();
  }

  this->capacity = capacity;
  this->mapSize = 0;
  this->elements = new TElem[this->capacity];
}
// BC: Theta(1), WC: Theta(1), TC: Theta(1)

FixedCapBiMap::~FixedCapBiMap() {
	delete[] elements;
}
// BC = WC= TC: Theta(1)

bool FixedCapBiMap::add(TKey c, TValue v){
	if (mapSize == capacity) {
    throw exception();

  }
  
  int count = 0;
  int index = 0;
  while (count < 2 && index < mapSize) {
    if (elements[index].first == c) {
      count += 1;
    }
    index += 1;
  }

  if (count == 2) {
    return false;
  }
	
  elements[mapSize].first = c;
  elements[mapSize].second = v;
  mapSize += 1;
  return true;
}
// BC: Theta(1), WC: Theta(mapSize), TC: O(mapSize)

ValuePair FixedCapBiMap::search(TKey c) const{
	ValuePair result;
  result.first = NULL_TVALUE;
  result.second = NULL_TVALUE;

  int nrfound = 0;
  int index = 0;
  while (nrfound < 2 && index < mapSize) {
    if (elements[index].first == c) {
      if (nrfound == 0) {
        result.first = elements[index].second;
        nrfound += 1;
      } else {
        result.second = elements[index].second;
      }
    }
    index += 1;
  }

  return result;
	// return std::pair<TValue, TValue>(NULL_TVALUE, NULL_TVALUE);
}
// BC: Theta(1), WC: Theta(mapSize), TC: O(mapSize)

bool FixedCapBiMap::remove(TKey c, TValue v){
	int index = 0;
  while (index < mapSize) {
    if (elements[index].first == c && elements[index].second == v) {
      elements[index] = elements[mapSize - 1];
      mapSize -= 1;
      return true;
    }
    index += 1;
  }

	return false;
}
// BC: Theta(1), WC: Theta(mapSize), TC: O(mapSize)

ValuePair FixedCapBiMap::removeKey(TKey k) {
	ValuePair result;
  result.first = NULL_TVALUE;
  result.second = NULL_TVALUE;

  int nrfound = 0;
  int index = 0;
  while (nrfound < 2 && index < mapSize) {
    if (elements[index].first == k) {
      if (nrfound == 0) {
        result.first = elements[index].second;
        elements[index] = elements[mapSize - 1];
        mapSize -= 1;
        nrfound += 1;
        index -= 1;
      } else {
        result.second = elements[index].second;
        elements[index] = elements[mapSize - 1];
        mapSize -= 1;
        nrfound += 1; // not really needed ig
      }
    }
    index += 1;
  }

  return result;
	// return std::pair<TValue, TValue>(NULL_TVALUE, NULL_TVALUE);
}
// BC: Theta(1), WC: Theta(mapSize), TC: O(mapSize)

int FixedCapBiMap::size() const {
	return mapSize;
}
// BC = WC = TC: Theta(1)

bool FixedCapBiMap::isEmpty() const {
	return mapSize == 0;
}
// BC = WC = TC: Theta(1)

bool FixedCapBiMap::isFull() const {
	return mapSize == capacity;
}
// BC = WC = TC: Theta(1)

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}
// BC = WC = TC: Theta(1)



