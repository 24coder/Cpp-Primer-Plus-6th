
#include <iostream>

int main() {
    for (int i = 0; i < 3; ++i) {
        std::cout << "Outer loop iteration: " << i << std::endl;
        for (int j = 0; j < 3; ++j) {
            if (j == 1) {
                std::cout << "Inner loop iteration: " << j << " - continue" << std::endl;
                continue; // 跳出内层循环的当前迭代
            }
            std::cout << "Inner loop iteration: " << j << std::endl;
        }
    }
    return 0;
}