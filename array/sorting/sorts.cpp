#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& nums, int n) {
  for(int i=0; i<n; i++) {
    int countSwap = 0;
    // sorts from back
    for(int j=0; j<n-1-i; j++) {
      if(nums[j] > nums[j+1]) {
        countSwap++;
        swap(nums[j], nums[j+1]);
      }
    }
    if(countSwap == 0) {
      return;
    }
  }
}

void selectionSort(vector<int>& nums, int n) {
  for(int i=0; i<n; i++) {
    int minIndex = i;
    // sorts from start
    for(int j=i+1; j<n; j++) {
      if(nums[j] < nums[minIndex]) {
        minIndex = j;
      }
    }
    if(minIndex != i) {
      swap(nums[i], nums[minIndex]);
    }
  }
}

void insertionSort(vector<int>& nums, int n) {
  for(int i=0; i<n; i++) {
    int card = i;
    // playing cards
    while(card > 0 && nums[card] < nums[card-1]) {
      swap(nums[card], nums[card-1]);
      card--;
    }
  }
}

void merge(vector<int>& nums, int left, int mid, int right) {
  int n = mid - left + 1; // including mid
  int m = right - mid; // excluding mid
  int a[n], b[m];

  for(int i=0; i<n; i++) {
    a[i] = nums[i + left];
  }
  for(int i=0; i<m; i++) {
    b[i] = nums[i + (mid + 1)];
  }

  vector<int> temp;
  int i = 0;
  int j = 0;

  while(i < n && j < m) {
    if(a[i] <= b[j]) {
      temp.push_back(a[i]);
      i++;
    } else {
      temp.push_back(b[j]);
      j++;
    }
  }
  while(i < n) {
    temp.push_back(a[i++]);
  }
  while(j < m) {
    temp.push_back(b[j++]);
  }

  for(auto& it: temp) {
    nums[left++] = it;
  }
}

void ms(vector<int>& nums, int left, int right) {
  // base case
  if(right-left+1 == 1) {
    return;
  }

  // transition
  int mid = (left + right) / 2;
  ms(nums, left, mid);
  ms(nums, mid+1, right);
  merge(nums, left, mid, right);
}

void mergeSort(vector<int>& nums, int n) {
  ms(nums, 0, n-1);
}

int partition(vector<int>& nums, int left, int right) {
  int pivot = left;
  while(left <= right) {
    while(nums[left] <= nums[pivot]) {
      left++;
    }
    while(nums[right] > nums[pivot]) {
      right--;
    }
    if(left <= right) {
      swap(nums[left], nums[right]);
    }
  }
  swap(nums[pivot], nums[right]);
  return right;
}

void qs(vector<int>& nums, int left, int right) {
  // base case
  if(left >= right) {
    return;
  }

  // transition
  int pivot = partition(nums, left, right);
  qs(nums, left, pivot-1);
  qs(nums, pivot+1, right);
}

void quickSort(vector<int>& nums, int n) {
  qs(nums, 0, n-1);
}

void heapify(vector<int>& nums, int n, int i) {
  int maxi = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if(left < n && nums[left] > nums[maxi]) {
    maxi = left;
  }
  if(right < n && nums[right] > nums[maxi]) {
    maxi = right;
  }
  if(maxi != i) {
    swap(nums[maxi], nums[i]);
    heapify(nums, n, maxi);
  }
}

void buildHeap(vector<int>& nums, int n) {
  for(int i=n/2-1; i>=0; i--) { // O(n)
    heapify(nums, n, i); // O(logn)
  }
}

void heapSort(vector<int>& nums, int n) {
  buildHeap(nums, n);
  for(int i=n-1; i>=0; i--) {
    swap(nums[0], nums[i]);
    heapify(nums, i, 0);
  }
}

int main() {
  vector<int> nums = {5, 4, 3, 2, 1};
  int n = nums.size();

  // bubbleSort(nums, n);
  // selectionSort(nums, n);
  // insertionSort(nums, n);
  // mergeSort(nums, n);
  // quickSort(nums, n);
  heapSort(nums, n);

  for(int i=0; i<n; i++) {
    cout << nums[i] << " ";
  }

  return 0;
}