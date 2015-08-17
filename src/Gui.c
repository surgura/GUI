/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#include "Gui/Gui.h"
#include "LinkedListFunctions.h"

void Gui_Gui_Construct(Gui_Gui* gui)
{
    // Construct elements linked list
    Gui_LinkedList_Construct(&gui->elements);
}

void Gui_Gui_Deconstruct(Gui_Gui* gui)
{
    // Deconstruct elements linked list
    Gui_LinkedList_Deconstruct(&gui->elements);
}

void Gui_Gui_Draw(Gui_Gui* gui, Grph_RenderTarget* renderTarget)
{
    // @todo
}
