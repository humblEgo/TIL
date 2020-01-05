### 합병 정렬

합병정렬은 분할정복법을 따른다. 아래 과정대로 흘러간다.
 - 분할: 해결하고자 하는 문제를 작은 크기의 **동일한** 문제들로 분할
   - *배열을 앞부분과 뒷부분으로 나눈다.*
 - 정복: 각각의 작은 문제를 순환적으로 해결.
   - *재귀적으로 각 배열내의 요소를 정렬한다.*
 - 합병: 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함.
   - *나눴던 배열의 요소를 크기비교하며 합친다.*
 
시간 복잡도는 O(nlogn)이다.


C로는 아래와 같이 구현할 수 있다.
```C

void merge(int data[], int p, int q, int r);

//Array[p....r]를 정렬한다.
void mergeSort(int data[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);    // 전반부 정렬
        mergeSort(data, q + 1, r);  // 후반부 정렬
        merge(data, p, q, r);         // 합병
    }
}

void merge(int data[], int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int k = p;    

    int* temp = (int*)malloc(sizeof(int)*MAX_SIZE);

    while (i <= q && j <= r) {
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        }
        else {
            temp[k++] = data[j++];
        }
    }
    while (i <= q) {
        temp[k++] = data[i++];
    }

    while (j <= r) {
        temp[k++] = data[j++];
    }

    for (int i = p; i <= r; i++) {
        data[i] = temp[i];
    }
}

```
