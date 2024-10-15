#include <stdio.h>

void delete_element(int* array, int arrlen, int position);
void print_array(int* array, int arrlen);

int main(void)
{
    int arrlen = 3;
    int myArray[] = {1, 3, 5};

    print_array(myArray, arrlen);

    delete_element(myArray, arrlen, 0); 
    print_array(myArray, arrlen-1);


    return 0;
}

void delete_element(int* array, int arrlen, int position)
{
    int i=0;
    while (i<(arrlen-1)) {
        array[position+i] = array[position+i+1]; 
        i++;
    }
}

void print_array(int* array, int arrlen)
{
    for (size_t i = 0; i<arrlen; i++)
        printf("%d ",  array[i]);
    printf("\n");
}
