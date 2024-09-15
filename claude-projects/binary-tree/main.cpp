#include <iostream>

class TreeNode {
    public:
        int value;
        TreeNode* LeftNode; 
        TreeNode* RightNode;

        TreeNode() {};
        TreeNode(int val) {
            value = val;
        };
        
        void insert() {};
        TreeNode* search() {};
        void remove() {};
};


using namespace std;

/*
Your task is to implement a binary search tree in C++. Here are the basic requirements:
Create a binary search tree class
Implement insertion of new nodes
Implement searching for a value
Implement deletion of nodes
Start with whatever approach you think is best. If you need any clarification on the requirements or get stuck on a specific part, feel free to ask for hints or guidance. I'll be here to provide support without giving away solutions.
Good luck, and enjoy the challenge!

will probably write some tests perhaps to do this...
*/
int main()
{
    TreeNode t = TreeNode(5);
    TreeNode f = TreeNode();
    cout << t.value << endl;

    return 0;
}