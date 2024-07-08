#include "harl.hpp"

int main() {
    Harl obj;
    obj.complain("DEBUG");
    obj.complain("WARNING");
    obj.complain("INFO");
    obj.complain("ERROR");
    obj.complain("OTHER");

    return 0;
}
