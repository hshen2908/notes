#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void InsertionSort(void* A, size_t n, size_t size, int (*cmp)(const void*, const void*)) {
    for (size_t i = 1; i < n; i++) {
        char* keybuf = (char*) malloc(size);
        memcpy(keybuf, ((void*)A)+i*size, size);
        ptrdiff_t j = i - 1;
        while (j >= 0 && cmp(((void*)A)+j*size, keybuf)) {
            memcpy(((void*)A)+(j+1)*size, ((void*)A)+j*size, size);
            j--;
        }
        memcpy(((void*)A)+j*size, keybuf, size);
    }
}

void InsertionSort(void** A, size_t n, int (*cmp)(const void*, const void*)) {
    for (size_t i = 1; i < n; i++) {
        void* key = A[i];
        // Insert A[i] into the sorted subarray A[0:i-1]
        ptrdiff_t  j = i - 1;
        while (j >= 0 && cmp(A[j], key)) {
            A[j+1] = A[j];
            j--;
        }
        A[j] = key;
    }
}
