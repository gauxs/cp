# C++ STL

## priority_queue

- Default declarations

```
priority_queue<int> pq;                             // creates max-heap
priority_queue<int, vector<int>, greater<int>> pq;  // creates min-heap
priority_queue<int> pq(vec.begin(), vec.end());     // init with existing vector
```

- comparator for priority_queue

1. built-in comparator

```
priority_queue<int, vector<int>, greater<int>> pq;  // creates min-heap
```

2. user defined comparator

```
struct mycomparator{
    bool operator()(int const&a, int const&b){
        return a<b; // max-heap
        return a>b; // min-heap
    }
}

priority_queue<int, vector<int>, mycomparator> pq;
```

## set
