void insertion_sort(int *a, int n) {
    int j, cur;
    for(int i = 1; i < n; i++) {
        cur = a[i];
        j = i -1;
        while(j >= 0 && a[j] > cur) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
    }
}

