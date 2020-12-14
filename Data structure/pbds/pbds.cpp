// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

// Driver code
int main()
{
	order_set p;
	p.insert(5);
	p.insert(2);
	p.insert(6);
	p.insert(4);

	// value at 3rd index in sorted array.
	cout << "The value at 3rd index ::"
		<< *p.find_by_order(3) << endl;

	// index of number 6
	cout << "The index of number 6::"
		<< p.order_of_key(6) << endl;

	// number 7 not in the set but it will show the
	// index number if it was there in sorted array.
	cout << "The index of number seven ::"
		<< p.order_of_key(7) << endl;
    p.erase(2);//delete 2 from the set
    if(p.empty()) cout<<"empty\n";
    else cout<<"Not empty\n";

    cout<<p.size()<<endl;

    cout<<*p.begin()<<endl;//print 1st element
    cout<<*p.rbegin()<<endl;//print the last element

    auto pos=p.end();
    pos--;
    cout<<*pos<<endl;//print the last element

    if(p.find(5)==p.end()) cout<<"Not found\n";
    else cout<<"Found\n";

    cout<<*p.lower_bound(5)<<' '<<*p.lower_bound(2)<<endl;
    cout<<*p.upper_bound(5)<<endl;

	return 0;
}
