#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
#include <string>
using std::string;

class TreeNode {
public:
    //构造函数分配新的left和right和新的计数器，将计数器置为1
    TreeNode() : value(string()), count(0), left(new TreeNode()),
                 right(new TreeNode()), use(new size_t(1)) {};
    //拷贝构造函数将拷贝所有数据成员，并递增计数器
    TreeNode(const TreeNode &t) : value(t.value), count(t.count),
        left(t.left), right(t.right), use(t.use) { ++*use;};
    TreeNode &operator=(const TreeNode &);
    ~TreeNode(){
        if (--*use == 0){   //如果引用计数变为0
            delete left;
            delete right;
            delete use;     //释放计数器内存
        }
    }
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
    size_t *use;    //用来记录有多少个对象共享*left和*right成员
};

TreeNode &
TreeNode::operator=(const TreeNode &t){
    ++*t.use;   //递增右侧运算对象的引用计数
    if (--*use == 0){   //然后递减本对象的引用计数
        delete left;
        delete right;
        delete use;
    }
    left = t.left;
    right = t.right;
    use = t.use;
    return *this;
}

class BinStrTree {
public:
    //构造函数分配新的left和right和新的计数器，将计数器置为1
    BinStrTree() : root(new TreeNode()), use_b(new size_t(1)) {};
    //拷贝构造函数将拷贝所有数据成员，并递增计数器
    BinStrTree(const BinStrTree &b) : root(b.root), use_b(b.use_b)
    {++*use_b;};
    BinStrTree &operator=(const BinStrTree &);
    ~BinStrTree(){
        if (--*use_b == 0){
            delete root;
            delete use_b;
        }
    }
private:
    TreeNode *root;
    size_t *use_b;
};

BinStrTree &
BinStrTree::operator=(const BinStrTree &b){
    ++*b.use_b;     //递增右侧运算对象的引用计数
    if (--*use_b == 0){     //然后递减本对象的引用计数
        delete root;
        delete use_b;
    }
    root = b.root;
    use_b = b.use_b;
    return *this;
}

int main() {}