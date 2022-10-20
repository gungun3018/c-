#include <bits/stdc++.h>
using namespace std;
typedef long long int li;

void insertionSortIP(li arr[], li n) {
    li i = 0, j = i + 1;
    while (j <= n - 1) {
        li temp = arr[j];
        while (i >= 0) {
            if (arr[i] > temp) {
                arr[i + 1] = arr[i];
                i--;
            }
            if (i == -1) {
                arr[0] = temp;
                break;
            }
            if (arr[i] <= temp) {
                arr[i + 1] = temp;
                break;
            }
        }
        j++;
        i = j - 1;
    }
    return;
}

void insertion_sort_OP(li arr[], li si, li ei) {
    if (si == ei) {
        return;
    }
    li j = si + 1;
    li temp = arr[j];
    while (si >= 0) {
        if (arr[si] > temp) {
            arr[si + 1] = arr[si];
            si--;
        }
        if (si == -1) {
            arr[0] = temp;
            break;
        }
        if (arr[si] <= temp) {
            arr[si + 1] = temp;
            break;
        }
    }
    insertion_sort_OP(arr, si + 1, ei);
}
void pfun(li arr[], li n){ for(li i = 0; i < n; i++){ cout << arr[i] << " ";}}
    

int main() {
    li n;
    cin >> n;
    li arr[n], arr2[n];
    cout << "ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for (li i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (li i = 0; i < n; i++) arr2[i] = arr[i];
    
    cout << endl;
    cout << "ARRAY BEFORE SORTING : ";
    pfun(arr, n);
    insertionSortIP(arr, n);
    cout << endl;
    cout << "ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    pfun(arr, n);
    cout << endl;
    insertion_sort_OP(arr2, 0, n - 1);
    cout << "ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    pfun(arr, n);
    cout << endl;

}

// ANS.3

// In-place techniques have lesser space complexity but are difficult to 
// apply in algorithm whereas out-place techniques are easy to aplly but 
// increases the space complexity of algorithm.
// For exapmle if we want to reverse an array then its in-place algorithm
// will be swaping the first and last element of array until we reach the 
// middle of array,If we want to solve the same problem using out-place 
// algorithm we have to create one extra array of same size and copy 
// elements of original array from back to the front of new array,this 
// algorith increases the space complexity to O(n) as we have creaed an 
// extra array.

// IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
// NOT IN-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.