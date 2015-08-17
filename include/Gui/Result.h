/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#ifndef GUI_RESULT_H
#define GUI_RESULT_H

/// The possible results from gui functions
typedef enum
{
    /// Everything went fine
    GUI_SUCCESS,

    /// Allocating memory was needed but something went wrong
    GUI_ERRMEM
} Gui_Result;

#endif // GUI_RESULT_H
