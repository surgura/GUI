/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#ifndef GUI_GUI_H
#define GUI_GUI_H

#include "Result.h"
#include "Grph/RenderTarget.h"
#include "Types.h"
#include "LinkedList.h"

typedef struct Gui_Element Gui_Element;

/// Base for a gui
typedef struct
{
    Gui_LinkedList elements;
} Gui_Gui;

/// Construct a gui
/// @param  gui     The gui to construct
void Gui_Gui_Construct(Gui_Gui* gui);

/// Deconstruct a gui
/// @param  gui     The gui to construct
void Gui_Gui_Deconstruct(Gui_Gui* gui);

/// Draw a gui
/// @param  gui             The gui to draw
/// @param  renderTarget    The render target to draw to
void Gui_Gui_Draw(Gui_Gui* gui, Grph_RenderTarget* renderTarget);

#endif // GUI_GUI_H
