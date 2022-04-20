#include <iostream>

/**
 * find any duplicated number in an array.
 * array length: n
 * array number between 0 ~ n-1
 * @param arr
 * @return
 */
int findDuplication(int arr[], int arrayLen) {
    if (nullptr == arr || arrayLen <= 0) {
        return -1;
    }
    if (1 == arrayLen) {
        return arr[0];
    }


}

int main(int argc, char **argv) {
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int arrayLen = sizeof(arr) / sizeof(arr[0]);
    std::cout << "arrayLen is " << arrayLen << std::endl;
    int dup = findDuplication(arr, arrayLen);
    std::cout << "dup is " << dup << std::endl;
}