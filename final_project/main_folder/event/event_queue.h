#include "event_node.h"

class event_queue{      // Queue + Doubly Linkedlist
    private:
        EventPtr head;
        EventPtr tail;
        int size;
    public:
        void add_event(string,int,int,int,int,int);   
        void remove_event(int x=1);     
        void display();                
        string event_name(int x=1);
        int qget_size();
        string eventRandomizer();
        void eventConsume(resourcesList &R, string);
        event_queue();     
        ~event_queue();
        // int getResourceInt(int ,int );
};


void event_queue::add_event(string name,int w ,int f,int m,int s,int p){
    EventPtr new_node = new event_node(name,w,f,m,s,p);
    if(new_node){
        if(size>0){     // If at least a single node existed
            new_node->set_prev(tail);
            tail->set_next(new_node);
        }
        else{           // If this is very first node created
            head = new_node;
        }
        //cout << "Adding " << name << endl;
        tail = new_node;
        size++;
    }
    else{
        cout << "Out of memory." << endl;
    }
}

void event_queue::remove_event(int x){
    EventPtr temp = head;
    if(size>0){
        if(x==1){
            if(size>1){
                head = head->get_next();
            }
        }
        else if(x>1 && x<=size){
            for(int i=1;i<x;i++){
                temp = temp->get_next();
            }
            if(temp->get_next()!=NULL && temp->get_prev()!=NULL){
                (temp->get_prev())->set_next(temp->get_next());
                (temp->get_next())->set_prev(temp->get_prev());
            }
            else if(temp->get_next()==NULL && temp->get_prev()!=NULL){
                tail = tail->get_prev();
            }
        }
        else{
            cout << "Please choose only number that is/are available." << endl;
            return;
        }
    }
    else{
        cout << "There is no event." << endl;
        return;
    }
    //cout << "Removing " << temp->get_Sdata() << endl;
    size--;
    delete temp;
}

void event_queue::display(){
    switch(size){
        case 0: cout << "There is no event." << endl; return; break;
        case 1: cout << "There is " << size << " event in total." << endl; break;
        default: cout << "There are " << size << " events in total." << endl; break;
    }
    EventPtr current = head;
    for(int i=0;i<size;i++){
        cout << i+1 << ". " << current->get_Sdata() << " (" << current->get_Sdata() << ")" << endl;
        current = current->get_next();
    }
}

string event_queue::event_name(int x){
    EventPtr current = head;
    for(int i=1;i<x;i++){
        current = current->get_next();
    }
    return current->get_Sdata();
}

int event_queue::qget_size(){
    return size;
}

string event_queue::eventRandomizer(){
    int eventChance = (rand()%100)+1;

    if (eventChance<=60){       // Randomize event, then give position of event node
        eventChance = (rand()%qget_size())+1;
        return event_name(eventChance);
    }
    return "None";
}

void event_queue::eventConsume(resourcesList &R, string n){
    EventPtr currentPtr;
    currentPtr = head;
    if(n=="None") return;   // If event doesn't occur
    while (currentPtr->get_Sdata()!= n){    // Check string until found
        currentPtr= currentPtr->get_next();
    }
    if(R.getData("Population")>=R.getData("Shelter") && n=="Survivor Found"){
            cout << "Not enought shelter" << endl;      // If event is found survivors
    }else{
        for(int i=1;i<=5;i++){
            R.addQuantity(i,currentPtr->get_Idata(i));      // Change resource by disaster
        }
    }
}

event_queue::event_queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

event_queue::~event_queue(){
    //cout << "Deleting all existing event node..." << endl;
    while(size>0){
        remove_event();
    }
}

/*int event_queue::getResourceInt(int x,int a){   //  x = position of event node, a = return resource type
    EventPtr current = head;
    for(int i=1;i<=x;i++){
        current = current->get_next();
    }
    return current->get_Idata(a);
}*/