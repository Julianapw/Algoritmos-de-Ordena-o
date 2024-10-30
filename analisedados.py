
import time
import matplotlib.pyplot as plt
import random

# Funções de ordenação para comparar
def bubble_sort(arr):  #bubble:  definidos para ilustrar diferentes complexidades de tempo. 
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def merge_sort(arr):  #merge:  definidos para ilustrar diferentes complexidades de tempo. 
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1


def measure_time(algorithm, data):  #Mede o tempo de execução de cada algoritmo usando uma cópia da lista para garantir que ambos tenham a mesma entrada.
    start_time = time.time()
    algorithm(data.copy())  # Usa uma cópia para cada algoritmo
    return time.time() - start_time

# Tamanhos de entrada e preparação dos dados
sizes = [100, 500, 1000, 5000, 10000] #Percorre tamanhos de entrada (sizes) e armazena o tempo de execução de cada algoritmo.
bubble_times = []
merge_times = []

# Executa a medição de tempo para cada tamanho
for size in sizes:
    data = random.sample(range(size * 10), size)
    bubble_times.append(measure_time(bubble_sort, data))
    merge_times.append(measure_time(merge_sort, data))

# Visualização dos dados
plt.plot(sizes, bubble_times, label="Bubble Sort", marker='o') #plt.plot cria gráficos de linha para cada algoritmo, exibindo o tempo de execução em relação ao tamanho da entrada.
plt.plot(sizes, merge_times, label="Merge Sort", marker='o')
plt.xlabel("Tamanho da Entrada")
plt.ylabel("Tempo de Execução (s)")
plt.title("Comparação de Algoritmos")
plt.legend()
plt.show()

