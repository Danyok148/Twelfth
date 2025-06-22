#include <iostream>
using namespace std;

void addBlockToEnd(int*& arr, int& size, int* block, int blockSize) {
    int* newArr = new int[size + blockSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        newArr[size + i] = block[i];
    }
    delete[] arr;
    arr = newArr;
    size += blockSize;
}

void insertBlockAtIndex(int*& arr, int& size, int* block, int blockSize, int index) {
    if (index < 0) index = 0;
    if (index > size) index = size;
    int* newArr = new int[size + blockSize];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        newArr[index + i] = block[i];
    }
    for (int i = index; i < size; i++) {
        newArr[blockSize + i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size += blockSize;
}

void deleteBlockAtIndex(int*& arr, int& size, int index, int blockSize) {
    if (index < 0) index = 0;
    if (index >= size) return;
    if (index + blockSize > size) blockSize = size - index;
    int* newArr = new int[size - blockSize];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + blockSize; i < size; i++) {
        newArr[i - blockSize] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size -= blockSize;
}

int main() {
    int size = 6;
    int* arr = new int[size] {1, -2, 3, -4, 5, -6};

    //   1
    int indexToDelete;
    cout << "Enter index to delete: ";
    cin >> indexToDelete;
    if (indexToDelete >= 0 && indexToDelete < size) {
        int* newArr = new int[size - 1];
        for (int i = 0; i < indexToDelete; i++) {
            newArr[i] = arr[i];
        }
        for (int i = indexToDelete + 1; i < size; i++) {
            newArr[i - 1] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size--;
    }

    //  2
    int negativeCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) negativeCount++;
    }
    int* negatives = new int[negativeCount];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negatives[j] = arr[i];
            j++;
        }
    }

    //  3
    int block1[3] = { 7, 8, 9 };
    addBlockToEnd(arr, size, block1, 3);

    //  4
    int block2[2] = { 10, 11 };
    insertBlockAtIndex(arr, size, block2, 2, 2);

    //5
    deleteBlockAtIndex(arr, size, 1, 3);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    delete[] negatives;
    return 0;
}
