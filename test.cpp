#include "include/disk.hpp"
#include "include/inode.hpp"
using namespace disk;
using namespace std;
#define TEST_LOCK 1

#if !TEST_LOCK
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

#endif

int main(){
    inode_namespace::inode_data data;
    data.access_time = 0;
    data.name_block_id = 0;
    inode_namespace::Inode inode(data);
    printf("inode data: %d %d\n", inode.data.access_time, inode.data.name_block_id);
    return 0;
}