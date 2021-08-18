class docs{
    std::string name[4] = {"Dr Singh","Dr Gupta","Dr Kumar","Dr Bansal"};
    int room[4] = {1,2,3,4};
    bool assigned[4] = {false,false,false,false};
    int n = 4;
    int start = 0 , end = 1;
public:

    bool assign()
    {
        if(start==end && assigned[end]==true){
            std::cout<<"No Doctor available\n";
            std::cout<<"Please wait\n";
            return false;
        }
        if(start==end)
        {
            std::cout<<name[end]<<" assigned\n";
            std::cout<<room[end]<<" is the room\n";
            assigned[end]=true;
            return true;
        }
        std::cout<<name[end]<<" assigned\n";
        std::cout<<room[end]<<" is the room number\n";
        assigned[end] = true;
        end = (++end)%n;
        return true;
    }

    void free(){
        assigned[start] = false;
        start = (++start)%n;
    }

    void show(){
        for(int i=0;i<n;i++){
            std::cout<<"Name->"<<name[i]<<" Room->"<<room[i]<<" Assigned->"<<assigned[i];
            std::cout<<std::endl;
        }
    }
};
