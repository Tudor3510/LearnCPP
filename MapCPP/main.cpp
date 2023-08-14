#include <iostream>
#include <map>

using namespace std;


// THIS WORKS !!!!!!!!!!!!!
/*
class Blegh
{
    int _number;

public:
    Blegh(int number) : _number(number)
    {
    }

    int GetNumber() const { return _number; }
};

bool operator < (const Blegh& lhs, const Blegh& rhs)
{
    return lhs.GetNumber() < rhs.GetNumber();
}

int main()
{
    map<Blegh, string> whoa;

    whoa[Blegh(3)] = "whoa";
    whoa[Blegh(2)] = "there";
    whoa[Blegh(1)] = "hey";

    cout << whoa[Blegh(1)] << '\n';             // hey
    cout << whoa[Blegh(2)] << '\n';             // there
    cout << whoa[Blegh(3)] << '\n';             // whoa


// When using a 'std::map' (or other associative containers like 'std::set', 'std::multimap', and 'std::multiset'),
// the container uses the comparison operator ('operator<') to determine both ordering and equivalence of elements.
// For each element insertion, access, or search operation, the 'std::map' compares keys using 'operator<' twice:

// Key Ordering: The first comparison determines the ordering of elements in the map.
// It's used to build the internal binary search tree structure.
// If 'key1 < key2' is true, then key1 is considered to come before key2 in the sorted order.

// Equivalence Check: If two keys are found to be not less than each other (i.e., neither 'key1 < key2' nor 'key2 < key1'),
// the container considers them equivalent. This is used to determine whether two keys are equal for purposes
// like insertion and searching.

// This behavior can be a bit counterintuitive if you're not aware of it, especially if you're coming from a perspective
// where you're used to thinking of "equality" as a separate concept from ordering.

// To summarize, the 'std::map' (and similar associative containers) uses 'operator<' to establish both the ordering
// and the equivalence of elements based on the outcome of the comparisons. If you need a more specific notion of
// equality, you should define an operator== overload for your class.



    return 0;
}
*/