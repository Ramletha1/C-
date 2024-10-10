void eventAssign(event_queue &E){   // Manually assign event here.

    // water,food,medicine,shelter,population

    E.add_event("Survivor Found",0,0,0,0,10);
    E.add_event("Trade Offer",-30,-30,-30,0,0);
    E.add_event("Raining",50,0,0,0,0);
    E.add_event("Drought",-50, 0, 0,-10,0);
    E.add_event("Epidemic", 0, 0,-20, 0,-20);
    E.add_event("Thief",-50,-50,-30,0,0);
    E.add_event("Heat Wave",-100,0,0,0,0);
}