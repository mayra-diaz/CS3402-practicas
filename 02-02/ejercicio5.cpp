#include <iostream>

#define assert(x,y) (x<y)

int main(int argc, char *argv[]){
        int x, y;
        std::cin >> x >> y;
#ifndef NDEBUG
        if (assert(x, y))
                std::cout << x << " < " << y << '\n';
#endif
}

