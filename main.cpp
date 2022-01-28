#include "iostream"
using namespace std;

class Node {
public:
    int data=0;
    Node* address;
};

void create(Node** var){
    Node* newNode = new Node();
    Node* ref = *var;

    newNode->data = 0;
    newNode->address = NULL;

    if(*var == NULL){
        *var = newNode;
        return;
    }

    while(ref->address != NULL){
        ref = ref->address;
    }
    ref->address = newNode;
    return;
}

void print(Node* node){
    cout<<"Your data: ";
    while(node!=NULL){
        cout<<node->data<<",";
        node = node->address;
    }
    cout<<endl;
}

void push(Node** node, int userData){
    Node* newNode = new Node();
    newNode->data = userData;
    newNode->address = *node;
    *node = newNode;
}

void append(Node** node, int userData) {
    Node* newNode = new Node();
    newNode->data = userData;
    newNode->address = NULL;

    Node* ref = *node;

    while (ref->address != NULL){
        ref = ref->address;
    }
    ref->address = newNode;
    return;
}

void insertAfter(Node** node, int index, int userData) {
    int i = 1;
    Node* head = *node;
    while(head->address != NULL) {
        head = head->address;
        i++;
    }

    if (index >= i){
        cout<<endl<<"Invalid Index No."<<endl<<endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = userData;

    Node* ref = *node;
    Node* ref2 = *node;
    for(int j=0; j<index; j++){
        ref = ref->address;
    }
    for (int k=0; k<index; k++) {
        ref2 = ref2->address;
    }
    newNode->address = ref2->address;
    ref->address = newNode;
}

int search(Node* node, int query) {
    int i = 0;
    Node* ref = node;
    while (ref != NULL) {
        if (ref->data == query){
            return i;
        }
        ref = ref->address;
        i++;
    }
    return -1;
}

int deleteData(Node** node, int query) {
    Node* temp = *node;
    Node* prev_node = NULL;

    if (temp->address != NULL && temp->data == query) {
        *node = temp->address;
        delete temp;
        return 1;
    } else if (temp->address == NULL && temp->data == query) {
        delete temp;
        return 0;
    } else {
        while (temp != NULL){
            if (temp->data == query) {
                prev_node->address = temp->address;
                delete temp;
                return 1;
            }
            prev_node = temp;
            temp = temp->address;
        }
        return -1;
    }
}

void update(Node** node, int index, int userData) {
    int i = 1;
    Node* head = *node;
    while(head->address != NULL) {
        head = head->address;
        i++;
    }

    if (index >= i){
        cout<<endl<<"Invalid Index No."<<endl<<endl;
        return;
    }

    Node* newNode = *node;
    for (int j=0; j<index; j++){
        newNode = newNode->address;
    }
    newNode->data = userData;
}

int main() {
    Node* var = NULL;
    var = new Node();

    while (true){
        int num = 0;
        cout<<"Size of data:";
        cin>>num;

        if (num == 0) {
            continue;
        } else {
            var->data=0;
            var->address=NULL;

            for(int i=1; i<num; i++){
                create(&var);
            }
            print(var);
            break;
        }
    }

    while (true){
        int option = 0;
        cout<<"------------------------------------------------------------------------------------"<<endl;
        cout<<"Options"<<endl<<"1. Push Data"<<endl<<"2. Append Data"<<endl<<"3. Insert after a Data"<<endl<<"4. Search"<<endl<<"5. Delete"<<endl<<"6. Update"<<endl<<"0. Exit"<<endl<<"Your Option:";
        cin>>option;

        if (option == 0) {
            break;
        } else {
            if (option == 1) {
                int data = 0;
                cout<<"Please enter a data to push:";
                cin>>data;
                push(&var, data);
                print(var);
                continue;
            } else if (option == 2) {
                int data = 0;
                cout<<"Please enter a data to append:";
                cin>>data;
                append(&var, data);
                print(var);
                continue;
            } else if (option == 3) {
                int index = 0;
                int data = 0;
                cout<<"Please enter index number:";
                cin>>index;
                cout<<"Please enter data for index no."<<" "<<index+1<<" to insert after:";
                cin>>data;
                insertAfter(&var, index, data);
                print(var);
                continue;
            } else if (option == 4){
                int data = 0;
                cout<<"Please enter a data to search:";
                cin>>data;
                int result = search(var, data);
                if (result == -1){
                    cout<<endl<<"Data not found."<<endl<<endl;
                } else {
                    cout<<endl<<"We found your data at index no."<<result<<endl<<endl;
                }
                print(var);
                continue;
            } else if (option == 5) {
                int data = 0;
                cout<<"Please enter a data to delete:";
                cin>>data;
                int result = deleteData(&var, data);
                if (result == 0) {
                    cout<<endl<<"You have no data now..."<<endl;
                    break;
                } else if (result == -1) {
                    cout<<endl<<"Not Found."<<endl<<endl;
                    continue;
                } else {
                    print(var);
                    continue;
                }
            } else if (option ==6) {
                int index = 0;
                int data = 0;
                cout<<"Please enter index number:";
                cin>>index;
                cout<<"Please enter data for index no."<<" "<<index<<" to update:";
                cin>>data;
                update(&var, index, data);
                print(var);
                continue;
            } else {
                continue;
            }
        }
    }
}
