#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include <cstddef>
#include <vector>

template<typename T>
void InsertionSort(std::vector<T> &A) {
    for (std::size_t i = 1; i < A.size(); i++) {
        T key = A[i];
        // Insert A[i] into the sorted subarray A[0:i-1]
        ptrdiff_t j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j] = key;
    }
}

#endif
