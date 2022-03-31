# Math

### Time complexity

1.

```
    What is time complexity of following code :

        int count = 0;
        for (int i = N; i > 0; i /= 2) {
            for (int j = 0; j < i; j++) {
                count += 1;
            }
        }

    Answer: O(N)

    N + N/2 + N/4 + ...... + N/(2^k)    where (2^k)>=N
    N * (1 + 1/2 + 1/4 + ..... + 1/(2^k))
    N * (1 + (1/2 * (1 - (1/2)^k))/(1-1/2))
    N * (1 + (1-(1/2)^k))
    N * (1 + 1) // it can be argued that for very big k, (1/2)^k approaches 0
    O(N)
```

## Reference

1. [Wikipedia - 1/2 + 1/4 + 1/8 + 1/16 + ...](https://en.wikipedia.org/wiki/1/2_%2B_1/4_%2B_1/8_%2B_1/16_%2B_%E2%8B%AF)
