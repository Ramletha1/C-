#include <iostream>
using namespace std;
#include "resourceList.h"
#include "event_queue.h"
#include "event.h"
#include "save.h"
#include <string.h>

int main(){
    resourcesList R;
    event_queue E;
    int choice, turn=0;
    string event;

    cout<<"Would you like to Start new game or load game?\n1.New Game\n2.Load Game"<<endl;
    cout<<"\nOption: ";
    cin>>choice;
    
    if(choice == 1) newGame(R);
    else loadGame(R);

    cout<<"\nStarting Game..."<<endl;
    eventAssign(E);
    cout<<setw(40)<<setfill('-')<<""<<setfill(' ')<<endl;
    while(1){
        cout << "The available resources are:" << endl;
        R.printList();

        cout<<"\n";
        event = E.eventRandomizer(R);

        if (event == "none"){
            cout<<"No event happening"<<endl;
        }else{
            cout<<"Event: "<<event<<endl;
        }




        cout<<endl<<"Choose action:"<<endl<<endl;

        //
        //action and event here
        //
        cout << "Updated Resources are:" << endl;
        R.printList();

        cout<<"\nDay: "<<++turn<<endl;

        cout<<setw(40)<<setfill('-')<<""<<setfill(' ')<<endl;
        cout<<"1.Continue\n2.Save"<<endl;
        cout<<"\nOption: ";
        cin>>choice;
        cout<<setw(40)<<setfill('-')<<""<<setfill(' ')<<endl<<endl;
        if(choice==2){
            saveGame(R);
            break;
        }
    }

    return 0;
}
