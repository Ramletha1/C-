#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
#include "resource/resource_ll.h"
#include "event/event_queue.h"
#include "event/event.h"
#include "save.h"
#include "main_action/action.h"

int main(){
    resourcesList R;
    event_queue E;
    int status=1, day=0; 
    int choice, quantity, x;
    string event = "None";

    LINE(60,2);
    cout << "Would you like to Start new game or load game?" << endl;
    cout << "1.New Game" << endl;
    cout << "2.Load Game" <<endl;
    cout << endl << "Option: ";

    while(1){
        cin >> choice;
        if(choice>0 && choice<3) break;
        cout << "Invalid Input." << endl;
    }
    
    if(choice==1) newGame(R);
    else loadGame(R,day);

    eventAssign(E);

    cout << "\nStarting Game..." << endl;

    while(status){
        day++;
        LINE(30,2);
        cout << "Day " << day << endl;
        quantity = (rand()%R.getData("Population"))/10*10 + R.getData("Population")*10/25;

        if(R.getData("Water")<1 ||R.getData("Food")<1||R.getData("Medicine")<1) cout << "You don't have enough resource(s) for the population." << endl;

        
        
        // Print event
        if(day>5) event = E.eventRandomizer();
        cout << "Event: " << event << endl;

        // Print Current resource
        cout << "The available resources are:" << endl;
        R.printList();
        LINE(30,1);

        // Choose action
        option();
        x = produce(quantity);
        R.addQuantity(x, quantity);
        LINE(30,1);        

        // Updating resource and print
        consumed(R);
        E.eventConsume(R, event);
        checkResource(R);
        cout << "Updated resources:" << endl;
        R.printList();
        LINE(30,1);

        if(R.getData("Population")/10>100 || day>=100){
            cout << endl;
            LINE(40,2);
            cout << "You've won the game!" << endl;
            LINE(40,2);
            saveGame(R,day); 
            break;
        }
        if(R.getData("Population")/10<1 ){
            cout << endl;
            LINE(40,2);
            cout << "You Lose!" << endl;
            LINE(40,2);
            newGame(R); 
            break;
        }
        
        
        cout << "1.Continue\n2.Save" << endl;
        cout << "\nOption: ";
        cin >> choice;
        if(choice==2){
            saveGame(R,day);
            break;
        }
    }
    return 0;
}