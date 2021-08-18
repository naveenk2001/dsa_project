class med_class{
    float medicines[5] = {1.12,5.2,3.6,4.8,5.1};
    std::string names[5] = {"Med1","Med2","Med3","Med4","Med5"};
    public:
    void list_med(){
        for(int i=0;i<5;i++){
            std::cout<<names[i]<<"-> Rs"<<medicines[i]<<std::endl;
        }
    }
    double show(){
        list_med();
        double price = 0;
        int med , no;
        std::cout<<"\n-1 to exit\n";
        std::cout<<"Enter medicine number and number of medicine\n\n";
        while(true){
            std::cin>>med>>no;
            if(med==-1){
                return price;
            }
            price += (medicines[med-1]*no);
        }
    }
};
