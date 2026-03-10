class Solution {
  public:
    int billOf5 = 0;
    int billOf10 = 0;
    int billOf20 = 0;
    bool canServe(vector<int> &arr) {
        // code here
        for(int i=0; i<arr.size(); i++){
            switch(arr[i]){
                case 5:
                    billOf5++;
                break;
                case 10:
                    if(billOf5 >= 1){
                        billOf5--;
                        billOf10++;
                    }else{
                        return false;
                    }
                break;
                case 20:
                    if(billOf10 >= 1 && billOf5 >= 1){
                        billOf10--;
                        billOf5--;
                        billOf20++;
                    }else if(billOf5>=3){
                        billOf5-=3;
                        billOf20++;
                    }else{
                        return false;
                    }
                break;
            }
        }
        return true;
    }
};