/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#include "Gui/Element.h"
#include "LinkedListFunctions.h"

Gui_Result Gui_NewElement(Gui_Gui* gui, Gui_Element** resultElement, Gui_U32 userDataSize,
                          void (*draw) (void* userData, Grph_RenderTarget* renderTarget))
{
    // Create a new node in the element list with size for an element plus its user data
    Gui_LinkedListNode* node;
    Gui_LinkedList_Result result = Gui_LinkedList_PushBack(&gui->elements, &node, sizeof(Gui_Element) + userDataSize);

    // return error if not successful
    if (result == GUI_LINKEDLIST_ALLOC_ERROR)
        return GUI_ERRMEM;

    // set result element
    *resultElement = Gui_LinkedList_GetData(node);

    // set element draw function
    (*resultElement)->draw = draw;

    return GUI_SUCCESS;
}

void* Gui_Element_GetUserData(Gui_Element* element)
{
    // user data is located directly after the element
    return ++element;
}
