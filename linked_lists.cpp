//
//  main.cpp
//  Linked Lists
//
//  Created by Maksymilian Podraza on 9/22/18.
//  Copyright © 2018 Maksymilian Podraza. All rights reserved.
//
#define LOG(x) std::cout << x << std::endl

#include <iostream>
struct node{
    int data;
    node *next;
};

// creates a newNode
node * newNode(int data){
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// inserts a node at the end recursively
node * insertAtEnd(node * node, int data){
    if(node == NULL){
        return newNode(data);
    }
    else
        node->next = insertAtEnd(node->next, data);
    return node;
}

// traverses the linked list and prints the data in each node
void traversal(node * node){
    if(node == NULL){
        return;
    }
    std::cout << node->data;
    
    traversal(node->next);
}

// searches the list for an input and returns the index
int searchList(node * input, int data){
    node * temp = input;
    int i = 0;
    while(temp != NULL){
        if(temp->data == data){
            return i;
        }
        else{
            temp = temp->next;
        }
        i++;
    }
    return 404;
}

// deletes a node with specified data
bool deleteNode(node * input, int data){
    node * temp = input;
    int index = searchList(input, data);
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }
    if(input->next == NULL){
        input = NULL;
    }
    node * temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
    if(searchList(temp, data) != index){
        return true;
    }
    else
        return false;
}

int main() {
    node * head = NULL;
    
    for(int i = 0; i < 20; i++){
        head = insertAtEnd(head, i);
    }
    
    LOG(searchList(head, 4));
    LOG(deleteNode(head, 2));
    LOG(searchList(head, 3));
    LOG(deleteNode(head,19));
    deleteNode(head, 13);
    
    head = head->next;
    head = head->next;
    
    
    
    traversal(head);
    
    return 0;
}
