#include <vector>
using namespace std;
class Traffic
{
    
    private:
        int id_traffic;
        vector<int> list_traffic;
    public:
        Traffic(int id_traffic);
        int get_id_traffic();
        void put_id_node(int id_node);
        vector<int> get_traffic();
};
