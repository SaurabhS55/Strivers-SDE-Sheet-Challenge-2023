// Find Nth Root Of M
//

int mul(int n,int mid,int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans*=mid;
    if(ans>m)return 2;
  }
  if(ans==m){
    return 1;
  }
  return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int min=1,max=m;
  while(min<=max){
    int mid=min+(max-min)/2;
    int t=mul(n,mid,m);
    if(t==1){
      return mid;
    }
    else if(t==2){
      max=mid-1;
    }
    else{
      min=mid+1;
    }
  }
  return -1;
}