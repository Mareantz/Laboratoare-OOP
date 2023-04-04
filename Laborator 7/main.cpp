#include <iostream>
#include "Template.h"
using namespace std;
float operator"" _Farenheit(unsigned long long x)//for some reason long double doesn't work as a parameter
{
    return (x - 32) / 1.8;
}
float operator"" _Kelvin(unsigned long long x)
{
    return x - 273.15;
}
int main()
{
    float a = 300_Kelvin;
    float b = 120_Farenheit;
    cout << a << " " << b << endl;

    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* nod1 = new TreeNode<int>(2);
    TreeNode<int>* nod2 = new TreeNode<int>(3);
    TreeNode<int>* nod3 = new TreeNode<int>(4);
    TreeNode<int>* nod4 = new TreeNode<int>(5);

    root->add_node(nod4, 5);
    root->add_node(nod1, 2);
    root->add_node(nod2, 3);
    nod1->add_node(nod3, 4);

    cout << "Root before sorting: ";
    root->print();
    root->sort();
    cout << "Root after sorting: ";
    root->print();
    nod1->print();

    cout << "Root has " << root->count() << " children" << endl;
    cout << "Nod1 has " << nod1->count() << " children" << endl;
    cout << "Root address: " << root->get_node(nullptr) << endl;
    cout << "Nod1 address: " << root->get_node(nod1) << endl;
    root->delete_node(nod1);
    cout << "Root has " << root->count() << " children after deleting nod1" << endl;
    root->print();
    root->insert_node(1, 9);
    root->print();
    TreeNode<int>* found_node = root->find_node(3, &compare_int);
}