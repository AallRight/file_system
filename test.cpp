#include "include/disk.hpp"
using namespace disk;
using namespace std;
int main(int argc, char *argv[]){
    map_diskfile();
    for(int i = 0; i < 10; i++){
        cout<<"Enter option, sectornum, blocknum, data"<<endl;
        int option;
        int sectornum, blocknum;
        char data[BLOCK_SIZE] = "hello woshi nindedie";
        cin>>option;
        cin>>sectornum>>blocknum;
        if(option == 0){
            read_block(sectornum, blocknum, data);
            cout<<data<<endl;
        }
        else if(option == 1){
            // cin.read(data, BLOCK_SIZE);
            write_block(sectornum, blocknum, data);
            cout<<data<<endl;
        }

    }
    umap_diskfile();
    return 0;
}