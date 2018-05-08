#include <iostream>

typedef struct Vertex{
    int intData;
    struct Vertex* nextVertex;
} typeVertex;

using namespace std;

int main()
{
    int intVerticesInList = 0;
    Vertex* current = NULL; //To store the address of the current element undergoing processing.
    Vertex* previous = NULL; //This is temp storage. It stores the address of the previous vertex that was processed.
    Vertex* head = NULL; //To store the address of the first vertex

    cout << "How many vertices will you enter? " << endl;
    cin >> intVerticesInList;

    for(int i=0;i<intVerticesInList;i++){
        current = new Vertex;
        current->intData = i;
        current->nextVertex = NULL;
        //attach the previous node to the current node.
        if(i > 0) previous->nextVertex = current;
        previous = current;
        //set the head vertex
        if(i == 0) head = current;
    }

    cout << endl << "---------------------------------------------" << endl;
    current = head;
    while(current != NULL ){
        cout << "Address: " << current << endl;
        cout << "\tData: " << current->intData << endl;
        cout << "\tNext Address: " << current->nextVertex << endl;
        current = current->nextVertex;
    }

    cout << endl << "---------------------------------------------" << endl;
    //Delete the memory allocated to the heap
    current = head;
    while(current != NULL ){

        cout << "DELETING" << endl;
        cout << "\tAddress: " << current << endl;
        cout << "\t\tData: " << current->intData << endl;
        cout << "\t\tNext Address: " << current->nextVertex << endl;

        //set the new head
        head = current->nextVertex;
        delete current;
        current = head;
    }

    cout << endl << "---------------------------------------------" << endl;
    current = head;
    while(current != NULL ){
        cout << "Address: " << current << endl;
        cout << "\tData: " << current->intData << endl;
        cout << "\tNext Address: " << current->nextVertex << endl;
        current = current->nextVertex;
    }

    return 0;
}
