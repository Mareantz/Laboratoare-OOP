#pragma once
#include <iostream>
#define MAX_CHILDREN 10
using namespace std;
template <typename T>
class TreeNode
{
public:
    T value;
    TreeNode<T>** children;
    int childrenCount;
    TreeNode(const T& value)
    {
        this->value = value;
        children = new TreeNode<T>*[MAX_CHILDREN];
        for (int i = 0; i < MAX_CHILDREN; i++)
            children[i] = nullptr;
        this->childrenCount = 0;
    }

    void add_node(TreeNode <T>* node, const T& value)
    {
        TreeNode <T>* new_node = new TreeNode<T>(value);
        if (node == nullptr)
        {
            this->children[0] = new_node;
            this->childrenCount = 1;
        }
        else
            if (node->childrenCount < MAX_CHILDREN)
            {
                this->children[this->childrenCount] = new_node;
                this->childrenCount++;
            }
            else
                cout << "Error: Cannot add any more children";
    }

    TreeNode<T>* get_node(TreeNode <T>* node)
    {
        if (node == nullptr)
            return this;
        for (int i = 0; i < node->childrenCount; i++)
            if (this->children[i] == node)
                return this->children[i];
    }

    void delete_node(TreeNode <T>* node)
    {
        if (node == nullptr)
            return;
        for (int i = 0; i < node->childrenCount; i++)
            node->delete_node(node->children[i]);
        if (node->childrenCount == 1)
            childrenCount--;
        for (int i = 0; i < node->childrenCount - 1; i++)
        {
            if (this->children[i] == node)
                for (int j = i + 1; j < node->childrenCount; j++)
                    this->children[j - 1] = this->children[j];
            this->childrenCount--;
            break;
        }
        delete node;
    }

    T GetValue()
    {
        return this->value;
    }

    TreeNode<T>* find_node(const T& param, bool (*compare)(const T&, const T&))
    {
        if (compare(this->GetValue(), param))
            return this;
        for (int i = 0; i < this->childrenCount; i++)
        {
            TreeNode<T>* child = this->children[i];
            TreeNode<T>* found = child->find_node(param, compare);
            if (found != nullptr)
                return found;
        }
        return nullptr;
    }

    void insert_node(int index, const T& value)
    {
        if (this == nullptr)
        {
            cout << "Error: parent node cannot be null.\n";
            return;
        }
        if (index < 0 || index > this->childrenCount)
        {
            cout << "Error: index out of range.\n";
            return;
        }
        TreeNode<T>* new_node = new TreeNode<T>(value);
        if (this->childrenCount < MAX_CHILDREN)
        {
            for (int i = this->childrenCount - 1; i >= index; i--)
                this->children[i + 1] = this->children[i];
            this->children[index] = new_node;
            this->childrenCount++;
        }
        else
        {
            cout << "Error: cannot add more children.\n";
            return;
        }
        delete new_node;
    }

    void sort(bool(*compare)(T, T) = nullptr)
    {
        if (this == nullptr)
            return;
        if (compare == nullptr)
        {
            for (int i = 0; i < this->childrenCount - 1; i++)
                for (int j = i + 1; j < this->childrenCount; j++)
                    if (this->children[i]->GetValue() > this->children[j]->GetValue())
                        swap(this->children[i], this->children[j]);
        }
        else
        {
            for (int i = 0; i < this->childrenCount - 1; i++)
                for (int j = i + 1; j < this->childrenCount; j++)
                    if (compare(this->children[i]->GetValue(), this->children[j]->GetValue()))
                        swap(this->children[i], this->children[j]);
        }
    }

    int count()
    {
        if (this == nullptr)
            return 0;
        int counter = this->childrenCount;
        for (int i = 0; i < this->childrenCount; i++) {
            counter += this->children[i]->count();
        }
        return counter;
    }

    void print()
    {
        for (int i = 0; i < this->childrenCount; i++)
            cout << this->children[i]->GetValue() << " ";

        cout << endl;
    }
};

bool compare_int(const int& a, const int& b)
{
    return a == b;
}

template <typename T>
void swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}