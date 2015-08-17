/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include "Grph/RenderTarget.h"
#include "Result.h"
#include "Types.h"
#include "Gui.h"

/// A gui element
typedef struct Gui_Element
{
    /// A function to draw this specific element
    /// @param  userData        The user data associated with this element
    /// @param  renderTarget    The render target to draw to
    void (*draw) (void* userData, Grph_RenderTarget* renderTarget);
} Gui_Element;

/// Create a gui element
/// @param  gui             The gui to create at
/// @param  resultElement   Where to store a pointer to the element
/// @param  userDataSize    The size of the user data of the element
/// @param  draw            A pointer to the draw handle function
///         @param  userData        The user data passed in this function
///         @param  renderTarget    The render target to draw to
/// @return                 How executing the function went
///         GUI_SUCCESS     Everything went fine
///         GUI_ERRMEM      Something went wrong with allocating memory
Gui_Result Gui_NewElement(Gui_Gui* gui, Gui_Element** resultElement, Gui_U32 userDataSize,
                          void (*draw) (void* userData, Grph_RenderTarget* renderTarget));

/// Get the user data of an element
/// @param  element         The element to get the user data for
/// @return                 The user data contained in the element
void* Gui_Element_GetUserData(Gui_Element* element);

#endif // GUI_ELEMENT_H
