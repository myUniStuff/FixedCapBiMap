#include "MyShortTest.h"
#include <assert.h>
#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <cstdio>
#include <utility>


void myTestAll() { //call each function to see if it is implemented
	FixedCapBiMap m(10);
  assert(m.isEmpty() == true);
  assert(m.add(1, 4));
  assert(m.add(2, 3));
  assert(m.add(3, 5));
  assert(m.add(2, 5));
  assert(m.add(1, 9));

  assert(m.removeKey(1) == ValuePair(4, 9));
}


