#include <iostream>

// this function will not work for deletion of last element
void remove_middle(int arr[], int i, int length)
{
    for (int index = i+1; index < length; index++)
        arr[index-1] = arr[index];
}

int main()
{
    myArray = {1,3,5};
    myArray[i];
