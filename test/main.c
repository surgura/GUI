#include "Gui/Gui.h"
#include "Gui/Image.h"

int main()
{
    // not legit way to get a texture
    Grph_Texture texture;



    Gui_Gui gui;
    Gui_Gui_Construct(&gui);

    Gui_Element* imageElement;
    Gui_NewImage(&gui, &imageElement, &texture);

    Gui_Gui_Deconstruct(&gui);

    while(1){}

    return 0;
}
