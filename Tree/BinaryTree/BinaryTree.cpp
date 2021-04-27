#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
} Node;

Node *CreateNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    return temp;
}

Node *Delete(Node *temp)
{
    delete temp;
    return NULL;
}

void InOrderTraversal(Node *head)
{
    if (head != NULL)
    {
        InOrderTraversal(head->left);
        cout << head->data << "\t";
        InOrderTraversal(head->right);
    }
}

void PreOrderTraversal(Node *head)
{
    if (head != NULL)
    {
        cout << head->data << "\t";
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
        cout << head->data << "\t";
    }
}

void LevelOrder(Node *head)
{
    if (head != NULL)
    {
        cout << "\nLevelOrder :\t";
        queue<Node *> Q;
        Node *temp;
        Q.push(head);
        while (!Q.empty())
        {
            temp = Q.front();
            cout << temp->data << "\t";
            if (temp->left != NULL)
                Q.push(temp->left);
            if (temp->right != NULL)
                Q.push(temp->right);
            Q.pop();
        }
    }
}

void ReverseLevelOrder(Node *head)
{
    if (head != NULL)
    {
        cout << "\nReverseLevelOrder :\t";
        deque<Node *> Qt;
        int i = 0;
        Node *temp;
        Qt.push_back(head);
        while (i < Qt.size())
        {
            temp = Qt.at(i);
            if (temp->right != NULL)
                Qt.push_back(temp->right);
            if (temp->left != NULL)
                Qt.push_back(temp->left);
            i++;
        }
        while (!Qt.empty())
        {
            temp = Qt.back();
            cout << temp->data << "\t";
            Qt.pop_back();
        }
    }
}

bool Search(Node *head, int search_item)
{
    if (head != NULL)
    {
        if (head->data == search_item)
            return true;
        return Search(head->left, search_item) || Search(head->right, search_item) ? true : false;
    }
    return false;
}

int Height(Node *head)
{
    if (head != NULL)
    {
        int left = Height(head->left);
        int right = Height(head->right);
        return left > right ? left + 1 : right + 1;
    }
    else
        return 0;
}

int Diameter(Node *head, int *max)
{
    if (head != NULL)
    {
        int left = Height(head->left);
        int right = Height(head->right);
        *max = *max > left + right + 1 ? *max : left + right + 1;
        return left > right ? left + 1 : right + 1;
    }
    else
        return 0;
}

int main()
{
    Node *head = CreateNode(5);
    head->left = CreateNode(2);
    head->right = CreateNode(1);
    head->left->left = CreateNode(4);
    head->left->right = CreateNode(7);
    head->right->left = CreateNode(8);
    head->right->right = CreateNode(9);
    head->right->right->right = CreateNode(10);
    head->left->right->right = CreateNode(19);

    // if (head != NULL)
    //     cout << head->data;
    // head = Delete(head);
    // if (head != NULL)
    //     cout << head->data;
    cout << "\nInOrderTraversal :\t";
    InOrderTraversal(head);
    cout << "\nPreOrderTraversal :\t";
    PreOrderTraversal(head);
    cout << "\nPostOrderTraversal :\t";
    PostOrderTraversal(head);
    LevelOrder(head);
    ReverseLevelOrder(head);
    Search(head, 17) ? cout << "\nFound" : cout << "\nNot Found";
    cout << "\nHeight of Tree is :\t" << Height(head);
    int *Dia = new int(0);
    Diameter(head, Dia);
    cout << "\nDiameter of Tree :\t" << *Dia;
    return 0;
}

//         5
//     2       1
// 4      7   8     9
//         9          10