#include <stdio.h>

void print_n(int i, int N) {
    if(i > N)
        return;
    printf("%d\n", i);
    print_n(i + 1, N);
}

int main(int argc, char *argv[]) {
    int N = 5;
    
    print_n(1, N);
    return 0;
}
