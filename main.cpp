#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<fstream>
#include "patients.h"
#include "doctors.h"
#include "medicine.h"
int main()
{

    std::cout<<"\n\nWelcome to hospital management system....\n";
    pat_class pat;
    med_class medicine;
    std::queue<std::string> queue;
    std::queue<std::string> queue_medicine;
    docs doctr;
    while(true)
    {

        std::cout<<"\n\nEnter (1-Register , 2-Assign Doctor , 3-Balance , 4-Room Status , 4-Quit)->";
        int inpt;
        std::cin>>inpt;
        std::cout<<std::endl;

        if(inpt==1)
        {

            std::string name , f_name;
            std::cout<<"Enter the name->";
            std::cin>>name;
            std::cout<<"Enter the fathers name->";
            std::cin>>f_name;
            long long int id = pat.search(name,f_name);
            if(id!=-1)
            {
                std::cout<<"Record already there\n";
                queue.push(name);
                std::cout<<"Your at "<<queue.size()<<" position\n";
            }else{
                std::cout<<"Adding your name in record\n";
                pat.insert(name,f_name);
                queue.push(name);
                std::cout<<"Your at "<<queue.size()<<" position\n";
            }
        }

        else if(inpt==2){

            if(!queue.empty()){
                std::cout<<queue.front()<<" turn\n";
                if(doctr.assign()==true){
                    queue_medicine.push(queue.front());
                    queue.pop();
                }
            }else{
                std::cout<<"No patients left\n";
            }
        }

        else if(inpt==3){
            if(!queue_medicine.empty()){
                std::cout<<queue_medicine.front()<<" please select your medicines\n";
                double price = medicine.show();
                std::cout<<"Your price(gst included) is Rs"<<price<<std::endl;
                queue_medicine.pop();
                doctr.free();
            }else{
                std::cout<<"No patients left\n";
            }
        }

        else if(inpt==4){
            std::cout<<"Room status \n";
            doctr.show();
        }

        else if(inpt==5)
            break;
    }
    std::cout<<"\n\nThanks have a good day\n";
    return 0;
}
