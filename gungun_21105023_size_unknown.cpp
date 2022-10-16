//Gungun Template
#include <bits/stdc++.h>
typedef long long int li;
using namespace std;
li linear_search(li arr[], li x){
    for (li i = 0;;i++){
        if (arr[i] == x) return i;
    }
}

li binary_search_code(li arr[],li l,li r,li x){
    li mid = l + (r-l)/2;
    while(l<=r){
        if(arr[mid]>x){
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<x){
            l = mid+1;
            mid = (l+r) / 2;
        }
        else  return mid;
    }
}

li binary_search(li arr[], li x){
    li low = 0;
    li high = 1;
    while (arr[high] < x) {
        low = high;
        high = 2 * high;
    }
    return binary_search_code(arr,low,high,x);
}


int main(){
    li *arr = new li[10000];
    li n;
    cin >> n;
    cout << endl;
    for (li i = 0; i < n; i++) cin >> arr[i];
    li x;
    cout << "Enter the element - we need to search for: " << endl;
    cin >> x;
    cout << "Index of " << x << ": " << linear_search(arr, x) << endl;
    cout << "Index of " << x << ": " << binary_search(arr, x) << endl;
    delete[] arr;
}