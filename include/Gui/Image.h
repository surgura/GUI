/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#ifndef GUI_IMAGE_H
#define GUI_IMAGE_H

#include "Gui.h"
#include "Result.h"
#include "Element.h"
#include "Grph/Texture.h"

/// An image gui element
typedef struct
{
    Grph_Texture* texture;
} Gui_Image;

/// Create a new image element
/// @param  gui             The gui to create the element at
/// @param  resultElement   Where to store a pointer to the created element
/// @return                 How executing the function went
///         GUI_SUCCESS     Everything went fine
///         GUI_ERRMEM      Something went wrong with allocating memory
Gui_Result Gui_NewImage(Gui_Gui* gui, Gui_Element** resultElement, Grph_Texture* texture);

/// Set the texture of an image
/// @param  image           The image to set the texture for
/// @param  texture         The texture to set at the image
void Gui_Image_SetTexture(Gui_Image* image, Grph_Texture* texture);

#endif // GUI_IMAGE_H
