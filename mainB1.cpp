#include "utils/sll.hpp"
#include "utils/dll.hpp"
#include <iostream>
using namespace std;

  int main(){

      cout<<"push front sll "<<endl;

     
               for(int i=0;i<5;i++){
             singlyLinkedList l1;

             auto t0=clk::now();
            for(int j=0;j<1000;j++){
                l1.push(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }

           cout<<"pop front sll "<<endl;

     
               for(int i=0;i<5;i++){
                    singlyLinkedList l1;

             auto t0=clk::now();
            for(int j=0;j<1000;j++){
                l1.pop();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }


               cout<<"push front dll"<<endl;

               for(int i=0;i<5;i++){
                    doublyLinkedList d1;

             auto t0=clk::now();
            for(int j=0;j<1000;j++){
                d1.push(j+1);
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }

           cout<<"pop front  dll"<<endl;

     
               for(int i=0;i<5;i++){
                    doublyLinkedList d1;

             auto t0=clk::now();
            for(int j=0;j<1000;j++){
                d1.pop();
         }
           auto t1=clk::now();
           auto duration=chrono::duration_cast<chrono::nanoseconds>(t1-t0);
           cout<<"time taken "<<duration.count()<<" nanosecond"<<endl;
        }









    return 0;
  }