#include<iostream>
#include "ICloneable.h"
using namespace std;

int main() {
	ICloneable * p = new ValueHolder<int>(20);
	p->clone();
	return 0;
}