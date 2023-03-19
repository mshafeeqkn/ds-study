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

void subset_sum_power_set(int *arr, int n, std::vector<int> &res) {
    int sum;

    for(int i = 0; i < (1<<n); i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            if((i & (1 << j)) != 0) {
                sum += arr[j];
            }
        }
        res.push_back(sum);
    }
}

void subset_sum_rec(int *arr, int n, int index, int sum, std::vector<int> &ds) {
    if(index == n) {
        ds.push_back(sum);
        return;
    }

    subset_sum_rec(arr, n, index+1, sum+arr[index], ds);
    subset_sum_rec(arr, n, index+1, sum, ds);
}

void subset_sum_rec_2(int *arr, int n, int index, std::vector<int> &ds) {
    print_list(ds);
    for(int i = index; i < n; i++) {
        if(i > index && arr[i] == arr[i-1]) {
            continue;
        }
        ds.push_back(arr[i]);
        subset_sum_rec_2(arr, n, i+1, ds);
        ds.pop_back();
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> res;
    std::vector<int>::iterator itr;

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    bool recursion = false;
    bool subset_sum_1 = false;
    bool subset_sum_2 = true;

    if(subset_sum_1) {
        if(recursion) {
            std::cout << "Subset sum using power set" << std::endl;
            subset_sum_power_set(arr, n, res);
        } else {
            std::cout << "Subset sum using recursion" << std::endl;
            subset_sum_rec(arr, n, 0, 0, res);
        }
        sort(res.begin(), res.end());
        for(itr = res.begin(); itr != res.end(); itr++) {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;
    }

    if(subset_sum_2) {
        std::cout << "Subset 2 using recursion" << std::endl;
        subset_sum_rec_2(arr, n, 0, res);
    }

    return 0;
}
