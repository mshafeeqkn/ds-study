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

void combination_sum(int *arr, int size, int index, std::vector<int> &ds, int target) {
    if(target == 0) {
        print_list(ds);
        return;
    }

    if(target < 0 || index == size) {
        return;
    }

    ds.push_back(arr[index]);
    combination_sum(arr, size, index, ds, target - arr[index]);
    ds.pop_back();
    combination_sum(arr, size, index+1, ds, target);
}


int main(int argc, char *argv[]) {
    std::vector<int> ds;
    int arr[] = {3, 2, 5};
    int sum = 10;

    combination_sum(arr, 3, 0, ds, sum);
    return 0;
}

#if 0


                                                                  f(i=0, ds={}, trgt=3)

                                         f(i=0, ds={1}, trgt=2)                      f(i=1, ds={}, target, 3)

               f(i=0, ds={1,1}, trgt=1)                     f(i=1, ds={1}, trgt=2)
                                            
f(i=0, ds={1,1,1}, trgt=0)  f(i=1, ds={1,1}, trgt=1)    f(i=1, ds={1, 3}x   f(i=2, ds={1}, trgt=2)
==========================      /           \
                       f(i=1, ds={1,1,3}x    \                          f(i=2, ds={1, 2} trgt=0
                                        f(i=2, ds={1,1}, trgt=1)        =======================
                                        /                      \
                                f(i=2, ds={1,1,2}x      f(i=3, ds={1,1}, trgt=1)x
#endif
