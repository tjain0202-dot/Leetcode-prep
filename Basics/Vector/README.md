// NOTE: The logic and code implementation were written by me. 
// I used AI to generate the detailed explanatory comments to help structure my learning log.

## 📝 What I Learned Today

* **Built-in Sorting:** `sort()` replaces manual looping and organizes tracking vectors instantly.
* **Smart Searching:** `lower_bound()` uses fast internal binary search, but strictly requires data to be sorted first.
* **Instant Math:** `accumulate()` sums up an entire range in a single line without manual loops.
* **Uniqueness Filters:** `unordered_set` filters out duplicate entries because it cannot hold identical values.
* **Smart Mapping:** `unordered_map` operates like a lookup directory, mapping keys to values for instant verification.

---

## 💻 STL Algorithms Practiced

### 1. Vector Sorting (`sort`)
* **How it works:** Rearranges disordered numbers from smallest to largest using internal memory references.
* **Easy Example:**
```cpp
vector<int> v = {5, 2, 8, 1};
sort(v.begin(), v.end()); // Changes layout to: 1 2 5 8
```
* **Intermediate Challenge (Reverse Sorting):** Pass reverse iterators to swap the direction from largest to smallest.
```cpp
vector<int> nums = {10, 40, 20};
sort(nums.rbegin(), nums.rend()); // Changes layout to: 40 20 10
```

### 2. Fast Boundary Search (`lower_bound`)
* **How it works:** Locates the first element that matches or is greater than your target. It gives an iterator position.
* **Easy Example:**
```cpp
vector<int> v = {1, 2, 5, 8, 9}; // Must be pre-sorted!
auto it = lower_bound(v.begin(), v.end(), 6); 
cout << *it; // OUTPUT: 8 (first number greater than or equal to 6)
```
* **Intermediate Challenge (Finding Index):** Subtracting the start marker calculates the normal index location.
```cpp
int index = it - v.begin(); // OUTPUT: 3 (index where 8 is located)
```

### 3. Range Summation (`accumulate`)
* **How it works:** Adds up values across a tracking loop. The last digit parameter specifies the initial starting total.
* **Easy Example:**
```cpp
vector<int> v = {1, 2, 3};
int total = accumulate(v.begin(), v.end(), 0); // OUTPUT: 6 (1 + 2 + 3)
```
* **Intermediate Challenge (Partial Sum):** Shift markers using mathematical offsets to read target sections only.
```cpp
// Sums elements inside the first half of the array block
int half_sum = accumulate(v.begin(), v.begin() + (v.size() / 2), 0);
```

---

## 🛠️ LeetCode Tools & Optimization

### 4. Twin Detection (`adjacent_find`)
* **How it works:** Scans sorted sequences sequentially to check if identical numbers are seated directly next to each other.
* **Easy Example:**
```cpp
vector<int> v = {1, 2, 2, 4}; // Sorted first
auto it = adjacent_find(v.begin(), v.end());
if(it != v.end()) cout << "Duplicate found: " << *it; // OUTPUT: 2
```

### 5. Unique Value Storage (`unordered_set`)
* **How it works:** Tracks entries internally and instantly rejects inserts if that item already exists in memory.
* **Easy Example:**
```cpp
unordered_set<int> s;
s.insert(10);
s.insert(10); // Automatically blocked and discarded!
cout << s.size(); // OUTPUT: 1
```

### 6. Key-Value Index Directories (`unordered_map`)
* **How it works:** Pairs data sets directly together (e.g., links a value string/int directly to its array array index).
* **Easy Example:**
```cpp
unordered_map<int, int> mp;
mp[5] = 0; // Maps key 5 to index tracking position 0
if(mp.find(5) != mp.end()) {
    cout << "Found index: " << mp[5]; // OUTPUT: 0
}
```

---

## ⚙️ Core Libraries Summary
* `<algorithm>` ➡️ `sort()`, `lower_bound()`, `adjacent_find()`
* `<numeric>` ➡️ `accumulate()`
* `<unordered_set>` ➡️ `unordered_set` containers
* `<unordered_map>` ➡️ `unordered_map` data trackers
