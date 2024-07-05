# Trie_Search_Engine

In computer science, a trie, also called digital tree or prefix tree, is a kind of search tree—an ordered tree data structure used to store a dynamic set or associative array where the keys are usually strings.

Unlike a binary search tree, no node in the tree stores the key associated with that node; instead, its position in the tree defines the key with which it is associated; i.e., the value of the key is distributed across the structure. All the descendants of a node have a common prefix of the string associated with that node, and the root is associated with the empty string. Keys tend to be associated with leaves, though some inner nodes may correspond to keys of interest. Hence, keys are not necessarily associated with every node. For the space-optimized presentation of prefix tree, see compact prefix tree.

![image](https://github.com/Chaitanya-030/Trie_Search_Engine/assets/134582344/256ce56c-10d8-4e7a-b1fe-21b92b96b931)

### Key Advantages
1. Looking up data in a trie is faster in the worst case, O(m) time (where m is the length of a search string), compared to an imperfect hash table. An imperfect hash table can have key collisions. A key collision is the hash function mapping of different keys to the same position in a hash table. The worst-case lookup speed in an imperfect hash table is O(N) time, but far more typically is O(1), with O(m) time spent evaluating the hash. <br/>
2. There are no collisions of different keys in a trie. <br/>
3. There is no need to provide a hash function or to change hash functions as more keys are added to a trie. <br/>
4. A trie can provide an alphabetical ordering of the entries by key.

### Applications : 
1. Autocomplete and Text Prediction: Tries are widely used in autocomplete features of text editors, search engines, and messaging applications. They efficiently store and retrieve words based on prefixes, making it quick to suggest completions as users type. <br/>
2. Dictionary Implementations: Tries are ideal for implementing dictionaries where words can be inserted, deleted, and searched efficiently. They can also be used for spell-checking and word validation. <br/>
3. Routing Tables in Networking: Tries are used to store IP addresses in routers' routing tables. They allow routers to efficiently determine the next hop for forwarding packets based on the longest matching prefix. <br/>
4. Symbol Tables in Compilers: Tries are used in compilers and interpreters to implement symbol tables, storing variables, functions, and other identifiers efficiently.

### Universal Search
![image](https://github.com/Chaitanya-030/Trie_Search_Engine/assets/134582344/1d980272-220b-42c4-93ed-d3e4e2e9049a)

### Prefix Search
![image](https://github.com/Chaitanya-030/Trie_Search_Engine/assets/134582344/baca878e-6af5-4fb8-8d5f-7073b38677e0)

### Exact search
![image](https://github.com/Chaitanya-030/Trie_Search_Engine/assets/134582344/fc50d49d-5423-41bc-b5cf-30743d14ae4f)


