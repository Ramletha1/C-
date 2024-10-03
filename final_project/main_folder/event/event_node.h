#ifndef stack_h
#define stack_h

class event_node{
    private:
        string event_disaster;
        int Water;
        int Food;
        int Medicine;
        int Shelter;
        int Population;
        event_node *next_ptr;
        event_node *prev_ptr;
    public:
        string get_Sdata();
        int get_Idata(int x);
        void set_next(event_node*);
        void set_prev(event_node*);
        event_node* get_next();
        event_node* get_prev();
        event_node(string,int, int,int ,int ,int );
        ~event_node();
};
typedef event_node* EventPtr;


string event_node::get_Sdata(){    // ONLY return valuable as STRING
    return event_disaster;
}

int event_node::get_Idata(int a){    // ONLY return valuable as STRING  // a = resource type
    switch(a){
        case 1: return Water; break;
        case 2: return Food; break;
        case 3: return Medicine; break;
        case 4: return Shelter; break;
        case 5: return Population; break;
        default: return -1; break;
    }
}

void event_node::set_next(event_node *ptr){
    next_ptr = ptr;
}

void event_node::set_prev(event_node *ptr){
    prev_ptr = ptr;
}

event_node* event_node::get_next(){
    return next_ptr;
}

event_node* event_node::get_prev(){
    return prev_ptr;
}

event_node::event_node(string name, int w=0,int f=0,int m=0,int s=0,int p=0){
    event_disaster = name;
    Water = w;
    Food = f;
    Medicine = m;
    Shelter = s;
    Population = p;

    next_ptr = NULL;
    prev_ptr = NULL;
}

event_node::~event_node(){ }

#endif