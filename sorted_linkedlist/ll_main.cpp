// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <iostream>
using namespace std;
#include "ll.h"

void instructions( void );

int main( void )
{ 
   LL l; // initially there are no nodes
   unsigned int choice; // user's choice
   int item; // char entered by user
   string name;

   instructions(); // display the menu
   cout<< "? " ;
   cin>> choice ;

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            cout<<"Enter a number_name: ";
            name.clear();
            cin >> item >> name;
            l.insert(item,name); // insert item in list
            l.printList();//print the list out
            /* for doubly linkedlist*/
            l.printListR(); 
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !l.isEmpty(  ) ) { 
               cout<< "Enter number to be deleted: " ;
               cin>>item ;

               // if the value is found, remove it
               if ( item==l.deletes( item ) ) { // remove item
                // cout<<item << " deleted.\n";
                  l.printList( );
                  l.printListR();
                /* for doubly linkedlist*/
                   //l.printListR(); 
               } // end if
               else {
                  cout<<item<<" not found.\n\n";
               } // end else
            } // end if
            else {
               cout<<"List is empty."<<endl;
            } // end else

            break;
         default:
           cout<< "Invalid choice." <<endl;
            instructions();
            break;
      } // end switch

      cout<< "\n? " ;
     cin>>choice ;
   } // end while

   puts( "End of run." );
} // end main




// display program instructions to user
void instructions( void )
{ 
   cout<< "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end."<<endl ;
} // end function instructions