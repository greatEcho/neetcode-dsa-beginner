/*
    implementation of insertion sort
    wost case - O(n^2)
    best case - O(n)
*/

/* TODO:
    - implement sorting algorithm for static int array
    - implement one for any array or std container
*/
#include <cassert>
#include <utility>
#include <vector>


/* only for static arrays */
template<class T>
void sort(T arr[], int len)
{
  int i, j;
  T bucket;
  for (i=1; i<len; ++i) {
    j = i;
    while (j > 0 && arr[j-1]>arr[j]) {
      bucket = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = bucket;
      j--;
    }
  }
}

template<class T>
void sort(std::vector<T>& arr)
{
  int i, j;
  for (i=1; i<arr.size(); ++i) {
    j=i;
    while (j>0 && arr[j-1]>arr[j]) {
      std::swap(arr[j-1], arr[j]);
      j--;
    }
  }
}



template<class T>
bool isEqual(T arr1[], T arr2[], int len);

void change(int arr[])
{
  arr[1] = 22;
}

int main(void)
{
  int length;
  int arr1[] = {2, 1, 3, 5, 8, 6};
  int sorted1[] = {1, 2, 3, 5, 6, 8};
  length = sizeof(arr1)/sizeof(int);
  sort(arr1, length);
  assert(isEqual(arr1, sorted1, length));

  double arr2[] = {1.77, 2.1, -3.984, -3.08, 55.4, 0.};
  double sorted2[] = {-3.984, -3.08, 0., 1.77, 2.1, 55.4};
  length = sizeof(arr2)/sizeof(arr2[0]);
  sort(arr2, length);
  assert(isEqual(arr2, sorted2, length));

  int* arr3 = new int[10];
  arr3[0] = 1; arr2[1] = 2;
  assert(1[arr3] == *(arr3+1));
  delete[] arr3;
  arr3 = nullptr;

  // dynamic arrays
}

template<class T>
bool isEqual(T arr1[], T arr2[], int len)
{
  for (int i=0; i<len; ++i)
    if (arr1[i] != arr2[i]) return false;
  return true;
}
