int produce(int quantity){
    int choice;
    while(1){
        cin >> choice;
        if(choice>0 && choice<5) break;
        else cout << "Invalid Input" << endl;
    }
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;
    cout << "Producing Resources..." << endl;
    switch (choice) {
        case 1:
            cout << "Water Produced : " << floor(quantity/10) << endl;
            break;
        case 2:
            cout << "Food Produced : " << floor(quantity/10) << endl;
            break;
        case 3:
            cout << "Medicine Produced : " << floor(quantity/10) << endl;
            break;
        case 4:
            cout << "Shelter Produced : " << floor(quantity/10) << endl;
            break;
    }
    return choice;
}

void checkResource(resourcesList &R){
    int minus = 0;

    if(R.getData("Water")<1) minus++;
    if(R.getData("Food")<1) minus++;
    if(R.getData("Medicine")<1) minus++;

    if(minus>0 && R.getData("Population")>90){ 
        R.addQuantity(5,-minus*R.getData("Population")/15);
    } else {
        R.addQuantity(5,-minus*10);
    }
}

void option(){
    cout << "Choose your action (1-4) " << endl;
    cout << "1. Produce Water    ? " << endl;
    cout << "2. Produce Food     ? " << endl;
    cout << "3. Produce Medicine ? " << endl;
    cout << "4. Produce Shelter  ? " << endl;
    cout << "Select your choice : ";
}

void consumed(resourcesList &R){
    R.addQuantity(1,-3*R.getData("Population")/10);
    R.addQuantity(2,-3*R.getData("Population")/10);
    R.addQuantity(3,-1*R.getData("Population")/10);
}

void LINE(int total, int no){
    char letter;
    if(no==1) letter = '-';
    else letter = '=';

    cout << setw(total) << setfill(letter) << "" << setfill(' ') << endl;
}