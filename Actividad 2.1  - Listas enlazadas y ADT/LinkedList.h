#include <iostream>
using namespace std; 

#pragma once
template<class T>
class Node{
    public:
        T data; 
        Node<T> *next; 
}; 

template<class T>
class LinkedList{
    private: 
        Node<T> *first; 
    public: 
        LinkedList<T>(){first = NULL; }; 
        
        LinkedList<T>(T A[], int n){
            Node<T> *last, *t; 
            int i = 0; 
            first = new Node<T>; 
            first->data = A[0]; 
            first->next=NULL; 
            last = first; 

            for(i = 1; i < n; i++){
                t=new Node<T>; 
                t->data=A[i]; 
                t->next=NULL; 
                last->next=t; 
                last = t; 
            }
        }; 

        ~LinkedList<T>(){
            Node<T> *p = first; 
            while(first){
                first=first->next; 
                delete p; 
                p = first; 
            }
        }; 

        void Display(){
            Node<T> *p = first; 
            while(p){                       
                cout << p->data<< " -> "; 
                p=p->next;  
            }
            cout << endl; 
        }; 
        
        int Length(){
            Node<T> *p = first; 
            int len = 0; 
            while(p){               
                len++; 
                p=p->next; 
            }
            return len; 
        };

        int Count(T val){
            Node<T> *p = first; 
            int counter=0; 
            while(p){
                if(p->data == val){
                    counter++; 
                }
                p=p->next; 
            }
            return counter; 
        };

        Node<T>* NewNode(T val){
            Node<T>* newNode = new Node<T>; 
            newNode->data = val; 
            newNode->next = NULL; 
            return newNode; 
        }; 

        void SortedInsert(Node<T>* newNode){
            Node<T> *p = first; 
            if(p == NULL or p->data >= newNode->data){
                newNode->next = p; 
                p=newNode; 
                return; 
            }

            while(p->next != NULL and p->next->data < newNode->data){
                p=p->next; 
            }
            newNode->next = p->next; 
            p->next = newNode; 

        }

        void RemoveDuplicate(){
            Node<T>*p = first; 
            Node<T> *q = p->next; 
            while(q!=NULL){
                if(p->data != q->data){
                p=q; 
                q=q->next; 
                }
                else{
                    p->next=q->next; 
                    delete q; 
                    q=p->next; 
                }
    
            }
        }; 

        void Reverse(){
            Node<T>*p = first; 
            int *A; 
            int i =0;  
            A = new int[Length()]; 
            Node<T> *q=p; 

            while(q!= NULL){
                A[i]=q->data; 
                q=q->next; 
                i++; 
            }
            q=p; 
            i--; 
            while(q!=NULL){
                q->data=A[i]; 
                q=q->next; 
                i--; 
            }

        }; 

       

};



