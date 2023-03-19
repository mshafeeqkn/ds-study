#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unistd.h>

void print_list(std::vector<int> &ds) {
    std::vector<int>::iterator itr;

    for(itr = ds.begin(); itr != ds.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

void print_arr(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *arr, int from, int to) {
    if(from == to) return;
    int tmp = arr[to];
    arr[to] = arr[from];
    arr[from] = tmp;
}

void permutation_with_swap(int *arr, int n, int index) {
    if(index == n) {
        print_arr(arr, n);
        return;
    }

    for(int i = index; i < n; i++) {
        swap(arr, index, i);
        permutation_with_swap(arr, n, index+1);
        swap(arr, index, i);
    }
}

void permutation_with_extra_hash(int *arr, int n, std::vector<int> &ds, bool *use) {
    int i;
    for(i = 0; i < n && use[i] == true; i++);
    if(i == n) {
        print_list(ds);
    }

    for(i = 0; i < n; i++) {
        if(!use[i]) {
            use[i] = true;
            ds.push_back(arr[i]);
            permutation_with_extra_hash(arr, n, ds, use);
            use[i] = false;
            ds.pop_back();
        }
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {1, 2, 3};
    int n = 3;
    bool use[n] = {0};
    std::vector<int> ds;

    // permutation_with_extra_hash(arr, n, ds, use);
    permutation_with_swap(arr, n, 0);
}
