## Vector
1. Vector implements a dynamic array which means it can grow or shrink as required. Like an array, it contains components that can be accessed using an integer index.
2. They are very similar to ArrayList, but Vector is synchronized and has some legacy methods that the collection framework does not contain.
3. It also maintains an insertion order like an ArrayList. Still, it is rarely used in a non-thread environment as it is synchronized, and due to this, it gives a poor performance in adding, searching, deleting, and updating its elements.

```
Vector<Integer> v = new Vector<Integer>(n);
```

## LinkedList & Queue
1. acts as a dynamic array
2. the elements are not stored in a continuous fashion
3. implemented using the doubly linked list data structure

```
 LinkedList ll = new LinkedList();

ll.add(2);
ll.offerFirst(1);
ll.offerLast(3);  // analogous to queue.push()

System.out.println(ll);
System.out.println(ll.peekFirst()); // analogous to queue.front()
```
```
OUTPUT:
[1, 2, 3]
1
```

## Deque

## Stack
The class is based on the basic principle of last-in-first-out. In addition to the basic push and pop operations, the class provides three more functions of empty, search, and peek. The class can also be said to extend Vector and treats the class as a stack with the five mentioned functions. The class can also be referred to as the subclass of Vector.

```
Stack<E> stack = new Stack<E>();
stack.push(i);
stack.peek();
stack.pop()
```

## HashMap
HashMap is the implementation of Map, but it doesn't maintain any order.
1. contains values based on the key
2. contains only unique keys
3. may have one null key and multiple null values
4. is non synchronized
5. maintains no order
6. initial default capacity of Java HashMap class is 16 with a load factor of 0.75
```
Map<Integer, String> hashMap = new HashMap<Integer, String>();

hashMap.put(5, "five");
hashMap.put(1, "one");
hashMap.put(3, "three");
hashMap.put(10, "ten");

System.out.println(hashMap);
```
```
OUTPUT:
{1=one, 3=three, 5=five, 10=ten}
```

## LinkedHashMap
Java LinkedHashMap class is Hashtable and Linked list implementation of the Map interface, with predictable iteration order. It inherits HashMap class and implements the Map interface.
1. contains values based on the key.
2. contains unique elements.
3. may have one null key and multiple null values.
4. non synchronized.
5. maintains insertion order.
6. initial default capacity of Java HashMap class is 16 with a load factor of 0.75.

```
Map<Integer, String> linkedHashMap = new LinkedHashMap<Integer, String>();

linkedHashMap.put(5, "five");
linkedHashMap.put(1, "one");
linkedHashMap.put(3, "three");
linkedHashMap.put(10, "ten");

System.out.println(linkedHashMap);
```
```
OUTPUT:
{5=five, 1=one, 3=three, 10=ten}
```

## TreeMap
TreeMap is the implementation of Map and SortedMap. It maintains ascending order.
1. red-black tree based implementation
2. contains only unique elements
3. not synchronized
4. cannot have a null key but can have multiple null values

```
NavigableMap<Integer, String> navigableTreeMap = new TreeMap<>();

navigableTreeMap.put(5, "five");
navigableTreeMap.put(1, "one");
navigableTreeMap.put(3, "three");
navigableTreeMap.put(10, "ten");

System.out.println(navigableTreeMap);
System.out.println(navigableTreeMap.descendingMap());
System.out.println(navigableTreeMap.headMap(5, true));
System.out.println(navigableTreeMap.tailMap(5, true));
System.out.println(navigableTreeMap.subMap(3, true, 5, true));
```
```
OUTPUT:
{1=one, 3=three, 5=five, 10=ten}
{10=ten, 5=five, 3=three, 1=one}
{1=one, 3=three, 5=five}
{5=five, 10=ten}
{3=three, 5=five}
```
**Note:** NavigableMap provides more freedom in navigation across a map <br>
**Note:** For concurrent environments use *ConcurrentHashMap*

## References
1. [GFG-Vector](https://www.geeksforgeeks.org/java-util-vector-class-java/)
2. [GFG-LinkedList](https://www.geeksforgeeks.org/linked-list-in-java/)
3. [GFG-Deque](https://www.geeksforgeeks.org/arraydeque-in-java/)
4. [GFG-Stack](https://www.geeksforgeeks.org/stack-class-in-java/)
5. [Javapoint-HashMap](https://www.javatpoint.com/java-hashmap)
6. [Javapoint-LinkedHashMap](https://www.javatpoint.com/java-linkedhashmap)
7. [Javapoint-TreeMap](https://www.javatpoint.com/java-treemap)
