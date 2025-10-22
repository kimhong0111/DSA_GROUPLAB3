#include "utils/sll.hpp"
#include "utils/dll.hpp"
#include <chrono>
#include <iostream>
using namespace std;
using clk=chrono::high_resolution_clock;

     int main(){

        singlyLinkedList l1;
        for(int i=0;i<1000;i++){
            l1.insert_front_onlyhead(i+1);
        }
        singlyLinkedList l2;
          for(int i=0;i<1000;i++){
            l2.insertFront(i+1);
      
         }
         
        // single linkedlist with head only
        cout<<"Remove_front with head only sll"<<endl;
       for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<30;j++){
                l1.remove_front_onlyhead();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
        cout<<endl;

          cout<<"insert_front with head only sll"<<endl;

         for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<70;j++){
                l1.insert_front_onlyhead(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;

   
           cout<<"insert_end with head only sll"<<endl;
    
          for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<70;j++){
                l1.insert_end_onlyhead(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;

            cout<<"Remove_end with head only sll"<<endl;
   
                for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<30;j++){
                l1.remove_end_onlyhead();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;


        }
           
      
                cout<<endl;
                
                //single linkedlist with head+tail

             cout<<"InsertFront with head + tail sll"<<endl;

     
               for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<70;j++){
                l2.insertFront(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;
            cout<<"DeleteFront with head + tail sll"<<endl;


                for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<30;j++){
                l2.deleteFront();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;
                
 
              cout<<"InsertBack with head + tail sll"<<endl;


               for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<70;j++){
                l2.insertBack(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;    

   
   

          cout<<"DeleteBack with head + tail sll"<<endl;

     for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<30;j++){
                l2.deleteEnd();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;

               
       
        doublyLinkedList dl1;
         for(int i=0;i<1000;i++){
            dl1.insertFront(i+1);
         }
            
    
     
         //double linked list

             cout<<"InsertFront with head + tail dll"<<endl;

     
               for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<70;j++){
                dl1.insertFront(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;
            cout<<"DeleteFront with head + tail dll"<<endl;

   
                for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<30;j++){
                dl1.deleteFront();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;
 
              cout<<"InsertBack with head + tail dll"<<endl;


               for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<70;j++){
                dl1.insertBack(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;    
   

    
          cout<<"DeleteBack with head + tail dll"<<endl;

     for(int i=0;i<5;i++){
             auto t0=clk::now();
            for(int j=0;j<30;j++){
                dl1.deleteEnd();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }
                cout<<endl;
      



           


           




      return 0;
   }
