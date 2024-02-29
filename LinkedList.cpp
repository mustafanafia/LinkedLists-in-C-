#include <iostream>
#include <cstdio>
using namespace std;
template <class T>
class Sequence {

private: // Internal Representation
    class NodeRecord {
    public:
        T value;
        NodeRecord* next;
    };

    NodeRecord* head;
    int size;
public:
    Sequence();
    ~Sequence();
    void clear(void);
    

    int length(void);
    void add(T& x, int pos);
    void remove(T& x, int pos);
    T& entry(int pos);
    void outputSequence(void);
    //implement the following four functions


private: // Internal operations
    void reclaimAllNodes(NodeRecord*& p);
    
};

template <class T>
Sequence<T>::Sequence(){

    head = NULL;
    size = 0;
}

template <class T>
Sequence<T>::~Sequence() {
    reclaimAllNodes(head);
    // ~Sequence;;;
 }

template <class T>
void Sequence<T>::clear(void) {
    reclaimAllNodes(head);
    head = NULL;
 } 

template <class T>
void Sequence<T>::reclaimAllNodes(NodeRecord*& initialP) {

    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    } // end if
}




    template<class T>
    void Sequence<T>::add(T& x, int pos) {
        if (pos<0 || pos > size) {
            cout << "Position out of bounds" << endl;
            return;
        } //if

        NodeRecord* temp = new NodeRecord;
        temp->value = x;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        }
        else if (pos == 0) {
            temp->next = head;
            head = temp;
        }  //else if
        else {
            NodeRecord* current = head;
            current = current->next;
            temp->next = current->next;
            current->next = temp;
        } //else
        size++;
    } //add

    template<class T>
    void Sequence<T>::remove(T& x, int pos) {
        if (pos<0 || pos > size) {
            cout << "Position out of bounds" << endl;
            return;
        } //if

        NodeRecord* temp = head;
        if (pos == 0) {
            x = head->value;
            head = head->next;
        } //if

        else {
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            } //for
            
        
            x = temp->next->value;
            if  (pos == size) {
                temp->next = NULL;
            } //if
            else {
                temp->next = temp->next->next;
            } //else
            size--;
        } //else
    } //remove


        template<class T>
        T& Sequence<T>::entry(int pos) {
            NodeRecord* temp = head;
            for (int i = 0; i <= pos; i++) {
                temp = temp->next;
            }
            return temp->value;
        }

        template<class T>
        int Sequence<T>::length(void) {
            return this.size;
        } //length
    

        template<class T>
        void Sequence<T>::outputSequence(void) {
            
            NodeRecord* current = new NodeRecord;
            current = head;
            while (current != NULL) {
                cout << current->value << "\n";
                current = current->next;
            }
        } //outputsequence


   
      

        int main() {
            Sequence<int> S1;
            Sequence<int> S2;
            Sequence<int> S3;
            int x1 = 1;
            int x2 = 2;
            int x3 = 3;
            int x4 = 4;
            int x5 = 5;

            int x6 = 6;
            int x7 = 7;
            int x8 = 8;
            int x9 = 9;
            int x10 = 10;

            int x11 = 11;
            int x12 = 12;
            int x13 = 13;
            int x14 = 14;
            int x15 = 15;

            S1.add(x1, 0);
            S1.add(x2, 1);
            S1.add(x3, 2);
            S1.add(x4, 3);
            S1.add(x5, 4);

            S2.add(x1, 5);
            S2.add(x2, 6);
            S2.add(x3, 7);
            S2.add(x4, 8);
            S2.add(x5, 9);

            S3.add(x1, 10);
            S3.add(x2, 11);
            S3.add(x3, 12);
            S3.add(x4, 13);
            S3.add(x5, 14);

            cout << "The linked list in List 1 is: ";           
            S1.outputSequence();

            cout << "The linked list in List 2 is: ";
            S2.outputSequence();

            cout << "The linked list in List 3 is: ";
            S3.outputSequence();


            cout << "The linked list after removing the element at index 4 from list 1: ";
            S1.remove(x5,4);
            S1.outputSequence();

            cout << "The list size of list 2 is: ";
            S2.length();
            S2.outputSequence();


            cout << "The list entry in list 3 is: ";
            S3.entry(3);
            S3.outputSequence();


            return 0;
        }
    

    

 


