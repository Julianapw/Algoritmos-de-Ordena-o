#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um array aleatório
void gerar_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;  // Números aleatórios entre 0 e 99999
    }
}

// Função para imprimir um array (opcional)
void imprimir_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Implementação do Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Implementação do Selection Sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Implementação do Insertion Sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Implementação do Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Implementação do Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Implementação do Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int* arr = malloc(n * sizeof(int));

        gerar_array(arr, n);

        // Teste Bubble Sort
        int* arr_bubble = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr_bubble[i] = arr[i];
        clock_t inicio = clock();
        bubble_sort(arr_bubble, n);
        clock_t fim = clock();
        double tempo_bubble = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Bubble Sort (n=%d): %f segundos\n", n, tempo_bubble);
        free(arr_bubble);

        // Teste Selection Sort
        int* arr_selection = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr_selection[i] = arr[i];
        inicio = clock();
        selection_sort(arr_selection, n);
        fim = clock();
        double tempo_selection = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Selection Sort (n=%d): %f segundos\n", n, tempo_selection);
        free(arr_selection);

        // Teste Insertion Sort
        int* arr_insertion = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr_insertion[i] = arr[i];
        inicio = clock();
        insertion_sort(arr_insertion, n);
        fim = clock();
        double tempo_insertion = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Insertion Sort (n=%d): %f segundos\n", n, tempo_insertion);
        free(arr_insertion);

        // Teste Merge Sort
        int* arr_merge = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr_merge[i] = arr[i];
        inicio = clock();
        merge_sort(arr_merge, 0, n - 1);
        fim = clock();
        double tempo_merge = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Merge Sort (n=%d): %f segundos\n", n, tempo_merge);
        free(arr_merge);

        // Teste Quick Sort
        int* arr_quick = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr_quick[i] = arr[i];
        inicio = clock();
        quick_sort(arr_quick, 0, n - 1);
        fim = clock();
        double tempo_quick = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Quick Sort (n=%d): %f segundos\n", n, tempo_quick);
        free(arr_quick);

        // Teste Heap Sort
        int* arr_heap = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr_heap[i] = arr[i];
        inicio = clock();
        heap_sort(arr_heap, n);
        fim = clock();
        double tempo_heap = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Heap Sort (n=%d): %f segundos\n", n, tempo_heap);
        free(arr_heap);

        free(arr);
        printf("\n");
    }

    return 0;
}

