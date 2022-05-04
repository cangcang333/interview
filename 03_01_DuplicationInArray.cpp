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
int main(int argc, char **argv) {
    //int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int arr[] = {2, 3, 1, 1, 4, 5, 6};
    //int arr[] = {0, 1, 2, 3, 4, 5, 6};
    //int arr[] = {0};
    int arrayLen = sizeof(arr) / sizeof(arr[0]);
    std::cout << "arrayLen is " << arrayLen << std::endl;
    int dup = findDuplication(arr, arrayLen);
    std::cout << "dup is " << dup << std::endl;

    int rep ;
    bool flag = duplicate(arr, arrayLen, &rep);
    std::cout << "flag is " << flag << " rep is " << rep << std::endl;

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}