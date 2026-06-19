// Binary Search Tree Iterator
// Bruteforce we can use inorder traversal

// Optimal
class BSTIterator
{
    stack<Node *> myStack;

public:
    BSTIterator(Node *root)
    {
        pushAll(root);
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

    int next()
    {
        Node *temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->data;
    }

private:
    void pushAll(Node *node)
    {
        for (; node != nullptr; myStack.push(node), node = node->left)
            ;
    }
};

class BSTIteratorReverse
{
    stack<Node *> myStack;

public:
    BSTIteratorReverse(Node *root)
    {
        pushAll(root); // push entire right spine
    }

    bool hasPrev()
    {
        return !myStack.empty();
    }

    int prev()
    {
        Node *temp = myStack.top();
        myStack.pop();
        pushAll(temp->left); // process left subtree
        return temp->data;
    }

private:
    void pushAll(Node *node)
    {
        for (; node != nullptr; myStack.push(node), node = node->right)
            ;
    }
};
