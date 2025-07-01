class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
        
        int candidate1 = 0, count1 = 0;
        int candidate2 = 0, count2 = 0;
        
        //1st pass: find potential candidates
        for(int num : arr){
            if(num == candidate1){
            count1++;
            }
            else if(num == candidate2){
                count2++;
            }
            else if(count1 == 0){
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
    
    // 2nd pass: confirm actual counts
        count1 = 0;
        count2 = 0;
        for(int num :arr){
            if(num == candidate1) 
                count1++;
            else if(num == candidate2)
                count2++;
        }
    
        vector<int> result;
        if(count1 > n/3)
            result.push_back(candidate1);
        if(count2 > n/3)
            result.push_back(candidate2);
    
        // Ensure output is sorted in increasing order
        sort(result.begin(),result.end());
        return result;
    }
};














