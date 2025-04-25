#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    int arr[100000];
    for(int i=0 ; i<N ; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int mindiff = 2000001;
    for(int i=0 ; i<=N-k ; i++){
        int maxval = arr[i];
        int minval = arr[i];

        for(int j=i ; j<i+k ; j++){
            if(arr[j] > maxval){
                maxval = arr[j];
            }
            if(arr[j] < minval){
                minval = arr[j];
            }
        }
        int diff = maxval - minval;
        if(diff < mindiff){
            mindiff = diff;
        }
    }
    cout<<mindiff<<endl;
    return 0;
}
