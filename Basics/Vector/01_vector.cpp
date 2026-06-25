#include<iostream>
#include<vector>
using namespace std;
int main(){
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
    cout<<nom[2]<<endl;
    cout<<nom.at(2)<<endl;
    for(int n : nom) cout<<n<<" ";
    cout<<endl;
    nom.insert(nom.begin() + 3 , 4);
    nom.insert(nom.begin() + 4 , 4);
    for(int i=0 ; i<nom.size();i++) cout<<nom[i]<<" ";
    cout<<endl;
    
    // 1. ACCESS METHODS (FRONT & BACK)
    cout<<nom.front()<<endl; // OUTPUT: 1 (first item)
    cout<<nom.back()<<endl;  // OUTPUT: 1 (last item)

    // 2. MODIFIERS (PUSH & POP)
    nom.push_back(9); // adds 9 to end -> {1,2,3,4,4,2,1,9}
    nom.pop_back();    // removes 9 from end -> {1,2,3,4,4,2,1}
    
    // 3. REVERSE ITERATORS PRACTICE
    // printing backward using rbegin and rend
    for(auto it = nom.rbegin(); it != nom.rend(); it++){
        cout<<*it<<" "; // OUTPUT: 1 2 4 4 3 2 1
    }
    cout<<endl;

    // 4. CAPACITY METHODS
    cout<<nom.size()<<endl;     // OUTPUT: 7 (total elements inside)
    cout<<nom.capacity()<<endl; // OUTPUT: total allocated space (usually doubled)
    cout<<nom.empty()<<endl;    // OUTPUT: 0 (false, because it is not empty)

    // 5. CLEAR METHOD
    nom.clear(); // erases everything, size becomes 0
    cout<<nom.size()<<endl; // OUTPUT: 0
}