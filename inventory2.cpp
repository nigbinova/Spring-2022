//  cla15X by Naomi Igbinovia, CSCI 2170-004, Due: 04/05/2022
//  Program ID: slist.cpp / stores, displays, searches, inserts, deletes, and releases
//  items in a linked list
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program reads in data from a file into a linked list, displays the
//  list content, and allows the user to delete items from the list.

#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef string ItemType;

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType {
   ItemType data;
   NodePtr next;
};


// Declare the function "Insert" here
void Insert(NodePtr & head, ItemType item);
// Declare the function "Delete" here
void Delete (NodePtr & head, ItemType item);
// Declare the function "ReleaseList" here
void ReleaseList(NodePtr & head);

bool IsPresent(NodePtr head, ItemType data);
void DisplayList(NodePtr head);
void BuildList(ifstream & myIn, NodePtr & head);

int main()
{
    ifstream myIn;
    ItemType item;
    NodePtr  head=NULL;  // the pointer points to the beginning of the list

    myIn.open("grocery.dat");
    assert(myIn);

    BuildList(myIn, head);
    DisplayList(head);

    cout << "Enter an item to be deleted from the list:";
    cin >> item;

    // call the function "IsPresent" to determine if the item is in the list
    // If the item is in the list,
    //              call the function "Delete" to delete the item from the list
    //              call the function "DisplayList" to display the list after the deletion
    // else
    //     display a message "The item is not found in the list
    if (IsPresent(head, item))
    {
         Delete(head, item);
         cout << item << " deleted from the list." << endl;
         DisplayList(head);
    }
    else
         cout << "Item is not in the list." << endl;

    myIn.close();

    ReleaseList(head);

    return 0;
}

// Define the function "Insert" here. This function inserts a value into a list such that
// the list is always in sorted order, i.e., sorted in alphabetically ascending order

void Insert(NodePtr & head, ItemType item)
{
    NodePtr cur, prev;
    NodePtr newPtr;

    //create a node to insert

    newPtr = new NodeType;
    newPtr->data = item;
    newPtr->next = NULL;

    //insert at the start
    if ((head == NULL) || (head != NULL && item < head->data))
    {
        newPtr->next = head;
        head = newPtr;
    }

    //insert at the middle/end of list
    else
    {
        prev = NULL;
        cur = head;

        //the right place to insert is searched for
        while (cur != NULL && cur->data < item)
        {
            prev = cur;
            cur = cur->next;
        }

        newPtr->next = cur;
        prev->next = newPtr;
    }
}

// Define the function "Delete" here. This function deletes a value from  the list
// If the list is empty, show an appropriate message indicating that fact;
// The item to be deleted may be the first item in the list,
// Or it may occur in the middle or at the end of the list.
// If the item is not found in the list, show an appropriate message indicating that;

void Delete(NodePtr & head, ItemType item)
{
    NodePtr cur, prev;

//check for an empty list
    if (head == NULL)
    {
        cout << "The list is empty, deletion cannot be done." << endl;
    }
// if the item is at the start of the list
    else if (head != NULL && head->data == item)
    {
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
    }
//if the item is in the middle or at the end of the list
    else if (head != NULL)
    {
        cur = prev = head;
        while (cur != NULL)
        {
            //if found
            if (cur->data == item)
            {
                prev->next = cur->next;

                cur->next = NULL;
                delete cur;
                break;
            }
            //if not, continue moving through the list
            prev = cur;
            cur = cur->next;
        }
    }
}



// Define the function "ReleaseList" here. This function releases the memory of all the nodes in the list

void ReleaseList(NodePtr & head)
{
    NodePtr cur;

    while (head != NULL)
    {
        cur = head;
        head = head->next;

        //release a node
        cur->next = NULL;
        delete cur;
    }
}

// function "BuildList" reads the values one by one from the datafile and calls
// the "Insert" function to insert each value into the linked list
void BuildList(ifstream & myIn, NodePtr & head)
{
    string item;

    while (myIn >> item)
    {
         Insert(head, item);
    }
}

// function "DisplayList" prints all the items in the list one by one
void DisplayList(NodePtr head)
{
    NodePtr cur;

    cur = head;
    cout << "The list of items are: " << endl;
    while (cur != NULL)
    {
        cout << cur->data << endl;
        cur = cur->next;
    }
    cout << '\n';
}

// Function "IsPresent" returns true if the item to search for is
// in the list, otherwise it returns false
bool IsPresent(NodePtr head, ItemType item)
{
    NodePtr cur=head;
    while (cur != NULL)
    {
       if (cur->data == item)
       {
           return true;
       }
       cur = cur->next;
    }
    return false;
}
              