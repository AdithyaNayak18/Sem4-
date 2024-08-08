#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    cout << "Enter the number of digits";
    int n;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the digis \n";
    for(int i=0;i <n;i++){
        cin >> arr[i];
    }
    auto start = high_resolution_clock::now();

    mergeSort(arr,0,n-1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end-start).count(); 

    cout << "Sorted array :\n";
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    cout << "\nTime taken by merge sort : " << duration << " ms\n";
    return 0;
}

void mergeSort(vector<int> &arr, int left, int right){
    if(left < right){
        int mid = left + (right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        Merge(arr,left,mid,right);
    }
}

void Merge(vector<int>& arr, int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
     for(int j=0;j<n2;j++){
        R[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=left;

  while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    if(i<n1){
        arr[k++]=L[i++];
    }
    if(j<n2){
        arr[k++]=R[j++];
    }

}
