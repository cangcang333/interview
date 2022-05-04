#include <iostream>

void printArray(int arr[], int arrayLen, int i) {
    std::cout << "index " << i << " , array ";
    for (int i = 0; i < arrayLen; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * find any duplicated number in an array.
 * array length: n
 * array number between 0 ~ n-1
 * @param arr
 * @return -1 means not found
 */
int findDuplication(int arr[], int arrayLen) {
    // 空指针判断及数组长度判断
    if (nullptr == arr || arrayLen <= 0) {
        return -1;
    }

    // 数组每个元素值范围判断
    // 这个很重要，不判断值范围，后面取值 arr[arr[i]] 有可能越界
    for (int i = 0; i < arrayLen; ++i) {
        if (arr[i] < 0 || arr[i] > arrayLen - 1) {
            return -1;
        }
    }

    if (1 == arrayLen) {
        return -1;
    }

    printArray(arr, arrayLen, 0);

    for (int i = 0; i < arrayLen; ++i) {
        if (i == arr[i]) {
            continue;
        } else {
            int j = arr[i];
            if (arr[j] == j) {
                // find duplicate, arr[i] = arr[j]
                return arr[j];
            } else {
                // switch index i and j values
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                printArray(arr, arrayLen, i);
                // start from position 0
                --i;
            }
        }
    }

    return -1;
}

bool duplicate(int numbers[], int length, int *duplication) {
    if (numbers == nullptr || length <= 0) {
        return false;
    }

    for (int i = 0; i < length; ++i) {
        if (numbers[i] < 0 || numbers[i] > length - 1) {
            return false;
        }
    }

    for (int i = 0; i < length; ++i) {
        while(numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }

            // swap
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;
}

int main(int argc, char **argv) {
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    //int arr[] = {2, 3, 1, 1, 4, 5, 6};
    //int arr[] = {0, 1, 2, 3, 4, 5, 6};
    //int arr[] = {0};
    int arrayLen = sizeof(arr) / sizeof(arr[0]);
    std::cout << "arrayLen is " << arrayLen << std::endl;
    int dup = findDuplication(arr, arrayLen);
    std::cout << "dup is " << dup << std::endl;

    int rep =  -1;
    bool flag = duplicate(arr, arrayLen, &rep);
    std::cout << "flag is " << flag << " rep is " << rep << std::endl;
}