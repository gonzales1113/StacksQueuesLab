#include "cs163_stack.h"


//These are the functions you will be implementing
//for this lab, using a linear linked list of arrays
//as the data structure

//Add a new item to the top of stack
int stack::push(const journal_entry & to_add)
{
    if (top_index < 0){
    BAD_INDEX error;
    error.badData = top_index;
    throw error;
    }
    
    if (!head){
     head = new node;
     head->entries = new journal_entry[MAX];
     top_index = 0;
     head->next = nullptr;

    }

    if (top_index == MAX){
        // hold onto list
        node *temp = head;

        // add new node at head
        head = new node;

        // allocate entries array
        head->entries = new journal_entry[MAX];

        // reconnect list
        head->next = temp;
        
        // reset top_index
        top_index = 0;
    }

        // add entry at top_index

        if (!head->entries[top_index].copy_entry(to_add))
            return 0;

        // increment top_index
        ++top_index;

        return 1;

}

//Remove the top of stack
int stack::pop (void)
{
    if (!head) return 0; // can't remove anything

    --top_index; 
    // This works because we're moving the "top" of the stack to the one before it and we're going to restart stacking at this position
    //

    if (top_index == 0){

        node *hold = head->next; // moving hold to "hold" the next node to move over to later when we delete the current one head is at
        delete[] head->entries; // deleting the array entries by using head to access it
        head->entries = NULL; // setting head->entries to null
        delete head; // deallocating head
        head = hold; // update head over to the next node
        top_index = MAX; // top_index is full because how else could you have deleted one off the top if the one below wasn't full
        }

    return 1;

}

//Supply the journal at the top of stack back to the client
//Return 0 if there are no items
//top_index is one beyond where the top of stack is...
//with no items, top_index is zero
int stack::peek(journal_entry & found_at_top) const
{
            
            if (!head) return 0; // there's nothing
                                
            if (!head->entries[top_index-1].entries(found_at_top)) // if head can't access entries from the top
                return 0;

                return 1;
}

