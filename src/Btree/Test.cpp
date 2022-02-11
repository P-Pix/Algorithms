#include "../../include/Btree.hpp"

int main(int argc, char **argv) {
    Btree<int> btree;
    int t[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    btree.setTree(t, 15);
    if (btree.exists(6)) {
        std::cout << "6 exists" << std::endl;
    } else {
        std::cout << "6 does not exist" << std::endl;
    }
    btree.print();
    //btree.sortGrowing();
    if (btree.isSort()) {
        std::cout << "Tree is sorted" << std::endl;
    } else {
        std::cout << "Tree is not sorted" << std::endl;
    }
}