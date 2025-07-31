/* Allocate Minimum Pages :
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. 
You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, 
find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1. */


class Solution {
  public:
// Your code is here
    bool isPossible(vector<int>& arr, int k, int maxPages) {
    // code here
    int students = 1;
    int currentSum = 0;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxPages) return false;
        
        if(currentSum + arr[i] > maxPages){
            students++;
            currentSum = arr[i];
            
            if(students > k) return false;
        } else {
            currentSum += arr[i];
        }
    }
    return true;
    
}
    
int findPages(vector<int>&arr, int k){
    int n = arr.size();
    if(k > n) return -1;
        
    int low = arr[0];
    int high = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > low)
            low = arr[i];
        high += arr[i];
    }
        int result = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if (isPossible(arr, k, mid)){
                result = mid;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
    
        return result;

    }
};
