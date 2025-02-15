#include <iostream>
#include <map>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildtree()
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    cout << "Enter the data for the left part of " << data << " node" << endl;
    root->left = buildtree();

    cout << "Enter the data for the right part of " << data << " node" << endl;
    root->right = buildtree();

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // C
            cout << temp->data << " ";
            // D
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void printTopView(Node *root)
{
    if (root == NULL)
        return;

    /// create a map for storing HD -> TopNode ->data
    map<int, int> topNode;

    // Level Order
    // we will store a pair consisting of Node and Horizontal Distance
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal distance aaya h , check if answer for that hd already exists
        // or not

        if (topNode.find(hd) == topNode.end())
        {
            // crete entry
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    // ab aapka answer store hua hoga aapke map me
    cout << "Printing the answer: " << endl;
    for (auto i : topNode)
    {
        cout << i.first << " -> " << i.second << endl;
    }
}

int main()
{

    Node *root = buildtree();
    printTopView(root);
}