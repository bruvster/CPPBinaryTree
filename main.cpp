/*
    Author : Mia Murray
    Date   : March 14th 2020
    Title  : CSCI 161 - Assignment 8

    A Program that can build a binary tree that stores
    any simple element with the utilization of templates. 
    The program stores the elements of the tree in a deque
    when one of the order functions is called and prints them
    in that specified order. I have added a print out representation
    of the binary tree so that we can visualize the different orders
    and confirm that they work.
*/
#include "BinaryTree.hpp"
#include "Deque.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
    //building up our binary tree
    BinaryTree tree("and");
    BinaryTree mia("you");
    BinaryTree both("this", tree, mia);
    BinaryTree t("find");
    BinaryTree m("order");
    BinaryTree c("will", t, m);
    BinaryTree b("follow", both, c);

    //printing the different orders
    cout << "*PRE-ORDER*";
    Deque<string> pre;
    b.pre_order(pre);
    cout << "\n";
    cout << "*IN-ORDER*";
    Deque<string> in;
    b.in_order(in);
    cout << "\n";
    cout << "*POST-ORDER*";
    Deque<string> post;
    b.post_order(post);
    cout << "\n";
 
    //testing size
    cout << "GENERATED BINARY TREE OF SIZE: " << b.size() << endl;

    //creating another deque for the visual tree
    Deque<string> image;
    b.pre_order(image);
    cout << endl;




    //printing the visual tree and popping one element of the deque 
    //each time so that we can access front   
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                 [" << pre.front() << "]                 " << endl;
    cout << "                                 |      |                                " << endl;
    image.dequeue(); //getting to the right element in image
    image.dequeue();
    image.dequeue();
    image.dequeue();
    cout << "                                 |      [" << image.front() <<"]         " << endl;
    pre.dequeue();
    cout << "                            [" << pre.front() << "]      |    |          " << endl;
    image.dequeue();
    cout << "                            |    | [" << image.front() << "]    |        " << endl;
    pre.dequeue();
    image.dequeue();
    cout << "                            |    |           [" << image.front() << "]   " << endl;
    cout << "                        [" << pre.front() << "]    |                     " << endl;
    pre.dequeue();
    cout << "                                 [" << pre.front() << "]                 " << endl;
    cout << "                                                                         " << endl;
    cout << "                                                                         " << endl;

    //testing the height
    int h =b.height();
    cout << "The height of our binary tree is: " << h << endl;
    return 0;
}