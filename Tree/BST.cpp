#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left = NULL, *right = NULL;
} Node;

Node *CreateNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    return temp;
}

int Delete(Node *head)
{
    if (head != NULL)
    {
        int x = head->data;
        delete head;
        return x;
    }
    return -1;
}

void Insertion(Node *head, int data)
{
    if (head != NULL)
        if (head->data > data)
            Insertion(head->left, data);
        else
            Insertion(head->right, data);
    else
        head = CreateNode(data);
}

void LevelOrder(Node *head)
{
    if (head != NULL)
    {
        cout << "\nLevelOrder of BST:\t";
        queue<Node *> Qt;
        Qt.push(head);
        Node *temp;
        while (!Qt.empty())
        {
            temp = Qt.front();
            cout << temp->data << " ";
            if (temp->left != NULL)
                Qt.push(temp->left);
            if (temp->right != NULL)
                Qt.push(temp->right);
            Qt.pop();
        }
        cout << endl;
    }
    else
        cout << "\nNULL TREE\n";
}

void InOrderTraversal(Node *head)
{
    if (head != NULL)
    {
        InOrderTraversal(head->left);
        cout << head->data << " ";
        InOrderTraversal(head->right);
    }
}

void PreOrderTraversal(Node *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        PreOrderTraversal(head->left);
        PreOrderTraversal(head->right);
    }
}

void PostOrderTraversal(Node *head)
{
    if (head != NULL)
    {
        PostOrderTraversal(head->left);
        PostOrderTraversal(head->right);
        cout << head->data << " ";
    }
}

Node *Search(Node *head, int data)
{
    if (head != NULL)
    {
        if (head->data == data)
            return head;
        Node *left = Search(head->left, data), *right = Search(head->right, data);
        if (left != NULL)
            return left;
        else
            return right;
    }
    return NULL;
}

bool IsBST(Node *head)
{
    if (head != NULL)
    {
        bool left = false, right = false;
        if (head->left != NULL)
            left = head->data >= head->left->data && IsBST(head->left);
        else
            left = true;
        if (head->right != NULL)
            right = head->data <= head->right->data && IsBST(head->right);
        else
            right = true;
        return left && right;
    }
    return false;
}

void InOrderTraversal_(Node *head, Node *node, bool found)
{
    if (head != NULL)
    {
        InOrderTraversal_(head->left, node, found);
        if (head->data == node->data)
            found = true;
        if (!found)
            node->left = head;

        if (found && node->right == NULL)
            node->right = head;
        InOrderTraversal_(head->right, node, found);
    }
}

Node *InorderNeighbours(Node *head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    InOrderTraversal_(head, temp, false);
    return temp;
}

void Delete(Node *head, int data)
{
    if (head != NULL)
    {
        Node *dlt = Search(head, data);
        Node *temp = InorderNeighbours(head, data);
        if (temp->left != NULL)
        {
            int x = temp->left->data;
            Delete(head, x);
            dlt->data = x;
        }
        else if (temp->right != NULL)
        {
            int x = temp->right->data;
            Delete(head, x);
            dlt->data = x;
        }
        else
        {
            delete dlt;
        }
    }
}

