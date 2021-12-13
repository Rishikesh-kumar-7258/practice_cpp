#include <iostream>
#include "bank_record.h"

int main()
{
    Account prince("prince");
    Account james("james");

    james.display_user();
    prince.display_user();

    return 0;
}