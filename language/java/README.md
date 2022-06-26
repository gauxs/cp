# Java data structures for LLD
## TreeMap
1. contains only unique elements
2. not synchronized
3. cannot have a null key but can have multiple null values
4. maintains ascending order

```
Map<Integer, String> treeMap = new TreeMap<>();

treeMap.put(5, "five");
treeMap.put(1, "one");
treeMap.put(3, "three");
treeMap.put(10, "ten");

for(Map.Entry<Integer,String> v :treeMap.entrySet())
    System.out.println(v.getKey() + " " + v.getValue());
```    
```
OUTPUT:
1 one
3 three
5 five
10 ten
```

