// Two Sum In BST
// Bruteforce we can inorder vector in which we can use 2 pointer approach
// which takes O(n + n) TC and O(n) SC.

// Optimal
class BSTIteratorCombo
{
    stack<Node *> myStack;
    bool reverse = true;

public:
    BSTIteratorCombo(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        Node *temp = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->data;
    }

private:
    void pushAll(Node *node)
    {
        for (; node != nullptr;)
        {
            myStack.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};

bool findTarget(Node *root, int k)
{
    if (!root)
        return false;
    BSTIteratorCombo l(root, false);
    BSTIteratorCombo r(root, true);

    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }
    return false;
}
