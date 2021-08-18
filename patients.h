
struct pat_str
{
    std::string name ;
    std::string f_name ;
    long long int id;
};

class pat_class
{
    std::vector<pat_str> pat_list;
    long long int id = 0;
public:

    long long int insert(std::string name , std::string f_name){
        pat_str str;
        str.f_name = f_name;
        str.name = name;
        str.id = id;
        pat_list.push_back(str);
        return str.id;
    }

    long long int search(std::string name , std::string f_name){
        for(int i=0;i<id;i++){
            if(pat_list[i].name==name && pat_list[i].f_name==f_name){
                return pat_list[i].id;
            }
        }
        return -1;
    }

    std::string name(long long int id)
    {

        return pat_list[id].name;
    }
};

