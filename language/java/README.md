# Java data structures for LLD
## HashMap
HashMap is the implementation of Map, but it doesn't maintain any order.
1. contains values based on the key
2. contains only unique keys
3. may have one null key and multiple null values
4. is non synchronized
5. maintains no order
6. initial default capacity of Java HashMap class is 16 with a load factor of 0.75

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
**Note:** NavigableMap provides more freedom in navigation across a map

## References
1. [Javapoint-HashMap](https://www.javatpoint.com/java-hashmap)
2. [Javapoint-TreeMap](https://www.javatpoint.com/java-treemap)
