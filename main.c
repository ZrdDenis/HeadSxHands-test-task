#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int compUp (const int *i, const int *j){
    return *i - *j;
}

int compDwn (const int *i, const int *j)
{
    return *j - *i;
}

void new_size(int n, int arr[], int i){

    int R;
    bool flag = false;
    while (flag == false){
        R = rand();
        flag = true;
        for (int sz = 0; sz < i; sz++){
            if (R == arr[sz]){
                flag = false;
                break;
            }
            else flag = true;
        }
    }
    arr[i] = R;
}


int main() {
    srand(time(NULL));
  
    int N;
    scanf("%d", &N);

    int ex_arr [N]; // Массив с размерами предыдущих массивов
    for (int i = 0; i < N; i++){
        ex_arr[i] = 0;
    }

    // Массив с массивами(см READme)
    int ** array = (int**) malloc (sizeof (int*) * N);

    // Создание запрашиваемых массивов
    for (int i = 0; i < N; ++i) {

        new_size(N, ex_arr, i);

        array[i] = (int *) malloc(sizeof(int) * ex_arr[i]);


        for (int k = 0; k < ex_arr[i]; k++) {
            array[i][k] = rand(); // random
        }

        if (i % 2 == 0)
            qsort(array[i], ex_arr[i], sizeof(int), (int(*) (const void *, const void *)) compDwn);
        else
            qsort(array[i], ex_arr[i], sizeof(int), (int(*) (const void *, const void *)) compUp);

        for (int k = 0; k < ex_arr[i]; k++){
            printf("%d ", array[i][k]);
        }
        printf("\n");
    }
    
    free(ex_arr);
    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);//можно подчистить и внутри, нужно иметь в виду, но он всё равно сам почистит

    return EXIT_SUCCESS;
}
