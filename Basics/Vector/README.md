#  Day 2: Mastering C++ std::vector

##  What I Learned Today

* **Dynamic Resizing:** Unlike normal arrays, vectors can grow and shrink automatically using `push_back()` and `pop_back()`.
* **Safe Access:** Learned that `v.at(index)` is safer than `v[index]` because it checks if the index actually exists.
* **Iterators:** Used `rbegin()` and `rend()` to loop through the vector backwards without messing up index math.
* **Size vs Capacity:** `size()` tells how many elements are inside, while `capacity()` is the actual memory allocated behind the scenes.

### 1. 2D Vector Initialization (Grid)
```cpp
// Creates a 3x4 grid filled with '*' character
vector<vector<char>> grid(3, vector<char>(4, '*'));
```

### 2. Element Insertion
```cpp
// Inserting number 4 at specific positions using iterators
nom.insert(nom.begin() + 3, 4);
nom.insert(nom.begin() + 4, 4);
```

### 3. Traversal Backwards
```cpp
// Printing elements from last to first
for(auto it = nom.rbegin(); it != nom.rend(); it++) {
    cout << *it << " ";
}
```

## ⚙️ Methods Used Summary
* **Access:** `[]`, `.at()`, `.front()`, `.back()`
* **Modifiers:** `.push_back()`, `.pop_back()`, `.insert()`, `.clear()`
* **Capacity:** `.size()`, `.capacity()`, `.empty()`
* **Iterators:** `.begin()`, `.end()`, `.rbegin()`, `.rend()`