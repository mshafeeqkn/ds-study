#include <iostream>
#include <vector>
#include <unistd.h>

void print_list(std::vector<int> &ds) {
    std::vector<int>::iterator itr;

    for(itr = ds.begin(); itr != ds.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}


void comb_sum(int *arr, int size, int index, std::vector<int> &ds, int target) {
    if(target == 0) {
        print_list(ds);
        return;
    }

    for(int i = index; i < size; i++) {
        if(i > index && (arr[i] == arr[i-1])) continue; 

        if(target < arr[i]) break;

        ds.push_back(arr[i]);
        comb_sum(arr, size, i + 1, ds, target - arr[i]);
        ds.pop_back();
    }
}


int main(int argc, char *argv[]) {
    int arr[] = {1, 1, 2, 2, 2, 3};
    int target = 5;
    std::vector<int> ds;
    comb_sum(arr, 6, 0, ds, target);

    return 0;
}

#if 0
                                     f(0, {}, 5)

                      f(1, {1}, 4)   f(3, {2}, 3)      f(6, {3}, 2)
#endif
