#include "bst.h"
#include <cassert>
#include <set>
using namespace std;

bool test_push_cointains()
{
	BinSearchTree<int> t1;
	t1.push(2);
	t1.push(4);
	t1.push(1);
	t1.push(10);
	assert(t1.contains(2));
	assert(!t1.contains(3));
	assert(t1.contains(4));
	assert(!t1.contains(5));
	t1.push(101);
	assert(t1.contains(101));
	assert(!t1.contains(100));
	return true;
}
bool test_min_max()
{
	BinSearchTree<int> t;
	t.push(2);
	t.push(4);
	t.push(1);
	t.push(10);
	assert(t.max() == 10);
	assert(t.min() == 1);
	t.push(12);
	t.push(-1);
	assert(t.max() == 12);
	assert(t.min() == -1);
	return true;
}
bool test_gte_lte()
{
	BinSearchTree<int> t;
	t.push(2);
	t.push(4);
	t.push(1);
	t.push(10);
	assert(t.gte(-1) == 2);
	assert(t.gte(3) == 4);
	assert(t.lte(1) == 1);
	return true;
}

int main()
{
	assert(test_push_cointains());
	assert(test_min_max());
	assert(test_gte_lte());
	set<int> s;
}