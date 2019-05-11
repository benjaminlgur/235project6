#include <string>
#include <iostream>
#include "Roster.hpp"
#include <algorithm>


int main(){
    Student a(123, "Adam", "Smith"), b(412, "Joe", "Deblazio"), c(555, "Dany", "Uarg"), d(777, "Jason", "Borne"), e(6677, "Yellow", "River"), f(12345, "Frodo", "Tam"), g(123123, "Bilbo", "Zoom");
    Roster roster;
    roster.add(a);
    roster.add(b);
    roster.add(c);
    roster.add(d);
    roster.add(e);
    roster.add(f);
    roster.add(g);
    roster.display();
    std::cout << roster.getHeight() << std::endl;
    roster.remove(a);
    //roster.display();
}