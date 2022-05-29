#include <iostream>

void printArray(int arr[], int arrayLen, int i) {
    std::cout << "index " << i << " , array ";
    for (int i = 0; i < arrayLen; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int countRangeData(int arr[], int arrayLen, int min, int max) {
    int count = 0;
    for (int i = 0; i < arrayLen; ++i) {
        if (arr[i] >= min && arr[i] <= max) {
            ++count;
        }
    }
    return count;
}

int findDuplication(int arr[], int arrayLen, int low, int high) {
    int dup = -1;
    if (low == high) {
        int digitalCount = countRangeData(arr, arrayLen, low, high);
        if (digitalCount > 1) {
            std::cout << "Find dup " << low << std::endl;
            dup = low;
            return dup;
        }
    }

    int mid = low + (high - low) / 2;
    printf("low: %d, high: %d, mid: %d\n", low, high, mid);
    // left range [low, mid], right range [mid+1, high]
    int leftCount = countRangeData(arr, arrayLen, low, mid);
    int rightCount = countRangeData(arr, arrayLen, mid+1, high);
    printf("leftCount: %d, rightCount: %d\n", leftCount, rightCount);
    if (leftCount > mid - low + 1) {
        dup = findDuplication(arr, arrayLen, low, mid);
    } else if (rightCount > high - mid) {
        dup = findDuplication(arr, arrayLen, mid+1, high);
    }


    return dup;
}

/**
 * find any duplicated number in an array, no change for input array.
 * array length: n
 * array number between 0 ~ n-1
 * @param arr
 * @return -1 means not found
 */
int findDuplicationNoEdit(int arr[], int arrayLen) {
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

    // 二分统计法
    int dup = findDuplication(arr, arrayLen, 1, arrayLen - 1);
    std::cout << "Finally duplication is " << dup << std::endl;
    if (-1 != dup) {
        return dup;
    }


    return -1;
}



/**
 *
 * @param numbers
 * @param length
 * @param duplication
 * @return
 *          true - Input valid, exist duplicate
 *          false - Input invalid, no duplicate
 */
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


// =================== Test code ===================
bool contains(int array[], int length, int number)
{
    for (int i = 0; i < length; ++i)
    {
        if (array[i] == number)
        {
            return true;
        }
    }

    return false;
}

void test(char *testName, int numbers[], int lengthNumbers, int expected[], int lengthExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);
    if (validArgument == validArgument)
    {
        if (validArgument)
        {
            if (contains(expected, lengthExpected, duplication)) {
                printf("Passed\n");
            } else {
                printf("FAILED\n");
            }
        }
        else {
            printf("Passed\n");
        }
    }
    else
    {
        printf("FAILED\n");
    }
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = {2, 1, 3, 1, 4};
    int duplications[] = {1};
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = {2, 4, 3, 1, 4};
    int duplications[] = {4};
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = {2, 4, 2, 1, 4};
    int duplications[] = {2, 4};
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中没有重复的数字
void test4()
{
    int numbers[] = {2, 4, 3, 0, 4};
    int duplications[] = {-1};
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 数组中没有重复的数字
void test5()
{
    int numbers[] = {2, 4, 3, 5, 4};
    int duplications[] = {-1};
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

//  无效的输入
void test6()
{
    int *numbers = nullptr;
    int duplications[] = {-1};
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

/**
 * 数组长度 n+1，数字范围 1 ~ n，找出重复数字。限制：不能修改输入数组
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    int arr[] = {2, 3, 5, 4, 3, 2, 6, 7};

    int arrayLen = sizeof(arr) / sizeof(arr[0]);

    std::cout << "arrayLen is " << arrayLen << std::endl;
    int dup = findDuplicationNoEdit(arr, arrayLen);
    std::cout << "dup is " << dup << std::endl;

    /*
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
     */

}