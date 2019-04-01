//
// Created by HWY on 2019/3/30.
//
#include "Storage.h"
void MyGraph::insert_node(Node* NewNode, std::string name)
{
    NodeInfoVec.push_back({NewNode, 0});
    StrToIntMap.insert(std::pair<std::string, int>(name, 0));
}

void MyGraph::empty_placeholder_rev()
{
    int VecSize = PlaceholderRev.size();
    PlaceholderRev.resize(VecSize, 0);
}
void MyGraph::mark_placeholder_rev(int rank)
{
    PlaceholderRev[rank] = 1;
}