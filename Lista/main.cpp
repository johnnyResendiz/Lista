//
//  main.cpp
//  Lista
//
//  Created by Johnny Resendiz on 10/4/20.
//  Copyright © 2020 Johnny Resendiz. All rights reserved.
//

#include <iostream>
#include "listFunction.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Lista* oct = new Lista();
    oct->formListEntry();
    oct->writeEntryToFile();
}
