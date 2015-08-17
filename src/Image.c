/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

#include "Gui/Image.h"

/// Draw an image
/// @param  userData        A pointer to the image user data
/// @param  renderTarget    The render target to draw to
void Gui_Image_Draw(void* userData, Grph_RenderTarget* renderTarget)
{
    // @todo
}

Gui_Result Gui_NewImage(Gui_Gui* gui, Gui_Element** resultElement, Grph_Texture* texture)
{
    // Create new element
    Gui_Result result = Gui_NewElement(gui, resultElement, sizeof(Gui_Image), Gui_Image_Draw);

    // check for errors
    if (result != GUI_SUCCESS)
        return result;

    // get image
    Gui_Image* image = Gui_Element_GetUserData(*resultElement);

    // set texture
    image->texture = texture;

    return GUI_SUCCESS;

}

void Gui_Image_SetTexture(Gui_Image* image, Grph_Texture* texture)
{
    // @todo
}
