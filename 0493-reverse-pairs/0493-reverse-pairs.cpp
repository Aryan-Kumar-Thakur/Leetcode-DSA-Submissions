class Solution {
int cnt=0;
void merge(vector<int> &nums,int lo,int hi,int mid){
    int res=0;
    int i=lo,j=mid+1;
    while(i<=mid){
        while(j<=hi && nums[i]>(long long)2*nums[j])
        {
            j++;
        }
        res+=(j-(mid+1));
        i++;
    }
    int n1=mid-lo+1;
    int n2=hi-mid;
    int first[n1];
    int second[n2];
    int mainind=lo;
    for(int i=0;i<n1;i++){
        first[i]=nums[mainind++];
    }
    mainind=mid+1;
    for(int i=0;i<n2;i++){
        second[i]=nums[mainind++];
    }
    i=0,j=0;
    mainind=lo;
    while(i<n1 && j<n2){
        if(first[i] <= second[j]){
            nums[mainind++]=first[i++];
        }
        else{
            nums[mainind++]=second[j++];
        }
    }
    while(i<n1){
        nums[mainind++]=first[i++];
    }
    while(j<n2){
        nums[mainind++]=second[j++];
    }
    cnt+=res;
}
void mergesort(vector<int> &nums,int lo,int hi){
    if(lo < hi){
        int mid=(lo+hi)/2;
        mergesort(nums,lo,mid);
        mergesort(nums,mid+1,hi);
        merge(nums,lo,hi,mid);
    }
}
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return cnt;
    }
};