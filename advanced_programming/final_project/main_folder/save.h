#include <fstream>

void saveGame(resourcesList &,int);
void loadGame(resourcesList &,int &);
void newGame(resourcesList &);
int readFile(int);
int countLinesInFile(string);


string resourcesArray[5] = {"Water","Food","Medicine","Shelter","Population"};


void saveGame(resourcesList &R,int day){
    ofstream saveFile("Saved.txt");
    for (int i =0;i<5;i++){
        saveFile<<R.getData(resourcesArray[i])<<endl;
    }
    saveFile<<day<<endl;
    saveFile.close();
    cout<<"\nGame Saved Successfully!"<<endl;
}

void loadGame(resourcesList &R,int &day){
    ifstream saveFile("Saved.txt");
    if(saveFile.is_open()){
        for (int i =0;i<5;i++){
            R.insertResource( resourcesArray[i] , readFile(i+1) );
        } 
        day = readFile(6);
    }else{
        newGame(R);
    }
}

void newGame(resourcesList &R){
    R.insertResource("Water",200);
    R.insertResource("Food",200);
    R.insertResource("Medicine",100);
    R.insertResource("Shelter",100);
    R.insertResource("Population",150);
}

int readFile(int n){
    int x,i;
    ifstream saveFile("Saved.txt");
    for(i = 0;i<n;i++){
        saveFile>>x;
    }
    saveFile.close();
    return x;
}