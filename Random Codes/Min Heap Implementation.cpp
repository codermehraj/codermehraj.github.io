#include<stdio.h>

#define MX 99999

// array to store the binary heap
int heap[MX];
int pos = 0; // current position in the heap
int cur_pos, parent, temp, dlteditem, leftChild, rightChild;

// inserts item inside the heap
void INSERT(int item){

    // inserting at the end of the array
    cur_pos = pos;
    heap[pos++] = item;

    // Gradually checking parents and moving up by swapping
    while(cur_pos > 0){
        parent = (cur_pos - 1) / 2;
        // breaking the loop if current node is in the correct position
        if(heap[parent] <= heap[cur_pos]) break;

        //otherwise swapping
        temp = heap[parent];
        heap[parent] = heap[cur_pos];
        heap[cur_pos] = temp;

        // updating current positon
        cur_pos = parent;
    }
}

int DELETE(){
    // storing the deleted item
    dlteditem = heap[0];

    // decresing size of the heap
    pos--;

    // placing the last element of the heap array as root of the tree
    heap[0] = heap[pos];

    // starting heptify from the root
    cur_pos = 0; leftChild = 1; rightChild = 2;

    // checking children for swaping
    while(rightChild < pos){

        // return if the node is in the correct place already
        if(heap[leftChild] >= heap[cur_pos] && heap[rightChild] >= heap[cur_pos]){
            return dlteditem;
        }

        // swapping with the smaller node
        if(heap[leftChild] < heap[rightChild]){
             temp = heap[leftChild];
             heap[leftChild] = heap[cur_pos];
             heap[cur_pos] = temp;
             cur_pos = leftChild;
        }  else {
            temp = heap[rightChild];
            heap[rightChild] = heap[cur_pos];
            heap[cur_pos] = temp;
            cur_pos = rightChild;
        }

        // calculating new node's child
        leftChild = (cur_pos * 2) + 1;
        rightChild = (cur_pos * 2) + 2;
    }

    return dlteditem;
}

int main(){

    int q, x, type;

    printf("Enter the number of queries : ");
    scanf("%d",&q); // q = number of queries

    while(q--){

        printf("Press 1 for insertion and 2 for deletation : ");
        scanf("%d",&type);

        if(type == 1){
            // insert
            printf("Enter the number that you want to insert : ");
            scanf("%d",&x);
            INSERT(x);
        }
        else if(type == 2){
            // delete
            printf("%d is deleted\n",DELETE());
        }

    }

    // prints the remaining heap array
    for(int i=0;i<pos; i++) printf("%d ",heap[i]);

    return 0;
}

// sample array:
// 95 85 70 55 33 30 65 15 20 15 22
