# Templates for Maps
The syntax for templates can be kind of confusing.  It is a little more confusing when dealing with a map where you have a "Name" and a "Value" that can each take on different types.  This tuturial will help you with the syntax details so that you can get into the fun part of programming your map.

To start out, lets look at the syntax for a normal template class that we might want to make for our HashMap.
```c++
template <class T>
class HashMap {
    T element;
  public:
    void put(T arg) {element = arg;};
    T get () {return element;}
};
```
Notice that here, we have a single template class "T" that will be substituted with the type when we declare a variable of this class.  For example, in the following declaration, T would be a "string".
```c++
HashMap<string> stringMap;
```
Now, the HashMap will be a little different, because we not only want to allow the key to take on different types, but the value as well.  It turns out that the syntax is very similar, but we will include two types in our "template" statement.
```c++
template <class Name, class Value>
class HashMap {
    Name myname;
    Value myvalue;
    
  public:
    void putName(Name arg) {myname = arg;};
    void putValue(Value arg) {myvalue = arg;};
    Name get () {return myname;}
};
```
If you want to create a hashmap, you will want to pair Names with Values.  This can be most easily performed with the 
["pair"](http://www.cplusplus.com/reference/utility/pair/)
container.  It is a container, just like a vector or list, but it only holds two values, "first" and "second".  Since it is a template class, first and second can be of any type.

So, you can declare a pair inside of your HashMap class using the following syntax
```c++
template <class Name, class Value>
class HashMap {
	private:
	pair <Name,Value> context;
  ...
```

If you are using chaining for your Hash table, then you will want to create a structure that will implement the links.  You will also want to declare an array of pointers to these structures.  I suggest you keep your hash table small so you can find bugs in your chaining code.
```c++
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
  ...
```
In order to declare a HashMap from "string" to "vector<string>", you can use the same syntax you use with the STL map.
```c++
HashMap <string, vector <string>> goo;
```
Make sure you are comfortable with the syntax.  It will save you a lot of time when compared to writing a different class for every type.
