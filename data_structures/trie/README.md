---
kind: theory
title: Trie
topic_id: data_structures/trie
---

# Trie

## Overview

A trie stores strings by shared prefixes. Each edge represents a character, making prefix lookup proportional to the query length rather than the number of stored words.

## Key Observations

1. Distinguish a complete word marker from the existence of a prefix.
2. Trie nodes trade memory for predictable character-by-character lookup.
3. A trie can prune a board search as soon as the current prefix matches no stored word.

## Algorithm Analysis

Insert, exact search, and prefix search take $O(L)$ time for a string of length $L$.

## References
1. [Introduction to Trie](https://leetcode.com/discuss/general-discussion/1066206/introduction-to-trie) by [@since2020](https://leetcode.com/since2020/)