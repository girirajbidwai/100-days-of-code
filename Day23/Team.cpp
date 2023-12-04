using namespace std;
int main(){
    int n,cnt=0;;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a,tmp=0;
        for(int j = 0; j < 3; j++){
            cin>>a;
            tmp+=a;
        }
        if(tmp>=2) cnt++;
    }
    cout<<cnt;
    return 0;
}
