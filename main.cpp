#include <iostream>
#include <vector>
#include "storage.h"
#include <stdio.h>

int main() {
    freopen("D:\\hwy\\bighomework\\intro\\dataout\\example_all\\data5.input", "r", stdin);
    freopen("D:\\hwy\\bighomework\\intro\\dataout\\example_all\\mydata5.output", "w", stdout);
    MyGraph i_love_compute;
    i_love_compute.create_root();//const or var or placeholder
    i_love_compute.create_tree();//others
    i_love_compute.graph_compute();//compute
    return 0;
}