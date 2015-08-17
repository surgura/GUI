/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#ifndef GUI_LINKED_LIST_FUNCTIONS_H
#define GUI_LINKED_LIST_FUNCTIONS_H

#include "Gui/LinkedList.h"
#include "Gui/Types.h"

/// Codes for the results of the linked list functions.
typedef enum
{
    /// Everything went as expected.
    GUI_LINKEDLIST_SUCCESS,

    /// Allocing memory was needed but it failed.
    /// No data was changed.
    GUI_LINKEDLIST_ALLOC_ERROR
} Gui_LinkedList_Result;

/// Initialize a linked list.
/// @param  list    The list to initialize.
void Gui_LinkedList_Construct(Gui_LinkedList* list);

/// Cleanup a linked list. Frees all memory.
/// Linked list structure is free to use as if it where never used.
/// @param  list    The list to clean up.
void Gui_LinkedList_Deconstruct(Gui_LinkedList* list);

/// Add a new node with an arbitrary size at the back of the list.
/// @param  list            The list to add to.
/// @param  resultNode      The variable to store the result pointer to the node in.
/// @param  dataSize        The size of data to be contained in the node.
/// @return                 How executing the function went.
///         GUI_SUCCESS     Everything went as expected.
///         GUI_ALLOC_ERROR Allocing memory was needed but it failed.
///                         No data was changed.
Gui_LinkedList_Result Gui_LinkedList_PushBack(Gui_LinkedList* list, Gui_LinkedListNode** resultNode, Gui_U32 dataSize);

/// Remove a node from the list.
/// @param  list        The list to remove from.
/// @param  node        The node to remove.
void Gui_LinkedList_Remove(Gui_LinkedList* list, Gui_LinkedListNode* node);

/// Get the first node from a linked list
/// @param  list    The list to get the first node from
/// @return         The first node of the list
Gui_LinkedListNode* Gui_LinkedList_First(Gui_LinkedList* list);

/// Get the next node in the list.
/// Returns null pointer if this was the last node in the list.
/// @param  node        The node to get the next sibling from.
/// @return             The next node, or null pointer,
///                     if the provided node was the last one in the list.
Gui_LinkedListNode* Gui_LinkedList_Next(Gui_LinkedListNode* node);

/// Get the data from a node.
/// @param  node        The node to get the data from.
void* Gui_LinkedList_GetData(Gui_LinkedListNode* node);

/// Get a node pointer from its data
/// @param  data        The data to get the node from.
Gui_LinkedListNode* Gui_LinkedList_GetNode(void* data);

#endif // GUI_LINKED_LIST_FUNCTIONS_H
