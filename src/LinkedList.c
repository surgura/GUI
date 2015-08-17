/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#include "LinkedListFunctions.h"
#include <stdlib.h>

void Gui_LinkedList_Construct(Gui_LinkedList* list)
{
    list->first = 0;
    list->last = 0;
}

void Gui_LinkedList_Deconstruct(Gui_LinkedList* list)
{
    Gui_LinkedListNode* node = list->first;
    while(node != 0)
    {
        Gui_LinkedListNode* toFree = node;
        node = node->next;
        free(toFree);
    }
}

Gui_LinkedList_Result Gui_LinkedList_PushBack(Gui_LinkedList* list, Gui_LinkedListNode** resultNode, Gui_U32 dataSize)
{
    // Calculate size of node
    Gui_U32 nodeSize = sizeof(Gui_LinkedListNode) + dataSize;
    // Alocate memory for node
    Gui_LinkedListNode* newNode = malloc(nodeSize);
    if(newNode == 0)
        return GUI_LINKEDLIST_ALLOC_ERROR;

    // If there is a last node
    if(list->last != 0)
    {
        // Set previous for new node to old last node
        newNode->previous = list->last;
        // Set new node next to 0
        newNode->next = 0;

        // Set next for old last
        list->last->next = newNode;
        // Set new node as last
        list->last = newNode;
    }
    else
    {
        // Set new node as last and first
        list->first = newNode;
        list->last = newNode;
        // Set previous and next of new node to 0
        newNode->next = 0;
        newNode->previous = 0;
    }

    // Set return value
    *resultNode = newNode;

    return GUI_LINKEDLIST_SUCCESS;
}

void Gui_LinkedList_Remove(Gui_LinkedList* list, Gui_LinkedListNode* node)
{
    // If this is the first node
    if(node->previous == 0)
    {
        // Set first node to this nodes next node
        list->first = node->next;
    }
    else
    {
        // Set previous nodes next to this nodes next
        node->previous->next = node->next;
    }

    // If this is the last node
    if(node->next == 0)
    {
        // Set last node to this nodes previous node
        list->last = node->previous;
    }
    else
    {
        // Set next nodes previous to this nodes previous
        node->next->previous = node->previous;
    }

    // Free memory
    free(node);
}

Gui_LinkedListNode* Gui_LinkedList_First(Gui_LinkedList* list)
{
    return list->first;
}

Gui_LinkedListNode* Gui_LinkedList_Next(Gui_LinkedListNode* node)
{
    return node->next;
}

void* Gui_LinkedList_GetData(Gui_LinkedListNode* node)
{
    // Skip node struct to get to the data
    return (Gui_U8*)node + sizeof(Gui_LinkedListNode);
}

Gui_LinkedListNode* Gui_LinkedList_GetNode(void* data)
{
    // Go back a node struct to get the node
    return (Gui_LinkedListNode*)((Gui_U8*)data - sizeof(Gui_LinkedListNode));
}
