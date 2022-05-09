#include"traffic.h"
#include <istream>

using namespace std;


Traffic::Traffic(int id){
    id_traffic = id;
}

int Traffic::get_id_traffic(){
    return id_traffic;
}

void Traffic::put_id_node(int id_node){

    list_traffic.push_back(id_node);

}