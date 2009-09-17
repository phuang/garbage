#ifndef __PY_PROPERTY_H_
#define __PY_PROPERTY_H_

#include <ibus.h>
#include "Pointer.h"

namespace PY {

typedef Pointer<IBusProperty> Property;
/* 
 class Property : public Pointer<IBusProperty> {
 };
 */

class PropList : public Pointer<IBusPropList> {
public:
    PropList (void) : Pointer<IBusPropList> (ibus_prop_list_new ()) { }

    void append (Property &prop) {
        ibus_prop_list_append (*this, prop);
    }
};

};

#endif
