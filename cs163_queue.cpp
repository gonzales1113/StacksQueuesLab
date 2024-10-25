#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
	if (!rear){
        rear = new q_node;
        if (!rear->entry.copy_entry(to_add)){
            rear = nullptr; // safe thing to do
            return 0;
        }

        rear->next = rear; // rear is currently q_node, or the node we just made
                           //
        }
    else // if a rear already exists
    {
        q_node *front = rear->next;
        rear->next = new q_node;
        rear = rear->next; // rear is now at the "front" of the list/line

        if (!rear->entry.copy_entry(to_add)){
            delete rear;
            rear = front; // moves rear over to the new end of the line
            return 0;
        }
        rear->next = front; // rear->next implies you're moving through the line, front is the actual "front" progression 
        }



    return 0;
}

//Remove the node at the front
int queue::dequeue ()
{

	if (!rear) return 0; // return 0 if nothing is in line

    if (rear->next == this->rear){ // this->rear means whatever the current spot of rear is
        // in this case, asking if the second person in line is equal to the last person
        // is asking if they are the same person
        rear->next = nullptr;
        delete rear;
        rear = nullptr;
        this->rear = nullptr;
    }
    else
    {
        q_node *hold = rear->next->next; // two nexts is to move from the back, then to the next person after
        delete rear->next; // deleting the node in front of the current node
        rear->next = hold;
    }



    return 1;
}
