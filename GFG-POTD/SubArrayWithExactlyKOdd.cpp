class Solution {
  public:
    int countOddWithXMost(vector<int>& arr, int x){
        int odds = 0;
        int start = 0;
        int oddCount = 0;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]%2){
                odds++;
            }
            while(odds > x){
                if(arr[start]%2){
                    odds--;
                }
                start++;
            }
            oddCount += (i-start+1);
            
        }
        return oddCount;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int oddsWithMaxK = countOddWithXMost(arr, k);
        int oddsWithMaxKLess1 = countOddWithXMost(arr, k-1);
        return oddsWithMaxK - oddsWithMaxKLess1;
    }
};