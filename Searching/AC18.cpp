// 4.   Binary search algorithm
/* #include<iostream>
#include<vector>    
using namespace std;

int binarySearch(vector<int> arr, int tar){ // Iterative approach
    int st=0, end=arr.size()-1;

    while(st <= end){
        int mid = (st + end) /2; // mid = 0 + 4 / 2 = 2

        if(tar > arr[mid]){
            st = mid + 1;   // 2nd half
        } else if(tar < arr[mid]){
            end = mid - 1;  // 1st half
        } else{             // tar == arr[mid]; 
            return mid;     // ans mid;
        }
    }

    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar1 = 40;

    // cout << binarySearch(arr1, tar1) << endl; 

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 10;

    cout << binarySearch(arr2, tar2) << endl;
    return 0;
} */








// mid = (st + end) / 2;  -> overflow condition b/c due to addition of two large numbers (INT_MAX + INT_MAX) => overflow condition
// mid = st + (end - st)/2       so we use this formula to avoid overflow condition & this formula is same as mid = (st + end) / 2;        // you also can check it solve the derivation      
// mid = st + (end - st) / 2;  => mid = st + (end - st) / 2;  => mid = (st + end) / 2;

// Binary search algorithm using iteration approach
/* #include<iostream>
#include<vector>    
using namespace std;

int binarySearch(vector<int> arr, int tar){ // Iterative approach
    int st=0, end=arr.size()-1;

    while(st <= end){
        int mid = st + (end - st) /2; // mid = 0 + 4 / 2 = 2

        if(tar > arr[mid]){
            st = mid + 1;   // 2nd half
        } else if(tar < arr[mid]){
            end = mid - 1;  // 1st half
        } else{             // tar == arr[mid]; 
            return mid;     // ans mid;
        }
    }

    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar1 = 40;

    // cout << binarySearch(arr1, tar1) << endl; 

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 10;

    cout << binarySearch(arr2, tar2) << endl;
    return 0;
} */
// for same example Linear search use - 10 operations
//                  Binary search use ~ 4 operations   
// Time complexity is from how many operations we are doing that value of n reduces and becomes 1 is known as Time complexity
// n = 2^k  =>  log^n 2 = k;

/* Binary search Time complexity - O(log n)
    n    n/2^0    | | | | | | | | | | |   

    n/2  n/2^1       | | | | | | | |

    n/4  n/2^2           | | | | |   

    n/8  n/2^3            | | | |

    |    n/2^k               |
    |    n/2^k               |   
    |    n/2^k               |

    1    n/2^k = 1          | |   (st = end) */







// Binary Search with Recursion
/* 1. tar > a[n] 2nd
2. tar < a[m] 1st
3. ans -> mid */

/*      int BS(arr, tar, st, end){
            if(st <= end){}
        mid = st + (end - st) / 2;
        if(tar > arr[mid])
            return BS (arr, tar, st, mid+1); -> 1st half
        else if(tar < arr[mid])
            return BS (arr, tar, st, mid -1); -> 2nd half
        else 
            return mid; 
    }   
            return -1;
} */








#include<iostream>
#include<vector>    
using namespace std;

/* int binarySearch(vector<int> arr, int tar){ // Iterative approach
    int st=0, end=arr.size()-1;

    while(st <= end){
        int mid = st + (end - st) /2; // mid = 0 + 4 / 2 = 2

        if(tar > arr[mid]){
            st = mid + 1;   // 2nd half
        } else if(tar < arr[mid]){
            end = mid - 1;  // 1st half
        } else{             // tar == arr[mid]; 
            return mid;     // ans mid;
        }
    }

    return -1;
} */

int recBinarySearch(vector<int> arr, int tar, int st, int end){
    if(st <= end){
        int mid = st + (end - st)/2;

        if(tar > arr[mid]){ // 2nd half
            return recBinarySearch(arr, tar, mid+1, end);
        } else if(tar < arr[mid]){  // 1st half
            return recBinarySearch(arr, tar, st, mid-1);  
        } else { // mid => ans      // tar == arr[mid]; 
            return mid;             // ans mid;
        }
    }

    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar1 = 40;

    cout << binarySearch(arr1, tar1) << endl; 

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 0;

    cout << binarySearch(arr2, tar2) << endl;

    return 0;
}