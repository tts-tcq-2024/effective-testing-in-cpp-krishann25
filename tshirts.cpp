
#include <iostream>
#include <cassert>

char size(int cms) {
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S';
    } else if (cms >= 38 && cms <= 42) {
        sizeName = 'M';
    } else if (cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testSizeFunction() {
    assert(size(37) == 'S');
    assert(size(38) == 'M');
    assert(size(40) == 'M');
    assert(size(42) == 'M');
    assert(size(43) == 'L');
    
    assert(size(38) == 'M');
    assert(size(42) == 'M');

    assert(size(-1) == '\0');
    assert(size(0) == 'S');
}

int main() {
    testSizeFunction();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
