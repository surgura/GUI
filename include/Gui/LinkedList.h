/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#ifndef GUI_LINKED_LIST_H
#define GUI_LINKED_LIST_H

/// A node in the linked list.
typedef struct Gui_LinkedListNode
{
    /// The previous node in the list. Null if this is the first node.
    struct Gui_LinkedListNode* previous;

    /// The next node in the list. Null if this is the last node.
    struct Gui_LinkedListNode* next;
} Gui_LinkedListNode;

/// A doubly linked list with arbitrary size for each node.
typedef struct
{
    /// The first node in the list
    Gui_LinkedListNode* first;

    /// The last node in the list
    Gui_LinkedListNode* last;// @todo remove no longer needed
} Gui_LinkedList;

#endif // GUI_LINKED_LIST_H
