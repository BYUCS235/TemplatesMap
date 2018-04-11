#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int CONSIZE=10;
template <class Name, class Value>
class HashMap {
	private:
	pair <Name,Value> context;
	
	struct node {
		pair<Name, Value> context;
		node *next;
	};
	
	node *context_array[CONSIZE];
	
	public:
	void printit() {
		cout << "Name size"<<context.first.size();
		cout << "Value size"<<context.second.size()<<endl;
	}
	Value at(Name name) {
		if(name == context.first)
		  return(context.second);
		else
		  return(NULL);
	}
	void set(Name myName, Value myValue) {
		context.first = myName;
		context.second = myValue;
	}
};
int main()
{
	
	HashMap <string, string>foo;
	foo.printit();
	foo.set("Hello","goodbye");
	foo.printit();
	cout << "value for Hello "<<foo.at("Hello")<<endl;
	HashMap <string, vector <string>> goo;
	goo.printit();
	vector <string> con;
	con.push_back("Who");
	con.push_back("Knows");
	goo.set("Geeber",con);
	goo.printit();
	
}