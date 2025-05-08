#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool solucaoAnagrama1(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2) return false;
    bool aindaOK = true;
    for (int pos1 = 0; pos1 < len1 && aindaOK; pos1++) {
        bool encontrado = false;
        for (int pos2 = 0; pos2 < len2 && !encontrado; pos2++) {
            if (s1[pos1] == s2[pos2]) {
                encontrado = true;
                s2[pos2] = '\0';
                break;
            }
        }
        if (!encontrado) aindaOK = false;
    }
    return aindaOK;
}

int compare_chars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

bool solucaoAnagrama2(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2) {
        return false;
    }
    qsort(s1, len1, sizeof(char), compare_chars);
    qsort(s2, len2, sizeof(char), compare_chars);
    bool iguais = true;
    for (int pos = 0; pos < len1 && iguais; pos++) {
        if (s1[pos] != s2[pos]) {
            iguais = false;
        }
    }
    return iguais;
}

bool solucaoAnagrama3(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2) {
        return false;
    }
    int c1[26] = {0};
    int c2[26] = {0};
    for (int i = 0; i < len1; i++) {
        char char_lower_s1 = s1[i];
        int pos = char_lower_s1 - 'a';
        c1[pos]++;
    }
    for (int i = 0; i < len2; i++) {
        char char_lower_s2 = s2[i];
        int pos = char_lower_s2 - 'a';
        c2[pos]++;
    }
    bool aindaOK = true;
    for (int j = 0; j < 26 && aindaOK; j++) {
        if (c1[j] != c2[j]) {
            aindaOK = false;
        }
    }
    return aindaOK;
}


void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    char s1[] = "anagrama";
    char s2[] = "nagarama";
    char s3[] = "ananab";
    char s4[] = "banana";

    if (solucaoAnagrama2(s1, s2)) {
        printf("\"%s\" e \"%s\" são anagramas\n", s1, s2);
    } else {
        printf("\"%s\" e \"%s\" não são anagramas\n", s1, s2);
    }

    if (solucaoAnagrama2(s1, s3)) {
        printf("\"%s\" e \"%s\" são anagramas\n", s1, s3);
    } else {
        printf("\"%s\" e \"%s\" não são anagramas\n", s1, s3);
    }

    if (solucaoAnagrama2(s3, s4)) {
        printf("\"%s\" e \"%s\" são anagramas\n", s3, s4);
    } else {
        printf("\"%s\" e \"%s\" não são anagramas\n", s3, s4);
    }

    return 0;
}