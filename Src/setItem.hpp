#ifndef SET_ITEM_H_INCLUDED
#define SET_ITEM_H_INCLUDED

namespace Godel{
    // Puse esto para definir un array de items
    class item{
    public:
        hwnd handler;
        tipo_de_item;
        posicion_x_de_item;
        posicion_y_de_item;
        tamanio_x_de_item;
        tamanio_y_de_item;
        color_de_item;
        datos_extra_del_item // Estos pueden ser el texto del boton
        // o el estilo, o cualquier otra cosa, tengo que encontrar
        // la manera de colocarlo del mejor modo posible
    private:    
        // ...Aca creo que no va nada... A lo mejor los miembros
        // publicos algunos deberian ser privados    
    };
}

#endif //SET_ITEM_H_INCLUDED