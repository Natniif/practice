#include <iostream>

template <typename T>

T doubleit(T num) {
  return 2 * num;
}

int main() {
    int n1 = 1;
    float n2 = 2.0;

    int ans = doubleit(n1);
    
    std::cout << "Double of " << n1 << " is: " << ans << std::endl;

    return 0;
}
