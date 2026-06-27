// NOTE: The logic and code implementation were written by me. 
// I used AI to generate the detailed explanatory comments to help structure my learning log.
#include<iostream>
#include<vector>
#include<algorithm> // Added for today's topics: sort(), reverse(), and find()
#include<iterator>  // Added for iterator distance math
#include<numeric>   // Added for acumulate , adjacent_find
using namespace std;

int main(){
    // ==========================================
    // DAY 1 REVISION: INITIALIZATION & PRINTING
    // ==========================================
    
    // 2D Vector Grid (Handy for game maps or matrices)
    // vector<vector<char>> grid(3, vector<char>(4,'*'));
    // for(int r=0;r<3;r++){
    //     for(int s=0;s<4;s++){
    //         cout<<grid[r][s]<<" "; 
    // // OUTPUT: * * * *
    //            * * * * 
    //            * * * *
    //     }
    //     cout<<"\n";
    // }
    
    vector<int> nom={1,2,3,2,1};
    
    // 0. ELEMENT ACCESS DIFFERENCE ([ ] vs .at())
    cout<<nom[2]<<endl;    // Fast, but does not check limits. If you ask for nom[100], program crashes silently.
    cout<<nom.at(2)<<endl; // Safe. If you ask for out-of-bounds index, it throws a safe error to catch bugs.
    
    // Range-based for loop (Cleanest way to view all items)
    for(int n : nom) cout<<n<<" ";
    cout<<endl;
    
    // Iterator-based insertion
    nom.insert(nom.begin() + 3 , 4); // Inserts 4 at index 3
    nom.insert(nom.begin() + 4 , 4); // Inserts 4 at index 4
    for(int i=0 ; i<nom.size();i++) cout<<nom[i]<<" ";
    cout<<endl;
    
    // 1. ACCESS METHODS (FRONT & BACK)
    // CRITICAL POINT: Calling these on an empty vector causes undefined behavior (crashing).
    cout<<nom.front()<<endl; // OUTPUT: 1 (first item)
    cout<<nom.back()<<endl;  // OUTPUT: 1 (last item)

    // 2. MODIFIERS (PUSH & POP)
    nom.push_back(9); // adds 9 to end -> {1,2,3,4,4,2,1,9}
    nom.pop_back();    // removes 9 from end -> {1,2,3,4,4,2,1}
    // EXCEPTION: Never call pop_back() on an empty vector, or it will crash.
    
    // 3. REVERSE ITERATORS PRACTICE
    // printing backward using rbegin and rend
    for(auto it = nom.rbegin(); it != nom.rend(); it++){
        cout<<*it<<" "; // OUTPUT: 1 2 4 4 3 2 1
    }
    cout<<endl;

    // 4. CAPACITY METHODS
    cout<<nom.size()<<endl;     // OUTPUT: 7 (How many elements are currently inside)
    cout<<nom.capacity()<<endl; // OUTPUT: Total memory space allocated behind the scenes
    cout<<nom.empty()<<endl;    // OUTPUT: 0 (Returns 1 if completely empty, 0 if it contains elements)

    // ==========================================
    // DAY 2 NEW TOPICS: SORTING & ITERATOR MATH
    // ==========================================

    // 5. SORTING IN ASCENDING ORDER (Smallest to Largest)
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end());        // Rearranges elements from low to high
    for(int x : v) cout << x << " "; // OUTPUT: 1 2 5 8 9
    cout << "\n";

    // 6. SORTING IN DESCENDING ORDER (Largest to Smallest)
    // Trick: Feed reverse iterators to the sorting algorithm
    vector<int> nums = {10, 40, 20, 30};
    sort(nums.rbegin(), nums.rend()); 
    for(int x : nums) cout << x << " "; // OUTPUT: 40 30 20 10
    cout << "\n";

    // Alternative Descending: Use greater<int>() comparator
    vector<int> nums2 = {10, 40, 20, 30};
    sort(nums2.begin(), nums2.end(), greater<int>()); 

    // 7. PRINTING AN ASCENDING LIST IN REVERSE
    sort(v.begin(), v.end()); // v reset to ascending: {1, 2, 5, 8, 9}
    // CRITICAL WARNING: Loop variable 'i' must be signed 'int'.
    // If you use 'unsigned int' or 'size_t', 'i >= 0' is always true, causing an infinite loop crash!
    for (int i = v.size() - 1; i >= 0; i--) { 
        cout << v[i] << " "; // OUTPUT: 9 8 5 2 1
    }
    cout << "\n";

    // 8. ITERATOR DISTANCE MATH (Finding a 0-based Index)
    auto it = find(v.begin(), v.end(), 8); // Finds where number 8 is hiding
    // EXCEPTION SAFETY: Always confirm the element was actually found before doing math
    if (it != v.end()) {
        int index = it - v.begin(); // Current Target Address - Starting Address = Step Distance
        cout << "Index position of 8: " << index << "\n"; // OUTPUT: 3
    }

    // 9. Adjacent find works for sorted array as it finds addjacent num that are duplicate so let v is a sorted array {1,1,2,3}
    auto it = adjacent_find(v.begin(),v.begin()+v.size()); // Finds where number 1 is hiding now it is pointing to first 1
    // If it reached the end without finding anything, there are no duplicates
    if (it != v.end()) {// means there is a duplicate as iterator it is not pointing to end of vector
        return true; // Found a duplicate!
    }
    return false;

    // 10. finding pivot index
    int left_sum=0;
    int total_sum= accumulate(v.begin(),v.end(),0); // total sum of vector
    for(int i=0;i<v.size();i++){
        int right_sum=total_sum-left_sum-v[i]; // right sum is total sum - left sum - current element
        if(left_sum==right_sum){
            return i; // pivot index found
        }
        left_sum+=v[i]; // update left sum for next iteration
    }
    // . CLEAR METHOD 
    // WARNING: Run this only when you are 100% finished using the data.
    nom.clear(); // erases everything inside 'nom', size drops to 0
    cout<<nom.size()<<endl; // OUTPUT: 0
}
