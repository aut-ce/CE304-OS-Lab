#include <stdio.h>
#include <stdlib.h>
#include "red_black_tree/rb.h"
#include "red_black_tree/rb_data.h"
#include "proc.h"

#define PROCESS_COUNT 3


void fill_process_array(process* process_array[PROCESS_COUNT]){
    // fill the process_array with processes
}

void insert_one_process_to_rbtree(rbtree *rbt, process* proc){
    // make mydata instance of process and insert it to the rbtree, the key is proc->vruntime
}

void insert_processes_to_rbtree(rbtree *rbt, process *process_array[PROCESS_COUNT]){
    // insert processes in process_array to rbtree
}

process* process_of_node(rbnode* node){
    // extract the process in node
}

int main(){
    // create an array of procdesses and fill it
    printf("process array filled\n");
    // create a red-black tree
    
    // insert processes to rbtree
    printf("inserted processes to rbtree\n");

    // declare node, current_proc and current_tick

    //scheduling algorithm:
    while(
        // condition of loop
        ){
        // execute the process in left-most node of rbtree
        // increment current_tick
        // if process still has positive residual_duration, reinsert it to the rbtree 
    }
}