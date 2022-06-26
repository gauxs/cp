# Java data structures for LLD
## HashMap
HashMap is the implementation of Map, but it doesn't maintain any order.

## TreeMap
TreeMap is the implementation of Map and SortedMap. It maintains ascending order.
1. contains only unique elements
2. not synchronized
3. cannot have a null key but can have multiple null values

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
1. [Javapoint - TreeMap](https://www.javatpoint.com/java-treemap)
